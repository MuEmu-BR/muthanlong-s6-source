#include "stdafx.h"
#include "CapNhapBangXepHang.h"
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
#include "CustomRanking.h"

//21-03-2022 

BangXepHang gBangXepHang;

void BangXepHang::Init()
{
	this->CheckSync();
}

void BangXepHang::Read(char * FilePath)
{
	this->m_TimeReloadInfoAll.clear();

	this->CheckSync();

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

					BANGXEPHANGALL_START_TIME info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_TimeReloadInfoAll.push_back(info);
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

void BangXepHang::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_RemainTime <= 0)
		{
			this->Init(); //Set Lai Time
			this->SendRanking();
			return;
		}
	}
}
void BangXepHang::CheckSync() // OK
{
	if (this->m_TimeReloadInfoAll.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<BANGXEPHANGALL_START_TIME>::iterator it = this->m_TimeReloadInfoAll.begin(); it != this->m_TimeReloadInfoAll.end(); it++)
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

void BangXepHang::SendRanking()
{
	if (this->m_RemainTime <= 0)
	{
		return;
	}

#if(RANKING_NEW == 1)
	gRanking.SendDS();
	gRanking.SendDSDW();
	gRanking.SendDSDK();
	gRanking.SendDSEF();
	gRanking.SendDSMG();
	gRanking.SendDSDL();
	gRanking.SendDSSM();
	gRanking.SendDSRF();
	gRanking.SendDSNAP();
	gRanking.SendDSBLOOD();
	gRanking.SendDSDEVIL();
	gRanking.SendDSCHAOS();
#endif
	
	LogAdd(LOG_RED, "[Cap Nhap Bang Xep Hang]");
}
