// CommandManager.h: interface for the CCommandManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Protocol.h"
#include "User.h"

#define MAX_COMMAND 100

enum eCommandNumber
{
	COMMAND_MOVE			= 1,
	COMMAND_POST			= 2,
	COMMAND_ADD_POINT1		= 3,
	COMMAND_ADD_POINT2		= 4,
	COMMAND_ADD_POINT3		= 5,
	COMMAND_ADD_POINT4		= 6,
	COMMAND_ADD_POINT5		= 7,
	COMMAND_PK_CLEAR		= 8,
	COMMAND_MONEY			= 9,
	COMMAND_CHANGE			= 10,
	COMMAND_WARE			= 11,
	COMMAND_RESET			= 12,
	COMMAND_GM_MOVE			= 13,
	COMMAND_GM_POST			= 14,
	COMMAND_TRACK			= 15,
	COMMAND_TRACE			= 16,
	COMMAND_DISCONNECT		= 17,
	COMMAND_FIREWORKS		= 18,
	COMMAND_MAKE			= 19,
	COMMAND_SKIN			= 20,
	COMMAND_SET_MONEY		= 21,
	COMMAND_NOTICE			= 22,
	COMMAND_MASTER_RESET	= 23,
	COMMAND_GUILD_WAR		= 24,
	COMMAND_BATTLE_SOCCER	= 25,
	COMMAND_REQUEST			= 26,
	COMMAND_HIDE			= 27,
	COMMAND_REI				= 28,
	COMMAND_CLEAR_INVENTORY = 29,
	COMMAND_SETVIP			= 30,
	COMMAND_MARRY			= 31,
	COMMAND_OPENWAREHOUSE	= 32,
	COMMAND_CHANGECLASS		= 33,
	COMMAND_REWARD			= 34,
	COMMAND_REWARDALL		= 35,
	COMMAND_RELOAD			= 36,
	COMMAND_BLOCCHAR		= 37,
	COMMAND_BLOCACC			= 38,
	COMMAND_RENAME			= 39,
	COMMAND_EVENTQUICKLY	= 40,
	COMMAND_INF				= 41,
	COMMAND_EVENTSTART		= 42,
	COMMAND_EVENTSTARTJOIN	= 43,
	COMMAND_EVENTGET		= 44,
	COMMAND_EVENTGETJOIN	= 45,
	COMMAND_EVENTESC		= 46,
	COMMAND_MAKESET			= 47,
	COMMAND_DROP			= 48,
	COMMAND_QUEST			= 49,
	COMMAND_GIFT			= 50,
	COMMAND_EVENTROULETTE	= 51,
	COMMAND_TOP				= 52,
	COMMAND_READD			= 53,
	COMMAND_QUIZ			= 54,
	COMMAND_PICK			= 55,
	COMMAND_HELPER			= 56,
	COMMAND_REMASTER		= 57,
	COMMAND_STARTBC			= 58,
	COMMAND_STARTDS			= 59,
	COMMAND_STARTCC			= 60,
	COMMAND_STARTIT			= 61,
	COMMAND_DISABLEPVP		= 62,
	COMMAND_LOCK			= 63,
	COMMAND_UNLOCK			= 64,
	COMMAND_CUSTOM_STORE	= 65,
	COMMAND_CUSTOM_OFFSTORE = 66,
	COMMAND_CUSTOM_ATTACK	= 67,
	COMMAND_CUSTOM_OFFATTACK= 68,
	COMMAND_MOVEALL			= 69,
	COMMAND_MOVEGUILD		= 70,
	COMMAND_PVP				= 71,
	COMMAND_KILLALL			= 72,
	COMMAND_STARTTVT		= 73,
	COMMAND_SPOT			= 74,
	COMMAND_SETCOIN			= 75,
	COMMAND_PACK			= 76,
	COMMAND_UNPACK			= 77,
	COMMAND_STARTQUIZ		= 78,
	COMMAND_STARTDROP		= 79,
	COMMAND_STARTKING		= 80,
	COMMAND_STARTINVASION	= 81,
	COMMAND_STARTARENA		= 82,
	COMMAND_SETLEVEL		= 83,
	COMMAND_SET				= 84,
	COMMAND_DROPALL			= 85,
	COMMAND_PKEVENT = 86,
	COMMAND_GIFCODE = 87,
#if(MOCNAP == 1)
	COMMAND_SETMOCNAP = 88,
#endif
	COMMAND_RANDOMITEM = 89,
};

//**********************************************//
//********** DataServer -> GameServer **********//
//**********************************************//

struct SDHP_COMMAND_MARRY_RECV
{
    PSBMSG_HEAD header; // C1:0F:02
    WORD index;
    char name[11];
    char marryname[11];
    char mode[11];
    char NameGet1[11];
    char NameGet2[11];
    UINT countyou;
    UINT counthim;
    UINT marriedon;
};

