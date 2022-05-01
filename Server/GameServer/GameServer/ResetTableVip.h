// ResetTableVip.h: interface for the CResetTableVip class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"

#if(RESETVIP == 1)

struct RESET_TABLE_VIP_INFO
{
	int MinReset;
	int MaxReset;
	int Level[MAX_ACCOUNT_LEVEL];
	int Money[MAX_ACCOUNT_LEVEL];
	int Point[MAX_ACCOUNT_LEVEL];
};

class CResetTableVip
{
public:
	CResetTableVip();
	virtual ~CResetTableVip();
	void Load(char* path);
	int GetResetLevel(LPOBJ lpObj);
	int GetResetMoney(LPOBJ lpObj);
	int GetResetPoint(LPOBJ lpObj);

	int GetResetPointKeep(LPOBJ lpObj);

private:
	std::vector<RESET_TABLE_VIP_INFO> m_ResetTableVipInfo;
	RESET_TABLE_VIP_INFO m_ResetTableVip;
};

extern CResetTableVip gResetTableVip;

#endif