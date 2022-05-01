#include "stdafx.h"
#include "MuunAFK.h"
#include "Monster.h"
#include "Protocol.h"
#include "GameMain.h"
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
#include "CashShop.h"

#if(MUUNAFK == 1)

MuunAFK gMuunAFK;

//===============================================================================================================================
void MuunAFK::GDSaveData(int aIndex)
{
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	MUUNAFK_GD_SAVE_DATA pRequest;
	pRequest.header.set(0xB0, 0x08, sizeof(pRequest));
	memcpy(pRequest.Name, lpUser->Name, 11);
	pRequest.index = aIndex;
	//----
	pRequest.MuunAFKTime = lpUser->MUUNPETAFK.MuunAFKTime;
	pRequest.MuunAFKStamina = lpUser->MUUNPETAFK.MuunAFKStamina;
	pRequest.MuunAFKWCoinClaim = lpUser->MUUNPETAFK.MuunAFKWCoinClaim;
	//----
	gDataServerConnection.DataSend((BYTE*)&pRequest, pRequest.header.size);
}
// -------------------------------------------------------------------------------
void MuunAFK::GDReqData(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	MUUNAFK_GD_REQ_DATA pMsg;
	pMsg.header.set(0xB0, 0x07, sizeof(pMsg));
	pMsg.index = aIndex;
	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}
// -------------------------------------------------------------------------------
void MuunAFK::GDSaveUserInfo(int aIndex)	//-> Complete
{
	this->GDSaveData(aIndex);
}
// -------------------------------------------------------------------------------
void MuunAFK::GDReqUserInfo(int aIndex)	//-> Complete
{
	// ----
	this->GDReqData(aIndex);
}
// -------------------------------------------------------------------------------
void MuunAFK::DGGetData(MUUNAFK_DG_GET_DATA * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->index];
	// ----

	if (aRecv->MuunAFKTime < 0)
	{
		aRecv->MuunAFKTime = 0;
	}
	else if (aRecv->MuunAFKStamina < 0)
	{
		aRecv->MuunAFKStamina = 0;
	}
	else if (aRecv->MuunAFKWCoinClaim < 0)
	{
		aRecv->MuunAFKWCoinClaim = 0;
	}
	// ----
	lpUser->MUUNPETAFK.MuunAFKTime = aRecv->MuunAFKTime;
	lpUser->MUUNPETAFK.MuunAFKStamina = aRecv->MuunAFKStamina;
	lpUser->MUUNPETAFK.MuunAFKWCoinClaim = aRecv->MuunAFKWCoinClaim;
	//----
}
// -------------------------------------------------------------------------------

void MuunAFK::Init()
{
	this->CheckSync();
}

void MuunAFK::InitStamina()
{
	this->CheckSyncStamina();
}


void MuunAFK::Read(char * FilePath)
{
	this->m_MuunAFK_Time.clear();

	this->CheckSync();

	this->CheckSyncStamina();

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

					MuunAFKStamina_Time info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_MuunAFKStamina_Time.push_back(info);
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					MuunAFK_Time info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_MuunAFK_Time.push_back(info);
				}
				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					this->Debug = lpMemScript->GetNumber();
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

