// InvasionManager.h: interface for the CInvasionManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if(BOSS_NHEN_TIME == 1)

#include "User.h"

#define MAX_BOSSNHEN 30
#define MAX_BOSSNHEN_MONSTER 500
#define MAX_BOSSNHEN_RESPAWN_GROUP 20

enum eBOSSNHENState
{
	BOSSNHEN_STATE_BLANK = 0,
	BOSSNHEN_STATE_EMPTY = 1,
	BOSSNHEN_STATE_START = 2,
};

struct BOSSNHEN_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct BOSSNHEN_RESPWAN_INFO
{
	int Group;
	int Map;
	int Value;
};

struct BOSSNHEN_MONSTER_INFO
{
	int Group;
	int MonsterClass;
	int RegenType;
	int RegenTime;
};

struct BOSSNHEN_INFO
{
	int Index;
	int State;
	int RemainTime;
	int TargetTime;
	int TickCount;
	int MonsterIndex[MAX_BOSSNHEN_MONSTER];
	int RespawnMessage;
	int DespawnMessage;
	int BossIndex;
	int BossMessage;
	int BOSSNHENTime;
	std::vector<BOSSNHEN_START_TIME> StartTime;
	std::vector<BOSSNHEN_RESPWAN_INFO> RespawnInfo[MAX_BOSSNHEN_RESPAWN_GROUP];
	std::vector<BOSSNHEN_MONSTER_INFO> MonsterInfo;
};

class CBOSSNHENManager
{
public:
	CBOSSNHENManager();
	virtual ~CBOSSNHENManager();
	void Init();
	void Load(char* path);
	void MainProc();
	void ProcState_BLANK(BOSSNHEN_INFO* lpInfo);
	void ProcState_EMPTY(BOSSNHEN_INFO* lpInfo);
	void ProcState_START(BOSSNHEN_INFO* lpInfo);
	void SetState(BOSSNHEN_INFO* lpInfo, int state);
	void SetState_BLANK(BOSSNHEN_INFO* lpInfo);
	void SetState_EMPTY(BOSSNHEN_INFO* lpInfo);
	void SetState_START(BOSSNHEN_INFO* lpInfo);
	void CheckSync(BOSSNHEN_INFO* lpInfo);
	int GetState(int index);
	int GetRemainTime(int index);
	bool AddMonster(BOSSNHEN_INFO* lpInfo, int aIndex);
	bool DelMonster(BOSSNHEN_INFO* lpInfo, int aIndex);
	int* GetMonster(BOSSNHEN_INFO* lpInfo, int aIndex);
	void CleanMonster(BOSSNHEN_INFO* lpInfo);
	void ClearMonster(BOSSNHEN_INFO* lpInfo);
	int GetMonsterCount(BOSSNHEN_INFO* lpInfo);
	void SetMonster(BOSSNHEN_INFO* lpInfo, BOSSNHEN_RESPWAN_INFO* lpRespawnInfo, BOSSNHEN_MONSTER_INFO* lpMonsterInfo);
	void MonsterDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	void StartBOSSNHEN(int index);
private:
	BOSSNHEN_INFO m_BOSSNHENInfo[MAX_BOSSNHEN];
};

extern CBOSSNHENManager gBOSSNHENManager;

#endif