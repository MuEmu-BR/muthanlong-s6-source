#include "stdafx.h"
#include "MenuGame.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "Other.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Import.h"
#include "WindowsStruct.h"
#include "Ranking.h"
#include "PartySearchSettings.h"
#include "CustomLuckySpin.h"
#include "DanhHieu.h"
#include "TuLuyen.h"
#include "VipNhanVat.h"
#include "VipTaiKhoan.h"
#include "NguHanh.h"
#include "KinhMach.h"
#include "Achievements.h"
#include "MocNap.h"
#include "TaiSinh.h"

BEXO_MENU G_BEXO_MENU;

BEXO_MENU::BEXO_MENU()
{
	HIENTHIMENU = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
}

void BEXO_MENU::BIND()
{
	gInterface.BindObject(EXBEXO_MENU_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_MENU_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_1, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_2, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_3, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_4, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_5, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_6, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_7, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_8, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_9, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_10, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_11, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_12, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_13, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_14, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eBUTTON_MENU_15, 31461, 35, 14, -1, -1);

}

void BEXO_MENU::DRAW_MENU()
{
	DRAW_WINDOW_MENU();
}

void BEXO_MENU::DRAW_WINDOW_MENU()
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
	if (!gInterface.Data[EXBEXO_MENU_MAIN].OnShow)
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
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 5, gInterface.Data[EXBEXO_MENU_MAIN].Y + 160, 105, 170, 0.0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.BangXepHang == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_1, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 15, gInterface.Data[EXBEXO_MENU_MAIN].Y + 173, 210, 1, "Xếp Hạng"); // Tính năng

	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.TaoNhom == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_2, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 15, gInterface.Data[EXBEXO_MENU_MAIN].Y + 193, 210, 1, "Tạo Nhóm"); // Tính năng
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.TimNhom == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_3, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 15, gInterface.Data[EXBEXO_MENU_MAIN].Y + 213, 210, 1, "Tìm Nhóm");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.TreoMay == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_4, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 15, gInterface.Data[EXBEXO_MENU_MAIN].Y + 233, 210, 1, "Treo Máy");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.VongQuay == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_5, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 12, gInterface.Data[EXBEXO_MENU_MAIN].Y + 253, 210, 1, "Vòng Quay");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.DoiClass == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_6, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 12, gInterface.Data[EXBEXO_MENU_MAIN].Y + 273, 210, 1, "Đổi Class");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.ThanhTuu == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_13, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 12, gInterface.Data[EXBEXO_MENU_MAIN].Y + 293, 210, 1, "Thành Tựu");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.TaiSinhTrungSinh == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_15, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 310);
		if (CheckButtonPressed(StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 10, gInterface.Data[EXBEXO_MENU_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		if (gObjUser.m_TaiSinh == 1)
		{
			gInterface.DrawFormat(eWhite, StartX + 15, gInterface.Data[EXBEXO_MENU_MAIN].Y + 313, 210, 1, "Tái Sinh");
		}
		if (gObjUser.m_TrungSinh == 1)
		{
			gInterface.DrawFormat(eWhite, StartX + 13, gInterface.Data[EXBEXO_MENU_MAIN].Y + 313, 210, 1, "Trùng Sinh");
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.DanhHieu == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_7, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 170, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 62, gInterface.Data[EXBEXO_MENU_MAIN].Y + 173, 210, 1, "Danh Hiệu");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.TuLuyen == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_8, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 190, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 62, gInterface.Data[EXBEXO_MENU_MAIN].Y + 193, 210, 1, "Tu Luyện");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.VipNhanVat == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_9, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 210, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 58, gInterface.Data[EXBEXO_MENU_MAIN].Y + 213, 210, 1, "Vip Nhân Vật");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.VipTaiKhoan == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_10, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 230, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 58, gInterface.Data[EXBEXO_MENU_MAIN].Y + 233, 210, 1, "Vip Tài Khoản");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.NguHanh == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_11, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 250, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 62, gInterface.Data[EXBEXO_MENU_MAIN].Y + 253, 210, 1, "Ngũ Hành");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.KinhMach == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_12, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 270, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 62, gInterface.Data[EXBEXO_MENU_MAIN].Y + 273, 210, 1, "Kinh Mạch");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gObjUser.MocNap == 1)
	{
		gInterface.DrawGUI(eBUTTON_MENU_14, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290);
		if (CheckButtonPressed(StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 60, gInterface.Data[EXBEXO_MENU_MAIN].Y + 290, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		gInterface.DrawFormat(eWhite, StartX + 65, gInterface.Data[EXBEXO_MENU_MAIN].Y + 293, 210, 1, "Mốc Nạp");
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MENU::MAIN_MENU(DWORD Event)
{
	//---
	DWORD CurrentTick = GetTickCount();
	//---
	this->CLOSE_MENU(Event);
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_1)) // Xếp Hạng
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_1].EventTick = GetTickCount();

		if (gObjUser.BangXepHang == 1)
		{
#if(RANKING_NEW == 1)
			SEND_GS_REQ pRequest;
			pRequest.h.set(0xFD, 0x21, sizeof(pRequest));
			DataSend((BYTE*)&pRequest, pRequest.h.size);
			gRanking.Show = true;
#endif
		}
		if (gObjUser.BangXepHang == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Bảng Xếp Hạng] đang bảo trì !");
		}

		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_2)) // Tạo Nhóm
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_2].EventTick = GetTickCount();


		if (gObjUser.TaoNhom == 1)
		{
			gPartySearchSettings.party_search_settings_switch_state();
		}
		if (gObjUser.TaoNhom == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Tạo Nhóm] đang bảo trì !");
		}

		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_3)) // Tìm Nhóm
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_3].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_3].EventTick = GetTickCount();
		// ----
		if (gObjUser.TimNhom == 1)
		{
			SEND_GS_REQ pMsg;
			pMsg.h.set(0xFC, 0x20, sizeof(pMsg));
			DataSend((BYTE*)&pMsg, pMsg.h.size);
		}
		if (gObjUser.TimNhom == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Tìm Nhóm] đang bảo trì !");
		}

		pSetCursorFocus = false;
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_4)) // Treo Máy
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_4].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_4].EventTick = GetTickCount();
		// ----
		if (gObjUser.TreoMay == 1)
		{
#if(OFFLINE_MODE_NEW)
			gInterface.SwitchOffExpWindoState();
#endif
		}
		if (gObjUser.TreoMay == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Treo Máy] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_5)) // Treo Máy
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_5].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_5].EventTick = GetTickCount();
		// ----
		if (gObjUser.VongQuay == 1)
		{
#if(VONGQUAY_NEW)
			gLuckySpin.SwitchLuckySpinWindowState();
#endif
		}
		if (gObjUser.VongQuay == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Vòng Quay May Mắn] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_6)) // Treo Máy
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_6].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_6].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_6].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_6].EventTick = GetTickCount();
		// ----
		if (gObjUser.DoiClass == 1)
		{
			gInterface.Data[eCHANGINGCLASS_MAIN].Open();
		}
		if (gObjUser.DoiClass == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Đổi Giới Tính] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_7)) // Danh Hiệu
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_7].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_7].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_7].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_7].EventTick = GetTickCount();
		// ----
		if (gObjUser.DanhHieu == 1)
		{
#if(DANH_HIEU_NEW == 1)
			G_BEXO_DANH_HIEU.OPEN_WINDOW_DANH_HIEU();
#endif
		}
		if (gObjUser.DanhHieu == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Danh Hiệu] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_8)) // Tu Luyện
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_8].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_8].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_8].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_8].EventTick = GetTickCount();
		// ----
		if (gObjUser.TuLuyen == 1)
		{
#if(TU_LUYEN_NEW == 1)
			G_BEXO_TU_LUYEN.OPEN_WINDOW_TU_LUYEN();
#endif
		}
		if (gObjUser.TuLuyen == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Tu Luyện] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_9)) // Vip Nhan Vat
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_9].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_9].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_9].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_9].EventTick = GetTickCount();
		// ----
		if (gObjUser.VipNhanVat == 1)
		{
#if(THUE_VIP_NEW == 1)
			G_BEXO_VIPNHANVAT.OPEN_WINDOW_VIPNHANVAT();
#endif
		}
		if (gObjUser.VipNhanVat == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Vip Nhân Vật] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_10))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_10].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_10].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_10].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_10].EventTick = GetTickCount();
		// ----
		if (gObjUser.VipTaiKhoan == 1)
		{
#if(VIP_TAI_KHOAN_NEW == 1)
			G_BEXO_VIPTAIKHOAN.OPEN_WINDOW_VIPTAIKHOAN();
#endif
		}
		if (gObjUser.VipTaiKhoan == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Vip Tài Khoản] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_11))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_11].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_11].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_11].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_11].EventTick = GetTickCount();
		// ----
		if (gObjUser.NguHanh == 1)
		{
#if(NGU_HANH_NEW == 1)
			G_BEXO_NGUHANH.BUY_NGU_HANH(2); // Lấy dữ liệu gs
			G_BEXO_NGUHANH.OPEN_WINDOW_NGUHANH();
#endif
		}
		if (gObjUser.NguHanh == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Nghũ Hành] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_12))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_12].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_12].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_12].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_12].EventTick = GetTickCount();
		// ----
		if (gObjUser.KinhMach == 1)
		{
#if(KINH_MACH_NEW == 1)
			G_BEXO_KINHMACH.BUY_KINH_MACH(9); // Lấy dữ liệu gs
			G_BEXO_KINHMACH.OPEN_WINDOW_KINHMACH();
#endif
		}
		if (gObjUser.KinhMach == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Kinh Mạch] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_13))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_13].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_13].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_13].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_13].EventTick = GetTickCount();
		// ----
		if (gObjUser.ThanhTuu == 1)
		{
#if (ARCHIVEMENT == 1)
			gAchievements.CGWindowOpen();
#endif
		}
		if (gObjUser.ThanhTuu == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Thành Tựu] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_14))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_14].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_14].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_14].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_14].EventTick = GetTickCount();
		// ----
