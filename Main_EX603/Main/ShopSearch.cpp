#include "stdafx.h"
#include "ShopSearch.h"
#include "Interface.h"
#include "Protocol.h"
#include "Central.h"
#include "Object.h"
#include "Offset.h"
#include "Util.h"
#include "CustomMessage.h"
#include "TMemory.h"
#include "SItemOption.h"


#if(SHOPSEARCH==TRUE)

PersonalShopEx g_PersonalShopEx;
// ----------------------------------------------------------------------------------------------


void PersonalShopEx::BindImages()
{
	gInterface.BindObject(ePT_PERSONAL_SEARCH_MAIN, 31461, 1000, 1000, -1, -1);  // 31461
	gInterface.BindObject(ePT_PERSONAL_SEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_L, 0x7BAA, 17, 17, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_R, 0x7BAB, 17, 17, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP1, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP2, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP3, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP4, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP5, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP6, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP7, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP8, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP9, 0x7E98, 170, 21, -1, -1);
	gInterface.BindObject(ePT_PERSONAL_SEARCH_PAGEUP10, 0x7E98, 170, 21, -1, -1);
}
// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------
//bool PersonalShopEx::CheckWindowEx2(int WindowID)
//{
//	return gInterface.Data[WindowID].OnShow;
//}
//
//void PersonalShopEx::OpenWindowEx(int WindowID)
//{
//	gInterface.Data[WindowID].Open();
//}
//
//void PersonalShopEx::CloseWindowEx(int WindowID)
//{
//	gInterface.Data[WindowID].Close();
//}

