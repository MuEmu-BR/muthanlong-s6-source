#include "StdAfx.h"
#include "user.h"
#include "PhuKien.h"
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
#include "SachThuocTinh.h"
#include "Guild.h"

#if(PHUKIEN_NEW == 1)

PhuKien gPhuKien;

PhuKien::PhuKien() // OK
{

}

PhuKien::~PhuKien() // OK
{

}

///===============================================================
void PhuKien::GDSaveData(int aIndex)
{
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	PHUKIEN_GD_SAVE_DATA pRequest;
	pRequest.header.set(0xB0, 0x10, sizeof(pRequest));
	memcpy(pRequest.Name, lpUser->Name, 11);
	pRequest.index = aIndex;
	//--
	pRequest.PHUKIEN1 = lpUser->PHUKIEN.PHUKIEN1;
	pRequest.PHUKIEN2 = lpUser->PHUKIEN.PHUKIEN2;
	//--
	gDataServerConnection.DataSend((BYTE*)&pRequest, pRequest.header.size);
}
// -------------------------------------------------------------------------------
void PhuKien::GDReqData(int aIndex)
{

	LPOBJ lpObj = &gObj[aIndex];
	PHUKIEN_GD_REQ_DATA pMsg;
	pMsg.header.set(0xB0, 0x09, sizeof(pMsg));
	pMsg.index = aIndex;
	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);

}
// -------------------------------------------------------------------------------
void PhuKien::GDSaveUserInfo(int aIndex)	//-> Complete
{
	this->GDSaveData(aIndex);
}
// -------------------------------------------------------------------------------
void PhuKien::GDReqUserInfo(int aIndex)	//-> Complete
{
	// ----
	this->GDReqData(aIndex);
}
// -------------------------------------------------------------------------------
void PhuKien::DGGetData(PHUKIEN_DG_GET_DATA * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->index];
	// ----

	if (aRecv->PHUKIEN1 < 0)
	{
		aRecv->PHUKIEN1 = 0;
	}
	else if (aRecv->PHUKIEN2 < 0)
	{
		aRecv->PHUKIEN2 = 0;
	}
	// ----
	lpUser->PHUKIEN.PHUKIEN1 = aRecv->PHUKIEN1;
	lpUser->PHUKIEN.PHUKIEN2 = aRecv->PHUKIEN2;
}
// -------------------------------------------------------------------------------
//===============================================================================================================================
void PhuKien::Load()
{
	this->MAX_PHUKIEN1 = GetPrivateProfileInt("Config", "MAX_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->MAX_PHUKIEN2 = GetPrivateProfileInt("Config", "MAX_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));

	this->ID_PHUKIEN1 = GetPrivateProfileInt("Config", "ID_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->ID_PHUKIEN2 = GetPrivateProfileInt("Config", "ID_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));

	this->OP1_PHUKIEN1 = GetPrivateProfileInt("Option", "OP1_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP2_PHUKIEN1 = GetPrivateProfileInt("Option", "OP2_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP3_PHUKIEN1 = GetPrivateProfileInt("Option", "OP3_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP4_PHUKIEN1 = GetPrivateProfileInt("Option", "OP4_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP5_PHUKIEN1 = GetPrivateProfileInt("Option", "OP5_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP6_PHUKIEN1 = GetPrivateProfileInt("Option", "OP6_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP7_PHUKIEN1 = GetPrivateProfileInt("Option", "OP7_PHUKIEN1", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));

	this->OP1_PHUKIEN2 = GetPrivateProfileInt("Option", "OP1_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP2_PHUKIEN2 = GetPrivateProfileInt("Option", "OP2_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP3_PHUKIEN2 = GetPrivateProfileInt("Option", "OP3_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP4_PHUKIEN2 = GetPrivateProfileInt("Option", "OP4_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP5_PHUKIEN2 = GetPrivateProfileInt("Option", "OP5_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP6_PHUKIEN2 = GetPrivateProfileInt("Option", "OP6_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	this->OP7_PHUKIEN2 = GetPrivateProfileInt("Option", "OP7_PHUKIEN2", 0, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));

	GetPrivateProfileString("Text", "MSG_01", "BAN DA DAT CAP DO TOI DA", MSG_01, 1024, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini"));
	GetPrivateProfileString("Text", "MSG_02", "BAN CAN 1 %s PHU KIEN", MSG_02, 1024, gPath.GetFullPath("VanThanh\\CustomPhuKien.ini")); 

}
//===============================================================================================================================
void PhuKien::BUG_PHUKIEN(LPOBJ lpObj, BUY_PHUKIEN_REQ *aRecv)
{
	//===================================================================================================>
	if (aRecv->Number == 1)
	{
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
#endif
		//----
		if (lpObj->PHUKIEN.PHUKIEN1 >  this->MAX_PHUKIEN1) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int PHUKIEN01 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, this->ID_PHUKIEN1))
				{
					PHUKIEN01 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->PHUKIEN.PHUKIEN1 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1550), lpObj->Name, gItemManager.GetItemName(GET_ITEM(14, this->ID_PHUKIEN1)), lpObj->PHUKIEN.PHUKIEN1);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (PHUKIEN01 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, this->ID_PHUKIEN1)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		lpObj->ClickClientSend = GetTickCount();
	}
	//===================================================================================================>
	if (aRecv->Number == 2)
	{
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
#endif
		//----
		if (lpObj->PHUKIEN.PHUKIEN2 >  this->MAX_PHUKIEN2) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int PHUKIEN02 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, this->ID_PHUKIEN2))
				{
					PHUKIEN02 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->PHUKIEN.PHUKIEN2 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1550), lpObj->Name, gItemManager.GetItemName(GET_ITEM(14, this->ID_PHUKIEN2)), lpObj->PHUKIEN.PHUKIEN2);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (PHUKIEN02 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, this->ID_PHUKIEN2)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		lpObj->ClickClientSend = GetTickCount();
	}
	//===================================================================================================>
	// remove 
	if (aRecv->Number == 5)
	{
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
#endif
		int Count = 1;
		//----
		if (lpObj->PHUKIEN.PHUKIEN1 <= 0) // < 30
		{
			return;
		}
		int EmptySlot = gItemManager.GetInventoryEmptySlotCount(lpObj);

		if (EmptySlot < Count)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hãy dọn dẹp thùng đồ cá nhân.");
			return;
		}
		for (int n = 0; n < Count; n++)
		{
			lpObj->PHUKIEN.PHUKIEN1 -= 1; // Thay Đổi
			this->GDSaveUserInfo(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);

			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, GET_ITEM(14, this->ID_PHUKIEN1), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã tháo 1 [%s]", gItemManager.GetItemName(GET_ITEM(14, this->ID_PHUKIEN1)));
		lpObj->ClickClientSend = GetTickCount();
	}
	//===================================================================================================>
	// remove 
	if (aRecv->Number == 6)
	{
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
#endif

		int Count = 1;
		//----
		if (lpObj->PHUKIEN.PHUKIEN2 <= 0)
		{
			return;
		}
		int EmptySlot = gItemManager.GetInventoryEmptySlotCount(lpObj);

		if (EmptySlot < Count)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hãy dọn dẹp thùng đồ cá nhân.");
			return;
		}
		for (int n = 0; n < Count; n++)
		{
			lpObj->PHUKIEN.PHUKIEN2 -= 1; // Thay Đổi
			this->GDSaveUserInfo(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);

			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, GET_ITEM(14, this->ID_PHUKIEN2), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã tháo 1 [%s]", gItemManager.GetItemName(GET_ITEM(14, this->ID_PHUKIEN2)));
		lpObj->ClickClientSend = GetTickCount();
	}
	//===================================================================================================>
}
//===============================================================================================================================
void PhuKien::Option(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	CItem* Right = &lpObj->Inventory[0];

	if (lpObj->PHUKIEN.PHUKIEN1 > 0)
	{
		////--------------------------------------------------------------------------------
		if (lpObj->PHUKIEN.PHUKIEN1 >= 5)
		{
			lpObj->AddLife += (int)((lpObj->MaxLife * this->OP1_PHUKIEN1) / 100);
			lpObj->AddMana += (int)((lpObj->MaxMana * this->OP2_PHUKIEN1) / 100);
		}
		if (lpObj->PHUKIEN.PHUKIEN1 >= 10)
		{
			lpObj->DamageReflect += (int)((lpObj->DamageReflect * this->OP3_PHUKIEN1) / 100); // Phản sát thương
			lpObj->DamageReduction[5] += (int)((lpObj->DamageReduction[5] * this->OP4_PHUKIEN1) / 100); // Giảm sát thương
		}
		if (lpObj->PHUKIEN.PHUKIEN1 >= 15)
		{
			lpObj->Defense += this->OP5_PHUKIEN1; // Sức chống đỡ
			lpObj->SkillDamageBonus += this->OP6_PHUKIEN1; // Tấn công của tuyệt chiêu
			lpObj->ExcellentDamage += this->OP7_PHUKIEN1; // Sát thương hoàn hảo
		}
	}
	////--------------------------------------------------------------------------------
	if (lpObj->PHUKIEN.PHUKIEN2 > 0)
	{
		if (lpObj->PHUKIEN.PHUKIEN2 >= 5)
		{
			lpObj->AddLife += (int)((lpObj->MaxLife * this->OP1_PHUKIEN2) / 100);
			lpObj->AddMana += (int)((lpObj->MaxMana * this->OP2_PHUKIEN2) / 100);
		}
		if (lpObj->PHUKIEN.PHUKIEN2 >= 10)
		{
			lpObj->DamageReflect += (int)((lpObj->DamageReflect * this->OP3_PHUKIEN2) / 100); // Phản sát thương
			lpObj->DamageReduction[5] += (int)((lpObj->DamageReduction[5] * this->OP4_PHUKIEN2) / 100); // Giảm sát thương
		}
		if (lpObj->PHUKIEN.PHUKIEN2 >= 15)
		{
			lpObj->Defense += this->OP5_PHUKIEN2; // Sức chống đỡ
			lpObj->SkillDamageBonus += this->OP6_PHUKIEN2; // Tấn công của tuyệt chiêu
			lpObj->ExcellentDamage += this->OP7_PHUKIEN2; // Sát thương hoàn hảo
		}
	}
	////--------------------------------------------------------------------------------
}

