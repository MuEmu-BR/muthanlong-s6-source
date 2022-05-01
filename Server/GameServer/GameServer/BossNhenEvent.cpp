// BOSSNHENManager.cpp: implementation of the CBOSSNHENManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BossNhenEvent.h"
#include "Map.h"
#include "MemScript.h"
#include "Message.h"
#include "Monster.h"
#include "MonsterSetBase.h"
#include "Notice.h"
#include "ObjectManager.h"
#include "ScheduleManager.h"
#include "ServerInfo.h"
#include "Util.h"
#include "FlyingDragons.h"

#if(BOSS_NHEN_TIME == 1)

CBOSSNHENManager gBOSSNHENManager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBOSSNHENManager::CBOSSNHENManager() // OK
{
	for (int n = 0; n < MAX_BOSSNHEN; n++)
	{
		BOSSNHEN_INFO* lpInfo = &this->m_BOSSNHENInfo[n];

		lpInfo->Index = n;
		lpInfo->State = BOSSNHEN_STATE_BLANK;
		lpInfo->RemainTime = 0;
		lpInfo->TargetTime = 0;
		lpInfo->TickCount = GetTickCount();

		this->CleanMonster(lpInfo);
	}
}

CBOSSNHENManager::~CBOSSNHENManager() // OK
{

}

void CBOSSNHENManager::Init() // OK
{
	for (int n = 0; n < MAX_BOSSNHEN; n++)
	{
		if (gServerInfo.m_BossNhenSwitch == 0)
		{
			this->SetState(&this->m_BOSSNHENInfo[n], BOSSNHEN_STATE_BLANK);
		}
		else
		{
			this->SetState(&this->m_BOSSNHENInfo[n], BOSSNHEN_STATE_EMPTY);
		}
	}
}

void CBOSSNHENManager::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	for (int n = 0; n < MAX_BOSSNHEN; n++)
	{
		this->m_BOSSNHENInfo[n].RespawnMessage = -1;
		this->m_BOSSNHENInfo[n].DespawnMessage = -1;
		this->m_BOSSNHENInfo[n].BossIndex = -1;
		this->m_BOSSNHENInfo[n].BossMessage = -1;
		this->m_BOSSNHENInfo[n].BOSSNHENTime = 0;
		this->m_BOSSNHENInfo[n].StartTime.clear();
		this->m_BOSSNHENInfo[n].RespawnInfo[0].clear();
		this->m_BOSSNHENInfo[n].MonsterInfo.clear();
	}

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					BOSSNHEN_START_TIME info;

					int index = lpMemScript->GetNumber();

					info.Year = lpMemScript->GetAsNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].StartTime.push_back(info);
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int index = lpMemScript->GetNumber();

					this->m_BOSSNHENInfo[index].RespawnMessage = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].DespawnMessage = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].BossIndex = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].BossMessage = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].BOSSNHENTime = lpMemScript->GetAsNumber();
				}
				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					BOSSNHEN_RESPWAN_INFO info;

					int index = lpMemScript->GetNumber();

					info.Group = lpMemScript->GetAsNumber();

					info.Map = lpMemScript->GetAsNumber();

					info.Value = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].RespawnInfo[info.Group].push_back(info);
				}
				else if (section == 3)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					BOSSNHEN_MONSTER_INFO info;

					int index = lpMemScript->GetNumber();

					info.Group = lpMemScript->GetAsNumber();

					info.MonsterClass = lpMemScript->GetAsNumber();

					info.RegenType = lpMemScript->GetAsNumber();

					info.RegenTime = lpMemScript->GetAsNumber();

					this->m_BOSSNHENInfo[index].MonsterInfo.push_back(info);
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CBOSSNHENManager::MainProc() // OK
{
	for (int n = 0; n < MAX_BOSSNHEN; n++)
	{
		BOSSNHEN_INFO* lpInfo = &this->m_BOSSNHENInfo[n];

		DWORD elapsed = GetTickCount() - lpInfo->TickCount;

		if (elapsed < 1000)
		{
			continue;
		}


		if (lpInfo->State == BOSSNHEN_STATE_BLANK)
		{
			if (gServerDisplayer.EventBossNhen[n] != -1)
			{
				gServerDisplayer.EventBossNhen[n] = -1;
			}
		}
		else
		{
			if (lpInfo->State == BOSSNHEN_STATE_EMPTY)
			{
				gServerDisplayer.EventBossNhen[n] = lpInfo->RemainTime;
			}
			else
			{
				if (gServerDisplayer.EventBossNhen[n] != 0)
				{
					gServerDisplayer.EventBossNhen[n] = 0;
				}
			}
		}

		if (gServerDisplayer.EventBossNhen[n] > 0)
		{
			if (lpInfo->State != BOSSNHEN_STATE_EMPTY && lpInfo->State != BOSSNHEN_STATE_BLANK)
			{
				gServerDisplayer.EventBossNhen[n] = 0;
			}
		}

		lpInfo->TickCount = GetTickCount();

		lpInfo->RemainTime = (int)difftime(lpInfo->TargetTime, time(0));

		switch (lpInfo->State)
		{
		case BOSSNHEN_STATE_BLANK:
			this->ProcState_BLANK(lpInfo);
			break;
		case BOSSNHEN_STATE_EMPTY:
			this->ProcState_EMPTY(lpInfo);
			break;
		case BOSSNHEN_STATE_START:
			this->ProcState_START(lpInfo);
			break;
		}
	}
}

