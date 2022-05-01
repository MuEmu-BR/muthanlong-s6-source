#pragma once

#define BC_MAP_RANGE(x) (((x)<MAP_BLOOD_CASTLE1)?0:((x)>MAP_BLOOD_CASTLE7)?(((x)==MAP_BLOOD_CASTLE8)?1:0):1)
#define CC_MAP_RANGE(x) (((x)<MAP_CHAOS_CASTLE1)?0:((x)>MAP_CHAOS_CASTLE6)?(((x)==MAP_CHAOS_CASTLE7)?1:0):1)
#define IT_MAP_RANGE(x) (((x)<MAP_ILLUSION_TEMPLE1)?0:((x)>MAP_ILLUSION_TEMPLE6)?0:1)
#define DA_MAP_RANGE(x) (((x)==MAP_DUEL_ARENA)?1:0)
#define DG_MAP_RANGE(x) (((x)<MAP_DOUBLE_GOER1)?0:((x)>MAP_DOUBLE_GOER4)?0:1)
#define IG_MAP_RANGE(x) (((x)<MAP_IMPERIAL_GUARDIAN1)?0:((x)>MAP_IMPERIAL_GUARDIAN4)?0:1)

void InitMap();
static void LoadNewTextMapName();
char* LoadMapName(signed int MapNumber);