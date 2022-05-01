// ResetTableVip.cpp: implementation of the CResetTableVip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ResetTableVip.h"
#include "MemScript.h"
#include "ServerInfo.h"
#include "Util.h"

#if(RESETVIP == 1)

CResetTableVip gResetTableVip;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CResetTableVip::CResetTableVip() // OK
{
	this->m_ResetTableVipInfo.clear();
}

CResetTableVip::~CResetTableVip() // OK
{

}

void CResetTableVip::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_ResetTableVipInfo.clear();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			RESET_TABLE_VIP_INFO info;

			info.MinReset = lpMemScript->GetNumber();

			info.MaxReset = lpMemScript->GetAsNumber();

			info.Level[0] = lpMemScript->GetAsNumber();

			info.Level[1] = lpMemScript->GetAsNumber();

			info.Level[2] = lpMemScript->GetAsNumber();

			info.Level[3] = lpMemScript->GetAsNumber();

			info.Money[0] = lpMemScript->GetAsNumber();

			info.Money[1] = lpMemScript->GetAsNumber();

			info.Money[2] = lpMemScript->GetAsNumber();

			info.Money[3] = lpMemScript->GetAsNumber();

			info.Point[0] = lpMemScript->GetAsNumber();

			info.Point[1] = lpMemScript->GetAsNumber();

			info.Point[2] = lpMemScript->GetAsNumber();

			info.Point[3] = lpMemScript->GetAsNumber();

			this->m_ResetTableVipInfo.push_back(info);
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

int CResetTableVip::GetResetLevel(LPOBJ lpObj) // OK
{
	for (std::vector<RESET_TABLE_VIP_INFO>::iterator it = this->m_ResetTableVipInfo.begin(); it != this->m_ResetTableVipInfo.end(); it++)
	{
		if ((lpObj->Reset + 1) >= it->MinReset && (lpObj->Reset + 1) <= it->MaxReset)
		{
			if (it->Level[lpObj->AccountLevel] == -1)
			{
				return gServerInfo.m_CommandResetLevel[lpObj->AccountLevel];
			}
			else
			{
				return it->Level[lpObj->AccountLevel];
			}
		}
	}

	return gServerInfo.m_CommandResetLevel[lpObj->AccountLevel];
}

int CResetTableVip::GetResetMoney(LPOBJ lpObj) // OK
{
	for (std::vector<RESET_TABLE_VIP_INFO>::iterator it = this->m_ResetTableVipInfo.begin(); it != this->m_ResetTableVipInfo.end(); it++)
	{
		if ((lpObj->Reset + 1) >= it->MinReset && (lpObj->Reset + 1) <= it->MaxReset)
		{
			if (it->Money[lpObj->AccountLevel] == -1)
			{
				return gServerInfo.m_CommandResetMoney[lpObj->AccountLevel];
			}
			else
			{
				return it->Money[lpObj->AccountLevel];
			}
		}
	}

	return gServerInfo.m_CommandResetMoney[lpObj->AccountLevel];
}

int CResetTableVip::GetResetPoint(LPOBJ lpObj) // OK
{
	int point = 0;

	for (int n = 1; n <= lpObj->Reset; n++)
	{
		int AddPoint = gServerInfo.m_CommandResetPoint[lpObj->AccountLevel];

		for (std::vector<RESET_TABLE_VIP_INFO>::iterator it = this->m_ResetTableVipInfo.begin(); it != this->m_ResetTableVipInfo.end(); it++)
		{
			if (n >= it->MinReset && n <= it->MaxReset)
			{
				if (it->Point[lpObj->AccountLevel] == -1)
				{
					AddPoint = gServerInfo.m_CommandResetPoint[lpObj->AccountLevel];
					break;
				}
				else
				{
					AddPoint = it->Point[lpObj->AccountLevel];
					break;
				}
			}
		}

		point += AddPoint;
	}

	return point;
}


int CResetTableVip::GetResetPointKeep(LPOBJ lpObj) // OK
{

	for (std::vector<RESET_TABLE_VIP_INFO>::iterator it = this->m_ResetTableVipInfo.begin(); it != this->m_ResetTableVipInfo.end(); it++)
	{
		if ((lpObj->Reset + 1) >= it->MinReset && (lpObj->Reset + 1) <= it->MaxReset)
		{
			return it->Point[lpObj->AccountLevel];
		}
	}

	return m_ResetTableVip.Point[lpObj->AccountLevel];
}

#endif