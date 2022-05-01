#include "stdafx.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "ChoTroi.h"
#include "NPCRuud.h"
#include "Achievements.h"
#include "NewInterface.h"
#include "ResetSystem.h"
#include "GrandResetSystem.h"
#include "ServerInfo.h"
#include "ChangeClass.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "MuHelper.h"
#include "WindowsStruct.h"
#include "CustomRankUser.h"
#include "MiniMap.h"
#include "SItemOption.h"
#include "Other.h"
#include "CustomLuckySpin.h"
#include "JewelBank.h"
#include "CustomOfflineMode.h"
//#include "CustomThuongGia.h"
#include "CustomFont.h"
#include "ShopSearch.h"
#include "LeoThap.h"
#include "Bytes.h"
#include "SCharFrameHIght.h"
#include "NewUIMyInventory.h"
#include "WindowsQuest.h"
#include "Ranking.h"
#include "MenuGame.h"
#include "DanhHieu.h"
#include "TuLuyen.h"
#include "VipNhanVat.h"
#include "VipTaiKhoan.h"
#include "NguHanh.h"
#include "KinhMach.h"
#include "MocNap.h"
#include "TaiSinh.h"
#include "DangKyTaiKhoan.h"

Interface gInterface;

Interface::Interface()
{
}

Interface::~Interface()
{
}
void Interface::RenderObjectSystem()
{
	///emoji
	InitEncDec();
	///
	if (gProtect.m_MainInfo.MonitorMS == 1){
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if (gProtect.m_MainInfo.MonitorFPS == 1){
		gInterface.iniciador = 1;
	}



	this->BindObject(eCONFIRM_MUUNBTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_MUUNBTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eTVTHUD, 0x9912, 200, 27, -1, -1);

#if(LEOTHAP == 1)
	// Leo thap
	this->BindObject(eLEOTHAP_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eLEOTHAP_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eLEOTHAP_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eLEOTHAP_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eLEOTHAP_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eLEOTHAP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eLEOTHAP_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE1, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE2, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE3, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE4, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE5, 0x7A5B, 54, 30, -1, -1);
#endif

#if(OFFLINE_MODE_NEW)
	this->BindObject(eOFFEXP_MAIN, 31461, 900, 1000, -1, -1);  // 31461
	this->BindObject(eOFFEXP_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eOFFEXP_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eOFFEXP_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eOFFEXP_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eOFFEXP_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eOFFEXP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_BUFF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_ZEN, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_JEWELS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_EXC, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_ANC, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_SELECTED_HELPER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_BTN_OK, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eOFFEXP_SKILL1, 0x7A4C, 20, 28, -1, -1);
	this->BindObject(eOFFEXP_SKILL2, 0x7A4C, 20, 28, -1, -1);
	this->BindObject(eOFFEXP_SKILL3, 0x7A4C, 20, 28, -1, -1);
#endif
	//**********************************************************************//
	//----------------------------------------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
	this->BindObject(eSACHTHUOCTINH_INTERFACE, 31461, 35, 35, -1, -1);  // 31461
#endif
#if(PHUKIEN_NEW == 1)
	this->BindObject(ePHUKIEN1_INTERFACE, 31461, 16, 24, -1, -1);  // 31461
	this->BindObject(ePHUKIEN2_INTERFACE, 31461, 16, 24, -1, -1);  // 31461
#endif
	//----------------------------------------------------------------------------------------
#if(MUUNAFK == 1)
	//1-04-2022
	this->BindObject(eHOIMAU_MUUN_STAMINA, 31461, 16, 24, -1, -1);
	this->BindObject(eHOIMAU_MUUN_WCOINCLAIM, 31461, 16, 24, -1, -1);
#endif
		//----------------------------------------------------------------------------------------

	///emoji
	if (gProtect.m_MainInfo.PutoEllQueLoLea != 0)
	{
		myheart::MUEmoji::Init(TEXTURE_EMOJI_LIST_ARROW, TEXTURE_EMOJI_LIST_ON, TEXTURE_EMOJI_LIST_BTN, 20, 14, 4, 0);
		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST1, 361);
		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST2, 309);
		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST3, 118);
	}
	////
	///////////////////////////
#if(CHARACTER_NEW)
	this->BindObject(TINHNANG_CHARACTER, 31461, 35, 14, -1, -1);  // 31461
#if(DEV_PLAYERSHOP == 1)
	this->BindObject(CHOTROI_CHARACTER, 31461, 35, 14, -1, -1);  // 31461
#endif
	this->BindObject(MUUN_CHARACTER, 31461, 35, 14, -1, -1);  // 31461

#if(SHOPSEARCH==TRUE)
	this->BindObject(STORE_CHARACTER, 31461, 35, 14, -1, -1);  // 31461
#endif

	this->BindObject(eAUTORESET, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eATTACK, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eOFFATTACK, 31461, 35, 14, -1, -1);  // 31461

	this->BindObject(TINHNANG_MAIN, 31461, 900, 1000, -1, -1);  // 31461

	this->BindObject(BUTTON_YES, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO, 31461, 35, 14, -1, -1);  // 31461

	this->BindObject(BUTTON_YES1, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO1, 31461, 35, 14, -1, -1);  // 31461

	this->BindObject(BUTTON_YES2, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO2, 31461, 35, 14, -1, -1);  // 31461

	this->BindObject(BUTTON_YES3, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO3, 31461, 35, 14, -1, -1);  // 31461
#endif
#if(OANTUTY)
	//
	this->BindObject(eRock, 0x9323, 36, 28, -1, -1);
	this->BindObject(ePaper, 0x9324, 36, 28, -1, -1);
	this->BindObject(eScissors, 0x9325, 36, 28, -1, -1);
#endif
	//----------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	this->BindObject(eCheck, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUnCheck, 0x9992, 15, 15, -1, -1);

	this->BindObject(EXBEXO_THUONG_GIA_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(EXBEXO_THUONG_GIA_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eTHUONG_GIA1, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eTHUONG_GIA2, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eTHUONG_GIA3, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eTHUONGGIA_01, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eTHUONGGIA_02, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eTHUONGGIA_03, 0x7A5E, 108, 29, -1, -1);

#if(VIP_TAI_KHOAN_NEW == 1)
	this->BindObject(EXBEXO_VIPTAIKHOAN_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(EXBEXO_VIPTAIKHOAN_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVIPTAIKHOAN_SEND_01, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVIPTAIKHOAN_SEND_03, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVIPTAIKHOAN_SEND_07, 0x7A5E, 108, 29, -1, -1);
#endif

#if(THUE_VIP_NEW == 1)
	this->BindObject(EXBEXO_VIPNHANVAT_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(EXBEXO_VIPNHANVAT_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVIPNHANVAT_SEND_01, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVIPNHANVAT_SEND_02, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVIPNHANVAT_SEND_03, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVIPNHANVAT_SEND_04, 0x7A5E, 108, 29, -1, -1);
#endif

	//----------------------------------------------------------------------------------------
#if(DANH_HIEU_NEW == 1)
	this->BindObject(EXBEXO_DANH_HIEU_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eDANH_HIEU2, 0x7903, 25, 40, -1, -1);
	this->BindObject(eDANH_HIEU1, 0x7904, 25, 40, -1, -1);
#endif

#if(TU_LUYEN_NEW == 1)
	this->BindObject(EXBEXO_TU_LUYEN_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_TU_LUYEN_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_TU_LUYEN_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eTU_LUYEN2, 0x7903, 25, 40, -1, -1);
	this->BindObject(eTU_LUYEN1, 0x7904, 25, 40, -1, -1);
#endif

#if(KINH_MACH_NEW == 1)
	this->BindObject(EXBEXO_KINHMACH_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_KINHMACH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eKINHMACH1, 10168, 70, 70, -1, -1);
	this->BindObject(eKINHMACH2, 10169, 70, 70, -1, -1);
	this->BindObject(eKINHMACH3, 10170, 70, 70, -1, -1);
	this->BindObject(eKINHMACH4, 10171, 70, 70, -1, -1);
	this->BindObject(eKINHMACH5, 10172, 70, 70, -1, -1);
	this->BindObject(eKINHMACH6, 10173, 70, 70, -1, -1);
	this->BindObject(eKINHMACH7, 10174, 70, 70, -1, -1);
	this->BindObject(eKINHMACH8, 10175, 70, 70, -1, -1);
#endif

#if(NGU_HANH_NEW == 1)
	this->BindObject(EXBEXO_NGUHANH_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_NGUHANH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eNGUHANH, 0x7A5E, 108, 29, -1, -1);
#endif
	//----------------------------------------------------------------------------------------
	this->BindObject(eRankPANEL_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eEventTimePANEL_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eSHOWTIME_MAIN, 31461, 640, 419, -1, -1);  // 31461
	//----------------------------------------------------------------------------------------
#if(VONGQUAY_NEW)
	this->BindObject(eLuckySpin, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eLuckySpinRoll, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eLuckySpinClose, 0x7EC5, 36, 29, -1, -1);
#endif
	//----------------------------------------------------------------------------------------
	//--
	this->BindObject(eTIME, 30847, 131, 70, -10, 359);
	//--
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
#if(RANKINGGOC == 1)
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
#endif
	//--
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	//Custom Store
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);

	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);

	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	this->Data[eTIME].OnShow = true;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);

	switch (gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{*/
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		//}
		/*//-- Interface MiniMapa 97/99
		//this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);
		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);*/
		//---
		if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 383.5);
			this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 383.5);
			this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
			this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
			this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
			this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
			this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		}
		//-> Custom Interface S2
		if (gProtect.m_MainInfo.CustomInterfaceType == 2){
			this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{*/
		this->BindObject(eMenu, 51522, 19, 19, -1, -1);
		this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		//}
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{*/
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		//}
		break;
	}
	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
	}

	this->BindObject(eCHANGINGCLASS_MAIN, 31461, 640, 419, -1, -1);  // 31461
	//this->BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	//this->BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	//this->BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);
	//---

	this->BindObject(OBJECT_PARTYSETTINGS_MAIN, 31461, 222, 345 + 30, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_TITLE, 31461, 230, 67, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_FRAME, 31461, 230, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_FOOTER, 31461, 230, 50, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ONLY_ALLIANCE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_PASSWORD, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);

	this->BindObject(OBJECT_PARTYSEARCH_MAIN, 31461, 222, 345, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_TITLE, 31461, 230, 67, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_FRAME, 31461, 230, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_FOOTER, 31461, 230, 50, -1, -1);

	this->BindObject(OBJECT_PARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);

	this->BindObject(OBJECT_PARTYPASSWORD_MAIN, 0x7A5A, 222, 122, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_TEXTBOX, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_IMAGE1, 0x7898, -1, -1, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_IMAGE2, 0x7899, -1, -1, -1, -1);

	memset(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, 0, sizeof(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue));


	this->BindObject(eWAREHOUSE_MAIN, 0x7A5A, 222, 211, -1, -1);
	this->BindObject(eWAREHOUSE_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eWAREHOUSE_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eWAREHOUSE_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eWAREHOUSE_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eWAREHOUSE_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM1, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM2, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM3, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM4, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM5, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM6, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM7, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM8, 0x7A5E, 106, 29, -1, -1);
	

	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}

	gNewInterface.Load();

	//20-03-2022 
	gCustomEventTime.Bind();

#if(MENU_NEW == 1)
	G_BEXO_MENU.BIND();
#endif

#if(NGANHANGNGOC_NEW == 1)
	gJewelBank.Bind();
#endif

#if(DEV_DAMAGE_TABLE)
	this->m_EnableDamageTable = false;
#endif

#if(SHOPSEARCH==TRUE)
	g_PersonalShopEx.BindImages();
#endif

#if(DEV_PLAYERSHOP == 1)
	g_ChoTroi.Bind();
#endif

#if(RANKING_NEW == 1)
	gRanking.Bind();
#endif

#if(NHIEMVU_NEW == 1)
	if (gProtect.m_MainInfo.NhiemVu == 1)
	{
		g_ExWinQuestSystem.BindImages();
	}
#endif

#if (ARCHIVEMENT == 1)
	if (gProtect.m_MainInfo.ThanhTuu == 1)
	{
		gAchievements.BindImages();
	}
#endif
#if (MOCNAP == 1)
	if (gProtect.m_MainInfo.MocNap == 1)
	{
		G_BEXO_MOCNAP.BIND();
	}
#endif
#if (TAISINH == 1)
	if (gProtect.m_MainInfo.TaiSinhTrungSinh == 1)
	{
		G_BEXO_TAISINH.BIND();
	}
#endif

#if(DKTK1 == 1)
	gDangKyTaiKhoan.bind();
#endif

}

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 21, v10 + 367, 20, 1, "Zen");
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 106, v10 + 367, 20, 1, "GP");
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 21, v10 + 380, 20, 1, "WC");
	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 103, v10 + 380, 20, 1, "WCP");
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}

