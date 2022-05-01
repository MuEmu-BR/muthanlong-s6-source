#include "stdafx.h"
#include "user.h"
#include "ChoTroi.h"
#include "protocol.h"
#include "GameMain.h"
#include "Util.h"
#include "ItemManager.h"
#include "CashShop.h"
#include "Notice.h"
#include "DSProtocol.h"
#include "Message.h"
#include "Path.h"

#if(DEV_PLAYERSHOP == 1)

CChoTroi g_ChoTroi;

CChoTroi::CChoTroi()
{
	this->Init();
}

CChoTroi::~CChoTroi()
{
}

void CChoTroi::Init()
{

}

void CChoTroi::Load()
{
	this->ThuPhiZen = GetPrivateProfileInt("Config", "ThuPhiZen", 0, gPath.GetFullPath("VanThanh\\ChoTroi.ini"));
	this->ThuPhiWCoinC = GetPrivateProfileInt("Config", "ThuPhiWCoinC", 0, gPath.GetFullPath("VanThanh\\ChoTroi.ini"));
	this->ThuPhiWCoinP = GetPrivateProfileInt("Config", "ThuPhiWCoinP", 0, gPath.GetFullPath("VanThanh\\ChoTroi.ini"));
}

void CChoTroi::Protocol(BYTE protoNum, BYTE *aRecv)
{

}

void CChoTroi::CGReqItemList(PMSG_REQ_MARKET_ITEM* lpMsg, int aIndex)
{
	SDHP_REQ_MARKET_ITEM pMsg;

	pMsg.h.set((LPBYTE)&pMsg, 0xEC, 0x00, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = aIndex;

	pMsg.PriceType = lpMsg->PriceType;

#if(MARKET_FILTER_DEV)

	pMsg.Filter.FilterType = lpMsg->Filter.FilterType;

	pMsg.Filter.FilterLevel = lpMsg->Filter.FilterLevel;

	pMsg.Filter.FilterLuck = lpMsg->Filter.FilterLuck;

	pMsg.Filter.FilterExl = lpMsg->Filter.FilterExl;

	pMsg.Filter.FilterAnc = lpMsg->Filter.FilterAnc;

#endif

#if(MARKET_PAGE_DEV)

	pMsg.PageNumber = lpMsg->PageNumber;

#endif

	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void CChoTroi::GDReqItemList(int aIndex, int NumPage)
{

}

void CChoTroi::DGAnsItemList(SDHP_ANS_MARKET_ITEM* lpMsg)
{
	int aIndex = lpMsg->aIndex;

	// ----

	memset(this->m_MarketData[aIndex], 0, sizeof(this->m_MarketData[aIndex]));

	memcpy(this->m_MarketData[aIndex], lpMsg->Data, sizeof(this->m_MarketData[aIndex]));

	// ----

	PMSG_ANS_MARKET_ITEM pMsg;

	memset(&pMsg, 0, sizeof(pMsg));

	pMsg.h.set((LPBYTE)&pMsg, 0xFA, 0xF5, sizeof(pMsg));

	pMsg.Result = 1;

	CItem item;

	for (int i = 0; i < MARKET_ITEM_MAX; i++)
	{
		pMsg.Info[i].ID = lpMsg->Data[i].ID;

		memcpy(pMsg.Info[i].Name, lpMsg->Data[i].Name, 10);

		// ----
		gItemManager.ConvertItemByte(&item, this->m_MarketData[aIndex][i].Item);
		// ----

		pMsg.Info[i].ItemType = item.m_Index;

		pMsg.Info[i].ItemDurability = item.m_Durability;

		pMsg.Info[i].PriceType = lpMsg->Data[i].PriceType;

		pMsg.Info[i].Price = lpMsg->Data[i].Price;

		gItemManager.ItemByteConvert(pMsg.Info[i].ItemData, item);
	}

	DataSend(aIndex, (LPBYTE)&pMsg, sizeof(pMsg));
}

void CChoTroi::CGReqItemSell(PMSG_REQ_MARKET_SELL* lpMsg, int aIndex)
{

	this->GDReqItemSell(aIndex, lpMsg->ItemPos, lpMsg->ItemPriceType, lpMsg->ItemPrice);
}

void CChoTroi::GDReqItemSell(int aIndex, int ItemPos, int ItemPriceType, int ItemPrice)
{
	if (!OBJECT_RANGE(aIndex))
	{
		return;
	}
	
	LPOBJ lpUser = &gObj[aIndex];

#if(CHECK_USER == 1)
	if (lpUser->Interface.type == INTERFACE_CHAOS_BOX
		|| lpUser->Interface.type == INTERFACE_TRADE
		|| lpUser->Interface.type == INTERFACE_PARTY
		|| lpUser->Interface.type == INTERFACE_WAREHOUSE
		|| lpUser->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpUser->Interface.type == INTERFACE_CASH_SHOP
		|| lpUser->Interface.type == INTERFACE_TRAINER
		|| lpUser->Interface.use != 0
		|| lpUser->State == OBJECT_DELCMD
		|| lpUser->DieRegen != 0
		|| lpUser->Teleport != 0
		|| lpUser->PShopOpen != 0
		|| lpUser->ChaosLock != 0
		|| lpUser->SkillSummonPartyTime != 0)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
		return;
	}
	// Delay Khi Click
	if ((GetTickCount() - lpUser->ClickClientSend) < 2000)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
		return;
	}
#endif

	SDHP_REQ_MARKET_SELL pMsg;

	pMsg.h.set((LPBYTE)&pMsg, 0xEC, 0x01, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = aIndex;

	pMsg.PriceType = ItemPriceType;

	pMsg.Price = ItemPrice;

	//pMsg.Account[10] = 0;

	memcpy(pMsg.Account, lpUser->Account, sizeof(pMsg.Account) - 1);

#if(MARKET_NAME_DEV)

	//pMsg.Name[10] = 0;

	memcpy(pMsg.Name, lpUser->Name, sizeof(pMsg.Name) - 1);

#endif

	pMsg.ItemPos = ItemPos;


	gItemManager.DBItemByteConvert((LPBYTE)pMsg.ItemData, &lpUser->Inventory[ItemPos]);

#if(MARKET_FILTER_DEV)

	BYTE btLuck = lpUser->Inventory[ItemPos].m_Option2;

	BYTE btOption = lpUser->Inventory[ItemPos].m_Option3;

	BYTE btNewOption = lpUser->Inventory[ItemPos].m_NewOption;

	BYTE btSetOption = lpUser->Inventory[ItemPos].m_SetOption;

	if (lpUser->Inventory[ItemPos].m_IsPeriodicItem)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, "Vật phẩm có thời gian không thể giao bán!");
		LogAdd(LOG_RED, "ItemMakert : Sell Item Thoi Han Error");
		return;
	}

	if (lpUser->Inventory[ItemPos].m_LoadPeriodicItem)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, "Vật phẩm có thời gian không thể giao bán!");
		LogAdd(LOG_RED, "ItemMakert : Sell Item Thoi Han Error");
		return;
	}

	if (lpUser->Inventory[ItemPos].m_PeriodicItemTime)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, "Vật phẩm có thời gian không thể giao bán!");
		LogAdd(LOG_RED, "ItemMakert : Sell Item Thoi Han Error");
		return;
	}
	// --

	pMsg.Filter.FilterLuck = 0;

	pMsg.Filter.FilterExl = 0;

	pMsg.Filter.FilterAnc = 0;

	pMsg.Filter.FilterType = lpUser->Inventory[ItemPos].m_Index / 512;

	pMsg.Filter.FilterLevel = lpUser->Inventory[ItemPos].m_Level;

	if (btLuck)
	{
		pMsg.Filter.FilterLuck = 1;
	}

	if (btNewOption)
	{
		pMsg.Filter.FilterExl = 1;
	}

	if (btSetOption)
	{
		pMsg.Filter.FilterAnc = 1;
	}

