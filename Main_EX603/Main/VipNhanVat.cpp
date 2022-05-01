#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "VipNhanVat.h"
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

#if(THUE_VIP_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_VIPNHANVAT G_BEXO_VIPNHANVAT;

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_VIPNHANVAT::BEXO_VIPNHANVAT()
{
	//--------------------------------------------------------------
	HIENTHIVIPNHANVAT = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_VIPNHANVAT::DRAW_VIPNHANVAT()
{
	DRAW_WINDOW_VIPNHANVAT();
}

void BEXO_VIPNHANVAT::DRAW_WINDOW_VIPNHANVAT()
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
	if (!gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow)
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
	gCItemSetOption.ItemTooltipS15(StartX + 200, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 50, 280, 300, 0.0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_VIPNHANVAT_CLOSE, StartX + 450, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 48);
	if (gInterface.IsWorkZone(EXBEXO_VIPNHANVAT_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_VIPNHANVAT_CLOSE, gInterface.Data[EXBEXO_VIPNHANVAT_CLOSE].X, gInterface.Data[EXBEXO_VIPNHANVAT_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XVIPNHANVAT = 210;
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 58, 210, 1, gOther.TextVN[46], gObjUser.lpPlayer->Name); // "Hệ thống cửa hàng VIP Tài Khoản, chào %s!"
	//--------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eVIPNHANVAT_SEND_01, XVIPNHANVAT + 10, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 250); // "Vip Đồng"
	gInterface.DrawGUI(eVIPNHANVAT_SEND_02, XVIPNHANVAT + 140, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 250); // "Vip Bạc"
	gInterface.DrawGUI(eVIPNHANVAT_SEND_03, XVIPNHANVAT + 10, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 300); // "Vip Vàng"
	gInterface.DrawGUI(eVIPNHANVAT_SEND_04, XVIPNHANVAT + 140, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 300); // "Vip Kim Cương"
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 258, 210, 1, gOther.TextVN[50]); // "Vip Đồng"
	gInterface.DrawFormat(eWhite, XVIPNHANVAT + 180, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 258, 210, 1, gOther.TextVN[51]); // "Vip Bạc"
	gInterface.DrawFormat(eWhite, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 308, 210, 1, gOther.TextVN[52]); // "Vip Vàng"
	gInterface.DrawFormat(eWhite, XVIPNHANVAT + 180, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 308, 210, 1, gOther.TextVN[53]); // "Vip Kim Cương"
	//--------------------------------------------------------------------------------------------
	//==>> hình ảnh Vip
	pDrawGUFULL(10176, XVIPNHANVAT + 30, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 258, 15, 15, 0, 0, 1, 1, 1, 1, 0.0);  // 
	pDrawGUFULL(10177, XVIPNHANVAT + 160, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 258, 15, 15, 0, 0, 1, 1, 1, 1, 0.0);  // 
	//==>>
	pDrawGUFULL(10178, XVIPNHANVAT + 30, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 308, 15, 15, 0, 0, 1, 1, 1, 1, 0.0); // 
	pDrawGUFULL(10179, XVIPNHANVAT + 160, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 308, 15, 15, 0, 0, 1, 1, 1, 1, 0.0); // 
	//--------------------------------------------------------------------------------------------
	//==>>
	if (gInterface.IsWorkZone(eVIPNHANVAT_SEND_01))
	{
		DWORD Color = eGray150;

		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 90, 210, 1, gOther.TextVN[61]);  // "Tỉ lệ sát thương hoàn hảo tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 110, 210, 1, gOther.TextVN[62]); // "Tỉ lệ ra đòn sát thương chí mạng tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 130, 300, 1, gOther.TextVN[63]); // "Tỉ lể x2 dame tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 150, 300, 1, gOther.TextVN[64]); // "Sát thương tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 170, 300, 1, gOther.TextVN[65]); // "Thể lực tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 190, 300, 1, gOther.TextVN[66]); // "SD tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 210, 300, 1, gOther.TextVN[67]); // "WCoin = "

		gInterface.DrawColoredGUI(eVIPNHANVAT_SEND_01, gInterface.Data[eVIPNHANVAT_SEND_01].X, gInterface.Data[eVIPNHANVAT_SEND_01].Y, Color);
	}
	if (gInterface.IsWorkZone(eVIPNHANVAT_SEND_02))
	{
		DWORD Color = eGray150;

		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 90, 210, 1, gOther.TextVN[68]);  // "Tỉ lệ sát thương hoàn hảo tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 110, 210, 1, gOther.TextVN[69]); // "Tỉ lệ ra đòn sát thương chí mạng tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 130, 300, 1, gOther.TextVN[70]); // "Tỉ lể x2 dame tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 150, 300, 1, gOther.TextVN[71]); // "Sát thương tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 170, 300, 1, gOther.TextVN[72]); // "Thể lực tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 190, 300, 1, gOther.TextVN[73]); // "SD tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 210, 300, 1, gOther.TextVN[74]); // "WCoin = "

		gInterface.DrawColoredGUI(eVIPNHANVAT_SEND_02, gInterface.Data[eVIPNHANVAT_SEND_02].X, gInterface.Data[eVIPNHANVAT_SEND_02].Y, Color);
	}
	if (gInterface.IsWorkZone(eVIPNHANVAT_SEND_03))
	{
		DWORD Color = eGray150;

		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 90, 210, 1, gOther.TextVN[75]);  // "Tỉ lệ sát thương hoàn hảo tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 110, 210, 1, gOther.TextVN[76]); // "Tỉ lệ ra đòn sát thương chí mạng tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 130, 300, 1, gOther.TextVN[77]); // "Tỉ lể x2 dame tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 150, 300, 1, gOther.TextVN[78]); // "Sát thương tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 170, 300, 1, gOther.TextVN[79]); // "Thể lực tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 190, 300, 1, gOther.TextVN[80]); // "SD tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 210, 300, 1, gOther.TextVN[81]); // "WCoin = "

		gInterface.DrawColoredGUI(eVIPNHANVAT_SEND_03, gInterface.Data[eVIPNHANVAT_SEND_03].X, gInterface.Data[eVIPNHANVAT_SEND_03].Y, Color);
	}
	if (gInterface.IsWorkZone(eVIPNHANVAT_SEND_04))
	{
		DWORD Color = eGray150;

		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 90, 210, 1, gOther.TextVN[82]);  // "Tỉ lệ sát thương hoàn hảo tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 110, 210, 1, gOther.TextVN[83]); // "Tỉ lệ ra đòn sát thương chí mạng tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 130, 300, 1, gOther.TextVN[84]); // "Tỉ lể x2 dame tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 150, 300, 1, gOther.TextVN[85]); // "Sát thương tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 170, 300, 1, gOther.TextVN[86]); // "Thể lực tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 190, 300, 1, gOther.TextVN[87]); // "SD tăng:"
		gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 210, 300, 1, gOther.TextVN[88]); // "WCoin = "

		gInterface.DrawColoredGUI(eVIPNHANVAT_SEND_04, gInterface.Data[eVIPNHANVAT_SEND_04].X, gInterface.Data[eVIPNHANVAT_SEND_04].Y, Color);
	}
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eExcellent, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 90, 210, 1, gOther.TextVN[54]);  // "Tỉ lệ sát thương hoàn hảo tăng:"
	gInterface.DrawFormat(eExcellent, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 110, 210, 1, gOther.TextVN[55]);  // "Tỉ lệ ra đòn sát thương chí mạng tăng:"
	gInterface.DrawFormat(eExcellent, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 130, 300, 1, gOther.TextVN[56]); // "Tỉ lể x2 dame tăng:"
	gInterface.DrawFormat(eExcellent, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 150, 300, 1, gOther.TextVN[57]); // "Sát thương tăng:"
	gInterface.DrawFormat(eExcellent, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 170, 300, 1, gOther.TextVN[58]); // "Thể lực tăng:"
	gInterface.DrawFormat(eExcellent, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 190, 300, 1, gOther.TextVN[59]); // "SD tăng:"
	gInterface.DrawFormat(eYellow, XVIPNHANVAT + 50, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 210, 300, 1, gOther.TextVN[60]);    // "WCoin = "
	//--------------------------------------------------------------------------------------------
	pDrawGUI(71520, XVIPNHANVAT + 23, gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].Y + 225, 200, 1); //-- Divisor
	//--------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_VIPNHANVAT::MAIN_VIPNHANVAT(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_VIPNHANVAT(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_01))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_01].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_01].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_01].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_01].EventTick = GetTickCount();
		this->BUY_THUE_VIP(1);
		this->CLOSE_WINDOW_VIPNHANVAT();
	}
	if (gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_02))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_02].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_02].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_02].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_02].EventTick = GetTickCount();
		this->BUY_THUE_VIP(2);
		this->CLOSE_WINDOW_VIPNHANVAT();
	}
	if (gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_03))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_03].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_03].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_03].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_03].EventTick = GetTickCount();
		this->BUY_THUE_VIP(3);
		this->CLOSE_WINDOW_VIPNHANVAT();
	}
	if (gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_04))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_04].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_04].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_04].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_04].EventTick = GetTickCount();
		this->BUY_THUE_VIP(4);
		this->CLOSE_WINDOW_VIPNHANVAT();
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_VIPNHANVAT::CLOSE_VIPNHANVAT(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_VIPNHANVAT_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_VIPNHANVAT_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_VIPNHANVAT_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_VIPNHANVAT_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_VIPNHANVAT_CLOSE].EventTick = GetTickCount();
	G_BEXO_VIPNHANVAT.CLOSE_WINDOW_VIPNHANVAT();
	// ----
	return false;
}
//---------------------------------------------------------
void BEXO_VIPNHANVAT::BUY_THUE_VIP(int Number)
{
	BUY_THUE_VIP_REQ pMsg;
	pMsg.h.set(0xFC, 0x02, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif