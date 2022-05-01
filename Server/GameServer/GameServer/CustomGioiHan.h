// GioiHan.h: interface for the CGioiHan class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"
#include "Protocol.h"

#if(CUSTOM_GIOIHAN == 1)

struct GIOIHAN_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int BloodCastle;
	int DevilSquare;
	int ChaosCastle;
};

struct GIOIHAN_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
// -------------------------------------------------------------------------------
struct GIOIHAN_DG_GET_DATA
{
	PSBMSG_HEAD	header;
	WORD	index;
	int BloodCastle;
	int DevilSquare;
	int ChaosCastle;
};

class CCustomGioiHan
{
public:
	CCustomGioiHan();
	virtual ~CCustomGioiHan();

	void Load(char* path);

	void		GDSaveData(int aIndex);
	void		GDReqData(int aIndex);
	void		GDSaveUserInfo(int aIndex);
	void		GDReqUserInfo(int aIndex);
	void		DGGetData(GIOIHAN_DG_GET_DATA * aRecv);

public:

	int m_BloodCastle;
	int m_DevilSquare;
	int m_ChaosCastle;

	int m_BloodCastleCount;
	int m_DevilSquareCount;
	int m_ChaosCastleCount;

	char Msg01[256];
	char Msg02[256];
	char Msg03[256];
	char Msg04[256];
	char Msg05[256];
	char Msg06[256];

};

extern CCustomGioiHan gCustomGioiHan;

#endif