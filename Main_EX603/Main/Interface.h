#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"
#include "CustomOfflineMode.h"

#define MAX_OBJECT 	1000 // 350
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define MAX_WINDOW_EX 100
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)

#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))

#if(DEV_PLAYERSHOP == 1)
#define VK_0 	0x30 //	0 key
#define VK_1 	0x31 //	1 key
#define VK_2 	0x32 //	2 key
#define VK_3 	0x33 // 3 key
#define VK_4 	0x34 //	4 key
#define VK_5 	0x35 //	5 key
#define VK_6 	0x36 //	6 key
#define VK_7 	0x37 //	7 key
#define VK_8 	0x38 //	8 key
#define VK_9 	0x39 //	9 key 
#endif

enum ObjectID
{

#if(DEV_PLAYERSHOP)
	eMARKET_MAIN,
	eMARKET_TITLE,
	eMARKET_FRAME,
	eMARKET_FOOTER,
	eMARKET_DIV,
	eMARKET_OK,
	eMARKET_CLOSE,
	eMARKET_INFOBG,
	eMARKET_INFOBG2,
	eMARKET_INFOBG3,
	eMARKET_SCROLL,
	eMARKET_BUY,

	eMARKET_PRICE_MAIN,
	eMARKET_PRICE_TITLE,
	eMARKET_PRICE_FRAME,
	eMARKET_PRICE_FOOTER,
	eMARKET_PRICE_OK,
	eMARKET_PRICE_CLOSE,
	eMARKET_PRICE_INFOBG,
	eMARKET_PRICE_CHECK1,
	eMARKET_PRICE_CHECK2,
	eMARKET_PRICE_CHECK3,
	eMARKET_PRICE_POINT,
	eMARKET_PRICE_LINE,

	eMARKET_FILTER_MAIN,
	eMARKET_FILTER_TITLE,
	eMARKET_FILTER_FRAME,
	eMARKET_FILTER_FOOTER,
	eMARKET_FILTER_POINT,
	eMARKET_FILTER_PAGEUP,
	eMARKET_FILTER_PAGEDN,
	eMARKET_FILTER_LINE,
	eMARKET_FILTER_CHECK1,
	eMARKET_FILTER_CHECK2,
	eMARKET_FILTER_CHECK3,
	eMARKET_FILTER_CHECK4,
	eMARKET_FILTER_CHECK5,
	eMARKET_FILTER_CHECK6,
	eMARKET_FILTER_NAME,
	eMARKET_FILTER_CAATEGORY,
	eMARKET_FILTER_DIV,

	eMARKET_ITEM_MAIN,
	eMARKET_ITEM_TITLE,
	eMARKET_ITEM_FRAME,
	eMARKET_ITEM_FOOTER,
	eMARKET_ITEM_BG,
	eMARKET_ITEM_OK,
	eMARKET_ITEM_CLOSE,

	eMARKET_L,
	eMARKET_R,

	ex_TEXT_BOX3,
#endif

#if(RANKING_NEW == 1)
	eMAIN_RANKING,
	eRANKINGALL,
	eRANKINGDW,
	eRANKINGDK,
	eRANKINGEF,
	eRANKINGMG,
	eRANKINGDL,
	eRANKINGSM,
	eRANKINGRF,
	eRANKINGTOPNAP,
	eRANKINGBLOOD,
	eRANKINGDEVIL,
	eRANKINGCHAOS,
#endif

	eTIME,
	eRankPANEL_MAIN,
	//eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,

#if(RANKINGGOC == 1)
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
#endif

	eLogo,

	eTVTHUD,

	eEventTimePANEL_MAIN,
	eSHOWTIME_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,

#if(DANH_HIEU_NEW)
	EXBEXO_DANH_HIEU_MAIN,
	EXBEXO_DANH_HIEU_CLOSE,
	EXBEXO_DANH_HIEU_NANG_CAP,

	eDANH_HIEU1,
	eDANH_HIEU2,
#endif

#if(TU_LUYEN_NEW)
	EXBEXO_TU_LUYEN_MAIN,
	EXBEXO_TU_LUYEN_CLOSE,
	EXBEXO_TU_LUYEN_NANG_CAP,

	eTU_LUYEN1,
	eTU_LUYEN2,
#endif

#if(BOSS_GUILD == 1)
	eBossGuildWindow,
#endif
	////////////////////////
	eCTCMiniWindow,
	eOTHERCHAR_POINT,
	eCHAR_POINT,
	/////////////////////
	eTimeCTC,
	eCuaSoCTC,
	////////////////////
	eMenu,
	eMenuBG,
	eRock,
	ePaper,
	eScissors,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	eCommandWindow,
	//--custom money
	eMoney1,
	eMoney2,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,

