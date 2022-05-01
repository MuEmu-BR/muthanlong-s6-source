#pragma once

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define GAMESERVER_STATUS "STANDBY MODE"

#define GAMESERVER_STATUS_MODE "ACTIVE MODE"

#define GAMESERVER_HOST 1

#define ISPREMIUN 1

extern int Conectar;

#define GAMESERVER_NOMBRE 1

#if(GAMESERVER_NOMBRE == 0)
	#define GAMESERVER_CLIENT "VIERJA&HIGHLEVEL"
#elif(GAMESERVER_NOMBRE == 1)
	#define GAMESERVER_CLIENT "0782229639-GS"
#else
#define GAMESERVER_CLIENT "REAL GAMING"
#endif

#define UPDATE_GAMING 15
#define GAMESERVER_CLIENTE_UPDATE 17
#define GAMESERVER_CLIENTE_PREMIUM 1

#define VERSION "1.0.0.0"

#if(GAMESERVER_TYPE==0)
#define GAMESERVER_VERSION "0782229639-GS"
#else
#define GAMESERVER_VERSION "0782229639-GSGS"
#endif

#ifndef GAMESERVER_TYPE
#define GAMESERVER_TYPE 0
#endif

#define GAMESERVER_TYPE2 0


#ifndef GAMESERVER_EXTRA
#define GAMESERVER_EXTRA 1
#endif

#ifndef GAMESERVER_UPDATE
#define GAMESERVER_UPDATE 803
#endif

#if(GAMESERVER_UPDATE==401)
#define GAMESERVER_SEASON "SEASON 4"
#endif

#if(GAMESERVER_UPDATE==603)
#define GAMESERVER_SEASON "SEASON 6"
#endif

#if(GAMESERVER_UPDATE==803)
#define GAMESERVER_SEASON "SEASON 8"
#endif

#ifndef GAMESERVER_LANGUAGE
#define GAMESERVER_LANGUAGE 1
#endif

#ifndef PROTECT_STATE
#define PROTECT_STATE 1
#endif

#ifndef BOTCONGHUONG
#define BOTCONGHUONG 1
#endif

#ifndef BOTHUMUADORAC
#define BOTHUMUADORAC 1
#endif

#ifndef BOT_STATUE
#define BOT_STATUE 1
#endif

#ifndef OANTUTI
#define OANTUTI 1
#endif

#ifndef ENCRYPT_STATE
#define ENCRYPT_STATE 1
#endif

#if(PROTECT_STATE==0)
#define GAMESERVER_NAME "Free"
#else
#define GAMESERVER_NAME "Premium"
#endif

#define HIDE                        1
#define HIDE_VT                     0

// Sửa Lỗi
#define FIXVT   		            1

#define VANTHANH 15

#define CUSTOM_PET					1

#define OFFLINE_MODE				1

#define CHANGE_FIX_POINT            0 // OFF

#define Fix_Dupe             1

#define BUFFSETDAME     	 1

#define MONSTER_CALL     	 1
#define VONGQUAY_NEW         1 
#define NGANHANGNGOC_NEW     1 

#define MONSTERITEM          1 

#define TULUYEN_NEW         1 

#define DANHHIEU_NEW	     1

#define THUEVIP_NEW	        1 

#define KINHMACH_NEW        1

#define NGUHANH_NEW         1

#define WINDOWSQUEST        1

#define ARCHIVEMENT          1

#define TINHNANG_NEW         1

#define SACHTHUOCTINH_NEW    1 

#define PHUKIEN_NEW          1 

#define USE_FAKE_ONLINE      TRUE

#define POINT_SAU_KHI_RESET  1 //

#define RESETLIFE_NEW	     1

#define GHRS_TOP1_NEW        1 // ON 
//----------------------------
#define SWAMP_EVENT                 1
//----------------------------
#define MOVE_EVENT_NEW              1

#define DEV_DAMAGE_TABLE	    1

#define OFFLINE_MODE_NEW        1 // ON

#define USE_OFFLINEMODE_HELPER_PICK FALSE

#define CUSTOM_PARTY_LEADER		0
//MC bot
//----------------------------
//	 ZG-Defines			     -
//	 1:ON  (CPP AND HEADER!) -
//	 2:OFF (CPP AND HEADER!) -
//----------------------------

#ifndef POINT_CUSTOM 
#define POINT_CUSTOM 1 // ShopPointEx
#endif


#define PC_POINT			 2 //Agregar algun npc o bot con PCP
#define HAPPY_HOURS			 2 //[80%]->Falta Arreglar Los Vip!
#define MASTER_HOURS		 2
#define ACHERON_GUARDIAN	 2

#define BOT_BUFFER			 1

#define BOT_ATTACK   		 1

#define BOT_STORE            1

#define BOT_ONLINE           1

#define CUSTOM_PERSONAL_SHOP 1

// Event
#define LEOTHAP              1  

#define SKY_EVENT            1

//==================================
#define BOSS_GUILD           1
// save kill boss guild
#define NEWBOSSGUILD 1
//==================================

#define CTC_MINI             1

#define CHIENTRUONGCO        1

#define HONCHIENCLASS        1

#define TVTEVENT             1

#define GVGEVENT             1

#define RANKINGGOC  0
#define RANKING_NEW 1

#define MOCNAP 1

#define GHETINFOCLIENT 1

#define CHANGECLASS 1

#define THAPBOSS_NEW 1

#define TAISINH 1

#define CUSTOMARENA_NEW 0

#define RESETVIP 1

// add new reconnect fix
#define RECONNECT 1

#define GHRSSERVER 1

#define CHECK_USER 1

#define ANTIHACKVT 1

#define DKTK1 0 //22-03-2022 OFF
#define DKTK2 0 //22-03-2022 OFF

// 07-03-2022
#define FIXMUUNPET 1

// 09-03-2022
#define FIX_VANTHANH 1

//=========================================================
#define CAPNHAP_DATASERVER 1   // 11-03-2022
#define CUSTOM_GIOIHAN     1   // 11-03-2022
#define CUSTOM_MIXDEV      1   // 12-03-2022
//20-03-2022 
//20-03-2022 MuunPetCustom.cpp.h
#define BOSS_NHEN_TIME     1   // 20-03-2022
//21-03-2022
//22-03-2022 #define FIXAMWCOIN Xóa
//23-03-2022
//24-03-2022
//25-03-2022
//27-03-2022
#define LICENSE  0 // //28-03-2022
//28-03-2022
#define MUUNAFK  1 // //29-03-2022
//29-03-2022
//1-04-2022
//=========================================================

//-- Need All Types
#define PG_CUSTOM			 1
#define ALLBOTSSTRUC		 1

#include <windows.h>
#include <winsock2.h>
#include <mswSock.h>
#include <commctrl.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <random>
#include <Rpc.h>
#include <algorithm>
#include <string>
#include <atltime.h>
#include <dbghelp.h>
#include <Psapi.h>
#include "..//..//..//Util//pugixml//pugixml.hpp"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")

#if(GAMESERVER_UPDATE>=701)
#if(NDEBUG==0)
#pragma comment(lib,"..\\..\\Util\\cryptopp\\Debug\\cryptlib.lib")
#else
#pragma comment(lib,"..\\..\\Util\\cryptopp\\Release\\cryptlib.lib")
#endif
#pragma comment(lib,"..\\..\\Util\\mapm\\mapm.lib")
#endif

typedef char chr;

typedef float flt;

typedef short shrt;

typedef unsigned __int64 QWORD;