#if (MOCNAP == 1)
		if (gObjUser.MocNap == 1)
		{
			G_BEXO_MOCNAP.OPEN_WINDOW_MOCNAP();
			gInterface.BUY_TINH_NANG_GAME(19); // Update
		}
#endif
		if (gObjUser.MocNap == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Mốc Nạp] đang bảo trì !");
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	//---
	if (gInterface.Data[EXBEXO_MENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_15))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_15].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_15].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_15].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eBUTTON_MENU_15].EventTick = GetTickCount();
		// ----
#if (TAISINH == 1)
		if (gObjUser.TaiSinhTrungSinh == 1)
		{
			G_BEXO_TAISINH.OPEN_WINDOW_TAISINH();
			// Update GS
			G_BEXO_TAISINH.TAISINH_ATIVE(100);
		}
#endif
		if (gObjUser.TaiSinhTrungSinh == 0)
		{
			if (gObjUser.m_TaiSinh == 1)
			{
				gInterface.DrawMessage(1, "Chức năng [Tái Sinh] đang bảo trì !");
			}
			if (gObjUser.m_TrungSinh == 1)
			{
				gInterface.DrawMessage(1, "Chức năng [Trùng Sinh] đang bảo trì !");
			}
		}
		// ----
		G_BEXO_MENU.CLOSE_WINDOW_MENU();
	}
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MENU::CLOSE_MENU(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_MENU_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_MENU_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_MENU_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_MENU_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_MENU_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_MENU_CLOSE].EventTick = GetTickCount();
	G_BEXO_MENU.CLOSE_WINDOW_MENU();
	// ----
	return false;
}