	//OBJECT_RESET_MAIN,
	//OBJECT_RESET_TITLE,
	//OBJECT_RESET_FRAME,
	//OBJECT_RESET_FOOTER,
	//OBJECT_RESET_DIV,
	//OBJECT_RESET_INFO_BG,
	//OBJECT_RESET_MONEY_BG,
	//OBJECT_RESET_CLOSE,
	//OBJECT_RESET_FINISH,
	//OBJECT_GRESET_MAIN,
	//OBJECT_GRESET_TITLE,
	//OBJECT_GRESET_FRAME,
	//OBJECT_GRESET_FOOTER,
	//OBJECT_GRESET_DIV,
	//OBJECT_GRESET_INFO_BG,
	//OBJECT_GRESET_MONEY_BG,
	//OBJECT_GRESET_CLOSE,
	//OBJECT_GRESET_FINISH,
	// ---
#if(NHIEMVU_NEW == 1)
	OBJECT_WIN_QUEST_MAIN,
	OBJECT_WIN_QUEST_TITLE,
	OBJECT_WIN_QUEST_FRAME,
	OBJECT_WIN_QUEST_FOOTER,
	OBJECT_WIN_QUEST_DIV,
	OBJECT_WIN_QUEST_CLOSE,
	OBJECT_WIN_QUEST_TAB,
	OBJECT_WIN_QUEST_TAB1,
	OBJECT_WIN_QUEST_TAB2,
	OBJECT_WIN_QUEST_TAB3,
	OBJECT_WIN_QUEST_FINISH,
	OBJECT_WIN_QUEST_COUNT1,
	OBJECT_WIN_QUEST_COUNT2,
	OBJECT_WIN_QUEST_COUNT3,
	OBJECT_WIN_QUEST_INFOBG,
	OBJECT_WIN_QUEST_INFOBG2,
	OBJECT_WIN_QUEST_LINE1,
	OBJECT_WIN_QUEST_POINT1,
	OBJECT_WIN_QUEST_INFO,
	OBJECT_WIN_QUEST_INFOBG3,
	OPEN_QUEST,
#endif

#if (ARCHIVEMENT == 1)
	OBJECT_ACHIEVEMENTS_MAIN,
	OBJECT_ACHIEVEMENTS_PROGRESS_BG,
	OBJECT_ACHIEVEMENTS_PANEL,
	OBJECT_ACHIEVEMENTS_CLOSE,
	OBJECT_ACHIEVEMENTS_MISSIONS,
	OBJECT_ACHIEVEMENTS_DAMAGE,
	OBJECT_ACHIEVEMENTS_DEFENSE,
	OBJECT_ACHIEVEMENTS_LIFE,
	OBJECT_ACHIEVEMENTS_EXCELLENT,
	OBJECT_ACHIEVEMENTS_CRITICAL,
#endif

	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,

	OBJECT_PARTYSETTINGS_MAIN,
	OBJECT_PARTYSETTINGS_TITLE,
	OBJECT_PARTYSETTINGS_FRAME,
	OBJECT_PARTYSETTINGS_FOOTER,
	OBJECT_PARTYSETTINGS_DIV,
	OBJECT_PARTYSETTINGS_CLOSE,
	OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE,
	OBJECT_PARTYSETTINGS_ONLY_GUILD,
	OBJECT_PARTYSETTINGS_ONLY_ALLIANCE,
	OBJECT_PARTYSETTINGS_ONE_CLASS,
	OBJECT_PARTYSETTINGS_DARK_WIZARD,
	OBJECT_PARTYSETTINGS_DARK_KNIGHT,
	OBJECT_PARTYSETTINGS_ELF,
	OBJECT_PARTYSETTINGS_MAGIC_GLADIATOR,
	OBJECT_PARTYSETTINGS_DARK_LORD,
	OBJECT_PARTYSETTINGS_SUMMONER,
	OBJECT_PARTYSETTINGS_RAGE_FIGHTER,
	OBJECT_PARTYSETTINGS_LEVEL_MINUS,
	OBJECT_PARTYSETTINGS_LEVEL_PLUS,
	OBJECT_PARTYSETTINGS_PASSWORD,
	OBJECT_PARTYSETTINGS_OK,
	OBJECT_PARTYSEARCH_LEFT,
	OBJECT_PARTYSEARCH_RIGHT,
	OBJECT_PARTYSEARCH_IMAGE1,
	OBJECT_PARTYSEARCH_IMAGE2,

	OBJECT_PARTYSEARCH_MAIN,
	OBJECT_PARTYSEARCH_TITLE,
	OBJECT_PARTYSEARCH_FRAME,
	OBJECT_PARTYSEARCH_FOOTER,
	OBJECT_PARTYSEARCH_DIV,
	OBJECT_PARTYSEARCH_CLOSE,

	OBJECT_PARTYPASSWORD_MAIN,
	OBJECT_PARTYPASSWORD_TITLE,
	OBJECT_PARTYPASSWORD_FRAME,
	OBJECT_PARTYPASSWORD_FOOTER,
	OBJECT_PARTYPASSWORD_CLOSE,
	OBJECT_PARTYPASSWORD_TEXTBOX,
	OBJECT_PARTYPASSWORD_OK,

	eWAREHOUSE,
	eWAREHOUSE1,
	eWAREHOUSE_MAIN,
	eWAREHOUSE_TITLE,
	eWAREHOUSE_FRAME,
	eWAREHOUSE_FOOTER,
	eWAREHOUSE_DIV,
	eWAREHOUSE_CLOSE,
	eWAREHOUSE_NUM1,
	eWAREHOUSE_NUM2,
	eWAREHOUSE_NUM3,
	eWAREHOUSE_NUM4,
	eWAREHOUSE_NUM5,
	eWAREHOUSE_NUM6,
	eWAREHOUSE_NUM7,
	eWAREHOUSE_NUM8,

	//eMAX_VALUE,

	//---------------------------------------------------------------------
#if(MENU_NEW)
	EXBEXO_MENU_MAIN,
	EXBEXO_MENU_CLOSE,
	eBUTTON_MENU_1,
	eBUTTON_MENU_2,
	eBUTTON_MENU_3,
	eBUTTON_MENU_4,
	eBUTTON_MENU_5,
	eBUTTON_MENU_6,
	eBUTTON_MENU_7,
	eBUTTON_MENU_8,
	eBUTTON_MENU_9,
	eBUTTON_MENU_10,
	eBUTTON_MENU_11,
	eBUTTON_MENU_12,
	eBUTTON_MENU_13,
	eBUTTON_MENU_14,
	eBUTTON_MENU_15,
#endif

#if(VONGQUAY_NEW)
	eLuckySpin,
	eLuckySpinRoll,
	eLuckySpinClose,
#endif


#if(NGANHANGNGOC_NEW)
	eJEWELBANK_MAIN,
	eJEWELBANK_TITLE,
	eJEWELBANK_FRAME,
	eJEWELBANK_FOOTER,
	eJEWELBANK_POINT,
	eJEWELBANK_LINE,
	eJEWELBANK_DIV,
	eJEWELBANK_CLOSE,

	eJEWELBANK_ZEN_MINUS,
	eJEWELBANK_ZEN_PLUS,

	eJEWELBANK_CHAOS_MINUS,
	eJEWELBANK_CHAOS_MINUS10,
	eJEWELBANK_CHAOS_MINUS20,
	eJEWELBANK_CHAOS_MINUS30,

	eJEWELBANK_BLESS_MINUS,
	eJEWELBANK_BLESS_MINUS10,
	eJEWELBANK_BLESS_MINUS20,
	eJEWELBANK_BLESS_MINUS30,

	eJEWELBANK_SOUL_MINUS,
	eJEWELBANK_SOUL_MINUS10,
	eJEWELBANK_SOUL_MINUS20,
	eJEWELBANK_SOUL_MINUS30,

	eJEWELBANK_LIFE_MINUS,
	eJEWELBANK_LIFE_MINUS10,
	eJEWELBANK_LIFE_MINUS20,
	eJEWELBANK_LIFE_MINUS30,

	eJEWELBANK_CRE_MINUS,
	eJEWELBANK_CRE_MINUS10,
	eJEWELBANK_CRE_MINUS20,
	eJEWELBANK_CRE_MINUS30,

	eJEWELBANK_GEM_MINUS,
	eJEWELBANK_GEM_MINUS10,
	eJEWELBANK_GEM_MINUS20,
	eJEWELBANK_GEM_MINUS30,

	eJEWELBANK_GEM1_MINUS,
	eJEWELBANK_GEM1_MINUS10,
	eJEWELBANK_GEM1_MINUS20,
	eJEWELBANK_GEM1_MINUS30,

	eJEWELBANK_GEM2_MINUS,
	eJEWELBANK_GEM2_MINUS10,
	eJEWELBANK_GEM2_MINUS20,
	eJEWELBANK_GEM2_MINUS30,

	eJEWELBANK_GEM3_MINUS,
	eJEWELBANK_GEM3_MINUS10,
	eJEWELBANK_GEM3_MINUS20,
	eJEWELBANK_GEM3_MINUS30,

