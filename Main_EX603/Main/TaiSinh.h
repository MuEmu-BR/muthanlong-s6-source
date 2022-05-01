#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(TAISINH == 1)

struct TAISINH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_TAISINH
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_TAISINH();
	void DRAW_TAISINH();
	void BIND();
	bool HIENTHITAISINH;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;

	void TAISINH_ATIVE(int Number);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_TAISINH() { gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_TAISINH() { gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_TAISINH() { return gInterface.Data[EXBEXO_TAISINH_MAIN].OnShow; };

	void		DRAW_WINDOW_TAISINH();

	bool		MAIN_TAISINH(DWORD Event);
	bool		CLOSE_TAISINH(DWORD Event);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_TAISINH G_BEXO_TAISINH;
//===================================================================================================================================================================

#endif