#pragma once
#include "stdafx.h"
#include "Protocol.h"

#if(RANKING_NEW == 1)

#define MAXTOP	 10
#define MAXTOPDW 10
#define MAXTOPDK 10
#define MAXTOPEF 10
#define MAXTOPMG 10
#define MAXTOPDL 10
#define MAXTOPSM 10
#define MAXTOPRF 10

#define MAXTOPNAP 10

#define MAXTOPBLOOD 10
#define MAXTOPDEVIL 10
#define MAXTOPCHAOS 10


struct CharTop
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTop
{
	PWMSG_HEAD h;
	CharTop	tp[MAXTOP];
};
//========================================================
struct CharTopDW
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopDW
{
	PWMSG_HEAD h;
	CharTopDW	tp[MAXTOPDW];
};
//========================================================
struct CharTopDK
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopDK
{
	PWMSG_HEAD h;
	CharTopDK	tp[MAXTOPDK];
};
//========================================================
struct CharTopEF
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopEF
{
	PWMSG_HEAD h;
	CharTopEF	tp[MAXTOPEF];
};
//========================================================
struct CharTopMG
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopMG
{
	PWMSG_HEAD h;
	CharTopMG	tp[MAXTOPMG];
};
//========================================================
struct CharTopDL
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopDL
{
	PWMSG_HEAD h;
	CharTopDL	tp[MAXTOPDL];
};
//========================================================
struct CharTopSM
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopSM
{
	PWMSG_HEAD h;
	CharTopSM	tp[MAXTOPSM];
};
//========================================================
struct CharTopRF
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopRF
{
	PWMSG_HEAD h;
	CharTopRF	tp[MAXTOPRF];
};
//========================================================
struct CharTopNAP
{
	char Name[11];
	int TopNap;
};
struct DGCharTopNAP
{
	PWMSG_HEAD h;
	CharTopNAP	tp[MAXTOPNAP];
};
//========================================================
struct CharTopBLOOD
{
	char Name[11];
	int TopBLOOD;
};
struct DGCharTopBLOOD
{
	PWMSG_HEAD h;
	CharTopBLOOD	tp[MAXTOPBLOOD];
};
//========================================================
struct CharTopDEVIL
{
	char Name[11];
	int TopDEVIL;
};
struct DGCharTopDEVIL
{
	PWMSG_HEAD h;
	CharTopDEVIL	tp[MAXTOPDEVIL];
};
//========================================================
struct CharTopCHAOS
{
	char Name[11];
	int TopCHAOS;
};
struct DGCharTopCHAOS
{
	PWMSG_HEAD h;
	CharTopCHAOS	tp[MAXTOPCHAOS];
};

//========================================================

class cRanking
{
public:
	cRanking();
	~cRanking();



	void ClickRanking(DWORD ClickMouse);
	DWORD ClickTick;
	int TrangRanking;

	void RecvInfo(DGCharTop * lpMsg);
	void RecvInfoDW(DGCharTopDW * lpMsg);
	void RecvInfoDK(DGCharTopDK * lpMsg);
	void RecvInfoEF(DGCharTopEF * lpMsg);

	void Draw();
	void Bind();
	bool Active;
	bool Show;
	int StartX;
	int StartY;
	int Page;
	DWORD ClickTime;

	CharTop	RankingChar[MAXTOP];
	CharTopDW	RankingCharDW[MAXTOPDW];
	CharTopDK	RankingCharDK[MAXTOPDK];
	CharTopEF	RankingCharEF[MAXTOPEF];

	void RecvInfoMG(DGCharTopMG * lpMsg);
	CharTopMG	RankingCharMG[MAXTOPMG];

	void RecvInfoDL(DGCharTopDL * lpMsg);
	CharTopDL	RankingCharDL[MAXTOPDL];

	CharTopSM	RankingCharSM[MAXTOPSM];
	void cRanking::RecvInfoSM(DGCharTopSM * lpMsg);

	void RecvInfoRF(DGCharTopRF * lpMsg);
	CharTopRF	RankingCharRF[MAXTOPRF];
	
	void RecvInfoNAP(DGCharTopNAP * lpMsg);
	CharTopNAP	RankingCharNAP[MAXTOPNAP];

	void RecvInfoBLOOD(DGCharTopBLOOD * lpMsg);
	CharTopBLOOD	RankingCharBLOOD[MAXTOPBLOOD];

	void RecvInfoDEVIL(DGCharTopDEVIL * lpMsg);
	CharTopDEVIL	RankingCharDEVIL[MAXTOPDEVIL];

	void RecvInfoCHAOS(DGCharTopCHAOS * lpMsg);
	CharTopCHAOS	RankingCharCHAOS[MAXTOPCHAOS];
};
extern cRanking gRanking;
#endif