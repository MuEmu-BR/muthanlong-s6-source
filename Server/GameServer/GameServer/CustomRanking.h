// ---
#include "stdafx.h"
#include "protocol.h"
// ---
#if(RANKINGGOC == 1)
#define MAX_RANK  10
// ---
struct CUSTOM_RANKING
{
	int index;
	char Name[20];
	char Col1[20];
	char Col2[20];
};
// ---
struct CUSTOM_RANKING_DATA
{
	char szName[20];
	int valor;
};

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//
struct SDHP_CUSTOM_RANKING_SEND 
{
    PBMSG_HEAD header;
	WORD index;
	WORD type;
};

//**********************************************//
//********** DataServer -> GameServer **********//
//**********************************************//
struct SDHP_CUSTOM_RANKING_RECV
{
	PWMSG_HEAD header; 
	int index;
	int type;
	int count;
};

//**********************************************//
//********** GameServer -> Cliente    **********//
//**********************************************//

struct PMSG_CUSTOM_RANKING_SEND
{
	PSWMSG_HEAD header; 
	int index;
	char rankname[20];
	char col1[20];
	char col2[20];
	int count;
};

struct PMSG_CUSTOM_RANKING_COUNT_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
	int count;
};

//**********************************************//
//********** Cliente -> GameServer    **********//
//**********************************************//

struct PMSG_CUSTOM_RANKING_COUNT_RECV
{
	PSBMSG_HEAD header; // C1:BF:51
};

struct PMSG_CUSTOM_RANKING_RECV
{
	PSBMSG_HEAD header; // C1:BF:51
	BYTE type;
};

// ---
class CCustomRanking
{
public:
	void Load(char* path);
	void GCReqRanking(int Index,PMSG_CUSTOM_RANKING_RECV* pMsg);
	void GCReqRankingCount(int Index,PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg);
	// ---
	int GetRankIndex(int aIndex);
	void CheckUpdate(LPOBJ lpObj);
	void GDCustomRankingRecv(SDHP_CUSTOM_RANKING_RECV* lpMsg);

private:
	int m_count;
	// ---
	CUSTOM_RANKING r_Data[MAX_RANK];
};
extern CCustomRanking gCustomRanking;
// ---
#endif

#define MAXTOP   10
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


struct GDTop
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTop tp[MAXTOP];
};
struct DGCharTop2
{
	PWMSG_HEAD h;
	CharTop	tp[MAXTOP];
};
//=======================================
struct GDTopDW
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopDW tp[MAXTOPDW];
};
struct DGCharTop2DW
{
	PWMSG_HEAD h;
	CharTopDW	tp[MAXTOPDW];
};
//=======================================
struct GDTopDK
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopDK tp[MAXTOPDK];
};
struct DGCharTop2DK
{
	PWMSG_HEAD h;
	CharTopDK	tp[MAXTOPDK];
};
//=======================================
struct GDTopEF
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopEF tp[MAXTOPEF];
};
struct DGCharTop2EF
{
	PWMSG_HEAD h;
	CharTopEF	tp[MAXTOPEF];
};
//=======================================
struct GDTopMG
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopMG tp[MAXTOPMG];
};
struct DGCharTop2MG
{
	PWMSG_HEAD h;
	CharTopMG	tp[MAXTOPMG];
};
//=======================================
struct GDTopDL
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopDL tp[MAXTOPDL];
};
struct DGCharTop2DL
{
	PWMSG_HEAD h;
	CharTopDL	tp[MAXTOPDL];
};
//=======================================
struct GDTopSM
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopSM tp[MAXTOPSM];
};
struct DGCharTop2SM
{
	PWMSG_HEAD h;
	CharTopSM	tp[MAXTOPSM];
};
//=======================================
struct GDTopRF
{
	PSWMSG_HEAD h;
	BYTE Result;
};
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
	PSWMSG_HEAD h;
	CharTopRF tp[MAXTOPRF];
};
struct DGCharTop2RF
{
	PWMSG_HEAD h;
	CharTopRF	tp[MAXTOPRF];
};
//=======================================
struct GDTopNAP
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopNAP
{
	char Name[11];
	int TopNap;
};
struct DGCharTopNAP
{
	PSWMSG_HEAD h;
	CharTopNAP tp[MAXTOPNAP];
};
struct DGCharTop2NAP
{
	PWMSG_HEAD h;
	CharTopNAP	tp[MAXTOPNAP];
};
//=======================================
struct GDTopBLOOD
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopBLOOD
{
	char Name[11];
	int TopBLOOD;
};
struct DGCharTopBLOOD
{
	PSWMSG_HEAD h;
	CharTopBLOOD tp[MAXTOPBLOOD];
};
struct DGCharTop2BLOOD
{
	PWMSG_HEAD h;
	CharTopBLOOD	tp[MAXTOPBLOOD];
};
//=======================================
struct GDTopDEVIL
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopDEVIL
{
	char Name[11];
	int TopDEVIL;
};
struct DGCharTopDEVIL
{
	PSWMSG_HEAD h;
	CharTopDEVIL tp[MAXTOPDEVIL];
};
struct DGCharTop2DEVIL
{
	PWMSG_HEAD h;
	CharTopDEVIL	tp[MAXTOPDEVIL];
};
//=======================================
struct GDTopCHAOS
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopCHAOS
{
	char Name[11];
	int TopCHAOS;
};
struct DGCharTopCHAOS
{
	PSWMSG_HEAD h;
	CharTopCHAOS tp[MAXTOPCHAOS];
};
struct DGCharTop2CHAOS
{
	PWMSG_HEAD h;
	CharTopCHAOS	tp[MAXTOPCHAOS];
};
//=======================================

