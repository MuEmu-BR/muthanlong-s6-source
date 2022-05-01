#include "user.h"
#include "Protocol.h"
#pragma once
#if(DANHHIEU_NEW == 1)
// -------------------------------------------------------------------------------
struct BUY_DANH_HIEU_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------

void DanhHieuDataSend(int aIndex);

class DanhHieu
{
public:
	// ----
	DanhHieu();
	virtual ~DanhHieu();
	// ----
	void		BUY_DANH_HIEU(LPOBJ lpObj, BUY_DANH_HIEU_REQ *aRecv);
	// ----
	void		DANH_HIEU_OPTION(LPOBJ lpObj, bool flag);
	// ----
	void	    LOAD_TXT();
	// ----
	int         DANH_HIEU_WCOINC_01;
	int         DANH_HIEU_WCOINC_02;
	int         DANH_HIEU_WCOINC_03;
	int         DANH_HIEU_WCOINC_04;
	int         DANH_HIEU_WCOINC_05;
	int         DANH_HIEU_WCOINC_06;
	int         DANH_HIEU_WCOINC_07;
	int         DANH_HIEU_WCOINC_08;
	int         DANH_HIEU_WCOINC_09;
	int         DANH_HIEU_WCOINC_10;
	int         DANH_HIEU_WCOINC_11;
	int         DANH_HIEU_WCOINC_12;
	int         DANH_HIEU_WCOINC_13;
	int         DANH_HIEU_WCOINC_14;
	int         DANH_HIEU_WCOINC_15;
	int         DANH_HIEU_WCOINC_16;

	int         DANH_HIEU_SAT_THUONG_01;
	int         DANH_HIEU_SAT_THUONGX2_01;
	int         DANH_HIEU_PHONG_THU_01;
	int         DANH_HIEU_THE_LUC_01;
	int         DANH_HIEU_SD_01;

	int         DANH_HIEU_SAT_THUONG_02;
	int         DANH_HIEU_SAT_THUONGX2_02;
	int         DANH_HIEU_PHONG_THU_02;
	int         DANH_HIEU_THE_LUC_02;
	int         DANH_HIEU_SD_02;

	int         DANH_HIEU_SAT_THUONG_03;
	int         DANH_HIEU_SAT_THUONGX2_03;
	int         DANH_HIEU_PHONG_THU_03;
	int         DANH_HIEU_THE_LUC_03;
	int         DANH_HIEU_SD_03;

	int         DANH_HIEU_SAT_THUONG_04;
	int         DANH_HIEU_SAT_THUONGX2_04;
	int         DANH_HIEU_PHONG_THU_04;
	int         DANH_HIEU_THE_LUC_04;
	int         DANH_HIEU_SD_04;

	int         DANH_HIEU_SAT_THUONG_05;
	int         DANH_HIEU_SAT_THUONGX2_05;
	int         DANH_HIEU_PHONG_THU_05;
	int         DANH_HIEU_THE_LUC_05;
	int         DANH_HIEU_SD_05;

	int         DANH_HIEU_SAT_THUONG_06;
	int         DANH_HIEU_SAT_THUONGX2_06;
	int         DANH_HIEU_PHONG_THU_06;
	int         DANH_HIEU_THE_LUC_06;
	int         DANH_HIEU_SD_06;

	int         DANH_HIEU_SAT_THUONG_07;
	int         DANH_HIEU_SAT_THUONGX2_07;
	int         DANH_HIEU_PHONG_THU_07;
	int         DANH_HIEU_THE_LUC_07;
	int         DANH_HIEU_SD_07;

	int         DANH_HIEU_SAT_THUONG_08;
	int         DANH_HIEU_SAT_THUONGX2_08;
	int         DANH_HIEU_PHONG_THU_08;
	int         DANH_HIEU_THE_LUC_08;
	int         DANH_HIEU_SD_08;

	int         DANH_HIEU_SAT_THUONG_09;
	int         DANH_HIEU_SAT_THUONGX2_09;
	int         DANH_HIEU_PHONG_THU_09;
	int         DANH_HIEU_THE_LUC_09;
	int         DANH_HIEU_SD_09;

	int         DANH_HIEU_SAT_THUONG_10;
	int         DANH_HIEU_SAT_THUONGX2_10;
	int         DANH_HIEU_PHONG_THU_10;
	int         DANH_HIEU_THE_LUC_10;
	int         DANH_HIEU_SD_10;

	int         DANH_HIEU_SAT_THUONG_11;
	int         DANH_HIEU_SAT_THUONGX2_11;
	int         DANH_HIEU_PHONG_THU_11;
	int         DANH_HIEU_THE_LUC_11;
	int         DANH_HIEU_SD_11;

	int         DANH_HIEU_SAT_THUONG_12;
	int         DANH_HIEU_SAT_THUONGX2_12;
	int         DANH_HIEU_PHONG_THU_12;
	int         DANH_HIEU_THE_LUC_12;
	int         DANH_HIEU_SD_12;

	int         DANH_HIEU_SAT_THUONG_13;
	int         DANH_HIEU_SAT_THUONGX2_13;
	int         DANH_HIEU_PHONG_THU_13;
	int         DANH_HIEU_THE_LUC_13;
	int         DANH_HIEU_SD_13;

	int         DANH_HIEU_SAT_THUONG_14;
	int         DANH_HIEU_SAT_THUONGX2_14;
	int         DANH_HIEU_PHONG_THU_14;
	int         DANH_HIEU_THE_LUC_14;
	int         DANH_HIEU_SD_14;

	int         DANH_HIEU_SAT_THUONG_15;
	int         DANH_HIEU_SAT_THUONGX2_15;
	int         DANH_HIEU_PHONG_THU_15;
	int         DANH_HIEU_THE_LUC_15;
	int         DANH_HIEU_SD_15;

	int         DANH_HIEU_SAT_THUONG_16;
	int         DANH_HIEU_SAT_THUONGX2_16;
	int         DANH_HIEU_PHONG_THU_16;
	int         DANH_HIEU_THE_LUC_16;
	int         DANH_HIEU_SD_16;
	// ----
}; extern DanhHieu gDanhHieu;

#endif
// -------------------------------------------------------------------------------