void Interface::LoadImages()
{

	pDrawMessage("Phát triển bởi TDA-Team!", 1);
	pLoadSomeForm();

	LoadBitmapA("Interface\\login_auto.tga", 531141, GL_NEAREST, GL_CLAMP, 1, 0);
	
#if(DANH_HIEU_NEW)
	pLoadImage("Custom\\DanhHieu\\Main.tga", 0x0899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\DanhHieu\\Successful.tga", 0x0898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\DanhHieu\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		pLoadImage("Custom\\DanhHieu\\SuccessNo.tga", 0x0896, 0x2601, 0x2901, 1, 0);
	}
#endif

	pLoadImage("Custom\\Interface\\PartySearch_Title.tga", 0x7898, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Info_Block.tga", 0x7899, GL_LINEAR, GL_REPEAT, 1, 0);

#if(DEV_PLAYERSHOP == 1)
	pLoadImage("Custom\\Interface\\itembackpanel.tga", ex_SMITHY_ITEM, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\newui_cha_textbox03.tga", ex_TEXT_BOX3, 0x2601, 0x2900, 1, 0);
#endif

	pLoadImage("Interface\\in_main_number0_21.tga", 10004, 0x2601, 0x2900, 1, 0); //

	pLoadImage("Custom\\Interface\\BankButton.tga", 10005, 0x2601, 0x2900, 1, 0); //

	pLoadImage("Custom\\Interface\\tvt_hud.tga", 0x9912, 0x2601, 0x2900, 1, 0);

#if(SACHTHUOCTINH_NEW)
	pLoadImage("Interface\\GFx\\ex700\\Interface\\SachThuocTinh_UI.tga", 10000, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\ex700\\Interface\\Button-ThuocTinh.tga", 10003, 0x2601, 0x2900, 1, 0); // NÚT XÓA HÒM ĐỒ
#endif

	pLoadImage("Custom\\Interface\\SmallBackground\\ChieuNgang.tga", 0x501A, 0x2601, 0x2900, 1, 0); // THANH NGANG
	pLoadImage("Custom\\Interface\\SmallBackground\\ChieuDoc.tga", 0x502A, 0x2601, 0x2900, 1, 0); // THANH DỌC
	
	pLoadImage("Interface\\GFx\\Upgrade\\PetInventoryFrame_I3.tga", 0xF1003, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\check.jpg", 0x9991, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\uncheck.jpg", 0x9992, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\Button-30-20.tga", 10099, 0x2601, 0x2900, 1, 0);

#if(DANH_HIEU_NEW == 1)
	pLoadImage("Custom\\DanhHieu\\1ThuHo\\1.tga", 10100, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\2TienPhong\\1.tga", 10200, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\3VoUy\\1.tga", 10300, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\4ThaoPhat\\1.tga", 10400, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\5BatBai\\(1).tga", 10500, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\6ChiCao\\(1).tga", 10600, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\7DoLuc\\(1).tga", 10700, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\8TanDiet\\(1).tga", 10800, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\9HuyDiet\\(1).tga", 10900, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\10ChinhPhuc\\(1).tga", 11000, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\11ThongTri\\(1).tga", 11100, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\12CuuThe\\(1).tga", 11200, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\13PhaQuanGia\\(1).tga", 11300, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\14TiemDietGia\\(1).tga", 11400, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\15BatDietGia\\(1).tga", 11500, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\16SangTheGia\\(1).tga", 11600, 0x2601, 0x2900, 1, 0);
#endif

	pLoadImage("Custom\\TuLuyen\\TuLuyen_1.tga", 10128, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_2.tga", 10129, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_3.tga", 10130, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_4.tga", 10131, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_5.tga", 10132, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_6.tga", 10133, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_7.tga", 10134, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_8.tga", 10135, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_9.tga", 10136, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_10.tga", 10137, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_11.tga", 10138, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_12.tga", 10139, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_13.tga", 10140, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_14.tga", 10141, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_15.tga", 10142, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_16.tga", 10143, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_17.tga", 10144, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_18.tga", 10145, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_19.tga", 10146, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_20.tga", 10147, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_21.tga", 10148, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_22.tga", 10149, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_23.tga", 10150, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_24.tga", 10151, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_25.tga", 10152, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_26.tga", 10153, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_27.tga", 10154, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_28.tga", 10155, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_29.tga", 10156, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_30.tga", 10157, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_31.tga", 10158, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_32.tga", 10159, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_33.tga", 10160, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_34.tga", 10161, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_35.tga", 10162, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_36.tga", 10163, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_37.tga", 10164, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_38.tga", 10165, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_39.tga", 10166, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\TuLuyen\\TuLuyen_40.tga", 10167, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\KinhMach\\KinhMach_1.tga", 10168, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_2.tga", 10169, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_3.tga", 10170, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_4.tga", 10171, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_5.tga", 10172, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_6.tga", 10173, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_7.tga", 10174, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\KinhMach\\KinhMach_8.tga", 10175, 0x2601, 0x2900, 1, 0);

#if(THUE_VIP_NEW == 1)
	pLoadImage("Custom\\VipNhanVat\\vipbac.tga", 10176, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\VipNhanVat\\vipdong.tga", 10177, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\VipNhanVat\\vipvang.tga", 10178, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\VipNhanVat\\vipkimcuong.tga", 10179, 0x2601, 0x2900, 1, 0);
#endif

	pLoadImage("Custom\\NguHanh\\1.tga", 0x9596, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\NguHanh\\2.tga", 0x9597, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\NguHanh\\3.tga", 0x9598, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\NguHanh\\4.tga", 0x9599, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\NguHanh\\5.tga", 0x9600, 0x2601, 0x2900, 1, 0);

	//////////emoji
	if ( gProtect.m_MainInfo.PutoEllQueLoLea != 0)
	{
		pLoadImage("Interface\\GFx\\emojis_f.tga", TEXTURE_EMOJI_LIST1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\emojis_f2.tga", TEXTURE_EMOJI_LIST2, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\emojis_f3.tga", TEXTURE_EMOJI_LIST3, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\emoji_list_btn.tga", TEXTURE_EMOJI_LIST_BTN, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\newui_chat_emoji_on.jpg", TEXTURE_EMOJI_LIST_ON, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\btn_arrow.tga", TEXTURE_EMOJI_LIST_ARROW, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\newui_chat_back.jpg", 31279, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		// CAMERA 3D
		pLoadImage("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);
	}
	//--
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
	}

	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}

	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	//--Interface MiniMap 97/99/S2/S6
	if(MiniMapType == 0)
	{
	pLoadImage("Custom\\Maps\\edBtUcx_old.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\timeold.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--Interface MiniMap ex700/Legends
	if(MiniMapType == 1)
	{
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\time700.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--
	pLoadImage("Custom\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold
	

	//=== CTC Mini UI ==//
	pLoadImage("Custom\\CTCMini\\UiCtc.tga", 32584, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\CTCMiniMap.tga", 32583, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\StartCTC.tga", 32585, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\WinCTC.tga", 32586, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\LoseCTC.tga", 32589, 9729, 10496, 1, 0); //Trung voi ID effect 32587
	pLoadImage("Custom\\CTCMini\\DialogCTC.tga", 32588, 9729, 10496, 1, 0);
     pLoadImage("Custom\\CTCMini\\CharPoint.tga", 32506, 9729, 10496, 1, 0);
     pLoadImage("Custom\\CTCMini\\OtherCharPoint.tga", 32507, 9729, 10496, 1, 0);
	//==============================//

	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	if(gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	//--
	//Party Bar 97/99/S2/S6
	if(MiniMapType == 0)
	{
	LoadBitmapA("Custom\\Party\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	//--Party Bar ex700/Legends
	if(MiniMapType == 1)
	{
	LoadBitmapA("Custom\\Party\\Ex700\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
    pLoadImage("Custom\\Party\\Ex700\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}

	//--
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);
	#if(OANTUTY)
	pLoadImage("Custom\\RPSMode\\rock.tga", 0x9323, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RPSMode\\paper.tga", 0x9324, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RPSMode\\scissors.tga", 0x9325, 0x2601, 0x2900, 1, 0);
#endif
	//Interface Minimapa 97/99
	//LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar ex700/Legends
	if(MiniMapType == 1)
	{
	LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar 97/99/S2/S6
	if(MiniMapType == 0)
	{
	LoadBitmapA("Custom\\Party\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//--
	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
	case 1:
	case 2:
	if(gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2){
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		
		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
	}
		break;
	case 3:
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}//--Finaliza
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3_E.tga", 61536, GL_LINEAR, GL_CLAMP, 1, 0); //-- Windows Party/Pet/Gens and Others
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3_C.tga", 61558, GL_LINEAR, GL_CLAMP, 1, 0); //-- Window Chaos Mix
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); //Boton Shop Ruud
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- MuHelper ex700
	if(gProtect.m_MainInfo.MuHelperType == 1)
	{
	//-- Folder MacroUI
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//RuudCoin Interface S6/97/S2/Legends
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
	LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Interface\\RuudHeadOld.tga", 0x7877, 0x2601, 0x2901,1,0);
	}
	else if (gProtect.m_MainInfo.CustomInterfaceType == 3 ||gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	LoadBitmapA("Custom\\Interface\\RuudHeadLegends.tga", 0x7877, 0x2601, 0x2901,1,0);
	}
	//TimerBar
	LoadBitmapA("Custom\\Interface\\TimeBarex700.tga", 0x7878, 0x2601, 0x2901,1,0);
	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x7879, 0x2601, 0x2901,1,0);

	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	//--
	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	pLoadImage("Custom\\Interface\\Title.tga", 400001, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\PartySearch_Title.tga", 400002, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Info_Block.tga", 400003, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\newui_cha_textbox01.tga", 400004, 0x2601, 0x2900, 1, 0);

	pLoadImage("Logo\\Mu-logo_g.jpg",  531019, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Logo\\Mu-logo.tga",  531018, GL_LINEAR, GL_REPEAT, 1, 0);

#if (ARCHIVEMENT == 1)
	if (gProtect.m_MainInfo.ThanhTuu == 1)
	{
		gAchievements.LoadImages();
	}
#endif
	//--
	pLoadSomeForm();
}

void Interface::WindowsKG()
{
	if (gProtect.m_MainInfo.CustomInterfaceType >= 0)
	{
		char interaltas[500];
		if (gInterface.validar == 0){
			if (gInterface.ultimo_Ping > 0)
			{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Name: %s || Level: %d || Reset: %d || WCoins: %d || || WCPCoins: %d || GPCoins: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
			}
			else{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Name: %s || Level: %d || Reset: %d || WCoins: %d || WCPCoins: %d || GPCoins: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
			}
			SetWindowText(pGameWindow, interaltas);
		}
	}
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

void Interface::Work()
{


#if(RECONNECT == 1)
	ReconnectMainProc();
#endif

#if(ANTIHACK == 1)
	//---------------------------------------------------------
	if (*(BYTE *)0x004DA3E0 != 40)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 1", "[ExBexo]", ERROR);	  //hack speed
		ExitProcess(0);
	}
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 2", "[ExBexo]", ERROR);	 //hithack
		ExitProcess(0);
	}

	if (*(BYTE*)0x005DE171 != 137 || *(BYTE*)0x005DE172 != 138
		|| *(BYTE*)0x005DE173 != 160 || *(BYTE*)0x005DE174 != 0
		|| *(BYTE*)0x005DE175 != 0 || *(BYTE*)0x005DE176 != 0
		|| *(BYTE*)0x005B5FFF != 245 || *(BYTE*)0x005B6000 != 0
		|| *(BYTE*)0x005B6001 != 0 || *(BYTE*)0x005B6002 != 0)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 2", "[ERROR]", ERROR);	 //delay hack
		ExitProcess(0);
	}

	if (*(BYTE*)0x005A1797 != 141 || *(BYTE*)0x005A1798 != 212
		|| *(BYTE*)0x005A1799 != 247 || *(BYTE*)0x005A179A != 255
		|| *(BYTE*)0x005A179B != 255
		|| *(BYTE*)0x005AD824 != 141 || *(BYTE*)0x005AD825 != 172 || *(BYTE*)0x005AD826 != 239 || *(BYTE*)0x005AD827 != 255 || *(BYTE*)0x005AD828 != 255
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E != 28 || *(BYTE*)0x005AF96F != 142 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		|| *(BYTE*)0x0059C79D != 141 || *(BYTE*)0x0059C79E != 212 || *(BYTE*)0x0059C79F != 247 || *(BYTE*)0x0059C7A0 != 255 || *(BYTE*)0x0059C7A1 != 255
		|| *(BYTE*)0x005AFBF1 != 141 || *(BYTE*)0x005AFBF2 != 4 || *(BYTE*)0x005AFBF3 != 134 || *(BYTE*)0x005AFBF4 != 255 || *(BYTE*)0x005AFBF5 != 255
		|| *(BYTE*)0x0059CEDC != 141 || *(BYTE*)0x0059CEDD != 228 || *(BYTE*)0x0059CEDE != 247 || *(BYTE*)0x0059CEDF != 255 || *(BYTE*)0x0059CEE0 != 255
		|| *(BYTE*)0x005B1CCB != 141 || *(BYTE*)0x005B1CCC != 4 || *(BYTE*)0x005B1CCD != 151 || *(BYTE*)0x005B1CCE != 255 || *(BYTE*)0x005B1CCF != 255
		|| *(BYTE*)0x005B170A != 141 || *(BYTE*)0x005B170B != 52 || *(BYTE*)0x005B170C != 175 || *(BYTE*)0x005B170D != 255 || *(BYTE*)0x005B170E != 255
		|| *(BYTE*)0x005B0C07 != 141 || *(BYTE*)0x005B0C08 != 124 || *(BYTE*)0x005B0C09 != 207 || *(BYTE*)0x005B0C0A != 255 || *(BYTE*)0x005B0C0B != 255
		|| *(BYTE*)0x005B187C != 141 || *(BYTE*)0x005B187D != 36 || *(BYTE*)0x005B187E != 167 || *(BYTE*)0x005B187F != 255 || *(BYTE*)0x005B1880 != 255
		|| *(BYTE*)0x0059D1E2 != 141 || *(BYTE*)0x0059D1E3 == 144 || *(BYTE*)0x0059D1E4 != 231 || *(BYTE*)0x0059D1E5 != 255 || *(BYTE*)0x0059D1E6 != 255
		|| *(BYTE*)0x005B1AA9 != 141 || *(BYTE*)0x005B1AAA != 20 || *(BYTE*)0x005B1AAB != 159 || *(BYTE*)0x005B1AAC != 255 || *(BYTE*)0x005B1AAD != 255
		|| *(BYTE*)0x005AC554 != 141 || *(BYTE*)0x005AC555 != 116 || *(BYTE*)0x005AC556 != 182 || *(BYTE*)0x005AC557 != 255 || *(BYTE*)0x005AC558 != 255
		|| *(BYTE*)0x0059D6AD != 141 || *(BYTE*)0x0059D6AE != 204 || *(BYTE*)0x0059D6AF != 239 || *(BYTE*)0x0059D6B0 != 255 || *(BYTE*)0x0059D6B1 != 255
		|| *(BYTE*)0x005AC22C != 141 || *(BYTE*)0x005AC22D != 252 || *(BYTE*)0x005AC22E != 190 || *(BYTE*)0x005AC22F != 255 || *(BYTE*)0x005AC230 != 255
		|| *(BYTE*)0x00534FD2 != 141 || *(BYTE*)0x00534FD3 == 144 || *(BYTE*)0x00534FD4 != 247 || *(BYTE*)0x00534FD5 != 255 || *(BYTE*)0x00534FD6 != 255
		|| *(BYTE*)0x0059DED9 != 141 || *(BYTE*)0x0059DEDA == 144 || *(BYTE*)0x0059DEDB != 239 || *(BYTE*)0x0059DEDC != 255 || *(BYTE*)0x0059DEDD != 255
		|| *(BYTE*)0x0059DC87 != 141 || *(BYTE*)0x0059DC88 == 144 || *(BYTE*)0x0059DC89 != 247 || *(BYTE*)0x0059DC8A != 255 || *(BYTE*)0x0059DC8B != 255
		//hetsum
		|| *(BYTE*)0x005B2C98 != 141 || *(BYTE*)0x005B2C99 != 108 || *(BYTE*)0x005B2C9A != 110 || *(BYTE*)0x005B2C9B != 255 || *(BYTE*)0x005B2C9C != 255
		//Rf damdat
		|| *(BYTE*)0x0059F471 != 141 || *(BYTE*)0x0059F472 != 36 || *(BYTE*)0x0059F473 != 191 || *(BYTE*)0x0059F474 != 255 || *(BYTE*)0x0059F475 != 255
		//vatnga
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E == 144 || *(BYTE*)0x005AF96F == 144 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		//AALH1
		|| *(BYTE*)0x0059F211 != 141 || *(BYTE*)0x0059F212 != 68 || *(BYTE*)0x0059F213 != 199 || *(BYTE*)0x0059F214 != 255 || *(BYTE*)0x0059F215 != 255

		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 90 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		//manhlong		
		|| *(BYTE*)0x0050F357 != 141 || *(BYTE*)0x0050F358 != 180 || *(BYTE*)0x0050F359 != 239 || *(BYTE*)0x0050F35A != 255 || *(BYTE*)0x0050F35B != 255

		//MG
		|| *(BYTE*)0x005ADE26 != 141 || *(BYTE*)0x005ADE27 != 116 || *(BYTE*)0x005ADE28 != 223 || *(BYTE*)0x005ADE29 != 255 || *(BYTE*)0x005ADE2A != 255
		|| *(BYTE*)0x005ADACC != 141 || *(BYTE*)0x005ADACD != 140 || *(BYTE*)0x005ADACE != 231 || *(BYTE*)0x005ADACF != 255 || *(BYTE*)0x005ADAD0 != 255
		|| *(BYTE*)0x005AE854 != 141 || *(BYTE*)0x005AE855 != 188 || *(BYTE*)0x005AE856 != 206 || *(BYTE*)0x005AE857 != 255 || *(BYTE*)0x005AE858 != 255
		//DL
		|| *(BYTE*)0x005AF1B1 != 141 || *(BYTE*)0x005AF1B2 != 92 || *(BYTE*)0x005AF1B3 != 166 || *(BYTE*)0x005AF1B4 != 255 || *(BYTE*)0x005AF1B5 != 255
		|| *(BYTE*)0x005AE1B5 != 141 || *(BYTE*)0x005AE1B6 != 236 || *(BYTE*)0x005AE1B7 != 214 || *(BYTE*)0x005AE1B8 != 255 || *(BYTE*)0x005AE1B9 != 255
		//saitama
		|| *(BYTE*)0x0064CF51 != 51 || *(BYTE*)0x0064CF52 != 1 || *(BYTE*)0x0064CF53 != 0 || *(BYTE*)0x0064CF54 != 0)

	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 3", "[ERROR]", ERROR);	 //Xdame
		ExitProcess(0);
	}

	if (*(BYTE*)0x00564D30 == 233)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 4", "[ERROR]", ERROR);	 //cahy nhanh
		ExitProcess(0);
	}
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)// loi khi su dung /Dance
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 5", "[ERROR]", ERROR);	 //hithack ok
		ExitProcess(0);
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if ((*(BYTE *)0x006407C0 == 195)		//khang day lui ok
			|| (*(BYTE *)0x005528A0 == 195)	//khang sat thuong ok
			|| (*(BYTE *)0x00749A30 == 195)		//khang sat thuong ok
			|| (*(BYTE *)0x004C8F00 == 195)	// khang hieu ung x?u ok
			|| (*(BYTE *)0x00596500 == 195)	// Xoa hoi chieu va noi luc
			|| (*(BYTE *)0x0057D760 == 195))	//khangtele dw ok
		{
			MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 6", "[ERROR]", ERROR); // ok
			ExitProcess(0);
		}


		if ((*(BYTE *)0x006407C0 != 85)		//khang day lui ok
			|| (*(BYTE *)0x005528A0 != 85)	//khang sat thuong ok
			|| (*(BYTE *)0x00749A30 != 236)		//khang sat thuong ok
			|| (*(BYTE *)0x004C8F00 != 85)	// khang hieu ung x?u ok
			|| (*(BYTE *)0x00596500 != 85)	// Xoa hoi chieu va noi luc
			|| (*(BYTE *)0x0057D760 != 85))	//khangtele dw ok
		{
			MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 7", "[ERROR]", ERROR); // ok
			ExitProcess(0);
		}
	}

	if (*(BYTE *)0x0073A641 != 91 || *(BYTE *)0x0055D515 == 100 || *(BYTE *)0x0055D515 != 4)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 8", "[ERROR]", ERROR);	  //Evilhit ok
		ExitProcess(0);
	}

	if (*(DWORD *)0x0054539E == 1166749052 || *(DWORD *)0x00545248 == 1300967031
		|| *(BYTE *)0x0054539E == 118 || *(BYTE *)0x0054539E == 124
		|| *(BYTE *)0x00545248 == 117 || *(BYTE *)0x00545248 == 119
		|| *(BYTE *)0x00545248 == 123 || *(BYTE *)0x0054539E != 117
		|| *(BYTE *)0x00545248 != 122 || *(BYTE *)0x005B5FFA == 233)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 9", "[ERROR]", ERROR);	  //?ánh li?n skill ok
		ExitProcess(0);
	}

	if (*(BYTE *)0x00561746 == 0 || *(BYTE *)0x00561746 != 1)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 10", "[ERROR]", ERROR);	  //skill trong thanh ok
		ExitProcess(0);
	}

	if (*(BYTE *)0x0065FC76 == 235 || *(BYTE *)0x0065FC76 != 117)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 11", "[ERROR]", ERROR);	  //godmode ok
		ExitProcess(0);
	}

	if (*(BYTE *)0x005DE16C != 102)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 12", "[ERROR]", ERROR);	  //delaycuoi soi
		ExitProcess(0);
	}

	if ((*(BYTE*)*(DWORD *)0x5B1705 == 10)			//quayrong
		|| (*(BYTE*)*(DWORD *)0x5A1792 == 10)		//danh thuong Dk
		|| (*(BYTE*)*(DWORD *)0x5AD81F == 10)		//xoay kiem
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)
		//----DW
		|| (*(BYTE*)*(DWORD *)0x59CED7 == 10)		//skill don
		|| (*(BYTE*)*(DWORD *)0x5B1CC6 == 10)		//muabangtuyet
		|| (*(BYTE*)*(DWORD *)0x5B0C02 == 10)		//Lua Dia Nguc
		|| (*(BYTE*)*(DWORD *)0x59D1DD == 10)		//muasaobang
		|| (*(BYTE*)*(DWORD *)0x5B1877 == 10)		//Kame
		|| (*(BYTE*)*(DWORD *)0x5B05C6 == 10)		//Nova
		|| (*(BYTE*)*(DWORD *)0x5B071D == 10)		//Nova1
		|| (*(BYTE*)*(DWORD *)0x5B1AA4 == 10)		//Cot lua
		//-------EFL
		|| (*(BYTE*)*(DWORD *)0x5AC54F == 10)		//Ngu Tien
		|| (*(BYTE*)*(DWORD *)0x59D6A8 == 10)		//Ban bang
		|| (*(BYTE*)*(DWORD *)0x5AC227 == 10)		//Buff mau
		//--------SUM
		|| (*(BYTE*)*(DWORD *)0x534FCD == 10)		//Skill sach
		|| (*(BYTE*)*(DWORD *)0x59DED4 == 10)		//Giat Set
		|| (*(BYTE*)*(DWORD *)0x59DC82 == 10)		//Hut Mau
		|| (*(BYTE*)*(DWORD *)0x5B2C93 == 10)		//Shok Dien
		//--------RF
		|| (*(BYTE*)*(DWORD *)0x59F46C == 10)		//D?m ??t
		|| (*(BYTE*)*(DWORD *)0x59F20C == 10)		//AALH
		//--------MG
		|| (*(BYTE*)*(DWORD *)0x5ADE21 == 10)		//Cú chém
		|| (*(BYTE*)*(DWORD *)0x5ADAC7 == 10)		//Chem Lua
		|| (*(BYTE*)*(DWORD *)0x5AE84F == 10)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)		//Quat xich
		|| (*(BYTE*)*(DWORD *)0x5AF1AC == 10)		//Hoa Am
		|| (*(BYTE*)*(DWORD *)0x5AE1B0 == 10)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))				//So lan Xdame	
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 13", "[ERROR]", ERROR);	  //XSdame ok
		ExitProcess(0);
	}

	if (*(BYTE*)(*(DWORD*)(0x0400000) + 0x00927C88) != 0)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 14", "[ERROR]", ERROR);	 //hithack ok
		ExitProcess(0);
	}

	if (*(BYTE*)0x00400020 > 0)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 15", "[ERROR]", ERROR);	 //attacksped ok
		ExitProcess(0);
	}

	if (*(FLOAT*)0x00D27BFC > 60)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 16", "[ERROR]", ERROR);	 //Zoom
		ExitProcess(0);
	}

	if ((*(BYTE*)0x005B1705 != 106)			//quayrong
		|| (*(BYTE*)0x005A1792 != 106)		//danh thuong Dk
		|| (*(BYTE*)0x005AD81F != 106)		//xoay kiem
		|| (*(BYTE*)0x0059C798 != 106)
		//----DW
		|| (*(BYTE*)0x0059CED7 != 106)		//skill don
		|| (*(BYTE*)0x005B1CC6 != 106)		//muabangtuyet
		|| (*(BYTE*)0x005B0C02 != 106)		//Lua Dia Nguc
		|| (*(BYTE*)0x0059D1DD != 106)		//muasaobang
		|| (*(BYTE*)0x005B1877 != 106)		//Kame
		|| (*(BYTE*)0x005B05C6 != 106)		//Nova
		|| (*(BYTE*)0x005B071D != 106)		//Nova1
		|| (*(BYTE*)0x005B1AA4 != 106)		//Cot lua
		//-------EFL
		|| (*(BYTE*)0x005AC54F != 106)		//Ngu Tien
		|| (*(BYTE*)0x0059D6A8 != 106)		//Ban bang
		|| (*(BYTE*)0x005AC227 != 106)		//Buff mau
		//--------SUM
		|| (*(BYTE*)0x00534FCD != 106)		//Skill sach
		|| (*(BYTE*)0x0059DED4 != 106)		//Giat Set
		|| (*(BYTE*)0x0059DC82 != 106)		//Hut Mau
		|| (*(BYTE*)0x005B2C93 != 106)		//Shok Dien
		//--------RF
		|| (*(BYTE*)0x0059F46C != 106)		//D?m ??t
		|| (*(BYTE*)0x0059F20C != 106)		//AALH
		//--------MG
		|| (*(BYTE*)0x005ADE21 != 106)		//Cú chém
		|| (*(BYTE*)0x005ADAC7 != 106)		//Chem Lua
		|| (*(BYTE*)0x005AE84F != 106)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)0x0059C798 != 106)		//Quat xich
		|| (*(BYTE*)0x005AF1AC != 106)		//Hoa Am
		|| (*(BYTE*)0x005AE1B0 != 106)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))		//So lan Xdame
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 17", "[ERROR]", ERROR);	  //XSdame
		ExitProcess(0);
	}

	if (*(BYTE*)0x004DA3E4 != 139 || *(BYTE*)0x004DA3E9 != 255)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 18", "[ERROR]", ERROR);	// Speed moi
		ExitProcess(0);
	}
	if (*(BYTE*)0x00596343 == 233)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 19", "[ERROR]", ERROR);	//hack danh xa
		ExitProcess(0);
	}

	if (*(BYTE*)0x0054539E != 117 || *(BYTE*)0x004DA3E9 == 124)
	{
		MessageBoxA(NULL, "Phat Hien Ghi Van Hack Vui Long Tat Hack! 20", "[ERROR]", ERROR);	// loai bo hanh dong
		ExitProcess(0);
	}
#endif

	gInterface.RightMiniInfoY = 130;

#if(DEV_DAMAGE_TABLE)
	if (gProtect.m_MainInfo.DamageTable == 1)
	{
		gInterface.DrawDamageTable();
	}
#endif

	//---------------------------------------------------------
	//-- Advance Status Custom Low Interfaces
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (gProtect.m_MainInfo.DisableAdvance == 0)
		{
			g_StatsAdvance.DrawInfo();
		}
	}
	//--

	//--Bar MiniMap
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
		{
			gInterface.MiniMapMini();
		}
	}
	//--
	//--Bar Pet
	//2-04-2022
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (*(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535)
		{
			gCRenderEx700.BarPetMuun();
		}
	}

	//gInterface.BarPartyNew();

	//--
	gObjUser.Refresh();

	jCRenderRuud.CheckOpen();

	/*if (gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4, 0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4, 255)
		|| gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4, 0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4, 255))
	{
		gInterface.PetY = 38.0f;

	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if (gObjUser.lpViewPlayer->PetSlot != -1)
	{
		gInterface.PetX = 61.0f;
	}
	else
	{
		gInterface.PetX = 0;
	}*/

	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	gInterface.DrawMiniMap();

#if(RANKINGGOC == 1)
	gCustomRanking.DrawRankPanelWindow();
#endif

#if(DANH_HIEU_NEW == 1)
	G_BEXO_DANH_HIEU.DRAW_DANH_HIEU();
#endif

#if(TU_LUYEN_NEW == 1)
	G_BEXO_TU_LUYEN.DRAW_TU_LUYEN();
#endif

#if(THUE_VIP_NEW == 1)
	G_BEXO_VIPNHANVAT.DRAW_VIPNHANVAT();
#endif

#if(VIP_TAI_KHOAN_NEW == 1)
	G_BEXO_VIPTAIKHOAN.DRAW_VIPTAIKHOAN();
#endif

#if(NGU_HANH_NEW == 1)
	G_BEXO_NGUHANH.DRAW_NGUHANH();
#endif

#if(KINH_MACH_NEW == 1)
	G_BEXO_KINHMACH.DRAW_KINHMACH();
#endif

	gCustomEventTime.DrawEventTimePanelWindow();

#if(SHOWTIMEEVENT == 1)
	gCustomEventTime.Notice();
#endif

#if(LEOTHAP == 1)
	gInterface.DrawLeoThap();
	gLeoThap.LeoThapCountdown();
	gLeoThap.LeoThapDelayTime();
#endif

	gInterface.TvTEvent();

#if(MENU_NEW == 1)
	G_BEXO_MENU.DRAW_MENU();
#endif

#if(VONGQUAY_NEW)
	gLuckySpin.Draw();
#endif

#if(NGANHANGNGOC_NEW)
	gJewelBank.DrawJewelBank();
#endif

	gInterface.DrawTextRun();

	//	G_BEXO_THUONG_GIA.DRAW_THUONG_GIA();
	//  G_SOLAR_BUTTON_HUONGDAN.DRAW_BUTTON();

	gInterface.DrawMenu();

	gInterface.DrawAutoReset();

	gInterface.DrawAttack();

	if (gInterface.m_AttackCustom == 1)
	{
		gInterface.DrawOffAttack();
	}

	gInterface.DrawConfirmOpen();

#if(NHIEMVU_NEW == 1)
	if (gObjUser.NhiemVu == 1)
	{
		g_ExWinQuestSystem.DrawMiniInfo();
		g_ExWinQuestSystem.Draw();
		g_ExWinQuestSystem.DrawOpenWQ();
	}
#endif

#if (ARCHIVEMENT == 1)
	if (gObjUser.ThanhTuu == 1)
	{
		gAchievements.Draw();
	}
#endif

#if(RANKING_NEW == 1)
	gRanking.Draw();
#endif

#if(MOCNAP == 1)
	if (gObjUser.MocNap == 1)
	{
		G_BEXO_MOCNAP.DRAW_MOCNAP();
	}
#endif

#if(TAISINH == 1)
	if (gObjUser.TaiSinhTrungSinh == 1)
	{
		G_BEXO_TAISINH.DRAW_TAISINH();
	}
#endif

	gNewInterface.Work();

#if(OANTUTY)
	gInterface.DrawRPS();
#endif

	if (gObjUser.DoiClass == 1)
	{
		gInterface.DrawChangingClassWindow();
	}

	gInterface.DrawWarehouseWindow();

	if (gObjUser.TaoNhom == 1)
	{
		gPartySearchSettings.draw_party_settings_window();
	}

	if (gObjUser.TimNhom == 1)
	{
		gPartySearch.draw_party_search();
		gPartySearch.draw_party_password();
	}

	gInterface.DrawCTCMiNiMap(); //LOad de draw
	gInterface.DrawCTCMiniWindow();//LOad de draw

#if(BOSS_GUILD == 1)
	gInterface.DrawBossGuildWindow();
	gInterface.DrawBossGuildMap(); // Time
#endif
	
#if(CHIENTRUONGCO == 1)
	gInterface.DrawChienTruongCo();
	gInterface.DrawTimeCTC();
#endif

	gInterface.WindowsKG();

//#if(SHOPSEARCH==TRUE)
//	g_PersonalShopEx.Draw();
//#endif

	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}


	pDrawInterface();


	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}


	
	if (GetForegroundWindow() == pGameWindow)
	{
		if (GetKeyState(VK_SNAPSHOT) < 0)
		{
			gInterface.DrawLogo(1);
		}

#if(NGANHANGNGOC_NEW)
		if (GetKeyState('H') & 0x4000)
		{
			gInterface.SwitchNganHangNgoc();
		}
#endif

		if (GetKeyState('J') & 0x4000)
		{
			gCustomEventTime.OpenWindow();
		}

		if (gProtect.m_MainInfo.FenrirCuoiTrongThanh == 1)
		{
			if (GetKeyState('S') & 0x4000)
			{
				gInterface.SwitchFenrir();
			}
		}

		if (GetKeyState(VK_F5) & 0x4000)
		{
			gInterface.SwitchHideDanhHieu();
		}
		if (GetKeyState(VK_F4) & 0x4000)
		{
			gInterface.SwitchChatExpand();
		}
		if (GetKeyState(VK_F6) & 0x4000)
		{
			gInterface.SwitchAntiLag1();
		}
		if (GetKeyState(VK_F7) & 0x4000)
		{
			gInterface.SwitchAntiLag2();
		}

		if (GetKeyState('K') & 0x4000)
		{
			gInterface.SwitchHidePlayer();
		}

		if (GetKeyState(VK_F10) & 0x4000)
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000)
		{
			gInterface.CameraInit();
		}
		if (GetKeyState(VK_F12) & 0x4000)
		{
			if (gTrayMode.TempWindowProc == NULL)
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}

		if (GetKeyState(VK_ESCAPE) < 0)
		{

			if (g_MuunSystem.InventoryCTRLStatus == 1)
			{
				g_MuunSystem.InventoryCTRLStatus = 0;
			}

#if(RANKING_NEW == 1)
			if (gRanking.Show == true)
			{
				gRanking.Show = false;
				pSetCursorFocus = false;
			}
#endif

			if (gInterface.CheckSachThuocTinhWindow())
			{
				gInterface.CloseSachThuocTinhWindow();
			}

			if (gInterface.CheckTinhNangWindow())
			{
				gInterface.CloseTinhNangWindow();
			}

#if(NGANHANGNGOC_NEW == 1)
			if (gJewelBank.Check_Window_JewelBank())
			{
				gJewelBank.Close_Window_JewelBank();
			}
#endif

#if(RANKINGGOC == 1)
			if (gCustomRanking.CHECK_WINDOW_RANKING())
			{
				gCustomRanking.CLOSE_WINDOW_RANKING();
			}
#endif

#if(DEV_PLAYERSHOP == 1)
			if (gInterface.CheckWindowEx(ObjWindowsEx::exWinItemMarket))
			{
				gInterface.CloseWindowEx(ObjWindowsEx::exWinItemMarket);
			}
#endif

#if (ARCHIVEMENT == 1)
			if (gProtect.m_MainInfo.ThanhTuu == 1)
			{
				if (gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow == true)
				{
					gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].Close();
				}
			}
#endif

		}
	}

//	gCRuudShop.RuudShop();

//	gInterface.DrawLogo(0);

}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
}

#if(NGANHANGNGOC_NEW)
void Interface::SwitchNganHangNgoc()
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


	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow) || this->CheckWindow(CreateGuild))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();


	if (gObjUser.NganHangNgoc == 1)
	{
		if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
		{

			if (!gJewelBank.Check_Window_JewelBank())
			{
				gJewelBank.Open_Window_JewelBank();
			}
			else
				gJewelBank.Close_Window_JewelBank();
		}
	}

	if (gObjUser.NganHangNgoc == 0)
	{
		gInterface.DrawMessage(1, "Chức năng [Ngân Hàng Ngọc] đang bảo trì !");
	}

}
#endif

void Interface::SwitchFenrir()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (gProtect.m_MainInfo.FenrirCuoiTrongThanh == 1)
	{
		if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow) && !gInterface.CheckWindow(ObjWindow::Inventory))
		{

			if (MinimizarFenrir != 0)
			{
				MinimizarFenrir = 0;
			}
			else
			{
				MinimizarFenrir = 1;
			}
		}
	}
}

//void Interface::DrawTimeUI()
//{
//	//-- Time Bar Custom
//	if(TimerBar == 0
//		|| (this->CheckWindow(ObjWindow::CashShop) 
//		|| this->CheckWindow(ObjWindow::MoveList)
//		|| this->CheckWindow(ObjWindow::Shop)
//		|| this->CheckWindow(ObjWindow::Character)
//		|| this->CheckWindow(ObjWindow::Help)
//		//|| this->CheckWindow(ObjWindow::FastDial)
//		|| this->CheckWindow(ObjWindow::SkillTree)
//		//|| this->CheckWindow(ObjWindow::GoldenArcher1)
//		//|| this->CheckWindow(ObjWindow::GoldenArcher2)
//		//|| this->CheckWindow(ObjWindow::LuckyCoin1)
//		//|| this->CheckWindow(ObjWindow::LuckyCoin2)
//		//|| this->CheckWindow(ObjWindow::NPC_Duel)
//		//|| this->CheckWindow(ObjWindow::NPC_Titus)
//		|| this->CheckWindow(ObjWindow::CashShop)
//		|| this->CheckWindow(ObjWindow::Lugard)
//		//|| this->CheckWindow(ObjWindow::QuestList1)
//		//|| this->CheckWindow(ObjWindow::QuestList2)
//		|| this->CheckWindow(ObjWindow::Jerint)
//		|| this->CheckWindow(ObjWindow::FullMap)
//		|| this->CheckWindow(ObjWindow::NPC_Dialog)
//		//|| this->CheckWindow(ObjWindow::GensInfo)
//		|| this->CheckWindow(ObjWindow::NPC_Julia)
//		|| this->CheckWindow(ObjWindow::NPC_ChaosMix)
//		//|| this->CheckWindow(ObjWindow::ExpandInventory)
//		//|| this->CheckWindow(ObjWindow::ExpandWarehouse)
//		//|| this->CheckWindow(ObjWindow::MuHelper)
//		|| pMapNumber == 34 
//		|| pMapNumber == 30 ))
//	{
//		return;
//	}
//	if (jCRenderRuud.OpeningRuud)
//	{
//		return;
//	}
//	//--
//	time_t TimeServer;
//	struct tm * ServerT;
//	time(&TimeServer);
//	// ----
//	ServerT = gmtime(&TimeServer);
//	// ----
//	char ServerTime[30];
//
//	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT)%24, ServerT->tm_min, ServerT->tm_sec);
//	// -----
//	pSetBlend(true);
//	glColor4f(1.0, 1.0, 1.0, 1.0);
//	if(gProtect.m_MainInfo.MuHelperType == 0)
//	{
//		if(gProtect.m_MainInfo.DisableHelper == 0)
//		{
//		RenderBitmap(0x7879, ReturnX(TransForX(42)), ReturnY(TransForY(16)), ReturnX(TransForX(80)), ReturnY(TransForY(20)), 0, 0, 0.821, 0.751, 0.8, 1, 0); //TimeBar
//		this->DrawFormat(eWhite, ReturnX(TransForX(63)), ReturnY(TransForY(19)), ReturnX(TransForX(100)), ReturnY(TransForY(1)), ServerTime);
//		}
//	}
//	else if(gProtect.m_MainInfo.MuHelperType == 1)
//	{
//		if(gProtect.m_MainInfo.DisableHelper == 0)
//		{
//		RenderBitmap(0x7878, ReturnX(TransForX(24)), ReturnY(TransForY(18)), ReturnX(TransForX(80)), ReturnY(TransForY(20)), 0, 0, 0.821, 0.751, 0.8, 1, 0); //TimeBar ex700
//		this->DrawFormat(eWhite, ReturnX(TransForX(40)), ReturnY(TransForY(20)), ReturnX(TransForX(100)), ReturnY(TransForY(1)), ServerTime);
//		}
//	}
//	// ----
//	pGLSwitchBlend();
//	pGLSwitch();
//	pSetBlend(false);
//}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;

}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

#if(OFFLINE_MODE_NEW)
//void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
//{
//	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
//	{
//		this->Data[ObjectID].X = PosX;
//		this->Data[ObjectID].Y = PosY;
//		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
//		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
//	}
//	// ----
//	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
//		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
//}
//
//int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
//{
//	char Buff[2048];
//	char Buff2[2048];
//	int BuffLen = sizeof(Buff);
//	ZeroMemory(Buff, BuffLen);
//	// ----
//	va_list args;
//	va_start(args, Text);
//	int Len = vsprintf_s(Buff, BuffLen, Text, args);
//	va_end(args);
//	// ----
//
//	int LineCount = 0;
//
//	strcpy(Buff2, Buff);
//
//	char * Line = strtok(Buff2, "\n");
//	// ----
//	while (Line != NULL)
//	{
//		LineCount++;
//		Line = strtok(NULL, "\n");
//	}
//
//	pSetBlend(1);
//	glColor4f(0.0, 0.0, 0.0, 0.8);
//	pDrawBarForm(PosX - 10, PosY, Width, LineCount * 10, 0.0f, 0);
//	pGLSwitchBlend();
//	pGLSwitch();
//
//	glColor3f(1.0, 1.0, 1.0);
//
//	this->DrawFormat(eYellow170, PosX, PosY, Width, Align, Buff);
//	return 0;
//}

////bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY)
////{
////	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
////		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
////	{
////		return false;
////	}
////	// ----
////	return true;
////}

#endif
bool Interface::IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
		return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	return false;
	return true;
}
bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY,ScaleX,ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

//=========================================================================================================================================
//=========================================================================================================================================
void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Character))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		if (G_BEXO_MENU.CHECK_WINDOW_MENU() || gInterface.CheckWindow(ChaosBox)// máy chaos

			|| gInterface.CheckWindow(ChaosBox)// máy chaos
			|| gInterface.CheckWindow(CashShop) //shop X
			|| gInterface.CheckWindow(FullMap) //Map
			|| gInterface.CheckWindow(ChatWindow)  //cửa sổ chat
			|| gInterface.CheckWindow(Inventory) //cửa sổ C
			|| gInterface.CheckWindow(SkillTree)  //Bảng master
			|| gInterface.CheckWindow(Store)  //shop
			|| gInterface.CheckWindow(ExpandWarehouse) //?? 
			|| gInterface.CheckWindow(Character)  //bảng C
			|| gInterface.CheckWindow(Warehouse) //Kho
			|| gInterface.CheckWindow(OtherStore) //Cửa hàng kh
			|| gInterface.CheckWindow(Trade)  //Trade
			|| gInterface.CheckWindow(Shop)   //Shop
			|| gInterface.CheckWindow(MoveList) //M
			|| gInterface.CheckWindow(CommandWindow)  //Cửa sổ lệnh
			|| gInterface.CheckWindow(GensInfo)
			|| gInterface.CheckWindow(Guild)
			|| gInterface.CheckWindow(NPC_Dialog)
			|| gInterface.CheckWindow(NPC_Julia)
			|| gInterface.CheckWindow(FriendList)
			|| gInterface.CheckWindow(FastDial)
			|| gInterface.CheckWindow(Help)
			|| gInterface.CheckWindow(Options)
			|| gInterface.CheckWindow(FastMenu)
			|| gInterface.CheckWindow(Party)
			|| gInterface.CheckWindow(PetInfo)
			|| gInterface.CheckWindow(MuHelper)
			|| gInterface.CheckWindow(Quest))
		{
			G_BEXO_MENU.CLOSE_WINDOW_MENU();
		}
		else
		{
			G_BEXO_MENU.OPEN_WINDOW_MENU();
#if(TAISINH == 1)
			G_BEXO_TAISINH.TAISINH_ATIVE(100);
#endif
		}
	}

	return false;
}

void Interface::DrawAutoReset()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eAUTORESET].OnShow)
	{
		this->Data[eAUTORESET].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList)
		|| this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Character))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	this->Data[eAUTORESET].OnShow = true;

	gRenderMap.AutoSendMove();
}

void Interface::DrawAttack()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eATTACK].OnShow)
	{
		this->Data[eATTACK].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Character))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	this->Data[eATTACK].OnShow = true;
}

void Interface::DrawOffAttack()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eOFFATTACK].OnShow)
	{
		this->Data[eOFFATTACK].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Character))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	this->Data[eOFFATTACK].OnShow = true;
}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

/*bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Stadium:
			return false;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}*/

void Interface::CloseCustomWindow()
{
	//this->Data[eEventTimePANEL_MAIN].OnShow = false;
	//this->Data[eCommand_MAIN].OnShow		= false;
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

#if(VONGQUAY_NEW)

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	//float X = ull_to_float2(*(QWORD*)0xE61E58);
	//float Y = ull_to_float2(*(QWORD*)0xE61E58+1);

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	//float v2 = (X / (Y / 100.0f)) / 100.0f;//(*(float*)MAIN_RESOLUTION_X / (*(float*)MAIN_RESOLUTION_Y / 100.0f)) / 100.0f;
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();


	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	//sub_637770_Addr();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}
#endif

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Xác nhận");

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, "Bạn có muốn mua vật phẩm này không!");

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

//---- cosas peladas

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(MoveList) || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}

	this->DrawFormat(eYellow, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(MoveList) || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0x89, sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0x89, sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(MoveList) || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing/2));
	// ----
	gInterface.validar=0;

	if(gInterface.msPing > 0){
		//----
		this->DrawFormat(eExcellent, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eExcellent, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar=1;
	}

	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eExcellent, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eExcellent, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eExcellent, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eExcellent, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::SwitchHideDanhHieu()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (MinimizarOfRank == 0)
	{
		MinimizarOfRank = 1;
		pDrawMessage("Ẩn danh hiệu: [Tắt]", 1);
	}
	else
	{
		MinimizarOfRank = 0;
		pDrawMessage("Ẩn danh hiệu: [Bật]", 1);
	}
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type = 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{
	if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
	{
		return;
	}

	if( pMapNumber == 62 )
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Restore();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Toggle();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	/*if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		|| this->Data[eTIME].OnShow
		)
	{
		return;
	}*/
	//-> Disable Move List
	if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap) 
		//|| this->CheckWindow(ObjWindow::ChatWindow) 
		|| this->CheckWindow(ObjWindow::SkillTree)
		//|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->CheckWindow(ObjWindow::FriendList) || this->CheckWindow(ObjWindow::Party) || this->CheckWindow(ObjWindow::Quest) || this->CheckWindow(ObjWindow::Guild)
	||  (this->CheckWindow(CommandWindow) || this->CheckWindow(Inventory) || this->CheckWindow(Character) || this->CheckWindow(FastMenu) || this->CheckWindow(SkillTree)
	|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap) || this->CheckWindow(MuHelper)) || pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
		this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