void CBOSSNHENManager::ProcState_BLANK(BOSSNHEN_INFO* lpInfo) // OK
{

}

void CBOSSNHENManager::ProcState_EMPTY(BOSSNHEN_INFO* lpInfo) // OK
{
	if (lpInfo->RemainTime <= 0)
	{
		if (lpInfo->RespawnMessage != -1)
		{
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(lpInfo->RespawnMessage));
		}

		this->SetState(lpInfo, BOSSNHEN_STATE_START);
	}
}

void CBOSSNHENManager::ProcState_START(BOSSNHEN_INFO* lpInfo) // OK
{
	if (lpInfo->RemainTime <= 0)
	{
		if (lpInfo->DespawnMessage != -1)
		{
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(lpInfo->DespawnMessage));
		}

		this->SetState(lpInfo, BOSSNHEN_STATE_EMPTY);
	}
}

void CBOSSNHENManager::SetState(BOSSNHEN_INFO* lpInfo, int state) // OK
{
	lpInfo->State = state;

	switch (lpInfo->State)
	{
	case BOSSNHEN_STATE_BLANK:
		this->SetState_BLANK(lpInfo);
		break;
	case BOSSNHEN_STATE_EMPTY:
		this->SetState_EMPTY(lpInfo);
		break;
	case BOSSNHEN_STATE_START:
		this->SetState_START(lpInfo);
		break;
	}
}

void CBOSSNHENManager::SetState_BLANK(BOSSNHEN_INFO* lpInfo) // OK
{

}

void CBOSSNHENManager::SetState_EMPTY(BOSSNHEN_INFO* lpInfo) // OK
{
	this->ClearMonster(lpInfo);

	this->CheckSync(lpInfo);
}

void CBOSSNHENManager::SetState_START(BOSSNHEN_INFO* lpInfo) // OK
{
	for (int n = 0; n < MAX_BOSSNHEN_RESPAWN_GROUP; n++)
	{
		if (lpInfo->RespawnInfo[n].empty() == 0)
		{
			BOSSNHEN_RESPWAN_INFO* lpRespawnInfo = &lpInfo->RespawnInfo[n][(GetLargeRand() % lpInfo->RespawnInfo[n].size())];

			for (std::vector<BOSSNHEN_MONSTER_INFO>::iterator it = lpInfo->MonsterInfo.begin(); it != lpInfo->MonsterInfo.end(); it++)
			{
				if (it->Group == lpRespawnInfo->Group)
				{
					this->SetMonster(lpInfo, lpRespawnInfo, &(*it));
				}
			}
		}
	}

	lpInfo->RemainTime = lpInfo->BOSSNHENTime;

	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
}