void MuunAFK::Load(char* path) // OK
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok)
	{
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}

	//--
	pugi::xml_node oMuunAFK = file.child("MuunAFK");

	//---------------------------------------------------------------------------------------------------------
	pugi::xml_node eEnabled = oMuunAFK.child("Enabled");
	for (pugi::xml_node rEnabled = eEnabled.child("Config"); rEnabled; rEnabled = rEnabled.next_sibling()){
		this->m_Enabled = rEnabled.attribute("BatTat").as_int();
	}
	//---------------------------------------------------------------------------------------------------------
	pugi::xml_node eStamina = oMuunAFK.child("Stamina");
	for (pugi::xml_node rStamina = eStamina.child("Config"); rStamina; rStamina = rStamina.next_sibling()){
		this->m_DiemStamina = rStamina.attribute("Stamina").as_int();
	}
	//---------------------------------------------------------------------------------------------------------
	pugi::xml_node eThoiGian = oMuunAFK.child("ThoiGian");
	for (pugi::xml_node rThoiGian = eThoiGian.child("Config"); rThoiGian; rThoiGian = rThoiGian.next_sibling()){
		this->m_SetThoiGian = rThoiGian.attribute("ThoiGian").as_int();
	}
	//---------------------------------------------------------------------------------------------------------
	pugi::xml_node eWCoinStamina = oMuunAFK.child("WCoinStamina");
	for (pugi::xml_node rWCoinStamina = eWCoinStamina.child("Config"); rWCoinStamina; rWCoinStamina = rWCoinStamina.next_sibling()){

		this->m_Stamina100Den90 = rWCoinStamina.attribute("Stamina100Den90").as_int();
		this->m_Stamina90Den80 = rWCoinStamina.attribute("Stamina90Den80").as_int();
		this->m_Stamina80Den70 = rWCoinStamina.attribute("Stamina80Den70").as_int();
		this->m_Stamina70Den60 = rWCoinStamina.attribute("Stamina70Den60").as_int();
		this->m_Stamina60Den50 = rWCoinStamina.attribute("Stamina60Den50").as_int();
		this->m_Stamina50Den40 = rWCoinStamina.attribute("Stamina50Den40").as_int();
		this->m_Stamina40Den30 = rWCoinStamina.attribute("Stamina40Den30").as_int();
		this->m_Stamina30Den20 = rWCoinStamina.attribute("Stamina30Den20").as_int();
		this->m_Stamina20Den10 = rWCoinStamina.attribute("Stamina20Den10").as_int();
		this->m_Stamina10Den00 = rWCoinStamina.attribute("Stamina10Den00").as_int();
	}							   
	//---------------------------------------------------------------------------------------------------------

}

void MuunAFK::LoadPetWCoinC(char* path)
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

	this->m_count = 0;

	for (int n = 0; n < MAX_PET_WCOINC; n++)
	{
		this->m_Data[n];
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

					this->m_Data[this->m_count].m_Type = lpMemScript->GetNumber();

					this->m_Data[this->m_count].m_Index = lpMemScript->GetAsNumber();

					this->m_Data[this->m_count].m_WCoin = lpMemScript->GetAsNumber();

					this->m_Data[this->m_count].m_TuyChinh = lpMemScript->GetAsNumber();

					this->m_count++;
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

void MuunAFK::LoadPetWCoinCStamina(char* path)
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

	this->m_count_stamina = 0;

	for (int n = 0; n < MAX_PET_WCOINC_STAMINA; n++)
	{
		this->m_DataStamina[n];
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

					this->m_DataStamina[this->m_count_stamina].m_Type = lpMemScript->GetNumber();
													 
					this->m_DataStamina[this->m_count_stamina].m_Index = lpMemScript->GetAsNumber();
													 
					this->m_DataStamina[this->m_count_stamina].m_WCoin = lpMemScript->GetAsNumber();
													 
					this->m_DataStamina[this->m_count_stamina].m_TuyChinh = lpMemScript->GetAsNumber();

					this->m_count_stamina++;
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

//OK
void MuunAFK::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_RemainTime <= 0)
		{
			this->Init(); //Set Lai Time
			this->RunMuunAFK();
			return;
		}
	}
}

//OK
void MuunAFK::MainProcStamina()
{
	if ((GetTickCount() - this->m_TickCountStamina) >= 1000)
	{
		this->m_TickCountStamina = GetTickCount();

		this->m_RemainTimeStamina = (int)difftime(this->TargetTimeStamina, time(0));

		if (this->m_RemainTimeStamina <= 0)
		{
			this->InitStamina(); //Set Lai Time
			this->RunMuunAFKStamina();
			return;
		}
	}
}