	eJEWELBANK_GEM4_MINUS,
	eJEWELBANK_GEM4_MINUS10,
	eJEWELBANK_GEM4_MINUS20,
	eJEWELBANK_GEM4_MINUS30,
#endif


// Thuong Gia
	EXBEXO_THUONG_GIA_MAIN,
	EXBEXO_THUONG_GIA_CLOSE,
	eTHUONG_GIA1,
	eTHUONG_GIA2,
	eTHUONG_GIA3,
	eTHUONGGIA_01,
	eTHUONGGIA_02,
	eTHUONGGIA_03,
	
#if(VIP_TAI_KHOAN_NEW == 1)
	EXBEXO_VIPTAIKHOAN_MAIN,
	EXBEXO_VIPTAIKHOAN_CLOSE,
	eVIPTAIKHOAN_SEND_01,
	eVIPTAIKHOAN_SEND_03,
	eVIPTAIKHOAN_SEND_07,
#endif

#if(THUE_VIP_NEW == 1)
	EXBEXO_VIPNHANVAT_MAIN,
	EXBEXO_VIPNHANVAT_CLOSE,
	eVIPNHANVAT_SEND_01,
	eVIPNHANVAT_SEND_02,
	eVIPNHANVAT_SEND_03,
	eVIPNHANVAT_SEND_04,
#endif

#if(KINH_MACH_NEW == 1)
	EXBEXO_KINHMACH_MAIN,
	EXBEXO_KINHMACH_CLOSE,
	eKINHMACH1,
	eKINHMACH2,
	eKINHMACH3,
	eKINHMACH4,
	eKINHMACH5,
	eKINHMACH6,
	eKINHMACH7,
	eKINHMACH8,
#endif

#if(NGU_HANH_NEW == 1)
	EXBEXO_NGUHANH_MAIN,
	EXBEXO_NGUHANH_CLOSE,
	eNGUHANH,
#endif

#if(MOCNAP == 1)
	EXBEXO_MOCNAP_MAIN,
	EXBEXO_MOCNAP_CLOSE,
	MOCNAP1,
	MOCNAP2,
	MOCNAP3,
	MOCNAP4,
	MOCNAP5,
	MOCNAP6,
	MOCNAP7,
	MOCNAP8,
	MOCNAP9,
	MOCNAP10,
	MOCNAP11,
	MOCNAP12,
	MOCNAP13,
#endif

#if(TAISINH == 1)
	EXBEXO_TAISINH_MAIN,
	EXBEXO_TAISINH_CLOSE,
	TAISINH1,
	TAISINH2,
	TAISINH3,
	TAISINH4,
	TAISINH5,
	TAISINH6,
	TAISINH7,
	TAISINH8,
	TAISINH9,
	TAISINH10,
#endif

	eCheck,
	eUnCheck,

	eCONFIRM_MUUN,
	eCONFIRM_MUUNBTN_OK,
	eCONFIRM_MUUNBTN_CANCEL,

	eHOIMAU_MUUN,
	eHOIMAU_MUUNBTN_OK,
	eHOIMAU_MUUN_TIME,



#if(MUUNAFK == 1)
	//1-04-2022
	eHOIMAU_MUUN_STAMINA,
	eHOIMAU_MUUN_WCOINCLAIM,

	eAFK_MUUN,
#endif

#if(CHARACTER_NEW)
	XOAHOMDO_CHARACTER,
	TINHNANG_CHARACTER,
#endif

#if(DEV_PLAYERSHOP == 1)
	CHOTROI_CHARACTER,
#endif

	MUUN_CHARACTER,

#if(SHOPSEARCH==TRUE)
	STORE_CHARACTER,
#endif

	TINHNANG_MAIN,

	eAUTORESET,
	eATTACK,
	eOFFATTACK,

	BUTTON_YES,
	BUTTON_NO,
	BUTTON_YES1,
	BUTTON_NO1,
	BUTTON_YES2,
	BUTTON_NO2,
	BUTTON_YES3,
	BUTTON_NO3,
	//---------------------------------------------------------------------
#if(DKTK1 == 1)
	OBJECT_DANGKY_MAIN,
	OBJECT_DANGKY_TAIKHOAN,
	OBJECT_DANGKY_MATKHAU,
	//OBJECT_DANGKY_TEN,
	//OBJECT_DANGKY_PHONE,
	OBJECT_DANGKY_SOBIMAT,
	//OBJECT_DANGKY_EMAIL,
	OBJECT_DANGKY_DONGY,
	OBJECT_DANGKY_BUTTON,
#endif

#if(OFFLINE_MODE_NEW)
	eOFFEXP_MAIN,
	eOFFEXP_TITLE,
	eOFFEXP_FRAME,
	eOFFEXP_FOOTER,
	eOFFEXP_DIV,
	eOFFEXP_CLOSE,
	eOFFEXP_POINT,
	eOFFEXP_CHECKBOX_BUFF,
	eOFFEXP_CHECKBOX_PICK_ZEN,
	eOFFEXP_CHECKBOX_PICK_JEWELS,
	eOFFEXP_CHECKBOX_PICK_EXC,
	eOFFEXP_CHECKBOX_PICK_ANC,
	eOFFEXP_CHECKBOX_SELECTED_HELPER,
	eOFFEXP_BTN_OK,