class cRanking
{
public:
	//=======================================
	void SendDS();
	void RecvDS(DGCharTop *Recv);
	void SendUser(LPOBJ lpObj);
	CharTop RankingChar[MAXTOP];
	//=======================================
	void SendDSDW();
	void RecvDSDW(DGCharTopDW *Recv);
	void SendUserDW(LPOBJ lpObj);
	CharTopDW RankingCharDW[MAXTOPDW];
	//=======================================
	void SendDSDK();
	void RecvDSDK(DGCharTopDK *Recv);
	void SendUserDK(LPOBJ lpObj);
	CharTopDK RankingCharDK[MAXTOPDK];
	//=======================================
	void SendDSEF();
	void RecvDSEF(DGCharTopEF *Recv);
	void SendUserEF(LPOBJ lpObj);
	CharTopEF RankingCharEF[MAXTOPEF];
	//=======================================
	void SendDSMG();
	void RecvDSMG(DGCharTopMG *Recv);
	void SendUserMG(LPOBJ lpObj);
	CharTopMG RankingCharMG[MAXTOPMG];
	//=======================================
	void SendDSDL();
	void RecvDSDL(DGCharTopDL *Recv);
	void SendUserDL(LPOBJ lpObj);
	CharTopDL RankingCharDL[MAXTOPDL];
	//=======================================
	void SendDSSM();
	void RecvDSSM(DGCharTopSM *Recv);
	void SendUserSM(LPOBJ lpObj);
	CharTopSM RankingCharSM[MAXTOPSM];
	//=======================================
	void SendDSRF();
	void RecvDSRF(DGCharTopRF *Recv);
	void SendUserRF(LPOBJ lpObj);
	CharTopRF RankingCharRF[MAXTOPRF];
	//=======================================
	void SendDSNAP();
	void RecvDSNAP(DGCharTopNAP *Recv);
	void SendUserNAP(LPOBJ lpObj);
	CharTopNAP RankingCharNAP[MAXTOPNAP];
	//=======================================
	void SendDSBLOOD();
	void RecvDSBLOOD(DGCharTopBLOOD *Recv);
	void SendUserBLOOD(LPOBJ lpObj);
	CharTopBLOOD RankingCharBLOOD[MAXTOPBLOOD];
	//=======================================
	void SendDSDEVIL();
	void RecvDSDEVIL(DGCharTopDEVIL *Recv);
	void SendUserDEVIL(LPOBJ lpObj);
	CharTopDEVIL RankingCharDEVIL[MAXTOPDEVIL];
	//=======================================
	void SendDSCHAOS();
	void RecvDSCHAOS(DGCharTopCHAOS *Recv);
	void SendUserCHAOS(LPOBJ lpObj);
	CharTopCHAOS RankingCharCHAOS[MAXTOPCHAOS];
	//=======================================
	int FirstTime;
};
extern cRanking gRanking;