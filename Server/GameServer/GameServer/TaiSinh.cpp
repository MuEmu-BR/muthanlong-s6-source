#include "StdAfx.h"
#include "user.h"
#include "TaiSinh.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "ObjectManager.h"
#include "JewelBank.h"
#include "CommandManager.h"

#if(TAISINH == 1)

TaiSinh gTaiSinh;
// -------------------------------------------------------------------------------
TaiSinh::TaiSinh() // OK
{
}
// -------------------------------------------------------------------------------
TaiSinh::~TaiSinh() // OK
{
}
// -------------------------------------------------------------------------------
void TaiSinh::Load(char* path) // OK
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok)
	{
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}

	//--
	pugi::xml_node oTaiSinh = file.child("TaiSinh");
	//--
	pugi::xml_node eEnabled = oTaiSinh.child("Enabled");
	for (pugi::xml_node rEnabled = eEnabled.child("Config"); rEnabled; rEnabled = rEnabled.next_sibling()){

		this->m_Enabled = rEnabled.attribute("BatTat").as_int();
		this->m_TaiSinh = rEnabled.attribute("TaiSinh").as_int();
		this->m_TrungSinh = rEnabled.attribute("TrungSinh").as_int();
	}
	//--
	pugi::xml_node eDieuKienLevel = oTaiSinh.child("DieuKienLevel");
	for (pugi::xml_node rDieuKienLevel = eDieuKienLevel.child("Config"); rDieuKienLevel; rDieuKienLevel = rDieuKienLevel.next_sibling()){

		this->m_DieuKienLevel = rDieuKienLevel.attribute("Level").as_int();
	}
	//--
	pugi::xml_node eDieuKienReset = oTaiSinh.child("DieuKienResets");
	for (pugi::xml_node rDieuKienReset = eDieuKienReset.child("Config"); rDieuKienReset; rDieuKienReset = rDieuKienReset.next_sibling()){

		this->DieuKien01 = rDieuKienReset.attribute("Lan1").as_int();
		this->DieuKien02 = rDieuKienReset.attribute("Lan2").as_int();
		this->DieuKien03 = rDieuKienReset.attribute("Lan3").as_int();
		this->DieuKien04 = rDieuKienReset.attribute("Lan4").as_int();
		this->DieuKien05 = rDieuKienReset.attribute("Lan5").as_int();
		this->DieuKien06 = rDieuKienReset.attribute("Lan6").as_int();
		this->DieuKien07 = rDieuKienReset.attribute("Lan7").as_int();
		this->DieuKien08 = rDieuKienReset.attribute("Lan8").as_int();
		this->DieuKien09 = rDieuKienReset.attribute("Lan9").as_int();
		this->DieuKien10 = rDieuKienReset.attribute("Lan10").as_int();
	}
	//--
	pugi::xml_node eDiemPoinTaiSinh = oTaiSinh.child("DiemTaiSinh");
	for (pugi::xml_node rDiemPoinTaiSinh = eDiemPoinTaiSinh.child("Config"); rDiemPoinTaiSinh; rDiemPoinTaiSinh = rDiemPoinTaiSinh.next_sibling()){

		this->DiemPointTaiSinh01 = rDiemPoinTaiSinh.attribute("Lan1").as_int();
		this->DiemPointTaiSinh02 = rDiemPoinTaiSinh.attribute("Lan2").as_int();
		this->DiemPointTaiSinh03 = rDiemPoinTaiSinh.attribute("Lan3").as_int();
		this->DiemPointTaiSinh04 = rDiemPoinTaiSinh.attribute("Lan4").as_int();
		this->DiemPointTaiSinh05 = rDiemPoinTaiSinh.attribute("Lan5").as_int();
		this->DiemPointTaiSinh06 = rDiemPoinTaiSinh.attribute("Lan6").as_int();
		this->DiemPointTaiSinh07 = rDiemPoinTaiSinh.attribute("Lan7").as_int();
		this->DiemPointTaiSinh08 = rDiemPoinTaiSinh.attribute("Lan8").as_int();
		this->DiemPointTaiSinh09 = rDiemPoinTaiSinh.attribute("Lan9").as_int();
		this->DiemPointTaiSinh10 = rDiemPoinTaiSinh.attribute("Lan10").as_int();
	}
	//--
	pugi::xml_node eDiemPoinTrungSinh = oTaiSinh.child("DiemTrungSinh");
	for (pugi::xml_node rDiemPoinTrungSinh = eDiemPoinTrungSinh.child("Config"); rDiemPoinTrungSinh; rDiemPoinTrungSinh = rDiemPoinTrungSinh.next_sibling()){

		this->DiemPointTrungSinh01 = rDiemPoinTrungSinh.attribute("Lan1").as_int();
		this->DiemPointTrungSinh02 = rDiemPoinTrungSinh.attribute("Lan2").as_int();
		this->DiemPointTrungSinh03 = rDiemPoinTrungSinh.attribute("Lan3").as_int();
		this->DiemPointTrungSinh04 = rDiemPoinTrungSinh.attribute("Lan4").as_int();
		this->DiemPointTrungSinh05 = rDiemPoinTrungSinh.attribute("Lan5").as_int();
		this->DiemPointTrungSinh06 = rDiemPoinTrungSinh.attribute("Lan6").as_int();
		this->DiemPointTrungSinh07 = rDiemPoinTrungSinh.attribute("Lan7").as_int();
		this->DiemPointTrungSinh08 = rDiemPoinTrungSinh.attribute("Lan8").as_int();
		this->DiemPointTrungSinh09 = rDiemPoinTrungSinh.attribute("Lan9").as_int();
		this->DiemPointTrungSinh10 = rDiemPoinTrungSinh.attribute("Lan10").as_int();
	}
	//--
	pugi::xml_node eMSG = oTaiSinh.child("ThongBao");
	for (pugi::xml_node rMSG = eMSG.child("Config"); rMSG; rMSG = rMSG.next_sibling()){

		strncpy_s(this->Msg01, rMSG.attribute("Msg1").as_string(), sizeof(this->Msg01));
		strncpy_s(this->Msg02, rMSG.attribute("Msg2").as_string(), sizeof(this->Msg02));
	}
	//--
	pugi::xml_node eDieuKienNgoc = oTaiSinh.child("DieuKienNgoc");
	for (pugi::xml_node rDieuKienNgoc = eDieuKienNgoc.child("Config"); rDieuKienNgoc; rDieuKienNgoc = rDieuKienNgoc.next_sibling()){

		DieuKienNgoc01.rChaos = rDieuKienNgoc.attribute("Chaos01").as_int();
		DieuKienNgoc01.rBless = rDieuKienNgoc.attribute("Bless01").as_int();
		DieuKienNgoc01.rSoul = rDieuKienNgoc.attribute("Sould01").as_int();
		DieuKienNgoc01.rLife = rDieuKienNgoc.attribute("Life01").as_int();
		DieuKienNgoc01.rCre = rDieuKienNgoc.attribute("Cre01").as_int();

		DieuKienNgoc02.rChaos = rDieuKienNgoc.attribute("Chaos02").as_int();
		DieuKienNgoc02.rBless = rDieuKienNgoc.attribute("Bless02").as_int();
		DieuKienNgoc02.rSoul = rDieuKienNgoc.attribute("Sould02").as_int();
		DieuKienNgoc02.rLife = rDieuKienNgoc.attribute("Life02").as_int();
		DieuKienNgoc02.rCre = rDieuKienNgoc.attribute("Cre02").as_int();

		DieuKienNgoc03.rChaos = rDieuKienNgoc.attribute("Chaos03").as_int();
		DieuKienNgoc03.rBless = rDieuKienNgoc.attribute("Bless03").as_int();
		DieuKienNgoc03.rSoul = rDieuKienNgoc.attribute("Sould03").as_int();
		DieuKienNgoc03.rLife = rDieuKienNgoc.attribute("Life03").as_int();
		DieuKienNgoc03.rCre = rDieuKienNgoc.attribute("Cre03").as_int();

		DieuKienNgoc04.rChaos = rDieuKienNgoc.attribute("Chaos04").as_int();
		DieuKienNgoc04.rBless = rDieuKienNgoc.attribute("Bless04").as_int();
		DieuKienNgoc04.rSoul = rDieuKienNgoc.attribute("Sould04").as_int();
		DieuKienNgoc04.rLife = rDieuKienNgoc.attribute("Life04").as_int();
		DieuKienNgoc04.rCre = rDieuKienNgoc.attribute("Cre04").as_int();

		DieuKienNgoc05.rChaos = rDieuKienNgoc.attribute("Chaos05").as_int();
		DieuKienNgoc05.rBless = rDieuKienNgoc.attribute("Bless05").as_int();
		DieuKienNgoc05.rSoul = rDieuKienNgoc.attribute("Sould05").as_int();
		DieuKienNgoc05.rLife = rDieuKienNgoc.attribute("Life05").as_int();
		DieuKienNgoc05.rCre = rDieuKienNgoc.attribute("Cre05").as_int();

		DieuKienNgoc06.rChaos = rDieuKienNgoc.attribute("Chaos06").as_int();
		DieuKienNgoc06.rBless = rDieuKienNgoc.attribute("Bless06").as_int();
		DieuKienNgoc06.rSoul = rDieuKienNgoc.attribute("Sould06").as_int();
		DieuKienNgoc06.rLife = rDieuKienNgoc.attribute("Life06").as_int();
		DieuKienNgoc06.rCre = rDieuKienNgoc.attribute("Cre06").as_int();

		DieuKienNgoc07.rChaos = rDieuKienNgoc.attribute("Chaos07").as_int();
		DieuKienNgoc07.rBless = rDieuKienNgoc.attribute("Bless07").as_int();
		DieuKienNgoc07.rSoul = rDieuKienNgoc.attribute("Sould07").as_int();
		DieuKienNgoc07.rLife = rDieuKienNgoc.attribute("Life07").as_int();
		DieuKienNgoc07.rCre = rDieuKienNgoc.attribute("Cre07").as_int();

		DieuKienNgoc08.rChaos = rDieuKienNgoc.attribute("Chaos08").as_int();
		DieuKienNgoc08.rBless = rDieuKienNgoc.attribute("Bless08").as_int();
		DieuKienNgoc08.rSoul = rDieuKienNgoc.attribute("Sould08").as_int();
		DieuKienNgoc08.rLife = rDieuKienNgoc.attribute("Life08").as_int();
		DieuKienNgoc08.rCre = rDieuKienNgoc.attribute("Cre08").as_int();

		DieuKienNgoc09.rChaos = rDieuKienNgoc.attribute("Chaos09").as_int();
		DieuKienNgoc09.rBless = rDieuKienNgoc.attribute("Bless09").as_int();
		DieuKienNgoc09.rSoul = rDieuKienNgoc.attribute("Sould09").as_int();
		DieuKienNgoc09.rLife = rDieuKienNgoc.attribute("Life09").as_int();
		DieuKienNgoc09.rCre = rDieuKienNgoc.attribute("Cre09").as_int();

		DieuKienNgoc10.rChaos = rDieuKienNgoc.attribute("Chaos10").as_int();
		DieuKienNgoc10.rBless = rDieuKienNgoc.attribute("Bless10").as_int();
		DieuKienNgoc10.rSoul = rDieuKienNgoc.attribute("Sould10").as_int();
		DieuKienNgoc10.rLife = rDieuKienNgoc.attribute("Life10").as_int();
		DieuKienNgoc10.rCre = rDieuKienNgoc.attribute("Cre10").as_int();


		//LogAdd(LOG_RED, "Chaos01 %d,Bless01 %d,Sould01 %d,Life01 %d,Cre01 %d", this->DieuKienNgoc01.rChaos, this->DieuKienNgoc01.rBles, this->DieuKienNgoc01.rSoul, this->DieuKienNgoc01.rLife, this->DieuKienNgoc01.rCre);

	}
	//===
}

