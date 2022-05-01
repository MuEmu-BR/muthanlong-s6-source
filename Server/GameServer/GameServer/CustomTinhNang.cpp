#include "StdAfx.h"
#include "user.h"
#include "CustomTinhNang.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "CommandManager.h"
//#include "CustomUyThacLevel.h"
#include "CustomAttack.h"
//#include "CustomNhiemVu.h"
#include "TuLuyen.h"
//#include "JewelBank.h"
//#include "CustomResetMasterGift.h"
#include "ObjectManager.h"
#include "ServerInfo.h"
#include "ShopSearch.h"
#include "MocNap.h"
#include "PhuKien.h"
#include "BossGuild.h"
#include "MuunPetCustom.h"
#include "VanThanhProtect.h"
#include "MuunAFK.h"

#if(TINHNANG_NEW == 1)

BUY_TINH_NANG gBUY_TINH_NANG;
// -------------------------------------------------------------------------------
BUY_TINH_NANG::BUY_TINH_NANG() // OK
{
}
// -------------------------------------------------------------------------------
BUY_TINH_NANG::~BUY_TINH_NANG() // OK
{
}
// -------------------------------------------------------------------------------
void BUY_TINH_NANG::BUY_TINH_NANG_GAME(LPOBJ lpObj, BUY_TINH_NANG_REQ *aRecv)
{
	//-----------------------------------------------
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
#endif
		gCommandManager.CommandReAdd(lpObj, "TayDiem", 1);
	}
	if (aRecv->Number == 2)
	{
#if(Fix_Dupe == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
#endif
		gCommandManager.CommandReMaster(lpObj, "TayDiemMaster", 1);
	}
	if (aRecv->Number == 3)
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
#endif
		gCommandManager.CommandChange(lpObj, "LamNhiemVu", 1);
	}
	//=================================================================================================
#if(UYTHACLEVEL_NEW)																				///
	if (aRecv->Number == 4)																			///
	{																								///
		///
		lpObj->AutoResetEnable = 1;																	///
		gCustomAttack.DGCustomAttackResumeSaveSend(lpObj->Index);									///
		gCustomUyThacLevel.CommandCustomUyThacLevelOffline(lpObj, "UyThacLevel");					///
	}																								///
#endif																								///
	//=================================================================================================
	if (aRecv->Number == 5)																			
	{																								
		gCommandManager.CommandResetAuto(lpObj, "AutoReset", 1);
	}																								
	if (aRecv->Number == 6)																			
	{																								
		gCustomAttack.CommandCustomAttack(lpObj, "attack");
	}																								
	//=================================================================================================
	if (aRecv->Number == 7)
	{
#if(BOSS_GUILD == 1)
		BossGuildDataSend(lpObj->Index);
#endif
	}
	if (aRecv->Number == 8)
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
#endif
		gCommandManager.CommandClearInventory(lpObj, "XoaHomDo");
	}
	//-----------------------------------------------

	// Cập Nhập cho Client
	if (aRecv->Number == 10)
	{
		GetInfoTinhNang(lpObj);
	}

	// Treo Offline
	if (aRecv->Number == 11)
	{
	   gCustomAttack.CommandCustomAttackOffline(lpObj, "offattack");
	}

	if (aRecv->Number == 12)
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
#endif
		gCommandManager.CommandLock(lpObj, "Lock");
		lpObj->Lock = 75112439324;
	}
	if (aRecv->Number == 13)
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
#endif
		gCommandManager.CommandUnLock(lpObj, "UnLock");
		lpObj->Lock = 75112439324;
		lpObj->Lock = 0;
	}

	if (aRecv->Number == 15)
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
#endif
		g_PersonalShopEx.RecShop(lpObj);
	}
	//================================================================================================
	if (aRecv->Number == 19)
	{
#if(MOCNAP == 1)
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
			return;
		}
		MocNapDataSend(lpObj->Index); // Send về client
#endif
	}
	//================================================================================================
