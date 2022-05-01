#pragma once
#define pGetItemBmdStruct(ItemId)   (ItemBmdStruct1*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct1) * ItemId)
#define SET_ITEMOPT_LEVEL(x)  (x << 3)
#define pGetItemAtt(id, offset)		(*(DWORD*)0x8128AC0 + 84 * id + offset)
struct ItemBmdStruct1
{
	char Name[30];
	/*+30*/ BYTE TwoHand;
	/*+31*/ BYTE gap01;
	/*+32*/ BYTE ItemLvl;
	/*+33*/ BYTE gap02;
	/*+34*/ BYTE Slot;
	/*+35*/ BYTE gap03;
	/*+36*/ BYTE Skill;
	/*+37*/ BYTE gap04;
	/*+38*/ BYTE ItemWidth;
	/*+39*/ BYTE ItemHeight;
	/*+40*/ BYTE MinDmg;
	/*+41*/ BYTE MaxDmg;
	/*+42*/ BYTE gap05;
	/*+43*/ BYTE Defence;
	/*+44*/ BYTE gap06;
	/*+45*/ BYTE Speed;
	/*+46*/ BYTE gap07;
	/*+47*/ BYTE Dur;
	/*+48*/ BYTE MagicDur;
	/*+49*/ BYTE MagicPwr;
	/*+50*/ BYTE ReqStr;
	/*+51*/ BYTE ReqStrValue;
	/*+52*/ BYTE ReqAgi;
	/*+53*/ BYTE ReqAgiValue;
	/*+54*/ BYTE ReqEne;
	/*+55*/ BYTE ReqEneValue;
	/*+56*/ BYTE ReqVit;
	/*+57*/ BYTE ReqVitValue;
	/*+58*/ BYTE ReqCmd; //ReqCmd = ReqCmd+(ReqCmdValue*256)
	/*+59*/ BYTE ReqCmdValue;
	/*+60*/ BYTE ReqLvl;
	/*+60*/ BYTE gap08[3];
	/*+63*/ unsigned int Money;
	/*+67*/ BYTE Type;
	/*+68*/ BYTE DW;
	/*+69*/ BYTE DK;
	/*+70*/ BYTE ELF;
	/*+71*/ BYTE MG;
	/*+72*/ BYTE DL;
	/*+73*/ BYTE Sum;
	/*+74*/ BYTE RF;
	BYTE Resists[8];
};

class JewelBank
{
public:

	void		Open_Window_JewelBank() { gInterface.Data[eJEWELBANK_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		Close_Window_JewelBank() { gInterface.Data[eJEWELBANK_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		Check_Window_JewelBank() { return gInterface.Data[eJEWELBANK_MAIN].OnShow; };


	void Bind();
	void DrawJewelBank();
	void DrawLine(int ItemType, int ItemIndex, int ItemLevel, float DrawX, float DrawY, char * ItemName, int Count);
	void DrawLineTaiSinh(int ItemType, int ItemIndex, int ItemLevel, float DrawX, float DrawY, char * ItemName, int Count);
	void DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count);
	void DrawItem(int ItemType, int ItemIndex, int ItemLevel);
	bool JewelBankEvent(DWORD Event);
	//
	bool ClickZenMinus(DWORD Event);
	bool ClickZenPlus(DWORD Event);

	bool ClickChaosMinus(DWORD Event);
	bool ClickChaosMinus10(DWORD Event);
	bool ClickChaosMinus20(DWORD Event);
	bool ClickChaosMinus30(DWORD Event);

	bool ClickBlessMinus(DWORD Event);
	bool ClickBlessMinus10(DWORD Event);
	bool ClickBlessMinus20(DWORD Event);
	bool ClickBlessMinus30(DWORD Event);

	bool ClickSoulMinus(DWORD Event);
	bool ClickSoulMinus10(DWORD Event);
	bool ClickSoulMinus20(DWORD Event);
	bool ClickSoulMinus30(DWORD Event);

	bool ClickLifeMinus(DWORD Event);
	bool ClickLifeMinus10(DWORD Event);
	bool ClickLifeMinus20(DWORD Event);
	bool ClickLifeMinus30(DWORD Event);

	bool ClickCreMinus(DWORD Event);
	bool ClickCreMinus10(DWORD Event);
	bool ClickCreMinus20(DWORD Event);
	bool ClickCreMinus30(DWORD Event);

	bool ClickGemMinus(DWORD Event);
	bool ClickGemMinus10(DWORD Event);
	bool ClickGemMinus20(DWORD Event);
	bool ClickGemMinus30(DWORD Event);

	bool ClickGem1Minus(DWORD Event);
	bool ClickGem1Minus10(DWORD Event);
	bool ClickGem1Minus20(DWORD Event);
	bool ClickGem1Minus30(DWORD Event);

	bool ClickGem2Minus(DWORD Event);
	bool ClickGem2Minus10(DWORD Event);
	bool ClickGem2Minus20(DWORD Event);
	bool ClickGem2Minus30(DWORD Event);

	bool ClickGem3Minus(DWORD Event);
	bool ClickGem3Minus10(DWORD Event);
	bool ClickGem3Minus20(DWORD Event);
	bool ClickGem3Minus30(DWORD Event);

	bool ClickGem4Minus(DWORD Event);
	bool ClickGem4Minus10(DWORD Event);
	bool ClickGem4Minus20(DWORD Event);
	bool ClickGem4Minus30(DWORD Event);
	//
};
extern JewelBank gJewelBank;