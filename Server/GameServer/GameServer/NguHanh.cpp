#include "StdAfx.h"
#include "user.h"
#include "NguHanh.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "ObjectManager.h"
#include "VanThanhProtect.h"

#if(NGUHANH_NEW == 1)

NguHanh gNguHanh;
// -------------------------------------------------------------------------------
NguHanh::NguHanh() // OK
{
}
// -------------------------------------------------------------------------------
NguHanh::~NguHanh() // OK
{
}
// -------------------------------------------------------------------------------
void NguHanh::Load()
{
	this->NGU_HANH_MAX = GetPrivateProfileInt("CONFIG", "NGU_HANH_MAX", 0, gPath.GetFullPath("Custom\\NguHanh\\CustomNguHanh.ini"));

	this->Kim = GetPrivateProfileInt("CONFIG", "Kim", 0, gPath.GetFullPath("Custom\\NguHanh\\CustomNguHanh.ini"));
	this->Moc = GetPrivateProfileInt("CONFIG", "Moc", 0, gPath.GetFullPath("Custom\\NguHanh\\CustomNguHanh.ini"));
	this->Thuy = GetPrivateProfileInt("CONFIG", "Thuy", 0, gPath.GetFullPath("Custom\\NguHanh\\CustomNguHanh.ini"));
	this->Hoa = GetPrivateProfileInt("CONFIG", "Hoa", 0, gPath.GetFullPath("Custom\\NguHanh\\CustomNguHanh.ini"));
	this->Tho = GetPrivateProfileInt("CONFIG", "Tho", 0, gPath.GetFullPath("Custom\\NguHanh\\CustomNguHanh.ini"));
}
// -------------------------------------------------------------------------------
void NguHanh::BUY_NGU_HANH(LPOBJ lpObj, BUY_NGU_HANH_REQ *aRecv)
{
	if (aRecv->Number == 1)
	{
		if (gVanThanhProtect.NguHanh == 0)
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
#endif

		if (lpObj->rNguHanh < 1)
		{
			if (lpObj->rNguHanh > this->NGU_HANH_MAX)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2020));
				return;
			}

			int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 141), 2);

			if (NguyenLieu < 1)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2019));
				return;
			}

			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 141), 2, 1);

			//--
			lpObj->rNguHanh += 1; // Thay Đổi
			//--
			GCFireworksSend(lpObj, lpObj->X, lpObj->Y);
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(2018), lpObj->Name, lpObj->rNguHanh);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			GetInfoNguHanh(lpObj);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		else if (lpObj->rNguHanh < 2)
		{
			if (lpObj->rNguHanh > this->NGU_HANH_MAX)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2020));
				return;
			}

			int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 30), 2);

			if (NguyenLieu < 1)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2019));
				return;
			}

			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 30), 2, 1);

			//--
			lpObj->rNguHanh += 1; // Thay Đổi
			//--
			GCFireworksSend(lpObj, lpObj->X, lpObj->Y);
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(2018), lpObj->Name, lpObj->rNguHanh);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			GetInfoNguHanh(lpObj);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		else if (lpObj->rNguHanh < 3)
		{
			if (lpObj->rNguHanh > this->NGU_HANH_MAX)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2020));
				return;
			}

			int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 31), 2);

			if (NguyenLieu < 1)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2019));
				return;
			}

			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 31), 2, 1);

			//--
			lpObj->rNguHanh += 1; // Thay Đổi
			//--
			GCFireworksSend(lpObj, lpObj->X, lpObj->Y);
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(2018), lpObj->Name, lpObj->rNguHanh);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			GetInfoNguHanh(lpObj);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		else if (lpObj->rNguHanh < 4)
		{
			if (lpObj->rNguHanh > this->NGU_HANH_MAX)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2020));
				return;
			}

			int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 136), 2);

			if (NguyenLieu < 1)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2019));
				return;
			}

			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 136), 2, 1);

			//--
			lpObj->rNguHanh += 1; // Thay Đổi
			//--
			GCFireworksSend(lpObj, lpObj->X, lpObj->Y);
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(2018), lpObj->Name, lpObj->rNguHanh);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			GetInfoNguHanh(lpObj);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		else if (lpObj->rNguHanh < 5)
		{
			if (lpObj->rNguHanh > this->NGU_HANH_MAX)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2020));
				return;
			}

			int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(12, 137), 2);

			if (NguyenLieu < 1)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2019));
				return;
			}

			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(12, 137), 2, 1);

			//--
			lpObj->rNguHanh += 1; // Thay Đổi
			//--
			GCFireworksSend(lpObj, lpObj->X, lpObj->Y);
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(2018), lpObj->Name, lpObj->rNguHanh);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			GetInfoNguHanh(lpObj);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
	}

	if (aRecv->Number == 2)
	{
		GetInfoNguHanh(lpObj);
	}

}
//
//void NguHanh::BUY_NGU_HANH_1(LPOBJ lpObj)
//{
//
//	int NguyenLieu = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(14, 180), 0);
//
//	if (NguyenLieu < 1)
//	{
//		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(2019));
//		return;
//	}
//	gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(14, 180 ), 0, 1);
//}
#endif