#if(MOCNAP == 1)
	if (aRecv->Number == 20)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}

		gMocNap.MocNap1(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 21)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap2(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 22)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap3(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 23)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap4(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 24)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap5(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 25)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap6(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 26)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap7(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 27)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap8(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 28)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap9(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 29)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap10(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 30)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap11(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 31)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap12(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
	if (aRecv->Number == 32)
	{
		//27-03-2022
		if (gVanThanhProtect.MocNap == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng Mốc Nạp đang bảo trì!");
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
		lpObj->ClickClientSend = GetTickCount();

		if (lpObj->QUANAP.MOCNAPCOIN <= 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(773));
			return;
		}
		gMocNap.MocNap13(lpObj);
		MocNapDataSend(lpObj->Index); // Send về client
	}
	//================================================================================================
#endif
	//================================================================================================
	if (aRecv->Number == 33)
	{
		//27-03-2022
		if (gVanThanhProtect.MuunPetTime == 1)
		{
			gMuunPetCustom.TimeMuunPet(lpObj->Index, 1);
		}
	}
	//================================================================================================
#if(MUUNAFK == 1)
	if (aRecv->Number == 34)
	{
		gMuunAFK.TimeMuunPet(lpObj->Index, 1);
		MuunAFKDataSend(lpObj->Index);
	}
	if (aRecv->Number == 35)
	{
		gMuunAFK.HoiStamina(lpObj);
	}
	if (aRecv->Number == 36)
	{
		gMuunAFK.NhanWCoinClaim(lpObj);
	}
#endif

}
#endif


//case 0x22: // Xoa Do
//	gCommandManager.CommandClearInventory(lpObj, "xoado");
//	break;
//case 0x23: // Reset Auto
//	gCommandManager.CommandResetAuto(lpObj, "auto");
//	break;
//case 0x24: // Lam Nhiem Vu
//	gCommandManager.CommandChange(lpObj, 0);
//	break;
//case 0x25: // Attack
//	gCustomAttack.CommandCustomAttack(lpObj, "attack");
//	break;
//case 0x26: // OffAttack
//	gCustomAttack.CommandCustomAttackOffline(lpObj, "offattack");
//	break;
//case 0x27: // Tay Diem
//	gCommandManager.CommandResetPoint(lpObj);
//	break;
//case 0x28: // Tay Diem Master
//	gCommandManager.CommandResetMaster(lpObj);
//	break;
//	//=============================================================================
//case 0x29: // Doi Class DW
//	gCommandManager.CommandChangeClass(lpObj, "dw");
//	break;
//case 0x30: // Doi  Class DK
//	gCommandManager.CommandChangeClass(lpObj, "dk");
//	break;
//case 0x31: // Doi  Class ELF
//	gCommandManager.CommandChangeClass(lpObj, "elf");
//	break;
//case 0x32: // Doi  Class MG
//	gCommandManager.CommandChangeClass(lpObj, "mg");
//	break;
//case 0x33: // Doi  Class DL
//	gCommandManager.CommandChangeClass(lpObj, "dl");
//	break;
//case 0x34: // Doi  Class SU
//	gCommandManager.CommandChangeClass(lpObj, "su");
//	break;
//case 0x35: // Doi  Class RF
//	gCommandManager.CommandChangeClass(lpObj, "rf");
//	break;
//	//=============================================================================
//case 0x36: // Thue Vip 01
//	gRankVip.SendRank_01(lpObj);
//	break;
//case 0x37: // Thue Vip 02
//	gRankVip.SendRank_02(lpObj);
//	break;
//case 0x38: // Thue Vip 03
//	gRankVip.SendRank_03(lpObj);
//	break;
//case 0x39: // Thue Vip 04
//	gRankVip.SendRank_04(lpObj);
//	break;
//	//=============================================================================
//case 0x40: // Auto Nhat Ngoc
//	gCustomPick.CommandPick(lpObj, "NgocTamLinh");
//	break;
//case 0x41: // Auto Nhat Ngoc
//	gCustomPick.CommandPick(lpObj, "NgocUocNguyen");
//	break;
//case 0x42: // Auto Nhat Ngoc
//	gCustomPick.CommandPick(lpObj, "NgocHonNguyen");
//	break;
//case 0x43: // Auto Nhat Ngoc
//	gCustomPick.CommandPick(lpObj, "NgocSinhMenh");
//	break;
//case 0x44: // Auto Nhat Ngoc
//	gCustomPick.CommandPick(lpObj, "NgocSangTao");
//	break;
//case 0x45: // Auto Nhat Ngoc
//	gCustomPick.CommandPick(lpObj, "LongVu");
//	break;
//	//=============================================================================
//case 0x46:
//	gJewelMix.CommandJewelMix(lpObj, "soul 10");
//	break;
//case 0x47:
//	gJewelMix.CommandJewelMix(lpObj, "soul 20");
//	break;
//case 0x48:
//	gJewelMix.CommandJewelMix(lpObj, "soul 30");
//	break;
//	//----------------------------------------------
//case 0x49:
//	gJewelMix.CommandJewelMix(lpObj, "bless 10");
//	break;
//case 0x50:
//	gJewelMix.CommandJewelMix(lpObj, "bless 20");
//	break;
//case 0x51:
//	gJewelMix.CommandJewelMix(lpObj, "bless 30");
//	break;
//	//----------------------------------------------