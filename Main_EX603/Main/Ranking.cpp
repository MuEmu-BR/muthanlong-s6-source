#include "stdafx.h"
#include "Ranking.h"
#include "Import.h"
#include "Defines.h"
#include "Interface.h"
#include "Util.h"
#include "RankingEx.h"
#include "CustomMap.h"
#include "Controller.h"
#include "PartySearch.h"
#include "Central.h"
#include "User.h"
#include "Map.h"
#include "SItemOption.h"
#include "WindowsStruct.h"


#if(RANKING_NEW == 1)

cRanking gRanking;

cRanking::cRanking()
{
	this->Active = true;
	this->Show = false;
	this->StartX = 0;
	this->StartY = 0;
	this->ClickTick = 0;
	this->Page = 1;
	this->TrangRanking = 1;
}

cRanking::~cRanking()
{
}

void cRanking::Bind()
{
#if(RANKING_NEW == 1)
	gInterface.BindObject(eMAIN_RANKING, 0x7A5A, 445, 364, 205, -1);
	gInterface.BindObject(eRANKINGALL, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGDW, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGDK, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGEF, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGMG, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGDL, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGSM, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGRF, 31461, 35, 14, -1, -1);  // 31461

	gInterface.BindObject(eRANKINGTOPNAP, 31461, 35, 14, -1, -1);  // 31461

	gInterface.BindObject(eRANKINGBLOOD, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGDEVIL, 31461, 35, 14, -1, -1);  // 31461
	gInterface.BindObject(eRANKINGCHAOS, 31461, 35, 14, -1, -1);  // 31461


#endif
}

void cRanking::RecvInfo(DGCharTop * lpMsg)
{
	for (int i = 0; i<MAXTOP; i++)
	{
		strncpy(this->RankingChar[i].Name, lpMsg->tp[i].Name, 11);
		this->RankingChar[i].Class = lpMsg->tp[i].Class;
		this->RankingChar[i].level = lpMsg->tp[i].level;
		this->RankingChar[i].Reset = lpMsg->tp[i].Reset;
		this->RankingChar[i].Relifes = lpMsg->tp[i].Relifes;
		this->RankingChar[i].Time = lpMsg->tp[i].Time;
		strncpy(this->RankingChar[i].Guild, lpMsg->tp[i].Guild, 9);
	}
}

void cRanking::RecvInfoDW(DGCharTopDW * lpMsg)
{
	for (int iDW = 0; iDW<MAXTOPDW; iDW++)
	{
		strncpy(this->RankingCharDW[iDW].Name, lpMsg->tp[iDW].Name, 11);
		this->RankingCharDW[iDW].Class = lpMsg->tp[iDW].Class;
		this->RankingCharDW[iDW].level = lpMsg->tp[iDW].level;
		this->RankingCharDW[iDW].Reset = lpMsg->tp[iDW].Reset;
		this->RankingCharDW[iDW].Relifes = lpMsg->tp[iDW].Relifes;
		this->RankingCharDW[iDW].Time = lpMsg->tp[iDW].Time;
		strncpy(this->RankingCharDW[iDW].Guild, lpMsg->tp[iDW].Guild, 9);
	}
}

void cRanking::RecvInfoDK(DGCharTopDK * lpMsg)
{
	for (int iDK = 0; iDK<MAXTOPDK; iDK++)
	{
		strncpy(this->RankingCharDK[iDK].Name, lpMsg->tp[iDK].Name, 11);
		this->RankingCharDK[iDK].Class = lpMsg->tp[iDK].Class;
		this->RankingCharDK[iDK].level = lpMsg->tp[iDK].level;
		this->RankingCharDK[iDK].Reset = lpMsg->tp[iDK].Reset;
		this->RankingCharDK[iDK].Relifes = lpMsg->tp[iDK].Relifes;
		this->RankingCharDK[iDK].Time = lpMsg->tp[iDK].Time;
		strncpy(this->RankingCharDK[iDK].Guild, lpMsg->tp[iDK].Guild, 9);
	}
}