struct SDHP_COMMAND_RESET_RECV
{
	PSBMSG_HEAD header; // C1:0F:00
	WORD index;
	char account[11];
	char name[11];
	UINT ResetDay;
	UINT ResetWek;
	UINT ResetMon;
};

struct SDHP_COMMAND_MASTER_RESET_RECV
{
	PSBMSG_HEAD header; // C1:0F:01
	WORD index;
	char account[11];
	char name[11];
	UINT MasterResetDay;
	UINT MasterResetWek;
	UINT MasterResetMon;
};

struct SDHP_COMMAND_RENAME_RECV
{
	PSBMSG_HEAD header; // C1:0F:05
	WORD index;
	char account[11];
	char name[11];
	char newname[11];
	BYTE result;
};

struct SDHP_GIFT_RECV
{
	PSBMSG_HEAD header; // C1:0F:08
	WORD index;
	BYTE result;
};

struct SDHP_TOP_RECV
{
	PSWMSG_HEAD header; // C1:0F:09
	WORD index;
	WORD type;
	WORD classe;
	BYTE count;
};

struct SDHP_COMMAND_BLOC_RECV
{
    PSBMSG_HEAD header; // C1:0F:06
    WORD index;
	BYTE result;
};

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//

struct SDHP_COMMAND_MARRY_SEND
{
	PSBMSG_HEAD header; // C1:0F:02
	WORD index;
	char name[11];
	char marryname[11];
	char mode[11];
};

