#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "TaiSinh.h"
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
#include "User.h"
#include "JewelBank.h"

#if(TAISINH == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_TAISINH G_BEXO_TAISINH;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_TAISINH::BEXO_TAISINH()
{
	//--------------------------------------------------------------
	HIENTHITAISINH = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_TAISINH::BIND()
{
	gInterface.BindObject(EXBEXO_TAISINH_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_TAISINH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(TAISINH1, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH2, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH3, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH4, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH5, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH6, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH7, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH8, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH9, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(TAISINH10, 0x7A5E, 108, 29, -1, -1);
}
// ----------------------------------------------------------------------------------------------


void BEXO_TAISINH::DRAW_TAISINH()
{
	DRAW_WINDOW_TAISINH();
}

void BEXO_TAISINH::DRAW_WINDOW_TAISINH()
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
	if (!gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow)
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
	gCentral.PrintDropBox(StartX + 200, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 25, 230, 300, 0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_TAISINH_CLOSE, StartX + 400, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 23);
	if (gInterface.IsWorkZone(EXBEXO_TAISINH_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_TAISINH_CLOSE, gInterface.Data[EXBEXO_TAISINH_CLOSE].X, gInterface.Data[EXBEXO_TAISINH_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XTAISINH = 170;

	if (gObjUser.m_TaiSinh == 1)
	{
		gInterface.DrawFormat(eGold, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 30, 200, 3, "Tái Sinh");
	}

	if (gObjUser.m_TrungSinh == 1)
	{
		gInterface.DrawFormat(eGold, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 30, 200, 3, "Trùng Sinh");
	}

	gCItemSetOption.ItemTooltipS15(XTAISINH + 110, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 60, 70, 15, 0.0, 0);
	gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 63, 200, 3, "Yêu Cầu");
	gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 85, 200, 15, 0.0, 0);

	float flDrawY = StartY + 100;
	flDrawY += 6;
	gCItemSetOption.ItemTooltipS15(XTAISINH + 45, flDrawY, 200, 15, 0.0, 0);
	flDrawY += 22;
	gCItemSetOption.ItemTooltipS15(XTAISINH + 45, flDrawY, 200, 15, 0.0, 0);
	flDrawY += 22;
	gCItemSetOption.ItemTooltipS15(XTAISINH + 45, flDrawY, 200, 15, 0.0, 0);
	flDrawY += 22;
	gCItemSetOption.ItemTooltipS15(XTAISINH + 45, flDrawY, 200, 15, 0.0, 0);
	flDrawY += 22;
	gCItemSetOption.ItemTooltipS15(XTAISINH + 45, flDrawY, 200, 15, 0.0, 0);
	//----
	flDrawY += -83;
	gJewelBank.DrawLineTaiSinh(12, 15, 1, XTAISINH + 70, flDrawY, "Ngọc Hỗn Nguyên", gObjUser.JChaos);
	flDrawY += 22;
	gJewelBank.DrawLineTaiSinh(14, 13, 2, XTAISINH + 70, flDrawY, "Ngọc Ước Nguyện", gObjUser.JBless);
	flDrawY += 22;
	gJewelBank.DrawLineTaiSinh(14, 14, 3, XTAISINH + 70, flDrawY, "Ngọc Tâm Linh", gObjUser.JSoul);
	flDrawY += 22;
	gJewelBank.DrawLineTaiSinh(14, 16, 4, XTAISINH + 70, flDrawY, "Ngọc Sinh Mệnh", gObjUser.JLife);
	flDrawY += 22;
	gJewelBank.DrawLineTaiSinh(14, 22, 5, XTAISINH + 70, flDrawY, "Ngọc Sáng Tạo", gObjUser.JCreation);
	//---
	if (ViewReset <= gObjUser.DieuKien01)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien01);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc01Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc01Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc01Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc01Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc01Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh01);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh01);
		}
		// Click
		gInterface.DrawGUI(TAISINH1, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH1))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH1, gInterface.Data[TAISINH1].X, gInterface.Data[TAISINH1].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 2
	if (ViewReset > gObjUser.DieuKien01 && ViewReset <= gObjUser.DieuKien02)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien02);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc02Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc02Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc02Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc02Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc02Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh02);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh02);
		}
		// Click
		gInterface.DrawGUI(TAISINH2, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH2))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH2, gInterface.Data[TAISINH2].X, gInterface.Data[TAISINH2].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 3
	if (ViewReset > gObjUser.DieuKien02 && ViewReset <= gObjUser.DieuKien03)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien03);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc03Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc03Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc03Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc03Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc03Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh03);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh03);
		}
		// Click
		gInterface.DrawGUI(TAISINH3, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH3))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH3, gInterface.Data[TAISINH3].X, gInterface.Data[TAISINH3].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 4
	if (ViewReset > gObjUser.DieuKien03 && ViewReset <= gObjUser.DieuKien04)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien04);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc04Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc04Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc04Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc04Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc04Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh04);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh04);
		}
		// Click
		gInterface.DrawGUI(TAISINH4, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH4))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH4, gInterface.Data[TAISINH4].X, gInterface.Data[TAISINH4].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 5
	if (ViewReset > gObjUser.DieuKien04 && ViewReset <= gObjUser.DieuKien05)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien05);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc05Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc05Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc05Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc05Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc05Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh05);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh05);
		}
		// Click
		gInterface.DrawGUI(TAISINH5, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH5))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH5, gInterface.Data[TAISINH5].X, gInterface.Data[TAISINH5].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 6
	if (ViewReset > gObjUser.DieuKien05 && ViewReset <= gObjUser.DieuKien06)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien06);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc06Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc06Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc06Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc06Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc06Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh06);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh06);
		}
		// Click
		gInterface.DrawGUI(TAISINH6, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH6))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH6, gInterface.Data[TAISINH6].X, gInterface.Data[TAISINH6].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 7
	if (ViewReset > gObjUser.DieuKien06 && ViewReset <= gObjUser.DieuKien07)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien07);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc07Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc07Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc07Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc07Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc07Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh07);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh07);
		}
		// Click
		gInterface.DrawGUI(TAISINH7, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH7))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH7, gInterface.Data[TAISINH7].X, gInterface.Data[TAISINH7].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 8
	if (ViewReset > gObjUser.DieuKien07 && ViewReset <= gObjUser.DieuKien08)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien08);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc08Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc08Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc08Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc08Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc08Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh08);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh08);
		}
		// Click
		gInterface.DrawGUI(TAISINH8, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH8))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH8, gInterface.Data[TAISINH8].X, gInterface.Data[TAISINH8].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 9
	if (ViewReset > gObjUser.DieuKien08 && ViewReset <= gObjUser.DieuKien09)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien09);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc09Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc09Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc09Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc09Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc09Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh09);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh09);
		}
		// Click
		gInterface.DrawGUI(TAISINH9, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH9))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH9, gInterface.Data[TAISINH9].X, gInterface.Data[TAISINH9].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 10
	if (ViewReset > gObjUser.DieuKien09 && ViewReset <= gObjUser.DieuKien10)
	{
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien10);
		//----
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc10Chaos);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc10Bless);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc10Soul);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc10Life);
		gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc10Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh10);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh10);
		}
		// Click
		gInterface.DrawGUI(TAISINH10, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		if (gInterface.IsWorkZone(TAISINH10))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(TAISINH10, gInterface.Data[TAISINH10].X, gInterface.Data[TAISINH10].Y, Color);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------
	// Lần 11 loading
	if (ViewReset > gObjUser.DieuKien10)
	{
		
		gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "loading...");

		//gInterface.DrawFormat(eOrange, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 88, 200, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, gObjUser.m_DieuKienLevel, ViewReset, gObjUser.DieuKien10);
		////----
		//gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 109, 200, 3, " %d /", gObjUser.DieuKienNgoc10Chaos);
		//gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 131, 200, 3, " %d /", gObjUser.DieuKienNgoc10Bless);
		//gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 153, 200, 3, " %d /", gObjUser.DieuKienNgoc10Soul);
		//gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 175, 200, 3, " %d /", gObjUser.DieuKienNgoc10Life);
		//gInterface.DrawFormat(eSocket, XTAISINH + 102, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 197, 200, 3, " %d /", gObjUser.DieuKienNgoc10Cre);
		//----
		if (gObjUser.m_TaiSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "loading...");
			//gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Tái tạo điểm về mốc");
			//gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTaiSinh10);
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			// Nhận đc
			gCItemSetOption.ItemTooltipS15(XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 230, 200, 35, 0.0, 0);
			gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "loading...");
			//gInterface.DrawFormat(eWhite, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 233, 200, 3, "Điểm được cộng thêm");
			//gInterface.DrawFormat(eExcellent, XTAISINH + 45, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 251, 200, 3, "Điểm đạt được %d", gObjUser.DiemPointTrungSinh10);
		}
		// Click
		//gInterface.DrawGUI(TAISINH10, XTAISINH + 90, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 280);
		//gInterface.DrawFormat(eGold, XTAISINH + 50, gInterface.Data[EXBEXO_TAISINH_MAIN].Y + 290, 200, 3, "Đồng ý");
		//if (gInterface.IsWorkZone(TAISINH10))
		//{
		//	DWORD Color = eGray150;
		//	gInterface.DrawColoredGUI(TAISINH10, gInterface.Data[TAISINH10].X, gInterface.Data[TAISINH10].Y, Color);
		//}
	}
	//-------------------------------------------------------------------------------------------------------------------------------

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TAISINH::TAISINH_ATIVE(int Number)
{
	TAISINH_REQ pMsg;
	pMsg.h.set(0xFC, 0x08, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_TAISINH::MAIN_TAISINH(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_TAISINH(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (ViewReset <= gObjUser.DieuKien01)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH1))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH1].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH1].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH1].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH1].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(1); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 2
	if (ViewReset > gObjUser.DieuKien01 && ViewReset <= gObjUser.DieuKien02)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH2))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH2].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH2].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH2].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH2].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(2); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 3
	if (ViewReset > gObjUser.DieuKien02 && ViewReset <= gObjUser.DieuKien03)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH3))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH3].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH3].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH3].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH3].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(3); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 4
	if (ViewReset > gObjUser.DieuKien03 && ViewReset <= gObjUser.DieuKien04)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH4))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH4].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH4].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH4].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH4].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(4); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 5
	if (ViewReset > gObjUser.DieuKien04 && ViewReset <= gObjUser.DieuKien05)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH5))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH5].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH5].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH5].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH5].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(5); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 6
	if (ViewReset > gObjUser.DieuKien05 && ViewReset <= gObjUser.DieuKien06)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH6))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH6].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH6].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH6].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH6].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(6); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 7
	if (ViewReset > gObjUser.DieuKien06 && ViewReset <= gObjUser.DieuKien07)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH7))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH7].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH7].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH7].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH7].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(7); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 8
	if (ViewReset > gObjUser.DieuKien07 && ViewReset <= gObjUser.DieuKien08)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH8))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH8].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH8].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH8].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH8].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(8); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 9
	if (ViewReset > gObjUser.DieuKien08 && ViewReset <= gObjUser.DieuKien09)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH9))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH9].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH9].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH9].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH9].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(9); // send gs
		}
	}
	//---------------------------------------------------------------------------------------------
	// Req lần 10
	if (ViewReset > gObjUser.DieuKien09 && ViewReset <= gObjUser.DieuKien10)
	{
		if (gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow && gInterface.IsWorkZone(TAISINH10))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[TAISINH10].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TAISINH10].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[TAISINH10].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[TAISINH10].EventTick = GetTickCount();
			this->CLOSE_WINDOW_TAISINH();
			this->TAISINH_ATIVE(10); // send gs
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_TAISINH::CLOSE_TAISINH(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_TAISINH_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_TAISINH_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_TAISINH_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_TAISINH_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_TAISINH_CLOSE].EventTick = GetTickCount();
	G_BEXO_TAISINH.CLOSE_WINDOW_TAISINH();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif