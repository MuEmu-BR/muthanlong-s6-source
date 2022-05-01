﻿#include "stdafx.h"
#include "CustomRankUser.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Protect.h"
#include "Import.h"
#include "Common.h"
#include "JewelBank.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

void ClearNewHealthBar() // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
		gNewHealthBar[n].rate2 = 0;
		gNewHealthBar[n].bHasManyFlag = 0;
	}
}

void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = lpInfo->index;
			gNewHealthBar[n].type = lpInfo->type;
			gNewHealthBar[n].rate = lpInfo->rate;
			gNewHealthBar[n].rate2 = lpInfo->rate2;
			gNewHealthBar[n].ItemID = lpInfo->ItemID;
			gNewHealthBar[n].bHasManyFlag = lpInfo->bHasManyFlag;
			return;
		}
	}
}

NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}

void DrawNewHealthBar() // OK
{
	if (pPlayerState == 4) //Select Character
	{
		return;
	}

	int PosX, PosY, LifeProgress, ShieldProgress;

	float LifeBarWidth; // [sp+D4h] [bp-4h]@2

	LifeBarWidth = 38.0;
	

	char LifeDisplay[25];
	VAngle Angle;

	if (gProtect.m_MainInfo.DisablePartyHpBar == 1)
	{
		if (pPartyMemberCount > 0)
		{
			for (int j = 0; j < pPartyMemberCount; j++)
			{
				signed int PartyNummber = *((DWORD*)&pPartyListStruct + 8 * j + 7);

				DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(), PartyNummber);

				if (ViewportAddress)
				{
					Angle.X = *(float*)(ViewportAddress + 0x404);

					Angle.Y = *(float*)(ViewportAddress + 0x408);

					Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;

					pGetPosFromAngle(&Angle, &PosX, &PosY);

					RenderBitmap(30019, (float)(PosX - 8), (float)(PosY - 32), 24.0, 24.0, 0.0, 0.40000001f, 1.4f, 1.4f, 1, 1, 0.0);
				}
			}
		}
	}
	else if (gProtect.m_MainInfo.DisablePartyHpBar == 0)
	{
		((void(*)())0x005BA770)();
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	for (int n = 0; n < MAX_MAIN_VIEWPORT; ++n)
	{
		DWORD ViewPortAddr = pGetPreviewStruct(pPreviewThis(), n);

		lpViewObj lpObj = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);

		lpViewObj lpTarget = gObjUser.lpViewTarget;

		
		// soiitem
		bool isTarget = 1;

		if (!lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex)
		{
			isTarget = 0;
		}
		// soiitem

		if (ViewPortAddr)
		{
			if (*(BYTE*)(ViewPortAddr + 0x30C) == 0)
			{
				continue;
			}

			Angle.X = *(float*)(ViewPortAddr + 0x404);

			Angle.Y = *(float*)(ViewPortAddr + 0x408);

			Angle.Z = *(float*)(ViewPortAddr + 0x40C) + *(float*)(ViewPortAddr + 0x3E8) + 100.0f;

			pGetPosFromAngle(&Angle, &PosX, &PosY);

			//if (*(BYTE*)(ViewPortAddr + 0x320) == 1) //Check User
			//{
			//	gCustomRankUser.RenderShowLogRank(ViewPortAddr, *(WORD*)(ViewPortAddr + 0x7E), PosX - 42, PosY);
			//}

			PosX -= (int)(LifeBarWidth / 2.0);

			PosY -= 16;

			NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(*(WORD*)(ViewPortAddr + 0x7E), *(BYTE*)(ViewPortAddr + 0x320));

			char* name = (char*)(ViewPortAddr + 0x38);

			if (lpNewHealthBar == 0)
			{
				continue;
			}

			int LifePercent = lpNewHealthBar->rate / 10;
			int ShieldPercent = lpNewHealthBar->rate2 / 10;

			LifeProgress = (LifePercent > 10) ? 10 : LifePercent;
			ShieldProgress = (ShieldPercent > 10) ? 10 : ShieldPercent;

			if (*(BYTE*)(ViewPortAddr + 0x320) == 1) //Check User
			{
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((double)PosX, (double)PosY, LifeBarWidth + 4.0, (gProtect.m_MainInfo.CustomInterfaceType != 1) ? 10.0 : 6.0, 0.0, 0);
				pGLSwitch();

				if (gProtect.m_MainInfo.CustomInterfaceType != 1)
				{
					glColor4f(0.19607843, 0.039215688, 0.0, 0.8);
					pDrawBarForm((double)(PosX + 2), (double)(PosY + 2), LifeBarWidth, 2.0, 0.0, 0);
					pGLSwitch();
					glColor3f(0.98039216f, 5.039215688f, 0.0);
					for (int i = 0; i < ShieldProgress; ++i)
					{
						pDrawBarForm((double)(PosX + 4 * i + 2), (double)(PosY + 6), 3.0, 2.0, 0.0, 0);
					}
					pGLSwitch();
				}
				// soiitem
				if (GetKeyState(VK_SHIFT) & 0x8000 && isTarget)
				{
					//float width = LifeBarWidth * 1.5;
					//int pos_x = PosX - 1 - (width - LifeBarWidth) / 2;

					//gInterface.DrawBarForm(pos_x, PosY + 6, 300, 300, 0.0, 0.0, 0.0, 0.6);

					//gInterface.DrawFormat(eExcellentS15, (float)(PosX - 15), (float)(PosY + 07), LifeBarWidth + 30, 3, "%s", lpObj->Name);
					//gInterface.DrawFormat(eGold, (float)(PosX), (float)(PosY + 17), LifeBarWidth, 3, "HP:%2d.0%%", lpNewHealthBar->rate);

					int Index = (lpNewHealthBar->ItemID - (lpNewHealthBar->ItemID % 512)) / 512;
					int Type = lpNewHealthBar->ItemID % 512;

					gJewelBank.DrawLine(Index, Type, 1, (float)(PosX), (float)(PosY + 75), (char*)pGetItemAtt(Index, Type), 1);
			
					isTarget = 0;
				}
				// soiitem
			}
			else
			{
				if (HPMonster == 1)
				{
					glColor4f(0.2, 0.0, 0.0, 0.8);
					pDrawBarForm((double)PosX, (double)PosY, LifeBarWidth + 4.0, 6.0, 0.0, 0);
					pGLSwitch();
				}
			}
			if (*(BYTE*)(ViewPortAddr + 0x320) == 1) //Check User
			{
				glColor4f(0.19607843, 0.039215688, 0.0, 0.8);
				pDrawBarForm((double)(PosX + 2), (double)(PosY + 2), LifeBarWidth, 2.0, 0.0, 0);
				pGLSwitch();

				glColor3f(0.98039216, 0.039215688, 0.0);

				for (int j = 0; j < LifeProgress; ++j)
				{
					pDrawBarForm((double)(PosX + 4 * j + 2), (double)(PosY + 2), 3.0, 2.0, 0.0, 0);
				}
				pGLSwitch();
			}
			else
			{
				if (HPMonster == 1)
				{
					glColor4f(0.19607843, 0.039215688, 0.0, 0.8);
					pDrawBarForm((double)(PosX + 2), (double)(PosY + 2), LifeBarWidth, 2.0, 0.0, 0);
					pGLSwitch();

					glColor3f(0.98039216, 0.039215688, 0.0); //==<<<<<<<<<<<<<<<<< ĐAy

					for (int j = 0; j < LifeProgress; ++j)
					{
						pDrawBarForm((double)(PosX + 4 * j + 2), (double)(PosY + 2), 3.0, 2.0, 0.0, 0);
					}
					pGLSwitch();
				}
			}

			if ((pCursorX >= PosX - 2) && ((float)pCursorX <= (float)PosX + LifeBarWidth + 2) && (pCursorY >= PosY - 2) && (pCursorY < PosY + 10))
			{
				if (*(BYTE*)(ViewPortAddr + 0x320) == 1) //Check User
				{
					if (gProtect.m_MainInfo.CustomInterfaceType != 1)
					{
						wsprintf(LifeDisplay, "HP : %d0%% | SD : %d0%%", LifePercent, ShieldPercent);
						pSetTextColor(pTextThis(), 0xFF, 0xE6, 0xD2, 0xFF);
						pDrawText(pTextThis(), PosX - 20, PosY - 10, LifeDisplay, 0, 0, (LPINT)3, 0);
					}
					else
					{
						wsprintf(LifeDisplay, "HP : %d0%%", LifePercent);
						pSetTextColor(pTextThis(), 0xFF, 0xE6, 0xD2, 0xFF);
						pDrawText(pTextThis(), PosX, PosY - 8, LifeDisplay, 0, 0, (LPINT)3, 0);
					}
				}
				else
				{
					if (HPMonster == 1)
					{
						wsprintf(LifeDisplay, "HP : %d0%%", LifePercent);
						pSetTextColor(pTextThis(), 0xFF, 0xE6, 0xD2, 0xFF);
						pDrawText(pTextThis(), PosX, PosY - 8, LifeDisplay, 0, 0, (LPINT)3, 0);
					}
				}
			}
		}
		pGLSwitch();
		EnableAlphaTest(0);
	}

	gCustomRankUser.DrawInfo();

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}

bool PlayerHasManyFlag(WORD index)
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].bHasManyFlag > 0)
			{
				return 1;
			}
		}
	}
	return 0;
}