void Interface::DrawWarehouseUI()
{
	float PosX = this->GetResizeX(eWAREHOUSE);
	// ----
	if (!this->CheckWindow(Warehouse))
	{
		return;
	}
	// ----
	this->DrawGUI(eWAREHOUSE, PosX, 348);
	this->DrawGUI(eWAREHOUSE1, PosX + 45, 348);
	this->DrawFormat(eWhite, PosX + 33, 350, 10, 1, "%d/5", gObjUser.m_WarehouseNumber + 1);
	// ----
	if (IsWorkZone(eWAREHOUSE))
	{
		if (this->Data[eWAREHOUSE].OnClick)
		{
			this->DrawColoredGUI(eWAREHOUSE, PosX, 348, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE, PosX, 348, pMakeColor(255, 204, 20, 200));
	}
	else if (IsWorkZone(eWAREHOUSE1))
	{
		if (this->Data[eWAREHOUSE1].OnClick)
		{
			this->DrawColoredGUI(eWAREHOUSE1, PosX + 45, 348, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE1, PosX + 45, 348, pMakeColor(255, 204, 20, 200));
	}
}

// ----------------------------------------------------------------------------------------------

void Interface::EventWarehouseUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	// ----
	if (!this->CheckWindow(Warehouse))
	{
		return;
	}
	// ----
	if (IsWorkZone(eWAREHOUSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eWAREHOUSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eWAREHOUSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eWAREHOUSE].EventTick = GetTickCount();
		// ----
		if (gObjUser.m_WarehouseNumber > 0)
		{
			gObjUser.m_WarehouseNumber--;
		}
		PMSG_CHANGEWAREHOUSE_RECV pRequest;
		pRequest.Number = gObjUser.m_WarehouseNumber;
		pRequest.header.set(0xF3, 0xE5, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.header.size);
	}
	else if (IsWorkZone(eWAREHOUSE1))
	{
		DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eWAREHOUSE1].OnClick = true;
			return;
		}
		// ----
		this->Data[eWAREHOUSE1].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eWAREHOUSE1].EventTick = GetTickCount();
		// ----
		if (gObjUser.m_WarehouseNumber < 4)
		{
			gObjUser.m_WarehouseNumber++;
		}
		PMSG_CHANGEWAREHOUSE_RECV pRequest;
		pRequest.Number = gObjUser.m_WarehouseNumber;
		pRequest.header.set(0xF3, 0xE5, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.header.size);
	}
}

void Interface::DrawWarehouseWindow()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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

	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	if (gServerInfo.AnimatedWarehouse == 1)
	{
		if (this->Data[eWAREHOUSE_MAIN].OpenedValue > 100)
		{
			this->Data[eWAREHOUSE_MAIN].OpenedValue -= this->Data[eWAREHOUSE_MAIN].Speed;

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue <= 250)
			{
				this->Data[eWAREHOUSE_MAIN].Speed = 15;
			}

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue < 100)
			{
				this->Data[eWAREHOUSE_MAIN].OpenedValue = 100;
			}
		}
	}

	// ----
	float MainWidth = 230.0;

	float StartY = 100;

	if (gServerInfo.AnimatedWarehouse == 1)
	{
		StartY = this->Data[eWAREHOUSE_MAIN].OpenedValue;//100.0;
	}

	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawAnimatedGUI(eWAREHOUSE_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eWAREHOUSE_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eWAREHOUSE_FRAME, StartX, StartY + 67.0, 7);
	this->DrawAnimatedGUI(eWAREHOUSE_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eWAREHOUSE_CLOSE, StartX + MainWidth - this->Data[eWAREHOUSE_CLOSE].Width, this->Data[eWAREHOUSE_MAIN].Y - 2/* + this->Data[eWAREHOUSE_CLOSE].Height + 2*/);
	// ----
	if (this->IsWorkZone(eWAREHOUSE_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWAREHOUSE_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_CLOSE, this->Data[eWAREHOUSE_CLOSE].X, this->Data[eWAREHOUSE_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eWAREHOUSE_CLOSE].X + 5, this->Data[eWAREHOUSE_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 8, 210, 3, "Kho đồ");

	this->DrawFormat(eBlue, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 30, 210, 3, "Chào %s, vui lòng lựa chọn kho đồ...", gObjUser.lpPlayer->Name);
	this->DrawAnimatedGUI(eWAREHOUSE_DIV, StartX, this->Data[eWAREHOUSE_MAIN].Y + 33);
	// ----
	this->DrawAnimatedGUI(eWAREHOUSE_NUM1, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 70, 210, 3, "Kho đồ 1");
	// ----
	if (gObjUser.m_MaxWarehouse >= 2)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM2, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 100, 210, 3, "Kho đồ 2");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 3)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM3, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 130, 210, 3, "Kho đồ 3");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 4)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM4, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 160, 210, 3, "Kho đồ 4");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 5)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM5, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 60);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 70, 210, 3, "Kho đồ 5");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 6)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM6, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 100, 210, 3, "Kho đồ 6");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 7)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM7, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 130, 210, 3, "Kho đồ 7");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 8)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM8, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 160, 210, 3, "Kho đồ 8");
	}
	// ----
	if (IsWorkZone(eWAREHOUSE_NUM1))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWAREHOUSE_NUM1].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_NUM1, this->Data[eWAREHOUSE_NUM1].X, this->Data[eWAREHOUSE_NUM1].Y, Color);
	}
	if (gObjUser.m_MaxWarehouse >= 2)
	{
		if (IsWorkZone(eWAREHOUSE_NUM2))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM2].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM2, this->Data[eWAREHOUSE_NUM2].X, this->Data[eWAREHOUSE_NUM2].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 3)
	{
		if (IsWorkZone(eWAREHOUSE_NUM3))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM3].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM3, this->Data[eWAREHOUSE_NUM3].X, this->Data[eWAREHOUSE_NUM3].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 4)
	{
		if (IsWorkZone(eWAREHOUSE_NUM4))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM4].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM4, this->Data[eWAREHOUSE_NUM4].X, this->Data[eWAREHOUSE_NUM4].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 5)
	{
		if (IsWorkZone(eWAREHOUSE_NUM5))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM5].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM5, this->Data[eWAREHOUSE_NUM5].X, this->Data[eWAREHOUSE_NUM5].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 6)
	{
		if (IsWorkZone(eWAREHOUSE_NUM6))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM6].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM6, this->Data[eWAREHOUSE_NUM6].X, this->Data[eWAREHOUSE_NUM6].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 7)
	{
		if (IsWorkZone(eWAREHOUSE_NUM7))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM7].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM7, this->Data[eWAREHOUSE_NUM7].X, this->Data[eWAREHOUSE_NUM7].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 8)
	{
		if (IsWorkZone(eWAREHOUSE_NUM8))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM8].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM8, this->Data[eWAREHOUSE_NUM8].X, this->Data[eWAREHOUSE_NUM8].Y, Color);
		}
	}
}

void Interface::EventWarehouseWindow_Main(DWORD Event)
{
	this->EventWarehouseWindow_Close(Event);
	// 4136

	DWORD CurrentTick = GetTickCount();

	if ((CurrentTick - this->Data[eWAREHOUSE_MAIN].EventTick) < 500)
	{
		return;
	}

	//DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	// || !IsWorkZone(eCHANGINGCLASS_MG) || !this->Data[eCHANGINGCLASS_MG].Attribute )

	int ObjectIDs[8] =
	{
		eWAREHOUSE_NUM1,
		eWAREHOUSE_NUM2,
		eWAREHOUSE_NUM3,
		eWAREHOUSE_NUM4,
		eWAREHOUSE_NUM5,
		eWAREHOUSE_NUM6,
		eWAREHOUSE_NUM7,
		eWAREHOUSE_NUM8
	};

	for (int i = 0; i < 8; i++)
	{
		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			CGSendWarehouseOpen(i);
			// ----
			SEND_GS_REQ pRequest;
			pRequest.h.set(0xFB, 0x81, sizeof(pRequest));
			DataSend((BYTE*)&pRequest, pRequest.h.size);
			// ----
			this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
		}
	}
}

void Interface::EventWarehouseWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE_CLOSE].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow || !IsWorkZone(eWAREHOUSE_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWAREHOUSE_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].EventTick = GetTickCount();
	this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
	// ----
	return;
}
#if(OANTUTY)
void Interface::DrawRPS()
{
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (this->CheckWindow(ObjWindow::Trade))
	{
		this->DrawGUI(eRock, StartX + 80, StartY + 85);
		this->DrawGUI(ePaper, StartX + 120, StartY + 85);
		this->DrawGUI(eScissors, StartX + 160, StartY + 85);

		if (this->IsWorkZone(eRock))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eRock].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eRock, this->Data[eRock].X, this->Data[eRock].Y, Color);
		}
		if (this->IsWorkZone(ePaper))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[ePaper].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(ePaper, this->Data[ePaper].X, this->Data[ePaper].Y, Color);
		}
		if (this->IsWorkZone(eScissors))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eScissors].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eScissors, this->Data[eScissors].X, this->Data[eScissors].Y, Color);
		}
		if (this->Data[eRock].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(eRock, gInterface.Data[eRock].X, gInterface.Data[eRock].Y, Color);
		}
		if (this->Data[ePaper].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(ePaper, gInterface.Data[ePaper].X, gInterface.Data[ePaper].Y, Color);
		}
		if (this->Data[eScissors].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(eScissors, gInterface.Data[eScissors].X, gInterface.Data[eScissors].Y, Color);
		}
	}
}

void Interface::EventRPS_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->CheckWindow(ObjWindow::Trade))
	{
		return;
	}

	if (this->IsWorkZone(eRock))
	{
		DWORD Delay = (CurrentTick - this->Data[eRock].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eRock].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eRock].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eRock].EventTick = GetTickCount();
		//Func
		RPSMode(1);
		//pDrawMessage("Ban chon bua",1);
		this->Data[eRock].Attribute = 1;
		this->Data[ePaper].Attribute = 0;
		this->Data[eScissors].Attribute = 0;
	}
	//
	else if (this->IsWorkZone(ePaper))
	{
		DWORD Delay = (CurrentTick - this->Data[ePaper].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePaper].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[ePaper].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[ePaper].EventTick = GetTickCount();
		//Func
		RPSMode(2);
		//pDrawMessage("Ban chon bao",1);
		this->Data[eRock].Attribute = 0;
		this->Data[ePaper].Attribute = 1;
		this->Data[eScissors].Attribute = 0;
	}
	//
	else if (this->IsWorkZone(eScissors))
	{
		DWORD Delay = (CurrentTick - this->Data[eScissors].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eScissors].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eScissors].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eScissors].EventTick = GetTickCount();
		//Func
		this->Data[eRock].Attribute = 0;
		this->Data[ePaper].Attribute = 0;
		this->Data[eScissors].Attribute = 1;
		RPSMode(3);
		//pDrawMessage("Ban chon keo",1);
	}
}
#endif

void Interface::DrawChangingClassWindow()
{
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eCHANGINGCLASS_MAIN, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 100);

	gCentral.PrintDropBox(StartX + 0, gInterface.Data[eCHANGINGCLASS_MAIN].Y + 1, 225, 260, 0, 0);

	this->DrawGUI(eCHANGINGCLASS_CLOSE, StartX + 195, this->Data[eCHANGINGCLASS_MAIN].Y + 0);
	// ----
	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eCHANGINGCLASS_CLOSE, this->Data[eCHANGINGCLASS_CLOSE].X, this->Data[eCHANGINGCLASS_CLOSE].Y, Color);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, gOther.TextVN[22]);
	// ----

	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, this->Data[eCHANGINGCLASS_MAIN].Y + 190);
	this->DrawFormat(eYellow, StartX + 10, this->Data[eCHANGINGCLASS_MAIN].Y + 196, 210, 3, "WCoinC = %d",gChangeClass.m_WCoinC);
	// ----

	// ----
	this->DrawGUI(eCHANGINGCLASS_DW, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 30);

	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s", pGetTextLine(pTextLineThis, 20));
	//pGetTextLine
	// ----
	this->DrawGUI(eCHANGINGCLASS_DK, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s", pGetTextLine(pTextLineThis, 21));
	// ----
	this->DrawGUI(eCHANGINGCLASS_ELF, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s", pGetTextLine(pTextLineThis, 22));
	// ----
	this->DrawGUI(eCHANGINGCLASS_MG, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s", pGetTextLine(pTextLineThis, 23));
	// ----
	this->DrawGUI(eCHANGINGCLASS_DL, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s", pGetTextLine(pTextLineThis, 24));
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 6)
	{
		this->DrawGUI(eCHANGINGCLASS_SUM, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s", pGetTextLine(pTextLineThis, 1687));
	}
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 7)
	{
		this->DrawGUI(eCHANGINGCLASS_RF, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 8, this->Data[eCHANGINGCLASS_MAIN].Y + 130, 210, 3, "%s", pGetTextLine(pTextLineThis, 3150));
	}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 150);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	// ----
	if (IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DW].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_ELF].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_MG].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DL].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.CharsCount >= 6)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_SUM].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if (IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.CharsCount >= 7)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_RF].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Main(DWORD Event)
{
	this->EventChangingClassWindow_Close(Event);
	this->EventChangingClassWindow_DW(Event);
	this->EventChangingClassWindow_DK(Event);
	this->EventChangingClassWindow_ELF(Event);
	this->EventChangingClassWindow_MG(Event);
	this->EventChangingClassWindow_DL(Event);
	this->EventChangingClassWindow_SUM(Event);
	this->EventChangingClassWindow_RF(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
	this->Data[eCHANGINGCLASS_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_DW(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DW)
		|| !this->Data[eCHANGINGCLASS_DW].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DW].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(0);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DK)
		|| !this->Data[eCHANGINGCLASS_DK].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(16);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_ELF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);

	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_ELF)
		|| !this->Data[eCHANGINGCLASS_ELF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_ELF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(32);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_MG(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_MG)
		|| !this->Data[eCHANGINGCLASS_MG].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_MG].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(48);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DL)
		|| !this->Data[eCHANGINGCLASS_DL].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(64);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_SUM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<6)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_SUM)
		|| !this->Data[eCHANGINGCLASS_SUM].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_SUM].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(80);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_RF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<7)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_RF)
		|| !this->Data[eCHANGINGCLASS_RF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_RF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(96);
	// ----
	return false;
}

void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	//if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	//{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color)
{
	this->Data[ObjectID].X = X;
	this->Data[ObjectID].Y = Y;
	this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(true);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}

void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char * Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawMessageBox(LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	CharTest v15;

	LPCSTR pText = Buff;
	sub_409A50_addr(&v15, (int)pText);
	pOpenInfoBox1(&v15, -1);
	sub_409AD0_Addr((LPVOID)&v15);
}

bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
		return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	return false;
	return true;
}

signed int __cdecl ColorMoneyRuud(unsigned int a1)
{
	signed int color1 = eWhite; // eax@2

	if(a1 >= 1000 && a1 < 1000000)
	{
		color1 = eShinyGreen;
	}
	else if(a1 >= 1000000 && a1 < 10000000)
	{
		color1 = eGold;
	}
	else if(a1 >= 1000000 && a1 < 100000000)
	{
		color1 = eOrange;
	}
	else if(a1 >= 100000000)
	{
		color1 = eRed;
	}
	return color1;
}

//-- Shop Ruud
void InventoryWindows(DWORD id, float x, float y, float w, float h)
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	//-- NPC RUUD
	//=============================
	jCRenderRuud.OpenRuud();
	//=============================
	pDrawGUI(id, x, y, w, h);
	
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
		{
			return;
		}
		//-- Ruud Coin Interface 97/99/S2/S6/Legends
		int x, y;
		char v10[255]; // ST24_4@1
		unsigned int v23; // [sp+128h] [bp-4h]@1
		char v22[260]; // [sp+24h] [bp-108h]@1
		int v15; // ST18_4@1
		int v639; // ST18_4@1

		x = 400;
		y = 400;
		
		ZeroMemory(v22, sizeof(v22));
		pGetMoneyFormat(Ruud, v22, 0);
		v15 = ColorMoneyRuud(Ruud);
		SetTextColorByHDC(pTextThis(), v15);

		if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			RenderBitmap(0x7877, x - 52, y + 10, 120, 20, 0, 0, 0.5, 0.5, 0.5, 1, 0);
			gInterface.DrawFormat(eBlack, x - 33, y + 16, 20, 1, "Ruud");
			gInterface.DrawFormat(eOrange, x - 19, y + 16, 50, 4, "%s", v22);
		}
		/*else if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			RenderBitmap(0x7877, x + 93, y + 28, 120, 20, 0, 0, 0.5, 0.5, 0.5, 1, 0);
			gInterface.DrawFormat(eBlack, x + 112, y + 35, 20, 1, "Ruud");
			gInterface.DrawFormat(eOrange, x + 126, y + 35, 50, 4, "%s", v22);
			}*/
		}
	}
}
//-- EXP Bar
int sub_895600(float x, float y, int number)
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	int result; // eax@1

	pSetBlend( 1 );

	result = CRenderNumberEx(x, y, number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);

	return result;
	}
}
//--
//--Pet HPBar Activado
DWORD VKBUTTON_DELAY;
void CEx700::BarPetMuun()
{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		//|| gInterface.CheckWindow(ObjWindow::Store)
		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	int y = 31;
	int x = 20;

	RenderBitmap(61545, 2, y + 6, Return2X(TransForX(59)), ReturnY(TransForY(16)), 0.0, 0.0, 0.75,0.1678999364, 1, 1, 0); //-- Barra
	//-- TitleName
	pSetFont(pTextThis(), (int) pFontBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), x + 4, y + 9, "Pet", 148.0, 0, (LPINT)1, 0);

	if(pCheckMouseOver( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
	{
		if(pCursorX >= Return2X(TransForX(61)))
		{
		pSetCursorFocus = true;
		}
	}

	if(MinimizarPet == 0)
	{
		if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.6000000238, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY + 200 )
			{
				MinimizarPet = 1;
				VKBUTTON_DELAY = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
		}
	}
	else
	{
		if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.1289999783, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY + 200 )
			{
				MinimizarPet = 0;
				VKBUTTON_DELAY = GetTickCount();
			}
		}
		else
			{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			}
		}
	}
}

//--
//--Spirit BarHP Activado
//void PetSpiritHP(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
//{
//		if(gInterface.CheckWindow(ObjWindow::CashShop) 
//		//||gInterface.CheckWindow(ObjWindow::FriendList)
//		||gInterface.CheckWindow(ObjWindow::MoveList)
//		//|| gInterface.CheckWindow(ObjWindow::Party)
//		//|| gInterface.CheckWindow(ObjWindow::Quest)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
//		//|| gInterface.CheckWindow(ObjWindow::Guild)	
//		//|| gInterface.CheckWindow(ObjWindow::Trade)
//		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
//		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
//		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
//		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
//		|| gInterface.CheckWindow(ObjWindow::Shop)
//		//|| gInterface.CheckWindow(ObjWindow::Inventory)
//		//|| gInterface.CheckWindow(ObjWindow::Store)
//		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
//		|| gInterface.CheckWindow(ObjWindow::Character)
//		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
//		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
//		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
//		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
//		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
//		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
//		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
//		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
//		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
//		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
//		//|| gInterface.CheckWindow(ObjWindow::HeroList)
//	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
//		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
//		//|| gInterface.CheckWindow(ObjWindow::Options)	
//		|| gInterface.CheckWindow(ObjWindow::Help)
//		//|| gInterface.CheckWindow(ObjWindow::FastDial)
//		|| gInterface.CheckWindow(ObjWindow::SkillTree)
//		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
//		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
//		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
//		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
//		|| gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::Lugard)
//		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
//		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
//		|| gInterface.CheckWindow(ObjWindow::Jerint)
//		|| gInterface.CheckWindow(ObjWindow::FullMap)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
//		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
//		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
//		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
//		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
//		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
//	{
//		return;
//	}
//	if (jCRenderRuud.OpeningRuud)
//	{
//		return;
//	}
//
//	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
//	{
//	y += ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 ) ? 8 : 5;
//
//	if( MinimizarPet == 0 )
//		{
//		RenderBitmap(61545, 2, y + 22, Return2X(TransForX( 74 )), ReturnY(TransForY( 24 )), 0.0, 0.1731800437, 0.75, 0.2378999293,1, 1, 0); //-- Fondo
//
//		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
//		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
//		pDrawText(pTextThis(), 5, y + 27, (LPCTSTR)nameIndex, 0, 0, (LPINT) 1, 0);
//
//		int v15 = (double)hp / (double)hpmax * 69.0;
//
//		pSetBlend(1);
//		glColor4f(0.4274, 0.0313, 0.1254, 0.798);
//
//		pDrawBarForm(4, y + 38, Return2X(TransForX( v15 )), 4, 0, 0);
//		pGLSwitch();
//		pSetBlend(0);
//		glColor4f(1.0, 1.0, 1.0, 1.0);
//		}
//	}
//}
//--