	eOFFEXP_SKILL1,
	eOFFEXP_SKILL2,
	eOFFEXP_SKILL3,
#endif

	//---------------------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
	eSACHTHUOCTINH_INTERFACE,
	eSACHTHUOCTINH_MAIN,
#endif
	//-------------------------------------------------------------------
#if(PHUKIEN_NEW == 1)
	ePHUKIEN1_INTERFACE,
	ePHUKIEN2_INTERFACE,
#endif
	//-------------------------------------------------------------------
	eEVENTTABLE_MOVE_01,
	eEVENTTABLE_MOVE_02,
	eEVENTTABLE_MOVE_03,
	eEVENTTABLE_MOVE_04,
	eEVENTTABLE_MOVE_05,
	eEVENTTABLE_MOVE_06,
	eEVENTTABLE_MOVE_07,
	eEVENTTABLE_MOVE_08,
	eEVENTTABLE_MOVE_09,
	eEVENTTABLE_MOVE_10,
	eEVENTTABLE_MOVE_11,
	eEVENTTABLE_MOVE_12,
	eEVENTTABLE_MOVE_13,
	eEVENTTABLE_MOVE_14,
	eEVENTTABLE_MOVE_15,
	eEVENTTABLE_MOVE_16,
	eEVENTTABLE_MOVE_17,
	eEVENTTABLE_MOVE_18,
	eEVENTTABLE_MOVE_19,
	eEVENTTABLE_MOVE_20,
	eEVENTTABLE_MOVE_21,
	//-------------------------------------------------------------------
	ex_PM_FLAGNEW_LEADER,
	
	ePT_PERSONAL_SEARCH_MAIN,
	ePT_PERSONAL_SEARCH_TITLE,
	ePT_PERSONAL_SEARCH_FRAME,
	ePT_PERSONAL_SEARCH_FOOTER,
	ePT_PERSONAL_SEARCH_DIV,
	ePT_PERSONAL_SEARCH_CLOSE,
	ePT_PERSONAL_SEARCH_L,
	ePT_PERSONAL_SEARCH_R,
	ePT_PERSONAL_SEARCH_PAGEUP1,
	ePT_PERSONAL_SEARCH_PAGEUP2,
	ePT_PERSONAL_SEARCH_PAGEUP3,
	ePT_PERSONAL_SEARCH_PAGEUP4,
	ePT_PERSONAL_SEARCH_PAGEUP5,
	ePT_PERSONAL_SEARCH_PAGEUP6,
	ePT_PERSONAL_SEARCH_PAGEUP7,
	ePT_PERSONAL_SEARCH_PAGEUP8,
	ePT_PERSONAL_SEARCH_PAGEUP9,
	ePT_PERSONAL_SEARCH_PAGEUP10,
	//**********************************************************************//
#if(LEOTHAP == 1)
	// Leo thap
	eLEOTHAP_MAIN,
	eLEOTHAP_TITLE,
	eLEOTHAP_FRAME,
	eLEOTHAP_FOOTER,
	eLEOTHAP_DIV,
	eLEOTHAP_CLOSE,
	eLEOTHAP_POINT,
	eLEOTHAP_BUTTON_GATE1,
	eLEOTHAP_BUTTON_GATE2,
	eLEOTHAP_BUTTON_GATE3,
	eLEOTHAP_BUTTON_GATE4,
	eLEOTHAP_BUTTON_GATE5,
#endif

	eMAX_VALUE,
	//**********************************************************************//
};

//========================================================================================================================================
// Advanced Stats
//========================================================================================================================================
enum ObjWindowsEx
{
	exWinNews = 1,
	exWinReset = 2,
	exWinGrandReset = 3,
	exWinRanking = 4,
	exWinDonate = 5,
	exWinPremium = 6,
	exWinMiniMenu = 7,
	exWinSettings = 8,
	exWinPTSearchMaster = 9,
	exWinPTSearchUser = 10,
	exWinPersonalSearch = 12,
	exWinPersonalPrice = 13,
	exWinNPCBuffer,
	exWinSmithy,
	exWinSmithyCheck,
	exWinCheckOffAfk,
	exWinMarriage,
	exWinAddPoints,
	exWinAddResetPoint,
	exWinCustomMenu,
	exWinCustomMenuChangeClass,
	exWinDungeonSiege,
	exWinTeamVsTeam,
	exWinTeamVsTeamStatistic,
	exWinAchievements,
	exWinAchievementsPower,
	exWinTeleport,
	exWinTeleportEvo,
	exWinResetRage,
	exWinDonateCheck,
	exWinPKClear,
	exWinAccWarning,
	exWinAccMenu,
	exWinAccOption,
	exWinAccPC,
	exWinAccMessage,
	exWinAccNumber,
	exWinReferralMenu,
	exWinReferralSystem,
	exWinReferralSystem2,
	exWinQuest,
	exWinLottery,
	exWinMenuV3,
	exWinStatsAdvance,

#if(DEV_PLAYERSHOP == 1)
	exWinItemMarket,
	exWinItemMarketPrice,
#endif

};

