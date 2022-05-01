// CustomJewel.cpp: implementation of the CCustomJewel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomJewel.h"
#include "CustomWing.h"
#include "ItemManager.h"
#include "MemScript.h"
#include "ObjectManager.h"
#include "ServerInfo.h"
#include "SetItemType.h"
#include "SocketItemType.h"
#include "Util.h"

CCustomJewel gCustomJewel;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomJewel::CCustomJewel() // OK
{
	this->Init();
}

CCustomJewel::~CCustomJewel() // OK
{

}

void CCustomJewel::Init(){
	for (int n = 0; n < MAX_CUSTOM_JEWEL; n++){
		this->m_CustomJewelInfo[n].Index = -1;
	}
	this->m_UpgradeInfo.clear();
}

void CCustomJewel::Load(char* path){
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->Init();
	pugi::xml_node oStartJewel = file.child("CustomJewels");

	pugi::xml_node eJewelInfo = oStartJewel.child("JewelInfo");
	for (pugi::xml_node xJewelInfo = eJewelInfo.child("Jewel"); xJewelInfo; xJewelInfo = xJewelInfo.next_sibling()){
		CUSTOM_JEWEL_INFO info;
		memset(&info, 0, sizeof(info));
		info.Index = xJewelInfo.attribute("Index").as_int();
		info.ItemIndex = xJewelInfo.attribute("ItemIndex").as_int();
		info.MinItemLevel = xJewelInfo.attribute("MinItemLevel").as_int();
		info.MaxItemLevel = xJewelInfo.attribute("MaxItemLevel").as_int();
		info.MaxItemOption1 = xJewelInfo.attribute("MaxItemOption1").as_int();
		info.MaxItemOption2 = xJewelInfo.attribute("MaxItemOption2").as_int();
		info.MinItemOption3 = xJewelInfo.attribute("MinItemOption3").as_int();
		info.MaxItemOption3 = xJewelInfo.attribute("MaxItemOption3").as_int();
		info.MinItemNewOption = xJewelInfo.attribute("MinItemNewOption").as_int();
		info.MaxItemNewOption = xJewelInfo.attribute("MaxItemNewOption").as_int();
		info.MaxItemSetOption = xJewelInfo.attribute("MaxItemSetOption").as_int();
		info.MinItemSocketOption = xJewelInfo.attribute("MinItemSocketOption").as_int();
		info.MaxItemSocketOption = xJewelInfo.attribute("MaxItemSocketOption").as_int();
		info.EnableSlotWeapon = xJewelInfo.attribute("EnableSlotWeapon").as_int();
		info.EnableSlotArmor = xJewelInfo.attribute("EnableSlotArmor").as_int();
		info.EnableSlotWing = xJewelInfo.attribute("EnableSlotWing").as_int();
		info.SuccessRate[0] = xJewelInfo.attribute("SuccessRate_AL0").as_int();
		info.SuccessRate[1] = xJewelInfo.attribute("SuccessRate_AL1").as_int();
		info.SuccessRate[2] = xJewelInfo.attribute("SuccessRate_AL2").as_int();
		info.SuccessRate[3] = xJewelInfo.attribute("SuccessRate_AL3").as_int();
		info.SalePrice = xJewelInfo.attribute("SalePrice").as_int();
		strcpy_s(info.ModelName, xJewelInfo.attribute("ModelName").as_string());
		this->SetInfo(info);
	}

	pugi::xml_node eJewelSuccess = oStartJewel.child("JewelSuccess");
	for (pugi::xml_node xJewelSuccess = eJewelSuccess.child("Jewel"); xJewelSuccess; xJewelSuccess = xJewelSuccess.next_sibling()){
		CUSTOM_JEWEL_SUCCESS_INFO info;
		memset(&info, 0, sizeof(info));
		info.Index = xJewelSuccess.attribute("Index").as_int();
		info.Level = xJewelSuccess.attribute("Level").as_int();
		info.Option1 = xJewelSuccess.attribute("Option1").as_int();
		info.Option2 = xJewelSuccess.attribute("Option2").as_int();
		info.Option3 = xJewelSuccess.attribute("Option3").as_int();
		info.NewOption = xJewelSuccess.attribute("NewOption").as_int();
		info.SetOption = xJewelSuccess.attribute("SetOption").as_int();
		info.SocketOption = xJewelSuccess.attribute("SocketOption").as_int();
		this->SetSuccessInfo(info);
	}

	pugi::xml_node eJewelFailure = oStartJewel.child("JewelFail");
	for (pugi::xml_node xJewelFailure = eJewelFailure.child("Jewel"); xJewelFailure; xJewelFailure = xJewelFailure.next_sibling()){
		CUSTOM_JEWEL_FAILURE_INFO info;
		memset(&info, 0, sizeof(info));
		info.Index = xJewelFailure.attribute("Index").as_int();
		info.Level = xJewelFailure.attribute("Level").as_int();
		info.Option1 = xJewelFailure.attribute("Option1").as_int();
		info.Option2 = xJewelFailure.attribute("Option2").as_int();
		info.Option3 = xJewelFailure.attribute("Option3").as_int();
		info.NewOption = xJewelFailure.attribute("NewOption").as_int();
		info.SetOption = xJewelFailure.attribute("SetOption").as_int();
		info.SocketOption = xJewelFailure.attribute("SocketOption").as_int();
		this->SetFailureInfo(info);
	}

	pugi::xml_node eJewelUpgrade = oStartJewel.child("JewelUpgrade");
	for (pugi::xml_node xJewelUpgrade = eJewelUpgrade.child("Jewel"); xJewelUpgrade; xJewelUpgrade = xJewelUpgrade.next_sibling()){
		CUSTOM_JEWEL_UPGRADE_INFO info;
		memset(&info, 0, sizeof(info));
		info.Index = xJewelUpgrade.attribute("Index").as_int();
		info.ItemOld = xJewelUpgrade.attribute("ItemIndexOld").as_int();
		info.ItemNew = xJewelUpgrade.attribute("ItemIndexNew").as_int();
		this->m_UpgradeInfo.push_back(info);
	}
}