void Interface::RenderObjectSystem2()
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	//-- Shop Ruud Activado
	//-- Number Stack
	SetCompleteHook(0xE9, 0x00895600, &sub_895600);
	//-- Windows Inventory Ruud
	//SetCompleteHook(0xE8, 0x00836EF6, &InventoryWindows);
	}
	//--
	//--Spirit BarHP Activado
	//if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	//{
	//SetCompleteHook(0xE8, 0x007E020C, &PetSpiritHP); //-- PAJARRACO
	//SetCompleteHook(0xE8, 0x007E0298, &PetSpiritHP);//-- PAJARRACO
	//}

	//--
}
//=========================================================================================================================================
//=========================================================================================================================================

#if(CHARACTER_NEW)
void Interface::DrawCharacterWindow()
{
	if (this->CheckWindow(ObjWindow::ExpandWarehouse)
		- CheckWindow(ObjWindow::SkillTree)
		- CheckWindow(ObjWindow::CashShop))
	{
		Data[TINHNANG_CHARACTER].OnShow = false;
		return;
	}

	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (this->CheckWindow(ObjWindow::Inventory))
	{
		//--------------------------------------------------------------------------------------------
		if (gObjUser.TinhNang == 1)
		{
			this->DrawGUI(TINHNANG_CHARACTER, StartX + 281, StartY + 400);
			if (CheckButtonPressed(StartX + 281, StartY + 400, Return2X(TransForX(43)), ReturnY(TransForY(17))))
			{
				RenderBitmap(61535, StartX + 281, StartY + 400, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			else
			{
				RenderBitmap(61535, StartX + 281, StartY + 400, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			this->DrawFormat(eWhite, StartX + 284, StartY + 403, 210, 1, gOther.TextVN[140]); // Tính năng
		}
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------
#if(DEV_PLAYERSHOP)
		if (gObjUser.ChoTroi == 1)
		{
			this->DrawGUI(CHOTROI_CHARACTER, StartX + 199, StartY + 174);
			if (CheckButtonPressed(StartX + 199, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17))))
			{
				RenderBitmap(61535, StartX + 199, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			else
			{
				RenderBitmap(61535, StartX + 199, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			this->DrawFormat(eWhite, StartX + 203, StartY + 177, 210, 1, "Chợ Trời"); // Trang sức
		}
#endif
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------
// MUUN
		if (gObjUser.MuunPet == 1)
		{
			this->DrawGUI(MUUN_CHARACTER, StartX + 243, StartY + 174);
			if (CheckButtonPressed(StartX + 243, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17))))
			{
				RenderBitmap(61535, StartX + 243, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			else
			{
				RenderBitmap(61535, StartX + 243, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			//                              + 4             + 3
			this->DrawFormat(eWhite, StartX + 247, StartY + 177, 210, 1, "MuunPet");
		}

#if(SHOPSEARCH==TRUE)
		if (gObjUser.TimShop == 1)
		{
			this->DrawGUI(STORE_CHARACTER, StartX + 243, StartY + 195);
			if (CheckButtonPressed(StartX + 243, StartY + 195, Return2X(TransForX(43)), ReturnY(TransForY(17))))
			{
				RenderBitmap(61535, StartX + 243, StartY + 195, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			else
			{
				RenderBitmap(61535, StartX + 243, StartY + 195, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			//                              + 4             + 3
			this->DrawFormat(eWhite, StartX + 247, StartY + 198, 210, 1, "Tìm Store");
		}
#endif
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------

		//--------------------------------------------------------------------------------------------
	}
}

bool Interface::EventCharacterWindow_TinhNang(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[TINHNANG_CHARACTER].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(TINHNANG_CHARACTER))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[TINHNANG_CHARACTER].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[TINHNANG_CHARACTER].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[TINHNANG_CHARACTER].EventTick = GetTickCount();

	if (gObjUser.TinhNang == 1)
	{
		if (GetForegroundWindow() == pGameWindow)
		{
			if (gInterface.CheckTinhNangWindow())
			{
				gInterface.CloseTinhNangWindow();
				pSetCursorFocus = false;
			}
			else
			{
				gInterface.OpenTinhNangWindow();
			}
		}
		this->BUY_TINH_NANG_GAME(10);
	}

	if (gObjUser.TinhNang == 0)
	{
		gInterface.DrawMessage(1, "Chức năng [Tính Năng] đang bảo trì !");
	}

	return true;
}

#endif

#if(DEV_PLAYERSHOP)
bool Interface::EventCharacterWindow_ChoTroi(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[CHOTROI_CHARACTER].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(CHOTROI_CHARACTER))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[CHOTROI_CHARACTER].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[CHOTROI_CHARACTER].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[CHOTROI_CHARACTER].EventTick = GetTickCount();

	if (gObjUser.ChoTroi == 1)
	{
		gInterface.OpenWindowEx(ObjWindowsEx::exWinItemMarket);
		// fix ?
		g_ChoTroi.CGReqItemList();
	}

	if (gObjUser.ChoTroi == 0)
	{
		gInterface.DrawMessage(1, "Chức năng [Chợ Trời] đang bảo trì !");
	}

	return true;
}
#endif
// Muun
bool Interface::EventCharacterWindow_MuunPet(DWORD Event)
{
	if (this->CheckWindow(ObjWindow::Trade))
	{
		return false;
	}

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[MUUN_CHARACTER].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(MUUN_CHARACTER))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[MUUN_CHARACTER].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[MUUN_CHARACTER].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[MUUN_CHARACTER].EventTick = GetTickCount();
	//---
	if (gObjUser.MuunPet == 1)
	{
		if (!IsVisible(g_pNewUISystem(), 33))
		{
			g_MuunSystem.InventoryCTRLStatus = !g_MuunSystem.InventoryCTRLStatus;
		}
	}
	if (gObjUser.MuunPet == 0)
	{
		gInterface.DrawMessage(1, "Chức năng [MuunPet] đang bảo trì !");
	}

	//22-03-2022
	if (gObjUser.MuunPetTime == 1)
	{
		gInterface.BUY_TINH_NANG_GAME(33);
	}

#if(MUUNAFK == 1)
	gInterface.BUY_TINH_NANG_GAME(34);
#endif

	//---
	return true;
}

#if(SHOPSEARCH==TRUE)
bool Interface::EventCharacterWindow_Store(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[STORE_CHARACTER].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(STORE_CHARACTER))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[STORE_CHARACTER].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[STORE_CHARACTER].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[STORE_CHARACTER].EventTick = GetTickCount();

	//---
	if (gObjUser.TimShop == 1)
	{
		gInterface.BUY_TINH_NANG_GAME(15);
	}
	if (gObjUser.TimShop == 0)
	{
		gInterface.DrawMessage(1, "Chức năng [Tìm Shop] đang bảo trì !");
	}
	//---

	return true;
}
#endif


#if(TINHNANG_NEW == 1)
void Interface::BUY_TINH_NANG_GAME(int Number)
{
	BUY_TINH_NANG_REQ pMsg;
	pMsg.h.set(0xFC, 0x01, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void Interface::GetInfoTinhNang(PMSG_TINHNANG_UPD * aRecv)
{
	this->m_CommandResetPoint_WCoinC = aRecv->CommandResetPoint_WCoinC;
	this->m_CommandResetMaster_WCoinC = aRecv->CommandResetMaster_WCoinC;
}
//===================================================================================================================
void Interface::DrawTinhNangWinDow()
{
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

	if (!this->Data[TINHNANG_MAIN].OnShow)
	{
		return;
	}
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(TINHNANG_MAIN, StartX, StartY);
	//--------------------------------------------------------------------------------------------
	//2-04-2022
	if (gObjUser.XoaHomDo == 1)
	{
		gCItemSetOption.ItemTooltipS15(StartX + 128, gInterface.Data[TINHNANG_MAIN].Y + 75, 115, 60, 0.0, 0);
	}
	if (gObjUser.LamNhiemVu == 1)
	{
		gCItemSetOption.ItemTooltipS15(StartX + 128, gInterface.Data[TINHNANG_MAIN].Y + 140, 115, 60, 0.0, 0);
	}
	//--------------------------------------------------------------------------------------------
	if (gObjUser.TayDiem == 1)
	{
		gCItemSetOption.ItemTooltipS15(StartX + 128, gInterface.Data[TINHNANG_MAIN].Y + 205, 115, 60, 0.0, 0);
	}
	//--------------------------------------------------------------------------------------------
	if (gObjUser.TayMaster == 1)
	{
		gCItemSetOption.ItemTooltipS15(StartX + 128, gInterface.Data[TINHNANG_MAIN].Y + 270, 115, 60, 0.0, 0);
	}
	//--------------------------------------------------------------------------------------------

	if (this->IsWorkZone(TINHNANG_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	if (gObjUser.XoaHomDo == 1)
	{
		//--------------------------------------------------------------------------------------------
		this->DrawFormat(eWhite, StartX + 160, gInterface.Data[TINHNANG_MAIN].Y + 80, 210, 1, gOther.TextVN[136]); // Xóa hòm đồ
		this->DrawFormat(eRed, StartX + 155, gInterface.Data[TINHNANG_MAIN].Y + 95, 210, 1, gOther.TextVN[137]);   // Chú ý đồ giá trị!
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_YES, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 115);
		if (CheckButtonPressed(StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 142, gInterface.Data[TINHNANG_MAIN].Y + 118, 210, 1, gOther.TextVN[134]); // Đồng ý
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_NO, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 115);
		if (CheckButtonPressed(StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 202, gInterface.Data[TINHNANG_MAIN].Y + 118, 210, 1, gOther.TextVN[135]); // Từ chối
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------------------
	if (gObjUser.LamNhiemVu == 1)
	{
		this->DrawFormat(eWhite, StartX + 160, gInterface.Data[TINHNANG_MAIN].Y + 145, 210, 1, gOther.TextVN[145]); // Làm nhiệm vụ
		this->DrawFormat(eBlue, StartX + 137, gInterface.Data[TINHNANG_MAIN].Y + 160, 210, 1, gOther.TextVN[146]);  // Thăng cấp nhân vật Master!
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_YES3, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 180);
		if (CheckButtonPressed(StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 142, gInterface.Data[TINHNANG_MAIN].Y + 183, 210, 1, gOther.TextVN[134]); // Đồng ý
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_NO3, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 180);
		if (CheckButtonPressed(StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 202, gInterface.Data[TINHNANG_MAIN].Y + 183, 210, 1, gOther.TextVN[135]); // Từ chối
	}
	if (gObjUser.TayDiem == 1)
	{
		this->DrawFormat(eWhite, StartX + 170, gInterface.Data[TINHNANG_MAIN].Y + 210, 210, 1, gOther.TextVN[149]); // Tẩy điểm 
		this->DrawFormat(eYellow, StartX + 140, gInterface.Data[TINHNANG_MAIN].Y + 225, 210, 1, gOther.TextVN[148], m_CommandResetPoint_WCoinC);  // WCoinC yêu cầu = %d
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_YES1, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 245);
		if (CheckButtonPressed(StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 142, gInterface.Data[TINHNANG_MAIN].Y + 248, 210, 1, gOther.TextVN[134]); // Đồng ý
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_NO1, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 245);
		if (CheckButtonPressed(StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 202, gInterface.Data[TINHNANG_MAIN].Y + 248, 210, 1, gOther.TextVN[135]); // Từ chối
	}
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	if (gObjUser.TayMaster == 1)
	{
		this->DrawFormat(eWhite, StartX + 160, gInterface.Data[TINHNANG_MAIN].Y + 275, 210, 1, gOther.TextVN[147]); // Tẩy điểm Master
		this->DrawFormat(eYellow, StartX + 140, gInterface.Data[TINHNANG_MAIN].Y + 290, 210, 1, gOther.TextVN[148], m_CommandResetMaster_WCoinC);  // WCoinC yêu cầu = %d
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_YES2, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 310);
		if (CheckButtonPressed(StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 135, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 142, gInterface.Data[TINHNANG_MAIN].Y + 313, 210, 1, gOther.TextVN[134]); // Đồng ý
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(BUTTON_NO2, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 310);
		if (CheckButtonPressed(StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 195, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 202, gInterface.Data[TINHNANG_MAIN].Y + 313, 210, 1, gOther.TextVN[135]); // Từ chối
	}
}
bool Interface::EventTinhNangWinDow(DWORD Event)
{
	if (gObjUser.TayDiem == 1)
	{
		if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES1))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES1].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[BUTTON_YES1].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[BUTTON_YES1].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[BUTTON_YES1].EventTick = GetTickCount();
			this->BUY_TINH_NANG_GAME(1);
			this->CloseTinhNangWindow();
		}
		if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO1))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO1].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[BUTTON_NO1].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[BUTTON_NO1].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[BUTTON_NO1].EventTick = GetTickCount();
			this->CloseTinhNangWindow();
		}
	}
	//---------
	if (gObjUser.TayMaster == 1)
	{
		if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES2))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES2].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[BUTTON_YES2].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[BUTTON_YES2].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[BUTTON_YES2].EventTick = GetTickCount();
			this->BUY_TINH_NANG_GAME(2);
			this->CloseTinhNangWindow();
		}
		if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO2))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO2].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[BUTTON_NO2].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[BUTTON_NO2].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[BUTTON_NO2].EventTick = GetTickCount();
			this->CloseTinhNangWindow();
		}
	}
	//------------
	if (gObjUser.LamNhiemVu == 1)
	{
		if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES3))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES3].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[BUTTON_YES3].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[BUTTON_YES3].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[BUTTON_YES3].EventTick = GetTickCount();
			this->BUY_TINH_NANG_GAME(3);
			this->CloseTinhNangWindow();
		}
		if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO3))
		{
			DWORD CurrentTick = GetTickCount();
			DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO3].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[BUTTON_NO3].OnClick = true;
				pSetCursorFocus = true;
				return true;
			}
			// ----
			gInterface.Data[BUTTON_NO3].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			gInterface.Data[BUTTON_NO3].EventTick = GetTickCount();
			this->CloseTinhNangWindow();
		}
	}

	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES].EventTick = GetTickCount();
		if (gObjUser.XoaHomDo == 1)
		{
			this->BUY_TINH_NANG_GAME(8);
		}
		if (gObjUser.XoaHomDo == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Xóa Hòm Đồ] đang bảo trì !");
		}
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO].EventTick = GetTickCount();
		if (gObjUser.XoaHomDo == 1)
		{
			this->CloseTinhNangWindow();
		}
		if (gObjUser.XoaHomDo == 0)
		{
			gInterface.DrawMessage(1, "Chức năng [Xóa Hòm Đồ] đang bảo trì !");
		}
	}


	return true;
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
#if(SACHTHUOCTINH_NEW == 1)
void Interface::DrawSachThuocTinhInterface()
{
	if (CheckWindow(ObjWindow::SkillTree) - CheckWindow(ObjWindow::CashShop))
	{
		Data[eSACHTHUOCTINH_INTERFACE].OnShow = false;
		return;
	}

	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float StartXRing = 40.0;

	if (this->CheckWindow(ObjWindow::Inventory))
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			if (gObjUser.SachThuocTinh == 1)
			{
				gInterface.DrawGUI(eSACHTHUOCTINH_INTERFACE, StartX + 285, StartY + 180);

				if (this->m_SachThuocTinh_01 >= 1)
				{
					gInterface.DrawItem2(StartX + 302, StartY + 205, 0, 0, ITEM(14, 450), 0, 0, 5, 0);
				}

				if (gInterface.IsWorkZone(eSACHTHUOCTINH_INTERFACE))
				{
					DWORD Color = eGray150;
					gInterface.DrawColoredGUI(eSACHTHUOCTINH_INTERFACE, gInterface.Data[eSACHTHUOCTINH_INTERFACE].X, gInterface.Data[eSACHTHUOCTINH_INTERFACE].Y, Color);
				}
			}

#if(PHUKIEN_NEW == 1)
			if (gObjUser.PhuKien == 1)
			{
				//==========================================================================================================
				gInterface.DrawGUI(ePHUKIEN1_INTERFACE, StartX + 203, StartY + 90);

				if (this->m_PHUKIEN1 >= 1)
				{
					gInterface.DrawItem2(StartX + 209, StartY + 120, 0, 0, ITEM(14, gProtect.m_MainInfo.IDPhuKien1), 0, 0, 0, 0);
				}
				if (this->m_PHUKIEN1 == 15)
				{
					gInterface.DrawItem2(StartX + 209, StartY + 120, 0, 0, ITEM(14, gProtect.m_MainInfo.IDPhuKien1), 15, 0, 5, 0);
				}
				//==========================================================================================================
				gInterface.DrawGUI(ePHUKIEN2_INTERFACE, StartX + 266, StartY + 90);

				if (this->m_PHUKIEN2 >= 1)
				{
					gInterface.DrawItem2(StartX + 271, StartY + 123, 0, 0, ITEM(14, gProtect.m_MainInfo.IDPhuKien2), 0, 0, 0, 0);
				}
				if (this->m_PHUKIEN2 == 15)
				{
					gInterface.DrawItem2(StartX + 271, StartY + 123, 0, 0, ITEM(14, gProtect.m_MainInfo.IDPhuKien2), 15, 0, 5, 0);
				}
				//==========================================================================================================
				if (this->m_PHUKIEN1 >= 1)
				{
					if (this->Data[eSACHTHUOCTINH_MAIN].OnShow)//
					{
						return;
					}

					if (gInterface.IsWorkZone(ePHUKIEN1_INTERFACE))
					{
						DWORD Color = eGray150;
						//-------------------------
						gCItemSetOption.ItemTooltipS15(340 - StartXRing, 100, 148, 170, 0.0, 0);
						//-------------------------
						gInterface.DrawFormat(eExcellentS15, StartX + 65 - StartXRing, StartY + 90, 150, 1, gOther.TextVN_PhuKien[19], this->m_PHUKIEN1);
						//-------------------------
						gInterface.DrawFormat(eWhite, StartX + 70 - StartXRing, StartY + 110, 100, 1, gOther.TextVN_PhuKien[2]);
						gInterface.DrawFormat(eWhite, StartX + 70 - StartXRing, StartY + 120, 100, 1, gOther.TextVN_PhuKien[3]);
						gInterface.DrawFormat(eWhite, StartX + 70 - StartXRing, StartY + 130, 100, 1, gOther.TextVN_PhuKien[4]);
						//-------------------------
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 150, 200, 1, gOther.TextVN_PhuKien[5], gObjUser.OP1_PHUKIEN1);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 160, 200, 1, gOther.TextVN_PhuKien[6], gObjUser.OP2_PHUKIEN1);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 170, 200, 1, gOther.TextVN_PhuKien[7], gObjUser.OP3_PHUKIEN1);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 180, 200, 1, gOther.TextVN_PhuKien[8], gObjUser.OP4_PHUKIEN1);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 190, 200, 1, gOther.TextVN_PhuKien[9], gObjUser.OP5_PHUKIEN1);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 200, 200, 1, gOther.TextVN_PhuKien[10], gObjUser.OP6_PHUKIEN1);
						gInterface.DrawFormat(eGray100, StartX + 45 - StartXRing, StartY + 210, 200, 1, gOther.TextVN_PhuKien[11], gObjUser.OP7_PHUKIEN1);
						//-------------------------
						if (this->m_PHUKIEN1 >= 5)
						{
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 150, 200, 1, gOther.TextVN_PhuKien[5], gObjUser.OP1_PHUKIEN1);
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 160, 200, 1, gOther.TextVN_PhuKien[6], gObjUser.OP2_PHUKIEN1);
						}
						if (this->m_PHUKIEN1 >= 10)
						{
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 170, 200, 1, gOther.TextVN_PhuKien[7], gObjUser.OP3_PHUKIEN1);
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 180, 200, 1, gOther.TextVN_PhuKien[8], gObjUser.OP4_PHUKIEN1);
						}
						if (this->m_PHUKIEN1 >= 15)
						{
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 190, 200, 1, gOther.TextVN_PhuKien[9], gObjUser.OP5_PHUKIEN1);
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 200, 200, 1, gOther.TextVN_PhuKien[10], gObjUser.OP6_PHUKIEN1);
							gInterface.DrawFormat(eYellow, StartX + 45 - StartXRing, StartY + 210, 200, 1, gOther.TextVN_PhuKien[11], gObjUser.OP7_PHUKIEN1);
						}
						//-------------------------
						gInterface.DrawFormat(eBlue, StartX + 62 - StartXRing, StartY + 230, 200, 1, "Click Chuột để tháo xuống");

						gInterface.DrawColoredGUI(ePHUKIEN1_INTERFACE, gInterface.Data[ePHUKIEN1_INTERFACE].X, gInterface.Data[ePHUKIEN1_INTERFACE].Y, Color);
					}
				}

				if (this->m_PHUKIEN2 >= 1)
				{
					if (this->Data[eSACHTHUOCTINH_MAIN].OnShow)//
					{
						return;
					}
					if (gInterface.IsWorkZone(ePHUKIEN2_INTERFACE))
					{
						DWORD Color = eGray150;
						//-------------------------
						gCItemSetOption.ItemTooltipS15(340 - StartXRing, 100, 148, 170, 0.0, 0);
						//-------------------------
						gInterface.DrawFormat(eExcellentS15, StartX + 65 - StartXRing, StartY + 90, 150, 1, gOther.TextVN_PhuKien[20], this->m_PHUKIEN2);
						//-------------------------
						gInterface.DrawFormat(eWhite, StartX + 70 - StartXRing, StartY + 110, 100, 1, gOther.TextVN_PhuKien[2]);
						gInterface.DrawFormat(eWhite, StartX + 70 - StartXRing, StartY + 120, 100, 1, gOther.TextVN_PhuKien[3]);
						gInterface.DrawFormat(eWhite, StartX + 70 - StartXRing, StartY + 130, 100, 1, gOther.TextVN_PhuKien[4]);
						//-------------------------
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 150, 200, 1, gOther.TextVN_PhuKien[5], gObjUser.OP1_PHUKIEN2);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 160, 200, 1, gOther.TextVN_PhuKien[6], gObjUser.OP2_PHUKIEN2);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 170, 200, 1, gOther.TextVN_PhuKien[7], gObjUser.OP3_PHUKIEN2);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 180, 200, 1, gOther.TextVN_PhuKien[8], gObjUser.OP4_PHUKIEN2);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 190, 200, 1, gOther.TextVN_PhuKien[9], gObjUser.OP5_PHUKIEN2);
						gInterface.DrawFormat(eGray100, StartX + 55 - StartXRing, StartY + 200, 200, 1, gOther.TextVN_PhuKien[10], gObjUser.OP6_PHUKIEN2);
						gInterface.DrawFormat(eGray100, StartX + 45 - StartXRing, StartY + 210, 200, 1, gOther.TextVN_PhuKien[11], gObjUser.OP7_PHUKIEN2);
						//-------------------------
						if (this->m_PHUKIEN2 >= 5)
						{
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 150, 200, 1, gOther.TextVN_PhuKien[5], gObjUser.OP1_PHUKIEN2);
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 160, 200, 1, gOther.TextVN_PhuKien[6], gObjUser.OP2_PHUKIEN2);
						}
						if (this->m_PHUKIEN2 >= 10)
						{
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 170, 200, 1, gOther.TextVN_PhuKien[7], gObjUser.OP3_PHUKIEN2);
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 180, 200, 1, gOther.TextVN_PhuKien[8], gObjUser.OP4_PHUKIEN2);
						}
						if (this->m_PHUKIEN2 >= 15)
						{
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 190, 200, 1, gOther.TextVN_PhuKien[9], gObjUser.OP5_PHUKIEN2);
							gInterface.DrawFormat(eYellow, StartX + 55 - StartXRing, StartY + 200, 200, 1, gOther.TextVN_PhuKien[10], gObjUser.OP6_PHUKIEN2);
							gInterface.DrawFormat(eYellow, StartX + 45 - StartXRing, StartY + 210, 200, 1, gOther.TextVN_PhuKien[11], gObjUser.OP7_PHUKIEN2);
						}
						//-------------------------
						gInterface.DrawFormat(eBlue, StartX + 62 - StartXRing, StartY + 230, 200, 1, "Click Chuột để tháo xuống");

						gInterface.DrawColoredGUI(ePHUKIEN2_INTERFACE, gInterface.Data[ePHUKIEN2_INTERFACE].X, gInterface.Data[ePHUKIEN2_INTERFACE].Y, Color);
					}
				}
			}
