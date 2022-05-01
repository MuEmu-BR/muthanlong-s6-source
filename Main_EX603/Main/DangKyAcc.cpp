#include "stdafx.h"
#include "DangKyAcc.h"

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

void CLoginMainWin::RequestRegister()
{
	char szID[MAX_ID_SIZE + 1] = { 0, };
	char szPass1[MAX_PASSWORD_SIZE + 1] = { 0, };
	char szPass2[MAX_PASSWORD_SIZE + 1] = { 0, };
	sprInputBox->GetText(szID, MAX_ID_SIZE + 1);
	sprInputBoxPass1->GetText(szPass1, MAX_PASSWORD_SIZE + 1);
	sprInputBoxPass2->GetText(szPass2, MAX_PASSWORD_SIZE + 1);

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

SetDword(0x0040C989 + 3, 1);