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
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_MAPS_INFO info);
public:
	CUSTOM_MAPS_INFO m_CustomMapInfo[MAX_MAP];
};

extern CCustomMap gCustomMap;
