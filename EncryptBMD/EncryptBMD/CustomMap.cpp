// CustomMap.cpp: interface for the CCustomMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomMap.h"
#include "MemScript.h"

CCustomMap gCustomMap;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomMap::CCustomMap() // OK
{
	this->Init();
}

CCustomMap::~CCustomMap() // OK
{

}

void CCustomMap::Init() // OK
{
	for (int n = 0; n < MAX_MAP; n++)
	{
		this->m_CustomMapInfo[n].MapNumber = -1;
	}
}

void CCustomMap::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_MAPS_INFO info;

			memset(&info, 0, sizeof(info));

			info.MapNumber = lpMemScript->GetNumber();

			strcpy_s(info.Name, lpMemScript->GetAsString());

			strcpy_s(info.MusicFile, lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch (...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CCustomMap::SetInfo(CUSTOM_MAPS_INFO info) // OK
{
	if (info.MapNumber < 0 || info.MapNumber >= MAX_MAP)
	{
		return;
	}

	this->m_CustomMapInfo[info.MapNumber] = info;
}
