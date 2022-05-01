#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "Achievements.h"
#include "GrandResetSystem.h"
#include "ResetSystem.h"
#include "NewInterface.h"
#include "CustomLuckySpin.h"
#include "JewelBank.h"
#include "CustomThuongGia.h"
#include "ShopSearch.h"
#include "ChoTroi.h"
#include "PartySearch.h"
#include "ControllerTextBox.h"
#include "PartySearchSettings.h"
#include "WindowsQuest.h"
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
#include "User.h"
#include "Ranking.h"
#include "NewUIMyInventory.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;

HHOOK HookKB;
HHOOK HookMS;

#if(DKTK1 == 1)
HHOOK HookDKTK;
#endif
// ----------------------------------------------------------------------------------------------
void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
			JMP dwJmp
	}
}

LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if (GetForegroundWindow() != pGameWindow)
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse = (MOUSEHOOKSTRUCTEX*)lParam;

	gController.wMouse = wParam;

#if(DEV_PLAYERSHOP == 1)
	g_ChoTroi.Mouse(Mouse, wParam);
#endif

	switch (wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
	{
						   //anh them ở daya
						   if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
						   {
							   gController.ProcInterface(wParam);

							   if (gNewInterface.EventAllWindow(wParam, Mouse) == true)
							   {
								   return 1;
							   }
						   }

#if(MUUNAFK == 1)
						   //1-04-2022
						  //g_MuunSystem.MainAll(wParam);
#endif

#if(MENU_NEW == 1)
						   G_BEXO_MENU.MAIN_MENU(wParam);
#endif

#if(TAISINH == 1)
						   G_BEXO_TAISINH.MAIN_TAISINH(wParam);
#endif

#if(DANH_HIEU_NEW == 1)
						   G_BEXO_DANH_HIEU.BEXO_CLICK_TRANG_DANH_HIEU(wParam);
						   G_BEXO_DANH_HIEU.MAIN_DANH_HIEU(wParam);
#endif

#if(TU_LUYEN_NEW == 1)
						   G_BEXO_TU_LUYEN.BEXO_CLICK_TRANG_TU_LUYEN(wParam);
						   G_BEXO_TU_LUYEN.MAIN_TU_LUYEN(wParam);
#endif

#if(THUE_VIP_NEW == 1)
						   G_BEXO_VIPNHANVAT.MAIN_VIPNHANVAT(wParam);
#endif

#if(VIP_TAI_KHOAN_NEW == 1)
						   G_BEXO_VIPTAIKHOAN.MAIN_VIPTAIKHOAN(wParam);
#endif

#if(NGU_HANH_NEW == 1)
						   G_BEXO_NGUHANH.MAIN_NGUHANH(wParam);
#endif

#if(KINH_MACH_NEW == 1)
						   G_BEXO_KINHMACH.MAIN_KINHMACH(wParam);
#endif

#if(VONGQUAY_NEW)
						   gLuckySpin.EventWindow_Main(wParam);
#endif
#if(OFFLINE_MODE_NEW)
						   gInterface.EventOffExpWindow_Main(wParam);
#endif
#if(OANTUTY)
						   gInterface.EventRPS_Main(wParam);
#endif


#if(NGANHANGNGOC_NEW)         			
						   if (gObjUser.NganHangNgoc == 1)
						   {
							   gJewelBank.JewelBankEvent(wParam);
							   gJewelBank.ClickZenMinus(wParam);
							   gJewelBank.ClickZenPlus(wParam);
							   gJewelBank.ClickChaosMinus(wParam);
							   gJewelBank.ClickChaosMinus10(wParam);
							   gJewelBank.ClickChaosMinus20(wParam);
							   gJewelBank.ClickChaosMinus30(wParam);
							   gJewelBank.ClickBlessMinus(wParam);
							   gJewelBank.ClickBlessMinus10(wParam);
							   gJewelBank.ClickBlessMinus20(wParam);
							   gJewelBank.ClickBlessMinus30(wParam);
							   gJewelBank.ClickSoulMinus(wParam);
							   gJewelBank.ClickSoulMinus10(wParam);
							   gJewelBank.ClickSoulMinus20(wParam);
							   gJewelBank.ClickSoulMinus30(wParam);
							   gJewelBank.ClickLifeMinus(wParam);
							   gJewelBank.ClickLifeMinus10(wParam);
							   gJewelBank.ClickLifeMinus20(wParam);
							   gJewelBank.ClickLifeMinus30(wParam);
							   gJewelBank.ClickCreMinus(wParam);
							   gJewelBank.ClickCreMinus10(wParam);
							   gJewelBank.ClickCreMinus20(wParam);
							   gJewelBank.ClickCreMinus30(wParam);
							   gJewelBank.ClickGemMinus(wParam);
							   gJewelBank.ClickGemMinus10(wParam);
							   gJewelBank.ClickGemMinus20(wParam);
							   gJewelBank.ClickGemMinus30(wParam);
							   gJewelBank.ClickGem1Minus(wParam);
							   gJewelBank.ClickGem1Minus10(wParam);
							   gJewelBank.ClickGem1Minus20(wParam);
							   gJewelBank.ClickGem1Minus30(wParam);
							   gJewelBank.ClickGem2Minus(wParam);
							   gJewelBank.ClickGem2Minus10(wParam);
							   gJewelBank.ClickGem2Minus20(wParam);
							   gJewelBank.ClickGem2Minus30(wParam);
							   gJewelBank.ClickGem3Minus(wParam);
							   gJewelBank.ClickGem3Minus10(wParam);
							   gJewelBank.ClickGem3Minus20(wParam);
							   gJewelBank.ClickGem3Minus30(wParam);
							   gJewelBank.ClickGem4Minus(wParam);
							   gJewelBank.ClickGem4Minus10(wParam);
							   gJewelBank.ClickGem4Minus20(wParam);
							   gJewelBank.ClickGem4Minus30(wParam);
						   }
#endif	

						   ///*G_BEXO_THUONG_GIA.BEXO_CLICK_TRANG_THUONG_GIA(wParam);
						   //G_BEXO_THUONG_GIA.MAIN_THUONG_GIA(wParam);*/

#if(CHARACTER_NEW)
						   //if (gObjUser.XoaHomDo == 1)
						   //{
							  // gInterface.EventCharacterWindow_XoaHomDo(wParam);
						   //}
						   if (gObjUser.TinhNang == 1)
						   {
							   gInterface.EventCharacterWindow_TinhNang(wParam);
						   }

#if(DEV_PLAYERSHOP == 1)
						   if (gObjUser.ChoTroi == 1)
						   {
							   gInterface.EventCharacterWindow_ChoTroi(wParam);
						   }
#endif
						   if (gObjUser.MuunPet == 1)
						   {
							   gInterface.EventCharacterWindow_MuunPet(wParam);
						   }

#if(SHOPSEARCH==TRUE)
						   if (gObjUser.TimShop == 1)
						   {
							   gInterface.EventCharacterWindow_Store(wParam);
						   }
#endif

#endif
						   if (gObjUser.TinhNang == 1)
						   {
							   gInterface.EventTinhNangWinDow(wParam);
						   }

#if (SACHTHUOCTINH_NEW)
						   if (gObjUser.SachThuocTinh == 1)
						   {
							   gInterface.EventSachThuocTinhInterface(wParam);
						   }
#endif

#if (PHUKIEN_NEW == 1)
						   if (gObjUser.PhuKien == 1)
						   {
							   gInterface.EventRemovePhuKien1(wParam);
							   gInterface.EventRemovePhuKien2(wParam);
						   }

#endif
						   //===========================================//
#if(RANKINGGOC == 1)
						   gCustomRanking.EventRankingNext(wParam);
						   gCustomRanking.EventRankingBack(wParam);
						   gCustomRanking.EventRankingWindow_Close(wParam);
#endif
						   //===========================================//
						   gCustomEventTime.Button(wParam);

#if(LEOTHAP == 1)
						   gInterface.EventLeoThap_All(wParam);
						   gInterface.EventLeoThap_Main(wParam);
						   gInterface.EventLeoThap_Close(wParam);
#endif

#if(MOCNAP == 1)
						   if (gObjUser.MocNap == 1)
						   {
							   G_BEXO_MOCNAP.MAIN_MOCNAP(wParam);
						   }
#endif

						   gInterface.EventDrawMenu_Open(wParam);

						   gInterface.EventConfirm_CANCEL(wParam);
						   gInterface.EventConfirm_OK(wParam);
						   gCRuudShop.RuudShopEventButton(wParam);
						   gCSCharacterS13.SelectCharButton(wParam);
						   EventMuOffhelper(wParam);

						   if (gCRuudShop.RuudRender.Open)
						   {
							   if (pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1)
							   {
								   gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
								   gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
								   if (wParam == WM_LBUTTONDOWN)
								   {
									   gCRuudShop.RuudRender.Move = 1;
								   }
								   else
								   {
									   gCRuudShop.RuudRender.Move = 0;
								   }
							   }
							   else
							   {
								   gCRuudShop.RuudRender.Move = 0;
							   }
						   }
						   else if (gProtect.m_MainInfo.CustomInterfaceType == 1)
						   {
							   gInterface.EventNewInterface97_All(wParam);
						   }
						   else if (gProtect.m_MainInfo.CustomInterfaceType == 2)
						   {
							   gInterface.EventNewInterface_All(wParam);
						   }
						   gCMacroUIEx.Button(wParam);
						   gOffTrade.EventOffTradeWindow_Main(wParam);
						   gOffTrade.EventCloseTradeWindow_Main(wParam);
	}

		break;
	case WM_MOUSEMOVE:

		gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
			((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
			((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

		if (GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.Move(Mouse);
		}
		break;
	case WM_MBUTTONDOWN:
		if (GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.SetIsMove(1);
			gCamera.SetCursorX(Mouse->pt.x);
			gCamera.SetCursorY(Mouse->pt.y);
		}
		break;
	case WM_MBUTTONUP:
		if (GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.SetIsMove(0);
		}
		break;
	case WM_MOUSEWHEEL:
		if (GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.Zoom(Mouse);
		}
		break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) // OK
{
	if (nCode == HC_ACTION)
	{
		// ----
		if (((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
		{
		
			switch (wParam)
			{

			case VK_END:
			{
						   if (*(int*)0x08793383 != 1)
						   {
							   SetByte((PVOID)0x08793383, 1);
							   pDrawMessage("Hệ thống Auto Train: [Bật]", 1);
						   }
						   else {
							   SetByte((PVOID)0x08793383, 0);
							   pDrawMessage("Hệ thống Auto Train: [Tắt]", 1);
						   }
			}
				break;

			case VK_F10:
			{
						   gInterface.SwitchCamera();
			}
				break;
			case VK_F11:
			{
						   gInterface.CameraInit();
			}
				break;
			case VK_F12:
			{
						   if (gTrayMode.TempWindowProc == NULL)
						   {
							   gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
						   }
						   // ----
						   gTrayMode.SwitchState();
			}
				break;

			case VK_ESCAPE:
			{

#if(RANKINGGOC == 1)

							  if (gCustomRanking.CHECK_WINDOW_RANKING())
							  {
								  gCustomRanking.CLOSE_WINDOW_RANKING();
								  return -1;
							  }
#endif

							  if (gInterface.CheckSachThuocTinhWindow())
							  {
								  gInterface.CloseSachThuocTinhWindow();
								  return -1;
							  }


							  if (gInterface.CheckTinhNangWindow())
							  {
								  gInterface.CloseTinhNangWindow();
								  return -1;
							  }

#if(NGANHANGNGOC_NEW)
							  if (gJewelBank.Check_Window_JewelBank())
							  {
								  gJewelBank.Close_Window_JewelBank();
							  }
#endif

			}
				break;

			default:
				break;
			}
		}

	}

	if (GetForegroundWindow() == pGameWindow && pPlayerState == GameProcess)
	{
		if (nCode == HC_ACTION)
		{
			if (((lParam >> 31) & 1))
			{
#if(DEV_PLAYERSHOP)
				g_ChoTroi.Keyboard(wParam);
#endif
			}
		}
	}


	return CallNextHookEx(HookKB, nCode, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------
#if(DKTK1 == 1)
LRESULT CALLBACK KeyboardDangKy(int Code, WPARAM wParam, LPARAM lParam) // OK
{

	if ((Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);

		if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW) && pPlayerState == SelectServer)
		{
			if (gTextBoxController.ControlTextBox(Hook))
			{
				return 1;
			}
		}
		switch (Hook.vkCode)
		{
		default:
			break;
		}
	}
	return (LRESULT)NULL;

}
#endif

LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{

	case TRAYMODE_ICON_MESSAGE:
	{
								  switch (lParam)
								  {
								  case WM_LBUTTONDBLCLK:
								  {
														   gTrayMode.SwitchState();
								  }
									  break;
								  }
	}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


void Controller::ProcInterface(WPARAM wParam)
{

#if(NHIEMVU_NEW == 1)
	if (gObjUser.NhiemVu == 1)
	{
		g_ExWinQuestSystem.Button(wParam);
	}
#endif

#if (ARCHIVEMENT == 1)
	if (gObjUser.ThanhTuu == 1)
	{
		gAchievements.Button(wParam);
	}
#endif

#if(SHOPSEARCH==TRUE)
	if (gObjUser.TimShop == 1)
	{
		g_PersonalShopEx.Button(wParam);
	}
#endif

	if (gObjUser.DoiClass == 1)
	{
		gInterface.EventChangingClassWindow_Main(wParam);
	}

	if (gObjUser.TaoNhom == 1)
	{
		gPartySearchSettings.event_party_search_settings_window(wParam);
	}

	if (gObjUser.TimNhom == 1)
	{
		gPartySearch.event_party_search_window(wParam);
		gPartySearch.event_party_search_password_window(wParam);
	}

	gInterface.EventWarehouseWindow_Main(wParam);

#if(DKTK1 == 1)
	gDangKyTaiKhoan.event_dangky_window(wParam);
#endif

#if(RANKING_NEW == 1)
	gRanking.ClickRanking(wParam);
#endif



	if (wParam == WM_LBUTTONUP)
	{
		for (int i = 0; i<eMAX_VALUE; i++)
		{
			gInterface.Data[i].OnClick = false;
		}
	}

}


void Controller::Load(HINSTANCE Instance)
{
	HookKB = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, Instance, GetCurrentThreadId());

#if(DKTK1 == 1)
	HookDKTK = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardDangKy, gController.Instance, NULL);
#endif

	if (!this->MouseHook)
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if (!this->MouseHook)
		{
			return;
		}
	}
	// ----
	if (!this->KeyboardHook)
	{

	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return;

}