//OK
void MuunAFK::CheckSync() // OK
{
	if (this->m_MuunAFK_Time.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<MuunAFK_Time>::iterator it = this->m_MuunAFK_Time.begin(); it != this->m_MuunAFK_Time.end(); it++)
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

//OK
void MuunAFK::CheckSyncStamina() // OK
{
	if (this->m_MuunAFKStamina_Time.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<MuunAFKStamina_Time>::iterator it = this->m_MuunAFKStamina_Time.begin(); it != this->m_MuunAFKStamina_Time.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		return;
	}

	this->m_RemainTimeStamina = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->TargetTimeStamina = (int)ScheduleTime.GetTime();
}

//OK
void MuunAFK::TimeMuunPet(int aIndex, int Type) //Gui thong tin ve CLient
{

	if (this->m_Enabled == 0)
	{
		return;
	}

	MUUNPETAFK_SENDCLIENT pMsg;

	pMsg.header.set(0xF3, 0x98, sizeof(pMsg));

	if (Type == 1)
	{
		//=== Send 1 Client===//
		if (gObjIsConnectedGP(aIndex) == 0)
		{
			return;
		}
		LPOBJ lpObj = &gObj[aIndex];
		pMsg.MuunAFKTime = lpObj->MUUNPETAFK.MuunAFKTime;
		pMsg.MuunAFKStamina = lpObj->MUUNPETAFK.MuunAFKStamina;
		pMsg.MuunAFKWCoinClaim = lpObj->MUUNPETAFK.MuunAFKWCoinClaim;

		DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
	}
}


//OK
void MuunAFK::RunMuunAFKStamina()
{
	if (this->m_RemainTimeStamina <= 0)
	{
		return;
	}

	for (int n = 0; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnectedGP(n) == 0)
		{
			continue;
		}

		LPOBJ lpObj = &gObj[n];

		if (lpObj->MUUNPETAFK.MuunAFKStamina >= 100)
		{
			if (this->Debug == 1)
			{
				LogAdd(LOG_RED, "[No Send MuunAFKStamina]");
			}
			continue;
		}

		lpObj->MUUNPETAFK.MuunAFKStamina += this->m_DiemStamina;
		this->GDSaveData(lpObj->Index);

		if (this->Debug == 1)
		{
			LogAdd(LOG_RED, "[MuunAFKStamina]");
		}

	}
}

void MuunAFK::RunMuunAFK()
{
	if (this->m_RemainTime <= 0)
	{
		return;
	}

	for (int n = 0; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnectedGP(n) == 0)
		{
			continue;
		}

		LPOBJ lpObj = &gObj[n];

		lpObj->MUUNPETAFK.MuunAFKTime += this->m_SetThoiGian;

		this->GDSaveData(lpObj->Index);

		if (this->Debug == 1)
		{
			LogAdd(LOG_RED, "[MuunAFKTime]");
		}
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
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_Data[i].m_Type, gMuunAFK.m_Data[i].m_Index))
				{
					int TienNhanDuoc = gMuunAFK.m_Data[i].m_WCoin + lpObj->Reset + gMuunAFK.m_Data[i].m_TuyChinh / lpObj->MUUNPETAFK.MuunAFKStamina;

					if (lpObj->MUUNPETAFK.MuunAFKStamina >= 1 && lpObj->MUUNPETAFK.MuunAFKStamina <= 99)
					{
						lpObj->MUUNPETAFK.MuunAFKWCoinClaim += TienNhanDuoc;
					}

					int TienNhanDuoc1 = gMuunAFK.m_Data[i].m_WCoin + lpObj->Reset + gMuunAFK.m_Data[i].m_TuyChinh;
					// Fix Cash
					if (lpObj->MUUNPETAFK.MuunAFKStamina <= 0)
					{
						lpObj->MUUNPETAFK.MuunAFKWCoinClaim += TienNhanDuoc1;
					}

					this->GDSaveData(lpObj->Index);

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKWCoinClaim]");
					}
				}
			}
		}
	}
}

