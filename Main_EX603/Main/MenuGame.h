#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_MENU
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_MENU();
	void DRAW_MENU();
	void BIND();
	bool HIENTHIMENU;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_MENU() { gInterface.Data[EXBEXO_MENU_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_MENU() { gInterface.Data[EXBEXO_MENU_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_MENU() { return gInterface.Data[EXBEXO_MENU_MAIN].OnShow; };

	void		DRAW_WINDOW_MENU();

	bool		MAIN_MENU(DWORD Event);
	bool		CLOSE_MENU(DWORD Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_MENU G_BEXO_MENU;
//===================================================================================================================================================================

