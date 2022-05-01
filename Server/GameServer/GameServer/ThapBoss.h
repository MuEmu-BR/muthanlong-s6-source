// InvasionManager.h: interface for the CInvasionManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"

#define MAX_THAPBOSS 30
#define MAX_THAPBOSS_MONSTER 500
#define MAX_THAPBOSS_RESPAWN_GROUP 20

enum eThapBossState
{
	THAPBOSS_STATE_BLANK = 0,
	THAPBOSS_STATE_EMPTY = 1,
	THAPBOSS_STATE_START = 2,
};

struct THAPBOSS_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct THAPBOSS_RESPWAN_INFO
{
	int Group;
	int Map;
	int Value;
};

struct THAPBOSS_MONSTER_INFO
{
	int Group;
	int MonsterClass;
	int RegenType;
	int RegenTime;
};

struct THAPBOSS_INFO
{
	int Index;
	int State;
	int RemainTime;
	int TargetTime;
	int TickCount;
	int MonsterIndex[MAX_THAPBOSS_MONSTER];
	int RespawnMessage;
	int DespawnMessage;
	int BossIndex;
	int BossMessage;
	int ThapBossTime;
	std::vector<THAPBOSS_START_TIME> StartTime;
	std::vector<THAPBOSS_RESPWAN_INFO> RespawnInfo[MAX_THAPBOSS_RESPAWN_GROUP];
	std::vector<THAPBOSS_MONSTER_INFO> MonsterInfo;
};

class CThapBossManager
{
public:
	CThapBossManager();
	virtual ~CThapBossManager();
	void Init();
	void Load(char* path);
	void MainProc();
	void ProcState_BLANK(THAPBOSS_INFO* lpInfo);
	void ProcState_EMPTY(THAPBOSS_INFO* lpInfo);
	void ProcState_START(THAPBOSS_INFO* lpInfo);
	void SetState(THAPBOSS_INFO* lpInfo, int state);
	void SetState_BLANK(THAPBOSS_INFO* lpInfo);
	void SetState_EMPTY(THAPBOSS_INFO* lpInfo);
	void SetState_START(THAPBOSS_INFO* lpInfo);
	void CheckSync(THAPBOSS_INFO* lpInfo);
	int GetState(int index);
	int GetRemainTime(int index);
	bool AddMonster(THAPBOSS_INFO* lpInfo, int aIndex);
	bool DelMonster(THAPBOSS_INFO* lpInfo, int aIndex);
	int* GetMonster(THAPBOSS_INFO* lpInfo, int aIndex);
	void CleanMonster(THAPBOSS_INFO* lpInfo);
	void ClearMonster(THAPBOSS_INFO* lpInfo);
	int GetMonsterCount(THAPBOSS_INFO* lpInfo);
	void SetMonster(THAPBOSS_INFO* lpInfo, THAPBOSS_RESPWAN_INFO* lpRespawnInfo, THAPBOSS_MONSTER_INFO* lpMonsterInfo);
	void MonsterDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	void StartThapBoss(int index);
private:
	THAPBOSS_INFO m_ThapBossInfo[MAX_THAPBOSS];
};

extern CThapBossManager gThapBossManager;
