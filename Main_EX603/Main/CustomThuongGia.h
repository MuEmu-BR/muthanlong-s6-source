#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"
#define MAX_ITEM_SPIN 12
#define SET_ITEMOPT_LEVEL(x)		(x << 3)

struct ThuongGiaZen_Data
{
	int ItemType;
	int ItemIndex;
	int ItemLevel;
	int ItemSkill;
	int ItemLuck;
	int ItemOption;
	int ItemExc;
	int ItemTime;
};
struct GC_ThuongGiaZen_Data
{
	PSBMSG_HEAD h;
	int ItemType;
	int ItemIndex;
	int ItemLevel;
	int ItemSkill;
	int ItemLuck;
	int ItemOption;
	int ItemExc;
	int ItemTime;
};

struct GC_ThuongGiaZenInit
{
	PSBMSG_HEAD h;
	bool result;
};

struct THUONGGIAZEN_REQ
{
	PSBMSG_HEAD	h;
};
struct ThuongGiaZen_UpdateData
{
	PSBMSG_HEAD header; // C1:F3:E3
	int	RollNumberZen;
};
//======================================================
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_THUONG_GIA
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_THUONG_GIA();
	void DRAW_THUONG_GIA();
	bool HIENTHITHUONG_GIA;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_THUONG_GIA;
	void BEXO_CLICK_TRANG_THUONG_GIA(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_THUONG_GIA() { gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_THUONG_GIA() { gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_THUONG_GIA() { return gInterface.Data[EXBEXO_THUONG_GIA_MAIN].OnShow; };

	void		DRAW_WINDOW_THUONG_GIA();

	bool		MAIN_THUONG_GIA(DWORD Event);
	bool		CLOSE_THUONG_GIA(DWORD Event);

	DWORD StartRollZen;
	int RollNumberZen;
	void ThuongGiaZenSend();
	void GCThuongGiaZenInit(GC_ThuongGiaZenInit* aRecv);
	void ThuongGiaZenData(ThuongGiaZen_UpdateData * aRecv);
	void ThuongGiaZenItemSend(GC_ThuongGiaZen_Data* aRecv);
	std::vector<ThuongGiaZen_Data> itemdataZen;

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_THUONG_GIA G_BEXO_THUONG_GIA;
//===================================================================================================================================================================