// -------------------------------------------------------------------------------
void TaiSinh::TAISINH_ATIVE(LPOBJ lpObj, TAISINH_REQ *aRecv)
{
	if (aRecv->Number == 1)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien01)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien01);
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc01.rChaos)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc01.rChaos);
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc01.rBless)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc01.rBless);
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc01.rSoul)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc01.rSoul);
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc01.rLife)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc01.rLife);
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc01.rCre)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc01.rCre);
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien01)
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc01.rChaos;
			lpObj->JBless -= this->DieuKienNgoc01.rBless;
			lpObj->JSoul  -= this->DieuKienNgoc01.rSoul;
			lpObj->JLife  -= this->DieuKienNgoc01.rLife;
			lpObj->JCreation -= this->DieuKienNgoc01.rCre;
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh01;

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh01;
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [1]", lpObj->Name);
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [1]", lpObj->Name);
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 1;
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index,0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 2
	if (aRecv->Number == 2)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien02) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien02); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc02.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc02.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc02.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc02.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc02.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc02.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc02.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc02.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc02.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc02.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien02) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc02.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc02.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc02.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc02.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc02.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh02; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh02; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [2]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [2]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 2; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 3
	if (aRecv->Number == 3)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien03) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien03); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc03.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc03.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc03.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc03.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc03.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc03.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc03.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc03.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc03.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc03.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien03) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc03.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc03.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc03.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc03.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc03.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh03; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh03; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [3]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [3]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 3; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 04
	if (aRecv->Number == 4)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien04) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien04); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc04.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc04.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc04.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc04.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc04.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc04.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc04.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc04.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc04.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc04.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien04) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc04.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc04.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc04.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc04.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc04.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh04; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh04; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [4]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [4]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 4; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 05
	if (aRecv->Number == 5)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien05) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien05); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc05.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc05.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc05.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc05.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc05.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc05.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc05.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc05.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc05.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc05.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien05) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc05.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc05.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc05.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc05.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc05.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh05; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh05; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [5]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [5]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 5; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 06
	if (aRecv->Number == 6)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien06) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien06); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc06.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc06.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc06.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc06.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc06.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc06.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc06.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc06.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc06.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc06.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien06) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc06.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc06.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc06.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc06.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc06.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh06; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh06; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [6]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [6]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 6; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 07
	if (aRecv->Number == 7)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien07) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien07); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc07.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc07.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc07.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc07.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc07.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc07.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc07.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc07.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc07.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc07.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien07) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc07.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc07.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc07.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc07.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc07.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh07; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh07; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [7]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [7]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 7; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 08
	if (aRecv->Number == 8)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien08) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien08); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc08.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc08.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc08.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc08.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc08.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc08.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc08.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc08.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc08.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc08.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien08) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc08.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc08.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc08.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc08.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc08.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh08; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh08; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [08]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [08]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 8; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 09
	if (aRecv->Number == 9)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien09) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien09); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc09.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc09.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc09.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc09.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc09.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc09.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc09.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc09.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc09.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc09.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien09) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc09.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc09.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc09.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc09.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc09.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh09; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh09; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [9]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [9]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 9; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	// Lần 10
	if (aRecv->Number == 10)
	{
		if (this->m_Enabled == 0)
		{
			return;
		}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		lpObj->ClickClientSend = GetTickCount();
		// Check level
		if (lpObj->Level < this->m_DieuKienLevel)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn không đủ %d Cấp độ!", this->m_DieuKienLevel);
			return;
		}
		// Check Reset
		if (lpObj->Reset < this->DieuKien10) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Resets!", this->DieuKien10); // Sửa
			return;
		}
		// Check Ngọc
		if (lpObj->JChaos < this->DieuKienNgoc10.rChaos) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Hỗn Nguyên!", this->DieuKienNgoc10.rChaos); // Sửa
			return;
		}
		if (lpObj->JBless < this->DieuKienNgoc10.rBless) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Ước Nguyện!", this->DieuKienNgoc10.rBless); // Sửa
			return;
		}
		if (lpObj->JSoul < this->DieuKienNgoc10.rSoul) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Tâm Linh!", this->DieuKienNgoc10.rSoul); // Sửa
			return;
		}
		if (lpObj->JLife < this->DieuKienNgoc10.rLife) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sinh Mệnh!", this->DieuKienNgoc10.rLife); // Sửa
			return;
		}
		if (lpObj->JCreation < this->DieuKienNgoc10.rCre) // Sửa
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn chưa đủ %d Ngọc Sáng Tạo!", this->DieuKienNgoc10.rCre); // Sửa
			return;
		}
		// Reg
		//---------------------------------------------------------
		if (lpObj->Reset == this->DieuKien10) // Sửa
		{
			//-------------------------------------------------
			lpObj->JChaos -= this->DieuKienNgoc10.rChaos; // Sửa
			lpObj->JBless -= this->DieuKienNgoc10.rBless; // Sửa
			lpObj->JSoul -= this->DieuKienNgoc10.rSoul; // Sửa
			lpObj->JLife -= this->DieuKienNgoc10.rLife; // Sửa
			lpObj->JCreation -= this->DieuKienNgoc10.rCre; // Sửa
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				lpObj->Strength = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 0);
				lpObj->Dexterity = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 1);
				lpObj->Vitality = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 2);
				lpObj->Energy = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 3);
				lpObj->Leadership = gDefaultClassInfo.GetCharacterDefaultStat(lpObj->Class, 4);

				lpObj->LevelUpPoint = this->DiemPointTaiSinh10; // Sửa

			}
			if (this->m_TrungSinh == 1)
			{
				// Sửa
				lpObj->LevelUpPoint += this->DiemPointTrungSinh10; // Sửa
			}
			//-------------------------------------------------
			if (this->m_TaiSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Tái Sinh lần [10]", lpObj->Name); // Sửa
			}
			if (this->m_TrungSinh == 1)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã Trùng Sinh lần [10]", lpObj->Name); // Sửa
			}
			//-------------------------------------------------
			lpObj->Level = 10;
			lpObj->Reset += 1;
			lpObj->rResetLife = 10; // Sửa
			//-------------------------------------------------
			JewelBankDataSend(lpObj->Index);
			GDResetInfoSaveSend(lpObj->Index, 0, 0, 0); // save Reset
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
			GCNewCharacterInfoSend(lpObj);
			//GDCharacterInfoSaveSend(lpObj->Index);
			//-------------------------------------------------
		}
	}
	//--------
	if (aRecv->Number == 100)
	{
		TaiSinhCheckDataSend(lpObj->Index);
		TaiSinhDiemDataSend(lpObj->Index);
		DieuKienNgoc01DataSend(lpObj->Index);
		DieuKienNgoc02DataSend(lpObj->Index);
	}
}

