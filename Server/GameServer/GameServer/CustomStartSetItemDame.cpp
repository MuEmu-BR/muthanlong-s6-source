#include "StdAfx.h"
#include "CustomStartSetItemDame.h"
#include "DSProtocol.h"
#include "MemScript.h"
#include "Util.h"
#include "ItemManager.h"
#include "CashShop.h"
#include "User.h"
#include "Notice.h"
#include "Message.h"
#include "ServerInfo.h"
#include "Path.h"
#include "ObjectManager.h"

#if(BUFFSETDAME == 1)

CCustomStartSetItemDame gCustomStartSetItemDame;

CCustomStartSetItemDame::CCustomStartSetItemDame()
{
	this->Init();
}

CCustomStartSetItemDame::~CCustomStartSetItemDame()
{
}

void CCustomStartSetItemDame::Init()
{
	this->itemdata.clear();
	this->setitemdata.clear();
}

void CCustomStartSetItemDame::Load()
{
	this->Init();
	this->Read(gPath.GetFullPath("VanThanh\\CustomBonusItem.txt"));
}

void CCustomStartSetItemDame::Read(char* path)
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

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CustomStartItemDame_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					this->itemdata.push_back(info);
				}

				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					CustomStartSetItemDame_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					info.HP = lpMemScript->GetAsNumber();

					info.Def = lpMemScript->GetAsNumber();

					info.DefRate = lpMemScript->GetAsNumber();
					this->setitemdata.push_back(info);
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CCustomStartSetItemDame::CalcCustomSetItemOption(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	CItem* lpItemTayPhai = &lpObj->Inventory[0];
	CItem* lpItemTayTrai = &lpObj->Inventory[1];
	//2 mũ 3 áo 4 quần 5 găng 6 giầy
	CItem* lpItemHelm = &lpObj->Inventory[2];
	CItem* lpItemArmor = &lpObj->Inventory[3];
	CItem* lpItemPant = &lpObj->Inventory[4];
	CItem* lpItemGloves = &lpObj->Inventory[5];
	CItem* lpItemBoot = &lpObj->Inventory[6];
	CItem* lpItemWing = &lpObj->Inventory[7]; // Wings
	CItem* lpItemPet = &lpObj->Inventory[8]; // Pet
	CItem* lpItemPedan = &lpObj->Inventory[9]; // Pedan
	CItem* lpItemRing = &lpObj->Inventory[10]; // Ring
	CItem* lpItemRing1 = &lpObj->Inventory[11]; // Ring

	for (std::vector<CustomStartItemDame_Data>::iterator it = gCustomStartSetItemDame.itemdata.begin(); it != gCustomStartSetItemDame.itemdata.end(); it++)
	{
		//-----
		if (lpItemTayPhai->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemTayPhai->m_Level >= it->Level && lpItemTayPhai->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
			}
		}
		//-----
		if (lpItemTayTrai->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemTayTrai->m_Level >= it->Level && lpItemTayTrai->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
			}
		}
	}

	for (std::vector<CustomStartSetItemDame_Data>::iterator it = gCustomStartSetItemDame.setitemdata.begin(); it != gCustomStartSetItemDame.setitemdata.end(); it++)
		{
		//-----
		if (lpItemHelm->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemHelm->m_Level >= it->Level && lpItemHelm->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemArmor->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemArmor->m_Level >= it->Level && lpItemArmor->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemPant->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemPant->m_Level >= it->Level && lpItemPant->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemGloves->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemGloves->m_Level >= it->Level && lpItemGloves->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemBoot->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemBoot->m_Level >= it->Level && lpItemBoot->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemWing->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemWing->m_Level >= it->Level && lpItemWing->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemPet->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemPet->m_Level >= it->Level && lpItemPet->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemPedan->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemPedan->m_Level >= it->Level && lpItemPedan->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemRing->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemRing->m_Level >= it->Level && lpItemRing->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}
		//-----
		if (lpItemRing1->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemRing1->m_Level >= it->Level && lpItemRing1->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->MagicDamageMin += it->Dame;
				lpObj->MagicDamageMax += it->Dame;
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				lpObj->AddLife += it->HP;
				lpObj->Defense += it->Def;
				lpObj->DoubleDamageRate += it->DefRate;
			}
		}

	}
}

#endif