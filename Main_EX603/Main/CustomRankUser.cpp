#include "stdafx.h"
#include "Defines.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Offset.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "Import.h"
#include "WindowsStruct.h"
#include "User.h"
#include "CustomRankUser.h"

CCustomRankUser::CCustomRankUser()
{
}

CCustomRankUser gCustomRankUser;

DWORD RunEffectTickTime[600] = { 0 };

void CCustomRankUser::DrawInfo()
{
	VAngle Angle;
	// ---
	int PosX, PosY;

	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(), n);

		ObjectPreview* Object = &*(ObjectPreview*)(ViewportAddress);

		if (!ViewportAddress)
		{
			continue;
		}

		int index = *(WORD*)(ViewportAddress + 0x7E);

		char* name = (char*)(ViewportAddress + 0x38);

		if (this->m_Data[index].m_Enabled == false)
		{
			continue;
		}

		if (*(BYTE*)(ViewportAddress + 0x30C) == 0)
		{
			continue;
		}

		if (*(BYTE*)(ViewportAddress + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
		{
			continue;
		}

		if ((((pMapNumber)<18) ? 0 : ((pMapNumber)>23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
		{
			continue;
		}

		// ---

		Angle.X = *(float*)(ViewportAddress + 0x404);

		Angle.Y = *(float*)(ViewportAddress + 0x408);

		Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		// ---
		PosX -= 42;

		if (this->m_Data[index].m_rVipTaiKhoan != 0 && !pCheckEffectPlayer((DWORD *)(ViewportAddress + 0x4EC), 28))
		//======================================
		if (!pCheckEffectPlayer((DWORD *)(ViewportAddress + 0x4EC), 28))
		{
			if ((GetTickCount() - RunEffectTickTime[index]) > 500)
			{
				gObjUser.RenderRuneEffect((int)&Object->m_Model, 32378, 2, 10, 2.0);
				RunEffectTickTime[index] = GetTickCount();
			}
		}
		//======================================
		if (gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{

			//======================================
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
#if(DANH_HIEU_NEW == 1)
				switch (this->m_Data[index].m_rDanhHieu)
				{
				case 0:
					//gInterface.DrawToolTip((float)PosX - 130, (float)PosY + 200, "no info ...");
					break;
				case 1:
					RenderBitmap(10100, (float)PosX - 58.0f, (float)PosY - 65.0f, 245, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(10200, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(10300, (float)PosX - 58.0f, (float)PosY - 65.0f, 245, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(10400, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 5:
					RenderBitmap(10500, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 6:
					RenderBitmap(10600, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 7:
					RenderBitmap(10700, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 8:
					RenderBitmap(10800, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 9:
					RenderBitmap(10900, (float)PosX - 41.0f, (float)PosY - 65.0f, 200, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 10:
					RenderBitmap(11000, (float)PosX - 30.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 11:
					RenderBitmap(11100, (float)PosX - 30.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 12:
					RenderBitmap(11200, (float)PosX - 30.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 13:
					RenderBitmap(11300, (float)PosX - 27.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 14:
					RenderBitmap(11400, (float)PosX - 27.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 15:
					RenderBitmap(11500, (float)PosX - 27.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 16:
                    RenderBitmap(11600, (float)PosX - 27.0f, (float)PosY - 65.0f, 170, 70, 0, 0, 1, 1, 1, 1, 0.0);
					break;

					pGLSwitchBlend();
				}
#endif
			}
			//======================================
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				switch (this->m_Data[index].m_rTuLuyen)
				{
	
					case 0:
					break;
					case 1:
					RenderBitmap(10128, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 2:
					RenderBitmap(10129, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 3:
					RenderBitmap(10130, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 4:
					RenderBitmap(10131, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 5:
					RenderBitmap(10132, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 6:
					RenderBitmap(10133, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 7:
					RenderBitmap(10134, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 8:
					RenderBitmap(10135, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 9:
					RenderBitmap(10136, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 10:
					RenderBitmap(10137, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 11:
					RenderBitmap(10138, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 12:
					RenderBitmap(10139, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 13:
					RenderBitmap(10140, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 14:
					RenderBitmap(10141, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 15:
					RenderBitmap(10142, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 16:
					RenderBitmap(10143, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 17:
					RenderBitmap(10144, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 18:
					RenderBitmap(10145, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 19:
					RenderBitmap(10146, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 20:
					RenderBitmap(10147, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 21:
					RenderBitmap(10148, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 22:
					RenderBitmap(10149, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 23:
					RenderBitmap(10150, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 24:
					RenderBitmap(10151, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 25:
					RenderBitmap(10152, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 26:
					RenderBitmap(10153, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 27:
					RenderBitmap(10154, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 28:
					RenderBitmap(10155, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 29:
					RenderBitmap(10156, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 30:
					RenderBitmap(10157, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 31:
					RenderBitmap(10158, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 32:
					RenderBitmap(10159, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 33:
					RenderBitmap(10160, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 34:
					RenderBitmap(10161, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 35:
					RenderBitmap(10162, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 36:
					RenderBitmap(10163, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 37:
					RenderBitmap(10164, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 38:
					RenderBitmap(10165, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 39:
					RenderBitmap(10166, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					case 40:
					RenderBitmap(10167, (float)PosX + 10.0f, (float)PosY - 70.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;

					pGLSwitchBlend();
				}
			}
			//======================================
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				switch (this->m_Data[index].m_rThueVip)
				{
				case 0:
					break;
				case 1:
					RenderBitmap(10176, (float)PosX + 32.0f, (float)PosY - 95.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(10177, (float)PosX + 32.0f, (float)PosY - 95.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(10178, (float)PosX + 32.0f, (float)PosY - 95.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(10179, (float)PosX + 32.0f, (float)PosY - 95.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;

					pGLSwitchBlend();
				}
			}

			// ---
			pGLSwitch();
			// ---
			glColor3f(1.0, 1.0, 1.0);
			//}
		}
	}
}

int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = {0};
	// ---
	int BuffLen = sizeof(Buff)-1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while(Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}

void CCustomRankUser::Test() // OK
{
	((void(*)())0x00576E40)();
	// ---
	gCustomRankUser.DrawInfo();
	// ---
	int PosX, PosY, LifeProgress, ShieldProgress;
	// ---
	float LifeBarWidth = 38.0f;
	// ---
	char LifeDisplay[20];
	// ---
	VAngle Angle;
	// --
	CPreviewManager * gPreview = new CPreviewManager;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{

		gPreview->ObjSelect(n, pObjPreviewThis); // -> Coletar Informações da ObjPreview

		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		if(!ViewportAddress)
		{
			continue;
		}


		if(*(BYTE*)(ViewportAddress+0x268) == 0 || *(BYTE*)(ViewportAddress+0x0E) == 1)
		{
			continue;
		}
	}
}
void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv)
{
	if(aRecv == NULL)
	{
		return;
	}
	// ---
	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;	
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = aRecv->iRank;
	// ---
	this->m_Data[aRecv->iIndex].m_rDanhHieu = aRecv->irDanhHieu;
	this->m_Data[aRecv->iIndex].m_rTuLuyen = aRecv->irTuLuyen;
	this->m_Data[aRecv->iIndex].m_rThueVip = aRecv->irThueVip;
	this->m_Data[aRecv->iIndex].m_rVipTaiKhoan = aRecv->irVipTaiKhoan;
	// ---
	memcpy(this->m_Data[aRecv->iIndex].szTitleRank, aRecv->szName, sizeof(this->m_Data[aRecv->iIndex].szTitleRank));
	memcpy(this->m_Data[aRecv->iIndex].m_Vip, aRecv->iVip, sizeof(this->m_Data[aRecv->iIndex].m_Vip));
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	if(!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}