#endif

		}
	}
}
bool Interface::EventSachThuocTinhInterface(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eSACHTHUOCTINH_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(eSACHTHUOCTINH_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eSACHTHUOCTINH_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eSACHTHUOCTINH_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eSACHTHUOCTINH_INTERFACE].EventTick = GetTickCount();

	if (gObjUser.SachThuocTinh == 1)
	{
		if (this->m_SachThuocTinh_01 >= 1)
		{
			if (GetForegroundWindow() == pGameWindow)
			{
				if (this->CheckSachThuocTinhWindow())
				{
					this->CloseSachThuocTinhWindow();
				}
				else
				{
					this->OpenSachThuocTinhWindow();
				}
			}
		}
		this->BUG_SACHTHUOCTINH(8);
	}
	if (gObjUser.SachThuocTinh == 0)
	{
		gInterface.DrawMessage(1, "Chức năng [Sách Thuộc Tính] đang bảo trì !");
	}

	return true;
}

#if(PHUKIEN_NEW == 1)
bool Interface::EventRemovePhuKien1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ePHUKIEN1_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(ePHUKIEN1_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[ePHUKIEN1_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[ePHUKIEN1_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[ePHUKIEN1_INTERFACE].EventTick = GetTickCount();

	if (gObjUser.PhuKien == 1)
	{
		if (this->m_PHUKIEN1 >= 1)
		{
			this->BUG_PHUKIEN(5);
		}
	}

	return true;
}
bool Interface::EventRemovePhuKien2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ePHUKIEN2_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(ePHUKIEN2_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[ePHUKIEN2_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[ePHUKIEN2_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[ePHUKIEN2_INTERFACE].EventTick = GetTickCount();

	if (gObjUser.PhuKien == 1)
	{
		if (this->m_PHUKIEN2 >= 1)
		{
			this->BUG_PHUKIEN(6);
		}
	}

	return true;
}
#endif

//=========================================================================================================================================
void Interface::DrawSachThuocTinh()
{
	{
		if (this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse))
		return;
		//--------------------------------------------------------------
		if (!this->Data[eSACHTHUOCTINH_MAIN].OnShow)
		{
			return;
		}
		//--------------------------------------------------------------
		float MainWidth = 30.0;
		float MainHeight = 20.0;
		float StartY = 40.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

		if (this->CheckWindow(ObjWindow::Inventory))
		{
			//--------------------------------------------------------------
			pDrawGUFULL(61526, StartX - 70, StartY - 25, 340, 620, 0, 0, 1, 1, 1, 1, 0.0);  // IMAGE MENU
			//--------------------------------------------------------------
			pSetCursorFocus = true;
			//--------------------------------------------------------------
			pDrawGUFULL(0x502A, StartX - 18, StartY + 25, 2, 330, 0, 0, 1, 1, 1, 1, 0.0); // Dọc
			pDrawGUFULL(0x502A, StartX + 38, StartY + 25, 2, 330, 0, 0, 1, 1, 1, 1, 0.0); // Dọc
			//--------------------------------------------------------------
			pDrawGUFULL(0x501A, StartX - 60, StartY + 50, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 100, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 150, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 200, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 250, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 300, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			//--------------------------------------------------------------
			gInterface.DrawItem2(StartX - 40, StartY + 81, 0, 0, ITEM(14, 451), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 131, 0, 0, ITEM(14, 452), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 181, 0, 0, ITEM(14, 453), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 231, 0, 0, ITEM(14, 454), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 281, 0, 0, ITEM(14, 455), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 331, 0, 0, ITEM(14, 456), 15, 63, 0, 0);
			//--------------------------------------------------------------
			gInterface.DrawFormat(eWhite, StartX + 10, StartY - 1, 1000, 1, gOther.TextVN_SachThuocTinh[0]);
			//--------------------------------------------------------------
			gInterface.DrawFormat(eAncient, StartX - 60, StartY + 25, 1000, 1, gOther.TextVN_SachThuocTinh[15]);
			gInterface.DrawFormat(eAncient, StartX - 5, StartY + 25, 1000, 1, gOther.TextVN_SachThuocTinh[16]);
			gInterface.DrawFormat(eAncient, StartX + 65, StartY + 25, 1000, 1, gOther.TextVN_SachThuocTinh[17]);
			//--------------------------------------------------------------
			// Slot 2
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_01);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[2], this->m_OPTION_ACTIVE_01);

			if (this->m_SachThuocTinh_02 >= this->m_OPTION_LEVEL_01)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_01);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[2], this->m_OPTION_ACTIVE_01);
			}

			// Slot 3
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_02);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[3], this->m_OPTION_ACTIVE_02);

			if (this->m_SachThuocTinh_02 >= this->m_OPTION_LEVEL_02)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_02);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[3], this->m_OPTION_ACTIVE_02);
			}

			// Slot 4
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_03);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[4], this->m_OPTION_ACTIVE_03);

			if (this->m_SachThuocTinh_03 >= this->m_OPTION_LEVEL_03)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_03);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[4], this->m_OPTION_ACTIVE_03);
			}

			// Slot 5
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_04);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[5], this->m_OPTION_ACTIVE_04);

			if (this->m_SachThuocTinh_03 >= this->m_OPTION_LEVEL_04)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_04);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[5], this->m_OPTION_ACTIVE_04);
			}

			// Slot 6
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_05);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[6], this->m_OPTION_ACTIVE_05);

			if (this->m_SachThuocTinh_04 >= this->m_OPTION_LEVEL_05)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_05);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[6], this->m_OPTION_ACTIVE_05);
			}

			// Slot 7
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_06);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[7], this->m_OPTION_ACTIVE_06);

			if (this->m_SachThuocTinh_04 >= this->m_OPTION_LEVEL_06)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_06);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[7], this->m_OPTION_ACTIVE_06);
			}

			// Slot 8
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_07);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[8], this->m_OPTION_ACTIVE_07);

			if (this->m_SachThuocTinh_05 >= this->m_OPTION_LEVEL_07)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_07);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[8], this->m_OPTION_ACTIVE_07);
			}

			// Slot 9
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_08);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[9], this->m_OPTION_ACTIVE_08);

			if (this->m_SachThuocTinh_05 >= this->m_OPTION_LEVEL_08)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_08);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[9], this->m_OPTION_ACTIVE_08);
			}

			// Slot 10
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_09);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[10], this->m_OPTION_ACTIVE_09);

			if (this->m_SachThuocTinh_06 >= this->m_OPTION_LEVEL_09)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_09);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[10], this->m_OPTION_ACTIVE_09);
			}

			// Slot 11
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_10);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[11], this->m_OPTION_ACTIVE_10);

			if (this->m_SachThuocTinh_06 >= this->m_OPTION_LEVEL_10)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_10);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[11], this->m_OPTION_ACTIVE_10);
			}

			// Slot 12
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_11);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[12], this->m_OPTION_ACTIVE_11);

			if (this->m_SachThuocTinh_07 >= this->m_OPTION_LEVEL_11)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_11);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[12], this->m_OPTION_ACTIVE_11);
			}

			// Slot 13
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_12);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[13], this->m_OPTION_ACTIVE_12);

			if (this->m_SachThuocTinh_07 >= this->m_OPTION_LEVEL_12)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_12);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[13], this->m_OPTION_ACTIVE_12);
			}
		}
		//--------------------------------------------------------------
	}
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEventEx(PMSG_TVTEVENT_UPD * aRecv)
{
	this->m_ScoreBlue = 0;
	this->m_ScoreBlue = aRecv->ScoreBlue;
	this->m_ScoreRed = 0;
	this->m_ScoreRed = aRecv->ScoreRed;
	this->m_KillCount = 0;
	this->m_KillCount = aRecv->KillCount;
	this->m_DieCount = 0;
	this->m_DieCount = aRecv->DieCount;
	this->m_TotalPlayer = 0;
	this->m_TotalPlayer = aRecv->TotalPlayer;
}

#if(SACHTHUOCTINH_NEW)
void Interface::GetInfoThuocTinh(PMSG_THUOCTINH_UPD * aRecv)
{
	//-----------------------------
	this->m_SachThuocTinh_02 = aRecv->SachThuocTinh_02;
	this->m_SachThuocTinh_03 = aRecv->SachThuocTinh_03;
	this->m_SachThuocTinh_04 = aRecv->SachThuocTinh_04;
	this->m_SachThuocTinh_05 = aRecv->SachThuocTinh_05;
	this->m_SachThuocTinh_06 = aRecv->SachThuocTinh_06;
	this->m_SachThuocTinh_07 = aRecv->SachThuocTinh_07;
}
void Interface::GetInfoThuocTinhAtive(PMSG_THUOCTINH_ATIVE_UPD * aRecv)
{
	//-----------------------------
	this->m_OPTION_LEVEL_01 = aRecv->OPTION_LEVEL_01;
	this->m_OPTION_LEVEL_02 = aRecv->OPTION_LEVEL_02;
	this->m_OPTION_LEVEL_03 = aRecv->OPTION_LEVEL_03;
	this->m_OPTION_LEVEL_04 = aRecv->OPTION_LEVEL_04;
	this->m_OPTION_LEVEL_05 = aRecv->OPTION_LEVEL_05;
	this->m_OPTION_LEVEL_06 = aRecv->OPTION_LEVEL_06;
	this->m_OPTION_LEVEL_07 = aRecv->OPTION_LEVEL_07;
	this->m_OPTION_LEVEL_08 = aRecv->OPTION_LEVEL_08;
	this->m_OPTION_LEVEL_09 = aRecv->OPTION_LEVEL_09;
	this->m_OPTION_LEVEL_10 = aRecv->OPTION_LEVEL_10;
	this->m_OPTION_LEVEL_11 = aRecv->OPTION_LEVEL_11;
	this->m_OPTION_LEVEL_12 = aRecv->OPTION_LEVEL_12;
	this->m_OPTION_ACTIVE_01 = aRecv->OPTION_ACTIVE_01;
	this->m_OPTION_ACTIVE_02 = aRecv->OPTION_ACTIVE_02;
	this->m_OPTION_ACTIVE_03 = aRecv->OPTION_ACTIVE_03;
	this->m_OPTION_ACTIVE_04 = aRecv->OPTION_ACTIVE_04;
	this->m_OPTION_ACTIVE_05 = aRecv->OPTION_ACTIVE_05;
	this->m_OPTION_ACTIVE_06 = aRecv->OPTION_ACTIVE_06;
	this->m_OPTION_ACTIVE_07 = aRecv->OPTION_ACTIVE_07;
	this->m_OPTION_ACTIVE_08 = aRecv->OPTION_ACTIVE_08;
	this->m_OPTION_ACTIVE_09 = aRecv->OPTION_ACTIVE_09;
	this->m_OPTION_ACTIVE_10 = aRecv->OPTION_ACTIVE_10;
	this->m_OPTION_ACTIVE_11 = aRecv->OPTION_ACTIVE_11;
	this->m_OPTION_ACTIVE_12 = aRecv->OPTION_ACTIVE_12;
}
#endif
//=====================================================================
#if(GHETINFOCLIENT == 1)
void Interface::GetInfoClient(PMSG_CLIENT_UPD * aRecv)
{
	//-----------------------------
	this->m_SachThuocTinh_01 = aRecv->SachThuocTinh_01;
	//-----------------------------
	this->m_PHUKIEN1 = aRecv->PHUKIEN1;
	this->m_PHUKIEN2 = aRecv->PHUKIEN2;
	this->m_AutoResetEnable = aRecv->AutoResetEnable;
	this->m_AttackCustom = aRecv->AttackCustom;
	this->m_GHRS = aRecv->GHRS;
	this->m_DanhHieu = aRecv->DanhHieu;
	this->m_TuLuyen = aRecv->TuLuyen;
#if(MOCNAP == 1)
	this->m_MOCNAPCOIN = aRecv->MOCNAPCOIN;
#endif
	this->m_Money = aRecv->Money;
}
#endif
//=====================================================================
//---------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
void Interface::BUG_SACHTHUOCTINH(int Number)
{
	SACHTHUOCTINH_REQ pMsg;
	pMsg.h.set(0xFC, 0x09, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif
//---------------------------------------------------------
#if(PHUKIEN_NEW == 1)
void Interface::BUG_PHUKIEN(int Number)
{
	BUY_PHUKIEN_REQ pMsg;
	pMsg.h.set(0xFC, 0x10, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
#if(OFFLINE_MODE_NEW)
void Interface::DrawOffExpWindow()
{
	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0; // 100.0
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	//---------------------------------------------------------------------------------------//
	if (this->IsWorkZone(eOFFEXP_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//
	this->DrawGUI(eOFFEXP_MAIN, StartX, StartY + 20);

	gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 20, 260, 280, 0.0, 150);
	//gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 30, 260, 260, 0.0, 150);

	//this->DrawGUI(eOFFEXP_TITLE, StartX, StartY);
	//StartY = this->DrawRepeatGUI(eOFFEXP_FRAME, StartX, StartY + 67.0, 13);
	//this->DrawGUI(eOFFEXP_FOOTER, StartX, StartY);

	this->DrawGUI(eOFFEXP_CLOSE, StartX + 216, this->Data[eOFFEXP_MAIN].Y + 28);
	// ----
	if (this->IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_CLOSE, this->Data[eOFFEXP_CLOSE].X, this->Data[eOFFEXP_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eOFFEXP_CLOSE].X + 5, this->Data[eOFFEXP_CLOSE].Y + 25, "Close");
	}
	// ----

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 5, 210, 3, "Treo Máy Offline"); // Treo Máy Offline

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 35, 210, 3, "Chào[%s]!Bạn đang bận việc và muốn treo máy ?", gObjUser.lpPlayer->Name); // "Chào [%s]! Bạn đang bận việc và muốn treo máy?"

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 55, 210, 3, "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."); // "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."

	pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2


	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	char szText[7][64] =
	{
		"Tự động Buff",
		"NULL",
		"Nhặt Zen",
		"Nhặt Ngọc",
		"Nhặt Item Hoàn hảo",
		"Nhặt Items Thần",
		"Nhặt Items có trong danh sách Auto train"
	};

	for (int i = 0; i<8; i++)
	{
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

		if (i != 1 && i != 7)
		{
			int btn = 1;
			if (i == 0 && gOfflineMode.DrawBuff == 0)
			{
				btn = 0;
			}

			if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
			{
				btn = 0;
			}

			this->DrawGUI(eOFFEXP_POINT, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 120 + (20 * i)); //
			this->DrawFormat(eWhite, StartX + 45, this->Data[eOFFEXP_MAIN].Y + 121 + (20 * i), 200, 1, szText[i]);
			if (btn == 1)
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i));
			}
			else
			{
//				this->DrawColoredButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i), eGray150);
			}

		}
	}

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 141, 210, 3, "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."); // "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."

	this->DrawGUI(eOFFEXP_BTN_OK, ButtonX - 3, this->Data[eOFFEXP_MAIN].Y + 260);
	this->DrawFormat(eWhite, StartX + 5, this->Data[eOFFEXP_MAIN].Y + 270, 210, 3, "Bắt Đầu"); // "Bắt Đầu"

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_BTN_OK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_BTN_OK, this->Data[eOFFEXP_BTN_OK].X, this->Data[eOFFEXP_BTN_OK].Y, Color);
	}

	gOfflineMode.DrawSkill(0, StartX);
	gOfflineMode.DrawSkill(1, StartX);
	gOfflineMode.DrawSkill(2, StartX);

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		if (this->IsWorkZone(StartX + (50 * (i + 1)), this->Data[eOFFEXP_MAIN].Y + 83, StartX + (50 * (i + 1)) + 20, this->Data[eOFFEXP_MAIN].Y + 83 + 28))
		{
			this->DrawToolTipEx(eWhite, StartX + (50 * (i + 1)) - 14, this->Data[eOFFEXP_MAIN].Y + 123, 50, 30, 3, gOfflineMode.SkillsName[i]);
		}
	}

	//if ((gObjUser.lpPlayer->Class & 7) == DarkWizard)
	//{
	//	pDrawGUI(0x1000, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1001, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1002, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkKnight)
	//{
	//	pDrawGUI(0x1003, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1004, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1005, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Elf)
	//{
	//	pDrawGUI(0x1006, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1007, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1008, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == MagicGladiator)
	//{
	//	pDrawGUI(0x1009, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1010, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1011, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkLord)
	//{
	//	pDrawGUI(0x1012, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1013, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1014, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Summoner)
	//{
	//	pDrawGUI(0x1015, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1016, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1017, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Monk)
	//{
	//	pDrawGUI(0x1018, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1019, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}

}
// ----------------------------------------------------------------------------------------------
bool Interface::EventOffExpWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return false;
	}

	if (IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_CLOSE].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].EventTick = GetTickCount();

		this->SwitchOffExpWindoState();
		// ----
		return false;
	}

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_BTN_OK].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].OnClick = false;;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].EventTick = GetTickCount();
		gOfflineMode.SendOffExpData();
		this->SwitchOffExpWindoState();
	}

	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	for (int i = 0; i<7; i++)
	{
		if (i == 1) continue;

		if (i == 0 && gOfflineMode.DrawBuff == 0)
		{
			continue;
		}

		if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
		{
			continue;
		}

		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (!this->Data[eOFFEXP_MAIN].OnShow)
			{
				return false;
			}
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 200)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gOfflineMode.ChangeCheckBox(i);
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		float X = gOfflineMode.GetSkillX(i);
		float Y = gOfflineMode.GetSkillY(i);

		if (this->IsWorkZone(X, Y, X + 20, Y + 28))
		{
			DWORD Delay = (CurrentTick - gOfflineMode.m_SkillCoord[i].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				continue;
			}
			// ----
			if (Delay < 500)
			{
				continue;
			}

			gOfflineMode.m_SkillCoord[i].EventTick = GetTickCount();

			if (gOfflineMode.SkillsData[i] == 0)
			{
				return false;
			}

			gOfflineMode.ClearSelectedSkill();
			gOfflineMode.SelectedSkill[i] = true;
		}
	}
	return false;
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEvent()
{

	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::Store)
		|| this->CheckWindow(ObjWindow::Character)
		|| this->CheckWindow(ObjWindow::Inventory)
		|| this->CheckWindow(ObjWindow::Quest)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	//===================================================================================================
	if (pMapNumber == 82)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 210, 0);
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);
		gCItemSetOption.ItemTooltipS15(MAX_WIN_WIDTH - 197, 3, 40, 13, 0.0, 0);
		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTVTHUD].EventTick) > 1000)
		{
			if (TvTEvent_TimeConLai > 0)
			{
				TvTEvent_TimeConLai = TvTEvent_TimeConLai - 1;
			}
			gInterface.Data[eTVTHUD].EventTick = GetTickCount();
		}
		int minutes = (TvTEvent_TimeConLai / 60) % 60;
		int seconds = TvTEvent_TimeConLai % 60;
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 210, 4, 70, 3, "%02d:%02d", minutes, seconds);
		//=================================

		this->DrawFormat(eRed, MAX_WIN_WIDTH - 176, 3, 70, 3, "%d", this->m_ScoreRed);
		this->DrawFormat(eBlue, MAX_WIN_WIDTH - 150, 3, 70, 3, "%d", this->m_ScoreBlue);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", this->m_KillCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", this->m_DieCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", this->m_TotalPlayer);

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);

	}
	//===================================================================================================
	if (pMapNumber == 88)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);

		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTVTHUD].EventTick) > 1000)
		{
			if (PKEvent_TimeConLai > 0)
			{
				PKEvent_TimeConLai = PKEvent_TimeConLai - 1;
			}
			gInterface.Data[eTVTHUD].EventTick = GetTickCount();
		}

		gCItemSetOption.ItemTooltipS15(MAX_WIN_WIDTH - 152, 3, 47, 13, 0.0, 0);
		int minutes = (PKEvent_TimeConLai / 60) % 60;
		int seconds = PKEvent_TimeConLai % 60;
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 165, 4, 70, 3, "%02d:%02d", minutes, seconds);
		//=================================

		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", gObjUser.SurvivorKill);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", gObjUser.SurvivorDie);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", gObjUser.SurvivorTotal);

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);
	}
}
// ----------------------------------------------------------------------------------------------
//======================================================================================================================================================
#if(DEV_DAMAGE_TABLE)