void cRanking::RecvInfoEF(DGCharTopEF * lpMsg)
{
	for (int iEF = 0; iEF<MAXTOPEF; iEF++)
	{
		strncpy(this->RankingCharEF[iEF].Name, lpMsg->tp[iEF].Name, 11);
		this->RankingCharEF[iEF].Class = lpMsg->tp[iEF].Class;
		this->RankingCharEF[iEF].level = lpMsg->tp[iEF].level;
		this->RankingCharEF[iEF].Reset = lpMsg->tp[iEF].Reset;
		this->RankingCharEF[iEF].Relifes = lpMsg->tp[iEF].Relifes;
		this->RankingCharEF[iEF].Time = lpMsg->tp[iEF].Time;
		strncpy(this->RankingCharEF[iEF].Guild, lpMsg->tp[iEF].Guild, 9);
	}
}

void cRanking::RecvInfoMG(DGCharTopMG * lpMsg)
{
	for (int iMG = 0; iMG<MAXTOPMG; iMG++)
	{
		strncpy(this->RankingCharMG[iMG].Name, lpMsg->tp[iMG].Name, 11);
		this->RankingCharMG[iMG].Class = lpMsg->tp[iMG].Class;
		this->RankingCharMG[iMG].level = lpMsg->tp[iMG].level;
		this->RankingCharMG[iMG].Reset = lpMsg->tp[iMG].Reset;
		this->RankingCharMG[iMG].Relifes = lpMsg->tp[iMG].Relifes;
		this->RankingCharMG[iMG].Time = lpMsg->tp[iMG].Time;
		strncpy(this->RankingCharMG[iMG].Guild, lpMsg->tp[iMG].Guild, 9);
	}
}

void cRanking::RecvInfoDL(DGCharTopDL * lpMsg)
{
	for (int iDL = 0; iDL<MAXTOPDL; iDL++)
	{
		strncpy(this->RankingCharDL[iDL].Name, lpMsg->tp[iDL].Name, 11);
		this->RankingCharDL[iDL].Class = lpMsg->tp[iDL].Class;
		this->RankingCharDL[iDL].level = lpMsg->tp[iDL].level;
		this->RankingCharDL[iDL].Reset = lpMsg->tp[iDL].Reset;
		this->RankingCharDL[iDL].Relifes = lpMsg->tp[iDL].Relifes;
		this->RankingCharDL[iDL].Time = lpMsg->tp[iDL].Time;
		strncpy(this->RankingCharDL[iDL].Guild, lpMsg->tp[iDL].Guild, 9);
	}
}

void cRanking::RecvInfoSM(DGCharTopSM * lpMsg)
{
	for (int iSM = 0; iSM<MAXTOPSM; iSM++)
	{
		strncpy(this->RankingCharSM[iSM].Name, lpMsg->tp[iSM].Name, 11);
		this->RankingCharSM[iSM].Class = lpMsg->tp[iSM].Class;
		this->RankingCharSM[iSM].level = lpMsg->tp[iSM].level;
		this->RankingCharSM[iSM].Reset = lpMsg->tp[iSM].Reset;
		this->RankingCharSM[iSM].Relifes = lpMsg->tp[iSM].Relifes;
		this->RankingCharSM[iSM].Time = lpMsg->tp[iSM].Time;
		strncpy(this->RankingCharSM[iSM].Guild, lpMsg->tp[iSM].Guild, 9);
	}
}

void cRanking::RecvInfoRF(DGCharTopRF * lpMsg)
{
	for (int iRF = 0; iRF<MAXTOPRF; iRF++)
	{
		strncpy(this->RankingCharRF[iRF].Name, lpMsg->tp[iRF].Name, 11);
		this->RankingCharRF[iRF].Class = lpMsg->tp[iRF].Class;
		this->RankingCharRF[iRF].level = lpMsg->tp[iRF].level;
		this->RankingCharRF[iRF].Reset = lpMsg->tp[iRF].Reset;
		this->RankingCharRF[iRF].Relifes = lpMsg->tp[iRF].Relifes;
		this->RankingCharRF[iRF].Time = lpMsg->tp[iRF].Time;
		strncpy(this->RankingCharRF[iRF].Guild, lpMsg->tp[iRF].Guild, 9);
	}
}

