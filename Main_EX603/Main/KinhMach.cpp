#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "KinhMach.h"
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
#include "Central.h"

#if(KINH_MACH_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_KINHMACH G_BEXO_KINHMACH;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_KINHMACH::BEXO_KINHMACH()
{
	//--------------------------------------------------------------
	HIENTHIKINHMACH = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_KINHMACH::DRAW_KINHMACH()
{
	DRAW_WINDOW_KINHMACH();
}

void BEXO_KINHMACH::DRAW_WINDOW_KINHMACH()
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
	if (!gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow)
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
	//gCItemSetOption.ItemTooltipS15(StartX + 190, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 50, 310, 300, 0.0, 0);
	gCentral.PrintDropBox(StartX + 190, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 50, 310, 300, 0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_KINHMACH_CLOSE, StartX + 470, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 48);
	if (gInterface.IsWorkZone(EXBEXO_KINHMACH_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_KINHMACH_CLOSE, gInterface.Data[EXBEXO_KINHMACH_CLOSE].X, gInterface.Data[EXBEXO_KINHMACH_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XKINHMACH = 210;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eKINHMACH1, XKINHMACH - 15, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 60);
	gInterface.DrawGUI(eKINHMACH2, XKINHMACH + 90, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 60);
	gInterface.DrawGUI(eKINHMACH3, XKINHMACH + 195, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 60);

	gInterface.DrawGUI(eKINHMACH4, XKINHMACH + 30, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 160);
	gInterface.DrawGUI(eKINHMACH5, XKINHMACH + 150, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 160);

	gInterface.DrawGUI(eKINHMACH6, XKINHMACH - 15, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 260);
	gInterface.DrawGUI(eKINHMACH7, XKINHMACH + 90, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 260);
	gInterface.DrawGUI(eKINHMACH8, XKINHMACH + 195, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 260);

	gCItemSetOption.ItemTooltipS15(XKINHMACH + 45, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 110, 20, 15, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(XKINHMACH + 160, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 110, 20, 15, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(XKINHMACH + 265, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 110, 20, 15, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(XKINHMACH + 20, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 210, 20, 15, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(XKINHMACH + 220, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 210, 20, 15, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(XKINHMACH + 55, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 310, 20, 15, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(XKINHMACH + 160, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 310, 20, 15, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(XKINHMACH + 265, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 310, 20, 15, 0.0, 0);

	gInterface.DrawFormat(eWhite, XKINHMACH + 50, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 113, 300, 1, "%d", this->m_KINHMACH1);
	gInterface.DrawFormat(eWhite, XKINHMACH + 165, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 113, 300, 1, "%d", this->m_KINHMACH2);
	gInterface.DrawFormat(eWhite, XKINHMACH + 270, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 113, 300, 1, "%d", this->m_KINHMACH3);

	gInterface.DrawFormat(eWhite, XKINHMACH + 25, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 213, 300, 1, "%d", this->m_KINHMACH4);
	gInterface.DrawFormat(eWhite, XKINHMACH + 225, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 213, 300, 1, "%d", this->m_KINHMACH5);

	gInterface.DrawFormat(eWhite, XKINHMACH + 60, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 313, 300, 1, "%d", this->m_KINHMACH6);
	gInterface.DrawFormat(eWhite, XKINHMACH + 165, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 313, 300, 1, "%d", this->m_KINHMACH7);
	gInterface.DrawFormat(eWhite, XKINHMACH + 270, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 313, 300, 1, "%d", this->m_KINHMACH8);


	if (gInterface.IsWorkZone(eKINHMACH1))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH - 25, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 130, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH - 20, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 133, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_01);

		gInterface.DrawItem2(XKINHMACH - 40, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 80, 100, 100, GET_ITEM(12, 15), 0, 1, 0, 0); // Ngọc hỗn nguyên

		gInterface.DrawFormat(eYellow, XKINHMACH + 15, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 133, 300, 1, "x10");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH - 25, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 146, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH - 5, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 149, 300, 1, gOther.TextVN[112], this->m_KINHMACH1);
		//---

		gInterface.DrawColoredGUI(eKINHMACH1, gInterface.Data[eKINHMACH1].X, gInterface.Data[eKINHMACH1].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH2))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 90, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 130, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH + 95, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 133, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_02);

		gInterface.DrawItem2(XKINHMACH + 75, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 52, 100, 100, GET_ITEM(14, 13), 0, 1, 0, 0); // Ngọc Ước Nguyện

		gInterface.DrawFormat(eYellow, XKINHMACH + 130, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 133, 300, 1, "x30");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 90, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 146, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH + 100, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 149, 300, 1, gOther.TextVN[113], this->m_KINHMACH2);
		//---

		gInterface.DrawColoredGUI(eKINHMACH2, gInterface.Data[eKINHMACH2].X, gInterface.Data[eKINHMACH2].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH3))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 195, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 130, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH + 200, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 133, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_03);

		gInterface.DrawItem2(XKINHMACH + 180, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 52, 100, 100, GET_ITEM(14, 14), 0, 1, 0, 0); // Ngọc Tâm Linh

		gInterface.DrawFormat(eYellow, XKINHMACH + 235, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 133, 300, 1, "x20");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 195, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 146, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH + 210, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 149, 300, 1, gOther.TextVN[114], this->m_KINHMACH3);
		//---

		gInterface.DrawColoredGUI(eKINHMACH3, gInterface.Data[eKINHMACH3].X, gInterface.Data[eKINHMACH3].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH4))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 20, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 230, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH + 30, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_04);

		gInterface.DrawItem2(XKINHMACH + 10, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 152, 100, 100, GET_ITEM(14, 16), 0, 1, 0, 0); // Ngọc Sinh Mệnh

		gInterface.DrawFormat(eYellow, XKINHMACH + 65, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 300, 1, "x30");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 20, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 246, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH + 35, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 249, 300, 1, gOther.TextVN[115], this->m_KINHMACH1);
		//---

		gInterface.DrawColoredGUI(eKINHMACH4, gInterface.Data[eKINHMACH4].X, gInterface.Data[eKINHMACH4].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH5))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 150, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 230, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH + 157, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_05);

		gInterface.DrawItem2(XKINHMACH + 139, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 152, 100, 100, GET_ITEM(14, 22), 0, 1, 0, 0); // Ngọc Sáng Tạo

		gInterface.DrawFormat(eYellow, XKINHMACH + 197, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 300, 1, "x30");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 150, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 246, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH + 180, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 249, 300, 1, gOther.TextVN[116], this->m_KINHMACHSD);
		//---

		gInterface.DrawColoredGUI(eKINHMACH5, gInterface.Data[eKINHMACH5].X, gInterface.Data[eKINHMACH5].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH6))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH - 25, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH - 20, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 236, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_06);

		gInterface.DrawItem2(XKINHMACH - 40, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 192, 100, 100, GET_ITEM(14, 31), 0, 1, 0, 0); // Đá Hộ Mệnh


		gInterface.DrawFormat(eYellow, XKINHMACH + 15, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 236, 300, 1, "x10");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH - 25, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 249, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH - 5, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 252, 300, 1, gOther.TextVN[117], this->m_KINHMACHHP);
		//---

		gInterface.DrawColoredGUI(eKINHMACH6, gInterface.Data[eKINHMACH6].X, gInterface.Data[eKINHMACH6].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH7))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 90, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH + 95, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 236, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_07);

		gInterface.DrawItem2(XKINHMACH + 77, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 154, 100, 100, GET_ITEM(14, 41), 0, 1, 0, 0); // Đá Nguyên Thủy

		gInterface.DrawFormat(eYellow, XKINHMACH + 135, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 236, 300, 1, "x30");

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 90, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 249, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH + 95, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 252, 300, 1, gOther.TextVN[118], this->m_KINHMACH7);
		//---

		gInterface.DrawColoredGUI(eKINHMACH7, gInterface.Data[eKINHMACH7].X, gInterface.Data[eKINHMACH7].Y, Color);
	}
	if (gInterface.IsWorkZone(eKINHMACH8))
	{
		DWORD Color = eGray150;

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 195, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 233, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eWhite, XKINHMACH + 200, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 236, 300, 1, gOther.TextVN[111], this->m_MAX_KINH_MACH_08);

		gInterface.DrawItem2(XKINHMACH + 180, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 154, 100, 100, GET_ITEM(13, 14), 0, 1, 0, 0); // Lông vũ

		//---
		gCItemSetOption.ItemTooltipS15(XKINHMACH + 195, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 249, 90, 15, 0.0, 0);

		gInterface.DrawFormat(eYellow, XKINHMACH + 210, gInterface.Data[EXBEXO_KINHMACH_MAIN].Y + 252, 300, 1, gOther.TextVN[119], this->m_KINHMACH8);
		//---

		gInterface.DrawColoredGUI(eKINHMACH8, gInterface.Data[eKINHMACH8].X, gInterface.Data[eKINHMACH8].Y, Color);
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_KINHMACH::MAIN_KINHMACH(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_KINHMACH(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH1].EventTick = GetTickCount();
		this->BUY_KINH_MACH(1);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH2].EventTick = GetTickCount();
		this->BUY_KINH_MACH(2);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH3))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH3].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH3].EventTick = GetTickCount();
		this->BUY_KINH_MACH(3);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH4))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH4].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH4].EventTick = GetTickCount();
		this->BUY_KINH_MACH(4);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH5))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH5].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH5].EventTick = GetTickCount();
		this->BUY_KINH_MACH(5);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH6))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH6].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH6].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH6].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH6].EventTick = GetTickCount();
		this->BUY_KINH_MACH(6);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH7))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH7].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH7].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH7].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH7].EventTick = GetTickCount();
		this->BUY_KINH_MACH(7);
	}
	if (gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow && gInterface.IsWorkZone(eKINHMACH8))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eKINHMACH8].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eKINHMACH8].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eKINHMACH8].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eKINHMACH8].EventTick = GetTickCount();
		this->BUY_KINH_MACH(8);
	}
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_KINHMACH::CLOSE_KINHMACH(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_KINHMACH_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_KINHMACH_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_KINHMACH_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_KINHMACH_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_KINHMACH_CLOSE].EventTick = GetTickCount();
	G_BEXO_KINHMACH.CLOSE_WINDOW_KINHMACH();
	// ----
	return false;
}