void MuunAFK::HoiStamina(LPOBJ lpObj)
{

	if (lpObj->MUUNPETAFK.MuunAFKStamina <= 0)
	{
		return;
	}

	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 90 && lpObj->MUUNPETAFK.MuunAFKStamina <= 100)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina100Den90 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina100Den90 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina100Den90 = this->m_Stamina100Den90 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina100Den90), -(0), -(0), "TienMuunStamina100Den90");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 80 && lpObj->MUUNPETAFK.MuunAFKStamina <= 90)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina90Den80 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina90Den80 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina90Den80 = this->m_Stamina90Den80 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina90Den80), -(0), -(0), "TienMuunStamina90Den80");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 70 && lpObj->MUUNPETAFK.MuunAFKStamina <= 80)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina80Den70 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina80Den70 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina80Den70 = this->m_Stamina80Den70 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina80Den70), -(0), -(0), "TienMuunStamina80Den70");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 60 && lpObj->MUUNPETAFK.MuunAFKStamina <= 70)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina70Den60 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina70Den60 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina70Den60 = this->m_Stamina70Den60 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina70Den60), -(0), -(0), "TienMuunStamina70Den60");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 50 && lpObj->MUUNPETAFK.MuunAFKStamina <= 60)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina60Den50 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina60Den50 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina60Den50 = this->m_Stamina60Den50 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina60Den50), -(0), -(0), "TienMuunStamina60Den50");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 40 && lpObj->MUUNPETAFK.MuunAFKStamina <= 50)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina50Den40 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina50Den40 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina50Den40 = this->m_Stamina50Den40 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina50Den40), -(0), -(0), "TienMuunStamina50Den40");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 30 && lpObj->MUUNPETAFK.MuunAFKStamina <= 40)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina40Den30 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina40Den30 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina40Den30 = this->m_Stamina40Den30 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina40Den30), -(0), -(0), "TienMuunStamina40Den30");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 20 && lpObj->MUUNPETAFK.MuunAFKStamina <= 30)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina30Den20 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina30Den20 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina30Den20 = this->m_Stamina30Den20 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina30Den20), -(0), -(0), "TienMuunStamina30Den20");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 10 && lpObj->MUUNPETAFK.MuunAFKStamina <= 20)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina20Den10 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina20Den10 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina20Den10 = this->m_Stamina20Den10 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina20Den10), -(0), -(0), "TienMuunStamina20Den10");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 0 && lpObj->MUUNPETAFK.MuunAFKStamina <= 10)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					if (lpObj->Coin1 < this->m_Stamina10Den00 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh)
					{
						gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuunAFK]bạn cần %d để hạ Stamina", this->m_Stamina10Den00 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh);
						return;
					}

					this->TienMuunStamina10Den00 = this->m_Stamina10Den00 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;

					GDSetCoinSend(lpObj->Index, -(this->TienMuunStamina10Den00), -(0), -(0), "TienMuunStamina10Den00");
					gCashShop.CGCashShopPointRecv(lpObj->Index); // save

					// ok
					lpObj->MUUNPETAFK.MuunAFKStamina = 0;
					this->GDSaveData(lpObj->Index);
					//---

					if (this->Debug == 1)
					{
						LogAdd(LOG_RED, "[MuunAFKStamina = 0]");
					}
				}
			}
		}
	}
	/// ket thuc
}

void MuunAFK::NhanWCoinClaim(LPOBJ lpObj)
{

	if (lpObj->MUUNPETAFK.MuunAFKWCoinClaim <= 0)
	{
		return;
	}

	int NhanWCoinClaim = lpObj->MUUNPETAFK.MuunAFKWCoinClaim;
	GDSetCoinSend(lpObj->Index, +(NhanWCoinClaim), +(0), +(0), "NhanWCoinClaim");
	gCashShop.CGCashShopPointRecv(lpObj->Index); // save

	// ok
	lpObj->MUUNPETAFK.MuunAFKWCoinClaim = 0;
	lpObj->MUUNPETAFK.MuunAFKTime = 0;
	this->GDSaveData(lpObj->Index);
	//---

	if (this->Debug == 1)
	{
		LogAdd(LOG_RED, "[MuunAFKWCoinClaim = 0]");
	}


}


