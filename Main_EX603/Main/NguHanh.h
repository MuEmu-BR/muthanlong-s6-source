#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(NGU_HANH_NEW == 1)

struct PMSG_NGUHANH_UPD
{
	PSBMSG_HEAD	h;
	int		rNguHanh;

};

struct BUY_NGU_HANH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_NGUHANH
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_NGUHANH();
	void DRAW_NGUHANH();
	bool HIENTHINGUHANH;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_NGUHANH() { gInterface.Data[EXBEXO_NGUHANH_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_NGUHANH() { gInterface.Data[EXBEXO_NGUHANH_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_NGUHANH() { return gInterface.Data[EXBEXO_NGUHANH_MAIN].OnShow; };

	void		DRAW_WINDOW_NGUHANH();

	bool		MAIN_NGUHANH(DWORD Event);
	bool		CLOSE_NGUHANH(DWORD Event);

	//-----------------------------
	void GetInfoNguHanh(PMSG_NGUHANH_UPD * aRecv);
	int  m_rNguHanh;
	void BUY_NGU_HANH(int Number);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_NGUHANH G_BEXO_NGUHANH;
//===================================================================================================================================================================

#endif