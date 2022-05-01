#include "stdafx.h"
#include "DangKyTaiKhoan.h"
#include "Interface.h"
#include "Console.h"
#include "Offset.h"
#include "Protect.h"
#include "Defines.h"
#include "SItemOption.h"
#include "Central.h"
#include "Util.h"

#if(DKTK1 == 1)

cDangKyTaiKhoan gDangKyTaiKhoan;

cDangKyTaiKhoan::cDangKyTaiKhoan()
{

}

cDangKyTaiKhoan::~cDangKyTaiKhoan()
{

}

void cDangKyTaiKhoan::bind()
{
	gInterface.BindObject(OBJECT_DANGKY_MAIN, 31461, 222, 345 + 30, -1, -1);

	gInterface.BindObject(OBJECT_DANGKY_TAIKHOAN, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(OBJECT_DANGKY_MATKHAU, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(OBJECT_DANGKY_SOBIMAT, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(OBJECT_DANGKY_DONGY, 0x7A5E, 108, 29, -1, -1);

	gInterface.BindObject(OBJECT_DANGKY_BUTTON, 31461, 50, 30, -1, -1);
	
	memset(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue, 0, sizeof(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue));
	memset(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue, 0, sizeof(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue));
	memset(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue, 0, sizeof(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue));

}

void cDangKyTaiKhoan::draw_dangky_window()
{

	gInterface.Data[OBJECT_DANGKY_MAIN].Open();

	if (showregister == true)
	{
		gCentral.PrintDropBox(450, 50, 180, 140, 0, 0);
		//---------------------------------------------
		gInterface.DrawFormat(eGold, 490, 54, 250, 1, "Đăng ký máy chủ Thần Long");
		//---------------------------------------------
		if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
		{
			if (strlen(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue) == 0)
				sprintf(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue, "NONE");
		}
		gInterface.DrawGUI(OBJECT_DANGKY_TAIKHOAN, 455, 80);
		if (gInterface.Data[OBJECT_DANGKY_TAIKHOAN].Attribute == 1)
		{
			gInterface.DrawColoredGUI(OBJECT_DANGKY_TAIKHOAN, 455, 80, eYellow);
		}
		gInterface.DrawText(eWhite, 460, 86, 200, 1, "Tài Khoản");
		gInterface.DrawText(eExcellent, 470, 86, 200, 3, gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue); // chỗ này là thêm à 
		//---------------------------------------------
		//---------------------------------------------
		if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
		{
			if (strlen(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue) == 0)
				sprintf(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue, "NONE");
		}
		gInterface.DrawGUI(OBJECT_DANGKY_MATKHAU, 455, 100);
		if (gInterface.Data[OBJECT_DANGKY_MATKHAU].Attribute == 1)
		{
			gInterface.DrawColoredGUI(OBJECT_DANGKY_MATKHAU, 455, 100, eYellow);
		}
		gInterface.DrawText(eWhite, 460, 106, 200, 1, "Mật Khẩu");
		gInterface.DrawText(eExcellent, 470, 106, 200, 3, gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue);
		//---------------------------------------------
		//---------------------------------------------
		if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
		{
			if (strlen(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue) == 0)
				sprintf(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue, "NONE");
		}
		gInterface.DrawGUI(OBJECT_DANGKY_SOBIMAT, 455, 120);
		if (gInterface.Data[OBJECT_DANGKY_SOBIMAT].Attribute == 1)
		{
			gInterface.DrawColoredGUI(OBJECT_DANGKY_SOBIMAT, 455, 120, eYellow);
		}
		gInterface.DrawText(eWhite, 460, 126, 200, 1, "7 Số bí mật");
		gInterface.DrawText(eExcellent, 470, 126, 200, 3, gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue);
		//---------------------------------------------
		//---------------------------------------------
		gInterface.DrawGUI(OBJECT_DANGKY_DONGY, 490, 150);
		gInterface.DrawText(eWhite, 525, 157, 200, 1, "Đăng Ký");
		if (gInterface.IsWorkZone(OBJECT_DANGKY_DONGY))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(OBJECT_DANGKY_DONGY, gInterface.Data[OBJECT_DANGKY_DONGY].X, gInterface.Data[OBJECT_DANGKY_DONGY].Y, Color);
		}
	}
	if (showregister == false)
	{
		float MainWidth = 230.0;
		float StartY = 20.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2) + 200 + 10;
		float MainCenter = StartX + (MainWidth / 3);

		gInterface.DrawButton(OBJECT_DANGKY_BUTTON, StartX - 165, StartY + 315, 0, 0);

		if (gInterface.IsWorkZone(OBJECT_DANGKY_BUTTON))
		{
			int ScaleY = 30;
			// ----
			if (gInterface.Data[OBJECT_DANGKY_BUTTON].OnClick)
			{
				ScaleY = 60;
			}
			gInterface.DrawButton(OBJECT_DANGKY_BUTTON, gInterface.Data[OBJECT_DANGKY_BUTTON].X + 28, gInterface.Data[OBJECT_DANGKY_BUTTON].Y + 110, 0, ScaleY);

		}
	}
	//---------------------------------------------
	//---------------------------------------------

	if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
	{
		gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad = false;
	}
}

void cDangKyTaiKhoan::dangky_switch_state()
{
	gInterface.Data[OBJECT_DANGKY_MAIN].OnShow == true ? gInterface.Data[OBJECT_DANGKY_MAIN].Close() : gInterface.Data[OBJECT_DANGKY_MAIN].Open();
}


BOOL check_number_string(const char * szStr)
{
	int len = strlen(szStr);
	for (int i = 0; i < len; i++)
	{
		if (szStr[i] >= '0' && szStr[i] <= '9')
		{
			continue;
		}

		return FALSE;
	}

	return TRUE;
}

bool CheckName(char * szID)
{
	if (FindText2(szID, " ", 0) || FindText2(szID, "¡¡", 0) ||
		FindText2(szID, ".", 0) || FindText2(szID, "¡¤", 0) ||
		FindText2(szID, "¡­", 0) || FindText2(szID, "Webzen", 0) ||
		FindText2(szID, "WebZen", 0) || FindText2(szID, "webzen", 0) ||
		FindText2(szID, "WEBZEN", 0) || FindText2(szID, GlobalText(GlobalLine, 457), 0) ||
		FindText2(szID, GlobalText(GlobalLine, 458), 0))
	{
		return true;
	}
	return false;
}

void cDangKyTaiKhoan::event_dangky_window(DWORD Event)
{
	if (!gInterface.Data[OBJECT_DANGKY_MAIN].OnShow)
	{
		return;
	}
	const DWORD CurrentTick = GetTickCount();
	//===================

	if (gInterface.IsWorkZone(OBJECT_DANGKY_BUTTON))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_DANGKY_BUTTON].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_DANGKY_BUTTON].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_DANGKY_BUTTON].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_DANGKY_BUTTON].EventTick = GetTickCount();
		showregister = true;
	}


	if (gInterface.IsWorkZone(OBJECT_DANGKY_TAIKHOAN))
	{
		gInterface.Data[OBJECT_DANGKY_TAIKHOAN].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_DANGKY_TAIKHOAN].Attribute = 0;
	}
	//===================
	if (gInterface.IsWorkZone(OBJECT_DANGKY_MATKHAU))
	{
		gInterface.Data[OBJECT_DANGKY_MATKHAU].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_DANGKY_MATKHAU].Attribute = 0;
	}
	//===================
	if (gInterface.IsWorkZone(OBJECT_DANGKY_SOBIMAT))
	{
		gInterface.Data[OBJECT_DANGKY_SOBIMAT].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_DANGKY_SOBIMAT].Attribute = 0;
	}
	//===================
	if (gInterface.IsWorkZone(OBJECT_DANGKY_DONGY))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_DANGKY_DONGY].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_DANGKY_DONGY].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_DANGKY_DONGY].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_DANGKY_DONGY].EventTick = GetTickCount();
		// moi cho nay la xuong gs
		bool isFail = false;

		PMSG_REGISTER_ACCOUNT_RECV bufer = { 0 };
		bufer.h.set(0xFB, 0x82, sizeof(bufer));
		
		// Account
		if (strlen(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue) > 3 
			&& strlen(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue) < sizeof(bufer.account))
		{
			memcpy(bufer.account, gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue, sizeof(bufer.account));
		}
		else
		{
			isFail = true;
		}
		// Pass
		if (strlen(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue) > 3
			&& strlen(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue) < sizeof(bufer.password))
		{
			memcpy(bufer.password, gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue, sizeof(bufer.password));
		}
		else
		{
			isFail = true;
		}
		// numcode
		if (strlen(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue) == 7			
			&& check_number_string(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue))
		{
			memcpy(bufer.numcode, gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue, sizeof(bufer.numcode));
		}
		else
		{
			isFail = true;
		}
		// ket thuc
		if (isFail == false)
		{
			DataSend((BYTE*)&bufer, sizeof(bufer));
			//pDrawMessage("send ok", 1);
			// Rs ve 0
			if (strlen(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue) > 0)
			{
				strcpy_s(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue, "");
			}
			if (strlen(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue) > 0)
			{
				strcpy_s(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue, "");
			}
			if (strlen(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue) > 0)
			{
				strcpy_s(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue, "");
			}
			return;
		}

	}


	return;
}


