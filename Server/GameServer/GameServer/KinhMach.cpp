#include "StdAfx.h"
#include "user.h"
#include "KinhMach.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "ItemBagManager.h"
#include "ItemManager.h"
#include "ObjectManager.h"
#include "JewelBank.h"
#include "VanThanhProtect.h"

#if(KINHMACH_NEW == 1)

KinhMach gKinhMach;

KinhMach::KinhMach() // OK
{
	this->Init();
}

KinhMach::~KinhMach() // OK
{

}

void KinhMach::Init()
{

}

///===============================================================
void KinhMach::GDSaveData(int aIndex)
{
	LPOBJ lpUser = &gObj[aIndex];
	KINHMACH_GD_SAVE_DATA pRequest;
	pRequest.header.set(0xB0, 0x12, sizeof(pRequest));
	memcpy(pRequest.Name, lpUser->Name, 11);
	pRequest.index = aIndex;
	pRequest.KINHMACH1 = lpUser->KINHMACH.KINHMACH1;
	pRequest.KINHMACH2 = lpUser->KINHMACH.KINHMACH2;
	pRequest.KINHMACH3 = lpUser->KINHMACH.KINHMACH3;
	pRequest.KINHMACH4 = lpUser->KINHMACH.KINHMACH4;
	pRequest.KINHMACH5 = lpUser->KINHMACH.KINHMACH5;
	pRequest.KINHMACH6 = lpUser->KINHMACH.KINHMACH6;
	pRequest.KINHMACH7 = lpUser->KINHMACH.KINHMACH7;
	pRequest.KINHMACH8 = lpUser->KINHMACH.KINHMACH8;
	pRequest.KINHMACHSD = lpUser->KINHMACH.KINHMACHSD;
	pRequest.KINHMACHHP = lpUser->KINHMACH.KINHMACHHP;
	gDataServerConnection.DataSend((BYTE*)&pRequest, pRequest.header.size);
}
// -------------------------------------------------------------------------------
void KinhMach::GDReqData(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	KINHMACH_GD_REQ_DATA pMsg;
	pMsg.header.set(0xB0, 0x11, sizeof(pMsg));
	pMsg.index = aIndex;
	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}
// -------------------------------------------------------------------------------
void KinhMach::GDSaveUserInfo(int aIndex)	//-> Complete
{
	this->GDSaveData(aIndex);
}
// -------------------------------------------------------------------------------
void KinhMach::GDReqUserInfo(int aIndex)	//-> Complete
{
	// ----
	this->GDReqData(aIndex);
}
// -------------------------------------------------------------------------------
void KinhMach::DGGetData(KINHMACH_DG_GET_DATA * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->index];
	// ----

	if (aRecv->KINHMACH1 < 0)
	{
		aRecv->KINHMACH1 = 0;
	}
	else if (aRecv->KINHMACH2 < 0)
	{
		aRecv->KINHMACH2 = 0;
	}
	else if (aRecv->KINHMACH3 < 0)
	{
		aRecv->KINHMACH3 = 0;
	}
	else if (aRecv->KINHMACH4 < 0)
	{
		aRecv->KINHMACH4 = 0;
	}
	else if (aRecv->KINHMACH5 < 0)
	{
		aRecv->KINHMACH5 = 0;
	}
	else if (aRecv->KINHMACH6 < 0)
	{
		aRecv->KINHMACH6 = 0;
	}
	else if (aRecv->KINHMACH7 < 0)
	{
		aRecv->KINHMACH7 = 0;
	}
	else if (aRecv->KINHMACH8 < 0)
	{
		aRecv->KINHMACH8 = 0;
	}
	else if (aRecv->KINHMACHSD < 0)
	{
		aRecv->KINHMACHSD = 0;
	}
	else if (aRecv->KINHMACHHP < 0)
	{
		aRecv->KINHMACHHP = 0;
	}
	// ----
	lpUser->KINHMACH.KINHMACH1 = aRecv->KINHMACH1;
	lpUser->KINHMACH.KINHMACH2 = aRecv->KINHMACH2;
	lpUser->KINHMACH.KINHMACH3 = aRecv->KINHMACH3;
	lpUser->KINHMACH.KINHMACH4 = aRecv->KINHMACH4;
	lpUser->KINHMACH.KINHMACH5 = aRecv->KINHMACH5;
	lpUser->KINHMACH.KINHMACH6 = aRecv->KINHMACH6;
	lpUser->KINHMACH.KINHMACH7 = aRecv->KINHMACH7;
	lpUser->KINHMACH.KINHMACH8 = aRecv->KINHMACH8;
	lpUser->KINHMACH.KINHMACHSD = aRecv->KINHMACHSD;
	lpUser->KINHMACH.KINHMACHHP = aRecv->KINHMACHHP;
}
// -------------------------------------------------------------------------------
//===============================================================================================================================
void KinhMach::Load()
{
	this->MAX_KINH_MACH_01 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_01", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_02 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_02", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_03 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_03", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_04 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_04", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_05 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_05", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_06 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_06", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_07 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_07", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->MAX_KINH_MACH_08 = GetPrivateProfileInt("CONFIG", "MAX_KINH_MACH_08", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));

	this->POINTSD = GetPrivateProfileInt("CONFIG", "POINTSD", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));
	this->POINTHP = GetPrivateProfileInt("CONFIG", "POINTHP", 0, gPath.GetFullPath("Custom\\KinhMach\\CustomKinhMach.ini"));

}
//===============================================================================================================================
void KinhMach::BUG_KINHMACH(LPOBJ lpObj, BUY_KINHMACH_REQ *aRecv)
{
	//<------------------------------------------------------------->
	if (aRecv->Number == 1)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH1 >  this->MAX_KINH_MACH_01) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 141), 0);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 141), 0, 1);

		lpObj->KINHMACH.KINHMACH1 += 1; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	else if (aRecv->Number == 2)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH2 >  this->MAX_KINH_MACH_02) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 30), 2);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 30), 2, 1);

		lpObj->KINHMACH.KINHMACH2 += 1; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//----------------------------------------------------------------------------------------------------------
	//<------------------------------------------------------------->
	else if (aRecv->Number == 3)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH3 >  this->MAX_KINH_MACH_03) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 31), 1);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 31), 1, 1);

		lpObj->KINHMACH.KINHMACH3 += 1; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	else if (aRecv->Number == 4)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH4 >  this->MAX_KINH_MACH_04) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12,136), 2);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 136), 2, 1);

		lpObj->KINHMACH.KINHMACH4 += 1; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	else if (aRecv->Number == 5)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH5 >  this->MAX_KINH_MACH_05) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 137), 2);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 137), 2, 1);

		lpObj->KINHMACH.KINHMACH5 += 1; // Thay Đổi

		lpObj->KINHMACH.KINHMACHSD += this->POINTSD; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	else if (aRecv->Number == 6)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH6 >  this->MAX_KINH_MACH_06) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 138), 0);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 138), 0, 1);

		lpObj->KINHMACH.KINHMACH6 += 1; // Thay Đổi

		lpObj->KINHMACH.KINHMACHHP += this->POINTHP; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	else if (aRecv->Number == 7)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH7 >  this->MAX_KINH_MACH_07) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 139), 2);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 139), 2, 1);

		lpObj->KINHMACH.KINHMACH7 += 1; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	else if (aRecv->Number == 8)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}

		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
