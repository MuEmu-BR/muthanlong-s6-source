#include "stdafx.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Util.h"
#include "Message.h"
#include "User.h"
#include "Path.h"
#include "ServerInfo.h"
#include "MemScript.h"
#include "CustomRanking.h"
#include "Notice.h"

#if(RANKINGGOC == 1)

CCustomRanking gCustomRanking;

void CCustomRanking::Load(char* path)
{

	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	for(int n=0;n < MAX_RANK;n++)
	{
		this->r_Data[n];
	}

	this->m_count = 0;

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while(true)
			{
				if(section == 0)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int index = lpMemScript->GetNumber();

					strcpy_s(this->r_Data[index].Name,lpMemScript->GetAsString());

					strcpy_s(this->r_Data[index].Col1,lpMemScript->GetAsString());

					strcpy_s(this->r_Data[index].Col2,lpMemScript->GetAsString());

					this->m_count++;
				}
			}
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;

	//LogAdd(LOG_BLUE, "[ServerInfo] CustomRanking Info loaded successfully");
}

void CCustomRanking::GCReqRankingCount(int Index,PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg)
{

#if (GAMESERVER_CLIENTE_UPDATE >= 6)

	if(gServerInfo.m_CustomRankingSwitch == 0)
	{
		return;
	}

	PMSG_CUSTOM_RANKING_COUNT_SEND pMsg;

    pMsg.header.set(0xF3,0xE7, sizeof(pMsg)); 

	pMsg.count = (this->m_count > MAX_RANK) ? MAX_RANK : this->m_count;

	DataSend(Index, (LPBYTE)&pMsg, pMsg.header.size);

#endif

}

void CCustomRanking::GCReqRanking(int Index,PMSG_CUSTOM_RANKING_RECV* lpMsg)
{

#if (GAMESERVER_CLIENTE_UPDATE >= 6)

	if(gServerInfo.m_CustomRankingSwitch == 0)
	{
		return;
	}

	if(gObjIsConnected(Index) == false)
	{
		return;
	}

	if (this->m_count <= 0 )
	{
		return;
	}

	if (lpMsg->type < 0 || lpMsg->type >= this->m_count)
	{
		return;
	}

	if (this->m_count == 0)
	{
		return;
	}

	SDHP_CUSTOM_RANKING_SEND pMsg;

    pMsg.header.set(0xF4, sizeof(pMsg)); 

	pMsg.index = Index;

	pMsg.type = lpMsg->type;

	gDataServerConnection.DataSend((BYTE*)&pMsg,pMsg.header.size);

#endif
}

void CCustomRanking::GDCustomRankingRecv(SDHP_CUSTOM_RANKING_RECV* lpMsg)
{
#if (GAMESERVER_CLIENTE_UPDATE >= 6)

	if( lpMsg == NULL )
	{
		return;
	}

	BYTE send[4096];

	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3,0xE6,0);

	int size = sizeof(pMsg);

	memcpy(pMsg.rankname, this->r_Data[lpMsg->type].Name, sizeof(pMsg.rankname));
	memcpy(pMsg.col1, this->r_Data[lpMsg->type].Col1, sizeof(pMsg.col1));
	memcpy(pMsg.col2, this->r_Data[lpMsg->type].Col2, sizeof(pMsg.col2));

	pMsg.count = 0;

	CUSTOM_RANKING_DATA info;

	for(int n=0;n < lpMsg->count;n++)
	{
		CUSTOM_RANKING_DATA* lpInfo = (CUSTOM_RANKING_DATA*)(((BYTE*)lpMsg)+sizeof(SDHP_CUSTOM_RANKING_RECV)+(sizeof(CUSTOM_RANKING_DATA)*n));
		memcpy(info.szName, lpInfo->szName, sizeof(info.szName));
	    info.valor = lpInfo->valor;
		pMsg.count++;

		memcpy(&send[size],&info,sizeof(info));
		size += sizeof(info);
	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send,&pMsg,sizeof(pMsg));

	DataSend(lpMsg->index,send,size);

#endif
}
#endif

cRanking gRanking;