void Interface::DrawDamageTable()
{
	
	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::Store)
		|| this->CheckWindow(ObjWindow::Character)
		|| this->CheckWindow(ObjWindow::Inventory)
		|| this->CheckWindow(ObjWindow::Quest)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	if(!gDamageTable)
	{
		return ;
	}
	
	if(!gObjUser.m_SecondInfo)
	{
		return;
	}

	if(this->MiniMapCheck() || this->CombinedChecks())
	{
		return;
	}

	/////////////////

	float Wind = 10;
	float Hig = 10 - 85;
	
	gInterface.RightMiniInfoY -= Hig;

	float PosX = 531;
	float PosY = gInterface.RightMiniInfoY + 80;

	this->DrawBarForm(PosX, PosY, 130, 120, 0, 0, 0, 255);

	this->DrawFormat(eGold180, PosX + 0, PosY + 10, 100, 1, "-ST Nhiều Nhất:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 20, 100, 1, "-Quái Đánh Mất HP:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 30, 100, 1, "-Dame Giết Người:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 40, 100, 1, "-ST Lớn Nhất:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 50, 100, 1, "-Tổng Phản ST:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 60, 100, 1, "-Giảm Sát Thương:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 70, 100, 1, "-Damage Chí Mạng:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 80, 100, 1, "-Damage Hoàn Hảo:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 90, 100, 1, "-Damage x2:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 100, 100, 1, "-Bỏ Qua Phòng Thủ:");

	this->DrawFormat(eBlowPink, PosX + 80, PosY + 10, 100, 1, "%d", gObjUser.m_SecondDamage);
	this->DrawFormat(eBlowPink, PosX + 80, PosY + 20, 100, 1, "%d", gObjUser.m_SecondDefence);
	this->DrawFormat(eBlowPink, PosX + 80, PosY + 30, 100, 1, "%d", gObjUser.m_SecondReflect);
	this->DrawFormat(eBlowPink, PosX + 80, PosY + 40, 100, 1, "%d", gObjUser.m_SecondDamageMax);
	this->DrawFormat(eYellow,   PosX + 80, PosY + 50, 100, 1, "%d%%", g_StatsAdvance.m_Data.TotalDamageReflect);
	this->DrawFormat(eYellow,   PosX + 80, PosY + 60, 100, 1, "%d%%", g_StatsAdvance.m_Data.DamageReductionRate);
	this->DrawFormat(eYellow,   PosX + 80, PosY + 70, 100, 1, "%d%%", g_StatsAdvance.m_Data.CriticalDamageRate);
	this->DrawFormat(eYellow,   PosX + 80, PosY + 80, 100, 1, "%d%%", g_StatsAdvance.m_Data.ExellentDamageRate);
	this->DrawFormat(eYellow,   PosX + 80, PosY + 90, 100, 1, "%d%%", g_StatsAdvance.m_Data.DoubleDamageRate);
	this->DrawFormat(eYellow,   PosX + 80, PosY + 100, 100, 1, "%d%%", g_StatsAdvance.m_Data.IgnoreDefenceRate);

}
#endif
//===========
void CGMoveCTCMini(int Type) 
{
	if(Type > 0) 
	{
	CTCMINI_CGPACKET pMsg;
	pMsg.header.set(0xF3, 0x39, sizeof(pMsg));	
	pMsg.CongVao = Type-1;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}


DWORD ClickTickCount = 0;

void Interface::DrawCTCMiniWindow() 
{

	if(!this->Data[eCTCMiniWindow].OnShow) 
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW			=	250.0;
	float CuaSoH			=	250.0;

	float StartX			= (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY			= 95.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	//======Close
	int CloseX = StartX+CuaSoW-40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY , 36.0f, 29.0f);
	if ( pCheckMouseOver(CloseX, CloseY, 36, 36) == 1 )
	{
      if ( GetTickCount() - ClickTickCount > 300 )
      {
        if ( GetKeyState(1) & 0x8000 )
        {
          glColor3f(1.0f, 0.0f, 0.0f);
		  gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
          ClickTickCount = GetTickCount();
        }
      }
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX+15, CloseY+30, 0, 1, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY+5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "CTC Mini"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================
	StartY = StartY+ 45;
	CustomFont.Draw(CustomFont.FontNormal, StartX+(CuaSoW/10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: +25000 cống hiến khi Phá Cổng"); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontNormal, StartX+(CuaSoW/10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: +30000 cống hiến khi Chiếm Trụ"); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontNormal, StartX+(CuaSoW/10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: +10000 cống hiến khi Thắng Sự Kiện"); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontBold, StartX+(CuaSoW/10), StartY, 0x00FFCCFF, 0x0, CuaSoW, 0, 1, "Lưu ý: Guild Chiếm 2 trụ trở lên sẽ thắng."); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontBold, StartX+(CuaSoW/10), StartY, 0x00FF90FF, 0x0, CuaSoW, 0, 1, "Guild Chiến Thắng Sự Kiện Trước Sẽ Được Vào 'Lãnh Địa'"); //
	StartY = StartY+25;
	pDrawGUI(32583, StartX, StartY, 128.0f, 128.0f); //Huong Dan CTC

	//============Button
	StartY = StartY+10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX+(CuaSoW/2);
	//=====================Button 1
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  CGMoveCTCMini(1);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 1"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button 2
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(2);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 2"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button 3
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(3);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 3"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button 4
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(4);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 4"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button Lanh Dia
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && CheckVaoLanhDia)
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(5);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		  }
	} 
	else if (!CheckVaoLanhDia) {
		glColor3f(0.42f, 0.42f, 0.42f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Lãnh Địa"); //Buoc Vao
	//=====================================
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}

void Interface::DrawCTCMiNiMap() 
{	
	if(pPlayerState < GameProcess) 
	{
		return;
	}
	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		if(gObjUser.m_MapNumber != 98 ) 
		{
				return;
		}
		float MainWidth = 138.0;
		float MainHeight = 265.0;
		float StartY = 264.0;
		float StartX = 512.0; //512

		pDrawGUI(32584, StartX, StartY , 128.0f, 157.0f); //UI
		pDrawGUI(32583, StartX, StartY+28.0 , 128.0f, 128.0f); //MAP

		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
		{
			if (CTCMINI_TimeCTCMini > 0)
			{
				CTCMINI_TimeCTCMini = CTCMINI_TimeCTCMini - 1;
			}
			gInterface.Data[eTimeCTC].EventTick = GetTickCount();
		}

		int hours = CTCMINI_TimeCTCMini / 3600;
		int minutes = (CTCMINI_TimeCTCMini / 60) % 60;
		int seconds = CTCMINI_TimeCTCMini % 60;
		CustomFont.Draw(CustomFont.FontBold, StartX + 10, StartY + 10, 0x16FAC1FF, 0x0, 100, 0, 3, " %02d:%02d:%02d", hours, minutes, seconds); //
		//=================================

		//== Cong Vao 1
		if(CTCMINI_Cong[0] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 96 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
		}
		//== Cong Vao 2
		if(CTCMINI_Cong[1] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 128 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
		}
		//== Cong Vao 3
		if(CTCMINI_Cong[2] == 0) {
		RenderBitmap(31681, (float)(StartX - 2.5 + 161 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
		}

		//Tru Chua Cong 1 //31683 Thuoc Ve Guild
		if(CTCMINI_Tru[0] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		} else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		}
		//Tru Chua Cong 2
		if(CTCMINI_Tru[1] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		} else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		}
		//Tru Chua Cong 3
		if(CTCMINI_Tru[2] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		} else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		}

		//pDrawGUI(32585, 640/2-(210/2), 480/2-(94/2),210,94);

		int Model;

		for(int i=0;i < 400 ;i++)
		{
			Model = pGetPreviewStruct(pPreviewThis(), i);
			if(!Model) {
				continue;
			}
			if ( Model
				&& *(BYTE *)(Model + 780)
				&&  *(BYTE *)(Model + 800) == emPlayer
				)
			{
				if(Model != *(DWORD *)0x7BC4F04) 
				{
					this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
				} else {
					this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
				}
				
			}
		}
}

#if(BOSS_GUILD == 1)
void CGMoveBossGuild(int Type)
{
	if (Type > 0)
	{
		BOSSGUILD_CGPACKET pMsg;
		pMsg.header.set(0xF3, 0x40, sizeof(pMsg));
		pMsg.CongVao = Type - 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}
void Interface::DrawBossGuildWindow()
{

	if (!this->Data[eBossGuildWindow].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW = 250.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 95.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);
	
	//======Close
	int CloseX = StartX + CuaSoW - 40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	{
		if (GetTickCount() - ClickTickCount > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(1.0f, 0.0f, 0.0f);
				gInterface.Data[eBossGuildWindow].OnShow ^= 1;
				ClickTickCount = GetTickCount();
			}
		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "Boss Guild"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================

	if (gObjUser.CheDo1 == 1)
	{
		StartY = StartY + 35;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Tiêu diệt các Boss Phù Thủy, Chiến Binh, Tiên Nữ"); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xCC0033FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ đem lại %d điểm Guild chiến thắng", gObjUser.Score); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xB8E600FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ nhận được %d WCoinC khi Guild chiến thắng", gObjUser.WCoinC); //
		//---
		StartY = StartY + 23;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x6699FFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Phù Thủy sẽ nhận được %d WCoinC", gObjUser.PhuThuyWCoinC); //
		StartY = StartY + 20;																						
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0xFFFF66FF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Chiến Binh sẽ nhận được %d WCoinC", gObjUser.ChienBinhWCoinC); //
		StartY = StartY + 20;																					
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x99FFFFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Tiên Nữ sẽ nhận được %d WCoinC", gObjUser.TienNuWCoinC); //
	}

	if (gObjUser.CheDo2 == 1)
	{
		StartY = StartY + 35;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Tiêu diệt các Boss Thuật Sĩ, Thiết Binh, Đấu Sĩ, Chúa Tể"); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xCC0033FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ đem lại %d điểm Guild chiến thắng", gObjUser.Score); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xB8E600FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ nhận được %d WCoinC khi Guild chiến thắng", gObjUser.WCoinC); //
		//---
		StartY = StartY + 23;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x6699FFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Thuật Sĩ sẽ nhận được %d WCoinC", gObjUser.ThuatSiWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0xFFFF66FF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Thiết Binh sẽ nhận được %d WCoinC", gObjUser.ThietBinhWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x99FFFFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Đấu Sĩ sẽ nhận được %d WCoinC", gObjUser.DauSiWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0xFFCC33FF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Chúa Tể sẽ nhận được %d WCoinC", gObjUser.ChuaTeWCoinC); //
	}

	//============Button
	StartY = StartY + 10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX + (CuaSoW / 2);
	int StartX1 = 50;
	int StartY1 = 10;
	//=====================Button 1
	if (pCheckMouseOver(StartX - StartX1, StartY + StartY1 + 20, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(0.72f, 0.438f, 0.0432f);
				CGMoveBossGuild(1);
				this->Data[eBossGuildWindow].OnShow = 0;
				gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	RenderBitmap(31563, StartX - StartX1, StartY + StartY1 + 20, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX - StartX1, StartY + (SizeButtonH / 4) + StartY1 + 20, 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Tham gia"); //Buoc Vao
	//-------
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}
void Interface::DrawBossGuildMap()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0; //512

	if (pMapNumber == 83)
	{
		pDrawGUI(31650, 412.0f, 362.0f, 227.0f, 87.0f);
		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
		{
			if (BossGuild_TimeConLai > 0)
			{
				BossGuild_TimeConLai = BossGuild_TimeConLai - 1;
			}
			gInterface.Data[eTimeCTC].EventTick = GetTickCount();
		}

		int hours = BossGuild_TimeConLai / 3600;
		int minutes = (BossGuild_TimeConLai / 60) % 60;
		int seconds = BossGuild_TimeConLai % 60;

		CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 110, eWhite, 0x0, 100, 0, 3, " Boss Guild"); //
		CustomFont.Draw(CustomFont.FontBold, StartX + 23, StartY + 135, eYellow, 0x0, 100, 0, 3, " Thời gian còn lại"); //
		CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 150, eWhite, 0x0, 100, 0, 3, " %02d:%02d:%02d", hours, minutes, seconds); //
		//=================================

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);
	}
}
#endif

void Interface::DrawChienTruongCo() 
{
	if(!this->Data[eCuaSoCTC].OnShow) 
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW			=	230.0;
	float CuaSoH			=	200.0;

	float StartX			= (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY			= 95.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	//======Close
	int CloseX = StartX+CuaSoW-40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY , 36.0f, 29.0f);
	if ( pCheckMouseOver(CloseX, CloseY, 36, 36) == 1 )
	{
      if ( GetTickCount() - ClickTickCount > 300 )
      {
        if ( GetKeyState(1) & 0x8000 )
        {
          glColor3f(1.0f, 0.0f, 0.0f);
		  gInterface.Data[eCuaSoCTC].OnShow ^= 1;
          ClickTickCount = GetTickCount();
        }
      }
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX+15, CloseY+30, 0, 1, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY+5, 0xB8E600FF, 0x0, CuaSoW, 0, 3,"Chiến Trường Cổ"); //
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	StartX = StartX+(CuaSoW / 8);
	StartY = StartY+45;
	//====================================
	int hours			= CTC_TimeConLai/3600;
	int minutes			= (CTC_TimeConLai/60) % 60;  
	int seconds			= CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xE6FCF7FF, 0x0, CuaSoW, 0, 1, "Thời gian còn lại:"); //
	CustomFont.Draw(CustomFont.FontBold, StartX+70, StartY, 0x16FAC1FF, 0x0, CuaSoW, 0, 1, "%02d:%02d:%02d", hours, minutes, seconds); //
	//===================================
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Tiêu diệt 1 quái vật nhận %d điểm WCoinC",CTC_PointKillQuai); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cùng Party nhận %d điểm WCoinC", CTC_PartyKillPoint); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- TIêu diệt %d sẽ rớt Item ngẫu nhiên",CTC_MonterYeuCau); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0x26FFD0FF, 0x0, CuaSoW, 0, 1, "- Có khả năng rớt Lông Vũ, HHHT"); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY, 0xFF7226FF, 0x0, CuaSoW, 0, 1, "Lưu Ý : Khu vực PK Tự Do, hãy cẩn thận"); //


	//============Button
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX-10;
	//=====================Button 1
	if ( pCheckMouseOver(StartX, StartY+40, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  XULY_CGPACKET pMsg;
			  pMsg.header.set(0xF3, 0x38, sizeof(pMsg));	
			  pMsg.ThaoTac = 1;
			  DataSend((LPBYTE)&pMsg, pMsg.header.size);
			  this->Data[eCuaSoCTC].OnShow  = 0;
			  gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY+40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY+40 + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Bước Vào"); //Buoc Vao

	//=====================================
	//=====================Button 2
	if ( pCheckMouseOver(StartX+SizeButtonW+5, StartY+40, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
			  glColor3f(0.72f, 0.438f, 0.0432f);

			  XULY_CGPACKET pMsg;
			  pMsg.header.set(0xF3, 0x38, sizeof(pMsg));	
			  pMsg.ThaoTac = 2;
			  DataSend((LPBYTE)&pMsg, pMsg.header.size);
			  //pDrawMessage ( "Button 2", 0 );		  
			  gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX+SizeButtonW+5, StartY+40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX+SizeButtonW+5, StartY+40 + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3,"Thêm Thời Gian"); //
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
	
}
void Interface::DrawTimeCTC() 
{

	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if(pMapNumber != 103) 
	{
		return;
	}
	float CuaSoW			=	130.0;
	float CuaSoH			=	81.0;

	float StartX			= 516.0;
	float StartY			= 348.0;
	//RenderBitmap(31566, StartX, StartY, CuaSoW, CuaSoH, 0.0, 0.0, 1.0, 1.0, 1, 1, 0);
	pDrawGUI(31650, 412.0f, 342.0f, 227.0f, 87.0f);
	int PhanTramKill;
	if(CTC_MonterYeuCau > 0) {
		PhanTramKill = (CTC_QuaiVatDaKill * 100) / CTC_MonterYeuCau;
		if(PhanTramKill > 100) { PhanTramKill = 100;}
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY+5, 0xFF7226FF, 0x0, CuaSoW, 0, 3, "Kill: %d/%d",CTC_QuaiVatDaKill,CTC_MonterYeuCau); //
	}
	//================ Tinh Toan Time
	if((GetTickCount()-gInterface.Data[eTimeCTC].EventTick) > 1000)
		{
			if (CTC_TimeConLai > 0)
			{
				CTC_TimeConLai = CTC_TimeConLai-1;
			}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours			= CTC_TimeConLai/3600;
	int minutes			= (CTC_TimeConLai/60) % 60;  
	int seconds			= CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY+35, 0x16FAC1FF, 0x0, CuaSoW, 0, 3, "Time : %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================
	float TyLeTGA = (166.0 * PhanTramKill) / 100;
	if(TyLeTGA > 166.0) { TyLeTGA = 166.0;}
	pDrawGUI(31653, 471.5f, 421.0f, TyLeTGA, 7.0f);



}	
//======================================================================================================================

DWORD	SetInvisibleEffect_PointerYYYYY;
DWORD	SetInvisibleEffect_BuffYYYYY;
DWORD	SetInvisibleEffect_PointerYYYY;
DWORD	SetInvisibleEffect_BuffYYYY;

__declspec(naked) void ItemInvisible11(){
	static DWORD m_aaaaab = 0x0060B37A;
	_asm{
		mov SetInvisibleEffect_BuffYYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerYYYYY, esi
			mov esi, SetInvisibleEffect_BuffYYYYY
	}
	if (SetInvisibleEffect_PointerYYYYY != 0x1EA5
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 15)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 30)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 136)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 137)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 138)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 139)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 140)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 141)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 142)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 143)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 14)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 16)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 42)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 41)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 43)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 44))
	{
		_asm{
			jmp[m_aaaaab]
		}
	}
}
__declspec(naked) void ItemInvisible22(){
	static DWORD m_aaaaaa = 0x0060B41D;
	_asm{
		mov SetInvisibleEffect_BuffYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			jmp[m_aaaaaa]
	}
}
DWORD	SetInvisibleEffect_PointerXXX;
DWORD	SetInvisibleEffect_BuffXXX;

