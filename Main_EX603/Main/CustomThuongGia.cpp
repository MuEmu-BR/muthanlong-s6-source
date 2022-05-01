#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomThuongGia.h"
#include "CustomLuckySpin.h"
#include "Item.h"
#include "Defines.h"
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
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_THUONG_GIA G_BEXO_THUONG_GIA;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_THUONG_GIA    4  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_THUONG_GIA::BEXO_THUONG_GIA()
{
	TRANG_THUONG_GIA = 1;
	//--------------------------------------------------------------
	HIENTHITHUONG_GIA = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;

	this->StartRollZen = 0;
	this->RollNumberZen = -1;
	this->itemdataZen.clear();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_THUONG_GIA::DRAW_THUONG_GIA()
{
	DRAW_WINDOW_THUONG_GIA();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_THUONG_GIA::BEXO_CLICK_TRANG_THUONG_GIA(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);

	if (gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow && gInterface.IsWorkZone(eTHUONG_GIA1))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TRANG_THUONG_GIA = 1)

			ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow && gInterface.IsWorkZone(eTHUONG_GIA2))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TRANG_THUONG_GIA = 2)

			ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow && gInterface.IsWorkZone(eTHUONG_GIA3))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TRANG_THUONG_GIA = 3)

			ClickTick = GetTickCount();
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_THUONG_GIA::GCThuongGiaZenInit(GC_ThuongGiaZenInit* aRecv)
{
	if (aRecv->result)
	{
		gInterface.Data[eLuckySpin].Open();
		this->OPEN_WINDOW_THUONG_GIA();
	}
}

void BEXO_THUONG_GIA::ThuongGiaZenItemSend(GC_ThuongGiaZen_Data* aRecv)
{
	ThuongGiaZen_Data pData;
	pData.ItemType = aRecv->ItemType;
	pData.ItemIndex = aRecv->ItemIndex;
	pData.ItemLevel = aRecv->ItemLevel;
	pData.ItemExc = aRecv->ItemExc;
	this->itemdataZen.push_back(pData);
}