struct TAISINHCHECK_UPDATE
{
	PBMSG_HEAD3 h;
	int m_TaiSinh;
	int m_TrungSinh;
	int m_DieuKienLevel;
	int DieuKien01;
	int DieuKien02;
	int DieuKien03;
	int DieuKien04;
	int DieuKien05;
	int DieuKien06;
	int DieuKien07;
	int DieuKien08;
	int DieuKien09;
	int DieuKien10;
};

void TaiSinhCheckDataSend(int aIndex)
{
	TAISINHCHECK_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 106, sizeof(rSend));
	rSend.m_TaiSinh = gTaiSinh.m_TaiSinh;
	rSend.m_TrungSinh = gTaiSinh.m_TrungSinh;
	rSend.m_DieuKienLevel = gTaiSinh.m_DieuKienLevel;
	rSend.DieuKien01 = gTaiSinh.DieuKien01;
	rSend.DieuKien02 = gTaiSinh.DieuKien02;
	rSend.DieuKien03 = gTaiSinh.DieuKien03;
	rSend.DieuKien04 = gTaiSinh.DieuKien04;
	rSend.DieuKien05 = gTaiSinh.DieuKien05;
	rSend.DieuKien06 = gTaiSinh.DieuKien06;
	rSend.DieuKien07 = gTaiSinh.DieuKien07;
	rSend.DieuKien08 = gTaiSinh.DieuKien08;
	rSend.DieuKien09 = gTaiSinh.DieuKien09;
	rSend.DieuKien10 = gTaiSinh.DieuKien10;
	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

