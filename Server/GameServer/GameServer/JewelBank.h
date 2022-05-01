#pragma once
//----

#include "User.h"
#include "DSProtocol.h"

// -------------------------------------------------------------------------------

enum eBankExType
{
	BANKEX_BLESS = 0,
	BANKEX_SOUL = 1,
	BANKEX_CHAOS = 2,
	BANKEX_CREATION = 3,
	BANKEX_LIFE = 4,
	BANKEX_HARMONY = 5,
	BANKEX_GUASTONE = 6,
	BANKEX_GEMSTONE = 7,
	BANKEX_SMALLSTONE = 8,
	BANKEX_BIGSTONE = 9,
};

struct PMSG_JEWELBANK
{
	PBMSG_HEAD3 h;
	int Result;
};

void JewelBankDataSend(int aIndex);

class CBankEx
{
public:
	CBankEx();
	virtual ~CBankEx();
	void Make(int aIndex, int Count, int Type);
	void Change(int aIndex, int Count, int Type);
}; extern CBankEx gBankEx;