//===============================================================================================================================
struct PHUKIEN_UPDATE  // ok
{
	PBMSG_HEAD3 h;
	int	OP1_PHUKIEN1;
	int	OP2_PHUKIEN1;
	int	OP3_PHUKIEN1;
	int	OP4_PHUKIEN1;
	int	OP5_PHUKIEN1;
	int	OP6_PHUKIEN1;
	int	OP7_PHUKIEN1;
	int	OP1_PHUKIEN2;
	int	OP2_PHUKIEN2;
	int	OP3_PHUKIEN2;
	int	OP4_PHUKIEN2;
	int	OP5_PHUKIEN2;
	int	OP6_PHUKIEN2;
	int	OP7_PHUKIEN2;
};
void PhuKienDataSend(int aIndex) // ok
{
	PHUKIEN_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 105, sizeof(rSend));
	rSend.OP1_PHUKIEN1 = gPhuKien.OP1_PHUKIEN1;
	rSend.OP2_PHUKIEN1 = gPhuKien.OP2_PHUKIEN1;
	rSend.OP3_PHUKIEN1 = gPhuKien.OP3_PHUKIEN1;
	rSend.OP4_PHUKIEN1 = gPhuKien.OP4_PHUKIEN1;
	rSend.OP5_PHUKIEN1 = gPhuKien.OP5_PHUKIEN1;
	rSend.OP6_PHUKIEN1 = gPhuKien.OP6_PHUKIEN1;
	rSend.OP7_PHUKIEN1 = gPhuKien.OP7_PHUKIEN1;
	rSend.OP1_PHUKIEN2 = gPhuKien.OP1_PHUKIEN2;
	rSend.OP2_PHUKIEN2 = gPhuKien.OP2_PHUKIEN2;
	rSend.OP3_PHUKIEN2 = gPhuKien.OP3_PHUKIEN2;
	rSend.OP4_PHUKIEN2 = gPhuKien.OP4_PHUKIEN2;
	rSend.OP5_PHUKIEN2 = gPhuKien.OP5_PHUKIEN2;
	rSend.OP6_PHUKIEN2 = gPhuKien.OP6_PHUKIEN2;
	rSend.OP7_PHUKIEN2 = gPhuKien.OP7_PHUKIEN2;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

#endif