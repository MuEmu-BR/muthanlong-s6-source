#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(KINH_MACH_NEW == 1)
//======================================================
struct PMSG_KINHMACH_UPD
{
	PSBMSG_HEAD	h;
	int KINHMACH1;
	int KINHMACH2;
	int KINHMACH3;
	int KINHMACH4;
	int KINHMACH5;
	int KINHMACH6;
	int KINHMACH7;
	int KINHMACH8;
	int KINHMACHSD;
	int KINHMACHHP;
};
struct PMSG_KINHMACH_LEVEL_UPD
{
	PSBMSG_HEAD	h;
	int		MAX_KINH_MACH_01;
	int		MAX_KINH_MACH_02;
	int		MAX_KINH_MACH_03;
	int		MAX_KINH_MACH_04;
	int		MAX_KINH_MACH_05;
	int		MAX_KINH_MACH_06;
	int		MAX_KINH_MACH_07;
	int		MAX_KINH_MACH_08;
};
//======================================================
struct BUY_KINH_MACH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//======================================================
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_KINHMACH
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_KINHMACH();
	void DRAW_KINHMACH();
	bool HIENTHIKINHMACH;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_KINHMACH() { gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_KINHMACH() { gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_KINHMACH() { return gInterface.Data[EXBEXO_KINHMACH_MAIN].OnShow; };

	void		DRAW_WINDOW_KINHMACH();

	bool		MAIN_KINHMACH(DWORD Event);
	bool		CLOSE_KINHMACH(DWORD Event);

	//-----------------------------
	void GetInfoKinhMach(PMSG_KINHMACH_UPD * aRecv);
	int m_KINHMACH1;
	int m_KINHMACH2;
	int m_KINHMACH3;
	int m_KINHMACH4;
	int m_KINHMACH5;
	int m_KINHMACH6;
	int m_KINHMACH7;
	int m_KINHMACH8;
	int m_KINHMACHSD;
	int m_KINHMACHHP;

	void GetInfoKinhMachLevel(PMSG_KINHMACH_LEVEL_UPD* aRecv);
	int	m_MAX_KINH_MACH_01;
	int	m_MAX_KINH_MACH_02;
	int	m_MAX_KINH_MACH_03;
	int	m_MAX_KINH_MACH_04;
	int	m_MAX_KINH_MACH_05;
	int	m_MAX_KINH_MACH_06;
	int	m_MAX_KINH_MACH_07;
	int	m_MAX_KINH_MACH_08;

	void BUY_KINH_MACH(int Number);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_KINHMACH G_BEXO_KINHMACH;
//===================================================================================================================================================================

#endif