void CCustomJewel::SetInfo(CUSTOM_JEWEL_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_JEWEL)
	{
		return;
	}

	this->m_CustomJewelInfo[info.Index] = info;
}

void CCustomJewel::SetSuccessInfo(CUSTOM_JEWEL_SUCCESS_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_JEWEL)
	{
		return;
	}

	this->m_CustomJewelInfo[info.Index].SuccessInfo = info;
}

void CCustomJewel::SetFailureInfo(CUSTOM_JEWEL_FAILURE_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_JEWEL)
	{
		return;
	}

	this->m_CustomJewelInfo[info.Index].FailureInfo = info;
}

CUSTOM_JEWEL_INFO* CCustomJewel::GetInfo(int index) // OK
{
	if (index < 0 || index >= MAX_CUSTOM_JEWEL)
	{
		return 0;
	}

	if (this->m_CustomJewelInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomJewelInfo[index];
}

CUSTOM_JEWEL_INFO* CCustomJewel::GetInfoByItem(int ItemIndex) // OK
{
	for (int n = 0; n < MAX_CUSTOM_JEWEL; n++)
	{
		CUSTOM_JEWEL_INFO* lpInfo = this->GetInfo(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}

	return 0;
}

CUSTOM_JEWEL_SUCCESS_INFO* CCustomJewel::GetSuccessInfo(int ItemIndex) // OK
{
	CUSTOM_JEWEL_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return &lpInfo->SuccessInfo;
}

CUSTOM_JEWEL_FAILURE_INFO* CCustomJewel::GetFailureInfo(int ItemIndex) // OK
{
	CUSTOM_JEWEL_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return &lpInfo->FailureInfo;
}

bool CCustomJewel::CheckCustomJewel(int index) // OK
{
	if (this->GetInfo(index) != 0)
	{
		return 1;
	}

	return 0;
}

bool CCustomJewel::CheckCustomJewelByItem(int ItemIndex) // OK
{
	if (this->GetInfoByItem(ItemIndex) != 0)
	{
		return 1;
	}

	return 0;
}

bool CCustomJewel::CheckCustomJewelApplyItem(int ItemIndex, CItem* lpItem) // OK
{
	CUSTOM_JEWEL_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	if (lpItem->IsLuckyItem() != 0)
	{
		return 0;
	}

	//if(lpItem->IsJewelOfHarmonyItem() == 0 && (lpInfo->MinItemSocketOption > 0 || lpInfo->MaxItemSocketOption > 0))
	//{
	//	return 0;
	//}

	if (lpItem->m_Index > GET_ITEM(12, 6) && (lpItem->m_Index < GET_ITEM(12, 36) || lpItem->m_Index > GET_ITEM(12, 43)) && lpItem->m_Index != GET_ITEM(12, 49) && lpItem->m_Index != GET_ITEM(12, 50) && (lpItem->m_Index < GET_ITEM(12, 200) || lpItem->m_Index > GET_ITEM(12, 265)) && lpItem->m_Index != GET_ITEM(13, 30) && gCustomWing.CheckCustomWingByItem(lpItem->m_Index) == 0)
	{
		return 0;
	}

	if (lpInfo->EnableSlotWeapon == 0 && (lpItem->m_Index >= GET_ITEM(0, 0) && lpItem->m_Index < GET_ITEM(6, 0)))
	{
		return 0;
	}

	if (lpInfo->EnableSlotArmor == 0 && (lpItem->m_Index >= GET_ITEM(6, 0) && lpItem->m_Index < GET_ITEM(12, 0)))
	{
		return 0;
	}

	if (lpInfo->EnableSlotWing == 0 && ((lpItem->m_Index >= GET_ITEM(12, 0) && lpItem->m_Index <= GET_ITEM(12, 6)) || (lpItem->m_Index >= GET_ITEM(12, 36) && lpItem->m_Index <= GET_ITEM(12, 43)) || lpItem->m_Index == GET_ITEM(12, 49) || lpItem->m_Index == GET_ITEM(12, 50) || (lpItem->m_Index >= GET_ITEM(12, 262) && lpItem->m_Index <= GET_ITEM(12, 265)) || lpItem->m_Index == GET_ITEM(13, 30) || gCustomWing.CheckCustomWingByItem(lpItem->m_Index) != 0))
	{
		return 0;
	}

	if (lpInfo->MinItemLevel != -1 && lpItem->m_Level < lpInfo->MinItemLevel)
	{
		return 0;
	}

	if (lpInfo->MaxItemLevel != -1 && lpItem->m_Level > lpInfo->MaxItemLevel)
	{
		return 0;
	}

	ITEM_INFO ItemInfo;

	if (gItemManager.GetInfo(lpItem->m_Index, &ItemInfo) == 0)
	{
		return 0;
	}

	if (lpInfo->MaxItemOption1 != -1 && (lpItem->m_Option1 > lpInfo->MaxItemOption1 || ItemInfo.Skill == 0))
	{
		return 0;
	}

	if (lpInfo->MaxItemOption2 != -1 && lpItem->m_Option2 > lpInfo->MaxItemOption2)
	{
		return 0;
	}

	if (lpInfo->MinItemOption3 != -1 && lpItem->m_Option3 < lpInfo->MinItemOption3)
	{
		return 0;
	}

	if (lpInfo->MaxItemOption3 != -1 && lpItem->m_Option3 > lpInfo->MaxItemOption3)
	{
		return 0;
	}

	if (this->CheckCustomJewelApplyItemNewOption(lpInfo, lpItem) == 0)
	{
		return 0;
	}

	if (this->CheckCustomJewelApplyItemSetOption(lpInfo, lpItem) == 0)
	{
		return 0;
	}

	if (this->CheckCustomJewelApplyItemSocketOption(lpInfo, lpItem) == 0)
	{
		return 0;
	}

	return 1;
}

bool CCustomJewel::CheckCustomJewelApplyItemNewOption(CUSTOM_JEWEL_INFO* lpInfo, CItem* lpItem) // OK
{
	if (lpInfo->MinItemNewOption != -1 && GetNewOptionCount(lpItem->m_NewOption) < lpInfo->MinItemNewOption)
	{
		return 0;
	}

	if (lpInfo->MaxItemNewOption != -1 && lpInfo->MaxItemNewOption > 10 && (lpItem->m_NewOption & (lpInfo->MaxItemNewOption - 10)) != 0)
	{
		return 0;
	}

	if (lpInfo->MaxItemNewOption != -1 && lpInfo->MaxItemNewOption < 10 && GetNewOptionCount(lpItem->m_NewOption) > lpInfo->MaxItemNewOption)
	{
		return 0;
	}

	return 1;
}

bool CCustomJewel::CheckCustomJewelApplyItemSetOption(CUSTOM_JEWEL_INFO* lpInfo, CItem* lpItem) // OK
{
	if (lpInfo->MaxItemSetOption != -1 && (lpItem->IsSetItem() != 0 || ((lpInfo->MaxItemSetOption & 1) != 0 && gSetItemType.GetSetItemOptionIndex(lpItem->m_Index, 0) <= 0)))
	{
		return 0;
	}

	if (lpInfo->MaxItemSetOption != -1 && (lpItem->IsSetItem() != 0 || ((lpInfo->MaxItemSetOption & 2) != 0 && gSetItemType.GetSetItemOptionIndex(lpItem->m_Index, 1) <= 0)))
	{
		return 0;
	}

	return 1;
}

bool CCustomJewel::CheckCustomJewelApplyItemSocketOption(CUSTOM_JEWEL_INFO* lpInfo, CItem* lpItem) // OK
{
	if (gServerInfo.m_JewelSocketPentagram == 1 && (lpItem->m_Index >= GET_ITEM(12, 200) && lpItem->m_Index <= GET_ITEM(12, 214)) && GetSocketOptionCount(lpItem->m_SocketOption) < 5)
	{
		return 1;
	}
	if (lpInfo->MinItemSocketOption != -1 && ((lpInfo->MinItemSocketOption == 0 && gSocketItemType.CheckSocketItemType(lpItem->m_Index) == 0) || (lpInfo->MinItemSocketOption != 0 && (gSocketItemType.CheckSocketItemType(lpItem->m_Index) == 0 || GetSocketOptionCount(lpItem->m_SocketOption) < lpInfo->MinItemSocketOption))))
	{
		return 0;
	}

	if (lpInfo->MaxItemSocketOption != -1 && ((lpInfo->MaxItemSocketOption == 0 && gSocketItemType.CheckSocketItemType(lpItem->m_Index) == 0) || (lpInfo->MaxItemSocketOption != 0 && (gSocketItemType.CheckSocketItemType(lpItem->m_Index) == 0 || GetSocketOptionCount(lpItem->m_SocketOption) > lpInfo->MaxItemSocketOption || GetSocketOptionCount(lpItem->m_SocketOption) >= gSocketItemType.GetSocketItemMaxSocket(lpItem->m_Index)))))
	{
		return 0;
	}

	return 1;
}

int CCustomJewel::GetCustomJewelSuccessRate(int ItemIndex, int AccountLevel) // OK
{
	CUSTOM_JEWEL_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return lpInfo->SuccessRate[AccountLevel];
}

int CCustomJewel::GetCustomJewelSalePrice(int ItemIndex) // OK
{
	CUSTOM_JEWEL_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo == 0)
	{
		return 0;
	}

	return lpInfo->SalePrice;
}

int CCustomJewel::GetCustomJewelNewOption(CItem* lpItem, int value) // OK
{
	if (value >= 10)
	{
		return (lpItem->m_NewOption = (lpItem->m_NewOption | (value - 10)));
	}

	int count = 0;

	int MaxNewOption = MAX_EXC_OPTION;

	if ((lpItem->m_Index >= GET_ITEM(12, 3) && lpItem->m_Index <= GET_ITEM(12, 6)) || lpItem->m_Index == GET_ITEM(12, 42) || lpItem->m_Index == GET_ITEM(12, 49) || lpItem->m_Index == GET_ITEM(13, 30)) // 2sd Wings
	{
		MaxNewOption = ((lpItem->m_Index == GET_ITEM(13, 30)) ? 4 : 3);
	}

	if ((lpItem->m_Index >= GET_ITEM(12, 36) && lpItem->m_Index <= GET_ITEM(12, 40)) || lpItem->m_Index == GET_ITEM(12, 43) || lpItem->m_Index == GET_ITEM(12, 50)) // 3rd Wings
	{
		MaxNewOption = 4;
	}

	if (lpItem->m_Index >= GET_ITEM(12, 262) && lpItem->m_Index <= GET_ITEM(12, 265)) // Monster Wings
	{
		MaxNewOption = 2;
	}

	if (lpItem->m_Index == GET_ITEM(12, 266)) // Wings of Conqueror
	{
		MaxNewOption = 3;
	}

	if (lpItem->m_Index == GET_ITEM(12, 267)) // Wings of Angel and Devil
	{
		MaxNewOption = 3;
	}

	if (gCustomWing.CheckCustomWingByItem(lpItem->m_Index) != 0)
	{
		MaxNewOption = 4;
	}

	if (lpItem->m_Index == GET_ITEM(13, 3)) // Dinorant
	{
		MaxNewOption = 3;
	}

	if (lpItem->m_Index == GET_ITEM(13, 37)) // Fenrir
	{
		MaxNewOption = 3;
	}

	while (true)
	{
		if (count >= value || GetNewOptionCount(lpItem->m_NewOption) >= MaxNewOption)
		{
			break;
		}

		int option = 1 << (GetLargeRand() % MaxNewOption);

		if ((lpItem->m_NewOption & option) == 0)
		{
			lpItem->m_NewOption |= option;
			count++;
		}
	}

	return count;
}

int CCustomJewel::GetCustomJewelSetOption(CItem* lpItem, int value) // OK
{
	BYTE SetIndex = lpItem->m_SetOption & 3;
	BYTE SetValue = lpItem->m_SetOption & 12;

	if (SetIndex == 0)
	{
		for (int n = 0; n < MAX_SET_ITEM_OPTION_INDEX; n++)
		{
			if ((value & (1 << n)) != 0 && gSetItemType.GetSetItemOptionIndex(lpItem->m_Index, n) > 0)
			{
				SetIndex = ((SetIndex == 0) ? (n + 1) : (((GetLargeRand() % 2) == 0) ? (n + 1) : SetIndex));
			}
		}
	}

	if (SetValue == 0 && SetIndex > 0 && (value & 4) != 0)
	{
		SetValue = 4;
	}

	if (SetValue == 4 && SetIndex > 0 && (value & 8) != 0)
	{
		SetValue = 8;
	}

	return ((lpItem->m_SetOption) = (SetIndex + SetValue));
}

int CCustomJewel::GetCustomJewelSocketOption(CItem* lpItem, int value) // OK
{
	int count = 0;

	for (int n = 0; n < MAX_SOCKET_OPTION; n++)
	{
		if (count < value && lpItem->m_SocketOption[n] == 0xFF)
		{
			lpItem->m_SocketOption[n] = 0xFE;
			count++;
		}
	}

	return count;
}

bool CCustomJewel::CharacterUseCustomJewel(LPOBJ lpObj, int SourceSlot, int TargetSlot){
	if (INVENTORY_FULL_RANGE(SourceSlot) == 0)
	{
		return 0;
	}

	if (INVENTORY_FULL_RANGE(TargetSlot) == 0)
	{
		return 0;
	}

	if (lpObj->Inventory[SourceSlot].IsItem() == 0)
	{
		return 0;
	}

	if (lpObj->Inventory[TargetSlot].IsItem() == 0)
	{
		return 0;
	}

	if (lpObj->Inventory[TargetSlot].m_IsPeriodicItem != 0)
	{
		return 0;
	}

	CItem* lpItem = &lpObj->Inventory[TargetSlot];

	if (gCustomJewel.CheckCustomJewelApplyItem(lpObj->Inventory[SourceSlot].m_Index, lpItem) == 0)
	{
		return 0;
	}

	if ((GetLargeRand() % 100) < gCustomJewel.GetCustomJewelSuccessRate(lpObj->Inventory[SourceSlot].m_Index, lpObj->AccountLevel))
	{
		CUSTOM_JEWEL_SUCCESS_INFO* lpInfo = gCustomJewel.GetSuccessInfo(lpObj->Inventory[SourceSlot].m_Index);
		for (std::vector<CUSTOM_JEWEL_UPGRADE_INFO>::iterator it = this->m_UpgradeInfo.begin(); it != this->m_UpgradeInfo.end(); it++)
		{
			if (it->Index == lpInfo->Index)
			{
				if (lpItem->m_Index == it->ItemOld)
				{
					GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemNew, lpInfo->Level, (BYTE)lpObj->Inventory[TargetSlot].m_Durability, lpInfo->Option1, lpInfo->Option2, lpInfo->Option3, lpObj->Index, lpInfo->NewOption, lpInfo->SetOption, 0, 0, 0, 0xFF, 0);
					gItemManager.InventoryDelItem(lpObj->Index, SourceSlot);
					gItemManager.GCItemDeleteSend(lpObj->Index, SourceSlot, 1);
					gItemManager.InventoryDelItem(lpObj->Index, TargetSlot);
					gItemManager.GCItemDeleteSend(lpObj->Index, TargetSlot, 1);
				}
			}

			gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);
		}

		lpItem->m_Level = (((lpItem->m_Level + lpInfo->Level)>15) ? 15 : (lpItem->m_Level + lpInfo->Level));

		lpItem->m_Option1 = (((lpItem->m_Option1 + lpInfo->Option1)>1) ? 1 : (lpItem->m_Option1 + lpInfo->Option1));

		lpItem->m_Option2 = (((lpItem->m_Option2 + lpInfo->Option2)>1) ? 1 : (lpItem->m_Option2 + lpInfo->Option2));

		lpItem->m_Option3 = (((lpItem->m_Option3 + lpInfo->Option3)>gServerInfo.m_MaxItemOption) ? gServerInfo.m_MaxItemOption : (lpItem->m_Option3 + lpInfo->Option3));

		gCustomJewel.GetCustomJewelNewOption(lpItem, lpInfo->NewOption);

		gCustomJewel.GetCustomJewelSetOption(lpItem, lpInfo->SetOption);

		gCustomJewel.GetCustomJewelSocketOption(lpItem, lpInfo->SocketOption);

		float dur = (float)gItemManager.GetItemDurability(lpItem->m_Index, lpItem->m_Level, lpItem->IsExcItem(), lpItem->IsSetItem());

		lpItem->m_Durability = (dur*lpItem->m_Durability) / lpItem->m_BaseDurability;

		lpItem->Convert(lpItem->m_Index, lpItem->m_Option1, lpItem->m_Option2, lpItem->m_Option3, lpItem->m_NewOption, lpItem->m_SetOption, lpItem->m_JewelOfHarmonyOption, lpItem->m_ItemOptionEx, lpItem->m_SocketOption, lpItem->m_SocketOptionBonus);

		gItemManager.InventoryDelItem(lpObj->Index, SourceSlot);

		gItemManager.GCItemDeleteSend(lpObj->Index, SourceSlot, 1);

		gItemManager.GCItemModifySend(lpObj->Index, TargetSlot);

		gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);
	}
	else
	{
		CUSTOM_JEWEL_FAILURE_INFO* lpInfo = gCustomJewel.GetFailureInfo(lpObj->Inventory[SourceSlot].m_Index);

		lpItem->m_Level = (((lpItem->m_Level - lpInfo->Level)<0) ? 0 : (lpItem->m_Level - lpInfo->Level));

		lpItem->m_Option1 = (((lpItem->m_Option1 - lpInfo->Option1)<0) ? 0 : (lpItem->m_Option1 - lpInfo->Option1));

		lpItem->m_Option2 = (((lpItem->m_Option2 - lpInfo->Option2)<0) ? 0 : (lpItem->m_Option2 - lpInfo->Option2));

		lpItem->m_Option3 = (((lpItem->m_Option3 - lpInfo->Option3)<0) ? 0 : (lpItem->m_Option3 - lpInfo->Option3));

		float dur = (float)gItemManager.GetItemDurability(lpItem->m_Index, lpItem->m_Level, lpItem->IsExcItem(), lpItem->IsSetItem());

		lpItem->m_Durability = (dur*lpItem->m_Durability) / lpItem->m_BaseDurability;

		lpItem->Convert(lpItem->m_Index, lpItem->m_Option1, lpItem->m_Option2, lpItem->m_Option3, lpItem->m_NewOption, lpItem->m_SetOption, lpItem->m_JewelOfHarmonyOption, lpItem->m_ItemOptionEx, lpItem->m_SocketOption, lpItem->m_SocketOptionBonus);

		gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);

		gItemManager.InventoryDelItem(lpObj->Index, SourceSlot);

		gItemManager.GCItemDeleteSend(lpObj->Index, SourceSlot, 1);

		gItemManager.GCItemModifySend(lpObj->Index, TargetSlot);
	}

	return 1;
}