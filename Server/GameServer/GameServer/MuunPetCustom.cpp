#include "stdafx.h"
#include "MuunPetCustom.h"
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
#include "MuunSystem.h"

//21-03-2022 

MuunPetCustom gMuunPetCustom;

void MuunPetCustom::Init()
{
	this->CheckSync();
}

void MuunPetCustom::Read(char * FilePath)
{
	this->m_MuunPetCustom_Time.clear();

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

					MuunPetCustom_Time info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_MuunPetCustom_Time.push_back(info);
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					this->Debug = lpMemScript->GetNumber();
				}
				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					this->MauPetGiam = lpMemScript->GetNumber();
				}
				else if (section == 3)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					this->MauPetTang = lpMemScript->GetNumber();
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

void MuunPetCustom::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_RemainTime <= 0)
		{
			this->Init(); //Set Lai Time
			this->GiamMauMuunPet();
			return;
		}
	}
}
void MuunPetCustom::CheckSync() // OK
{
	if (this->m_MuunPetCustom_Time.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<MuunPetCustom_Time>::iterator it = this->m_MuunPetCustom_Time.begin(); it != this->m_MuunPetCustom_Time.end(); it++)
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

void MuunPetCustom::TimeMuunPet(int aIndex, int Type) //Gui thong tin ve CLient
{
	MUUNPETTIME_SENDCLIENT pMsg;

	pMsg.header.set(0xF3, 0x37, sizeof(pMsg));

	if (Type == 1)
	{
		//=== Send 1 Client===//
		if (gObjIsConnectedGP(aIndex) == 0)
		{
			return;
		}
		LPOBJ lpObj = &gObj[aIndex];
		pMsg.MuunPetTime = this->m_RemainTime;
		DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
	}
}

void MuunPetCustom::GiamMauMuunPet()
{
	if (this->m_RemainTime <= 0)
	{
		return;
	}

	for (int n = OBJ_STARTUSERINDEX; n < MAX_OBJECT; n++) // điều kiện nhân vật online
	{
		if (gObj[n].Type != OBJECT_USER)
		{
			continue;
		}

		LPOBJ lpObj = &gObj[n];

		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0 || lpObj->MuunInventory[n].m_Durability == 0)
			{
				continue;
			}

			if ((lpObj->MuunInventory[n].m_Durability - this->MauPetGiam) >= 1)
			{
				lpObj->MuunInventory[n].m_Durability = lpObj->MuunInventory[n].m_Durability - this->MauPetGiam;

				gMuunSystem.GCMuunItemDurSend(lpObj->Index, n, (BYTE)lpObj->MuunInventory[n].m_Durability);

				if (this->Debug == 1)
				{
					LogAdd(LOG_RED, "[- mau pet 1]");
				}
			}
			else
			{
				lpObj->MuunInventory[n].m_Durability = 0;
				gMuunSystem.GCMuunItemDurSend(lpObj->Index, n, (BYTE)lpObj->MuunInventory[n].m_Durability);
				gObjectManager.CharacterCalcAttribute(lpObj->Index);

				if (this->Debug == 1)
				{
					LogAdd(LOG_RED, "[- mau pet 2]");
				}

			}
		}
	}
}

void MuunPetCustom::HoiMauMuunPet(LPOBJ lpObj)
{

	if (lpObj->Type != OBJECT_USER)
	{
		return;
	}

	CItem* pEquipet = &lpObj->MuunInventory[0];

	if (lpObj->MuunInventory[0].IsItem() == 0 || lpObj->MuunInventory[0].IsMuunItem() == 0 || lpObj->MuunInventory[0].m_Durability == 255)
	{
		return;
	}

	pEquipet->m_Durability = 255;

	gMuunSystem.GCMuunItemDurSend(lpObj->Index, 0, (BYTE)lpObj->MuunInventory[0].m_Durability);

	if (this->Debug == 1)
	{
		LogAdd(LOG_RED, "[+ mau pet 1]");
	}

}

void MuunPetCustom::HoiMauMuunPet1(LPOBJ lpObj)
{

	if (lpObj->Type != OBJECT_USER)
	{
		return;
	}

	CItem* pEquipet = &lpObj->MuunInventory[1];

	if (lpObj->MuunInventory[1].IsItem() == 0 || lpObj->MuunInventory[1].IsMuunItem() == 0 || lpObj->MuunInventory[1].m_Durability == 255)
	{
		return;
	}

	pEquipet->m_Durability = 255;

	gMuunSystem.GCMuunItemDurSend(lpObj->Index, 1, (BYTE)lpObj->MuunInventory[1].m_Durability);

	if (this->Debug == 1)
	{
		LogAdd(LOG_RED, "[+ mau pet 2]");
	}
}
