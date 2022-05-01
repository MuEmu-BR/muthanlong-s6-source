#include "stdafx.h"
#include "JewelBank.h"
#include "GameMain.h"
#include "ItemManager.h"
#include "ServerInfo.h"
#include "Notice.h"
#include "Util.h"

CBankEx gBankEx;

CBankEx::CBankEx()
{

}

CBankEx::~CBankEx()
{

}

struct JEWELBANK_UPDATE
{
	PBMSG_HEAD3 h;
	int JMoney;
	int JBless;
	int JSoul;
	int JChaos;
	int JCreation;
	int JLife;
	int JHarmony;
	int JGuaStone;
	int JGemStone;
	int JBigStone;
	int JSmallStone;
};

void JewelBankDataSend(int aIndex)
{
	JEWELBANK_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 14, sizeof(rSend));

	rSend.JMoney = lpObj->JMoney;
	rSend.JBless = lpObj->JBless;
	rSend.JSoul = lpObj->JSoul;
	rSend.JChaos = lpObj->JChaos;
	rSend.JCreation = lpObj->JCreation;
	rSend.JLife = lpObj->JLife;
	rSend.JHarmony = lpObj->JHarmony;
	rSend.JGuaStone = lpObj->JGuaStone;
	rSend.JGemStone = lpObj->JGemStone;
	rSend.JBigStone = lpObj->JBigStone;
	rSend.JSmallStone = lpObj->JSmallStone;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}