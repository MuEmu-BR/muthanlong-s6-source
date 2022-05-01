#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(VIP_TAI_KHOAN_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_VIPTAIKHOAN
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_VIPTAIKHOAN();
	void DRAW_VIPTAIKHOAN();
	bool HIENTHIVIPTAIKHOAN;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_VIPTAIKHOAN() { gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_VIPTAIKHOAN() { gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_VIPTAIKHOAN() { return gInterface.Data[EXBEXO_VIPTAIKHOAN_MAIN].OnShow; };

	void		DRAW_WINDOW_VIPTAIKHOAN();

	bool		MAIN_VIPTAIKHOAN(DWORD Event);
	bool		CLOSE_VIPTAIKHOAN(DWORD Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_VIPTAIKHOAN G_BEXO_VIPTAIKHOAN;

#endif