#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "MOCNAP.h"
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

#if(MOCNAP == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_MOCNAP G_BEXO_MOCNAP;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_MOCNAP::BEXO_MOCNAP()
{
	//--------------------------------------------------------------
	HIENTHIMOCNAP = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_MOCNAP::BIND()
{
	gInterface.BindObject(EXBEXO_MOCNAP_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_MOCNAP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(MOCNAP1, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP2, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP3, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP4, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP5, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP6, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP7, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP8, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP9, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP10, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP11, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP12, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP13, 10099, 30, 20, -1, -1);
}
// ----------------------------------------------------------------------------------------------


void BEXO_MOCNAP::DRAW_MOCNAP()
{
	DRAW_WINDOW_MOCNAP();
}

void BEXO_MOCNAP::DRAW_WINDOW_MOCNAP()
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
	if (!gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow)
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
	gCentral.PrintDropBox(StartX + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 25, 230, 360, 0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_MOCNAP_CLOSE, StartX + 400, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 23);
	if (gInterface.IsWorkZone(EXBEXO_MOCNAP_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_MOCNAP_CLOSE, gInterface.Data[EXBEXO_MOCNAP_CLOSE].X, gInterface.Data[EXBEXO_MOCNAP_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XMOCNAP = 150;

	gInterface.DrawFormat(eGold, XMOCNAP + 65, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 30, 200, 3, "Quà Nạp Theo Mốc");
	gInterface.DrawFormat(eBlue, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 45, 200, 3, "Để trống hòm đồ trước khi nhận!");

	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 1
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 60, 200, 15, 0.0, 0);
	//----
	int MocNap1;
	if (gObjUser.MocNapCheck1 > 0)
	{
		MocNap1 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck1) / gObjUser.MocNapCheck1;
		if (MocNap1 > gObjUser.MocNapCheck1)
		{
			MocNap1 = gObjUser.MocNapCheck1;
		}
	}
	float TyLeNap1 = (202.0 * MocNap1) / gObjUser.MocNapCheck1;
	if (TyLeNap1 > 202.0) { TyLeNap1 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 60.0f, TyLeNap1, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck1);
	//----
	if (gObjUser.MOCNAP1 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP1 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck1)
		{
			gInterface.DrawGUI(MOCNAP1, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 57);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP1))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP1, gInterface.Data[MOCNAP1].X, gInterface.Data[MOCNAP1].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 2
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 85, 200, 15, 0.0, 0);
	//----
	int MocNap2;
	if (gObjUser.MocNapCheck2 > 0)
	{
		MocNap2 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck2) / gObjUser.MocNapCheck2;
		if (MocNap2 > gObjUser.MocNapCheck2)
		{
			MocNap2 = gObjUser.MocNapCheck2;
		}
	}
	float TyLeNap2 = (202.0 * MocNap2) / gObjUser.MocNapCheck2;
	if (TyLeNap2 > 202.0) { TyLeNap2 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 85.0f, TyLeNap2, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck2);

	//----
	if (gObjUser.MOCNAP2 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP2 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck2)
		{
			gInterface.DrawGUI(MOCNAP2, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 82);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP2))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP2, gInterface.Data[MOCNAP2].X, gInterface.Data[MOCNAP2].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 3
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 110, 200, 15, 0.0, 0);
	//----
	int MocNap3;
	if (gObjUser.MocNapCheck3 > 0)
	{
		MocNap3 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck3) / gObjUser.MocNapCheck3;
		if (MocNap3 > gObjUser.MocNapCheck3)
		{
			MocNap3 = gObjUser.MocNapCheck3;
		}
	}
	float TyLeNap3 = (202.0 * MocNap3) / gObjUser.MocNapCheck3;
	if (TyLeNap3 > 202.0) { TyLeNap3 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 110.0f, TyLeNap3, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck3);

	//----
	if (gObjUser.MOCNAP3 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP3 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck3)
		{
			gInterface.DrawGUI(MOCNAP3, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 107);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP3))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP3, gInterface.Data[MOCNAP3].X, gInterface.Data[MOCNAP3].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 4
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 135, 200, 15, 0.0, 0);
	//----
	int MocNap4;
	if (gObjUser.MocNapCheck4 > 0)
	{
		MocNap4 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck4) / gObjUser.MocNapCheck4;
		if (MocNap4 > gObjUser.MocNapCheck4)
		{
			MocNap4 = gObjUser.MocNapCheck4;
		}
	}
	float TyLeNap4 = (202.0 * MocNap4) / gObjUser.MocNapCheck4;
	if (TyLeNap4 > 202.0) { TyLeNap4 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 135.0f, TyLeNap4, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck4);
	//----
	if (gObjUser.MOCNAP4 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP4 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck4)
		{
			gInterface.DrawGUI(MOCNAP4, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 132);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP4))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP4, gInterface.Data[MOCNAP4].X, gInterface.Data[MOCNAP4].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 5
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 160, 200, 15, 0.0, 0);
	//----
	int MocNap5;
	if (gObjUser.MocNapCheck5 > 0)
	{
		MocNap5 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck5) / gObjUser.MocNapCheck5;
		if (MocNap5 > gObjUser.MocNapCheck5)
		{
			MocNap5 = gObjUser.MocNapCheck5;
		}
	}
	float TyLeNap5 = (202.0 * MocNap5) / gObjUser.MocNapCheck5;
	if (TyLeNap5 > 202.0) { TyLeNap5 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 160.0f, TyLeNap5, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck5);
	//----
	if (gObjUser.MOCNAP5 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP5 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck5)
		{
			gInterface.DrawGUI(MOCNAP5, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 157);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP5))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP5, gInterface.Data[MOCNAP5].X, gInterface.Data[MOCNAP5].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 6
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 185, 200, 15, 0.0, 0);
	//----
	int MocNap6;
	if (gObjUser.MocNapCheck6 > 0)
	{
		MocNap6 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck6) / gObjUser.MocNapCheck6;
		if (MocNap6 > gObjUser.MocNapCheck6)
		{
			MocNap6 = gObjUser.MocNapCheck6;
		}
	}
	float TyLeNap6 = (202.0 * MocNap6) / gObjUser.MocNapCheck6;
	if (TyLeNap6 > 202.0) { TyLeNap6 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 185.0f, TyLeNap6, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck6);
	//----
	if (gObjUser.MOCNAP6 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP6 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck6)
		{
			gInterface.DrawGUI(MOCNAP6, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 182);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP6))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP6, gInterface.Data[MOCNAP6].X, gInterface.Data[MOCNAP6].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 7
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 210, 200, 15, 0.0, 0);
	//----
	int MocNap7;
	if (gObjUser.MocNapCheck7 > 0)
	{
		MocNap7 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck7) / gObjUser.MocNapCheck7;
		if (MocNap7 > gObjUser.MocNapCheck7)
		{
			MocNap7 = gObjUser.MocNapCheck7;
		}
	}
	float TyLeNap7 = (202.0 * MocNap7) / gObjUser.MocNapCheck7;
	if (TyLeNap7 > 202.0) { TyLeNap7 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 210.0f, TyLeNap7, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck7);
	//----
	if (gObjUser.MOCNAP7 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP7 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck7)
		{
			gInterface.DrawGUI(MOCNAP7, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 207);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP7))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP7, gInterface.Data[MOCNAP7].X, gInterface.Data[MOCNAP7].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 8
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 235, 200, 15, 0.0, 0);
	//----
	int MocNap8;
	if (gObjUser.MocNapCheck8 > 0)
	{
		MocNap8 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck8) / gObjUser.MocNapCheck8;
		if (MocNap8 > gObjUser.MocNapCheck8)
		{
			MocNap8 = gObjUser.MocNapCheck8;
		}
	}
	float TyLeNap8 = (202.0 * MocNap8) / gObjUser.MocNapCheck8;
	if (TyLeNap8 > 202.0) { TyLeNap8 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 235.0f, TyLeNap8, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck8);
	//----
	if (gObjUser.MOCNAP8 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP8 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck8)
		{
			gInterface.DrawGUI(MOCNAP8, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 232);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP8))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP8, gInterface.Data[MOCNAP8].X, gInterface.Data[MOCNAP8].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 9
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 260, 200, 15, 0.0, 0);
	//----
	int MocNap9;
	if (gObjUser.MocNapCheck9 > 0)
	{
		MocNap9 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck9) / gObjUser.MocNapCheck9;
		if (MocNap9 > gObjUser.MocNapCheck9)
		{
			MocNap9 = gObjUser.MocNapCheck9;
		}
	}
	float TyLeNap9 = (202.0 * MocNap9) / gObjUser.MocNapCheck9;
	if (TyLeNap9 > 202.0) { TyLeNap9 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 260.0f, TyLeNap9, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck9);
	//----
	if (gObjUser.MOCNAP9 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP9 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck9)
		{
			gInterface.DrawGUI(MOCNAP9, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 257);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP9))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP9, gInterface.Data[MOCNAP9].X, gInterface.Data[MOCNAP9].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 10
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 285, 200, 15, 0.0, 0);
	//----
	int MocNap10;
	if (gObjUser.MocNapCheck10 > 0)
	{
		MocNap10 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck10) / gObjUser.MocNapCheck10;
		if (MocNap10 > gObjUser.MocNapCheck10)
		{
			MocNap10 = gObjUser.MocNapCheck10;
		}
	}
	float TyLeNap10 = (202.0 * MocNap10) / gObjUser.MocNapCheck10;
	if (TyLeNap10 > 202.0) { TyLeNap10 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 285.0f, TyLeNap10, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck10);
	//----
	if (gObjUser.MOCNAP10 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP10 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck10)
		{
			gInterface.DrawGUI(MOCNAP10, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 282);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP10))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP10, gInterface.Data[MOCNAP10].X, gInterface.Data[MOCNAP10].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 11
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 310, 200, 15, 0.0, 0);
	//----
	int MocNap11;
	if (gObjUser.MocNapCheck11 > 0)
	{
		MocNap11 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck11) / gObjUser.MocNapCheck11;
		if (MocNap11 > gObjUser.MocNapCheck11)
		{
			MocNap11 = gObjUser.MocNapCheck11;
		}
	}
	float TyLeNap11 = (202.0 * MocNap11) / gObjUser.MocNapCheck11;
	if (TyLeNap11 > 202.0) { TyLeNap11 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 310.0f, TyLeNap11, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck11);
	//----
	if (gObjUser.MOCNAP11 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP11 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck11)
		{
			gInterface.DrawGUI(MOCNAP11, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 307);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP11))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP11, gInterface.Data[MOCNAP11].X, gInterface.Data[MOCNAP11].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 12
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 335, 200, 15, 0.0, 0);
	//----
	int MocNap12;
	if (gObjUser.MocNapCheck12 > 0)
	{
		MocNap12 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck12) / gObjUser.MocNapCheck12;
		if (MocNap12 > gObjUser.MocNapCheck12)
		{
			MocNap12 = gObjUser.MocNapCheck12;
		}
	}
	float TyLeNap12 = (202.0 * MocNap12) / gObjUser.MocNapCheck12;
	if (TyLeNap12 > 202.0) { TyLeNap12 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 335.0f, TyLeNap12, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck12);
	//----
	if (gObjUser.MOCNAP12 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP12 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck12)
		{
			gInterface.DrawGUI(MOCNAP12, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 332);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP12))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP12, gInterface.Data[MOCNAP12].X, gInterface.Data[MOCNAP12].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 13
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 360, 200, 15, 0.0, 0);
	//----
	int MocNap13;
	if (gObjUser.MocNapCheck13 > 0)
	{
		MocNap13 = (gInterface.m_MOCNAPCOIN * gObjUser.MocNapCheck13) / gObjUser.MocNapCheck13;
		if (MocNap13 > gObjUser.MocNapCheck13)
		{
			MocNap13 = gObjUser.MocNapCheck13;
		}
	}
	float TyLeNap13 = (202.0 * MocNap13) / gObjUser.MocNapCheck13;
	if (TyLeNap13 > 202.0) { TyLeNap13 = 202.0; }
	RenderBitmap(0x0897, 201.0f, 360.0f, TyLeNap13, 21.0f, 0, 0, 1, 1, 1, 1, 0.0);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362, 200, 3, "Mốc Nạp %dk", gObjUser.MocNapCheck13);
	//----
	if (gObjUser.MOCNAP13 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP13 == 0)
	{
		if (gInterface.m_MOCNAPCOIN >= gObjUser.MocNapCheck13)
		{
			gInterface.DrawGUI(MOCNAP13, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 357);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP13))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP13, gInterface.Data[MOCNAP13].X, gInterface.Data[MOCNAP13].Y, Color);
			}
		}
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MOCNAP::MAIN_MOCNAP(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_MOCNAP(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP1].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(20);
	}
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP2].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(21);
	}
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP3))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP3].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP3].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(22);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP4))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP4].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP4].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(23);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP5))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP5].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP5].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(24);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP6))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP6].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP6].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP6].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP6].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(25);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP7))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP7].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP7].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP7].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP7].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(26);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP8))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP8].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP8].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP8].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP8].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(27);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP9))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP9].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP9].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP9].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP9].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(28);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP10))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP10].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP10].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP10].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP10].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(29);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP11))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP11].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP11].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP11].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP11].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(30);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP12))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP12].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP12].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP12].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP12].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(31);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP13))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP13].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP13].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP13].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP13].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(32);
	}
	//------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MOCNAP::CLOSE_MOCNAP(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_MOCNAP_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_MOCNAP_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_MOCNAP_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_MOCNAP_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_MOCNAP_CLOSE].EventTick = GetTickCount();
	G_BEXO_MOCNAP.CLOSE_WINDOW_MOCNAP();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif