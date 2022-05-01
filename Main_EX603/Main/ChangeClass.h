#pragma once

#include "Protocol.h"

struct PMSG_CHANGECLASS_DATA
{
	PSBMSG_HEAD	Head;
	int m_WCoinC;
};

struct CG_CHANGECLASS_SEND
{
	PSBMSG_HEAD Head;
	int Type;
};

class cChangeClass
{
public:
	cChangeClass();
	virtual ~cChangeClass();
	void RecvData(PMSG_CHANGECLASS_DATA* Data);
	void SendChangeClass(int Type);
	int m_WCoinC;
}; extern cChangeClass gChangeClass;