void CBOSSNHENManager::CheckSync(BOSSNHEN_INFO* lpInfo) // OK
{
	if (lpInfo->StartTime.empty() != 0)
	{
		this->SetState(lpInfo, BOSSNHEN_STATE_BLANK);
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<BOSSNHEN_START_TIME>::iterator it = lpInfo->StartTime.begin(); it != lpInfo->StartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(lpInfo, BOSSNHEN_STATE_BLANK);
		return;
	}

	lpInfo->RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	lpInfo->TargetTime = (int)ScheduleTime.GetTime();
}

int CBOSSNHENManager::GetState(int index) // OK
{
	if (index < 0 || index >= MAX_BOSSNHEN)
	{
		return BOSSNHEN_STATE_BLANK;
	}

	return this->m_BOSSNHENInfo[index].State;
}

int CBOSSNHENManager::GetRemainTime(int index) // OK
{
	if (index < 0 || index >= MAX_BOSSNHEN)
	{
		return 0;
	}

	BOSSNHEN_INFO* lpInfo = &this->m_BOSSNHENInfo[index];

	if (lpInfo->StartTime.empty() != 0)
	{
		return 0;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<BOSSNHEN_START_TIME>::iterator it = lpInfo->StartTime.begin(); it != lpInfo->StartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		return 0;
	}

	int RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	return (((RemainTime % 60) == 0) ? (RemainTime / 60) : ((RemainTime / 60) + 1));
}

bool CBOSSNHENManager::AddMonster(BOSSNHEN_INFO* lpInfo, int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	if (this->GetMonster(lpInfo, aIndex) != 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_BOSSNHEN_MONSTER; n++)
	{
		if (OBJECT_RANGE(lpInfo->MonsterIndex[n]) == 0)
		{
			lpInfo->MonsterIndex[n] = aIndex;
			return 1;
		}
	}

	return 0;
}

bool CBOSSNHENManager::DelMonster(BOSSNHEN_INFO* lpInfo, int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	int* index = this->GetMonster(lpInfo, aIndex);

	if (index == 0)
	{
		return 0;
	}

	(*index) = -1;
	return 1;
}

int* CBOSSNHENManager::GetMonster(BOSSNHEN_INFO* lpInfo, int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_BOSSNHEN_MONSTER; n++)
	{
		if (lpInfo->MonsterIndex[n] == aIndex)
		{
			return &lpInfo->MonsterIndex[n];
		}
	}

	return 0;
}

void CBOSSNHENManager::CleanMonster(BOSSNHEN_INFO* lpInfo) // OK
{
	for (int n = 0; n < MAX_BOSSNHEN_MONSTER; n++)
	{
		lpInfo->MonsterIndex[n] = -1;
	}
}

void CBOSSNHENManager::ClearMonster(BOSSNHEN_INFO* lpInfo) // OK
{
	for (int n = 0; n < MAX_BOSSNHEN_MONSTER; n++)
	{
		if (OBJECT_RANGE(lpInfo->MonsterIndex[n]) != 0)
		{
			gObjDel(lpInfo->MonsterIndex[n]);
			lpInfo->MonsterIndex[n] = -1;
		}
	}
}

int CBOSSNHENManager::GetMonsterCount(BOSSNHEN_INFO* lpInfo) // OK
{
	int count = 0;

	for (int n = 0; n < MAX_BOSSNHEN_MONSTER; n++)
	{
		if (OBJECT_RANGE(lpInfo->MonsterIndex[n]) != 0)
		{
			count++;
		}
	}

	return count;
}