void cRanking::RecvInfoNAP(DGCharTopNAP * lpMsg)
{
	for (int iNAP = 0; iNAP<MAXTOPNAP; iNAP++)
	{
		strncpy(this->RankingCharNAP[iNAP].Name, lpMsg->tp[iNAP].Name, 11);
		this->RankingCharNAP[iNAP].TopNap = lpMsg->tp[iNAP].TopNap;
	}
}

void cRanking::RecvInfoBLOOD(DGCharTopBLOOD * lpMsg)
{
	for (int iBLOOD = 0; iBLOOD<MAXTOPBLOOD; iBLOOD++)
	{
		strncpy(this->RankingCharBLOOD[iBLOOD].Name, lpMsg->tp[iBLOOD].Name, 11);
		this->RankingCharBLOOD[iBLOOD].TopBLOOD = lpMsg->tp[iBLOOD].TopBLOOD;
	}
}

void cRanking::RecvInfoDEVIL(DGCharTopDEVIL * lpMsg)
{
	for (int iDEVIL = 0; iDEVIL<MAXTOPDEVIL; iDEVIL++)
	{
		strncpy(this->RankingCharDEVIL[iDEVIL].Name, lpMsg->tp[iDEVIL].Name, 11);
		this->RankingCharDEVIL[iDEVIL].TopDEVIL = lpMsg->tp[iDEVIL].TopDEVIL;
	}
}

void cRanking::RecvInfoCHAOS(DGCharTopCHAOS * lpMsg)
{
	for (int iCHAOS = 0; iCHAOS<MAXTOPCHAOS; iCHAOS++)
	{
		strncpy(this->RankingCharCHAOS[iCHAOS].Name, lpMsg->tp[iCHAOS].Name, 11);
		this->RankingCharCHAOS[iCHAOS].TopCHAOS = lpMsg->tp[iCHAOS].TopCHAOS;
	}
}

void cRanking::ClickRanking(DWORD ClickMouse)
{
	if (!this->Active) return;

	if (!this->Show) return;


	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.IsWorkZone(eRANKINGALL))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 1)

			ClickTick = GetTickCount();
	}
	if (gInterface.IsWorkZone(eRANKINGDW))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 2)
		ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x22, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	if (gInterface.IsWorkZone(eRANKINGDK))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 3)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x23, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	if (gInterface.IsWorkZone(eRANKINGEF))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 4)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x24, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	if (gInterface.IsWorkZone(eRANKINGMG))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 5)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x25, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	if (gInterface.IsWorkZone(eRANKINGDL))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 6)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x26, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	if (gInterface.IsWorkZone(eRANKINGSM))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 7)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x27, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	//=========================================================
	if (gInterface.IsWorkZone(eRANKINGRF))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 8)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x28, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	//=========================================================
	if (gInterface.IsWorkZone(eRANKINGTOPNAP))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 9)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x29, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	//=========================================================
	if (gInterface.IsWorkZone(eRANKINGBLOOD))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 10)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x30, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	//=========================================================
	if (gInterface.IsWorkZone(eRANKINGDEVIL))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 11)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x31, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	//=========================================================
	if (gInterface.IsWorkZone(eRANKINGCHAOS))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (TrangRanking = 12)
			ClickTick = GetTickCount();
		SEND_GS_REQ pRequest;
		pRequest.h.set(0xFD, 0x32, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
	//=========================================================


}

