#include "StdAfx.h"
#include "user.h"
#include "DanhHieu.h"
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

#if(DANHHIEU_NEW == 1)

DanhHieu gDanhHieu;
// -------------------------------------------------------------------------------
DanhHieu::DanhHieu() // OK
{
}
// -------------------------------------------------------------------------------
DanhHieu::~DanhHieu() // OK
{
}
// -------------------------------------------------------------------------------
void DanhHieu::DANH_HIEU_OPTION(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}
	//---
	if (lpObj->rDanhHieu == 0)
	{
		
	}
	//-----
	if (lpObj->rDanhHieu == 1)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_01;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_01;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_01;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_01;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_01;
	}
	//-----
	if (lpObj->rDanhHieu == 2)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_02;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_02;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_02;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_02;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_02;
	}
	//-----
	if (lpObj->rDanhHieu == 3)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_03;
		// x3 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_03;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_03;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_03;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_03;
	}
	//-----
	if (lpObj->rDanhHieu == 4)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_04;
		// x4 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_04;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_04;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_04;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_04;
	}
	//-----
	if (lpObj->rDanhHieu == 5)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_05;
		// x5 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_05;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_05;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_05;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_05;
	}
	//-----
	if (lpObj->rDanhHieu == 6)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_06;
		// x6 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_06;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_06;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_06;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_06;
	}
	//-----
	if (lpObj->rDanhHieu == 7)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_07;
		// x7 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_07;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_07;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_07;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_07;
	}
	//-----
	if (lpObj->rDanhHieu == 8)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_08;
		// x8 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_08;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_08;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_08;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_08;
	}
	//-----
	if (lpObj->rDanhHieu == 9)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_09;
		// x9 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_09;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_09;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_09;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_09;
	}
	if (lpObj->rDanhHieu == 10)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_10;
		// x10 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_10;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_10;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_10;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_10;
	}
	//-----
	if (lpObj->rDanhHieu == 11)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_11;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_11;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_11;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_11;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_11;
	}
	//-----
	if (lpObj->rDanhHieu == 12)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_12;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_12;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_12;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_12;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_12;
	}
	//-----
	if (lpObj->rDanhHieu == 13)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_13;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_13;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_13;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_13;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_13;
	}
	//-----
	if (lpObj->rDanhHieu == 14)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_14;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_14;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_14;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_14;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_14;
	}
	//-----
	if (lpObj->rDanhHieu == 15)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_15;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_15;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_15;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_15;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_15;
	}
	//-----
	if (lpObj->rDanhHieu == 16)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_16;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_16;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_16;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_16;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_16;
	}
}
// -------------------------------------------------------------------------------
void DanhHieu::LOAD_TXT()
{
	this->DANH_HIEU_WCOINC_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_01", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_02", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_03", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_04", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_05", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_06", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_07", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_08", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_09", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_10", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_11", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_12", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_13", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_14", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_15", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_16", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SAT_THUONG_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_01", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_02", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_03", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_04", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_05", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_06", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_07", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_08", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_09", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_10", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_11", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_12", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_13", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_14", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_15", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_16", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SAT_THUONGX2_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_01", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_02", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_03", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_04", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_05", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_06", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_07", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_08", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_09", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_10", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_11", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_12", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_13", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_14", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_15", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_16", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));

	this->DANH_HIEU_PHONG_THU_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_01", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_02", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_03", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_04", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_05", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_06", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_07", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_08", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_09", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_10", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_11", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_12", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_13", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_14", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_15", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_16", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));

	this->DANH_HIEU_THE_LUC_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_01", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_02", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_03", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_04", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_05", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_06", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_07", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_08", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_09", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_10", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_11", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_12", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_13", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_14", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_15", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_16", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SD_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_01", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_02", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_03", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_04", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_05", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_06", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_07", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_08", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_09", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_10", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_11", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_12", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_13", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_14", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_15", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_16", 0, gPath.GetFullPath("Custom\\DanhHieu\\CustomDanhHieu.ini"));

}
// -------------------------------------------------------------------------------
void DanhHieu::BUY_DANH_HIEU(LPOBJ lpObj, BUY_DANH_HIEU_REQ *aRecv)
{
	if (aRecv->Number == 1)
	{
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
		//---------------------------------------------------------
		if (lpObj->rDanhHieu < 1)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_01)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_01);
				return;
			}
			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_01), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Thủ Hộ", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 2)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_02)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_02);
				return;
			}
			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_02), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Tiên Phong", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 3)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_03)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_03);
				return;
			}
			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_03), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Vô Úy", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 4)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_04)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_04);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_04), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Thảo Phạt", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 5)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_05)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_05);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_05), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Bất Bại", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 6)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_06)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_06);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_06), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Chí Cao", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 7)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_07)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_07);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_07), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Đồ Lục", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 8)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_08)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_08);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_08), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Tận Diệt", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 9)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_09)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_09);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_09), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Hủy Diệt", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 10)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_10)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_10);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_10), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Chinh Phục", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 11)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_11)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_11);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_11), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Thống Trị", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 12)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_12)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_12);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_12), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Cứu Thế", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 13)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_13)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_13);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_13), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Phá Quân Giả", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 14)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_14)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_14);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_14), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Tiêm Diệt Giả", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 15)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_15)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_15);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_15), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Bất Diệt Giả", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rDanhHieu < 16)
		{
			if (lpObj->rDanhHieu > 16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			if (lpObj->Coin1 < this->DANH_HIEU_WCOINC_16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài khoản không đủ %d WCoinC", this->DANH_HIEU_WCOINC_16);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC_16), 0, 0, "Danh Hieu");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rDanhHieu += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân vật [%s] đã nâng cấp Danh Hiệu lên Sáng Thế Giả", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
	}
}

struct DANHHIEU_UPDATE
{
	PBMSG_HEAD3 h;
	int DANH_HIEU_WCOINC_01;
	int DANH_HIEU_WCOINC_02;
	int DANH_HIEU_WCOINC_03;
	int DANH_HIEU_WCOINC_04;
	int DANH_HIEU_WCOINC_05;
	int DANH_HIEU_WCOINC_06;
	int DANH_HIEU_WCOINC_07;
	int DANH_HIEU_WCOINC_08;
	int DANH_HIEU_WCOINC_09;
	int DANH_HIEU_WCOINC_10;
	int DANH_HIEU_WCOINC_11;
	int DANH_HIEU_WCOINC_12;
	int DANH_HIEU_WCOINC_13;
	int DANH_HIEU_WCOINC_14;
	int DANH_HIEU_WCOINC_15;
	int DANH_HIEU_WCOINC_16;
};

void DanhHieuDataSend(int aIndex)
{
	DANHHIEU_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 15, sizeof(rSend));

	rSend.DANH_HIEU_WCOINC_01 = gDanhHieu.DANH_HIEU_WCOINC_01;
	rSend.DANH_HIEU_WCOINC_02 = gDanhHieu.DANH_HIEU_WCOINC_02;
	rSend.DANH_HIEU_WCOINC_03 = gDanhHieu.DANH_HIEU_WCOINC_03;
	rSend.DANH_HIEU_WCOINC_04 = gDanhHieu.DANH_HIEU_WCOINC_04;
	rSend.DANH_HIEU_WCOINC_05 = gDanhHieu.DANH_HIEU_WCOINC_05;
	rSend.DANH_HIEU_WCOINC_06 = gDanhHieu.DANH_HIEU_WCOINC_06;
	rSend.DANH_HIEU_WCOINC_07 = gDanhHieu.DANH_HIEU_WCOINC_07;
	rSend.DANH_HIEU_WCOINC_08 = gDanhHieu.DANH_HIEU_WCOINC_08;
	rSend.DANH_HIEU_WCOINC_09 = gDanhHieu.DANH_HIEU_WCOINC_09;
	rSend.DANH_HIEU_WCOINC_10 = gDanhHieu.DANH_HIEU_WCOINC_10;
	rSend.DANH_HIEU_WCOINC_11 = gDanhHieu.DANH_HIEU_WCOINC_11;
	rSend.DANH_HIEU_WCOINC_12 = gDanhHieu.DANH_HIEU_WCOINC_12;
	rSend.DANH_HIEU_WCOINC_13 = gDanhHieu.DANH_HIEU_WCOINC_13;
	rSend.DANH_HIEU_WCOINC_14 = gDanhHieu.DANH_HIEU_WCOINC_14;
	rSend.DANH_HIEU_WCOINC_15 = gDanhHieu.DANH_HIEU_WCOINC_15;
	rSend.DANH_HIEU_WCOINC_16 = gDanhHieu.DANH_HIEU_WCOINC_16;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}


#endif