void BEXO_THUONG_GIA::ThuongGiaZenSend()
{
	THUONGGIAZEN_REQ pRequest;
	pRequest.h.set(0xFC, 0x17, sizeof(pRequest));
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

void BEXO_THUONG_GIA::ThuongGiaZenData(ThuongGiaZen_UpdateData * aRecv)
{
	this->StartRollZen = 0;
	this->RollNumberZen = aRecv->RollNumberZen;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_THUONG_GIA::DRAW_WINDOW_THUONG_GIA()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| (gInterface.CheckWindow(Inventory)
		&& gInterface.CheckWindow(ExpandInventory)
		&& gInterface.CheckWindow(Store))
		|| (gInterface.CheckWindow(Inventory)
		&& gInterface.CheckWindow(Warehouse)
		&& gInterface.CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow)
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
	gCItemSetOption.ItemTooltipS15(StartX + 150, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 50, 330, 330, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 280, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 50, 200, 330, 0.0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eTHUONG_GIA1, StartX + 160, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 80);
	gInterface.DrawGUI(eTHUONG_GIA2, StartX + 160, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 110);
	gInterface.DrawGUI(eTHUONG_GIA3, StartX + 160, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 140);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(eTHUONG_GIA1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eTHUONG_GIA1, gInterface.Data[eTHUONG_GIA1].X, gInterface.Data[eTHUONG_GIA1].Y, Color);
	}
	if (gInterface.IsWorkZone(eTHUONG_GIA2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eTHUONG_GIA2, gInterface.Data[eTHUONG_GIA2].X, gInterface.Data[eTHUONG_GIA2].Y, Color);
	}
	if (gInterface.IsWorkZone(eTHUONG_GIA3))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eTHUONG_GIA3, gInterface.Data[eTHUONG_GIA3].X, gInterface.Data[eTHUONG_GIA3].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, StartX + 190, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 90, 210, 1,  "Thương gia Zen");
	gInterface.DrawFormat(eWhite, StartX + 190, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 120, 210, 1, "Thương gia Ngọc");
	gInterface.DrawFormat(eWhite, StartX + 190, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 150, 210, 1, "Thương gia WCoinC");

	gInterface.DrawFormat(eYellow, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 180, 210, 1, "Phần thưởng khi quay bằng Zen");
	gInterface.DrawFormat(eWhite, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 195, 210, 1, "-Ngẫu nhiên nhận item thường +6~9");

	gInterface.DrawFormat(eYellow, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 215, 210, 1, "Phần thưởng khi quay bằng Ngọc");
	gInterface.DrawFormat(eWhite, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 230, 210, 1, "-Vũ khí Rồng(xác xuất siêu hiếm)");
	gInterface.DrawFormat(eWhite, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 245, 210, 1, "-Vũ khí /Trang bị cấp 3 trở lên");
	gInterface.DrawFormat(eWhite, StartX + 155, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 260, 210, 1, "-Nhẫn,dây chuyền Exc(xác xuất hiếm)");
	gInterface.DrawFormat(eWhite, StartX + 155, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 275, 210, 1, "-Các loại Pet(Gấu Trúc, Đại Quỷ,Muun..)");

	gInterface.DrawFormat(eYellow, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 295, 210, 1, "Phần thưởng khi quay bằng WCoinC");
	gInterface.DrawFormat(eWhite, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 310, 210, 1, "-Vũ khí Rồng(xác xuất hiếm)");
	gInterface.DrawFormat(eWhite, StartX + 165, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 325, 210, 1, "-Vũ khí /Trang bị cấp 3 trở lên");
	gInterface.DrawFormat(eWhite, StartX + 155, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 340, 210, 1, "-Nhẫn,dây chuyền Exc(xác xuất hiếm)");
	gInterface.DrawFormat(eWhite, StartX + 155, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 355, 210, 1, "-Các loại Pet(Ngựa Ma, Sói,Muun..)");

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_THUONG_GIA_CLOSE, StartX + 450, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 48);
	if (gInterface.IsWorkZone(EXBEXO_THUONG_GIA_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_THUONG_GIA_CLOSE, gInterface.Data[EXBEXO_THUONG_GIA_CLOSE].X, gInterface.Data[EXBEXO_THUONG_GIA_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float StartBody = 70;
	float XTHUONGGIA = 260;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_THUONG_GIA)
	{
	case 1:

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 75, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 70, 100, 20, 0.0, 0);
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 80, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 75, 210, 1, "Yêu cầu : 50.000.000 zen");

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 75, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 110, 100, 20, 0.0, 0);
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 80, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 115, 800, 1, "Hiện có : %d",gInterface.m_Money);

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 43, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 83, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 123, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 163, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);

		// lấy item
		gInterface.DrawItem2(XTHUONGGIA + 63, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(0, 2), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 103, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(1, 2), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 143, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(4, 2), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 183, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(5, 0), 0, 1, 0, 0);

	    //--------------------------------------------------------------------------------------------
		pDrawGUI(71520, XTHUONGGIA + 23, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 150, 200, 1); //-- Divisor
		pDrawGUI(71520, XTHUONGGIA + 23, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 245, 200, 1); //-- Divisor
		//--------------------------------------------------------------------------------------------
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0.0, 0);

		if (this->StartRollZen >= 1)
		{
			pSetBlend(true);
			glColor4f(1.0, 1.0, 0.0, 0.3);
			int ran = rand() % 11;
			pSetBlend(true);
			switch (ran)
			{
			case 0:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 1:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 2:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 3:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 4:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 5:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 6:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 7:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 8:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 9:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 10:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 11:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
				pGLSwitchBlend();
				glColor3f(1.0, 1.0, 1.0);
			}
		}

		if (this->RollNumberZen >= 0)
		{
			pSetBlend(true);
			glColor4f(1.0, 1.0, 0.0, 0.3);
			switch (RollNumberZen)
			{
			case 0:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 1:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 2:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 3:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 4:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 5:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 6:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 7:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 8:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 9:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 10:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
			case 11:
				pDrawBarForm(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0, 0);
				break;
				pGLSwitchBlend();
				glColor3f(1.0, 1.0, 1.0);
			}
		}
		// item nhận thưởng
		if (this->RollNumberZen >= 0)
		{
			gInterface.DrawItem2(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, ITEM(this->itemdataZen[RollNumberZen].ItemType, this->itemdataZen[RollNumberZen].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdataZen[RollNumberZen].ItemLevel), this->itemdataZen[RollNumberZen].ItemExc, 0, 0);
		}

		gInterface.DrawGUI(eTHUONGGIA_01, XTHUONGGIA + 70, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 336); // Cột 2
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 110, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 346, 210, 1, "Quay");
		//--------------------------------------------------------------------------------------------

		if (gInterface.IsWorkZone(eTHUONGGIA_01))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eTHUONGGIA_01, gInterface.Data[eTHUONGGIA_01].X, gInterface.Data[eTHUONGGIA_01].Y, Color);
		}
		break;
	case 2:
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 75, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 70, 100, 20, 0.0, 0);
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 80, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 75, 210, 1, "Yêu cầu : 50.000.000 zen");

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 75, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 110, 100, 20, 0.0, 0);
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 80, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 115, 210, 1, "Hiện có : %d", Zen);

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 43, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 83, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 123, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 163, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);

		// lấy item
		gInterface.DrawItem2(XTHUONGGIA + 63, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(0, 19), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 103, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(13, 80), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 143, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(14, 96), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 183, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(14, 42), 0, 1, 0, 0);

		//--------------------------------------------------------------------------------------------
		pDrawGUI(71520, XTHUONGGIA + 23, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 150, 200, 1); //-- Divisor
		pDrawGUI(71520, XTHUONGGIA + 23, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 245, 200, 1); //-- Divisor
		//--------------------------------------------------------------------------------------------
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0.0, 0);

		gInterface.DrawGUI(eTHUONGGIA_02, XTHUONGGIA + 70, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 336); // Cột 2
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 110, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 346, 210, 1, "Quay");
		//--------------------------------------------------------------------------------------------

		if (gInterface.IsWorkZone(eTHUONGGIA_02))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eTHUONGGIA_02, gInterface.Data[eTHUONGGIA_02].X, gInterface.Data[eTHUONGGIA_02].Y, Color);
		}
		break;
	case 3:
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 75, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 70, 100, 20, 0.0, 0);
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 80, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 75, 210, 1, "Yêu cầu : 10.000 WCoin");

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 75, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 110, 100, 20, 0.0, 0);
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 80, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 115, 210, 1, "Hiện có : %d", Coin1);

		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 43, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 83, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 123, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 163, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 170, 30, 40, 0.0, 0);

		// Lấy Item
		gInterface.DrawItem2(XTHUONGGIA + 63, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(0, 19), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 103, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(2, 13), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 143, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(4, 18), 0, 1, 0, 0);
		gInterface.DrawItem2(XTHUONGGIA + 183, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 200, 0, 0, GET_ITEM(5, 10), 0, 1, 0, 0);

		//--------------------------------------------------------------------------------------------
		pDrawGUI(71520, XTHUONGGIA + 23, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 150, 200, 1); //-- Divisor
		pDrawGUI(71520, XTHUONGGIA + 23, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 245, 200, 1); //-- Divisor
		//--------------------------------------------------------------------------------------------
		gCItemSetOption.ItemTooltipS15(XTHUONGGIA + 95, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 255, 50, 50, 0.0, 0);

		gInterface.DrawGUI(eTHUONGGIA_03, XTHUONGGIA + 70, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 336); // Cột 2
		gInterface.DrawFormat(eWhite, XTHUONGGIA + 110, gInterface.Data[EXBEXO_THUONG_GIA_MAIN].Y + 346, 210, 1, "Quay");
		//--------------------------------------------------------------------------------------------

		if (gInterface.IsWorkZone(eTHUONGGIA_03))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eTHUONGGIA_03, gInterface.Data[eTHUONGGIA_03].X, gInterface.Data[eTHUONGGIA_03].Y, Color);
		}
		break;

	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_THUONG_GIA::MAIN_THUONG_GIA(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_THUONG_GIA(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
#if(VIP_TAI_KHOAN_NEW)
	// TRANG 1
	if (gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_01) && this->TRANG_THUONG_GIA == 1)
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
		this->CLOSE_WINDOW_THUONG_GIA();
	}
	if (gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_03) && this->TRANG_THUONG_GIA == 1)
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
		this->CLOSE_WINDOW_THUONG_GIA();
	}
	if (gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_07) && this->TRANG_THUONG_GIA == 1)
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
		this->CLOSE_WINDOW_THUONG_GIA();
	}
#endif

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_THUONG_GIA::CLOSE_THUONG_GIA(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_THUONG_GIA_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_THUONG_GIA_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_THUONG_GIA_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_THUONG_GIA_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_THUONG_GIA_CLOSE].EventTick = GetTickCount();
	G_BEXO_THUONG_GIA.CLOSE_WINDOW_THUONG_GIA();
	// ----
	return false;
}
//---------------------------------------------------------