#if(DEV_PLAYERSHOP == 1)
enum MaiObjID
{
	ex_SMITHY_ITEM,
};
#endif

struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20]; // 20 phan tu day the
	bool	ByClose;
	bool	FirstLoad;

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}

	bool Check()
	{
		return this->OnShow;
	}
};

#if(TINHNANG_NEW == 1)
struct BUY_TINH_NANG_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

struct PMSG_TINHNANG_UPD
{
	PSBMSG_HEAD	h;
	int CommandResetPoint_WCoinC;
	int CommandResetMaster_WCoinC;
};
#endif

//--------------------------------------
#if(SACHTHUOCTINH_NEW)
struct SACHTHUOCTINH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
#endif
//--------------------------------------
#if(PHUKIEN_NEW == 1)
struct BUY_PHUKIEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
#endif
//--------------------------------------
struct MOVE_EVENT_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//--------------------------------------
//======================================================
#if(SACHTHUOCTINH_NEW)
struct PMSG_THUOCTINH_UPD
{
	PSBMSG_HEAD	h;
	int SachThuocTinh_02;
	int SachThuocTinh_03;
	int SachThuocTinh_04;
	int SachThuocTinh_05;
	int SachThuocTinh_06;
	int SachThuocTinh_07;
};

struct PMSG_THUOCTINH_ATIVE_UPD
{
	PSBMSG_HEAD	h;
	int OPTION_LEVEL_01;
	int OPTION_LEVEL_02;
	int OPTION_LEVEL_03;
	int OPTION_LEVEL_04;
	int OPTION_LEVEL_05;
	int OPTION_LEVEL_06;
	int OPTION_LEVEL_07;
	int OPTION_LEVEL_08;
	int OPTION_LEVEL_09;
	int OPTION_LEVEL_10;
	int OPTION_LEVEL_11;
	int OPTION_LEVEL_12;
	int OPTION_ACTIVE_01;
	int OPTION_ACTIVE_02;
	int OPTION_ACTIVE_03;
	int OPTION_ACTIVE_04;
	int OPTION_ACTIVE_05;
	int OPTION_ACTIVE_06;
	int OPTION_ACTIVE_07;
	int OPTION_ACTIVE_08;
	int OPTION_ACTIVE_09;
	int OPTION_ACTIVE_10;
	int OPTION_ACTIVE_11;
	int OPTION_ACTIVE_12;
};
#endif
//======================================================
#if(GHETINFOCLIENT == 1)
struct PMSG_CLIENT_UPD
{
	PSBMSG_HEAD	h;
	int SachThuocTinh_01;
	int PHUKIEN1;
	int PHUKIEN2;
	int AutoResetEnable;
	int AttackCustom;
	int GHRS;
	int DanhHieu;
	int TuLuyen;
#if(MOCNAP == 1)
	int MOCNAPCOIN;
#endif
	int Money;
};
#endif

//======================================================
struct PMSG_TVTEVENT_UPD
{
	PSBMSG_HEAD	h;
	int ScoreRed;
	int ScoreBlue;
	int KillCount;
	int DieCount;
	int TotalPlayer;
};
//======================================================

class Interface
{
public:
	float		VariableInterfazON;
	float		RightMiniInfoY;
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	InterfaceElement Data[MAX_OBJECT];
public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	void RenderObjectSystem2();
	static void LoadImages();
	static void LoadModels();
	static void Work();
//--
	#if(DEV_DAMAGE_TABLE)
	bool m_EnableDamageTable;
	void DrawDamageTable();
	#endif
	

