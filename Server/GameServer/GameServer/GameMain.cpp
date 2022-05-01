#include "stdafx.h"
#include "GameMain.h"
#include "BattleSoccerManager.h"
#include "CommandManager.h"
#include "DSProtocol.h"
#include "ESProtocol.h"
#include "HackCheck.h"
#include "JSProtocol.h"
#include "MasterSkillTree.h"
#include "MonsterAI.h"
#include "MonsterManager.h"
#include "ObjectManager.h"
#include "Protect.h"
#include "QueueTimer.h"
#include "ServerInfo.h"
#include "SocketManagerUdp.h"
#include "User.h"
#include "Util.h"
#include "CustomAttack.h"
#include "OfflineMode.h"
#include "CustomGHRS.h"
#include "SkyEvent.h"
#include "ChienTruongCo.h"
#include "FakeOnline.h"
#include "SwampEvent.h"
#include "CustomRanking.h"
#include "Survivor.h"
#include "EventTvT.h"
#include "MuunPetCustom.h" //20-03-2022

bool IsMeAuth = false;

CConnection gJoinServerConnection;
CConnection gDataServerConnection;

void GameMainInit(HWND hwnd) // OK
{
	if(CreateMutex(0,0,gServerInfo.m_ServerMutex) == 0 || GetLastError() == ERROR_ALREADY_EXISTS)
	{
		ErrorMessageBox("Could not open GameServer");
		return;
	}

	PROTECT_START

	gObjInit();

	InitHackCheck();

	InitBattleSoccer();

	gGameServerLogOut = 0;

	gGameServerDisconnect = 0;

	gServerInfo.ReadInit();

	//gCommandManager.Init();

	gObjSetExperienceTable();

	gMonsterManager.SetMonsterData();

	#if(GAMESERVER_UPDATE>=401)

	gMasterSkillTree.SetMasterLevelExperienceTable();

	#endif

	gJoinServerConnection.Init(hwnd,JoinServerProtocolCore);

	gDataServerConnection.Init(hwnd,DataServerProtocolCore);

	PROTECT_FINAL

	// ---
#if (GHRS_TOP1_NEW)
	IsMeAuth = true;
	srand(time(0));
	gCustomGHRS.serverStart = true;
#endif

#if(SKY_EVENT == 1)
	gSkyEvent.Init();
#endif

#if(SWAMP_EVENT  ==1 )
	gSwampEvent.Init();
#endif

	// ---
}

void ConnectServerInfoSend() // OK
{
	PROTECT_START

	SDHP_GAME_SERVER_LIVE_SEND pMsg;

	pMsg.header.set(0x01,sizeof(pMsg));

	pMsg.ServerCode = (WORD)gServerInfo.m_ServerCode;
if( Conectar == 1 )
{
	pMsg.UserTotal = (BYTE)((gObjTotalUser==0)?0:((gObjTotalUser*100) / 100));
}
else
{
	pMsg.UserTotal = (BYTE)((gObjTotalUser==0)?0:((gObjTotalUser*100)/ gServerInfo.m_ServerMaxUserNumber));
}

	pMsg.UserCount = (WORD)gObjTotalUser;

	pMsg.AccountCount = 0;

	pMsg.PCPointCount = 0;
if( Conectar == 1 )
{
	pMsg.MaxUserCount = (WORD) 100; //gServerInfo.m_ServerMaxUserNumber;
}
else
{
	pMsg.MaxUserCount = (WORD) gServerInfo.m_ServerMaxUserNumber;
}
	gSocketManagerUdp.DataSend((BYTE*)&pMsg,pMsg.header.size);

	PROTECT_FINAL
}

bool JoinServerConnect(DWORD wMsg) // OK
{
	if(gJoinServerConnection.Connect(gServerInfo.m_JoinServerAddress,(WORD)gServerInfo.m_JoinServerPort,wMsg) == 0)
	{
		return 0;
	}

	GJServerInfoSend();
	return 1;
}

bool DataServerConnect(DWORD wMsg) // OK
{
	if(gDataServerConnection.Connect(gServerInfo.m_DataServerAddress,(WORD)gServerInfo.m_DataServerPort,wMsg) == 0)
	{
		return 0;
	}

	GDServerInfoSend();
	return 1;
}

bool JoinServerReconnect(HWND hwnd,DWORD wMsg) // OK
{
	if(gJoinServerConnection.CheckState() == 0)
	{
		gJoinServerConnection.Init(hwnd,JoinServerProtocolCore);
		return JoinServerConnect(wMsg);
	}

	return 1;
}

