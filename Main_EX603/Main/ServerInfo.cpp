#include "stdafx.h"
#include "ServerInfo.h"
#include "Camera.h"
#include "PartySearch.h"
#include "MiniMap.h"
#include "Interface.h"
#include "TMemory.h"

CServerInfo gServerInfo;

CServerInfo::CServerInfo()
{

}

void CServerInfo::Load()
{
}

void CServerInfo::RecvServerInfo(PMSG_SERVER_INFO_RECV* Data)
{
	for (int i = 0; i < MAX_ACCOUNT_LEVEL; i++)
	{
		this->m_custom_char_interface_[i] = Data->CustomCharInterface[i];
		this->m_max_stat_point_[i] = Data->MaxStatPoint[i];
		gPartySearch.CanOpenSettings[i] = Data->CanOpenSettings[i];
		gPartySearch.CanOpenMain[i] = Data->CanOpenMain[i];
	}
	this->AnimatedWarehouse = Data->CustomWarehouseAnimated;

	this->m_strength_ = Data->Strength;
	this->m_dexterity_ = Data->Dexterity;
	this->m_vitality_ = Data->Vitality;
	this->m_energy_ = Data->Energy;
	this->m_leadership_ = Data->Leadership;
	this->m_PartyTeleportSwitch = Data->PartyTeleportSwitch;
	this->m_PartyTeleportMoney = Data->PartyTeleportMoney;

}

int CServerInfo::get_char_interface(int AccountLevel)
{
	return this->m_custom_char_interface_[AccountLevel];
}

int CServerInfo::get_max_stat_point(int AccountLevel)
{
	return this->m_max_stat_point_[AccountLevel];
}