Naked(InvisibleEffectXX){
	_asm{
		mov SetInvisibleEffect_BuffXXX, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerXXX, esi
			mov esi, SetInvisibleEffect_BuffXXX
	}
	if (SetInvisibleEffect_PointerXXX == 0x1EA5 || SetInvisibleEffect_PointerXXX == ITEM2(13, 18)){
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B37A
				jmp SetInvisibleEffect_BuffXXX
		}
	}
	else{
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B41D
				jmp SetInvisibleEffect_BuffXXX
		}
	}
}

void InvisibleItem11(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible11);
}
void InvisibleItem22(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible22);
}
void InvisibleItemXX(){
	SetRange((LPVOID)0x0060B36A, 10, ASM::NOP); //12
	SetCompleteHook(0xE9, 0x0060B36A, &InvisibleEffectXX);
}


void Interface::SwitchAntiLag1()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag1 != 0)
		{
			gInterface.DrawMessage(1, "AntiLag 1 [OFF]");

			AntiLag1 = 0;
			InvisibleItem22();
			InvisibleItemXX();
			SetByte((0x0074CD80 + 2), (this->AntiLag1 == 0) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag1 == 0) ? 1 : 0); // DisableStaticEffect
			DisableGlowEffect == this->AntiLag1 == 1;
			DisableShadow = this->AntiLag1 == 1;

			SetCompleteHook(0xE8, 0x00588661, 0x005655C0); // Dis Wings
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
			SetByte(0x0051EE20, 0x55); //Enable Cloaks

			WritePrivateProfileStringA("Setting", "AntiLag1", "0", "./Settings.ini");
		}
		else
		{
			gInterface.DrawMessage(1, "AntiLag 1 [ON]");

			InvisibleItem11();
			SetByte((0x0074CD80 + 2), (this->AntiLag1 == 1) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag1 == 1) ? 1 : 0); // DisableStaticEffect

			DisableGlowEffect == this->AntiLag1 == 0;
			DisableShadow = this->AntiLag1 == 0;

			MemorySet(0x00588661, 0x90, 0x05); // On Wing
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks

			AntiLag1 = 1;
			WritePrivateProfileStringA("Setting", "AntiLag1", "1", "./Settings.ini");
		}
	}
}

void Interface::SwitchAntiLag2()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag2 != 0)
		{
			gInterface.DrawMessage(1, "AntiLag 2 [OFF]");

			AntiLag2 = 0;
			InvisibleItem22();
			InvisibleItemXX();
			SetByte(0x005DE2B3 + 1, (this->AntiLag2 == 0) ? 0x85 : 0x84); // Ocultamos objetos del mapa
			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 0) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 0) ? 1 : 0); // DisableStaticEffect
			DisableGlowEffect == this->AntiLag2 == 1;
			DisableShadow = this->AntiLag2 == 1;
			SetCompleteHook(0xE8, 0x00588661, 0x005655C0); // Dis Wings
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
			SetByte(0x0051EE20, 0x55); //Enable Cloaks
		}
		else
		{
			gInterface.DrawMessage(1, "AntiLag 2 [ON]");

			InvisibleItem11();
			SetByte(0x005DE2B3 + 1, (this->AntiLag2 == 1) ? 0x85 : 0x84); // Ocultamos objetos del mapa
			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 1) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 1) ? 1 : 0); // DisableStaticEffect

			DisableGlowEffect == this->AntiLag2 == 0;
			DisableShadow = this->AntiLag2 == 0;

			MemorySet(0x00588661, 0x90, 0x05); // On Wing
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks

			AntiLag2 = 1;
		}
	}
}

void Interface::SwitchHidePlayer()
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLagPlayer != 0)
		{
			gInterface.DrawMessage(1, "Ẩn nhân vật [OFF]");

			AntiLagPlayer = 0;
			DisablePlayer = this->AntiLagPlayer == 1;
		}
		else
		{
			gInterface.DrawMessage(1, "Ẩn nhân vật [ON]");

			DisablePlayer = this->AntiLagPlayer == 0;

			AntiLagPlayer = 1;
		}
	}
}


float VitriX = 150.0;
float VitriY = 380.0;
bool QuayLai = false;
int res = 204;
int begin_time = 0;
void Interface::DrawTextRun()
{
	if (gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)) //-- 76
	{
		return;
	}

	if (!QuayLai && VitriX < 500)
	{

		VitriX++;
	}
	else
	{
		VitriX = 70.0;
		res++;
	}
	if (res > 209)
	{
		res = 204;
	}
	CustomFont.Draw(CustomFont.FontSize18, VitriX, VitriY, 0xB8E600FF, 0x0, ePLAYER_POINT, 0, 1000, gOther.TextVN[res]); //#00ffff	
}


// Leo thap
#if(LEOTHAP == 1)
void Interface::DrawLeoThap()
{
	if (!this->Data[eLEOTHAP_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eLEOTHAP_MAIN, StartX - 170, StartY - 50);
	this->DrawGUI(eLEOTHAP_TITLE, StartX - 170, StartY - 50);
	StartY = this->DrawRepeatGUI(eLEOTHAP_FRAME, StartX - 170, StartY + 17.0, 13);
	this->DrawGUI(eLEOTHAP_FOOTER, StartX - 170, StartY);
	this->DrawGUI(eLEOTHAP_CLOSE, StartX + MainWidth - this->Data[eLEOTHAP_CLOSE].Width - 170, this->Data[eLEOTHAP_TITLE].Height + this->Data[eLEOTHAP_CLOSE].Height - 47);
	// ----
	if (IsWorkZone(eLEOTHAP_BUTTON_GATE1))
	{
		if (this->Data[eLEOTHAP_BUTTON_GATE1].OnClick)
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 28, 0, 30);
		}
		else
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 28, 0, 29);
		}
	}
	else
	{
		this->DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 28, 0, 0);
	}

	if (IsWorkZone(eLEOTHAP_BUTTON_GATE2))
	{
		if (this->Data[eLEOTHAP_BUTTON_GATE2].OnClick)
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 63, 0, 30);
		}
		else
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 63, 0, 29);
		}
	}
	else
	{
		this->DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 63, 0, 0);
	}

	if (IsWorkZone(eLEOTHAP_BUTTON_GATE3))
	{
		if (this->Data[eLEOTHAP_BUTTON_GATE3].OnClick)
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 98, 0, 30);
		}
		else
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 98, 0, 29);
		}
	}
	else
	{
		this->DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 98, 0, 0);
	}

	if (IsWorkZone(eLEOTHAP_BUTTON_GATE4))
	{
		if (this->Data[eLEOTHAP_BUTTON_GATE4].OnClick)
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 133, 0, 30);
		}
		else
		{
			this->DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 133, 0, 29);
		}
	}
	else
	{
		this->DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 133, 0, 0);
	}

	if (this->IsWorkZone(eLEOTHAP_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eLEOTHAP_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eLEOTHAP_CLOSE, this->Data[eLEOTHAP_CLOSE].X, this->Data[eLEOTHAP_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eLEOTHAP_CLOSE].X + 5, this->Data[eLEOTHAP_CLOSE].Y + 25, "Đóng");
	}
	// ----
	//this->DrawFormat(eGold, StartX - 160, 60, 210, 3, "Khiêu Chiến Boss");
	CustomFont.Draw(CustomFont.FontBold, 125, 60, 0xFFFF00FF, 0x0, 0, 0, 0, "VƯỢT THÁP");
	// ----
	this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 42); //
	this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 43, 200, 1, "Cổng vào số 1");
	//this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 43, "1.000.000 Zen");
	pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 60, 82.0, 2.0); // gạch ngang
	pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 60, 82.0, 2.0); // gạch ngang
	// ----
	this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 82 - 5); //
	this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 83 - 5, 200, 1, "Cổng vào số 2");
	//this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 83-5, "1.000.000 Zen");
	pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 100 - 5, 82.0, 2.0); // gạch ngang
	pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 100 - 5, 82.0, 2.0); // gạch ngang
	// ----
	this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 122 - 10); //
	this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 123 - 10, 200, 1, "Cổng vào số 3");
	//this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 123-10, "1.000.000 Zen");
	pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 140 - 10, 82.0, 2.0); // gạch ngang
	pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 140 - 10, 82.0, 2.0); // gạch ngang
	// ----
	this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 162 - 15); //
	this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 163 - 15, 200, 1, "Cổng vào số 4");
	//this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 163-15, "1.000.000 Zen");
	pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 180 - 15, 82.0, 2.0); // gạch ngang
	pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 180 - 15, 82.0, 2.0); // gạch ngang
	// ----
	this->DrawFormat(eWhite, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 233 - 10, 200, 1, "Sau khi lựa chọn cổng vào phù hợp,hãy di chuyển và chuẩn bị tiêu diệt Boss");
	this->DrawFormat(eExcellent, StartX - 125, this->Data[eLEOTHAP_MAIN].Y + 248 - 10, 200, 1, "-Cẩn thận với những người chơi khác");
	this->DrawFormat(eExcellent, StartX - 125, this->Data[eLEOTHAP_MAIN].Y + 248 + 5, 200, 1, "-Khi Event diễn ra, lối vào sẽ đóng lại");
	CustomFont.Draw(CustomFont.FontBold, 55, 288, 0xFF0000FF, 0x0, 0, 0, 0, "Lưu ý: ");

	pSetCursorFocus = true;
}
bool Interface::EventLeoThap_Main(DWORD Event)
{
	this->EventLeoThap_All(Event);
	this->EventLeoThap_Close(Event);
	return true;
}
bool Interface::EventLeoThap_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if (!this->Data[eLEOTHAP_MAIN].OnShow)
	{
		return false;
	}

	int ObjectIDs[4] =
	{
		eLEOTHAP_BUTTON_GATE1,
		eLEOTHAP_BUTTON_GATE2,
		eLEOTHAP_BUTTON_GATE3,
		eLEOTHAP_BUTTON_GATE4,
	};
	gLeoThap.ResetData();
	for (int i = 0; i < 4; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();;
			this->Data[eLEOTHAP_MAIN].Close();
			PMSG_LEOTHAP_SEND pRequest;
			pRequest.Number = i;
			pRequest.header.set(0xFF, 0x10, sizeof(pRequest));
			DataSend((BYTE*)&pRequest, pRequest.header.size);
			//SetByte(0x005528A0, 0xC3);
		}
	}
	return false;
}
bool Interface::EventLeoThap_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eLEOTHAP_CLOSE].EventTick);
	// ----
	if (!this->Data[eLEOTHAP_MAIN].OnShow || !IsWorkZone(eLEOTHAP_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eLEOTHAP_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eLEOTHAP_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eLEOTHAP_CLOSE].EventTick = GetTickCount();

	this->Data[eLEOTHAP_MAIN].Close();
	// ----
	return false;
}
#endif

//Thêm vào cuối hoặc đâu thích hợp
#if(DEV_PLAYERSHOP)
void Interface::DrawColorGUI(int MainID, int X, int Y, int Width, int Height, DWORD Color)
{
	pDrawColorButton(MainID, X, Y, Width, Height, 0, 0, Color);
}

void Interface::DrawButtonBig(int ObjID, bool bActive, float fX, float fY, char* Text)
{
	gInterface.DrawGUI(ObjID, fX, fY);
	gInterface.DrawFormat(eWhite, fX + 4, fY + 10, 100, 3, Text);
	if (bActive)
	{
		gInterface.Data[ObjID].Attribute = true;
		if (gInterface.IsWorkZone(ObjID))
		{
			DWORD Color = eGray100;
			if (gInterface.Data[ObjID].OnClick)
			{
				Color = eGray150;
			}
			gInterface.DrawColoredGUI(ObjID, gInterface.Data[ObjID].X, gInterface.Data[ObjID].Y, Color);
		}
	}
	else
	{
		gInterface.Data[ObjID].Attribute = false;
		gInterface.DrawColoredGUI(ObjID, gInterface.Data[ObjID].X, gInterface.Data[ObjID].Y, eGray150);
	}
}

void Interface::DrawButtonMini(int id, int X, int Y, int res, char* Text)
{
	int StartX = X;
	int StartY = Y;

	gInterface.DrawGUI(id, StartX, StartY);
	gInterface.DrawFormat(eWhite, StartX + 5, StartY + 10, 50, 3, Text);

	if (!res)
	{
		gInterface.Data[id].Attribute = false;
		gInterface.DrawColoredGUI(id, gInterface.Data[id].X, gInterface.Data[id].Y, eGray150);
	}
	else
	{
		gInterface.Data[id].Attribute = true;
		if (gInterface.IsWorkZone(id))
		{
			DWORD Color = eGray100;
			// ----
			if (gInterface.Data[id].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(id, gInterface.Data[id].X, gInterface.Data[id].Y, Color);
		}
	}
}

void Interface::DrawCheckLineEx(bool Switch, int Point, int Check, int Line, float X, float Y, int Color, char* Text)
{
	gInterface.DrawGUI(Point, X + 20, Y);	//233
	gInterface.DrawFormat(Color, X + 40, Y + 2, 150, 1, Text);
	if (Switch == true)
	{
		gInterface.DrawGUIY(Check, X + 190, Y - 2, 0);
	}
	else
	{
		gInterface.DrawGUIY(Check, X + 190, Y - 2, 1);
	}
	if (Line)
	{
		gInterface.DrawGUI(Line, X + 35, Y + 12);
	}
}

void Interface::PartUPandDNEx(int Point, int PageUp, int PageDn, int Line, float X, float Y, int Color, int Number, char* Text)
{
	// --
	gInterface.DrawGUI(Point, X + 20, Y);	//293
	gInterface.DrawFormat(Color, X + 40, Y + 2, 150, 1, Text);

	int iPlusX = 15;

	if (gInterface.Data[PageDn].OnClick)
	{
		gInterface.DrawGUIY(PageDn, X + 130 + iPlusX, Y - 2, 1);
	}
	else
	{
		gInterface.DrawGUIY(PageDn, X + 130 + iPlusX, Y - 2, 0);
	}

	pDrawColorButton(0x7880, X + 150 + iPlusX, Y, 20, 13, 0, 0, Color4f(0, 0, 0, 255));

	gInterface.DrawFormat(eWhite, X + 125 + iPlusX, Y + 2, 70, 3, "%d", Number);

	if (gInterface.Data[PageUp].OnClick)
	{
		gInterface.DrawGUIY(PageUp, X + 175 + iPlusX, Y - 2, 1);
	}
	else
	{
		gInterface.DrawGUIY(PageUp, X + 175 + iPlusX, Y - 2, 0);
	}

	gInterface.DrawGUI(Line, X + 35, Y + 12);
	// --
}

bool Interface::ButtonExR(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_RBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_RBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawItem1(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::DrawItemToolTipText(void * item, int x, int y)
{
	static DWORD mem = 0;
	_asm
	{
		PUSH 0
			PUSH 0
			PUSH 0
			PUSH item
			PUSH y
			PUSH x
			MOV mem, 0x00861110
			CALL mem
			MOV ECX, EAX
			MOV mem, 0x00861AA0
			CALL mem
			MOV ECX, EAX
			MOV mem, 0x007E3E30
			CALL mem
	}
}

void Interface::KeyBoxEvent(DWORD Event, char* kText, int MaxText)
{
	int Len = strlen(kText);

	if (kText[0] == '0')
	{
		kText[0] = 0;
	}

	switch (Event)
	{
	case VK_0:
	case VK_NUMPAD0:
	{
					   if (Len < MaxText)
					   {
						   strcat(kText, "0");
					   }
	}
		break;
	case VK_1:
	case VK_NUMPAD1:
	{
					   if (Len < MaxText)
						   strcat(kText, "1");
	}
		break;
	case VK_2:
	case VK_NUMPAD2:
	{
					   if (Len < MaxText)
						   strcat(kText, "2");
	}
		break;
	case VK_3:
	case VK_NUMPAD3:
	{
					   if (Len < MaxText)
						   strcat(kText, "3");
	}
		break;
	case VK_4:
	case VK_NUMPAD4:
	{
					   if (Len < MaxText)
						   strcat(kText, "4");
	}
		break;
	case VK_5:
	case VK_NUMPAD5:
	{
					   if (Len < MaxText)
						   strcat(kText, "5");
	}
		break;
	case VK_6:
	case VK_NUMPAD6:
	{
					   if (Len < MaxText)
						   strcat(kText, "6");
	}
		break;
	case VK_7:
	case VK_NUMPAD7:
	{
					   strcat(kText, "7");
	}
		break;
	case VK_8:
	case VK_NUMPAD8:
	{
					   if (Len < MaxText)
						   strcat(kText, "8");
	}
		break;
	case VK_9:
	case VK_NUMPAD9:
	{
					   if (Len < MaxText)
						   strcat(kText, "9");
	}
		break;
	case VK_BACK:
	{
					if (Len >  0)
						kText[Len - 1] = 0;
	}
		break;
	}

	if (kText[0] == 0)
	{
		strcpy(kText, "0");
	}
}

void Interface::OpenWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return;
	}

	this->WindowEx[WindowID] = 1;

	pSetCursorFocus = true;
}
// ----------------------------------------------------------------------------------------------

void Interface::CloseWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return;
	}

    this->WindowEx[WindowID] = 0;
}

#if (ARCHIVEMENT == 1)
void Interface::TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...)
{
	char TextBuff[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(TextBuff, Format, va);
	va_end(va);

	int v13; // ST1C_4@1
	int v15; // ST20_4@1
	pSetFont(pTextThis(), (int)Font);
	v13 = sub_41FFE0_Addr(pTextThis());
	v15 = sub_420010_Addr(pTextThis());
	SetTextColorByHDC(pTextThis(), Color);
	sub_4200F0_Addr(pTextThis(), Arg7);
	pSetBkColor(pTextThis(), 255, 255, 255, 0);
	pDrawText(pTextThis(), PosX, PosY, TextBuff, Width, Arg5, (int*)Align, 0);
	SetTextColorByHDC(pTextThis(), v13);
	sub_4200F0_Addr(pTextThis(), v15);
}
#endif
// ----------------------------------------------------------------------------------------------
void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}
void Interface::DrawGUIY(short ObjectID, float PosX, float PosY, int Type)
{
	//if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----

	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0.0, (Type * this->Data[ObjectID].Height));
	/*
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
	this->Data[ObjectID].Width, this->Data[ObjectID].Height);*/
}

#endif
