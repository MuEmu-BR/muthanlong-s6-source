// CustomMap.cpp: implementation of the CCustomMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomMap.h"

CCustomMap gCustomMap;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomMap::CCustomMap() // OK
{
	this->m_CustomMapInfo.clear();
}

CCustomMap::~CCustomMap() // OK
{

}

void CCustomMap::Load(CUSTOM_MAPS_INFO* info) // OK
{
	for(int n=0;n < MAX_MAP;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomMap::SetInfo(CUSTOM_MAPS_INFO info) // OK
{
	if(info.MapNumber < 0 || info.MapNumber >= MAX_MAP)
	{
		return;
	}

	this->m_CustomMapInfo.insert(std::pair<int, CUSTOM_MAPS_INFO>(info.MapNumber, info));
}

CUSTOM_MAPS_INFO* CCustomMap::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_MAP)
	{
		return 0;
	}

	std::map<int,CUSTOM_MAPS_INFO>::iterator it = this->m_CustomMapInfo.find(index);

	if(it == this->m_CustomMapInfo.end())
	{
		return 0;
	}
	

	return &it->second;
}