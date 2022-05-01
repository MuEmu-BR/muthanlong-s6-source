#pragma once

#define MAX_MAIN_VIEWPORT 400
#define RGBTOGLFLOAT(x) ((float)x/255.0f)
#define FLOATTORGB(x)	((float)x*255)
#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#include "Protocol.h"

struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
	BYTE rate2;
	int ItemID;
	BYTE bHasManyFlag;
};

void ClearNewHealthBar();
void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo);
NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type);
void DrawNewHealthBar();

bool PlayerHasManyFlag(WORD index);