#endif

	//Set Delay
	lpUser->ClickClientSend = GetTickCount();

	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void CChoTroi::DGAnsItemSell(SDHP_ANS_MARKET_SELL* lpMsg)
{
	int aIndex = lpMsg->aIndex;

	if (lpMsg->Result)
	{
		LPOBJ lpUser = &gObj[aIndex];

		int ItemPos = lpMsg->ItemPos;

		gItemManager.InventoryItemSet(lpUser->Index, ItemPos, -1);

		lpUser->Inventory[ItemPos].Clear();

		gItemManager.GCItemDeleteSend(lpUser->Index, ItemPos, 1);
	}
	else
	{
	}
}

// ----

void CChoTroi::CGReqItemBuy(PMSG_REQ_MARKET_BUY* lpMsg, int aIndex)
{
	this->GDReqItemBuy(aIndex, lpMsg->ID);
}

void CChoTroi::GDReqItemBuy(int aIndex, int ID)
{
	if (!OBJECT_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpUser = &gObj[aIndex];

#if(CHECK_USER == 1)
	if (lpUser->Interface.type == INTERFACE_CHAOS_BOX
		|| lpUser->Interface.type == INTERFACE_TRADE
		|| lpUser->Interface.type == INTERFACE_PARTY
		|| lpUser->Interface.type == INTERFACE_WAREHOUSE
		|| lpUser->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpUser->Interface.type == INTERFACE_CASH_SHOP
		|| lpUser->Interface.type == INTERFACE_TRAINER
		|| lpUser->Interface.use != 0
		|| lpUser->State == OBJECT_DELCMD
		|| lpUser->DieRegen != 0
		|| lpUser->Teleport != 0
		|| lpUser->PShopOpen != 0
		|| lpUser->ChaosLock != 0
		|| lpUser->SkillSummonPartyTime != 0)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
		return;
	}
	// Delay Khi Click
	if ((GetTickCount() - lpUser->ClickClientSend) < 2000)
	{
		gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
		return;
	}
#endif

	SDHP_REQ_MARKET_BUY pMsg;

	pMsg.h.set((LPBYTE)&pMsg, 0xEC, 0x02, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = aIndex;

	pMsg.ID = ID;

	pMsg.Result = 0;

	for (int i = 0; i < MARKET_ITEM_MAX; i++)
	{
		if (ID == this->m_MarketData[aIndex][i].ID)
		{
			pMsg.Result = this->GetCheckMoney(aIndex, this->m_MarketData[aIndex][i].PriceType, this->m_MarketData[aIndex][i].Price);

			break;
		}
	}

	//Set Delay
	lpUser->ClickClientSend = GetTickCount();

	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void CChoTroi::DGAnsItemBuy(SDHP_ANS_MARKET_BUY* lpMsg)
{
	int aIndex = lpMsg->aIndex;

	if (!OBJECT_RANGE(aIndex))
	{
		return;
	}

	if (lpMsg->Result)
	{
		CItem item;

		for (int i = 0; i < MARKET_ITEM_MAX; i++)
		{
			if (lpMsg->ID == this->m_MarketData[aIndex][i].ID)
			{
				if (this->PlayerMoney(aIndex, this->m_MarketData[aIndex][i].PriceType, this->m_MarketData[aIndex][i].Price))
				{
					gItemManager.ConvertItemByte(&item, this->m_MarketData[aIndex][i].Item);
					BYTE btItemPos = gItemManager.InventoryInsertItem(lpMsg->aIndex, item);
					gItemManager.GCItemModifySend(lpMsg->aIndex, btItemPos);
				}

				break;
			}
		}
	}
	else
	{
	}

	PMSG_ANS_MARKET_BUY pMsg;

	pMsg.h.set((LPBYTE)&pMsg, 0xEC, 0x01, sizeof(pMsg));

	pMsg.Result = 1;

	DataSend(aIndex, (LPBYTE)&pMsg, sizeof(pMsg));
}

#if(MARKET_PRICE_DEV)

void CChoTroi::GDReqItemStatus(int aIndex)
{
	if (!OBJECT_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpUser = &gObj[aIndex];

	SDHP_REQ_MARKET_STATUS pMsg;

	pMsg.h.set((LPBYTE)&pMsg, 0xEC, 0x03, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = aIndex;

	memcpy(pMsg.Account, lpUser->Account, sizeof(pMsg.Account) - 1);

	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void CChoTroi::DGAnsItemStatus(SDHP_ANS_MARKET_STATUS * lpMsg)
{
	int aIndex = lpMsg->aIndex;

	if (!OBJECT_RANGE(aIndex))
	{
		return;
	}

	if (!lpMsg->Result)
	{
		return;
	}

	LPOBJ lpUser = &gObj[aIndex];

	if (lpMsg->PriceType == eMarketPriceTypeZen)
	{
		int TienZen = lpMsg->PriceValue - (lpMsg->PriceValue * this->ThuPhiZen) / 100;
		lpUser->Money += TienZen;
		GCMoneySend(aIndex, lpUser->Money);
		LogAdd(LOG_BLUE, "[ChoTroi][TaiKhoan %s] +%d Zen", lpMsg->Account, TienZen);
	}

	// ---- >
	if(lpMsg->PriceType == eMarketPriceTypeWcoin)
	{
	int TienWCoinC = lpMsg->PriceValue - (lpMsg->PriceValue * this->ThuPhiWCoinC) / 100;
	GDSetCoinSend(lpUser->Index, +(TienWCoinC), 0, 0, "ChoTroi + WCoinC");
	gCashShop.CGCashShopPointRecv(lpUser->Index);
	}

	if(lpMsg->PriceType == eMarketPriceTypeCredit)
	{
		int TienWcoinP = lpMsg->PriceValue - (lpMsg->PriceValue * this->ThuPhiWCoinP) / 100;
	GDSetCoinSend(lpUser->Index, 0, +(TienWcoinP), 0, "ChoTroi + WCoinP");
	gCashShop.CGCashShopPointRecv(lpUser->Index);
	}
	
}

#endif

CItem CChoTroi::GetByteToItem(LPBYTE lpByte)
{
	CItem item;

	item.Clear();

	int n = 0;

	int ItemDbByte = 16;

	int itype = lpByte[n*ItemDbByte];

	itype |= (lpByte[n*ItemDbByte + 9] & 0xF0) * 32;

	itype |= (lpByte[n*ItemDbByte + 7] & 0x80) * 2;

	int _type = itype;

	item.m_Level = DBI_GET_LEVEL(lpByte[n*ItemDbByte + 1]);

	BYTE OptionData = lpByte[n*ItemDbByte + 1];

	item.m_Option1 = (((OptionData) >> 7) & 0x01);

	item.m_Option2 = DBI_GET_LUCK(OptionData);

	item.m_Option3 = DBI_GET_OPTION(OptionData);

	item.m_Option3 |= DBI_GET_OPTION16(lpByte[n*ItemDbByte + 7]) >> 4;

	item.m_Durability = lpByte[n*ItemDbByte + 2];

	item.m_ItemOptionEx = DBI_GET_380OPTION(lpByte[n*ItemDbByte + 9]);

	item.m_ItemOptionEx = (lpByte[9] & 8) * 16;

	if (lpByte[11] == 0 && lpByte[12] == 0 && lpByte[13] == 0 && lpByte[14] == 0 && lpByte[15] == 0)
	{
		memset(item.m_SocketOption, 0xFF, MAX_SOCKET_OPTION);
	}
	else
	{
		memcpy(item.m_SocketOption, &lpByte[11], MAX_SOCKET_OPTION);
	}

	if (item.IsSocketItem() == 0 && item.IsPentagramItem() == 0 && item.IsPentagramJewel() == 0 && item.IsPentagramMithril() == 0 && item.IsMuunItem() == 0)
	{
		item.m_JewelOfHarmonyOption = lpByte[10];

		item.m_SocketOptionBonus = 0xFF;
	}
	else
	{
		item.m_JewelOfHarmonyOption = 0;

		item.m_SocketOptionBonus = lpByte[10];
	}

	item.Convert(item.m_Index, item.m_Option1, item.m_Option2, item.m_Option3, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus);

	WORD hiWord = ((lpByte[n*ItemDbByte + 4]) & 0xFF) & 0xFF | (((lpByte[n*ItemDbByte + 3]) & 0xFF) & 0xFF) * 256;

	WORD loWord = ((lpByte[n*ItemDbByte + 6]) & 0xFF) & 0xFF | (((lpByte[n*ItemDbByte + 5]) & 0xFF) & 0xFF) * 256;

	item.m_Serial = ((loWord & 0xFFFF) & 0xFFFF) | ((hiWord & 0xFFFF) & 0xFFFF) << 16;

	return item;
}

void CChoTroi::ConnectPlayer(int aIndex)
{
	this->GDReqItemStatus(aIndex);
}

bool CChoTroi::GetCheckMoney(int aIndex, int PriceType, int PriceValue)
{
	bool Result = true;

	LPOBJ lpUser = &gObj[aIndex];

	if (PriceType == eMarketPriceTypeZen)
	{
		if (PriceValue > lpUser->Money)
		{
			Result = false;
		}
	}

	// --------->
	if (PriceType == eMarketPriceTypeWcoin)
	{
		if (PriceValue > lpUser->Coin1)
		{
			Result = false;
		}
	}
	// --------->
	if (PriceType == eMarketPriceTypeCredit)
	{
		if (PriceValue > lpUser->Coin2)
		{
			Result = false;
		}
	}
	
	// --------->
	return Result;
}

bool CChoTroi::PlayerMoney(int aIndex, int PriceType, int PriceValue)
{
	bool Result = this->GetCheckMoney(aIndex, PriceType, PriceValue);

	LPOBJ lpUser = &gObj[aIndex];

	if (Result)
	{
		if (PriceType == eMarketPriceTypeZen)
		{
			lpUser->Money -= PriceValue;

			GCMoneySend(aIndex, lpUser->Money);

			LogAdd(LOG_RED, "[ItemMakert][TaiKhoan %s] -%d Zen", lpUser->Account, PriceValue);
		}
		// ----------->
		if(PriceType == eMarketPriceTypeWcoin)
		{
		GDSetCoinSend(lpUser->Index, -(PriceValue), 0, 0, "ItemMakert - WCoinC");
		gCashShop.CGCashShopPointRecv(lpUser->Index);
		}

		if(PriceType == eMarketPriceTypeCredit)
		{
		GDSetCoinSend(lpUser->Index, 0, -(PriceValue), 0, "ItemMakert - WCoinP");
		gCashShop.CGCashShopPointRecv(lpUser->Index);
		}
		
	}

	return Result;
}

#endif