void cDangKyTaiKhoan::RequestRegister()
{
	char szID[MAX_ID_SIZE + 1] = { 0, };
	char szPass1[MAX_PASSWORD_SIZE + 1] = { 0, };
	char szPass2[MAX_PASSWORD_SIZE + 1] = { 0, };
	//sprInputBox->GetText(szID, MAX_ID_SIZE + 1);
	//sprInputBoxPass1->GetText(szPass1, MAX_PASSWORD_SIZE + 1);
	//sprInputBoxPass2->GetText(szPass2, MAX_PASSWORD_SIZE + 1);

	if (strlen(szID) <= 0)
	{
		PopUpMsgWin(CharMakeWin(), 91, GlobalText(GlobalLine, 403));
	}
	else if (strlen(szID) < 4)
	{
		PopUpMsgWin(CharMakeWin(), 91, GlobalText(GlobalLine, 390));
	}
	else if (strlen(szPass1) <= 0)
	{
		PopUpMsgWin(CharMakeWin(), 91, GlobalText(GlobalLine, 404));
	}
	else if (strlen(szPass2) <= 0)
	{
		PopUpMsgWin(CharMakeWin(), 91, GlobalText(GlobalLine, 404));
	}
	else
	{
		if (strcmp(szPass1, szPass2))
		{
			PopUpMsgWin(CharMakeWin(), 91, "las contraseñas no coinciden");
		}
		else
		{
			if (CheckName(szID))
			{
				PopUpMsgWin(CharMakeWin(), 91, GlobalText(GlobalLine, 1715));
			}
			else
			{
				PopUpMsgWin(CharMakeWin(), 93, 0);
			}
		}
	}
}