struct SDHP_COMMAND_RESET_SEND
{
	PSBMSG_HEAD header; // C1:0F:00
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_COMMAND_MASTER_RESET_SEND
{
	PSBMSG_HEAD header; // C1:0F:01
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_COMMAND_REWARD_SEND
{
	PSBMSG_HEAD header; // C1:0F:03
	WORD index;
	char account[11];
	char name[11];
	char accountGM[11];
	char nameGM[11];
	UINT Type;
	UINT Value;
};

struct SDHP_COMMAND_REWARDALL_SEND
{
	PSBMSG_HEAD header; // C1:0F:04
	WORD index;
	char accountGM[11];
	char nameGM[11];
	UINT Type;
	UINT Value;
};

struct SDHP_COMMAND_RENAME_SEND
{
	PSBMSG_HEAD header; // C1:0F:05
	WORD index;
	char account[11];
	char name[11];
	char newname[11];
};

struct SDHP_COMMAND_BLOC_SEND
{
    PSBMSG_HEAD header; // C1:0F:06
    WORD index;
    char namebloc[11];
	WORD days;
};

struct SDHP_GIFT_SEND
{
    PSBMSG_HEAD header; // C1:0F:08
    WORD index;
	char account[11];
};

struct SDHP_TOP_SEND
{
    PSBMSG_HEAD header; // C1:0F:09
    WORD index;
	WORD type;
	WORD classe;
};

//**********************************************//
//**********************************************//
//**********************************************//

struct SDHP_TOP_INFO
{
	char name[11];
	UINT value;
};

struct COMMAND_INFO
{
	int code;
	char label[32];
};

class CCommandManager
{
public:
	CCommandManager();
	virtual ~CCommandManager();
	void Init();
	void MainProc();
	void Add(char* label,int code);
	long GetNumber(char* arg,int pos);
	void GetString(char* arg,char* out,int size,int pos);
	long GetCommandCode(char* label);
	bool ManagementCore(LPOBJ lpObj,char* message, int Npc);
	void RemoveRequisites(LPOBJ lpObj, int IdCommand);
	bool CommandMove(LPOBJ lpObj,char* arg);
	bool CommandPost(LPOBJ lpObj,char* arg);
	bool CommandAddPoint(LPOBJ lpObj,char* arg,int type);
	void CommandAddPointAuto(LPOBJ lpObj,char* arg,int type);
	bool CommandPKClear(LPOBJ lpObj,char* arg,int Npc);
	bool CommandMoney(LPOBJ lpObj,char* arg);
	bool CommandChange(LPOBJ lpObj,char* arg,int Npc);
	bool CommandWare(LPOBJ lpObj,char* arg);
	bool CommandReset(LPOBJ lpObj,char* arg,int Npc);
	void CommandResetAuto(LPOBJ lpObj,char* arg,int Npc);
	//--
#if(RESETVIP == 1)
	bool CommandResetVip(LPOBJ lpObj, char* arg, int Npc);
	void CommandResetAutoVip(LPOBJ lpObj, char* arg, int Npc);
	void CommandResetAutoProcVip(LPOBJ lpObj);
#endif
	//--
	bool CommandGMMove(LPOBJ lpObj,char* arg);
	bool CommandGMPost(LPOBJ lpObj,char* arg);
	bool CommandTrack(LPOBJ lpObj,char* arg);
	bool CommandTrace(LPOBJ lpObj,char* arg);
	bool CommandDisconnect(LPOBJ lpObj,char* arg);
	bool CommandFireworks(LPOBJ lpObj,char* arg);
	bool CommandMake(LPOBJ lpObj,char* arg);
	bool CommandSkin(LPOBJ lpObj,char* arg);
	bool CommandSetMoney(LPOBJ lpObj,char* arg);
	bool CommandNotice(LPOBJ lpObj,char* arg);
	bool CommandMasterReset(LPOBJ lpObj,char* arg,int Npc);
	bool CommandGuildWar(LPOBJ lpObj,char* arg);
	bool CommandBattleSoccer(LPOBJ lpObj,char* arg);
	bool CommandRequest(LPOBJ lpObj,char* arg);
	bool CommandHide(LPOBJ lpObj,char* arg);
	void CommandAddPointAutoProc(LPOBJ lpObj);
	void CommandResetAutoProc(LPOBJ lpObj);
	void DGCommandResetRecv(SDHP_COMMAND_RESET_RECV* lpMsg);
	void DGCommandMasterResetRecv(SDHP_COMMAND_MASTER_RESET_RECV* lpMsg);
	bool CommandClearInventory(LPOBJ lpObj,char* arg);
	void DGCommandMarryRecv(SDHP_COMMAND_MARRY_RECV* lpMsg);
	bool CommandMarry(LPOBJ lpObj,char* arg);
	bool CommandSetVIP(LPOBJ lpObj,char* arg);
	bool CommandOpenWarehouse(LPOBJ lpObj);
	bool CommandChangeClass(LPOBJ lpObj,char* arg,int Npc);
	bool CommandReward(LPOBJ lpObj,char* arg);
	bool CommandRewardAll(LPOBJ lpObj,char* arg);
    bool CommandReload(LPOBJ lpObj,char* arg);
	bool CommandRename(LPOBJ lpObj,char* arg);
	void DGCommandRenameRecv(SDHP_COMMAND_RENAME_RECV* lpMsg);
	bool CommandInfo(LPOBJ lpObj,char* arg);
    bool CommandBlocAcc(LPOBJ lpObj,char* arg);
	bool CommandBlocAccRecv(SDHP_COMMAND_BLOC_RECV* lpMsg);
    bool CommandBlocChar(LPOBJ lpObj,char* arg);
	bool CommandBlocCharRecv(SDHP_COMMAND_BLOC_RECV* lpMsg);
	bool CommandMakeSet(LPOBJ lpObj,char* arg);
	bool CommandDrop(LPOBJ lpObj,char* arg);
	bool CommandGift(LPOBJ lpObj,char* arg);
	void DGCommandGiftRecv(SDHP_GIFT_RECV* lpMsg);
	void DGCommandTopRecv(SDHP_TOP_RECV* lpMsg);
	bool CommandTop(LPOBJ lpObj,char* arg);
	bool CommandReAdd(LPOBJ lpObj,char* arg,int Npc);
	bool CommandHelper(LPOBJ lpObj,char* arg,int Npc);
	bool CommandReMaster(LPOBJ lpObj,char* arg,int Npc);
	bool CommandStartBC(LPOBJ lpObj,char* arg);
	bool CommandStartDS(LPOBJ lpObj,char* arg);
	bool CommandStartCC(LPOBJ lpObj,char* arg);
	bool CommandStartIT(LPOBJ lpObj,char* arg);
	bool CommandDisablePvp(LPOBJ lpObj,char* arg,int Npc);
	bool CommandLock(LPOBJ lpObj,char* arg);
	bool CommandUnLock(LPOBJ lpObj,char* arg);
	bool CommandMoveAll(LPOBJ lpObj,char* arg);
	bool CommandMoveGuild(LPOBJ lpObj,char* arg);
	bool CommandSpot(LPOBJ lpObj,char* arg);
	bool CommandSetCoin(LPOBJ lpObj,char* arg);
	bool CommandStartQuiz(LPOBJ lpObj,char* arg);
	bool CommandStartDrop(LPOBJ lpObj,char* arg);
	bool CommandStartKing(LPOBJ lpObj,char* arg);
	bool CommandStartTvT(LPOBJ lpObj,char* arg);
	bool CommandStartInvasion(LPOBJ lpObj,char* arg);
	bool CommandStartCustomArena(LPOBJ lpObj,char* arg);
	bool CommandSetLevel(LPOBJ lpObj,char* arg);
	bool CommandSet(LPOBJ lpObj,char* arg);
	bool CommandDropAll(LPOBJ lpObj,char* arg);

#if(MOCNAP == 1)
	bool CommandSetMocNap(LPOBJ lpObj, char* arg);
#endif

#if(NGANHANGNGOC_NEW)
	void SendZenCustomVault(LPOBJ lpObj, char* arg);
	void RecvZenCustomVault(LPOBJ lpObj, char* arg);
	void SendBlessCustomVault(LPOBJ lpObj, char* arg);
	void SendSoulCustomVault(LPOBJ lpObj, char* arg);
	void SendChaosCustomVault(LPOBJ lpObj, char* arg);
	void SendLifeCustomVault(LPOBJ lpObj, char* arg);
	void SendCreCustomVault(LPOBJ lpObj, char* arg);
	void SendGemCustomVault(LPOBJ lpObj, char* arg);

	void SendGem1CustomVault(LPOBJ lpObj, char* arg);
	void SendGem2CustomVault(LPOBJ lpObj, char* arg);
	void SendGem3CustomVault(LPOBJ lpObj, char* arg);
	void SendGem4CustomVault(LPOBJ lpObj, char* arg);
	//
	void RecvBlessCustomVault(LPOBJ lpObj, char* arg);
	void RecvSoulCustomVault(LPOBJ lpObj, char* arg);
	void RecvChaosCustomVault(LPOBJ lpObj, char* arg);
	void RecvLifeCustomVault(LPOBJ lpObj, char* arg);
	void RecvCreCustomVault(LPOBJ lpObj, char* arg);
	void RecvGemCustomVault(LPOBJ lpObj, char* arg);
	void RecvGem1CustomVault(LPOBJ lpObj, char* arg);
	void RecvGem2CustomVault(LPOBJ lpObj, char* arg);
	void RecvGem3CustomVault(LPOBJ lpObj, char* arg);
	void RecvGem4CustomVault(LPOBJ lpObj, char* arg);
	//
	void RecvChaosCustomVault10(LPOBJ lpObj, char* arg);
	void RecvBlessCustomVault10(LPOBJ lpObj, char* arg);
	void RecvSoulCustomVault10(LPOBJ lpObj, char* arg);
	void RecvLifeCustomVault10(LPOBJ lpObj, char* arg);
	void RecvCreCustomVault10(LPOBJ lpObj, char* arg);
	void RecvGemCustomVault10(LPOBJ lpObj, char* arg);
	void RecvGem1CustomVault10(LPOBJ lpObj, char* arg);
	void RecvGem2CustomVault10(LPOBJ lpObj, char* arg);
	void RecvGem3CustomVault10(LPOBJ lpObj, char* arg);
	void RecvGem4CustomVault10(LPOBJ lpObj, char* arg);
	//
	void RecvChaosCustomVault20(LPOBJ lpObj, char* arg);
	void RecvBlessCustomVault20(LPOBJ lpObj, char* arg);
	void RecvSoulCustomVault20(LPOBJ lpObj, char* arg);
	void RecvLifeCustomVault20(LPOBJ lpObj, char* arg);
	void RecvCreCustomVault20(LPOBJ lpObj, char* arg);
	void RecvGemCustomVault20(LPOBJ lpObj, char* arg);
	void RecvGem1CustomVault20(LPOBJ lpObj, char* arg);
	void RecvGem2CustomVault20(LPOBJ lpObj, char* arg);
	void RecvGem3CustomVault20(LPOBJ lpObj, char* arg);
	void RecvGem4CustomVault20(LPOBJ lpObj, char* arg);
	//
	void RecvChaosCustomVault30(LPOBJ lpObj, char* arg);
	void RecvBlessCustomVault30(LPOBJ lpObj, char* arg);
	void RecvSoulCustomVault30(LPOBJ lpObj, char* arg);
	void RecvLifeCustomVault30(LPOBJ lpObj, char* arg);
	void RecvCreCustomVault30(LPOBJ lpObj, char* arg);
	void RecvGemCustomVault30(LPOBJ lpObj, char* arg);
	void RecvGem1CustomVault30(LPOBJ lpObj, char* arg);
	void RecvGem2CustomVault30(LPOBJ lpObj, char* arg);
	void RecvGem3CustomVault30(LPOBJ lpObj, char* arg);
	void RecvGem4CustomVault30(LPOBJ lpObj, char* arg);
#endif

#if(HONCHIENCLASS == 1)
	void CommandPKEvent(LPOBJ lpObj);
#endif

	void CommandRandomItem(LPOBJ lpObj);

private:
	COMMAND_INFO m_CommandInfo[MAX_COMMAND];
};

extern CCommandManager gCommandManager;
