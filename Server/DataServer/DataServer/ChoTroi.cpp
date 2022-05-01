#include "stdafx.h"
#include "Util.h"
#include "QueryManager.h"
#include "SocketManager.h"
#include "ChoTroi.h"
#include "DataServerProtocol.h"

#if(DEV_PLAYERSHOP)

CChoTroi g_ChoTroi;

CChoTroi::CChoTroi()
{
}

CChoTroi::~CChoTroi()
{
}

void CChoTroi::Init()
{
}

void CChoTroi::Load()
{
}

bool CChoTroi::Connect()
{
	this->CreateTable();

	return true;
}

void CChoTroi::CreateTable()
{
	gQueryManager.ExecQuery("CREATE TABLE [dbo].[ItemMarketData]( [ID] [int] IDENTITY(1,1) NOT NULL) ON [PRIMARY]");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [Account] [varchar](10) NULL");
	gQueryManager.Fetch();
	gQueryManager.Close();

#if(MARKET_NAME_DEV)

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [Name][varchar](10) NULL");
	gQueryManager.Fetch();
	gQueryManager.Close();

#endif

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [PriceType] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [PriceValue] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [Status] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

#if(MARKET_FILTER_DEV)

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [FilterType] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [FilterLevel] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [FilterLuck] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [FilterExl] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [FilterAnc] INT not null default(0)");
	gQueryManager.Fetch();
	gQueryManager.Close();

#endif

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [Date] [varchar](20) NULL");
	gQueryManager.Fetch();
	gQueryManager.Close();

	gQueryManager.ExecQuery("ALTER TABLE [ItemMarketData] ADD [Item] [varbinary](16) NULL");
	gQueryManager.Fetch();
	gQueryManager.Close();
}

void CChoTroi::Protocol(BYTE protoNum, BYTE *aRecv, int uIndex)
{
	switch (protoNum)
	{
	case 0x00:
		this->GDReqItemList((SDHP_REQ_MARKET_ITEM *)aRecv, uIndex);
		break;
	case 0x01:
		this->GDReqItemSell((SDHP_REQ_MARKET_SELL *)aRecv, uIndex);
		break;
	case 0x02:
		this->GDReqBuyItem((SDHP_REQ_MARKET_BUY *)aRecv, uIndex);
		break;
#if(MARKET_FILTER_DEV)
	case 0x03:
		this->GDReqItemStatus((SDHP_REQ_MARKET_STATUS *)aRecv, uIndex);
		break;
#endif
	}
}