//__declspec(naked) void DangKyTaiKhoan()
//{
//	// day la bang giao dien
//	// chỗ ghi chữ đâu
//	gInterface.Data[OBJECT_DANGKY_MAIN].Open();
//	//---------------------------------------------
//	gCentral.PrintDropBox(450, 50, 180, 200, 0, 0);
//	//---------------------------------------------
//	gInterface.DrawFormat(eGold, 490, 54, 250, 1, "Đăng ký máy chủ Thần Long");
//	//---------------------------------------------
//	if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	{
//		if (strlen(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue) == 0)
//			sprintf(gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue, "NONE");
//	}
//	gInterface.DrawGUI(OBJECT_DANGKY_TAIKHOAN, 455, 80);
//	if (gInterface.Data[OBJECT_DANGKY_TAIKHOAN].Attribute == 1)
//	{
//		gInterface.DrawColoredGUI(OBJECT_DANGKY_TAIKHOAN, 455, 80, eYellow);
//	}
//	gInterface.DrawText(eWhite, 460, 86, 200, 1, "Tài Khoản");
//	gInterface.DrawText(eExcellent, 470, 86, 200, 3, gInterface.Data[OBJECT_DANGKY_TAIKHOAN].StatValue); // chỗ này là thêm à 
//	//---------------------------------------------
//	//---------------------------------------------
//	if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	{
//		if (strlen(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue) == 0)
//			sprintf(gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue, "NONE");
//	}
//	gInterface.DrawGUI(OBJECT_DANGKY_MATKHAU, 455, 100);
//	if (gInterface.Data[OBJECT_DANGKY_MATKHAU].Attribute == 1)
//	{
//		gInterface.DrawColoredGUI(OBJECT_DANGKY_MATKHAU, 455, 100, eYellow);
//	}
//	gInterface.DrawText(eWhite, 460, 106, 200, 1, "Mật Khẩu");
//	gInterface.DrawText(eExcellent, 470, 106, 200, 3, gInterface.Data[OBJECT_DANGKY_MATKHAU].StatValue);
//	//---------------------------------------------
//	//---------------------------------------------
//	//if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	//{
//	//	if (strlen(gInterface.Data[OBJECT_DANGKY_TEN].StatValue) == 0)
//	//		sprintf(gInterface.Data[OBJECT_DANGKY_TEN].StatValue, "NONE");
//	//}
//	//gInterface.DrawGUI(OBJECT_DANGKY_TEN, 455, 120);
//	//if (gInterface.Data[OBJECT_DANGKY_TEN].Attribute == 1)
//	//{
//	//	gInterface.DrawColoredGUI(OBJECT_DANGKY_TEN, 455, 120, eYellow);
//	//}
//	//gInterface.DrawText(eWhite, 460, 126, 200, 1, "Họ và Tên");
//	//gInterface.DrawText(eExcellent, 470, 126, 200, 3, gInterface.Data[OBJECT_DANGKY_TEN].StatValue);
//	////---------------------------------------------
//	////---------------------------------------------
//	//if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	//{
//	//	if (strlen(gInterface.Data[OBJECT_DANGKY_PHONE].StatValue) == 0)
//	//		sprintf(gInterface.Data[OBJECT_DANGKY_PHONE].StatValue, "NONE");
//	//}
//	//gInterface.DrawGUI(OBJECT_DANGKY_PHONE, 455, 140);
//	//if (gInterface.Data[OBJECT_DANGKY_PHONE].Attribute == 1)
//	//{
//	//	gInterface.DrawColoredGUI(OBJECT_DANGKY_PHONE, 455, 140, eYellow);
//	//}
//	//gInterface.DrawText(eWhite, 460, 146, 200, 1, "Số điện thoại");
//	//gInterface.DrawText(eExcellent, 470, 146, 200, 3, gInterface.Data[OBJECT_DANGKY_PHONE].StatValue);
//	//---------------------------------------------
//	//---------------------------------------------
//	if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	{
//		if (strlen(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue) == 0)
//			sprintf(gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue, "NONE");
//	}
//	gInterface.DrawGUI(OBJECT_DANGKY_SOBIMAT, 455, 160);
//	if (gInterface.Data[OBJECT_DANGKY_SOBIMAT].Attribute == 1)
//	{
//		gInterface.DrawColoredGUI(OBJECT_DANGKY_SOBIMAT, 455, 160, eYellow);
//	}
//	gInterface.DrawText(eWhite, 460, 166, 200, 1, "7 Số bí mật");
//	gInterface.DrawText(eExcellent, 470, 166, 200, 3, gInterface.Data[OBJECT_DANGKY_SOBIMAT].StatValue);
//	//---------------------------------------------
//	//---------------------------------------------
//	//if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	//{
//	//	if (strlen(gInterface.Data[OBJECT_DANGKY_EMAIL].StatValue) == 0)
//	//		sprintf(gInterface.Data[OBJECT_DANGKY_EMAIL].StatValue, "NONE");
//	//}
//	//gInterface.DrawGUI(OBJECT_DANGKY_EMAIL, 455, 180);
//	//if (gInterface.Data[OBJECT_DANGKY_EMAIL].Attribute == 1)
//	//{
//	//	gInterface.DrawColoredGUI(OBJECT_DANGKY_EMAIL, 455, 180, eYellow);
//	//}
//	//gInterface.DrawText(eWhite, 460, 186, 200, 1, "Email @gmail.com");
//	//gInterface.DrawText(eExcellent, 470, 186, 200, 3, gInterface.Data[OBJECT_DANGKY_EMAIL].StatValue);
//	//---------------------------------------------
//	//---------------------------------------------
//	gInterface.DrawGUI(OBJECT_DANGKY_DONGY, 490, 210);
//	gInterface.DrawText(eWhite, 525, 217, 200, 1, "Đăng Ký");
//	if (gInterface.IsWorkZone(OBJECT_DANGKY_DONGY))
//	{
//		DWORD Color = eGray150;
//		gInterface.DrawColoredGUI(OBJECT_DANGKY_DONGY, gInterface.Data[OBJECT_DANGKY_DONGY].X, gInterface.Data[OBJECT_DANGKY_DONGY].Y, Color);
//	}
//	//---------------------------------------------
//	//---------------------------------------------
//	if (gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad == true)
//	{
//		gInterface.Data[OBJECT_DANGKY_MAIN].FirstLoad = false;
//	}
//	//---------------------------------------------
//	static DWORD	Test_Buff;
//	static char		Test_LevelBuff[40];
//	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 470, 200, 3, "Văn Thành - SDT/Zalo : 0782229639");
//	_asm
//	{
//		lea eax, Test_LevelBuff
//			push eax
//	}
//	_asm
//	{
//		mov Test_Buff, 0x004D7D1D
//			jmp Test_Buff
//	}
//	//---------------------------------------------
//}

void RenderInformacion()
{
	if (CurrentProtocolState == 2)
	{
		gDangKyTaiKhoan.draw_dangky_window(); // thay vào
	}

	RenderInfomationR();
}

void cDangKyTaiKhoan::load()
{
	SetCompleteHook(0xE8, 0x004D7EB1, &RenderInformacion);
	
	//	MemorySet(0x004D7DAD, 0x90, 0x0F);
	//	SetCompleteHook(0xE9, 0x004D7D13, &DangKyTaiKhoan);
	
}

#endif