	//--------------------------------------
	void TvTEventEx(PMSG_TVTEVENT_UPD * aRecv);
	int m_ScoreRed;
	int m_ScoreBlue;
	int m_KillCount;
	int m_DieCount;
	int m_TotalPlayer;
	//--------------------------------------
#if(SACHTHUOCTINH_NEW)
	void BUG_SACHTHUOCTINH(int Number);
#endif
	//--------------------------------------
#if(PHUKIEN_NEW == 1)
	void BUG_PHUKIEN(int Number);
#endif
	//--------------------------------------
#if(SACHTHUOCTINH_NEW)
	void GetInfoThuocTinh(PMSG_THUOCTINH_UPD * aRecv);
	int m_SachThuocTinh_01;
	int m_SachThuocTinh_02;
	int m_SachThuocTinh_03;
	int m_SachThuocTinh_04;
	int m_SachThuocTinh_05;
	int m_SachThuocTinh_06;
	int m_SachThuocTinh_07;

	void GetInfoThuocTinhAtive(PMSG_THUOCTINH_ATIVE_UPD * aRecv);
	int m_OPTION_LEVEL_01;
	int m_OPTION_LEVEL_02;
	int m_OPTION_LEVEL_03;
	int m_OPTION_LEVEL_04;
	int m_OPTION_LEVEL_05;
	int m_OPTION_LEVEL_06;
	int m_OPTION_LEVEL_07;
	int m_OPTION_LEVEL_08;
	int m_OPTION_LEVEL_09;
	int m_OPTION_LEVEL_10;
	int m_OPTION_LEVEL_11;
	int m_OPTION_LEVEL_12;
	int m_OPTION_ACTIVE_01;
	int m_OPTION_ACTIVE_02;
	int m_OPTION_ACTIVE_03;
	int m_OPTION_ACTIVE_04;
	int m_OPTION_ACTIVE_05;
	int m_OPTION_ACTIVE_06;
	int m_OPTION_ACTIVE_07;
	int m_OPTION_ACTIVE_08;
	int m_OPTION_ACTIVE_09;
	int m_OPTION_ACTIVE_10;
	int m_OPTION_ACTIVE_11;
	int m_OPTION_ACTIVE_12;

#endif
	//-----------------------------
#if(GHETINFOCLIENT == 1)
	void GetInfoClient(PMSG_CLIENT_UPD * aRecv);
	int m_PHUKIEN1;
	int m_PHUKIEN2;
	int m_AutoResetEnable;
	int m_AttackCustom;
	int m_GHRS;
	int m_DanhHieu;
	int m_TuLuyen;
#if(MOCNAP == 1)
	int m_MOCNAPCOIN;
#endif
	int m_Money;
#endif
	//-----------------------------

#if(TINHNANG_NEW == 1)
	void BUY_TINH_NANG_GAME(int Number);
	void GetInfoTinhNang(PMSG_TINHNANG_UPD * aRecv);
	int m_CommandResetPoint_WCoinC;
	int m_CommandResetMaster_WCoinC;
#endif

#if(CHARACTER_NEW)
	void		DrawCharacterWindow();
	bool		EventCharacterWindow_TinhNang(DWORD Event);

#if(DEV_PLAYERSHOP)
	bool		EventCharacterWindow_ChoTroi(DWORD Event);
#endif

	// Muun
	bool		EventCharacterWindow_MuunPet(DWORD Event);

#if(SHOPSEARCH==TRUE)
	bool		EventCharacterWindow_Store(DWORD Event);
#endif
	//-----
	void		DrawTinhNangWinDow();
	void	    OpenTinhNangWindow() { this->Data[TINHNANG_MAIN].OnShow = true; };
	void	    CloseTinhNangWindow() { this->Data[TINHNANG_MAIN].OnShow = false; };
	bool	    CheckTinhNangWindow() { return this->Data[TINHNANG_MAIN].OnShow; };
	bool		EventTinhNangWinDow(DWORD Event);
	//-----
	void DrawAutoReset();
	void DrawAttack();
	void DrawOffAttack();

	void DrawTextRun();
	bool QuayLai;


#endif

	//---------------------------------------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
	void		DrawSachThuocTinhInterface();
	bool		EventSachThuocTinhInterface(DWORD Event);

