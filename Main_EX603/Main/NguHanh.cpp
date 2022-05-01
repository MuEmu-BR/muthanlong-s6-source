#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "NguHanh.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "Other.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Import.h"

#if(NGU_HANH_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_NGUHANH G_BEXO_NGUHANH;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_NGUHANH::BEXO_NGUHANH()
{
	//--------------------------------------------------------------
	HIENTHINGUHANH = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_NGUHANH::DRAW_NGUHANH()
{
	DRAW_WINDOW_NGUHANH();
}

void BEXO_NGUHANH::DRAW_WINDOW_NGUHANH()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_NGUHANH_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 200, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 50, 280, 300, 0.0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_NGUHANH_CLOSE, StartX + 450, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 48);
	if (gInterface.IsWorkZone(EXBEXO_NGUHANH_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_NGUHANH_CLOSE, gInterface.Data[EXBEXO_NGUHANH_CLOSE].X, gInterface.Data[EXBEXO_NGUHANH_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XNGUHANH = 220;

	gInterface.DrawFormat(eGold, XNGUHANH + 75, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 80, 70, 3, gOther.TextVN[100]);

	gInterface.DrawFormat(eWhite, XNGUHANH + 145, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 80, 70, 1, "%d/5", m_rNguHanh);

	gInterface.DrawFormat(eYellow, XNGUHANH + 70, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 100, 150, 1, gOther.TextVN[101]);

	gCItemSetOption.ItemTooltipS15(XNGUHANH + 70, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 115, 105, 150, 0.0, 0);

	pDrawGUI(0x9596, XNGUHANH + 80, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 120, 17, 17);
	pDrawGUI(0x9597, XNGUHANH + 80, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 150, 17, 17);
	pDrawGUI(0x9598, XNGUHANH + 80, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 180, 17, 17);
	pDrawGUI(0x9599, XNGUHANH + 80, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 210, 17, 17);
	pDrawGUI(0x9600, XNGUHANH + 80, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 240, 17, 17);

	gInterface.DrawFormat(eWhite, XNGUHANH + 100, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 123, 150, 1, gOther.TextVN[121]);
	gInterface.DrawFormat(eWhite, XNGUHANH + 100, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 153, 150, 1, gOther.TextVN[122]);
	gInterface.DrawFormat(eWhite, XNGUHANH + 100, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 183, 150, 1, gOther.TextVN[123]);
	gInterface.DrawFormat(eWhite, XNGUHANH + 100, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 213, 150, 1, gOther.TextVN[124]);
	gInterface.DrawFormat(eWhite, XNGUHANH + 100, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 243, 150, 1, gOther.TextVN[125]);

	gInterface.DrawItem2(XNGUHANH + 75, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 70, 100, 100, GET_ITEM(12, 15), 0, 1, 0, 0); // Ngọc hỗn nguyên
	gInterface.DrawItem2(XNGUHANH + 75, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 70, 100, 100, GET_ITEM(14, 13), 0, 1, 0, 0); // Ngọc ước nguyện
	gInterface.DrawItem2(XNGUHANH + 75, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 100, 100, 100, GET_ITEM(14, 14), 0, 1, 0, 0); // Ngọc tâm linh
	gInterface.DrawItem2(XNGUHANH + 75, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 130, 100, 100, GET_ITEM(14, 16), 0, 1, 0, 0); // Ngọc sinh mệnh
	gInterface.DrawItem2(XNGUHANH + 75, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 160, 100, 100, GET_ITEM(14, 22), 0, 1, 0, 0); // Ngọc sáng tạo

	gInterface.DrawFormat(eYellow, XNGUHANH + 130, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 123, 150, 1, "x30");
	gInterface.DrawFormat(eYellow, XNGUHANH + 130, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 153, 150, 1, "x30");
	gInterface.DrawFormat(eYellow, XNGUHANH + 130, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 183, 150, 1, "x30");
	gInterface.DrawFormat(eYellow, XNGUHANH + 130, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 213, 150, 1, "x30");
	gInterface.DrawFormat(eYellow, XNGUHANH + 130, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 243, 150, 1, "x30");

	pDrawGUI(0x9992, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 121, 15, 15);
	pDrawGUI(0x9992, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 151, 15, 15);
	pDrawGUI(0x9992, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 181, 15, 15);
	pDrawGUI(0x9992, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 211, 15, 15);
	pDrawGUI(0x9992, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 241, 15, 15);

	if (this->m_rNguHanh >= 1)
	{
		pDrawGUI(0x9991, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 121, 15, 15);
	}
	if (this->m_rNguHanh >= 2)
	{
		pDrawGUI(0x9991, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 151, 15, 15);
	}
	if (this->m_rNguHanh >= 3)
	{
		pDrawGUI(0x9991, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 181, 15, 15);
	}
	if (this->m_rNguHanh >= 4)
	{
		pDrawGUI(0x9991, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 211, 15, 15);
	}
	if (this->m_rNguHanh >= 5)
	{
		pDrawGUI(0x9991, XNGUHANH + 150, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 241, 15, 15);
	}

	gInterface.DrawGUI(eNGUHANH, XNGUHANH + 70, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 280);
	gInterface.DrawFormat(eGold, XNGUHANH + 45, gInterface.Data[EXBEXO_NGUHANH_MAIN].Y + 288, 160, 3, gOther.TextVN[102]);

	if (gInterface.IsWorkZone(eNGUHANH))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eNGUHANH, gInterface.Data[eNGUHANH].X, gInterface.Data[eNGUHANH].Y, Color);
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_NGUHANH::MAIN_NGUHANH(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_NGUHANH(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_NGUHANH_MAIN].OnShow && gInterface.IsWorkZone(eNGUHANH))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eNGUHANH].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eNGUHANH].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eNGUHANH].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eNGUHANH].EventTick = GetTickCount();
		this->BUY_NGU_HANH(1);
	}
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_NGUHANH::CLOSE_NGUHANH(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_NGUHANH_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_NGUHANH_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_NGUHANH_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_NGUHANH_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_NGUHANH_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_NGUHANH_CLOSE].EventTick = GetTickCount();
	G_BEXO_NGUHANH.CLOSE_WINDOW_NGUHANH();
	// ----
	return false;
}

void BEXO_NGUHANH::BUY_NGU_HANH(int Number)
{
	BUY_NGU_HANH_REQ pMsg;
	pMsg.h.set(0xFC, 0x07, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_NGUHANH::GetInfoNguHanh(PMSG_NGUHANH_UPD * aRecv)
{
	//-----------------------------
	this->m_rNguHanh = aRecv->rNguHanh;
	//-----------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif