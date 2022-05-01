#include "stdafx.h"
#include "CLoginWin.h"
#include "Util.h"

CLoginWin gCLoginWin;

float CLoginWin_x, CLoginWin_y;
void CLoginWin::cSetPosition(BYTE *This, int nXCoord, int nYCoord, int eChangedPram)
{
	CLoginWin_x = nXCoord;
	CLoginWin_y = nYCoord;
	Sprite_SetPosition(This, nXCoord, nYCoord, eChangedPram);
}

char iUser[32], iPassword[32];
void CButtonAutoLogin(int This, int a2)
{
	CUIRenderText_SetFont((int)pTextThis(), *(int*)0xE8C594);

	GetPrivateProfileString("AutoLogin", "User", "", iUser, 32, ".\\Settings.ini");
	GetPrivateProfileString("AutoLogin", "Password", "", iPassword, 32, ".\\Settings.ini");

	int Struct = InstanceProc() + 16968;
	float v = 0.0, vHeight = 0.235;
	if (SEASON3B_CheckMouseIn((CLoginWin_x - 122) / g_fScreenRate_x, CLoginWin_y / g_fScreenRate_y, 54 / g_fScreenRate_x, 30 / g_fScreenRate_y))
	{
		v = vHeight;
		if (IsPress(1))
		{
			v = vHeight + vHeight;
			PlayBuffer(25, 0, 0);
			InputBox_SetText(*(DWORD *)(Struct + 848), iUser);
			InputBox_SetText(*(DWORD *)(Struct + 852), iPassword);
			RequestLogin(Struct);
		}
	}
	RenderBitmap(531141, CLoginWin_x - 122, CLoginWin_y, 54, 30, 0.0, v, 0.84, vHeight, 0, 0, 0.0);
}

void CLoginWin::Load()
{
	SetCompleteHook(0xE8, 0x0040B306, &CLoginWin::cSetPosition);
	SetCompleteHook(0xE8, 0x0040B5A9, &CButtonAutoLogin);
}