bool PersonalShopEx::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!gInterface.IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!gInterface.Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && gInterface.Data[ButtonID].OnClick == false)
	{
		gInterface.Data[ButtonID].OnClick = true;
	//	return false;
	}

	if (Event == WM_LBUTTONUP && gInterface.Data[ButtonID].OnClick == true)
	{
		gInterface.Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[ButtonID].OnClick = false;
	// ----
	gInterface.Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------																	 
void PersonalShopEx::Draw()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}

	if (gInterface.CheckWindow(Store))
	{
		g_PersonalShopEx.aTargetIndex = pGameIndex;
		pSetCursorFocus = true;
		return;
	}

	if (gInterface.CheckWindow(OtherStore))
	{
		return;
		pSetCursorFocus = true;
	}

	if (!gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].OnShow)
	{
		return;
		pSetCursorFocus = true;
	}

	pSetCursorFocus = true;
	// ----
	DWORD ItemNameColor = eWhite;

	float MainWidth = 640;
	float MainHeight = 429;
	float StartY = 0;
	float StartX = 0;

	float ContentX = 170;
	float ContentY = 50;

	//-- Main
	gCItemSetOption.ItemTooltipS15(StartX + 150, gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].Y + 65, 260, 310, 0.0, 150);

	gInterface.DrawFormat(eGold, (int)StartX + 160, gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].Y + 70, 210, 3, "TÌM KIẾM ĐỒ SHOP TREO");
	// ---
	gInterface.DrawGUI(ePT_PERSONAL_SEARCH_CLOSE, StartX + 375, gInterface.Data[ePT_PERSONAL_SEARCH_MAIN].Y + 65);
	// ----
	if (gInterface.IsWorkZone(ePT_PERSONAL_SEARCH_CLOSE))
	{
		DWORD Color = eGray100;
	}
	// ----
	// -> Content
	gInterface.DrawGUI(ePT_PERSONAL_SEARCH_DIV, ContentX, ContentY + 40);

	float ListDrawX = ContentX + 20 + 15;
	float ListDrawY = ContentY + 10 + 25;

	gInterface.DrawFormat(eGold, ListDrawX, ListDrawY + 20, 100, 1, "TÊN SHOP");

	ListDrawX += 50;
	gInterface.DrawFormat(eGold, ListDrawX, ListDrawY + 20, 100, 1, "LOẠI TIỀN TỆ SHOP BÁN");

	ListDrawX += 50;

	ListDrawX += 15;

	ListDrawX += 20;

	ListDrawX += 35;

	gInterface.DrawGUI(ePT_PERSONAL_SEARCH_DIV, ContentX, ListDrawY + 23);

	// ----------

	// -> Draw Listing

	for (int i = 0; i < 10; i++)
	{

		if (this->PShop[i].Name[0] == NULL) continue;

		gInterface.DrawGUI(ePT_PERSONAL_SEARCH_PAGEUP1 + i, ContentX + 10 + 18, ContentY + 77 + i * 22);

		ListDrawX = ContentX + 20 + 18;
		ListDrawY = ContentY + 60 + i * 22;

		gInterface.DrawFormat(eYellow, ListDrawX - 7, ListDrawY + 21, 100, 1, this->PShop[i].Name);

		ListDrawX += 50;
		gInterface.DrawFormat(eWhite, ListDrawX, ListDrawY + 21, 100, 1, "%s", this->PShop[i].PersonalText);

		ListDrawX += 50;

		ListDrawX += 15;

		ListDrawX += 20;

		ListDrawX += 27;

		ListDrawX += 10;

		if (gInterface.IsWorkZone(ePT_PERSONAL_SEARCH_PAGEUP1 + i))
		{
			DWORD Color = eGray100;
			// ----
			if (gInterface.Data[ePT_PERSONAL_SEARCH_PAGEUP1 + i].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(ePT_PERSONAL_SEARCH_PAGEUP1 + i, gInterface.Data[ePT_PERSONAL_SEARCH_PAGEUP1 + i].X, gInterface.Data[ePT_PERSONAL_SEARCH_PAGEUP1 + i].Y, Color);
		}

	}

	// -----------

	//-> Page Draw

	//gInterface.DrawGUI(ePT_PERSONAL_SEARCH_DIV, ContentX, gInterface.Data[ePT_PERSONAL_SEARCH_FOOTER].Y - 10);

	gInterface.DrawGUI(ePT_PERSONAL_SEARCH_L, ContentX + 80, ContentY + 300);
	gInterface.DrawGUI(ePT_PERSONAL_SEARCH_R, ContentX + 140, ContentY + 300);

	if (gInterface.IsWorkZone(ePT_PERSONAL_SEARCH_L))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[ePT_PERSONAL_SEARCH_L].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(ePT_PERSONAL_SEARCH_L, gInterface.Data[ePT_PERSONAL_SEARCH_L].X, gInterface.Data[ePT_PERSONAL_SEARCH_L].Y, Color);
	}

	if (gInterface.IsWorkZone(ePT_PERSONAL_SEARCH_R))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[ePT_PERSONAL_SEARCH_R].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(ePT_PERSONAL_SEARCH_R, gInterface.Data[ePT_PERSONAL_SEARCH_R].X, gInterface.Data[ePT_PERSONAL_SEARCH_R].Y, Color);
	}

	gInterface.DrawFormat(eGold, ContentX + 97, ContentY + 304, 100, 1, "Trang: %d/%d", this->Page + 1, (this->TotalShop - 1) / 10 + 1);

	gInterface.CloseWindow(ChatWindow);
	gInterface.CloseWindow(MoveList);


	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

}
// ----------------------------------------------------------------------------------------------

