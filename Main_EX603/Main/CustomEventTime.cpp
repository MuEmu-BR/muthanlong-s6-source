#include "stdafx.h"
#include "CustomEventTime.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "SItemOption.h"
#include "WindowsStruct.h"
#include "Other.h"



CCustomEventTime::CCustomEventTime()
{
}

CCustomEventTime gCustomEventTime;

//20-03-2022 
void CCustomEventTime::Bind() // OK
{
	gInterface.BindObject(eEVENTTABLE_MOVE_01, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_02, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_03, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_04, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_05, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_06, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_07, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_08, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_09, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_10, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_11, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_12, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_13, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_14, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_15, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_16, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_17, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_18, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_19, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_20, 31461, 35, 14, -1, -1);
	gInterface.BindObject(eEVENTTABLE_MOVE_21, 31461, 35, 14, -1, -1);
}

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info) // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime() // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		gCustomEventTime[n].time = -1;
	}
	this->count = 0;
	this->EventTimeEnable = 0;
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg) // OK
{
	this->count = lpMsg->count;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_EVENTTIME_RECV)+(sizeof(CUSTOM_EVENTTIME_DATA)*n));

		this->gCustomEventTime[n].index = lpInfo->index;
		this->gCustomEventTime[n].time = lpInfo->time;

		//if (this->gCustomEventTime[n].index >= 19 && this->gCustomEventTime[n].time != -1) this->Arena = 1;
		if (this->gCustomEventTime[n].index >= 25 && this->gCustomEventTime[n].time != -1);
	}

	this->EventTimeEnable = 1;
}

int NextEvent = 0;
int PreventEvent = 0;

void CCustomEventTime::DrawEventTimePanelWindow()
{

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
	{
		return;
	}
	if (gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(MoveList)
		) //-- 76
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		return;
	}

	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	if (gInterface.IsWorkZone(eEventTimePANEL_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	gCItemSetOption.ItemTooltipS15(StartX - 140, StartY - 20, 340, 400, 0.0, 0);

	DWORD Color = eGray100;
	if (this->EventTimeEnable == 1)
	{

		if ((GetTickCount() - this->EventTimeTickCount) > 1000)
		{
			for (int i = 0; i < this->count; i++)
			{
				if (this->gCustomEventTime[i].time > 0)
				{
					this->gCustomEventTime[i].time = this->gCustomEventTime[i].time - 1;
				}
			}
			this->EventTimeTickCount = GetTickCount();
		}

		char text1[120];
		char text2[130];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;

		int line = 0;

		for (int i = 0; i < 25; i++) // Hiển thị event
		{
			if (this->gCustomEventTime[i].time <= -1)
			{
				continue;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				wsprintf(text2, "Online");
			}
			else
			{
				totalseconds = this->gCustomEventTime[i].time;
				hours = totalseconds / 3600;
				minutes = (totalseconds / 60) % 60;
				seconds = totalseconds % 60;
				wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);

				if (hours > 23)
				{
					days = hours / 24;
					wsprintf(text2, "%d day(s)+", days);
				}
				else
				{
					wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}


			if (this->gCustomEventTime[i].time <= -1)
			{
				Color = eRed2;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				Color = eExcellent;
			}
			else if (this->gCustomEventTime[i].time < 300)
			{
				Color = eOrange;
			}
			else
			{
				Color = eYellow;
			}

			gCItemSetOption.ItemTooltipS15(StartX - 135, StartY - 22 + (line)+10, 330, 15, 0.0, 0);

			gInterface.DrawFormat(eWhite, StartX - 125, StartY - 11 + (line), 500, 1, this->m_CustomEventInfo[i].Name); // Tên Event

			gInterface.DrawFormat(eBlue, StartX - 15, StartY - 11 + (line), 500, 1, this->m_CustomEventInfo[i].PhanThuong); // Phần Thương

			gInterface.DrawFormat(Color, StartX + 105, StartY - 11 + (line), 80, 1, text2); // Thời gian

			if (i == 0){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_01, StartX + 138, StartY - 12 + (line)); } }
			if (i == 1){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_02, StartX + 138, StartY - 12 + (line)); } }
			if (i == 2){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_03, StartX + 138, StartY - 12 + (line)); } }
			if (i == 3){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_04, StartX + 138, StartY - 12 + (line)); } }
			if (i == 4){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_05, StartX + 138, StartY - 12 + (line)); } }
			if (i == 5){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_06, StartX + 138, StartY - 12 + (line)); } }
			if (i == 6){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_07, StartX + 138, StartY - 12 + (line)); } }
			if (i == 7){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_08, StartX + 138, StartY - 12 + (line)); } }
			if (i == 8){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_09, StartX + 138, StartY - 12 + (line)); } }
			if (i == 9){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_10, StartX + 138, StartY - 12 + (line)); } }
			if (i == 10){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_11, StartX + 138, StartY - 12 + (line)); } }
			if (i == 11){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_12, StartX + 138, StartY - 12 + (line)); } }
			if (i == 12){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_13, StartX + 138, StartY - 12 + (line)); } }
			if (i == 13){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_14, StartX + 138, StartY - 12 + (line)); } }
			if (i == 14){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_15, StartX + 138, StartY - 12 + (line)); } }
			if (i == 15){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_16, StartX + 138, StartY - 12 + (line)); } }
			if (i == 16){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_17, StartX + 138, StartY - 12 + (line)); } }
			if (i == 17){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_18, StartX + 138, StartY - 12 + (line)); } }
			if (i == 18){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_19, StartX + 138, StartY - 12 + (line)); } }
			if (i == 19){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_20, StartX + 138, StartY - 12 + (line)); } }
			if (i == 20){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_21, StartX + 138, StartY - 12 + (line)); } }

			if (i == 0){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 1){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 2){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 3){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 4){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 5){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 6){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 7){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 8){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 9){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 10){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 11){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 12){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 13){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 14){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 15){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 16){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 17){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 18){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 19){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			if (i == 20){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }

			if (i == 0){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 1){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 2){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 3){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 4){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 5){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 6){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 7){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 8){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 9){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Đăng Ký"); } }
			if (i == 10){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 11){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 12){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 13){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 14){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 15){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 16){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 17){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 18){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 19){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }
			if (i == 20){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 151, StartY - 11 + (line), 80, 1, "Tham gia"); } }

			line += 18; // 18
		}
	}
	else
	{
		if (this->EventTimeLoad == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading ..");
			this->EventTimeLoad = 2;
		}
		else if (this->EventTimeLoad == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading ...");
			this->EventTimeLoad = 3;
		}
		else if (this->EventTimeLoad == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading ....");
			this->EventTimeLoad = 4;
		}
		else if (this->EventTimeLoad == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading .....");
			this->EventTimeLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading .");
			this->EventTimeLoad = 1;
		}
	}
	//}
	//this->OpenWindow();
}