struct TAISINHDIEM_UPDATE
{
	PBMSG_HEAD3 h;
	int DiemPointTaiSinh01;
	int DiemPointTaiSinh02;
	int DiemPointTaiSinh03;
	int DiemPointTaiSinh04;
	int DiemPointTaiSinh05;
	int DiemPointTaiSinh06;
	int DiemPointTaiSinh07;
	int DiemPointTaiSinh08;
	int DiemPointTaiSinh09;
	int DiemPointTaiSinh10;
	int DiemPointTrungSinh01;
	int DiemPointTrungSinh02;
	int DiemPointTrungSinh03;
	int DiemPointTrungSinh04;
	int DiemPointTrungSinh05;
	int DiemPointTrungSinh06;
	int DiemPointTrungSinh07;
	int DiemPointTrungSinh08;
	int DiemPointTrungSinh09;
	int DiemPointTrungSinh10;
};

void TaiSinhDiemDataSend(int aIndex)
{
	TAISINHDIEM_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 107, sizeof(rSend));
	rSend.DiemPointTaiSinh01 = gTaiSinh.DiemPointTaiSinh01;
	rSend.DiemPointTaiSinh02 = gTaiSinh.DiemPointTaiSinh02;
	rSend.DiemPointTaiSinh03 = gTaiSinh.DiemPointTaiSinh03;
	rSend.DiemPointTaiSinh04 = gTaiSinh.DiemPointTaiSinh04;
	rSend.DiemPointTaiSinh05 = gTaiSinh.DiemPointTaiSinh05;
	rSend.DiemPointTaiSinh06 = gTaiSinh.DiemPointTaiSinh06;
	rSend.DiemPointTaiSinh07 = gTaiSinh.DiemPointTaiSinh07;
	rSend.DiemPointTaiSinh08 = gTaiSinh.DiemPointTaiSinh08;
	rSend.DiemPointTaiSinh09 = gTaiSinh.DiemPointTaiSinh09;
	rSend.DiemPointTaiSinh10 = gTaiSinh.DiemPointTaiSinh10;
	rSend.DiemPointTrungSinh01 = gTaiSinh.DiemPointTrungSinh01;
	rSend.DiemPointTrungSinh02 = gTaiSinh.DiemPointTrungSinh02;
	rSend.DiemPointTrungSinh03 = gTaiSinh.DiemPointTrungSinh03;
	rSend.DiemPointTrungSinh04 = gTaiSinh.DiemPointTrungSinh04;
	rSend.DiemPointTrungSinh05 = gTaiSinh.DiemPointTrungSinh05;
	rSend.DiemPointTrungSinh06 = gTaiSinh.DiemPointTrungSinh06;
	rSend.DiemPointTrungSinh07 = gTaiSinh.DiemPointTrungSinh07;
	rSend.DiemPointTrungSinh08 = gTaiSinh.DiemPointTrungSinh08;
	rSend.DiemPointTrungSinh09 = gTaiSinh.DiemPointTrungSinh09;
	rSend.DiemPointTrungSinh10 = gTaiSinh.DiemPointTrungSinh10;
	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

