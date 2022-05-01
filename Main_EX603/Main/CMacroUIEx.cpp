#include "stdafx.h"
#include "CMacroUIEx.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "MuHelper.h"
#include "Protocol.h"
#include "Common.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "Camera.h"
#include "Other.h"
#include "PrintPlayer.h"
#include "SItemOption.h"

// ---------------------------------------------------------------------------------------------
CMacroUIEx gCMacroUIEx;
// ---------------------------------------------------------------------------------------------

int ImgTag = 0; //Rank Dynamic

void CMacroUIEx::RenderFrame(int *This)
{
	//--Fix Click Mouse Esquina Izquierda
	if (gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
		if (pCheckMouseOver(1, 1, 145, 145))
		{
			pSetCursorFocus = false;
		}
	}
	if (gProtect.m_MainInfo.MuHelperType == 1)
	{
		float CY;
		char Cord[256];
		float X = (double)*((DWORD *)This + 5);
		float Y = (double)*((signed int *)This + 6);

		float renderMenu = 15.0f;

		EnableAlphaTest(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		renderMenu = 10.0f;

		RenderBitmap(51550, X + 84.0 + renderMenu, Y, 124.0, 24.0, 0.0, 0.285, 0.715, 0.26, 1, 1, 0.0);
		RenderBitmap(51550, X, Y, 124.0, 24.0, 0.0, 0.0, 0.715, 0.28, 1, 1, 0.0);

		//Mapa y Coordenadas
		if (World >= 82 && World <= 106)
		{
			wsprintf(Cord, "%s  %d,%d", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
		}
		else
		{
			wsprintf(Cord, "%s  %d,%d", pMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
		}

		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
		pDrawText(pTextThis(), X - 35, Y + 4, Cord, 190, 0, (LPINT)3, 0);
		//Extra
		DWORD Color = Color4f(255, 189, 25, 255);
		gInterface.DrawFormat(Color, X + 154 + renderMenu, Y + 2, 27.5, 3, "0");
		pGLSwitch();
		EnableAlphaTest(0);
		//Botones
		renderMenu = 15.0f;
		gInterface.DrawButtonRender(ButtonSettings, 119.5f + renderMenu, 7.0, 0, 0);
		//-- Config
		if (gInterface.IsWorkZone(ButtonSettings))
		{
			gInterface.DrawToolTip(X + 119.5 + renderMenu, Y + 50, "Config Helper");

			if (gInterface.Data[ButtonSettings].OnClick)
			{
				RenderBitmap(51546, X + 119.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
			}
			else
			{
				RenderBitmap(51546, X + 119.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
			}
		}
		else
		{
			RenderBitmap(51546, X + 119.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
		}
		if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
		{
			gInterface.DrawButtonRender(ButtonStart, 138.5 + renderMenu, 7.0, 0, 0.0f);
			//-- Play
			if (gInterface.IsWorkZone(ButtonStart))
			{
				gInterface.DrawToolTip(X + 138.5 + renderMenu, Y + 50, "Play Helper");

				if (gInterface.Data[ButtonStart].OnClick)
				{
					RenderBitmap(51547, X + 138.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
				}
				else
				{
					RenderBitmap(51547, X + 138.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(51547, X + 138.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
			}
		}
		else
		{
			gInterface.DrawButtonRender(ButtonStop, 138.5 + renderMenu, 7.0, 0, 0.0f);
			if (offhelper == 1 && !gObjUser.InSafeZone)
			{
				gMuHelper.RunningOffHelper();
			}
			//-- Pause
			if (gInterface.IsWorkZone(ButtonStop))
			{
				gInterface.DrawToolTip(X + 138.5 + renderMenu, Y + 50, "Pause Helper");

				if (gInterface.Data[ButtonStop].OnClick)
				{
					RenderBitmap(51548, X + 138.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
				}
				else
				{
					RenderBitmap(51548, X + 138.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(51548, X + 138.5 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
			}
		}
		//=======================================================
		if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
		{
			if (gProtect.m_MainInfo.CustomMenuType == 2)
			{
				gInterface.DrawButtonRender(eMenu, X + 100.0f + renderMenu, Y + 7.0, 0, 0.0f);

				if (gInterface.IsWorkZone(eMenu))
				{
					gInterface.DrawToolTip(X + 100.0f + renderMenu, 50, "Click Mở Bảng MenuGame");
					// ----
					if (gInterface.Data[eMenu].OnClick)
					{
						RenderBitmap(51553, X + 100.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
					}
					else
					{
						RenderBitmap(51553, X + 100.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
					}
				}
				else
				{
					RenderBitmap(51553, X + 100.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
				}
			}
			else if (gProtect.m_MainInfo.CustomMenuType == 1)
			{
				if (pCheckMouseOver(131, 25, 45, 23))
				{
					pSetCursorFocus = true;
				}
				if (pCheckMouseOver(131, 25, 45, 23))
				{
					gInterface.DrawToolTip(X + 125.0f + renderMenu, 50, "Click Mở Bảng MenuGame");
					if (*(BYTE*)0x8793386)
					{
						RenderBitmap(0x7906, 139, 26.2, 56, 24, 0, 0, 0.8, 1, 0.1, 1, 0);
						if (GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200)
						{
						}
					}
					else
					{
						pSetBlend(true);
						glColor3f(1.0, 0.94, 0.44);
						pGLSwitchBlend();
						RenderBitmap(0x7906, 139, 26.2, 56, 24, 0, 0, 0.8, 1, 0.1, 1, 0);
						pGLSwitch();
						glColor3f(1.0, 1.0, 1.0);
						pSetBlend(false);
					}
				}
				else
				{
					RenderBitmap(0x7906, 139, 26, 56, 24, 0, 0, 0.8, 1, 0.1, 1, 0);
				}
			}
			//=======================================================
			if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
			{
				if (gInterface.CheckWindow(ObjWindow::ChatWindow))
				{
					return;
				}
				//--------------------------------------------------------------------------------------------
				if (pCheckMouseOver(285, 420, 43, 17))
				{
					pSetCursorFocus = true;
				}

				gInterface.DrawGUI(eAUTORESET, 285, 420);

				if (CheckButtonPressed(285, 420, Return2X(TransForX(43)), ReturnY(TransForY(17))))
				{
					RenderBitmap(61535, 285, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
				}
				else
				{
					RenderBitmap(61535, 285, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
				}
				gInterface.DrawFormat(eTextShop, 290, 423, 210, 1, gOther.TextVN[138]); // Auto Reset
				//--------------------------------------------------------------------------------------------
				//=======================================================
				//--------------------------------------------------------------------------------------------
				if (gInterface.CheckWindow(ObjWindow::ChatWindow))
				{
					return;
				}
				if (pCheckMouseOver(325, 420, 43, 17))
				{
					pSetCursorFocus = true;
				}

				gInterface.DrawGUI(eATTACK, 325, 420);

				if (CheckButtonPressed(325, 420, Return2X(TransForX(43)), ReturnY(TransForY(17))))
				{
					RenderBitmap(61535, 325, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
				}
				else
				{
					RenderBitmap(61535, 325, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
				}
				gInterface.DrawFormat(eTextShop, 330, 423, 210, 1, gOther.TextVN[139]); // Tự đánh
			}
			//--------------------------------------------------------------------------------------------
			if (gInterface.m_AttackCustom == 1)
			{
				if (pCheckMouseOver(305, 375, 43, 17))
				{
					pSetCursorFocus = true;
				}

				gInterface.DrawGUI(eOFFATTACK, 305, 380);

				if (CheckButtonPressed(305, 380, Return2X(TransForX(43)), ReturnY(TransForY(17))))
				{
					RenderBitmap(61535, 305, 380, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
				}
				else
				{
					RenderBitmap(61535, 305, 380, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
				}
				gInterface.DrawFormat(eYellow, 308, 383, 210, 1, "OffAttack");
			}
		}
		//--------------------------------------------------------------------------------------------
		if (gInterface.m_AutoResetEnable == 1)
		{
			gCItemSetOption.ItemTooltipS15(100, 30 , 90, 12, 0.0, 0);
			gInterface.DrawFormat(eAncient, 100, 30, 210, 1, "Tự động Resets (Bật)");
		}
		if (gInterface.m_AttackCustom == 1)
		{
			gCItemSetOption.ItemTooltipS15(100, 50, 90, 12, 0.0, 0);
			gInterface.DrawFormat(eAncient, 100, 50, 210, 1, "Tự động đánh (Bật)");
		}
		if (DisablePlayer == 1)
		{
			gCItemSetOption.ItemTooltipS15(100, 70, 90, 12, 0.0, 0);
			gInterface.DrawFormat(eAncient, 100, 70, 210, 1, "Ẩn Nhân Vật (Bật)");
		}
		//--------------------------------------------------------------------------------------------
		if (gObjUser.GifCode == 0)
		{
			gCItemSetOption.ItemTooltipS15(5, 410, 95, 12, 0.0, 0);
			gInterface.DrawFormat(eWhite, 5, 410, 210, 1, "%s", gProtect.m_MainInfo.NameGifCode);
		}
	}
}

void CMacroUIEx::Button(DWORD Event)
{
	if (gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (gInterface.IsWorkZone(ButtonSettings))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[ButtonSettings].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[ButtonSettings].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonSettings].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[ButtonSettings].EventTick = GetTickCount();
		// ----
	}
	else if (gInterface.IsWorkZone(ButtonStart))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[ButtonStart].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[ButtonStart].OnClick = true;

			return;
		}
		// ----
		gInterface.Data[ButtonStart].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[ButtonStart].EventTick = GetTickCount();
		// ----
	}
	else if (gInterface.IsWorkZone(ButtonStop))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[ButtonStop].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[ButtonStop].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonStop].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[ButtonStop].EventTick = GetTickCount();
		// ----
	}

	else if (gInterface.IsWorkZone(eAUTORESET))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eAUTORESET].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eAUTORESET].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[eAUTORESET].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eAUTORESET].EventTick = GetTickCount();
		// ----
		if (GetForegroundWindow() == pGameWindow)
		{
			gInterface.BUY_TINH_NANG_GAME(5);
		}
		// ----
	}

	else if (gInterface.IsWorkZone(eATTACK))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eATTACK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eATTACK].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[eATTACK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eATTACK].EventTick = GetTickCount();
		// ----
		if (GetForegroundWindow() == pGameWindow)
		{
			gInterface.BUY_TINH_NANG_GAME(6);
		}
		// ----
	}

	if (gInterface.m_AttackCustom == 1)
	{
		if (gInterface.IsWorkZone(eOFFATTACK))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[eOFFATTACK].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eOFFATTACK].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[eOFFATTACK].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			gInterface.Data[eOFFATTACK].EventTick = GetTickCount();
			// ----

			if (gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow)//
			{
				return;
			}

			gInterface.BUY_TINH_NANG_GAME(11);
			// ----
		}
	}
}

char BarTime(int This)
{
  float v1; // ST10_4@2
  float v2; // ST0C_4@2
  float v3; // ST30_4@3
  float v4; // ST08_4@3
  float v5; // ST04_4@3
  float v6; // ST10_4@5
  float v7; // ST0C_4@5
  float v8; // ST1C_4@5
  float v9; // ST08_4@5
  float v10; // ST04_4@5
  const CHAR *v11; // eax@7
  int v13; // [sp+30h] [bp-4h]@1

  v13 = This;
  if ( *(BYTE *)(This + 72) == 1 )
  {
    v1 = (double)*(signed int *)(This + 20);
    v2 = (double)*(signed int *)(This + 16);
    RenderImage2(51522, v2, v1);//Textura "none.tga"
    if ( *(DWORD *)(v13 + 88) == 1 )
    {
      v3 = *(float *)(v13 + 92) * 50.0;
      v4 = (double)(*(DWORD *)(v13 + 20) + 2);
      v5 = (double)(*(DWORD *)(v13 + 16) + 2);
      RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
    }
    else if ( *(DWORD *)(v13 + 88) > 1 )
    {
      v6 = (double)(*(DWORD *)(v13 + 20) + 2);
      v7 = (double)(*(DWORD *)(v13 + 16) + 2);
      RenderImage2(*(DWORD *)(v13 + 88) + 31763, v7, v6);
      v8 = *(float *)(v13 + 92) * 152.0;
      v9 = (double)(*(DWORD *)(v13 + 20) + 2);
      v10 = (double)(*(DWORD *)(v13 + 16) + 2);
      RenderImage(*(DWORD *)(v13 + 88) + 51522, v10, v9, v8, 4.0);//Textura "none.tga"
    }
//DrawToolTip
	/*
    if ( *(BYTE *)(v13 + 128) == 1 )
    {
      v11 = (const CHAR *)sub_402880(v13 + 100);
      sub_597220(*(DWORD *)(v13 + 132), *(DWORD *)(v13 + 136), v11);
    }
	*/
  }
  return 1;
}

//-- (007D25C0)
__declspec(naked) void MuHelperRemake_01()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 119.5 + 15.0f;
	static DWORD Y = 7;

	_asm
	{
		PUSH W                                  ; |Arg6 = 0000000D
		PUSH H                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_02()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138.5 + 15.0f;
	static DWORD Y = 5;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_03()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138.5 + 15.0f;
	static DWORD Y = 5;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Remake_Buffer]
	}
}

//==========================================================================================

void CMacroUIEx::RenderHelperFrame(int *This)
{
	if(gProtect.m_MainInfo.MuHelperType == 0)
	{
	//--Fix Click Mouse Esquina Izquierda
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
		if( pCheckMouseOver(0, 0, 145, 145) )
		{
			pSetCursorFocus = false;
		}
	}
	//--

	float CY;
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);
	float RenderX; 

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	RenderImage(31602, X, Y, 22.0, 25.0);

	for(int i = 0 ; i < 5 ; i ++)
	{
		RenderX = (double) X + 22.0 + (i * 26.0);
		RenderImage(31603, RenderX, Y, 26.0, 25.0);
	}

	RenderImage(31604, RenderX, Y, 73.0, 20.0);
	
	//Mapa y Coordenadas
	if (World >= 82 && World <= 100)
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  (%d , %d)", pMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), X - 30, Y + 4, Cord, 190, 0, (LPINT)3, 0);
	pGLSwitch();
	EnableAlphaTest(0);
	//-- Config
	gInterface.DrawButtonRender(ButtonSettings, 146, 1, 0, 0);
	if (gInterface.IsWorkZone(ButtonSettings))
	{
		gInterface.DrawToolTip(146, Y + 50, "Config Helper");

		if (gInterface.Data[ButtonSettings].OnClick)
		{
			pDrawButton(31761, 146, 1.6, 18.0f, 13.3, 0, 26.9);
		}
		else
		{
			pDrawButton(31761, 146, 1.6, 18.0f, 13.3, 0, 13.6);
		}
	}
	else
	{
		pDrawButton(31761, 146, 1.0,18.0f, 13.3, 0, 0);
	}

	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		if( pCheckMouseOver(146 + 16, 0, ReturnX(TransForX(16)), ReturnY(TransForY(11))) )
		{
			pSetCursorFocus = true;
		}
		gInterface.DrawButtonRender(ButtonStart, 146 + 18, 1, 0, 0);
		//-- Play
		if (gInterface.IsWorkZone(ButtonStart))
		{
			gInterface.DrawToolTip(146 + 18, Y + 50,"Play Helper");

			if (gInterface.Data[ButtonStart].OnClick)
			{
				pDrawButton(31762, 146 + 18, 1.6, 18.0f, 13.3, 0, 26.9);
			}
			else
			{
				pDrawButton(31762, 146 + 18, 1.6, 18.0f, 13.3, 0, 13.6);
			}
		}
		else
		{
			pDrawButton(31762, 146 + 18, 1.0,18.0f, 13.3, 0, 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStop, 146 + 18, 1, 0, 0);

		if(offhelper == 1 && !gObjUser.InSafeZone)
		{
			gMuHelper.RunningOffHelper();
		}
		//-- Pause
		if (gInterface.IsWorkZone(ButtonStop))
		{
			gInterface.DrawToolTip(146 + 18, Y + 50,"Pause Helper");

			if (gInterface.Data[ButtonStop].OnClick)
			{
				pDrawButton(31763, 146 + 18, 1.6, 18.0f, 13.3, 0, 26.9);
			}
			else
			{
				pDrawButton(31763, 146 + 18, 1.6, 18.0f, 13.3, 0, 13.6);
			}
		}
		else
		{
			pDrawButton(31763, 146 + 18, 1.0, 18.0f, 13.3, 0, 0);
		}
	}
//=======================================================
	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
	pDrawButton(0x787A, 145 + 37.2, 0, 54, 18, 0, 0);

	if(pCheckMouseOver( 145 + 36.2, 2, 16, 12 ))
	{
		if(pCursorX >= 145 + 36.2)
		{
		pSetCursorFocus = true;
		}
		gInterface.DrawToolTip(145 + 36.2, Y + 50, "Camera 3D");
		if( *(BYTE*)0x8793386 )
		{
			pDrawButton(0x787B, 146 + 36.2, 2.6, 16, 12, 0, 0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				gInterface.SwitchCamera();
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			pSetBlend(true);
			glColor3f(1.0, 0.75, 0.42);
			pGLSwitchBlend();
			pDrawButton(0x787B, 146 + 36.2, 2.6, 16, 12, 0, 0);
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
	}
		else
		{
			pDrawButton(0x787B, 146 + 36.2, 2.0, 16, 12, 0, 0);
		}
	}
//=======================================================
	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
	if(pCheckMouseOver( 145 + 55.2, 2, 16, 12 ))
	{
		if(pCursorX >= 145 + 55.2)
		{
		pSetCursorFocus = true;
		}
		gInterface.DrawToolTip(145 + 55.2, Y + 50, "Camera 3D Restore");
		if( *(BYTE*)0x8793386 )
		{
			pDrawButton(0x787C, 146 + 55.2, 2.6, 16, 12, 0, 0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				gInterface.CameraInit();
			}
		}
		else
		{
			pSetBlend(true);
			glColor3f(1.0, 0.75, 0.42);
			pGLSwitchBlend();
			pDrawButton(0x787C, 146 + 55.2, 2.6, 16, 12, 0, 0);
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
	}
		else
		{
			pDrawButton(0x787C, 146 + 55.2, 2.0, 16, 12, 0, 0);
		}
	}
//=======================================================
	/*if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
	pDrawButton(30983, 146 + 37.2, 0.0, 36, 18, 0, 0);

		gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);

		if (gInterface.IsWorkZone(eMenu))
		{
			gInterface.DrawToolTip(146 + 37.2, 50, "Especial Menu");
			// ----
			if (gInterface.Data[eMenu].OnClick)
			{
				gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
			}
			else
			{
				gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
			}
		}
		else
		{
			gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
		}
	}*/
		if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
		{
			if (gProtect.m_MainInfo.CustomMenuType == 2)
			{
			pDrawButton(30983, 145 + 74.2, 0, 36, 18, 0, 0);

				if(pCheckMouseOver( 145 + 73.2, 2, 16, 12 ))
				{
					if(pCursorX >= 145 + 73.2)
					{
						pSetCursorFocus = true;
					}
					gInterface.DrawToolTip(145 + 73.2, Y + 50, "Especial Menu");
					if( *(BYTE*)0x8793386 )
					{
					pDrawButton(0x7906, 146 + 73.2, 2.6, 16, 12, 0, 0);

					if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
						{
							//gInterface.Data[eMenu_MAIN].OnShow = true;
						}
					}
					else
					{
						pSetBlend(true);
						glColor3f(1.0, 0.75, 0.42);
						pGLSwitchBlend();
						pDrawButton(0x7906, 146 + 73.2, 2.6, 16, 12, 0, 0);
						pGLSwitch();
						glColor3f(1.0, 1.0, 1.0);
						pSetBlend(false);
					}
				}
				else
				{
					pDrawButton(0x7906, 146 + 73.2, 2.0, 16, 12, 0, 0);
				}
			}
			else if (gProtect.m_MainInfo.CustomMenuType == 1)
			{
				if(pCheckMouseOver( 157, 16, 45, 23 ))
				{
					pSetCursorFocus = true;
				}
				if(pCheckMouseOver( 157, 16, 45, 23 ))
				{
					gInterface.DrawToolTip(165, Y + 50, "Especial Menu");
					if( *(BYTE*)0x8793386 )
					{
					RenderBitmap(0x7906, 164, 17.2, 56, 24, 0, 0, 0.8, 1, 0.1, 1, 0);
					if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
						{
							//gInterface.Data[eMenu_MAIN].OnShow = true;
						}
					}
					else
					{
						pSetBlend(true);
						glColor3f(1.0, 0.94, 0.44);
						pGLSwitchBlend();
						RenderBitmap(0x7906, 164, 17.2, 56, 24, 0, 0, 0.8, 1, 0.1, 1, 0);
						pGLSwitch();
						glColor3f(1.0, 1.0, 1.0);
						pSetBlend(false);
					}
				}
				else
				{
					RenderBitmap(0x7906, 164, 17, 56, 24, 0, 0, 0.8, 1, 0.1, 1, 0);
				}
			}
		}
	}
}
__declspec(naked) void MuHelperRemake2_01()  //<- ConfigHelper
{
	static DWORD Addr_JMP = 0x007D26DA;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                  ; |Arg6 = 0000000D
		PUSH W                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_02()  //<- PlayHelper
{
	static DWORD Addr_JMP = 0x007D2776;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f + 18.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_03()  //<- PauseHelper
{
	static DWORD Addr_JMP = 0x007D2821;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f + 18.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}

void OffHelper(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, h);

	if( gInterface.IsWorkZone(ButtonStartAttack) )
	{
		if( gInterface.Data[ButtonStartAttack].OnClick )
		{
			if(offhelper == 0)
			{
				offhelper = 1;
			}
			else
			{
				offhelper = 0;
			}
			gInterface.Data[ButtonStartAttack].OnClick = false;
		}
	}
	if(offhelper == 1)
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 0);
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 15);
	}
	gInterface.DrawFormat(eGold, x + 50 + 16, y + 12, 60, 1, "MuOffHelper");
}

void CMacroUIEx::Load()
{
		SetCompleteHook(0xE8, 0x007F76CD, &OffHelper);

		if(gProtect.m_MainInfo.MuHelperType == 0)
		{
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake2_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake2_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake2_03);
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderHelperFrame);
		}
		else if(gProtect.m_MainInfo.MuHelperType == 1)
		{
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_03);
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderFrame);
		SetCompleteHook(0xE9, 0x0080B8E0, &BarTime);
		}
}
