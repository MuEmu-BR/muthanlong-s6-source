#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"
#if(THUE_VIP_NEW == 1)
//======================================================
//======================================================
struct BUY_THUE_VIP_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_VIPNHANVAT
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_VIPNHANVAT();
	void DRAW_VIPNHANVAT();
	bool HIENTHIVIPNHANVAT;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_VIPNHANVAT() { gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_VIPNHANVAT() { gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_VIPNHANVAT() { return gInterface.Data[EXBEXO_VIPNHANVAT_MAIN].OnShow; };

	void		DRAW_WINDOW_VIPNHANVAT();

	bool		MAIN_VIPNHANVAT(DWORD Event);
	bool		CLOSE_VIPNHANVAT(DWORD Event);

	void        BUY_THUE_VIP(int Number);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_VIPNHANVAT G_BEXO_VIPNHANVAT;
//===================================================================================================================================================================

#endif