bool CCustomEventTime::EventEventTimeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eEventTime_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eEventTime_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void CCustomEventTime::OpenWindow()
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
	//if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	//{
	//	return;
	//}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomEventTime();

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;

	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));

	DataSend((BYTE*)&pMsg, pMsg.header.size);

	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void CCustomEventTime::Notice()
{
	if (gInterface.CheckWindow(ChatWindow) || gInterface.CheckWindow(Trade) || gInterface.CheckWindow(ChaosBox)) //-- 76
	{
		return;
	}

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	
	this->EventTimeTickCount = GetTickCount();
	char text1[20];
	char text2[30];
	int totalseconds, hours, minutes, seconds, days, line = 0;

	for (int i = 0; i < this->count; i++)

	{
		if (this->gCustomEventTime[i].time <= -1){
			continue;
		}
		else if (this->gCustomEventTime[i].time == 0){
			wsprintf(text2, "Online");
		}
		else{
			totalseconds = this->gCustomEventTime[i].time;
			hours = totalseconds / 3600;
			minutes = (totalseconds / 60) % 60;
			seconds = totalseconds % 60;
			wsprintf(text2, gTime, minutes, seconds);
			if (hours > 23){
				days = hours / 24;
				wsprintf(text2, "%d day(s)+", days);
			}
			else{
				wsprintf(text2, gTime, minutes, seconds);
			}
		}
		DWORD Color;
		if (this->gCustomEventTime[i].time <= -1){
			Color = eRed2;
		}
		else if (this->gCustomEventTime[i].time == 0)
		{
			Color = eExcellent;
		}

		else if (this->gCustomEventTime[i].time < 300)
		{
				Color = eExcellent;
				float StartX = MAX_WIN_WIDTH;
				float StartY = MAX_WIN_HEIGHT;

				gCItemSetOption.ItemTooltipS15(StartX / 5 + 90, StartY / 4 + 280, 205, 20, 0.0, 0);

				gInterface.DrawFormat(eExcellent, StartX / 5 + 95, StartY / 4 + 284, 120, 1, this->m_CustomEventInfo[i].Name);

				gInterface.DrawFormat(eYellow, StartX / 5 + 210, StartY / 4 + 284, 100, 1, text2);

				gInterface.DrawFormat(eWhite, StartX / 5 + 254, StartY / 4 + 284, 100, 1, gSy2);

			}
			else
			{
				Color = eYellow;
			}

			line += 0;
	}
}
//---------------------------------------------------------
void CCustomEventTime::MOVE_EVENT_GAME(int Number)
{
	MOVE_EVENT_REQ pMsg;
	pMsg.h.set(0xFC, 0x11, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool CCustomEventTime::Button(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();

	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_01))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_01].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_01].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_01].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_01].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(1);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_02))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_02].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_02].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_02].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_02].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(2);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_03))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_03].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_03].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_03].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_03].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(3);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_04))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_04].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_04].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_04].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_04].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(4);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_05))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_05].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_05].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_05].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_05].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(5);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_06))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_06].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_06].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_06].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_06].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(6);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_07))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_07].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_07].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_07].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_07].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(7);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_08))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_08].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_08].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_08].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_08].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(8);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_09))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_09].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_09].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_09].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_09].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(9);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_10))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_10].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_10].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_10].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_10].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(10);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_11))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_11].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_11].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_11].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_11].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(11);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_12))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_12].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_12].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_12].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_12].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(12);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_13))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_13].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_13].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_13].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_13].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(13);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_14))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_14].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_14].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_14].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_14].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(14);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_15))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_15].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_15].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_15].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_15].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(15);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_16))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_16].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_16].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_16].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_16].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(16);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_17))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_17].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_17].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_17].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_17].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(17);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_18))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_18].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_18].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_18].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_18].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(18);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_19))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_19].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_19].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_19].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_19].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(19);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_20))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_20].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_20].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_20].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_20].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(20);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow && gInterface.IsWorkZone(eEVENTTABLE_MOVE_21))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eEVENTTABLE_MOVE_21].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eEVENTTABLE_MOVE_21].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eEVENTTABLE_MOVE_21].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eEVENTTABLE_MOVE_21].EventTick = GetTickCount();
		this->MOVE_EVENT_GAME(21);
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	}
	
	return true;
}