#endif
		if (lpObj->KINHMACH.KINHMACH8 >  this->MAX_KINH_MACH_08) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2016));
			return;
		}

		int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(13, 14), 0);

		if (NguyenLieu < 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2017));
			return;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(13, 14), 0, 1);

		lpObj->KINHMACH.KINHMACH8 += 1; // Thay Đổi

		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//<------------------------------------------------------------->
	// Taget Client
	else if (aRecv->Number == 9)
	{
		if (gVanThanhProtect.KinhMach == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng đang bảo trì!");
			return;
		}
		this->GDSaveUserInfo(lpObj->Index);
		GetInfoKinhMach(lpObj);
	}
	//<------------------------------------------------------------->
}
//===============================================================================================================================
void KinhMach::Option(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	CItem* Right = &lpObj->Inventory[0];

	//--------------------------------------------------------------------------------
	// Sát thương + phép
	lpObj->MagicDamageMin += lpObj->KINHMACH.KINHMACH1;
	lpObj->MagicDamageMax += lpObj->KINHMACH.KINHMACH1;
	lpObj->PhysiDamageMinLeft += lpObj->KINHMACH.KINHMACH1;
	lpObj->PhysiDamageMinRight += lpObj->KINHMACH.KINHMACH1;
	lpObj->PhysiDamageMaxLeft += lpObj->KINHMACH.KINHMACH1;
	lpObj->PhysiDamageMaxRight += lpObj->KINHMACH.KINHMACH1;
	//--------------------------------------------------------------------------------
	lpObj->SkillDamageBonus += lpObj->KINHMACH.KINHMACH2; // Tấn công của tuyệt chiêu
	////--------------------------------------------------------------------------------
	lpObj->Defense += lpObj->KINHMACH.KINHMACH3; // Sức chống đỡ
	////--------------------------------------------------------------------------------
	lpObj->DamageReflect += lpObj->KINHMACH.KINHMACH4; // Giảm Sát Thương
	////--------------------------------------------------------------------------------
	lpObj->AddShield += lpObj->KINHMACH.KINHMACHSD; // SD +
	////--------------------------------------------------------------------------------
	lpObj->AddLife += lpObj->KINHMACH.KINHMACHHP; // HP +
	////--------------------------------------------------------------------------------
	lpObj->IgnoreDefenseRate += lpObj->KINHMACH.KINHMACH7; // Bỏ qua phòng thủ
	////--------------------------------------------------------------------------------
	lpObj->ExperienceRate += lpObj->KINHMACH.KINHMACH8; // Tăng Exp
	lpObj->MasterExperienceRate += lpObj->KINHMACH.KINHMACH8; // Tăng ExpMaster
	////--------------------------------------------------------------------------------



}
//===============================================================================================================================
#endif