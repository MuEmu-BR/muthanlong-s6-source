#include "stdafx.h"
#include "ChienTruongCoRsTime.h"
#include "Monster.h"
#include "Protocol.h"
#include "Util.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "User.h"
#include "ItemManager.h"
#include "Map.h"
#include "ScheduleManager.h"
#include "ObjectManager.h"
#include "DSProtocol.h"
#include "SkillManager.h"
#include "MuunSystem.h"
#include "GensSystem.h"
#include "PcPoint.h"
#include "ESProtocol.h"
#include "GuildClass.h"
#include "CustomRankUser.h"
#include "CustomGHRS.h"

ChienTruongCoTime gChienTruongCoTime;

void ChienTruongCoTime::Init()
{
	this->CheckSync();
}

void ChienTruongCoTime::Read(char * FilePath)
{
	this->m_TimeReloadInfo.clear();
	this->Enabled = 0;
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, FilePath);
		return;
	}

	if (lpMemScript->SetBuffer(FilePath) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
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

					CHIENTRUONGCO_START_TIME info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_TimeReloadInfo.push_back(info);
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

void ChienTruongCoTime::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_RemainTime <= 0) {

			this->Init(); //Set Lai Time
			this->RsTime();
			return;

		}
	}
}
void ChienTruongCoTime::CheckSync() // OK
{
	if (this->m_TimeReloadInfo.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<CHIENTRUONGCO_START_TIME>::iterator it = this->m_TimeReloadInfo.begin(); it != this->m_TimeReloadInfo.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->TargetTime = (int)ScheduleTime.GetTime();
}

void ChienTruongCoTime::RsTime()
{
	// Sét điểm Guild về 0
	for (int n = 0; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnectedGP(n) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[n];

		lpObj->CTCTime = 0;
		lpObj->CTCRegDay = 0;

		lpObj->TowerCount = 0;
		lpObj->TowerTime = 0;

		GDCharacterInfoSaveSend(gObj[n].Index);
	}

	LogAdd(LOG_EVENT, "[RsTime]");
}