struct MUUNAFK_UPDATE
{
	PBMSG_HEAD3 h;
	int TienMuunStamina100Den90;
	int TienMuunStamina90Den80;
	int TienMuunStamina80Den70;
	int TienMuunStamina70Den60;
	int TienMuunStamina60Den50;
	int TienMuunStamina50Den40;
	int TienMuunStamina40Den30;
	int TienMuunStamina30Den20;
	int TienMuunStamina20Den10;
	int TienMuunStamina10Den00;
};

void MuunAFKDataSend(int aIndex)
{
	MUUNAFK_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 113, sizeof(rSend));

	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 90 && lpObj->MUUNPETAFK.MuunAFKStamina <= 100)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina100Den90 = gMuunAFK.m_Stamina100Den90 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 80 && lpObj->MUUNPETAFK.MuunAFKStamina <= 90)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina90Den80 = gMuunAFK.m_Stamina90Den80 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 70 && lpObj->MUUNPETAFK.MuunAFKStamina <= 80)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina80Den70 = gMuunAFK.m_Stamina80Den70 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 60 && lpObj->MUUNPETAFK.MuunAFKStamina <= 70)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina70Den60 = gMuunAFK.m_Stamina70Den60 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 50 && lpObj->MUUNPETAFK.MuunAFKStamina <= 60)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina60Den50 = gMuunAFK.m_Stamina60Den50 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 40 && lpObj->MUUNPETAFK.MuunAFKStamina <= 50)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina50Den40 = gMuunAFK.m_Stamina50Den40 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 30 && lpObj->MUUNPETAFK.MuunAFKStamina <= 40)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina40Den30 = gMuunAFK.m_Stamina40Den30 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 20 && lpObj->MUUNPETAFK.MuunAFKStamina <= 30)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina30Den20 = gMuunAFK.m_Stamina30Den20 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 10 && lpObj->MUUNPETAFK.MuunAFKStamina <= 20)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina20Den10 = gMuunAFK.m_Stamina20Den10 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	if (lpObj->MUUNPETAFK.MuunAFKStamina >= 0 && lpObj->MUUNPETAFK.MuunAFKStamina <= 10)
	{
		for (int n = 0; n < MUUN_INVENTORY_SIZE; n++)
		{
			if (lpObj->MuunInventory[n].IsItem() == 0 || lpObj->MuunInventory[n].IsMuunItem() == 0)
			{
				continue;
			}

			// Phan Thuong
			for (int i = 0; i < gMuunAFK.m_count_stamina; i++)
			{
				if (lpObj->MuunInventory[n].m_Index == GET_ITEM(gMuunAFK.m_DataStamina[i].m_Type, gMuunAFK.m_DataStamina[i].m_Index))
				{

					gMuunAFK.TienMuunStamina10Den00 = gMuunAFK.m_Stamina10Den00 + gMuunAFK.m_DataStamina[i].m_WCoin + gMuunAFK.m_DataStamina[i].m_TuyChinh;
				}
			}
		}
	}
	rSend.TienMuunStamina100Den90 = gMuunAFK.TienMuunStamina100Den90;
	rSend.TienMuunStamina90Den80 = gMuunAFK.TienMuunStamina90Den80;
	rSend.TienMuunStamina80Den70 = gMuunAFK.TienMuunStamina80Den70;
	rSend.TienMuunStamina70Den60 = gMuunAFK.TienMuunStamina70Den60;
	rSend.TienMuunStamina60Den50 = gMuunAFK.TienMuunStamina60Den50;
	rSend.TienMuunStamina50Den40 = gMuunAFK.TienMuunStamina50Den40;
	rSend.TienMuunStamina40Den30 = gMuunAFK.TienMuunStamina40Den30;
	rSend.TienMuunStamina30Den20 = gMuunAFK.TienMuunStamina30Den20;
	rSend.TienMuunStamina20Den10 = gMuunAFK.TienMuunStamina20Den10;
	rSend.TienMuunStamina10Den00 = gMuunAFK.TienMuunStamina10Den00;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}



#endif