void PersonalShopEx::Button(DWORD Event)
{
	if (gInterface.CheckWindow(Store) || gInterface.CheckWindow(OtherStore))
	{
		return;
	}

	if (!g_PersonalShopEx.CHECK_WINDOW_STORE())
	{
		return;
	}

	if (g_PersonalShopEx.ButtonEx(Event, ePT_PERSONAL_SEARCH_CLOSE, 0))
	{
		g_PersonalShopEx.CLOSE_WINDOW_STORE();
	}

	if (g_PersonalShopEx.ButtonEx(Event, ePT_PERSONAL_SEARCH_L, false))
	{
		if (this->Page != 0)
		{
			this->Page--;
			this->CG_Send();
		}
		return;
	}
	else if (g_PersonalShopEx.ButtonEx(Event, ePT_PERSONAL_SEARCH_R, false))
	{
		if (this->Page != (this->TotalShop - 1) / 10)
		{
			this->Page++;
			this->CG_Send();
		}
		return;
	}

	// --------

	if (g_PersonalShopEx.CHECK_WINDOW_STORE())
	{
		for (int i = 0; i < 10; i++)
		{
			if (g_PersonalShopEx.ButtonEx(Event, ePT_PERSONAL_SEARCH_PAGEUP1 + i, false))
			{
				PMSG_REQ_BUYLIST_FROM_PSHOP pReq;
				pReq.header.set(0xDE, 0x20, sizeof(pReq));
				pReq.index[0] = SET_NUMBERHB(this->PShop[i].aIndex);
				pReq.index[1] = SET_NUMBERLB(this->PShop[i].aIndex);
				g_PersonalShopEx.bIndex = MAKE_NUMBERW(pReq.index[0], pReq.index[1]);
				memcpy(pReq.name, this->PShop[i].Name, 10);

				DataSend((BYTE*)&pReq, pReq.header.size);
			}
		}
	}
}
// ----------------------------------------------------------------------------------------------

void PersonalShopEx::GC_Recv(LPBYTE aRecv)
{
	ZeroMemory(&this->PShop, sizeof(this->PShop));
	int datasize = 8;
	int excount = MAKE_NUMBERW(aRecv[datasize - 3], aRecv[datasize - 2]);
	this->TotalShop = excount;

	int SendCount = aRecv[datasize - 1];

	for (int n = 0; n < SendCount; n++)
	{
		GC_PersonalShopInfo ap;
		memcpy(&ap, &aRecv[datasize], sizeof(ap));

		this->PShop[n].aIndex = ap.aIndex;
		strncpy(this->PShop[n].Name, ap.Name, 10);
		strncpy(this->PShop[n].PersonalText, ap.PersonalText, 36);

		this->PShop[n].Value = ap.Value;

		datasize += sizeof(ap);
	}

	if (!g_PersonalShopEx.CHECK_WINDOW_STORE());
	{
		g_PersonalShopEx.OPEN_WINDOW_STORE();
	}
}
// ----------------------------------------------------------------------------------------------

void PersonalShopEx::CG_Send()
{
	CG_PersonalPage pRequest;
	pRequest.h.set(0xDE, 0x22, sizeof(pRequest));
	pRequest.Page = this->Page;
	DataSend((BYTE*)&pRequest, pRequest.h.size);
}
// ----------------------------------------------------------------------------------------------
void PersonalShopEx::GC_PSRecv(GC_SendTargetInfo* aRecv)
{
	this->aTargetIndex = aRecv->bIndex;
	memset(this->TargetName, 0, sizeof(this->TargetName));
	memcpy(this->TargetName, aRecv->Name, 10);
}

int PersonalShopEx::ReturnPos()
{
	LPVOID  v11 = (LPVOID)sub_861420(pWindowThis()); //00861420
	int v16 = sub_668A80(v11) + 204; //00668A80
	return v16;
}
void PSShopVieweFix()
{
	PMSG_REQ_BUYITEM_FROM_PSHOP pReq;
	pReq.h.set(0xDE, 0x23, sizeof(pReq));
	pReq.index[0] = SET_NUMBERHB(g_PersonalShopEx.aTargetIndex);
	pReq.index[1] = SET_NUMBERLB(g_PersonalShopEx.aTargetIndex);
	memcpy(pReq.name, g_PersonalShopEx.TargetName, 10);

	pReq.slot = g_PersonalShopEx.ReturnPos();

	DataSend((BYTE*)&pReq, pReq.h.size);

	float MainWidth = 640;
	float MainHeight = 429;
	float StartY = 0;
	float StartX = 0;

	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

}
void PersonalShopEx::Load()
{
	SetRange((LPVOID)0x0079AEE9, 191, ASM::NOP);
	SetOp((LPVOID)0x0079AEEF, &PSShopVieweFix, ASM::CALL);
}
#endif