struct DIEUKIENNGOC01_UPDATE
{
	PBMSG_HEAD3 h;
	int DieuKienNgoc01Chaos;
	int DieuKienNgoc01Bless;
	int DieuKienNgoc01Soul;
	int DieuKienNgoc01Life;
	int DieuKienNgoc01Cre;
	int DieuKienNgoc02Chaos;
	int DieuKienNgoc02Bless;
	int DieuKienNgoc02Soul;
	int DieuKienNgoc02Life;
	int DieuKienNgoc02Cre;
	int DieuKienNgoc03Chaos;
	int DieuKienNgoc03Bless;
	int DieuKienNgoc03Soul;
	int DieuKienNgoc03Life;
	int DieuKienNgoc03Cre;
	int DieuKienNgoc04Chaos;
	int DieuKienNgoc04Bless;
	int DieuKienNgoc04Soul;
	int DieuKienNgoc04Life;
	int DieuKienNgoc04Cre;
	int DieuKienNgoc05Chaos;
	int DieuKienNgoc05Bless;
	int DieuKienNgoc05Soul;
	int DieuKienNgoc05Life;
	int DieuKienNgoc05Cre;
};

void DieuKienNgoc01DataSend(int aIndex)
{
	DIEUKIENNGOC01_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 108, sizeof(rSend));
	rSend.DieuKienNgoc01Chaos = gTaiSinh.DieuKienNgoc01.rChaos;
	rSend.DieuKienNgoc01Bless = gTaiSinh.DieuKienNgoc01.rBless;
	rSend.DieuKienNgoc01Soul = gTaiSinh.DieuKienNgoc01.rSoul;
	rSend.DieuKienNgoc01Life = gTaiSinh.DieuKienNgoc01.rLife;
	rSend.DieuKienNgoc01Cre = gTaiSinh.DieuKienNgoc01.rCre;
	//--
	rSend.DieuKienNgoc02Chaos = gTaiSinh.DieuKienNgoc02.rChaos;
	rSend.DieuKienNgoc02Bless = gTaiSinh.DieuKienNgoc02.rBless;
	rSend.DieuKienNgoc02Soul = gTaiSinh.DieuKienNgoc02.rSoul;
	rSend.DieuKienNgoc02Life = gTaiSinh.DieuKienNgoc02.rLife;
	rSend.DieuKienNgoc02Cre = gTaiSinh.DieuKienNgoc02.rCre;
	//--
	rSend.DieuKienNgoc03Chaos = gTaiSinh.DieuKienNgoc03.rChaos;
	rSend.DieuKienNgoc03Bless = gTaiSinh.DieuKienNgoc03.rBless;
	rSend.DieuKienNgoc03Soul = gTaiSinh.DieuKienNgoc03.rSoul;
	rSend.DieuKienNgoc03Life = gTaiSinh.DieuKienNgoc03.rLife;
	rSend.DieuKienNgoc03Cre = gTaiSinh.DieuKienNgoc03.rCre;
	//--
	rSend.DieuKienNgoc04Chaos = gTaiSinh.DieuKienNgoc04.rChaos;
	rSend.DieuKienNgoc04Bless = gTaiSinh.DieuKienNgoc04.rBless;
	rSend.DieuKienNgoc04Soul = gTaiSinh.DieuKienNgoc04.rSoul;
	rSend.DieuKienNgoc04Life = gTaiSinh.DieuKienNgoc04.rLife;
	rSend.DieuKienNgoc04Cre = gTaiSinh.DieuKienNgoc04.rCre;
	//--
	rSend.DieuKienNgoc05Chaos = gTaiSinh.DieuKienNgoc05.rChaos;
	rSend.DieuKienNgoc05Bless = gTaiSinh.DieuKienNgoc05.rBless;
	rSend.DieuKienNgoc05Soul = gTaiSinh.DieuKienNgoc05.rSoul;
	rSend.DieuKienNgoc05Life = gTaiSinh.DieuKienNgoc05.rLife;
	rSend.DieuKienNgoc05Cre = gTaiSinh.DieuKienNgoc05.rCre;
	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

