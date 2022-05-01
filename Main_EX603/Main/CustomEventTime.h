#pragma once

#include "Protocol.h"
#include "Import.h"


#define MAX_EVENTTIME 42

struct PMSG_CUSTOM_EVENTTIME_RECV
{
	PSWMSG_HEAD h;
	int count;
};

struct PMSG_CUSTOM_EVENTTIME_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
};

struct CUSTOM_EVENTTIME_DATA
{
	int index;
	int time;
};

struct CUSTOM_EVENT_INFO
{
	int Index;
	char Name[200];
	char PhanThuong[200];
};


class CCustomEventTime
{
public:
	CCustomEventTime();

	//20-03-2022 
	void Bind();

	void Load(CUSTOM_EVENT_INFO* info);
	void SetInfo(CUSTOM_EVENT_INFO info);
	void ClearCustomEventTime();
	void GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg);	
	void DrawEventTimePanelWindow();
	bool EventEventTimeWindow_Close(DWORD Event);
	void OpenWindow();
	//bool EventNext(DWORD Event);
	//bool EventPrev(DWORD Event);
	void Notice();

	bool Button(DWORD Event);

	void MOVE_EVENT_GAME(int Number);

	CUSTOM_EVENT_INFO m_CustomEventInfo[MAX_EVENTTIME];
	int count;
	CUSTOM_EVENTTIME_DATA gCustomEventTime[MAX_EVENTTIME];
	int EventTimeTickCount;

private:
	//CUSTOM_EVENT_INFO m_CustomEventInfo[MAX_EVENTTIME];
	//int count;
	//CUSTOM_EVENTTIME_DATA gCustomEventTime[MAX_EVENTTIME];
	int EventTimeLoad;
	int EventTimeEnable;
	//int EventTimeTickCount;
	int Page;
	int Arena;
};
extern CCustomEventTime gCustomEventTime;



static char gTime[255] = "%02d:%02d";
static char gSy1[255] = "Sự kiện ";
static char gSy2[255] = "Phím J";
