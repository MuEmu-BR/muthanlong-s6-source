#include "stdafx.h"
#include "BossNhenTime.h"
#include "Monster.h"
#include "Protocol.h"
#include "Util.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "User.h"
#include "Map.h"
#include "ScheduleManager.h"
#include "ObjectManager.h"
#include "DSProtocol.h"
#include "ESProtocol.h"
#include "Raklion.h"

#if(BOSS_NHEN_TIME == 1)

BossNhenTime gBossNhenTime;

void BossNhenTime::Init()
{
	this->CheckSync();
}

void BossNhenTime::Read(char * FilePath)
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

					BOSSNHEN1_START_TIME info;

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

void BossNhenTime::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_RemainTime <= 0)
		{
			this->Init(); //Set Lai Time
			this->KhoiDongBossNhen();
			return;
		}
	}
}
void BossNhenTime::CheckSync() // OK
{
	if (this->m_TimeReloadInfo.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<BOSSNHEN1_START_TIME>::iterator it = this->m_TimeReloadInfo.begin(); it != this->m_TimeReloadInfo.end(); it++)
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

void BossNhenTime::KhoiDongBossNhen()
{
	if (this->m_RemainTime <= 0)
	{
		return;
	}

	gRaklion.SetState(RAKLION_STATE_END);

	LogAdd(LOG_RED, "[Boss Nhen Bat Dau]");
}

#endif