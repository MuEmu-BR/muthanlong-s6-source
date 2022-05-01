// Log.h: interface for the CLog class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_LOG 14

enum eLogType
{
	LOG_GENERAL = 0,
	LOG_CHAT = 1,
	LOG_COMMAND = 2,
	LOG_TRADE = 3,
	LOG_CONNECT = 4,
	LOG_HACK = 5,
	LOG_CASH_SHOP = 6,
	LOG_CHAOS_MIX = 7,
	LOG_ANTIFLOOD = 8,
	LOG_RESET = 9,
	LOG_GRAND_RESET = 10,
	LOG_TIEN_TE = 11,
#if(VANTHANH > 3)
	LOG_KET_NOI = 12,
	LOG_THU_MUA = 13,
#endif
};

struct LOG_INFO
{
	BOOL Active;
	char Directory[256];
	int Day;
	int Month;
	int Year;
	char Filename[256];
	HANDLE File;
};

class CLog
{
public:
	CLog();
	virtual ~CLog();
	void AddLog(BOOL active,char* directory);
	void Output(eLogType type,char* text,...);
private:
	LOG_INFO m_LogInfo[MAX_LOG];
	int m_count;
};

extern CLog gLog;