// CustomGioiHan.cpp: implementation of the CCustomGioiHan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomGioiHan.h"
#include "CommandManager.h"
#include "EffectManager.h"
#include "GameMain.h"
#include "ItemManager.h"
#include "Util.h"
#include "Map.h"
#include "MapManager.h"
#include "MasterSkillTree.h"
#include "Message.h"
#include "Notice.h"
#include "Party.h"
#include "SkillManager.h"
#include "SocketManager.h"
#include "Viewport.h"
#include "FakeOnline.h"
#include "CustomOfflineMode.h"
#include "ServerInfo.h"

#if(CUSTOM_GIOIHAN == 1)

CCustomGioiHan gCustomGioiHan;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomGioiHan::CCustomGioiHan() // OK
{

}

CCustomGioiHan::~CCustomGioiHan() // OK
{

}

//===============================================================================================================================
void CCustomGioiHan::GDSaveData(int aIndex)
{
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	GIOIHAN_GD_SAVE_DATA pRequest;
	pRequest.header.set(0xB0, 0x06, sizeof(pRequest));
	memcpy(pRequest.Name, lpUser->Name, 11);
	pRequest.index = aIndex;
	//----
	pRequest.BloodCastle = lpUser->GIOIHAN.BloodCastle;
	pRequest.DevilSquare = lpUser->GIOIHAN.DevilSquare;
	pRequest.ChaosCastle = lpUser->GIOIHAN.ChaosCastle;
	//----
	gDataServerConnection.DataSend((BYTE*)&pRequest, pRequest.header.size);
}
// -------------------------------------------------------------------------------
void CCustomGioiHan::GDReqData(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	GIOIHAN_GD_REQ_DATA pMsg;
	pMsg.header.set(0xB0, 0x05, sizeof(pMsg));
	pMsg.index = aIndex;
	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}
// -------------------------------------------------------------------------------
void CCustomGioiHan::GDSaveUserInfo(int aIndex)	//-> Complete
{
	this->GDSaveData(aIndex);
}
// -------------------------------------------------------------------------------
void CCustomGioiHan::GDReqUserInfo(int aIndex)	//-> Complete
{
	// ----
	this->GDReqData(aIndex);
}
// -------------------------------------------------------------------------------
void CCustomGioiHan::DGGetData(GIOIHAN_DG_GET_DATA * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->index];
	// ----

	if (aRecv->BloodCastle < 0)
	{
		aRecv->BloodCastle = 0;
	}
	else if (aRecv->DevilSquare < 0)
	{
		aRecv->DevilSquare = 0;
	}
	else if (aRecv->ChaosCastle < 0)
	{
		aRecv->ChaosCastle = 0;
	}
	// ----
	lpUser->GIOIHAN.BloodCastle = aRecv->BloodCastle;
	lpUser->GIOIHAN.DevilSquare = aRecv->DevilSquare;
	lpUser->GIOIHAN.ChaosCastle = aRecv->ChaosCastle;
	//----
}
// -------------------------------------------------------------------------------

void CCustomGioiHan::Load(char* path) // OK
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok)
	{
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}

	//--
	pugi::xml_node oGioiHan = file.child("CustomGioiHan");
	//--
	pugi::xml_node eEnabled = oGioiHan.child("Enabled");
	for (pugi::xml_node rEnabled = eEnabled.child("Config"); rEnabled; rEnabled = rEnabled.next_sibling())
	{
		this->m_BloodCastle = rEnabled.attribute("BloodCastle").as_int();
		this->m_DevilSquare = rEnabled.attribute("DevilSquare").as_int();
		this->m_ChaosCastle = rEnabled.attribute("ChaosCastle").as_int();
	}
	//--
	pugi::xml_node eGioiHanCount = oGioiHan.child("GioiHanSoLanThamGia");
	for (pugi::xml_node rGioiHanCount = eGioiHanCount.child("Config"); rGioiHanCount; rGioiHanCount = rGioiHanCount.next_sibling()){

		this->m_BloodCastleCount = rGioiHanCount.attribute("BloodCastleCount").as_int();
		this->m_DevilSquareCount = rGioiHanCount.attribute("DevilSquareCount").as_int();
		this->m_ChaosCastleCount = rGioiHanCount.attribute("ChaosCastleCount").as_int();
	}
	//--
	pugi::xml_node eMSG = oGioiHan.child("ThongBao");
	for (pugi::xml_node rMSG = eMSG.child("Config"); rMSG; rMSG = rMSG.next_sibling()){

		strncpy_s(this->Msg01, rMSG.attribute("Msg1").as_string(), sizeof(this->Msg01));
		strncpy_s(this->Msg02, rMSG.attribute("Msg2").as_string(), sizeof(this->Msg02));
		strncpy_s(this->Msg03, rMSG.attribute("Msg3").as_string(), sizeof(this->Msg03));
		strncpy_s(this->Msg04, rMSG.attribute("Msg4").as_string(), sizeof(this->Msg04));
		strncpy_s(this->Msg05, rMSG.attribute("Msg5").as_string(), sizeof(this->Msg05));
		strncpy_s(this->Msg06, rMSG.attribute("Msg6").as_string(), sizeof(this->Msg06));
	}
}

#endif