struct DIEUKIENNGOC02_UPDATE
{
	PBMSG_HEAD3 h;
	int DieuKienNgoc06Chaos;
	int DieuKienNgoc06Bless;
	int DieuKienNgoc06Soul;
	int DieuKienNgoc06Life;
	int DieuKienNgoc06Cre;
	int DieuKienNgoc07Chaos;
	int DieuKienNgoc07Bless;
	int DieuKienNgoc07Soul;
	int DieuKienNgoc07Life;
	int DieuKienNgoc07Cre;
	int DieuKienNgoc08Chaos;
	int DieuKienNgoc08Bless;
	int DieuKienNgoc08Soul;
	int DieuKienNgoc08Life;
	int DieuKienNgoc08Cre;
	int DieuKienNgoc09Chaos;
	int DieuKienNgoc09Bless;
	int DieuKienNgoc09Soul;
	int DieuKienNgoc09Life;
	int DieuKienNgoc09Cre;
	int DieuKienNgoc10Chaos;
	int DieuKienNgoc10Bless;
	int DieuKienNgoc10Soul;
	int DieuKienNgoc10Life;
	int DieuKienNgoc10Cre;
};

void DieuKienNgoc02DataSend(int aIndex)
{
	DIEUKIENNGOC02_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 109, sizeof(rSend));
	rSend.DieuKienNgoc06Chaos = gTaiSinh.DieuKienNgoc06.rChaos;
	rSend.DieuKienNgoc06Bless = gTaiSinh.DieuKienNgoc06.rBless;
	rSend.DieuKienNgoc06Soul = gTaiSinh.DieuKienNgoc06.rSoul;
	rSend.DieuKienNgoc06Life = gTaiSinh.DieuKienNgoc06.rLife;
	rSend.DieuKienNgoc06Cre = gTaiSinh.DieuKienNgoc06.rCre;
	//--
	rSend.DieuKienNgoc07Chaos = gTaiSinh.DieuKienNgoc07.rChaos;
	rSend.DieuKienNgoc07Bless = gTaiSinh.DieuKienNgoc07.rBless;
	rSend.DieuKienNgoc07Soul = gTaiSinh.DieuKienNgoc07.rSoul;
	rSend.DieuKienNgoc07Life = gTaiSinh.DieuKienNgoc07.rLife;
	rSend.DieuKienNgoc07Cre = gTaiSinh.DieuKienNgoc07.rCre;
	//--
	rSend.DieuKienNgoc08Chaos = gTaiSinh.DieuKienNgoc08.rChaos;
	rSend.DieuKienNgoc08Bless = gTaiSinh.DieuKienNgoc08.rBless;
	rSend.DieuKienNgoc08Soul = gTaiSinh.DieuKienNgoc08.rSoul;
	rSend.DieuKienNgoc08Life = gTaiSinh.DieuKienNgoc08.rLife;
	rSend.DieuKienNgoc08Cre = gTaiSinh.DieuKienNgoc08.rCre;
	//--
	rSend.DieuKienNgoc09Chaos = gTaiSinh.DieuKienNgoc09.rChaos;
	rSend.DieuKienNgoc09Bless = gTaiSinh.DieuKienNgoc09.rBless;
	rSend.DieuKienNgoc09Soul = gTaiSinh.DieuKienNgoc09.rSoul;
	rSend.DieuKienNgoc09Life = gTaiSinh.DieuKienNgoc09.rLife;
	rSend.DieuKienNgoc09Cre = gTaiSinh.DieuKienNgoc09.rCre;
	//--
	rSend.DieuKienNgoc10Chaos = gTaiSinh.DieuKienNgoc10.rChaos;
	rSend.DieuKienNgoc10Bless = gTaiSinh.DieuKienNgoc10.rBless;
	rSend.DieuKienNgoc10Soul = gTaiSinh.DieuKienNgoc10.rSoul;
	rSend.DieuKienNgoc10Life = gTaiSinh.DieuKienNgoc10.rLife;
	rSend.DieuKienNgoc10Cre = gTaiSinh.DieuKienNgoc10.rCre;
	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}


#endif