void CBOSSNHENManager::SetMonster(BOSSNHEN_INFO* lpInfo, BOSSNHEN_RESPWAN_INFO* lpRespawnInfo, BOSSNHEN_MONSTER_INFO* lpMonsterInfo) // OK
{
	for (int n = 0; n < gMonsterSetBase.m_count; n++)
	{
		MONSTER_SET_BASE_INFO* lpMsbInfo = &gMonsterSetBase.m_MonsterSetBaseInfo[n];

		// Đoạn này set monster ở monsterbase
		if (lpMsbInfo->Type != 3 || lpMsbInfo->MonsterClass != lpMonsterInfo->MonsterClass || lpMsbInfo->Map != lpRespawnInfo->Map || lpMsbInfo->Value != lpRespawnInfo->Value)
		{
			continue;
		}

		int index = gObjAddMonster(lpMsbInfo->Map);

		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}

		LPOBJ lpObj = &gObj[index];

		if (gObjSetPosMonster(index, n) == 0)
		{
			gObjDel(index);
			continue;
		}

		if (gObjSetMonster(index, lpMsbInfo->MonsterClass) == 0)
		{
			gObjDel(index);
			continue;
		}

		lpObj->MaxRegenTime = ((lpMonsterInfo->RegenType == 0) ? (lpInfo->BOSSNHENTime * 1000) : lpMonsterInfo->RegenTime);

		if (lpObj->Class == lpInfo->BossIndex && lpInfo->BossMessage != -1)
		{
			LogAdd(LOG_EVENT, "[BOSSNHEN Manager] Index(%d) Boss Position (Map: %d X: %d Y: %d)", lpInfo->Index, lpObj->Map, lpObj->X, lpObj->Y);
		}

		lpObj->MaxRegenTime = ((lpMonsterInfo->RegenType == 0) ? (lpInfo->BOSSNHENTime * 1000) : lpMonsterInfo->RegenTime);

		if (lpObj->Class == lpInfo->BossIndex && lpInfo->BossMessage != -1)
		{
			LogAdd(LOG_EVENT, "[BOSSNHEN Manager] Index(%d) Boss Position (Map: %d X: %d Y: %d)", lpInfo->Index, lpObj->Map, lpObj->X, lpObj->Y);

		}

		if (this->AddMonster(lpInfo, index) == 0)
		{
			gObjDel(index);
			continue;
		}
	}
}

void CBOSSNHENManager::MonsterDieProc(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	int aIndex = gObjMonsterGetTopHitDamageUser(lpObj);

	if (OBJECT_RANGE(aIndex) != 0)
	{
		lpTarget = &gObj[aIndex];
	}

	for (int n = 0; n < MAX_BOSSNHEN; n++)
	{
		BOSSNHEN_INFO* lpInfo = &this->m_BOSSNHENInfo[n];

		if (this->GetState(lpInfo->Index) != BOSSNHEN_STATE_START)
		{
			continue;
		}

		if (this->GetMonster(lpInfo, lpObj->Index) == 0)
		{
			continue;
		}

		if (this->GetMonster(lpInfo, lpObj->Index) == 0)
		{
			continue;
		}
		//---
		if (lpObj->Class == lpInfo->BossIndex)
		{
			if (lpInfo->BossMessage != -1){
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(lpInfo->BossMessage), lpTarget->Name);
				continue;
			}
		}
		//---
	}
}

void CBOSSNHENManager::StartBOSSNHEN(int index)
{
	CTime CurrentTime = CTime::GetTickCount();

	int hour = (int)CurrentTime.GetHour();
	int minute = (int)CurrentTime.GetMinute() + 2;

	if (minute >= 60)
	{
		hour++;
		minute = minute - 60;
	}

	BOSSNHEN_START_TIME info;

	info.Year = (int)CurrentTime.GetYear();

	info.Month = (int)CurrentTime.GetMonth();

	info.Day = (int)CurrentTime.GetDay();

	info.DayOfWeek = -1;

	info.Hour = hour;

	info.Minute = minute;

	info.Second = 0;

	this->m_BOSSNHENInfo[index].StartTime.push_back(info);

	LogAdd(LOG_EVENT, "[Set BOSSNHEN Start] Index %d At %2d:%2d:00", index, hour, minute);

	this->SetState(&this->m_BOSSNHENInfo[index], BOSSNHEN_STATE_EMPTY);
}

#endif