void CChoTroi::GDReqItemList(SDHP_REQ_MARKET_ITEM* lpMsg, int uIndex)
{
#if(MARKET_PRICE_DEV)

	this->GDReqItemListPage(lpMsg, uIndex);

#else

	char szQuery[256];

	int iReturnCode = 0;

	int iCount = 0;

	SDHP_ANS_MARKET_ITEM pMsg;

	memset(&pMsg, 0, sizeof(pMsg));

	pMsg.h.set((LPBYTE)&pMsg, 0xFE, 0x00, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = lpMsg->aIndex;

	// --

	char szPriceType[256];

	memset(szPriceType, 0, sizeof(szPriceType));

	if (lpMsg->PriceType == eMarketPriceTypeZen)
	{
		sprintf(szPriceType, "AND PriceType = %d ", lpMsg->PriceType);
	}

	if (lpMsg->PriceType == eMarketPriceTypeWcoin)
	{
		sprintf(szPriceType, "AND PriceType = %d ", lpMsg->PriceType);
	}

	if (lpMsg->PriceType == eMarketPriceTypeCredit)
	{
		sprintf(szPriceType, "AND PriceType = %d ", lpMsg->PriceType);
	}

	// --

#if(MARKET_FILTER_DEV)

	char szFilter[256];

	memset(szFilter, 0, sizeof(szFilter));

	if (lpMsg->Filter.FilterType < 16)
	{
		sprintf(szFilter, "AND FilterType = %d ", lpMsg->Filter.FilterType);
	}

	if (lpMsg->Filter.FilterLevel > 0 && lpMsg->Filter.FilterLevel <= 15)	//=(
	{
		char szLevel[256];

		memset(szLevel, 0, sizeof(szLevel));

		sprintf(szLevel, "AND FilterLevel >= %d AND FilterLevel <= 15 ", lpMsg->Filter.FilterLevel);

		strcat(szFilter, szLevel);
	}

	if (lpMsg->Filter.FilterLuck)
	{
		strcat(szFilter, "AND FilterLuck = 1 ");
	}

	if (lpMsg->Filter.FilterExl)
	{
		strcat(szFilter, "AND FilterExl = 1 ");
	}

	if (lpMsg->Filter.FilterAnc)
	{
		strcat(szFilter, "AND FilterAnc = 1 ");
	}

	sprintf(szQuery, "SELECT TOP %d ID, Account, Name, PriceType, PriceValue FROM ItemMarketData WHERE Status = 0 %s %s ORDER BY ID DESC", MARKET_ITEM_MAX, szFilter, szPriceType);

#else

	sprintf(szQuery, "SELECT TOP %d ID, Account, PriceType, PriceValue FROM ItemMarketData WHERE Status = 0 ORDER BY ID DESC", MARKET_ITEM_MAX); // <<== Arg

#endif

	if (!gQueryManager.Exec(szQuery))
	{
		gQueryManager.Close();

		pMsg.Result = 0;
	}
	else
	{
		short sqlReturn = gQueryManager.Fetch();

		while (sqlReturn != SQL_NO_DATA && sqlReturn != SQL_NULL_DATA)
		{
			iReturnCode = gQueryManager.GetInt(1);

			if (iReturnCode < 0)
			{
				break;
			}

			char szSeller[MARKET_NAME_LEN];
			gQueryManager.GetStr("Name", szSeller);

			pMsg.Data[iCount].Name[MARKET_NAME_LEN - 1] = 0;

			memcpy(pMsg.Data[iCount].Name, szSeller, MARKET_NAME_LEN - 1);

			pMsg.Data[iCount].PriceType = gQueryManager.GetInt("PriceType");

			pMsg.Data[iCount].Price = gQueryManager.GetInt("PriceValue");

			// --

			int id = gQueryManager.GetInt("ID");

			pMsg.Data[iCount].ID = id;

			sprintf(szQuery, "SELECT Item FROM ItemMarketData WHERE ID = %d", id);

			int	nRet = this->m_DBItem.ReadBlob(szQuery, pMsg.Data[iCount].Item);

			if (nRet < 0)
			{
				memset(pMsg.Data[iCount].Item, -1, sizeof(pMsg.Data[iCount].Item));
			}

			// --

			iCount++;

			if (iCount >= MARKET_ITEM_MAX)
			{
				break;
			}

			sqlReturn = gQueryManager.Fetch();
		}

		gQueryManager.Close();
	}

	wsjServer.DataSend(uIndex, (char*)&pMsg, sizeof(pMsg));

#endif
}

void CChoTroi::GDReqItemSell(SDHP_REQ_MARKET_SELL* lpMsg, int uIndex)
{
	char szQuery[512];

	SDHP_ANS_MARKET_SELL pMsg;

	memset(&pMsg, 0, sizeof(pMsg));

	pMsg.h.set((LPBYTE)&pMsg, 0xFE, 0x01, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = lpMsg->aIndex;

	pMsg.ItemPos = lpMsg->ItemPos;

#if(MARKET_FILTER_DEV)

	char szAccount[11];
	memset(szAccount, 0, sizeof(szAccount));
	memcpy(szAccount, lpMsg->Account, sizeof(szAccount)-1);

	char szName[11];
	memset(szName, 0, sizeof(szName));
	memcpy(szName, lpMsg->Name, sizeof(szName)-1);

	sprintf(szQuery,
		"INSERT INTO ItemMarketData (Account, PriceType, PriceValue, Date, Status, FilterLuck, FilterExl, FilterAnc, FilterType, FilterLevel, Name) VALUES ('%s', %d, %d, '%s', 0, %d, %d, %d, %d, %d, '%s')",
		lpMsg->Account,
		lpMsg->PriceType,
		lpMsg->Price,
		"19.12.2020",
		lpMsg->Filter.FilterLuck,
		lpMsg->Filter.FilterExl,
		lpMsg->Filter.FilterAnc,
		lpMsg->Filter.FilterType,
		lpMsg->Filter.FilterLevel,
		lpMsg->Name
		);

#else

	sprintf(szQuery, "INSERT INTO ItemMarketData (Account, PriceType, PriceValue, Date, Status) VALUES ('%s', %d, %d, '%s', 0)",
		lpMsg->Account, lpMsg->PriceType, lpMsg->Price, "19.12.2020");

#endif

	pMsg.Result = gQueryManager.ExecQuery(szQuery);

	gQueryManager.Fetch();

	gQueryManager.Close();

	// --

	sprintf(szQuery, "SELECT TOP 1 ID FROM ItemMarketData ORDER BY ID DESC");	//need recode

	if (!gQueryManager.ExecQuery(szQuery) || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		pMsg.Result = 0;
	}

	int id = gQueryManager.GetAsInteger("ID");

	gQueryManager.Close();

	// --

#if(MARET_MUEMU)

	sprintf(szQuery, "UPDATE ItemMarketData SET Item = ? WHERE ID = %d", id);

	gQueryManager.BindParameterAsBinary(1, lpMsg->ItemData, sizeof(lpMsg->ItemData));

	gQueryManager.ExecQuery(szQuery, id);

	gQueryManager.Close();

#else

	sprintf(szQuery, "UPDATE ItemMarketData SET Item = ? WHERE ID = %d", id);

	this->m_DBItem.WriteBlob(szQuery, lpMsg->ItemData, 16);

#endif

	// --

	gSocketManager.DataSend(uIndex, (BYTE*)&pMsg, sizeof(pMsg));
}

void CChoTroi::GDReqBuyItem(SDHP_REQ_MARKET_BUY* lpMsg, int uIndex)
{
	char szQuery[256];

	int iResult = lpMsg->Result;

	if (iResult)
	{
		sprintf(szQuery, "UPDATE ItemMarketData SET Status = 1 WHERE ID = %d", lpMsg->ID);

		iResult = gQueryManager.ExecQuery(szQuery);

		gQueryManager.Close();
	}

	SDHP_ANS_MARKET_BUY pMsg;

	memset(&pMsg, 0, sizeof(pMsg));

	pMsg.h.set((LPBYTE)&pMsg, 0xFE, 0x02, sizeof(pMsg));

	pMsg.Result = iResult;

	pMsg.aIndex = lpMsg->aIndex;

	pMsg.ID = lpMsg->ID;

	gSocketManager.DataSend(uIndex, (BYTE*)&pMsg, sizeof(pMsg));
}

#if(MARKET_PRICE_DEV)

void CChoTroi::GDReqItemStatus(SDHP_REQ_MARKET_STATUS* lpMsg, int uIndex)
{
	char szQuery[256];

	SDHP_ANS_MARKET_STATUS pMsg;

	memset(&pMsg, 0, sizeof(pMsg));

	pMsg.h.set((LPBYTE)&pMsg, 0xFE, 0x03, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = lpMsg->aIndex;

#if(MARKET_DEBUG)

	while (true)
	{
		pMsg.Result = 1;

		sprintf(szQuery, "SELECT * FROM ItemMarketData WHERE Account = '%s' AND Status = 1", lpMsg->Account);
		if (!gQueryManager.ExecQuery(szQuery) || gQueryManager.Fetch() == SQL_NO_DATA)
		{
			pMsg.Result = 0;

			gQueryManager.Close();

			break;
		}
		else
		{
			int iID = gQueryManager.GetAsInteger("ID");

			pMsg.PriceType = gQueryManager.GetAsInteger("PriceType");

			pMsg.PriceValue = gQueryManager.GetAsInteger("PriceValue");

			gQueryManager.GetAsString("Account", pMsg.Account, sizeof(pMsg.Account));

			gQueryManager.Close();

			// --

			if (pMsg.Result)
			{
				sprintf(szQuery, "DELETE FROM ItemMarketData WHERE ID = %d", iID);

				if (!gQueryManager.ExecQuery(szQuery) || gQueryManager.Fetch() == SQL_NO_DATA)
				{
					pMsg.Result = 0;
				}

				gQueryManager.Close();
			}
		}

		gSocketManager.DataSend(uIndex, (BYTE*)&pMsg, sizeof(pMsg));
	}

#else

	sprintf(szQuery, "SELECT * FROM ItemMarketData WHERE Account = '%s' AND Status = 1", lpMsg->Account);

	if (!gQueryManager.Exec(szQuery) || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		pMsg.Result = 0;
	}
	else
	{
		int iID = gQueryManager.GetInt("ID");

		pMsg.PriceType = gQueryManager.GetInt("PriceType");

		pMsg.PriceValue = gQueryManager.GetInt("PriceValue");

		gQueryManager.GetStr("Account", pMsg.Account);

		gQueryManager.Close();

		// --

		if (pMsg.Result)
		{
			sprintf(szQuery, "DELETE FROM ItemMarketData WHERE ID = %d", iID);

			if (!gQueryManager.Exec(szQuery) || gQueryManager.Fetch() == SQL_NO_DATA)
			{
				pMsg.Result = 0;
			}

			gQueryManager.Close();
		}
	}

	gSocketManager.DataSend(uIndex, (BYTE*)&pMsg, sizeof(pMsg));

#endif
}

#endif

#if(MARKET_PRICE_DEV)

void CChoTroi::GDReqItemListPage(SDHP_REQ_MARKET_ITEM* lpMsg, int uIndex)
{
	char szQuery[256];

	int iReturnCode = 0;

	int iCount = 0;

	int iPageNumber = lpMsg->PageNumber;

	SDHP_ANS_MARKET_ITEM pMsg;

	memset(&pMsg, 0, sizeof(pMsg));

	pMsg.h.set((LPBYTE)&pMsg, 0xFE, 0x00, sizeof(pMsg));

	pMsg.Result = 1;

	pMsg.aIndex = lpMsg->aIndex;

	// --

	char szPriceType[256];

	memset(szPriceType, 0, sizeof(szPriceType));

	if (lpMsg->PriceType == eMarketPriceTypeZen)
	{
		sprintf(szPriceType, "AND PriceType = %d ", lpMsg->PriceType);
	}

	if (lpMsg->PriceType == eMarketPriceTypeWcoin)
	{
		sprintf(szPriceType, "AND PriceType = %d ", lpMsg->PriceType);
	}

	if (lpMsg->PriceType == eMarketPriceTypeCredit)
	{
		sprintf(szPriceType, "AND PriceType = %d ", lpMsg->PriceType);
	}

	// --

#if(MARKET_FILTER_DEV)

	char szFilter[256];

	memset(szFilter, 0, sizeof(szFilter));

	if (lpMsg->Filter.FilterType < 16)
	{
		sprintf(szFilter, "AND FilterType = %d ", lpMsg->Filter.FilterType);
	}

	if (lpMsg->Filter.FilterLevel > 0 && lpMsg->Filter.FilterLevel <= 15)	//=(
	{
		char szLevel[256];

		memset(szLevel, 0, sizeof(szLevel));

		sprintf(szLevel, "AND FilterLevel >= %d AND FilterLevel <= 15 ", lpMsg->Filter.FilterLevel);

		strcat(szFilter, szLevel);
	}

	if (lpMsg->Filter.FilterLuck)
	{
		strcat(szFilter, "AND FilterLuck = 1 ");
	}

	if (lpMsg->Filter.FilterExl)
	{
		strcat(szFilter, "AND FilterExl = 1 ");
	}

	if (lpMsg->Filter.FilterAnc)
	{
		strcat(szFilter, "AND FilterAnc = 1 ");
	}
	sprintf(szQuery, "SELECT TOP %d ID, Account, Name, PriceType, PriceValue, Item FROM ItemMarketData WHERE Status = 0 %s %s ORDER BY ID DESC", MARKET_ITEM_MAX * 10, szFilter, szPriceType);

#else

	sprintf(szQuery, "SELECT TOP %d ID, Account, PriceType, PriceValue FROM ItemMarketData WHERE Status = 0 ORDER BY ID DESC", MARKET_ITEM_MAX); // <<== Arg

#endif

#if(MARET_MUEMU)

	int iDataCount = 0;

	int iDataID[MARKET_ITEM_MAX] = { 0 };

#endif

	if (!gQueryManager.ExecQuery(szQuery))
	{
		gQueryManager.Close();

		pMsg.Result = 0;
	}
	else
	{
		int iQueryCount = 0;

		short sqlReturn = gQueryManager.Fetch();

		while (sqlReturn != SQL_NO_DATA && sqlReturn != SQL_NULL_DATA)
		{
			iReturnCode = gQueryManager.GetResult(1);

			if (iReturnCode < 0)
			{
				break;
			}

			if (iQueryCount >= iPageNumber * MARKET_ITEM_MAX)
			{
				char szSeller[MARKET_NAME_LEN];

				gQueryManager.GetAsString("Name", szSeller, sizeof(szSeller));

				pMsg.Data[iCount].Name[MARKET_NAME_LEN - 1] = 0;

				memcpy(pMsg.Data[iCount].Name, szSeller, MARKET_NAME_LEN - 1);

				pMsg.Data[iCount].PriceType = gQueryManager.GetAsInteger("PriceType");

				pMsg.Data[iCount].Price = gQueryManager.GetAsInteger("PriceValue");

				// --

#if(MARET_MUEMU)

				int id = gQueryManager.GetAsInteger("ID");

				pMsg.Data[iCount].ID = id;

				memset(pMsg.Data[iCount].Item, -1, sizeof(pMsg.Data[iCount].Item));

				gQueryManager.GetAsBinary("Item", pMsg.Data[iCount].Item, sizeof(pMsg.Data[iCount].Item));

				//iDataCount++;

#else

				int id = gQueryManager.GetAsInteger("ID");

				pMsg.Data[iCount].ID = id;

				sprintf(szQuery, "SELECT Item FROM ItemMarketData WHERE ID = %d", id);

				int	nRet = this->m_DBItem.ReadBlob(szQuery, pMsg.Data[iCount].Item);

				if (nRet < 0)
				{
					memset(pMsg.Data[iCount].Item, -1, sizeof(pMsg.Data[iCount].Item));
				}

#endif

				// --

				iCount++;

				if (iCount >= MARKET_ITEM_MAX)
				{
					break;
				}
			}

			sqlReturn = gQueryManager.Fetch();

			iQueryCount++;
		}

		gQueryManager.Close();
	}

	gSocketManager.DataSend(uIndex, (BYTE*)&pMsg, sizeof(pMsg));
}

#endif

#endif