	void		DrawSachThuocTinh();
	void	    OpenSachThuocTinhWindow() { this->Data[eSACHTHUOCTINH_MAIN].OnShow = true; };
	void	    CloseSachThuocTinhWindow() { this->Data[eSACHTHUOCTINH_MAIN].OnShow = false; };
	bool	    CheckSachThuocTinhWindow() { return this->Data[eSACHTHUOCTINH_MAIN].OnShow; };
#endif
	//---------------------------------------------------------------------------------------
#if(PHUKIEN_NEW == 1)
	bool		EventRemovePhuKien1(DWORD Event);
	bool		EventRemovePhuKien2(DWORD Event);
#endif
	//---------------------------------------------------------------------------------------
	#if(OANTUTY)
	void		DrawRPS();
	void		EventRPS_Main(DWORD Event);
#endif
#if(OFFLINE_MODE_NEW)
	void		DrawOffExpWindow();
	bool		EventOffExpWindow_Main(DWORD Event);
	void		SwitchOffExpWindoState() { (Data[eOFFEXP_MAIN].OnShow == true) ? Data[eOFFEXP_MAIN].Close() : gOfflineMode.CGOfflineModeSend(); };
#endif
#if(OFFLINE_MODE_NEW)
	//bool		IsWorkZone(float X, float Y, float MaxX, float MaxY);
//	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
//	void		DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
#endif
	//---------------------------------------------------------------------------------------
	//--
	void DrawMenu();
	bool EventDrawMenu_Open(DWORD Event);
	//--
	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
	void        WindowsKG();
	
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	//void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
#if(VONGQUAY_NEW)
	static void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
#endif
	bool CheckWindow(int WindowID);
	int CloseWindow(int WindowID);
	int OpenWindow(int WindowID);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool		IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5 = false);
	bool IsWorkZone(short ObjectID);
	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();
	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();
	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	bool WindowEx[MAX_WINDOW_EX];
	bool CheckWindowEx(int WindowID);
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void CameraInit();
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	void DrawPing();
	void SendPingRecv();

	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	void		DrawWarehouseUI();
	void		EventWarehouseUI(DWORD Event);
	// ----
	void		DrawWarehouseWindow();
	void		EventWarehouseWindow_Main(DWORD Event);
	void		EventWarehouseWindow_Close(DWORD Event);

	// ----
	void		DrawChangingClassWindow();
	bool		EventChangingClassWindow_Main(DWORD Event);
	bool		EventChangingClassWindow_Close(DWORD Event);
	bool		EventChangingClassWindow_DW(DWORD Event);
	bool		EventChangingClassWindow_DK(DWORD Event);
	bool		EventChangingClassWindow_ELF(DWORD Event);
	bool		EventChangingClassWindow_MG(DWORD Event);
	bool		EventChangingClassWindow_DL(DWORD Event);
	bool		EventChangingClassWindow_SUM(DWORD Event);
	bool		EventChangingClassWindow_RF(DWORD Event);
	// ----
	bool		ControlTextBox(KBDLLHOOKSTRUCT Hook);
	
	void		DrawAnimatedGUI(short ObjectID, float X, float Y);
	void		DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color);
	void		DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	void		DrawMessageBox(LPCSTR Text, ...);
	//-- Party Bar ex700
	void		BarPartyNew();
	//-- Minimizar MiniMapa
	void		MiniMapMini();
	//////CTCmini//////////
	void		DrawCTCMiNiMap();
	void		DrawCTCMiniWindow();

#if(BOSS_GUILD == 1)
	void		DrawBossGuildWindow();
	void		DrawBossGuildMap();
#endif

#if(CHIENTRUONGCO == 1)
	void		DrawChienTruongCo();
	void		DrawTimeCTC();
#endif

	void	    TvTEvent();

	void SwitchNganHangNgoc();
	void SwitchFenrir();
	void SwitchHidePlayer();
	void SwitchHideDanhHieu();
	void SwitchAntiLag1();
	void SwitchAntiLag2();

	int  AntiLag1;
	int  AntiLag2;
	int  AntiLagPlayer;

#if(LEOTHAP == 1)
	// Leo thap
	void		DrawLeoThap();
	bool		EventLeoThap_Main(DWORD Event);
	bool		EventLeoThap_Close(DWORD Event);
	bool		EventLeoThap_All(DWORD Event);
#endif

	//-- Mover MiniMapa
	bool		IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false);

#if(DEV_PLAYERSHOP)
	void		DrawColorGUI(int MainID, int X, int Y, int Width, int Height, DWORD Color);
	void		DrawButtonBig(int ObjID, bool bActive, float fX, float fY, char* Text);
	void		DrawButtonMini(int id, int X, int Y, int res, char* Text);
	void		DrawCheckLineEx(bool Switch, int Point, int Check, int Line, float X, float Y, int Color, char* Text);
	void		PartUPandDNEx(int Point, int PageUp, int PageDn, int Line, float X, float Y, int Color, int Number, char* Text);
	bool		ButtonExR(DWORD Event, int ButtonID, bool Type);
	void		DrawItem1(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void DrawItemToolTipText(void * item, int x, int y);
	void		KeyBoxEvent(DWORD Event, char* kText, int MaxText);
	void		DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	void		DrawGUIY(short ObjectID, float PosX, float PosY, int Type);

	void		OpenWindowEx(int WindowID);
	void		CloseWindowEx(int WindowID);
#endif

#if (ARCHIVEMENT == 1)
	void TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...);
#endif

private:
	
};

//void InitAllSeason();

extern Interface gInterface;