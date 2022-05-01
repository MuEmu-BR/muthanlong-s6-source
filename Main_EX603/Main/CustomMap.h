// CustomMap.h: interface for the CCustomMap class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_MAP 150

struct CUSTOM_MAPS_INFO
{
	int MapNumber;
	char Name[32];
	char MusicFile[32];
};

class CCustomMap
{
public:
	CCustomMap();
	virtual ~CCustomMap();
	void Load(CUSTOM_MAPS_INFO* info);
	void SetInfo(CUSTOM_MAPS_INFO info);
	CUSTOM_MAPS_INFO* GetInfo(int index);
private:
	std::map<int,CUSTOM_MAPS_INFO> m_CustomMapInfo;
};

extern CCustomMap gCustomMap;