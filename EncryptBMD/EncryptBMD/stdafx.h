#pragma once

// System Include
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>

//newadd
#include <map>
#include <fstream>

#define PREMIUN	1

//new add
#define MAX_CUSTOM_GLOVES	50
#define MAX_CUSTOM_BOW		50
#define MAX_PET_ITEM		300
#define MAX_CUSTOMCLOAK		20


#define MAX_REMAKE_EFFECT	100
#define MAX_CUSTOM_WING		100
#define MAX_POSITION_ITEM	1000

#define MAX_CUSTOPETEFFECT	3000
#define MAX_DYNAMIC_WING_EFFECT	15000
#define MAX_CUSTOM_WING_EFFECT	15000

#define ITEM_INTER					1171
#define ITEM(x, y)					((x * 512) + y)
#define ITEM2(x, y)					((x * 512) + y + ITEM_INTER)
#define GET_ITEM(x, y)	((x * 512) + y)
#define UPDATE 15