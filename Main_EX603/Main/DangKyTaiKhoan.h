#pragma once

#if(DKTK1 == 1)

#include "Protocol.h"

#define CurrentProtocolState			*(int*)0x87935A4

//struct PMSG_SEND_PARTYSEARCH_ADD
//{
//	PSBMSG_HEAD header;
//	bool SystemActive;
//	bool OnlyGuild;
//	bool OnlyAlliance;
//	bool OneClass;
//	bool DarkWizard;
//	bool DarkKnight;
//	bool Elf;
//	bool MagicGladiator;
//	bool DarkLord;
//	bool Summoner;
//	bool RageFighter;
//	int Level;
//	bool RequirePassword;
//	char Password[20];
//};
//
//struct PMSG_PARTYSETTINGS_RECV
//{
//	PSBMSG_HEAD header;
//	bool SystemActive;
//	bool OnlyGuild;
//	bool OnlyAlliance;
//	bool OneClass;
//	bool DarkWizard;
//	bool DarkKnight;
//	bool Elf;
//	bool MagicGladiator;
//	bool DarkLord;
//	bool Summoner;
//	bool RageFighter;
//	int Level;
//	bool RequiredPassword;
//	char Password[20];
//};

#define MAX_ID_SIZE								10
#define MAX_PERSONAL_SIZE						14
#define MAX_PASSWORD_SIZE						20
#define SIZE_PROTOCOLVERSION					( 5)
#define SIZE_PROTOCOLSERIAL						( 16)
//--
#define	REQUEST_JOIN_SERVER						0
#define RECEIVE_JOIN_SERVER_WAITING				1	// 인증서버가 바쁘니 대기하라.
#define	RECEIVE_JOIN_SERVER_SUCCESS				2
#define	RECEIVE_JOIN_SERVER_FAIL_VERSION		3
#define	REQUEST_CREATE_ACCOUNT					10	// 사용안함.
#define	RECEIVE_CREATE_ACCOUNT_SUCCESS			11	// 사용안함.
#define	RECEIVE_CREATE_ACCOUNT_FAIL_ID			12	// 사용안함.
#define	RECEIVE_CREATE_ACCOUNT_FAIL_RESIDENT	13	// 사용안함.

#define CurrentProtocolState			*(int*)0x87935A4

#define CharMakeWin						((int(*)()) 0x00482B70)
#define GlobalLine									(LPVOID)0x008128ADC
#define FindText2						((bool(__cdecl*)(char *Text,char *Token,bool First)) 0x00512DC0)
#define PopUpMsgWin						((void(__thiscall*)(int thisa, int nMsgCode, char* pszMsg)) 0x00484A10)
#define GlobalText									((char*(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)

class cDangKyTaiKhoan
{
public:
	cDangKyTaiKhoan();
	virtual ~cDangKyTaiKhoan();

	void bind();

	void load();

	void draw_dangky_window();

	static void dangky_switch_state();

	void event_dangky_window(DWORD Event);

	void RequestRegister();

	bool showregister;

		char sprInputBox[10];
		char sprInputBoxPass1[10];
		char sprInputBoxPass2[10];

	//void CGSendPartySearchAdd();
	//void GCPartySettingsRecv(PMSG_PARTYSETTINGS_RECV* lpMsg);
	// ----
}; extern cDangKyTaiKhoan gDangKyTaiKhoan;

void Copyright();

#endif