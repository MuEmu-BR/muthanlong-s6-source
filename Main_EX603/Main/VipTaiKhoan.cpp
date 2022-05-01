#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "VipTaiKhoan.h"
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

#if(VIP_TAI_KHOAN_NEW == 1)

BEXO_VIPTAIKHOAN G_BEXO_VIPTAIKHOAN;

BEXO_VIPTAIKHOAN::BEXO_VIPTAIKHOAN()
{
	HIENTHIVIPTAIKHOAN = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_VIPTAIKHOAN::DRAW_VIPTAIKHOAN()
{
	DRAW_WINDOW_VIPTAIKHOAN();
}

void BEXO_VIPTAIKHOAN::DRAW_WINDOW_VIPTAIKHOAN()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow)
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
	gCItemSetOption.ItemTooltipS15(StartX + 200, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 50, 285, 300, 0.0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_VIPTAIKHOAN_CLOSE, StartX + 450, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 48);
	if (gInterface.IsWorkZone(EXBEXO_VIPTAIKHOAN_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_VIPTAIKHOAN_CLOSE, gInterface.Data[EXBEXO_VIPTAIKHOAN_CLOSE].X, gInterface.Data[EXBEXO_VIPTAIKHOAN_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XVIPTAIKHOAN = 200;
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 50, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 68, 210, 1, gOther.TextVN[32], gObjUser.lpPlayer->Name); // "Hệ thống cửa hàng VIP Tài Khoản, chào %s!"
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 75, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 88, 210, 1, gOther.TextVN[39]);  // Tất cả tỷ lệ đập đồ tăng + 20%%!"
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 70, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 108, 210, 1, gOther.TextVN[40]); // Exp được cộng tính cho cả cấp Master!"
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 80, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 128, 210, 1, gOther.TextVN[41]); // Không có tác dụng khi party!"
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 165, 300, 1, gOther.TextVN[42]); // "Name                   Exp                   Drop                  Time"
	gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 185, 300, 1, gOther.TextVN[43]); // "Vip 1 Ngày          +30%%              +10%%               1 Ngày"
	gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 205, 300, 1, gOther.TextVN[44]); // "Vip 3 Ngày          +30%%              +10%%               3 Ngày"
	gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 225, 300, 1, gOther.TextVN[45]); // "Vip 7 Ngày          +30%%              +10%%               7 Ngày"
	//--------------------------------------------------------------------------------------------
	pDrawGUI(71520, XVIPTAIKHOAN + 23, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 150, 200, 1); //-- Divisor
	pDrawGUI(71520, XVIPTAIKHOAN + 23, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 245, 200, 1); //-- Divisor
	//--------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eVIPTAIKHOAN_SEND_01, XVIPTAIKHOAN + 80, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 250); // Cột 1
	gInterface.DrawGUI(eVIPTAIKHOAN_SEND_03, XVIPTAIKHOAN + 80, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 278); // Cột 2
	gInterface.DrawGUI(eVIPTAIKHOAN_SEND_07, XVIPTAIKHOAN + 80, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 306); // Cột 2
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 120, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 255, 210, 1, gOther.TextVN[36]); // "Vip Đồng"
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 120, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 283, 210, 1, gOther.TextVN[37]); // "Vip Bạc"
	gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 120, gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].Y + 311, 210, 1, gOther.TextVN[38]); // "Vip Vàng"
	//--------------------------------------------------------------------------------------------
	//==>>
	if (gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_01))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eVIPTAIKHOAN_SEND_01, gInterface.Data[eVIPTAIKHOAN_SEND_01].X, gInterface.Data[eVIPTAIKHOAN_SEND_01].Y, Color);
	}
	if (gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_03))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eVIPTAIKHOAN_SEND_03, gInterface.Data[eVIPTAIKHOAN_SEND_03].X, gInterface.Data[eVIPTAIKHOAN_SEND_03].Y, Color);
	}
	if (gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_07))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eVIPTAIKHOAN_SEND_07, gInterface.Data[eVIPTAIKHOAN_SEND_07].X, gInterface.Data[eVIPTAIKHOAN_SEND_07].Y, Color);
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_VIPTAIKHOAN::MAIN_VIPTAIKHOAN(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_VIPTAIKHOAN(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_01))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPTAIKHOAN_SEND_01].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPTAIKHOAN_SEND_01].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPTAIKHOAN_SEND_01].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPTAIKHOAN_SEND_01].EventTick = GetTickCount();
		gCustomBuyVip.BuyStatus(1);
		this->CLOSE_WINDOW_VIPTAIKHOAN();
	}
	if (gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_03))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPTAIKHOAN_SEND_03].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPTAIKHOAN_SEND_03].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPTAIKHOAN_SEND_03].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPTAIKHOAN_SEND_03].EventTick = GetTickCount();
		gCustomBuyVip.BuyStatus(2);
		this->CLOSE_WINDOW_VIPTAIKHOAN();
	}
	if (gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_07))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPTAIKHOAN_SEND_07].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPTAIKHOAN_SEND_07].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPTAIKHOAN_SEND_07].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPTAIKHOAN_SEND_07].EventTick = GetTickCount();
		gCustomBuyVip.BuyStatus(3);
		this->CLOSE_WINDOW_VIPTAIKHOAN();
	}
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_VIPTAIKHOAN::CLOSE_VIPTAIKHOAN(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_VIPTAIKHOAN_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_VIPTAIKHOAN_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_VIPTAIKHOAN_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_VIPTAIKHOAN_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_VIPTAIKHOAN_CLOSE].EventTick = GetTickCount();
	G_BEXO_VIPTAIKHOAN.CLOSE_WINDOW_VIPTAIKHOAN();
	// ----
	return false;
}
#endif