#include "user.h"
#include "Protocol.h"
#pragma once

#if(TAISINH == 1)

struct TAISINH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

struct DieuKienNgoc // ok
{
	int rChaos;
	int rBless;
	int rSoul;
	int rLife;
	int rCre;
};

void TaiSinhCheckDataSend(int aIndex);
void TaiSinhDiemDataSend(int aIndex);
void DieuKienNgoc01DataSend(int aIndex);
void DieuKienNgoc02DataSend(int aIndex);

class TaiSinh
{
public:
	// ----
	TaiSinh();
	virtual ~TaiSinh();
	void Load(char* path);
	// ----
	void		TAISINH_ATIVE(LPOBJ lpObj, TAISINH_REQ *aRecv);

	int m_Enabled;
	int m_TaiSinh;
	int m_TrungSinh;
	int m_DieuKienLevel;

	int DieuKien01;
	int DieuKien02;
	int DieuKien03;
	int DieuKien04;
	int DieuKien05;
	int DieuKien06;
	int DieuKien07;
	int DieuKien08;
	int DieuKien09;
	int DieuKien10;

	int DiemPointTaiSinh01;
	int DiemPointTaiSinh02;
	int DiemPointTaiSinh03;
	int DiemPointTaiSinh04;
	int DiemPointTaiSinh05;
	int DiemPointTaiSinh06;
	int DiemPointTaiSinh07;
	int DiemPointTaiSinh08;
	int DiemPointTaiSinh09;
	int DiemPointTaiSinh10;

	int DiemPointTrungSinh01;
	int DiemPointTrungSinh02;
	int DiemPointTrungSinh03;
	int DiemPointTrungSinh04;
	int DiemPointTrungSinh05;
	int DiemPointTrungSinh06;
	int DiemPointTrungSinh07;
	int DiemPointTrungSinh08;
	int DiemPointTrungSinh09;
	int DiemPointTrungSinh10;

	char Msg01[256];
	char Msg02[256];

	DieuKienNgoc DieuKienNgoc01;
	DieuKienNgoc DieuKienNgoc02;
	DieuKienNgoc DieuKienNgoc03;
	DieuKienNgoc DieuKienNgoc04;
	DieuKienNgoc DieuKienNgoc05;
	DieuKienNgoc DieuKienNgoc06;
	DieuKienNgoc DieuKienNgoc07;
	DieuKienNgoc DieuKienNgoc08;
	DieuKienNgoc DieuKienNgoc09;
	DieuKienNgoc DieuKienNgoc10;

	// ----
}; extern TaiSinh gTaiSinh;

#endif
// -------------------------------------------------------------------------------