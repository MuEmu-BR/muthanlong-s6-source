#pragma once

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define DATASERVER_VERSION "1.0.0.0"
#define GAMESERVER_TYPE2 0

#define GAMESERVER_NOMBRE 1

#if(GAMESERVER_NOMBRE == 0)
	#define DATASERVER_CLIENT "VIERJA&HIGHLEVEL"
#elif(GAMESERVER_NOMBRE == 1)
	#define DATASERVER_CLIENT "DataServer"
#else
#define DATASERVER_CLIENT "REAL GAMING"
#endif



#ifndef DATASERVER_UPDATE
#define DATASERVER_UPDATE 803
#endif

#ifndef PROTECT_STATE
#define PROTECT_STATE 1
#endif

#ifndef BOT_STATUE
#define BOT_STATUE 1
#endif

#define NGANHANGNGOC_NEW            1

#define KINH_MACH_NEW               1

#define TU_LUYEN_NEW                1

#define DANH_HIEU_NEW	            1

#define THUE_VIP_NEW	            1

#define NGU_HANH_NEW	            1

#define RESETLIFE_NEW	            1

#define SACHTHUOCTINH_NEW           1

#define PHUKIEN_NEW               1

#define GHRS_TOP1_NEW               1

#define WINDOWSQUEST         1

#define ARCHIVEMENT          1

#define RSTIME               0

#define HONCHIENCLASS        1

#define CHIENTRUONGCO 1

#define LEOTHAP 1

#define RANKINGGOC  0
#define RANKING_NEW 1

#define NEWBOSSGUILD 1

#define MOCNAP 1
//----------------------------
//11-03-2022
#define CAPNHAP_DATASERVER 1 // 11-03-2022
#define CUSTOM_GIOIHAN 1 // 11-03-2022
//22-03-2022 #define FIXAMWCOIN Xóa
#define MUUNAFK  1 // //29-03-2022
//29-03-2022
//----------------------------
#define HIDE_VT 0 
//----------------------------
// System Include
#include <windows.h>
#include <winsock2.h>
#include <commctrl.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <process.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <Rpc.h>
#include <dbghelp.h>
#include <Psapi.h>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")

extern char CustomerName[32];
extern char CustomerHardwareId[36];

typedef unsigned __int64 QWORD;
