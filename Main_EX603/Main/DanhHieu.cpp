#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "DanhHieu.h"
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


#if(DANH_HIEU_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_DANH_HIEU G_BEXO_DANH_HIEU;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_DANH_HIEU    4  // OK

int ImgTagExDanhHieu1 = 10100; //Rank Dynamic
int ImgTagExDanhHieu2 = 10200; //Rank Dynamic
int ImgTagExDanhHieu3 = 10300; //Rank Dynamic
int ImgTagExDanhHieu4 = 10400; //Rank Dynamic
int ImgTagExDanhHieu5 = 10500; //Rank Dynamic
int ImgTagExDanhHieu6 = 10600; //Rank Dynamic
int ImgTagExDanhHieu7 = 10700; //Rank Dynamic
int ImgTagExDanhHieu8 = 10800; //Rank Dynamic
int ImgTagExDanhHieu9 = 10900; //Rank Dynamic
int ImgTagExDanhHieu10 = 11000; //Rank Dynamic
int ImgTagExDanhHieu11 = 11100; //Rank Dynamic
int ImgTagExDanhHieu12 = 11200; //Rank Dynamic
int ImgTagExDanhHieu13 = 11300; //Rank Dynamic
int ImgTagExDanhHieu14 = 11400; //Rank Dynamic
int ImgTagExDanhHieu15 = 11500; //Rank Dynamic
int ImgTagExDanhHieu16 = 11600; //Rank Dynamic
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_DANH_HIEU::BEXO_DANH_HIEU()
{
	TRANG_DANH_HIEU = 1;
	//--------------------------------------------------------------
	HIENTHIDANH_HIEU = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::DRAW_DANH_HIEU()
{
	DRAW_WINDOW_DANH_HIEU();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::BEXO_CLICK_TRANG_DANH_HIEU(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(eDANH_HIEU1))
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
		if (1 < TRANG_DANH_HIEU && TRANG_DANH_HIEU <= MAX_TRANG_DANH_HIEU)
		{
			TRANG_DANH_HIEU--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(eDANH_HIEU2))

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
		if (1 <= TRANG_DANH_HIEU && TRANG_DANH_HIEU < MAX_TRANG_DANH_HIEU)
		{
			TRANG_DANH_HIEU++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_DANH_HIEU < 1)
	{
		TRANG_DANH_HIEU = 1;
	}
	if (TRANG_DANH_HIEU > TRANG_DANH_HIEU)
	{
		TRANG_DANH_HIEU = TRANG_DANH_HIEU;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_DANH_HIEU::DRAW_WINDOW_DANH_HIEU()
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
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		pDrawGUFULL(0x0899, StartX + 70, StartY + 50, 900, 550, 0, 0, 1, 1, 1, 1, 0.0); // MENU
	}
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		gCItemSetOption.ItemTooltipS15(StartX + 70, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 50, 495, 300, 0.0, 0);

		gCItemSetOption.ItemTooltipS15(StartX + 95, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 85, 450, 60, 0.0, 0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------

	gInterface.DrawFormat(eWhite, StartX + 280, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 60, 210, 1, "Nâng cấp Danh Hiệu");

	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 90, 210, 1, gOther.TextVN_DanhHieu[0]);

	//---- wcoin nâng cấp
	if (gInterface.m_DanhHieu == 0)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_01);
	}
	if (gInterface.m_DanhHieu == 1)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_02);
	}
	if (gInterface.m_DanhHieu == 2)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_03);
	}
	if (gInterface.m_DanhHieu == 3)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_04);
	}
	if (gInterface.m_DanhHieu == 4)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_05);
	}
	if (gInterface.m_DanhHieu == 5)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_06);
	}
	if (gInterface.m_DanhHieu == 6)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_07);
	}
	if (gInterface.m_DanhHieu == 7)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_08);
	}
	if (gInterface.m_DanhHieu == 8)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_09);
	}
	if (gInterface.m_DanhHieu == 9)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_10);
	}
	if (gInterface.m_DanhHieu == 10)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_11);
	}
	if (gInterface.m_DanhHieu == 11)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_12);
	}
	if (gInterface.m_DanhHieu == 12)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_13);
	}
	if (gInterface.m_DanhHieu == 13)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_14);
	}
	if (gInterface.m_DanhHieu == 14)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_15);
	}
	if (gInterface.m_DanhHieu == 15)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gOther.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC_16);
	}
	//----
	gInterface.DrawFormat(eSocket, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 120, 210, 1, gOther.TextVN_DanhHieu[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_DANH_HIEU_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_DANH_HIEU_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_DANH_HIEU_NANG_CAP, gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].X, gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 450, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 110, 210, 1, gOther.TextVN_DanhHieu[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 132, 210, 1, gOther.TextVN_DanhHieu[4], gInterface.m_DanhHieu);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eDANH_HIEU1, StartX + 70, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eDANH_HIEU1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eDANH_HIEU1, gInterface.Data[eDANH_HIEU1].X, gInterface.Data[eDANH_HIEU1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eDANH_HIEU2, StartX + 535, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eDANH_HIEU2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eDANH_HIEU2, gInterface.Data[eDANH_HIEU2].X, gInterface.Data[eDANH_HIEU2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_DANH_HIEU_CLOSE, StartX + 532, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_DANH_HIEU_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_DANH_HIEU_CLOSE, gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].X, gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// Thanh Xanh Coin
	RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 109, 210, 14, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 108, 210, 1, "WCoinC %d", Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		// Nền đen nằm text
		RenderBitmap(0x0896, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_DANH_HIEU) //====================================================================================================================================
	{
		//=============================================================================================================================================================	
	case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 4)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(ImgTagExDanhHieu1, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu2, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu3, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu4, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[20]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[21]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[22]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[23]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[24]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[25]);

		//=============================================================================================================================================================	
		break;
	case 2:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 5)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 6)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 7)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 8)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(ImgTagExDanhHieu5, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu6, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu7, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu8, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[26]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[27]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[28]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[29]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[30]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[31]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[32]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[33]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[34]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[35]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[36]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[37]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[38]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[39]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[40]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[41]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[42]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[43]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[44]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[45]);
		//=============================================================================================================================================================	
		break;
	case 3:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 9)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 10)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 11)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 12)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(ImgTagExDanhHieu9, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu10, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu11, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu12, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[46]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[47]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[48]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[49]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[50]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[51]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[52]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[53]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[54]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[55]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[56]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[57]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[58]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[59]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[60]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[61]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[62]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[63]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[64]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[65]);
		//=============================================================================================================================================================	
		break;
	case 4:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 13)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 14)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 15)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 16)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(ImgTagExDanhHieu13, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu14, StartX + 205, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 135, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu15, StartX + 310, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExDanhHieu16, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[66]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[67]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[68]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[69]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[70]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[71]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[72]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[73]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[74]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[75]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[76]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[77]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[78]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[79]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[80]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gOther.TextVN_DanhHieu[81]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gOther.TextVN_DanhHieu[82]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gOther.TextVN_DanhHieu[83]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gOther.TextVN_DanhHieu[84]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gOther.TextVN_DanhHieu[85]);
		//=============================================================================================================================================================	
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_DANH_HIEU::MAIN_DANH_HIEU(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_DANH_HIEU(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_DANH_HIEU_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].EventTick = GetTickCount();
		this->BUY_DANH_HIEU(1);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_DANH_HIEU::CLOSE_DANH_HIEU(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_DANH_HIEU_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].EventTick = GetTickCount();
	G_BEXO_DANH_HIEU.CLOSE_WINDOW_DANH_HIEU();
	// ----
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::BUY_DANH_HIEU(int Number)
{
	BUY_DANH_HIEU_REQ pMsg;
	pMsg.h.set(0xFC, 0x03, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#endif