bool DataServerReconnect(HWND hwnd,DWORD wMsg) // OK
{
	if(gDataServerConnection.CheckState() == 0)
	{
		gDataServerConnection.Init(hwnd,DataServerProtocolCore);
		return DataServerConnect(wMsg);
	}

	return 1;
}

void JoinServerMsgProc(WPARAM wParam,LPARAM lParam) // OK
{
	switch(LOWORD(lParam))
	{
		case FD_READ:
			gJoinServerConnection.DataRecv();
			break;
		case FD_WRITE:
			gJoinServerConnection.DataSendEx();
			break;
		case FD_CLOSE:
			gJoinServerConnection.Disconnect();
			gObjAllDisconnect();
			break;
	}
}

void DataServerMsgProc(WPARAM wParam,LPARAM lParam) // OK
{
	switch(LOWORD(lParam))
	{
		case FD_READ:
			gDataServerConnection.DataRecv();
			break;
		case FD_WRITE:
			gDataServerConnection.DataSendEx();
			break;
		case FD_CLOSE:
			gDataServerConnection.Disconnect();
			gObjAllDisconnect();
			break;
	}
}

void CALLBACK QueueTimerCallback(PVOID lpParameter,BOOLEAN TimerOrWaitFired) // OK
{
	PROTECT_START

	static CCriticalSection critical;

	critical.lock();

	switch(((int)lpParameter))
	{
		case QUEUE_TIMER_MONSTER:
			gObjectManager.ObjectMonsterAndMsgProc();
			break;
		case QUEUE_TIMER_MONSTER_MOVE:
			gObjectManager.ObjectMoveProc();
			break;
		case QUEUE_TIMER_MONSTER_AI:
			CMonsterAI::MonsterAIProc();
			break;
		case QUEUE_TIMER_MONSTER_AI_MOVE:
			CMonsterAI::MonsterMoveProc();
			break;
		case QUEUE_TIMER_EVENT:
			gObjEventRunProc();
			break;
		case QUEUE_TIMER_VIEWPORT:
			gObjViewportProc();

			for (int n = OBJ_STARTUSERINDEX; n < MAX_OBJECT; n++)
			{
				if (gObj[n].Type != OBJECT_USER)
				{
					continue;
				}

				g_OfflineMode.PickUP(n);
				g_OfflineMode.regresar(n);

#if(CHIENTRUONGCO == 1)
				gChienTruongCo.CheckTimeInCTC(n); //Check Time CTC
#endif

#if(TVTEVENT == 1) // ok
				gTvTEvent.TimeTvTEvent(n);
#endif

#if(HONCHIENCLASS == 1) // ok
				g_Survivor.TimePkEvent(n);
#endif

				s_FakeOnline.NhatItem(n);
				s_FakeOnline.QuayLaiToaDoGoc(n);
			}
			break;
		case QUEUE_TIMER_FIRST:
			gObjFirstProc();
			break;
		case QUEUE_TIMER_CLOSE:
			gObjCloseProc();
			break;
		case QUEUE_TIMER_MATH_AUTHENTICATOR:
			gObjMathAuthenticatorProc();
			break;
		case QUEUE_TIMER_ACCOUNT_LEVEL:
			gObjAccountLevelProc();
			break;
		case QUEUE_TIMER_PICK_COMMAND:
			gObjPickProc();
			break;
#if(RANKING_NEW == 1)
		case QUEUE_TIMER_RANKINGALL:
			LogAdd(LOG_RED, "[XepHang] CLASS ALL"); //20-03-2022 
			gRanking.SendDS();
			break;
		case QUEUE_TIMER_RANKINGCLASS: 
			LogAdd(LOG_RED, "[XepHang] CLASS"); //20-03-2022 
			gRanking.SendDSDW();
			gRanking.SendDSDK();
			gRanking.SendDSEF();
			gRanking.SendDSMG();
			gRanking.SendDSDL();
			gRanking.SendDSSM();
			gRanking.SendDSRF();
			break;
		case QUEUE_TIMER_RANKINGTOPNAP:
			LogAdd(LOG_RED, "[XepHang] TOP NAP"); //20-03-2022 
			gRanking.SendDSNAP();
			break;
		case QUEUE_TIMER_RANKINGEVENT:
			LogAdd(LOG_RED, "[XepHang] TOP EVENT"); //20-03-2022 
			gRanking.SendDSBLOOD();
			gRanking.SendDSDEVIL();
			gRanking.SendDSCHAOS();
			break;
#endif
	}

	critical.unlock();

	PROTECT_FINAL
}