void BEXO_KINHMACH::BUY_KINH_MACH(int Number)
{
	BUY_KINH_MACH_REQ pMsg;
	pMsg.h.set(0xFC, 0x06, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void BEXO_KINHMACH::GetInfoKinhMach(PMSG_KINHMACH_UPD * aRecv)
{
	this->m_KINHMACH1 = aRecv->KINHMACH1;
	this->m_KINHMACH2 = aRecv->KINHMACH2;
	this->m_KINHMACH3 = aRecv->KINHMACH3;
	this->m_KINHMACH4 = aRecv->KINHMACH4;
	this->m_KINHMACH5 = aRecv->KINHMACH5;
	this->m_KINHMACH6 = aRecv->KINHMACH6;
	this->m_KINHMACH7 = aRecv->KINHMACH7;
	this->m_KINHMACH8 = aRecv->KINHMACH8;
	this->m_KINHMACHSD = aRecv->KINHMACHSD;
	this->m_KINHMACHHP = aRecv->KINHMACHHP;
}
void BEXO_KINHMACH::GetInfoKinhMachLevel(PMSG_KINHMACH_LEVEL_UPD * aRecv)
{
	this->m_MAX_KINH_MACH_01 = aRecv->MAX_KINH_MACH_01;
	this->m_MAX_KINH_MACH_02 = aRecv->MAX_KINH_MACH_02;
	this->m_MAX_KINH_MACH_03 = aRecv->MAX_KINH_MACH_03;
	this->m_MAX_KINH_MACH_04 = aRecv->MAX_KINH_MACH_04;
	this->m_MAX_KINH_MACH_05 = aRecv->MAX_KINH_MACH_05;
	this->m_MAX_KINH_MACH_06 = aRecv->MAX_KINH_MACH_06;
	this->m_MAX_KINH_MACH_07 = aRecv->MAX_KINH_MACH_07;
	this->m_MAX_KINH_MACH_08 = aRecv->MAX_KINH_MACH_08;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif