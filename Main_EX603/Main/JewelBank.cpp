#include "stdafx.h"
#include "Interface.h"
#include "JewelBank.h"
#include "Item.h"
#include "User.h"
#include "Util.h"
#include "Defines.h"
#include "postInterface.h"
#include "Central.h"

JewelBank gJewelBank;

void JewelBank::Bind()
{
	//									  ObjectID,	Hight	Wight	
	gInterface.BindObject(eJEWELBANK_MAIN, 0x7A5A, 222, 210, -1, -1); //BackPanel
	gInterface.BindObject(eJEWELBANK_TITLE, 0x7A63, 230, 67, -1, -1); //Title
	gInterface.BindObject(eJEWELBANK_FRAME, 0x7A58, 230, 7, -1, -1); //Border
	gInterface.BindObject(eJEWELBANK_FOOTER, 0x7A59, 230, 50, -1, -1); //
	gInterface.BindObject(eJEWELBANK_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//
	gInterface.BindObject(eJEWELBANK_POINT, 0x7B68, 10, 10, -1, -1);//----
	gInterface.BindObject(eJEWELBANK_LINE, 71520, 154, 3, -1, -1);	//----
	gInterface.BindObject(eJEWELBANK_DIV, 0x7A62, 223, 21, -1, -1);
	//
	gInterface.BindObject(eJEWELBANK_ZEN_MINUS, 0x7C0D, 16, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_ZEN_PLUS, 0x7AA4, 16, 15, -1, -1);

	gInterface.BindObject(eJEWELBANK_CHAOS_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_CHAOS_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_CHAOS_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_CHAOS_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_BLESS_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_BLESS_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_BLESS_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_BLESS_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_SOUL_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_SOUL_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_SOUL_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_SOUL_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_LIFE_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_LIFE_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_LIFE_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_LIFE_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_CRE_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_CRE_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_CRE_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_CRE_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_GEM_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_GEM1_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM1_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM1_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM1_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_GEM2_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM2_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM2_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM2_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_GEM3_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM3_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM3_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM3_MINUS30, 10005, 16, 16, -1, -1);

	gInterface.BindObject(eJEWELBANK_GEM4_MINUS, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM4_MINUS10, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM4_MINUS20, 10005, 16, 16, -1, -1);
	gInterface.BindObject(eJEWELBANK_GEM4_MINUS30, 10005, 16, 16, -1, -1);
	//
}

void JewelBank::DrawJewelBank()
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

	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float MainWidth = 230.0;
	float MainHeight = 320.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	DWORD Color = eGray100;

	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	// ----
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Ngân hàng ngọc");
	//
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor

	float flDrawX = StartX + 10;
	float flDrawY = StartY + 20;

	flDrawY += 20;
	this->DrawInfo(flDrawX, flDrawY + 14, "Zen", true, gObjUser.JMoney);
	// -----------
	// -> jewel
	// -----------

	flDrawY += 33;
	this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Ngọc Hỗn Nguyên", gObjUser.JChaos);

	flDrawY += 22;
	this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Ngọc Ước Nguyện", gObjUser.JBless);

	flDrawY += 22;
	this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Ngọc Tâm Linh", gObjUser.JSoul);

	flDrawY += 22;
	this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Ngọc Sinh Mệnh", gObjUser.JLife);

	flDrawY += 22;
	this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Ngọc Sáng Tạo", gObjUser.JCreation);

	flDrawY += 22;
	this->DrawLine(14, 41, 6, flDrawX, flDrawY, "Đá Nguyên Thủy", gObjUser.JHarmony);

	flDrawY += 22;
	this->DrawLine(14, 31, 6, flDrawX, flDrawY, "Đá Hộ Mệnh", gObjUser.JGuaStone);

	flDrawY += 22;
	this->DrawLine(14, 42, 7, flDrawX, flDrawY, "Đá Tạo Hóa", gObjUser.JGemStone);

	flDrawY += 22;
	this->DrawLine(14, 43, 8, flDrawX, flDrawY, "Đá Cấp Thấp", gObjUser.JSmallStone);

	flDrawY += 22;
	this->DrawLine(14, 44, 9, flDrawX, flDrawY, "Đá Cấp Cao", gObjUser.JBigStone);

	flDrawY += 35;
	pDrawGUI(71520, flDrawX, flDrawY, 200, 1); //-- Divisor

	//Nut -Zen
	gInterface.DrawButton(eJEWELBANK_ZEN_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 97, 0, 0); // 
	//Nut +Zen
	gInterface.DrawButton(eJEWELBANK_ZEN_PLUS, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 97, 0, 0); //

	//Nut -Chaos 1
	gInterface.DrawButton(eJEWELBANK_CHAOS_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 122, 0, 0); // 
	//Nut -Chaos 10
	gInterface.DrawButton(eJEWELBANK_CHAOS_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 122, 0, 0); //
	//Nut -Chaos 20
	gInterface.DrawButton(eJEWELBANK_CHAOS_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 122, 0, 0); //
	//Nut -Chaos 20
	gInterface.DrawButton(eJEWELBANK_CHAOS_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 122, 0, 0); //

	//Nut -Bless
	gInterface.DrawButton(eJEWELBANK_BLESS_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 144, 0, 0); // 
	//Nut +Bless10
	gInterface.DrawButton(eJEWELBANK_BLESS_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 144, 0, 0); //
	//Nut +Bless20
	gInterface.DrawButton(eJEWELBANK_BLESS_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 144, 0, 0); //
	//Nut +Bless30
	gInterface.DrawButton(eJEWELBANK_BLESS_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 144, 0, 0); //

	//Nut -Soul
	gInterface.DrawButton(eJEWELBANK_SOUL_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 166, 0, 0); // 
	//Nut +Soul10
	gInterface.DrawButton(eJEWELBANK_SOUL_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 166, 0, 0); //
	//Nut +Soul20
	gInterface.DrawButton(eJEWELBANK_SOUL_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 166, 0, 0); //
	//Nut +Soul30
	gInterface.DrawButton(eJEWELBANK_SOUL_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 166, 0, 0); //

	//Nut -Life
	gInterface.DrawButton(eJEWELBANK_LIFE_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 188, 0, 0); // 
	//Nut +Life10
	gInterface.DrawButton(eJEWELBANK_LIFE_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 188, 0, 0); //
	//Nut +Life20
	gInterface.DrawButton(eJEWELBANK_LIFE_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 188, 0, 0); //
	//Nut +Life30
	gInterface.DrawButton(eJEWELBANK_LIFE_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 188, 0, 0); //

	//Nut -Cre
	gInterface.DrawButton(eJEWELBANK_CRE_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 210, 0, 0); // 
	//Nut +Cre10
	gInterface.DrawButton(eJEWELBANK_CRE_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 210, 0, 0); //
	//Nut +Cre20
	gInterface.DrawButton(eJEWELBANK_CRE_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 210, 0, 0); //
	//Nut +Cre30
	gInterface.DrawButton(eJEWELBANK_CRE_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 210, 0, 0); //
	
	//Nut -Gem
	gInterface.DrawButton(eJEWELBANK_GEM_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 232, 0, 0); // 
	//Nut +Gem10
	gInterface.DrawButton(eJEWELBANK_GEM_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 232, 0, 0); //
	//Nut +Gem20
	gInterface.DrawButton(eJEWELBANK_GEM_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 232, 0, 0); //
	//Nut +Gem30
	gInterface.DrawButton(eJEWELBANK_GEM_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 232, 0, 0); //

	//
	gInterface.DrawButton(eJEWELBANK_GEM1_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 254, 0, 0); // 
	//Nut +Gem10						
	gInterface.DrawButton(eJEWELBANK_GEM1_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 254, 0, 0); //
	//Nut +Gem20						
	gInterface.DrawButton(eJEWELBANK_GEM1_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 254, 0, 0); //
	//Nut +Gem30						
	gInterface.DrawButton(eJEWELBANK_GEM1_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 254, 0, 0); //

	//
	gInterface.DrawButton(eJEWELBANK_GEM2_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 276, 0, 0); // 
	//Nut +Gem10						
	gInterface.DrawButton(eJEWELBANK_GEM2_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 276, 0, 0); //
	//Nut +Gem20						
	gInterface.DrawButton(eJEWELBANK_GEM2_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 276, 0, 0); //
	//Nut +Gem30						
	gInterface.DrawButton(eJEWELBANK_GEM2_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 276, 0, 0); //

	//
	gInterface.DrawButton(eJEWELBANK_GEM3_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 298, 0, 0); // 
	//Nut +Gem10						
	gInterface.DrawButton(eJEWELBANK_GEM3_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 298, 0, 0); //
	//Nut +Gem20						
	gInterface.DrawButton(eJEWELBANK_GEM3_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 298, 0, 0); //
	//Nut +Gem30						
	gInterface.DrawButton(eJEWELBANK_GEM3_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 298, 0, 0); //

	//
	gInterface.DrawButton(eJEWELBANK_GEM4_MINUS, StartX + 157, gInterface.Data[eJEWELBANK_MAIN].Y + 320, 0, 0); // 
	//Nut +Gem10						
	gInterface.DrawButton(eJEWELBANK_GEM4_MINUS10, StartX + 174, gInterface.Data[eJEWELBANK_MAIN].Y + 320, 0, 0); //
	//Nut +Gem20						
	gInterface.DrawButton(eJEWELBANK_GEM4_MINUS20, StartX + 191, gInterface.Data[eJEWELBANK_MAIN].Y + 320, 0, 0); //
	//Nut +Gem30						
	gInterface.DrawButton(eJEWELBANK_GEM4_MINUS30, StartX + 208, gInterface.Data[eJEWELBANK_MAIN].Y + 320, 0, 0); //
	
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 125, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 147, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 169, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 191, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 213, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 235, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 257, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 279, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 301, 200, 3, "1     10   20   30");
	gInterface.DrawFormat(eWhite, StartX + 92, gInterface.Data[eJEWELBANK_MAIN].Y + 323, 200, 3, "1     10   20   30");

	gInterface.DrawFormat(eExcellent, StartX + 22, gInterface.Data[eJEWELBANK_MAIN].Y + 350, 200, 3, "Shift + Chuột Phải để gửi ngọc");

	gInterface.DrawGUI(eJEWELBANK_CLOSE, StartX + 201, gInterface.Data[eJEWELBANK_MAIN].Y + 52);
	if (gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eJEWELBANK_CLOSE, gInterface.Data[eJEWELBANK_CLOSE].X, gInterface.Data[eJEWELBANK_CLOSE].Y, Color);
	}
}

void JewelBank::DrawLine(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char * ItemName, int Count)
{
	ItemBmdStruct1* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
	const int WidthValue = 30;
	const int HeightValue = 31;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flY = ItemDrawY - 20;
	int iLevel = 0;
	gInterface.DrawItem2(flX, flY + 15, 10, 15, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 0, 0, 0);

	flX += 30;
	flY += 15;

	gInterface.DrawFormat(eYellow, flX, flY + 2, 120, 1, "%s", ItemName);
	gInterface.DrawFormat(eBlue, flX + 75, flY + 2, 120, 1, "x%d", Count);
}

void JewelBank::DrawLineTaiSinh(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char * ItemName, int Count)
{
	ItemBmdStruct1* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
	const int WidthValue = 30;
	const int HeightValue = 31;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flY = ItemDrawY - 20;
	int iLevel = 0;
	gInterface.DrawItem2(flX, flY + 15, 10, 15, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 0, 0, 0);

	flX += 30;
	flY += 15;

	gInterface.DrawFormat(eYellow, flX, flY + 2, 120, 1, "%s", ItemName);
	gInterface.DrawFormat(eBlue, flX + 105, flY + 2, 120, 1, "%d", Count);
}

void JewelBank::DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count)
{
	float flX = InfoDrawX + 10;
	float flY = InfoDrawY;

	gInterface.DrawGUI(eJEWELBANK_POINT, flX, gInterface.Data[eJEWELBANK_MAIN].Y + 97);

	flX += 30;
	flY += 10;


	if (Type)
	{
		gInterface.DrawFormat(eYellow, flX, gInterface.Data[eJEWELBANK_MAIN].Y + 99, 120, 1, "%s: %d", Text, Count);
	}

	flX += 95;
	//gInterface.DrawGUI(eJEWELBANK_LINE, InfoDrawX + 15, flY + 15);

}

bool JewelBank::JewelBankEvent(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eJEWELBANK_MAIN].Close();
	// ----
	return false;
}

//
bool JewelBank::ClickZenMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_ZEN_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_ZEN_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_ZEN_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_ZEN_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_ZEN_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x18, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}
bool JewelBank::ClickZenPlus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_ZEN_PLUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_ZEN_PLUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_ZEN_PLUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_ZEN_PLUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_ZEN_PLUS].EventTick = GetTickCount();
	//
	//gMonsterQuest.DrawInfoTable = !gMonsterQuest.DrawInfoTable;
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x19, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickChaosMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CHAOS_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CHAOS_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CHAOS_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x30, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickChaosMinus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CHAOS_MINUS10].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CHAOS_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CHAOS_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x31, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickChaosMinus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CHAOS_MINUS20].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CHAOS_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CHAOS_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x12, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickChaosMinus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CHAOS_MINUS30].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CHAOS_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CHAOS_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CHAOS_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x13, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickBlessMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_BLESS_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_BLESS_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_BLESS_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x14, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickBlessMinus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_BLESS_MINUS10].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_BLESS_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_BLESS_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x15, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickBlessMinus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_BLESS_MINUS20].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_BLESS_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_BLESS_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x36, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickBlessMinus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_BLESS_MINUS30].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_BLESS_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_BLESS_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_BLESS_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x17, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}


bool JewelBank::ClickSoulMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_SOUL_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_SOUL_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_SOUL_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x28, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickSoulMinus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_SOUL_MINUS10].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_SOUL_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_SOUL_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x39, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickSoulMinus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_SOUL_MINUS20].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_SOUL_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_SOUL_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x40, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickSoulMinus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_SOUL_MINUS30].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_SOUL_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_SOUL_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_SOUL_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x41, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}


bool JewelBank::ClickLifeMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_LIFE_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_LIFE_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_LIFE_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x42, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}
bool JewelBank::ClickLifeMinus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_LIFE_MINUS10].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_LIFE_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_LIFE_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x43, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}
bool JewelBank::ClickLifeMinus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_LIFE_MINUS20].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_LIFE_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_LIFE_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x44, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}
bool JewelBank::ClickLifeMinus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_LIFE_MINUS30].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_LIFE_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_LIFE_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_LIFE_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x45, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}


bool JewelBank::ClickCreMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CRE_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CRE_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CRE_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x46, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickCreMinus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CRE_MINUS10].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CRE_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CRE_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x47, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickCreMinus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CRE_MINUS20].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CRE_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CRE_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x48, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickCreMinus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CRE_MINUS30].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CRE_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CRE_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CRE_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x49, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}


bool JewelBank::ClickGemMinus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM_MINUS].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x50, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickGemMinus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM_MINUS10].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x51, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickGemMinus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM_MINUS20].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x52, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickGemMinus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM_MINUS30].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x53, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	// ----
	return false;
}

bool JewelBank::ClickGem1Minus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM1_MINUS].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM1_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM1_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x65, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem1Minus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM1_MINUS10].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM1_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM1_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x66, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem1Minus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM1_MINUS20].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM1_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM1_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x67, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem1Minus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM1_MINUS30].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM1_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM1_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM1_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x68, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem2Minus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM2_MINUS].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM2_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM2_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x69, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem2Minus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM2_MINUS10].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM2_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM2_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x70, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem2Minus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM2_MINUS20].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM2_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM2_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x71, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem2Minus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM2_MINUS30].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM2_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM2_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM2_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x72, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem3Minus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM3_MINUS].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM3_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM3_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x73, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem3Minus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM3_MINUS10].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM3_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM3_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x74, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem3Minus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM3_MINUS20].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM3_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM3_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x75, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem3Minus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM3_MINUS30].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM3_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM3_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM3_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x76, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem4Minus(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM4_MINUS].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM4_MINUS))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM4_MINUS].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x77, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem4Minus10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM4_MINUS10].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM4_MINUS10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM4_MINUS10].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS10].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS10].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x78, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem4Minus20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM4_MINUS20].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM4_MINUS20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM4_MINUS20].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS20].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS20].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x79, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}
bool JewelBank::ClickGem4Minus30(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_GEM4_MINUS30].EventTick);
	this->JewelBankEvent(Event);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_GEM4_MINUS30))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_GEM4_MINUS30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_GEM4_MINUS30].EventTick = GetTickCount();
	//
	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFB, 0x80, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	//
	// ----
	return false;
}