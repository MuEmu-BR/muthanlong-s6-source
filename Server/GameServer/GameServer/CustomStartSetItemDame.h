#pragma once

#include "StdAfx.h"
#include "Protocol.h"

#if(BUFFSETDAME == 1)

struct CustomStartItemDame_Data
{
	int ItemType;
	int ItemIndex;
	int Level;
	int Option;
	int Dame;
};

struct CustomStartSetItemDame_Data
{
	int ItemType;
	int ItemIndex;
	int Level;
	int Option;
	int Dame;
	int HP;
	int Def;
	int DefRate;
};


class CCustomStartSetItemDame
{
public:
	CCustomStartSetItemDame();
	~CCustomStartSetItemDame();
	void Init();
	void Load();
	void Read(char* filename);
	void CalcCustomSetItemOption(LPOBJ lpObj, bool flag);
	std::vector<CustomStartSetItemDame_Data> setitemdata;
	std::vector<CustomStartItemDame_Data> itemdata;
};
extern CCustomStartSetItemDame gCustomStartSetItemDame;

#endif