void cRanking::SendDS()
{
	BYTE send[4096];
	GDTop pMsg;
	pMsg.h.set(0xD9, 0x17, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDS(DGCharTop *Recv)
{
	for (int i = 0; i<MAXTOP; i++)
	{
		strncpy(this->RankingChar[i].Name, Recv->tp[i].Name, 11);
		this->RankingChar[i].Class = Recv->tp[i].Class;
		this->RankingChar[i].level = Recv->tp[i].level;
		this->RankingChar[i].Reset = Recv->tp[i].Reset;
		this->RankingChar[i].Relifes = Recv->tp[i].Relifes;
		this->RankingChar[i].Time = Recv->tp[i].Time;
		strncpy(this->RankingChar[i].Guild, Recv->tp[i].Guild, 9);
	}
}
void cRanking::SendUser(LPOBJ lpObj)
{
	DGCharTop2	sClient;
	sClient.h.set(0xFE, sizeof(sClient));

	for (int i = 0; i<MAXTOP; i++)
	{
		strncpy(sClient.tp[i].Name, this->RankingChar[i].Name, 11);
		sClient.tp[i].Class = this->RankingChar[i].Class;
		sClient.tp[i].level = this->RankingChar[i].level;
		sClient.tp[i].Reset = this->RankingChar[i].Reset;
		sClient.tp[i].Relifes = this->RankingChar[i].Relifes;
		sClient.tp[i].Time = this->RankingChar[i].Time;
		strncpy(sClient.tp[i].Guild, this->RankingChar[i].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSDW()
{
	BYTE send[4096];
	GDTopDW pMsg;
	pMsg.h.set(0xD9, 0x18, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSDW(DGCharTopDW *Recv)
{
	for (int iDW = 0; iDW<MAXTOPDW; iDW++)
	{
		strncpy(this->RankingCharDW[iDW].Name, Recv->tp[iDW].Name, 11);
		this->RankingCharDW[iDW].Class = Recv->tp[iDW].Class;
		this->RankingCharDW[iDW].level = Recv->tp[iDW].level;
		this->RankingCharDW[iDW].Reset = Recv->tp[iDW].Reset;
		this->RankingCharDW[iDW].Relifes = Recv->tp[iDW].Relifes;
		this->RankingCharDW[iDW].Time = Recv->tp[iDW].Time;
		strncpy(this->RankingCharDW[iDW].Guild, Recv->tp[iDW].Guild, 9);
	}
}
void cRanking::SendUserDW(LPOBJ lpObj)
{
	DGCharTop2DW	sClient;
	sClient.h.set(0x50, sizeof(sClient));
	for (int iDW = 0; iDW<MAXTOPDW; iDW++)
	{
		strncpy(sClient.tp[iDW].Name, this->RankingCharDW[iDW].Name, 11);
		sClient.tp[iDW].Class = this->RankingCharDW[iDW].Class;
		sClient.tp[iDW].level = this->RankingCharDW[iDW].level;
		sClient.tp[iDW].Reset = this->RankingCharDW[iDW].Reset;
		sClient.tp[iDW].Relifes = this->RankingCharDW[iDW].Relifes;
		sClient.tp[iDW].Time = this->RankingCharDW[iDW].Time;
		strncpy(sClient.tp[iDW].Guild, this->RankingCharDW[iDW].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSDK()
{
	BYTE send[4096];
	GDTopDK pMsg;
	pMsg.h.set(0xD9, 0x19, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSDK(DGCharTopDK *Recv)
{
	for (int iDK = 0; iDK<MAXTOPDK; iDK++)
	{
		strncpy(this->RankingCharDK[iDK].Name, Recv->tp[iDK].Name, 11);
		this->RankingCharDK[iDK].Class = Recv->tp[iDK].Class;
		this->RankingCharDK[iDK].level = Recv->tp[iDK].level;
		this->RankingCharDK[iDK].Reset = Recv->tp[iDK].Reset;
		this->RankingCharDK[iDK].Relifes = Recv->tp[iDK].Relifes;
		this->RankingCharDK[iDK].Time = Recv->tp[iDK].Time;
		strncpy(this->RankingCharDK[iDK].Guild, Recv->tp[iDK].Guild, 9);
	}
}
void cRanking::SendUserDK(LPOBJ lpObj)
{
	DGCharTop2DK	sClient;
	sClient.h.set(0x51, sizeof(sClient));
	for (int iDK = 0; iDK<MAXTOPDK; iDK++)
	{
		strncpy(sClient.tp[iDK].Name, this->RankingCharDK[iDK].Name, 11);
		sClient.tp[iDK].Class = this->RankingCharDK[iDK].Class;
		sClient.tp[iDK].level = this->RankingCharDK[iDK].level;
		sClient.tp[iDK].Reset = this->RankingCharDK[iDK].Reset;
		sClient.tp[iDK].Relifes = this->RankingCharDK[iDK].Relifes;
		sClient.tp[iDK].Time = this->RankingCharDK[iDK].Time;
		strncpy(sClient.tp[iDK].Guild, this->RankingCharDK[iDK].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSEF()
{
	BYTE send[4096];
	GDTopEF pMsg;
	pMsg.h.set(0xD9, 0x20, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSEF(DGCharTopEF *Recv)
{
	for (int iEF = 0; iEF<MAXTOPEF; iEF++)
	{
		strncpy(this->RankingCharEF[iEF].Name, Recv->tp[iEF].Name, 11);
		this->RankingCharEF[iEF].Class = Recv->tp[iEF].Class;
		this->RankingCharEF[iEF].level = Recv->tp[iEF].level;
		this->RankingCharEF[iEF].Reset = Recv->tp[iEF].Reset;
		this->RankingCharEF[iEF].Relifes = Recv->tp[iEF].Relifes;
		this->RankingCharEF[iEF].Time = Recv->tp[iEF].Time;
		strncpy(this->RankingCharEF[iEF].Guild, Recv->tp[iEF].Guild, 9);
	}
}
void cRanking::SendUserEF(LPOBJ lpObj)
{
	DGCharTop2EF	sClient;
	sClient.h.set(0x52, sizeof(sClient));
	for (int iEF = 0; iEF<MAXTOPEF; iEF++)
	{
		strncpy(sClient.tp[iEF].Name, this->RankingCharEF[iEF].Name, 11);
		sClient.tp[iEF].Class = this->RankingCharEF[iEF].Class;
		sClient.tp[iEF].level = this->RankingCharEF[iEF].level;
		sClient.tp[iEF].Reset = this->RankingCharEF[iEF].Reset;
		sClient.tp[iEF].Relifes = this->RankingCharEF[iEF].Relifes;
		sClient.tp[iEF].Time = this->RankingCharEF[iEF].Time;
		strncpy(sClient.tp[iEF].Guild, this->RankingCharEF[iEF].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSMG()
{
	BYTE send[4096];
	GDTopMG pMsg;
	pMsg.h.set(0xD9, 0x21, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSMG(DGCharTopMG *Recv)
{
	for (int iMG = 0; iMG<MAXTOPMG; iMG++)
	{
		strncpy(this->RankingCharMG[iMG].Name, Recv->tp[iMG].Name, 11);
		this->RankingCharMG[iMG].Class = Recv->tp[iMG].Class;
		this->RankingCharMG[iMG].level = Recv->tp[iMG].level;
		this->RankingCharMG[iMG].Reset = Recv->tp[iMG].Reset;
		this->RankingCharMG[iMG].Relifes = Recv->tp[iMG].Relifes;
		this->RankingCharMG[iMG].Time = Recv->tp[iMG].Time;
		strncpy(this->RankingCharMG[iMG].Guild, Recv->tp[iMG].Guild, 9);
	}
}
void cRanking::SendUserMG(LPOBJ lpObj)
{
	DGCharTop2MG	sClient;
	sClient.h.set(0x53, sizeof(sClient));
	for (int iMG = 0; iMG<MAXTOPMG; iMG++)
	{
		strncpy(sClient.tp[iMG].Name, this->RankingCharMG[iMG].Name, 11);
		sClient.tp[iMG].Class = this->RankingCharMG[iMG].Class;
		sClient.tp[iMG].level = this->RankingCharMG[iMG].level;
		sClient.tp[iMG].Reset = this->RankingCharMG[iMG].Reset;
		sClient.tp[iMG].Relifes = this->RankingCharMG[iMG].Relifes;
		sClient.tp[iMG].Time = this->RankingCharMG[iMG].Time;
		strncpy(sClient.tp[iMG].Guild, this->RankingCharMG[iMG].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSDL()
{
	BYTE send[4096];
	GDTopDL pMsg;
	pMsg.h.set(0xD9, 0x22, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSDL(DGCharTopDL *Recv)
{
	for (int iDL = 0; iDL<MAXTOPDL; iDL++)
	{
		strncpy(this->RankingCharDL[iDL].Name, Recv->tp[iDL].Name, 11);
		this->RankingCharDL[iDL].Class = Recv->tp[iDL].Class;
		this->RankingCharDL[iDL].level = Recv->tp[iDL].level;
		this->RankingCharDL[iDL].Reset = Recv->tp[iDL].Reset;
		this->RankingCharDL[iDL].Relifes = Recv->tp[iDL].Relifes;
		this->RankingCharDL[iDL].Time = Recv->tp[iDL].Time;
		strncpy(this->RankingCharDL[iDL].Guild, Recv->tp[iDL].Guild, 9);
	}
}
void cRanking::SendUserDL(LPOBJ lpObj)
{
	DGCharTop2DL	sClient;
	sClient.h.set(0x55, sizeof(sClient));
	for (int iDL = 0; iDL<MAXTOPDL; iDL++)
	{
		strncpy(sClient.tp[iDL].Name, this->RankingCharDL[iDL].Name, 11);
		sClient.tp[iDL].Class = this->RankingCharDL[iDL].Class;
		sClient.tp[iDL].level = this->RankingCharDL[iDL].level;
		sClient.tp[iDL].Reset = this->RankingCharDL[iDL].Reset;
		sClient.tp[iDL].Relifes = this->RankingCharDL[iDL].Relifes;
		sClient.tp[iDL].Time = this->RankingCharDL[iDL].Time;
		strncpy(sClient.tp[iDL].Guild, this->RankingCharDL[iDL].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSSM()
{
	BYTE send[4096];
	GDTopSM pMsg;
	pMsg.h.set(0xD9, 0x23, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSSM(DGCharTopSM *Recv)
{
	for (int iSM = 0; iSM<MAXTOPSM; iSM++)
	{
		strncpy(this->RankingCharSM[iSM].Name, Recv->tp[iSM].Name, 11);
		this->RankingCharSM[iSM].Class = Recv->tp[iSM].Class;
		this->RankingCharSM[iSM].level = Recv->tp[iSM].level;
		this->RankingCharSM[iSM].Reset = Recv->tp[iSM].Reset;
		this->RankingCharSM[iSM].Relifes = Recv->tp[iSM].Relifes;
		this->RankingCharSM[iSM].Time = Recv->tp[iSM].Time;
		strncpy(this->RankingCharSM[iSM].Guild, Recv->tp[iSM].Guild, 9);
	}
}
void cRanking::SendUserSM(LPOBJ lpObj)
{
	DGCharTop2SM	sClient;
	sClient.h.set(0x56, sizeof(sClient));
	for (int iSM = 0; iSM<MAXTOPSM; iSM++)
	{
		strncpy(sClient.tp[iSM].Name, this->RankingCharSM[iSM].Name, 11);
		sClient.tp[iSM].Class = this->RankingCharSM[iSM].Class;
		sClient.tp[iSM].level = this->RankingCharSM[iSM].level;
		sClient.tp[iSM].Reset = this->RankingCharSM[iSM].Reset;
		sClient.tp[iSM].Relifes = this->RankingCharSM[iSM].Relifes;
		sClient.tp[iSM].Time = this->RankingCharSM[iSM].Time;
		strncpy(sClient.tp[iSM].Guild, this->RankingCharSM[iSM].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSRF()
{
	BYTE send[4096];
	GDTopRF pMsg;
	pMsg.h.set(0xD9, 0x24, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSRF(DGCharTopRF *Recv)
{
	for (int iRF = 0; iRF<MAXTOPRF; iRF++)
	{
		strncpy(this->RankingCharRF[iRF].Name, Recv->tp[iRF].Name, 11);
		this->RankingCharRF[iRF].Class = Recv->tp[iRF].Class;
		this->RankingCharRF[iRF].level = Recv->tp[iRF].level;
		this->RankingCharRF[iRF].Reset = Recv->tp[iRF].Reset;
		this->RankingCharRF[iRF].Relifes = Recv->tp[iRF].Relifes;
		this->RankingCharRF[iRF].Time = Recv->tp[iRF].Time;
		strncpy(this->RankingCharRF[iRF].Guild, Recv->tp[iRF].Guild, 9);
	}
}
void cRanking::SendUserRF(LPOBJ lpObj)
{
	DGCharTop2RF	sClient;
	sClient.h.set(0x57, sizeof(sClient));
	for (int iRF = 0; iRF<MAXTOPRF; iRF++)
	{
		strncpy(sClient.tp[iRF].Name, this->RankingCharRF[iRF].Name, 11);
		sClient.tp[iRF].Class = this->RankingCharRF[iRF].Class;
		sClient.tp[iRF].level = this->RankingCharRF[iRF].level;
		sClient.tp[iRF].Reset = this->RankingCharRF[iRF].Reset;
		sClient.tp[iRF].Relifes = this->RankingCharRF[iRF].Relifes;
		sClient.tp[iRF].Time = this->RankingCharRF[iRF].Time;
		strncpy(sClient.tp[iRF].Guild, this->RankingCharRF[iRF].Guild, 9);
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSNAP()
{
	BYTE send[4096];
	GDTopNAP pMsg;
	pMsg.h.set(0xD9, 0x25, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSNAP(DGCharTopNAP *Recv)
{
	for (int iNAP = 0; iNAP<MAXTOPNAP; iNAP++)
	{
		strncpy(this->RankingCharNAP[iNAP].Name, Recv->tp[iNAP].Name, 11);
		this->RankingCharNAP[iNAP].TopNap = Recv->tp[iNAP].TopNap;
	}
}
void cRanking::SendUserNAP(LPOBJ lpObj)
{
	DGCharTop2NAP	sClient;
	sClient.h.set(0x58, sizeof(sClient));
	for (int iNAP = 0; iNAP<MAXTOPNAP; iNAP++)
	{
		strncpy(sClient.tp[iNAP].Name, this->RankingCharNAP[iNAP].Name, 11);
		sClient.tp[iNAP].TopNap = this->RankingCharNAP[iNAP].TopNap;
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSBLOOD()
{
	BYTE send[4096];
	GDTopBLOOD pMsg;
	pMsg.h.set(0xD9, 0x26, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSBLOOD(DGCharTopBLOOD *Recv)
{
	for (int iBLOOD = 0; iBLOOD<MAXTOPBLOOD; iBLOOD++)
	{
		strncpy(this->RankingCharBLOOD[iBLOOD].Name, Recv->tp[iBLOOD].Name, 11);
		this->RankingCharBLOOD[iBLOOD].TopBLOOD = Recv->tp[iBLOOD].TopBLOOD;
	}
}
void cRanking::SendUserBLOOD(LPOBJ lpObj)
{
	DGCharTop2BLOOD	sClient;
	sClient.h.set(0x59, sizeof(sClient));
	for (int iBLOOD = 0; iBLOOD<MAXTOPBLOOD; iBLOOD++)
	{
		strncpy(sClient.tp[iBLOOD].Name, this->RankingCharBLOOD[iBLOOD].Name, 11);
		sClient.tp[iBLOOD].TopBLOOD = this->RankingCharBLOOD[iBLOOD].TopBLOOD;
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSDEVIL()
{
	BYTE send[4096];
	GDTopDEVIL pMsg;
	pMsg.h.set(0xD9, 0x27, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSDEVIL(DGCharTopDEVIL *Recv)
{
	for (int iDEVIL = 0; iDEVIL<MAXTOPDEVIL; iDEVIL++)
	{
		strncpy(this->RankingCharDEVIL[iDEVIL].Name, Recv->tp[iDEVIL].Name, 11);
		this->RankingCharDEVIL[iDEVIL].TopDEVIL = Recv->tp[iDEVIL].TopDEVIL;
	}
}
void cRanking::SendUserDEVIL(LPOBJ lpObj)
{
	DGCharTop2DEVIL	sClient;
	sClient.h.set(0x60, sizeof(sClient));
	for (int iDEVIL = 0; iDEVIL<MAXTOPDEVIL; iDEVIL++)
	{
		strncpy(sClient.tp[iDEVIL].Name, this->RankingCharDEVIL[iDEVIL].Name, 11);
		sClient.tp[iDEVIL].TopDEVIL = this->RankingCharDEVIL[iDEVIL].TopDEVIL;
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================
void cRanking::SendDSCHAOS()
{
	BYTE send[4096];
	GDTopCHAOS pMsg;
	pMsg.h.set(0xD9, 0x28, 0);
	int size = sizeof(pMsg);
	pMsg.Result = 1;
	pMsg.h.size[0] = SET_NUMBERHB(size);
	pMsg.h.size[1] = SET_NUMBERLB(size);
	memcpy(send, &pMsg, sizeof(pMsg));
	gDataServerConnection.DataSend(send, size);
}

void cRanking::RecvDSCHAOS(DGCharTopCHAOS *Recv)
{
	for (int iCHAOS = 0; iCHAOS<MAXTOPCHAOS; iCHAOS++)
	{
		strncpy(this->RankingCharCHAOS[iCHAOS].Name, Recv->tp[iCHAOS].Name, 11);
		this->RankingCharCHAOS[iCHAOS].TopCHAOS = Recv->tp[iCHAOS].TopCHAOS;
	}
}
void cRanking::SendUserCHAOS(LPOBJ lpObj)
{
	DGCharTop2CHAOS	sClient;
	sClient.h.set(0x71, sizeof(sClient));
	for (int iCHAOS = 0; iCHAOS<MAXTOPCHAOS; iCHAOS++)
	{
		strncpy(sClient.tp[iCHAOS].Name, this->RankingCharCHAOS[iCHAOS].Name, 11);
		sClient.tp[iCHAOS].TopCHAOS = this->RankingCharCHAOS[iCHAOS].TopCHAOS;
	}
	DataSend(lpObj->Index, (BYTE*)&sClient, sizeof(sClient));
}
//=========================================================================================