void cRanking::Draw()
{
	if (!this->Active) return;

	if (!this->Show) return;

	float MainWidth = 445.0;
	float MainHeight = 364.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--
	gInterface.Data[eMAIN_RANKING].MaxX = StartX + MainWidth;
	gInterface.Data[eMAIN_RANKING].MaxY = StartY + MainHeight;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight -135, 0, 0);

	//=======
	gInterface.DrawGUI(eRANKINGALL, StartX + 5, StartY + 30);
	if (CheckButtonPressed(StartX + 5, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 5, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 5, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 20, StartY + 33, 210, 1, "All");
	if (TrangRanking == 1)
	{
		gInterface.DrawFormat(eRed, StartX + 20, StartY + 33, 210, 1, "All");
	}
	//=======
	gInterface.DrawGUI(eRANKINGDW, StartX + 50, StartY + 30);
	if (CheckButtonPressed(StartX + 50, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 50, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 50, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 65, StartY + 33, 210, 1, "DW");
	if (TrangRanking == 2)
	{
		gInterface.DrawFormat(eRed, StartX + 65, StartY + 33, 210, 1, "DW");
	}
	//=======
	gInterface.DrawGUI(eRANKINGDK, StartX + 95, StartY + 30);
	if (CheckButtonPressed(StartX + 95, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 95, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 95, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 110, StartY + 33, 210, 1, "DK");
	if (TrangRanking == 3)
	{
		gInterface.DrawFormat(eRed, StartX + 110, StartY + 33, 210, 1, "DK");
	}
	//=======
	gInterface.DrawGUI(eRANKINGEF, StartX + 140, StartY + 30);
	if (CheckButtonPressed(StartX + 140, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 140, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 140, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 155, StartY + 33, 210, 1, "EF");
	if (TrangRanking == 4)
	{
		gInterface.DrawFormat(eRed, StartX + 155, StartY + 33, 210, 1, "EF");
	}
	//=======
	gInterface.DrawGUI(eRANKINGMG, StartX + 185, StartY + 30);
	if (CheckButtonPressed(StartX + 185, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 185, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 185, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 200, StartY + 33, 210, 1, "MG");
	if (TrangRanking == 5)
	{
		gInterface.DrawFormat(eRed, StartX + 200, StartY + 33, 210, 1, "MG");
	}
	//=======
	gInterface.DrawGUI(eRANKINGDL, StartX + 230, StartY + 30);
	if (CheckButtonPressed(StartX + 230, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 230, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 230, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 245, StartY + 33, 210, 1, "DL");
	if (TrangRanking == 6)
	{
		gInterface.DrawFormat(eRed, StartX + 245, StartY + 33, 210, 1, "DL");
	}
	//=======
	gInterface.DrawGUI(eRANKINGSM, StartX + 275, StartY + 30);
	if (CheckButtonPressed(StartX + 275, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 275, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 275, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 290, StartY + 33, 210, 1, "SM");
	if (TrangRanking == 7)
	{
		gInterface.DrawFormat(eRed, StartX + 290, StartY + 33, 210, 1, "SM");
	}
	//=======
	gInterface.DrawGUI(eRANKINGRF, StartX + 320, StartY + 30);
	if (CheckButtonPressed(StartX + 320, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 320, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 320, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 335, StartY + 33, 210, 1, "RF");
	if (TrangRanking == 8)
	{
		gInterface.DrawFormat(eRed, StartX + 335, StartY + 33, 210, 1, "RF");
	}
	//=======
	gInterface.DrawGUI(eRANKINGTOPNAP, StartX + 365, StartY + 30);
	if (CheckButtonPressed(StartX + 365, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 365, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 365, StartY + 30, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 370, StartY + 33, 210, 1, "Top Nạp");
	if (TrangRanking == 9)
	{
		gInterface.DrawFormat(eRed, StartX + 370, StartY + 33, 210, 1, "Top Nạp");
	}
	//
	//
	//
	//
	//=======
	gInterface.DrawGUI(eRANKINGBLOOD, StartX + 5, StartY + 50);
	if (CheckButtonPressed(StartX + 5, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 5, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 5, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 20, StartY + 53, 210, 1, "Blood");
	if (TrangRanking == 10)
	{
		gInterface.DrawFormat(eRed, StartX + 20, StartY + 53, 210, 1, "Blood");
	}
	//=======
	gInterface.DrawGUI(eRANKINGDEVIL, StartX + 50, StartY + 50);
	if (CheckButtonPressed(StartX + 50, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 50, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 50, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 65, StartY + 53, 210, 1, "Devil");
	if (TrangRanking == 11)
	{
		gInterface.DrawFormat(eRed, StartX + 65, StartY + 53, 210, 1, "Devil");
	}
	//=======
	gInterface.DrawGUI(eRANKINGCHAOS, StartX + 95, StartY + 50);
	if (CheckButtonPressed(StartX + 95, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 95, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 95, StartY + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + 110, StartY + 53, 210, 1, "Chaos");
	if (TrangRanking == 12)
	{
		gInterface.DrawFormat(eRed, StartX + 110, StartY + 53, 210, 1, "Chaos");
	}
	//=======


	//=======
	int TitleX = StartX + 20;
	int TitleY = StartY + 70;

	int InfoY = StartY + 85;
	int c = 0;
	time_t mTime;
	tm* lpTime = NULL;
	//=======
	switch (TrangRanking)
	{
	case 1:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Tất Cả Chủng Tộc");

		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingChar[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingChar[up].Name, sizeof(this->RankingChar[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingChar[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingChar[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingChar[up].Reset, this->RankingChar[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingChar[up].Guild, sizeof(this->RankingChar[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingChar[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);

			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
//========================================================================================================================
	case 2:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Phù Thủy");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharDW[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharDW[up].Name, sizeof(this->RankingCharDW[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharDW[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharDW[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharDW[up].Reset, this->RankingCharDW[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharDW[up].Guild, sizeof(this->RankingCharDW[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharDW[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
		//========================================================================================================================
	case 3:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Chiến Binh");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharDK[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharDK[up].Name, sizeof(this->RankingCharDK[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharDK[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharDK[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharDK[up].Reset, this->RankingCharDK[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharDK[up].Guild, sizeof(this->RankingCharDK[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharDK[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 4:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Tiên Nữ");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharEF[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharEF[up].Name, sizeof(this->RankingCharEF[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharEF[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharEF[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharEF[up].Reset, this->RankingCharEF[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharEF[up].Guild, sizeof(this->RankingCharEF[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharEF[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 5:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Đấu Sĩ");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharMG[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharMG[up].Name, sizeof(this->RankingCharMG[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharMG[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharMG[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharMG[up].Reset, this->RankingCharMG[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharMG[up].Guild, sizeof(this->RankingCharMG[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharMG[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 6:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Chúa Tể");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharDL[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharDL[up].Name, sizeof(this->RankingCharDL[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharDL[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharDL[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharDL[up].Reset, this->RankingCharDL[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharDL[up].Guild, sizeof(this->RankingCharDL[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharDL[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 7:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Thuật Sĩ");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharSM[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharSM[up].Name, sizeof(this->RankingCharSM[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharSM[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharSM[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharSM[up].Reset, this->RankingCharSM[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharSM[up].Guild, sizeof(this->RankingCharSM[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharSM[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 8:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Chủng Tộc Thiết Binh");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		gCItemSetOption.ItemTooltipS15(TitleX - 15, TitleY, 430, 12, 0.0, 0);

		gInterface.DrawFormat(eTextShop, TitleX - 12, TitleY, 100, 1, "(N)");

		TitleX += 10;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Class");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Level");

		TitleX += 40;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Reset/Rl");

		TitleX += 55;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Guild");

		TitleX += 70;
		gInterface.DrawFormat(eTextShop, TitleX, TitleY, 100, 1, "Thời gian Resets cuối");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharRF[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eWhite;
			}
			else
			{
				Color = eShinyGreen;
			}

			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", up + 1);

			InfoX += 20;
			char NameID[11];
			memcpy(NameID, this->RankingCharRF[up].Name, sizeof(this->RankingCharRF[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 80;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, CharacterCode(this->RankingCharRF[up].Class));

			InfoX += 70;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharRF[up].level);

			InfoX += 40;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d/(%d)", this->RankingCharRF[up].Reset, this->RankingCharRF[up].Relifes);

			InfoX += 55;
			char GuildID[9];
			memcpy(GuildID, this->RankingCharRF[up].Guild, sizeof(this->RankingCharRF[up].Guild));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, GuildID);

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			mTime = this->RankingCharRF[up].Time;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;
				mMonth = 1 + lpTime->tm_mon;
				mDays = lpTime->tm_mday;
				hours = lpTime->tm_hour;
				minutes = lpTime->tm_min;
				seconds = lpTime->tm_sec;
			}
			InfoX += 65;
			gInterface.DrawFormat(eSocket, InfoX, InfoY, 100, 1, "%02d:%02d:%02d (%02d/%02d/%d)", hours, minutes, seconds, mDays, mMonth, mYear);
			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 9:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Top Triệu Phú");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		TitleX += 100;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "(N)");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Tổng Nạp");
		
		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharNAP[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eSocket;
			}
			else
			{
				Color = eBlue;
			}

			TitleX += 100;
			gInterface.DrawFormat(Color, InfoX + 110, InfoY, 100, 1, "%d", up + 1);

			InfoX += 180;
			char NameID[11];
			memcpy(NameID, this->RankingCharNAP[up].Name, sizeof(this->RankingCharNAP[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 95;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharNAP[up].TopNap);

			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 10:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Top Huyết Lâu");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		TitleX += 100;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "(N)");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Điểm");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharBLOOD[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eSocket;
			}
			else
			{
				Color = eBlue;
			}

			TitleX += 100;
			gInterface.DrawFormat(Color, InfoX + 110, InfoY, 100, 1, "%d", up + 1);

			InfoX += 180;
			char NameID[11];
			memcpy(NameID, this->RankingCharBLOOD[up].Name, sizeof(this->RankingCharBLOOD[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 95;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharBLOOD[up].TopBLOOD);

			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 11:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Top Quảng Trường Quỷ");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		TitleX += 100;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "(N)");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Điểm");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharDEVIL[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eSocket;
			}
			else
			{
				Color = eBlue;
			}

			TitleX += 100;
			gInterface.DrawFormat(Color, InfoX + 110, InfoY, 100, 1, "%d", up + 1);

			InfoX += 180;
			char NameID[11];
			memcpy(NameID, this->RankingCharDEVIL[up].Name, sizeof(this->RankingCharDEVIL[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 95;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharDEVIL[up].TopDEVIL);

			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;
	case 12:
		gInterface.DrawFormat(eBlue, (int)StartX + 130, (int)StartY + 10, 210, 3, "Top Hỗn Nguyên Lầu");
		pDrawGUI(0x7EC5, StartX + 410, StartY + 5, 36, 29);

		TitleX += 100;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "(N)");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Name");

		TitleX += 80;
		gInterface.DrawFormat(eYellow, TitleX, TitleY, 100, 1, "Điểm");

		for (int i = 0; i < 10; i++)
		{
			int InfoX = StartX + 10;
			int up = i + ((this->Page - 1) * 10);

			if (this->RankingCharCHAOS[up].Name[0] == NULL) continue;

			DWORD Color;

			if (c == 0)
			{
				Color = eSocket;
			}
			else
			{
				Color = eBlue;
			}

			TitleX += 100;
			gInterface.DrawFormat(Color, InfoX + 110, InfoY, 100, 1, "%d", up + 1);

			InfoX += 180;
			char NameID[11];
			memcpy(NameID, this->RankingCharCHAOS[up].Name, sizeof(this->RankingCharCHAOS[up].Name));
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, NameID);

			InfoX += 95;
			gInterface.DrawFormat(Color, InfoX, InfoY, 100, 1, "%d", this->RankingCharCHAOS[up].TopCHAOS);

			InfoY += 14; // 12
			c++;
			if (c == 2)c = 0;
		}
		break;

	default:
		break;
	}

	// Nut Close
	DWORD Delay = (GetTickCount() - this->ClickTime);
	if (gInterface.IsWorkZone2(StartX + 410, StartY + 5, StartX + 446, StartY + 41))
	{
		if (gController.wMouse == WM_LBUTTONDOWN && Delay > 300)
		{
			this->ClickTime = GetTickCount();
			gRanking.Show = false;
			pSetCursorFocus = false;
		}
		pDrawColorButton(0x7EC5, StartX + 410, StartY + 5, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
	}

}

#endif