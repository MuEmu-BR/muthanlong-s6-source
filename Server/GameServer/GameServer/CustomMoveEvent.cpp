#include "StdAfx.h"
#include "user.h"
#include "CustomMoveEvent.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CommandManager.h"
#include "ObjectManager.h"
#include "ServerInfo.h"

#if(MOVE_EVENT_NEW == 1)

MOVE_EVENT gMOVE_EVENT;
// -------------------------------------------------------------------------------
MOVE_EVENT::MOVE_EVENT() // OK
{
}
// -------------------------------------------------------------------------------
MOVE_EVENT::~MOVE_EVENT() // OK
{
}
// -------------------------------------------------------------------------------
void MOVE_EVENT::MOVE_EVENT_GAME(LPOBJ lpObj, MOVE_EVENT_REQ *aRecv)
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
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();

		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent1);
	}
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent2);
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
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent3);
	}
	if (aRecv->Number == 4)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent4);
	}
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent5);
	}
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent6);
	}
	if (aRecv->Number == 7)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent7);
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
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent8);
	}
	if (aRecv->Number == 9)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent9);
	}
	if (aRecv->Number == 10)
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
		lpObj->ClickClientSend = GetTickCount();
		//gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent10);
		gCommandManager.CommandPKEvent(lpObj);
	}
	//---------------------------------------------------------------------------------------------
	if (aRecv->Number == 11) // Rồng Đỏ
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
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunRongDo == 0)
		{
			lpObj->MoveEventRunRongDo++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent11);
		}
		else if (lpObj->MoveEventRunRongDo == 1)
		{
			lpObj->MoveEventRunRongDo++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent12);
		}
		else if (lpObj->MoveEventRunRongDo == 2)
		{
			lpObj->MoveEventRunRongDo++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent13);
		}
		else if (lpObj->MoveEventRunRongDo == 3)
		{
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent14);
			lpObj->MoveEventRunRongDo = 0;
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Quái Vật Rồng Đỏ] vị trí %d/4", lpObj->MoveEventRunRongDo);
	}
	//---------------------------------------------------------------------------------------------
	// Move Boss Hoàng Kim
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
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunHoangKim == 0)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent15);
		}
		else if (lpObj->MoveEventRunHoangKim == 1)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent16);
		}
		else if (lpObj->MoveEventRunHoangKim == 2)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent17);
		}
		else if (lpObj->MoveEventRunHoangKim == 3)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent18);
		}
		else if (lpObj->MoveEventRunHoangKim == 4)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent19);
		}
		else if (lpObj->MoveEventRunHoangKim == 5)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent20);
		}
		else if (lpObj->MoveEventRunHoangKim == 6)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent21);
		}
		else if (lpObj->MoveEventRunHoangKim == 7)
		{
			lpObj->MoveEventRunHoangKim++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent22);
		}
		else if (lpObj->MoveEventRunHoangKim == 8)
		{
			lpObj->MoveEventRunHoangKim = 0;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent23);
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Quái Vật Hoàng Kim] vị trí %d/9", lpObj->MoveEventRunHoangKim);
	}
	//---------------------------------------------------------------------------------------------
	// Move Binh Đoàn Phù Thủy
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
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunPhuThuy == 0)
		{
			lpObj->MoveEventRunPhuThuy++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent24);
		}
		else if (lpObj->MoveEventRunPhuThuy == 1)
		{
			lpObj->MoveEventRunPhuThuy++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent25);
		}
		else if (lpObj->MoveEventRunPhuThuy == 2)
		{
			lpObj->MoveEventRunPhuThuy = 0;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent26);
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Binh Đoàn Phù Thủy] vị trí %d/3", lpObj->MoveEventRunPhuThuy);
	}
	//---------------------------------------------------------------------------------------------
	// Move Junie
	if (aRecv->Number == 14)
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
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunJunie == 0)
		{
			lpObj->MoveEventRunJunie++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent27);
		}
		else if (lpObj->MoveEventRunJunie == 1)
		{
			lpObj->MoveEventRunJunie++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent28);
		}
		else if (lpObj->MoveEventRunJunie == 2)
		{
			lpObj->MoveEventRunJunie++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent29);
		}
		else if (lpObj->MoveEventRunJunie == 3)
		{
			lpObj->MoveEventRunJunie++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent30);
		}
		else if (lpObj->MoveEventRunJunie == 4)
		{
			lpObj->MoveEventRunJunie = 0;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent31);
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Junie] vị trí %d/5", lpObj->MoveEventRunJunie);
	}
	//---------------------------------------------------------------------------------------------
	// Move Thỏ Ngọc
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
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunThoNgoc == 0)
		{
			lpObj->MoveEventRunThoNgoc++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent32);
		}
		else if (lpObj->MoveEventRunThoNgoc == 1)
		{
			lpObj->MoveEventRunThoNgoc++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent33);
		}
		else if (lpObj->MoveEventRunThoNgoc == 2)
		{
			lpObj->MoveEventRunThoNgoc++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent34);
		}
		else if (lpObj->MoveEventRunThoNgoc == 3)
		{
			lpObj->MoveEventRunThoNgoc = 0;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent35);
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Thỏ Ngọc] vị trí %d/4", lpObj->MoveEventRunThoNgoc);
	}
	//---------------------------------------------------------------------------------------------
	// Move Hỏa Diệm Quỷ
	if (aRecv->Number == 16)
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
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunHoaDiemQuy == 0)
		{
			lpObj->MoveEventRunHoaDiemQuy++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent36);
		}
		else if (lpObj->MoveEventRunHoaDiemQuy == 1)
		{
			lpObj->MoveEventRunHoaDiemQuy++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent37);
		}
		else if (lpObj->MoveEventRunHoaDiemQuy == 2)
		{
			lpObj->MoveEventRunHoaDiemQuy++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent38);
		}
		else if (lpObj->MoveEventRunHoaDiemQuy == 3)
		{
			lpObj->MoveEventRunHoaDiemQuy = 0;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent39);
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Hỏa Diệm Quỷ] vị trí %d/4", lpObj->MoveEventRunHoaDiemQuy);
	}
	//---------------------------------------------------------------------------------------------
	// Move Santa
	if (aRecv->Number == 17)
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
		lpObj->ClickClientSend = GetTickCount();
		if (lpObj->MoveEventRunSanta == 0)
		{
			lpObj->MoveEventRunSanta++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent40);
		}
		else if (lpObj->MoveEventRunSanta == 1)
		{
			lpObj->MoveEventRunSanta++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent41);
		}
		else if (lpObj->MoveEventRunSanta == 2)
		{
			lpObj->MoveEventRunSanta++;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent42);
		}
		else if (lpObj->MoveEventRunSanta == 3)
		{
			lpObj->MoveEventRunSanta = 0;
			gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent43);
		}

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Di chuyển đến Event[Santa] vị trí %d/4", lpObj->MoveEventRunSanta);
	}
	//---------------------------------------------------------------------------------------------
	if (aRecv->Number == 18)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent44);
	}
	//---------------------------------------------------------------------------------------------
	if (aRecv->Number == 19)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent45);
	}
	//---------------------------------------------------------------------------------------------
	if (aRecv->Number == 20)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent46);
	}
	//---------------------------------------------------------------------------------------------
	if (aRecv->Number == 21)
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
		lpObj->ClickClientSend = GetTickCount();
		gObjMoveGate(lpObj->Index, gServerInfo.GateMoveEvent47);
	}
}
#endif
