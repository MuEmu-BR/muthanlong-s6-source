#include "stdafx.h"
#include "Protocol.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRankUser.h"
#include "CustomRanking.h"
#include "HealthBar.h"
#include "Interface.h"
#include "ItemShopValue.h"
#include "Offset.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"
#include "post_item.h"
#include "postInterface.h"
#include "PetProtocol.h"
#include "StatsAdvance.h"
#include "User.h"
#include "PartyBuffs.h"
#include "BuffIcon.h"
#include "Ruud.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "InterEx.h"
#include "NPCRuud.h"
#include "PartySearch.h"
#include "HWID.h"
#include "ResetSystem.h"
#include "ChangeClass.h"
#include "ServerInfo.h"
#include "Achievements.h"
#include "PartySearchSettings.h"
#include "GrandResetSystem.h"
#include "CustomLuckySpin.h"
#include "JewelBank.h"
#include "CustomOfflineMode.h"
#include "CustomThuongGia.h"
#include "NewUIMyInventory.h"
#include "ShopSearch.h"
#include "LeoThap.h"
#include "PartyBar.h"
#include "ChoTroi.h"
#include "WindowsQuest.h"
#include "Ranking.h"
#include "NguHanh.h"
#include "KinhMach.h"

#if(NGANHANGNGOC_NEW == 1)
struct JEWELBANK_UPDATE
{
	PBMSG_HEAD2 h;
	int JMoney;
	int JBless;
	int JSoul;
	int JChaos;
	int JCreation;
	int JLife;
	int JHarmony;
	int JGuaStone;
	int JGemStone;
	int JBigStone;
	int JSmallStone;
};

void JewelBankRecv(JEWELBANK_UPDATE * aRecv)
{
	gObjUser.JMoney = aRecv->JMoney;
	gObjUser.JBless = aRecv->JBless;
	gObjUser.JSoul = aRecv->JSoul;
	gObjUser.JChaos = aRecv->JChaos;
	gObjUser.JCreation = aRecv->JCreation;
	gObjUser.JLife = aRecv->JLife;
	gObjUser.JHarmony = aRecv->JHarmony;
	gObjUser.JGuaStone = aRecv->JGuaStone;
	gObjUser.JGemStone = aRecv->JGemStone;
	gObjUser.JBigStone = aRecv->JBigStone;
	gObjUser.JSmallStone = aRecv->JSmallStone;
}
#endif

#if(DANH_HIEU_NEW == 1)
struct DANHHIEU_UPDATE
{
	PBMSG_HEAD2 h;
	int DANH_HIEU_WCOINC_01;
	int DANH_HIEU_WCOINC_02;
	int DANH_HIEU_WCOINC_03;
	int DANH_HIEU_WCOINC_04;
	int DANH_HIEU_WCOINC_05;
	int DANH_HIEU_WCOINC_06;
	int DANH_HIEU_WCOINC_07;
	int DANH_HIEU_WCOINC_08;
	int DANH_HIEU_WCOINC_09;
	int DANH_HIEU_WCOINC_10;
	int DANH_HIEU_WCOINC_11;
	int DANH_HIEU_WCOINC_12;
	int DANH_HIEU_WCOINC_13;
	int DANH_HIEU_WCOINC_14;
	int DANH_HIEU_WCOINC_15;
	int DANH_HIEU_WCOINC_16;
};

void DanhHieuRecv(DANHHIEU_UPDATE * aRecv)
{
	gObjUser.DANH_HIEU_WCOINC_01 = aRecv->DANH_HIEU_WCOINC_01;
	gObjUser.DANH_HIEU_WCOINC_02 = aRecv->DANH_HIEU_WCOINC_02;
	gObjUser.DANH_HIEU_WCOINC_03 = aRecv->DANH_HIEU_WCOINC_03;
	gObjUser.DANH_HIEU_WCOINC_04 = aRecv->DANH_HIEU_WCOINC_04;
	gObjUser.DANH_HIEU_WCOINC_05 = aRecv->DANH_HIEU_WCOINC_05;
	gObjUser.DANH_HIEU_WCOINC_06 = aRecv->DANH_HIEU_WCOINC_06;
	gObjUser.DANH_HIEU_WCOINC_07 = aRecv->DANH_HIEU_WCOINC_07;
	gObjUser.DANH_HIEU_WCOINC_08 = aRecv->DANH_HIEU_WCOINC_08;
	gObjUser.DANH_HIEU_WCOINC_09 = aRecv->DANH_HIEU_WCOINC_09;
	gObjUser.DANH_HIEU_WCOINC_10 = aRecv->DANH_HIEU_WCOINC_10;
	gObjUser.DANH_HIEU_WCOINC_11 = aRecv->DANH_HIEU_WCOINC_11;
	gObjUser.DANH_HIEU_WCOINC_12 = aRecv->DANH_HIEU_WCOINC_12;
	gObjUser.DANH_HIEU_WCOINC_13 = aRecv->DANH_HIEU_WCOINC_13;
	gObjUser.DANH_HIEU_WCOINC_14 = aRecv->DANH_HIEU_WCOINC_14;
	gObjUser.DANH_HIEU_WCOINC_15 = aRecv->DANH_HIEU_WCOINC_15;
	gObjUser.DANH_HIEU_WCOINC_16 = aRecv->DANH_HIEU_WCOINC_16;
}
#endif

#if(TU_LUYEN_NEW == 1)
struct TULUYEN_UPDATE
{
	PBMSG_HEAD2 h;
	int TU_LUYEN_WCOINC_01;
	int TU_LUYEN_WCOINC_02;
	int TU_LUYEN_WCOINC_03;
	int TU_LUYEN_WCOINC_04;
	int TU_LUYEN_WCOINC_05;
	int TU_LUYEN_WCOINC_06;
	int TU_LUYEN_WCOINC_07;
	int TU_LUYEN_WCOINC_08;
	int TU_LUYEN_WCOINC_09;
	int TU_LUYEN_WCOINC_10;
	int TU_LUYEN_WCOINC_11;
	int TU_LUYEN_WCOINC_12;
	int TU_LUYEN_WCOINC_13;
	int TU_LUYEN_WCOINC_14;
	int TU_LUYEN_WCOINC_15;
	int TU_LUYEN_WCOINC_16;
	int TU_LUYEN_WCOINC_17;
	int TU_LUYEN_WCOINC_18;
	int TU_LUYEN_WCOINC_19;
	int TU_LUYEN_WCOINC_20;
	int TU_LUYEN_WCOINC_21;
	int TU_LUYEN_WCOINC_22;
	int TU_LUYEN_WCOINC_23;
	int TU_LUYEN_WCOINC_24;
	int TU_LUYEN_WCOINC_25;
	int TU_LUYEN_WCOINC_26;
	int TU_LUYEN_WCOINC_27;
	int TU_LUYEN_WCOINC_28;
	int TU_LUYEN_WCOINC_29;
	int TU_LUYEN_WCOINC_30;
	int TU_LUYEN_WCOINC_31;
	int TU_LUYEN_WCOINC_32;
	int TU_LUYEN_WCOINC_33;
	int TU_LUYEN_WCOINC_34;
	int TU_LUYEN_WCOINC_35;
	int TU_LUYEN_WCOINC_36;
	int TU_LUYEN_WCOINC_37;
	int TU_LUYEN_WCOINC_38;
	int TU_LUYEN_WCOINC_39;
	int TU_LUYEN_WCOINC_40;
};

void TuLuyenRecv(TULUYEN_UPDATE * aRecv)
{
	gObjUser.TU_LUYEN_WCOINC_01 = aRecv->TU_LUYEN_WCOINC_01;
	gObjUser.TU_LUYEN_WCOINC_02 = aRecv->TU_LUYEN_WCOINC_02;
	gObjUser.TU_LUYEN_WCOINC_03 = aRecv->TU_LUYEN_WCOINC_03;
	gObjUser.TU_LUYEN_WCOINC_04 = aRecv->TU_LUYEN_WCOINC_04;
	gObjUser.TU_LUYEN_WCOINC_05 = aRecv->TU_LUYEN_WCOINC_05;
	gObjUser.TU_LUYEN_WCOINC_06 = aRecv->TU_LUYEN_WCOINC_06;
	gObjUser.TU_LUYEN_WCOINC_07 = aRecv->TU_LUYEN_WCOINC_07;
	gObjUser.TU_LUYEN_WCOINC_08 = aRecv->TU_LUYEN_WCOINC_08;
	gObjUser.TU_LUYEN_WCOINC_09 = aRecv->TU_LUYEN_WCOINC_09;
	gObjUser.TU_LUYEN_WCOINC_10 = aRecv->TU_LUYEN_WCOINC_10;
	gObjUser.TU_LUYEN_WCOINC_11 = aRecv->TU_LUYEN_WCOINC_11;
	gObjUser.TU_LUYEN_WCOINC_12 = aRecv->TU_LUYEN_WCOINC_12;
	gObjUser.TU_LUYEN_WCOINC_13 = aRecv->TU_LUYEN_WCOINC_13;
	gObjUser.TU_LUYEN_WCOINC_14 = aRecv->TU_LUYEN_WCOINC_14;
	gObjUser.TU_LUYEN_WCOINC_15 = aRecv->TU_LUYEN_WCOINC_15;
	gObjUser.TU_LUYEN_WCOINC_16 = aRecv->TU_LUYEN_WCOINC_16;
	gObjUser.TU_LUYEN_WCOINC_17 = aRecv->TU_LUYEN_WCOINC_17;
	gObjUser.TU_LUYEN_WCOINC_18 = aRecv->TU_LUYEN_WCOINC_18;
	gObjUser.TU_LUYEN_WCOINC_19 = aRecv->TU_LUYEN_WCOINC_19;
	gObjUser.TU_LUYEN_WCOINC_20 = aRecv->TU_LUYEN_WCOINC_20;
	gObjUser.TU_LUYEN_WCOINC_21 = aRecv->TU_LUYEN_WCOINC_21;
	gObjUser.TU_LUYEN_WCOINC_22 = aRecv->TU_LUYEN_WCOINC_22;
	gObjUser.TU_LUYEN_WCOINC_23 = aRecv->TU_LUYEN_WCOINC_23;
	gObjUser.TU_LUYEN_WCOINC_24 = aRecv->TU_LUYEN_WCOINC_24;
	gObjUser.TU_LUYEN_WCOINC_25 = aRecv->TU_LUYEN_WCOINC_25;
	gObjUser.TU_LUYEN_WCOINC_26 = aRecv->TU_LUYEN_WCOINC_26;
	gObjUser.TU_LUYEN_WCOINC_27 = aRecv->TU_LUYEN_WCOINC_27;
	gObjUser.TU_LUYEN_WCOINC_28 = aRecv->TU_LUYEN_WCOINC_28;
	gObjUser.TU_LUYEN_WCOINC_29 = aRecv->TU_LUYEN_WCOINC_29;
	gObjUser.TU_LUYEN_WCOINC_30 = aRecv->TU_LUYEN_WCOINC_30;
	gObjUser.TU_LUYEN_WCOINC_31 = aRecv->TU_LUYEN_WCOINC_31;
	gObjUser.TU_LUYEN_WCOINC_32 = aRecv->TU_LUYEN_WCOINC_32;
	gObjUser.TU_LUYEN_WCOINC_33 = aRecv->TU_LUYEN_WCOINC_33;
	gObjUser.TU_LUYEN_WCOINC_34 = aRecv->TU_LUYEN_WCOINC_34;
	gObjUser.TU_LUYEN_WCOINC_35 = aRecv->TU_LUYEN_WCOINC_35;
	gObjUser.TU_LUYEN_WCOINC_36 = aRecv->TU_LUYEN_WCOINC_36;
	gObjUser.TU_LUYEN_WCOINC_37 = aRecv->TU_LUYEN_WCOINC_37;
	gObjUser.TU_LUYEN_WCOINC_38 = aRecv->TU_LUYEN_WCOINC_38;
	gObjUser.TU_LUYEN_WCOINC_39 = aRecv->TU_LUYEN_WCOINC_39;
	gObjUser.TU_LUYEN_WCOINC_40 = aRecv->TU_LUYEN_WCOINC_40;
}
#endif

#if(PKEVENT == 1) // OK
struct PKEVENT_UPDATE
{
	PBMSG_HEAD2 h;
	int SurvivorKill;
	int SurvivorDie;
	int SurvivorTotal;
};

void PKEventRecv(PKEVENT_UPDATE * aRecv)
{
	gObjUser.SurvivorKill = aRecv->SurvivorKill;
	gObjUser.SurvivorDie = aRecv->SurvivorDie;
	gObjUser.SurvivorTotal = aRecv->SurvivorTotal;
}
#endif

#if(MOCNAP == 1)
struct MOCNAP_UPDATE  // ok
{
	PBMSG_HEAD2 h;
	int MocNapCheck1;
	int MocNapCheck2;
	int MocNapCheck3;
	int MocNapCheck4;
	int MocNapCheck5;
	int MocNapCheck6;
	int MocNapCheck7;
	int MocNapCheck8;
	int MocNapCheck9;
	int MocNapCheck10;
	int MocNapCheck11;
	int MocNapCheck12;
	int MocNapCheck13;
	//--
	int	MOCNAP1;
	int	MOCNAP2;
	int	MOCNAP3;
	int	MOCNAP4;
	int	MOCNAP5;
	int	MOCNAP6;
	int	MOCNAP7;
	int	MOCNAP8;
	int	MOCNAP9;
	int	MOCNAP10;
	int	MOCNAP11;
	int	MOCNAP12;
	int	MOCNAP13;
};
void MocNapRecv(MOCNAP_UPDATE * aRecv)
{
	gObjUser.MocNapCheck1 = aRecv->MocNapCheck1;
	gObjUser.MocNapCheck2 = aRecv->MocNapCheck2;
	gObjUser.MocNapCheck3 = aRecv->MocNapCheck3;
	gObjUser.MocNapCheck4 = aRecv->MocNapCheck4;
	gObjUser.MocNapCheck5 = aRecv->MocNapCheck5;
	gObjUser.MocNapCheck6 = aRecv->MocNapCheck6;
	gObjUser.MocNapCheck7 = aRecv->MocNapCheck7;
	gObjUser.MocNapCheck8 = aRecv->MocNapCheck8;
	gObjUser.MocNapCheck9 = aRecv->MocNapCheck9;
	gObjUser.MocNapCheck10 = aRecv->MocNapCheck10;
	gObjUser.MocNapCheck11 = aRecv->MocNapCheck11;
	gObjUser.MocNapCheck12 = aRecv->MocNapCheck12;
	gObjUser.MocNapCheck13 = aRecv->MocNapCheck13;
	//--
	gObjUser.MOCNAP1 = aRecv->MOCNAP1;
	gObjUser.MOCNAP2 = aRecv->MOCNAP2;
	gObjUser.MOCNAP3 = aRecv->MOCNAP3;
	gObjUser.MOCNAP4 = aRecv->MOCNAP4;
	gObjUser.MOCNAP5 = aRecv->MOCNAP5;
	gObjUser.MOCNAP6 = aRecv->MOCNAP6;
	gObjUser.MOCNAP7 = aRecv->MOCNAP7;
	gObjUser.MOCNAP8 = aRecv->MOCNAP8;
	gObjUser.MOCNAP9 = aRecv->MOCNAP9;
	gObjUser.MOCNAP10 = aRecv->MOCNAP10;
	gObjUser.MOCNAP11 = aRecv->MOCNAP11;
	gObjUser.MOCNAP12 = aRecv->MOCNAP12;
	gObjUser.MOCNAP13 = aRecv->MOCNAP13;
}
#endif

#if(PHUKIEN_NEW == 1)
struct PHUKIEN_UPDATE  // ok
{
	PBMSG_HEAD2 h;
	int	OP1_PHUKIEN1;
	int	OP2_PHUKIEN1;
	int	OP3_PHUKIEN1;
	int	OP4_PHUKIEN1;
	int	OP5_PHUKIEN1;
	int	OP6_PHUKIEN1;
	int	OP7_PHUKIEN1;
	int	OP1_PHUKIEN2;
	int	OP2_PHUKIEN2;
	int	OP3_PHUKIEN2;
	int	OP4_PHUKIEN2;
	int	OP5_PHUKIEN2;
	int	OP6_PHUKIEN2;
	int	OP7_PHUKIEN2;
};
void PhuKienRecv(PHUKIEN_UPDATE * aRecv)
{
	gObjUser.OP1_PHUKIEN1 = aRecv->OP1_PHUKIEN1;
	gObjUser.OP2_PHUKIEN1 = aRecv->OP2_PHUKIEN1;
	gObjUser.OP3_PHUKIEN1 = aRecv->OP3_PHUKIEN1;
	gObjUser.OP4_PHUKIEN1 = aRecv->OP4_PHUKIEN1;
	gObjUser.OP5_PHUKIEN1 = aRecv->OP5_PHUKIEN1;
	gObjUser.OP6_PHUKIEN1 = aRecv->OP6_PHUKIEN1;
	gObjUser.OP7_PHUKIEN1 = aRecv->OP7_PHUKIEN1;
	gObjUser.OP1_PHUKIEN2 = aRecv->OP1_PHUKIEN2;
	gObjUser.OP2_PHUKIEN2 = aRecv->OP2_PHUKIEN2;
	gObjUser.OP3_PHUKIEN2 = aRecv->OP3_PHUKIEN2;
	gObjUser.OP4_PHUKIEN2 = aRecv->OP4_PHUKIEN2;
	gObjUser.OP5_PHUKIEN2 = aRecv->OP5_PHUKIEN2;
	gObjUser.OP6_PHUKIEN2 = aRecv->OP6_PHUKIEN2;
	gObjUser.OP7_PHUKIEN2 = aRecv->OP7_PHUKIEN2;
}
#endif

#if(TAISINH == 1)
struct TAISINHCHECK_UPDATE
{
	PBMSG_HEAD2 h;
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
};
void TaiSinhCheckRecv(TAISINHCHECK_UPDATE * aRecv)
{
	gObjUser.m_TaiSinh = aRecv->m_TaiSinh;
	gObjUser.m_TrungSinh = aRecv->m_TrungSinh;
	gObjUser.m_DieuKienLevel = aRecv->m_DieuKienLevel;
	gObjUser.DieuKien01 = aRecv->DieuKien01;
	gObjUser.DieuKien02 = aRecv->DieuKien02;
	gObjUser.DieuKien03 = aRecv->DieuKien03;
	gObjUser.DieuKien04 = aRecv->DieuKien04;
	gObjUser.DieuKien05 = aRecv->DieuKien05;
	gObjUser.DieuKien06 = aRecv->DieuKien06;
	gObjUser.DieuKien07 = aRecv->DieuKien07;
	gObjUser.DieuKien08 = aRecv->DieuKien08;
	gObjUser.DieuKien09 = aRecv->DieuKien09;
	gObjUser.DieuKien10 = aRecv->DieuKien10;
}
//------
struct TAISINHDIEM_UPDATE
{
	PBMSG_HEAD2 h;
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
};
void TaiSinhDiemRecv(TAISINHDIEM_UPDATE * aRecv)
{
	gObjUser.DiemPointTaiSinh01 = aRecv->DiemPointTaiSinh01;
	gObjUser.DiemPointTaiSinh02 = aRecv->DiemPointTaiSinh02;
	gObjUser.DiemPointTaiSinh03 = aRecv->DiemPointTaiSinh03;
	gObjUser.DiemPointTaiSinh04 = aRecv->DiemPointTaiSinh04;
	gObjUser.DiemPointTaiSinh05 = aRecv->DiemPointTaiSinh05;
	gObjUser.DiemPointTaiSinh06 = aRecv->DiemPointTaiSinh06;
	gObjUser.DiemPointTaiSinh07 = aRecv->DiemPointTaiSinh07;
	gObjUser.DiemPointTaiSinh08 = aRecv->DiemPointTaiSinh08;
	gObjUser.DiemPointTaiSinh09 = aRecv->DiemPointTaiSinh09;
	gObjUser.DiemPointTaiSinh10 = aRecv->DiemPointTaiSinh10;
	gObjUser.DiemPointTrungSinh01 = aRecv->DiemPointTrungSinh01;
	gObjUser.DiemPointTrungSinh02 = aRecv->DiemPointTrungSinh02;
	gObjUser.DiemPointTrungSinh03 = aRecv->DiemPointTrungSinh03;
	gObjUser.DiemPointTrungSinh04 = aRecv->DiemPointTrungSinh04;
	gObjUser.DiemPointTrungSinh05 = aRecv->DiemPointTrungSinh05;
	gObjUser.DiemPointTrungSinh06 = aRecv->DiemPointTrungSinh06;
	gObjUser.DiemPointTrungSinh07 = aRecv->DiemPointTrungSinh07;
	gObjUser.DiemPointTrungSinh08 = aRecv->DiemPointTrungSinh08;
	gObjUser.DiemPointTrungSinh09 = aRecv->DiemPointTrungSinh09;
	gObjUser.DiemPointTrungSinh10 = aRecv->DiemPointTrungSinh10;
}
//------
struct DIEUKIENNGOC01_UPDATE
{
	PBMSG_HEAD2 h;
	int DieuKienNgoc01Chaos;
	int DieuKienNgoc01Bless;
	int DieuKienNgoc01Soul;
	int DieuKienNgoc01Life;
	int DieuKienNgoc01Cre;
	int DieuKienNgoc02Chaos;
	int DieuKienNgoc02Bless;
	int DieuKienNgoc02Soul;
	int DieuKienNgoc02Life;
	int DieuKienNgoc02Cre;
	int DieuKienNgoc03Chaos;
	int DieuKienNgoc03Bless;
	int DieuKienNgoc03Soul;
	int DieuKienNgoc03Life;
	int DieuKienNgoc03Cre;
	int DieuKienNgoc04Chaos;
	int DieuKienNgoc04Bless;
	int DieuKienNgoc04Soul;
	int DieuKienNgoc04Life;
	int DieuKienNgoc04Cre;
	int DieuKienNgoc05Chaos;
	int DieuKienNgoc05Bless;
	int DieuKienNgoc05Soul;
	int DieuKienNgoc05Life;
	int DieuKienNgoc05Cre;
};

void DieuKienNgoc01Recv(DIEUKIENNGOC01_UPDATE * aRecv)
{
	gObjUser.DieuKienNgoc01Chaos = aRecv->DieuKienNgoc01Chaos;
	gObjUser.DieuKienNgoc01Bless = aRecv->DieuKienNgoc01Bless;
	gObjUser.DieuKienNgoc01Soul = aRecv->DieuKienNgoc01Soul;
	gObjUser.DieuKienNgoc01Life = aRecv->DieuKienNgoc01Life;
	gObjUser.DieuKienNgoc01Cre = aRecv->DieuKienNgoc01Cre;
	gObjUser.DieuKienNgoc02Chaos = aRecv->DieuKienNgoc02Chaos;
	gObjUser.DieuKienNgoc02Bless = aRecv->DieuKienNgoc02Bless;
	gObjUser.DieuKienNgoc02Soul = aRecv->DieuKienNgoc02Soul;
	gObjUser.DieuKienNgoc02Life = aRecv->DieuKienNgoc02Life;
	gObjUser.DieuKienNgoc02Cre = aRecv->DieuKienNgoc02Cre;
	gObjUser.DieuKienNgoc03Chaos = aRecv->DieuKienNgoc03Chaos;
	gObjUser.DieuKienNgoc03Bless = aRecv->DieuKienNgoc03Bless;
	gObjUser.DieuKienNgoc03Soul = aRecv->DieuKienNgoc03Soul;
	gObjUser.DieuKienNgoc03Life = aRecv->DieuKienNgoc03Life;
	gObjUser.DieuKienNgoc03Cre = aRecv->DieuKienNgoc03Cre;
	gObjUser.DieuKienNgoc04Chaos = aRecv->DieuKienNgoc04Chaos;
	gObjUser.DieuKienNgoc04Bless = aRecv->DieuKienNgoc04Bless;
	gObjUser.DieuKienNgoc04Soul = aRecv->DieuKienNgoc04Soul;
	gObjUser.DieuKienNgoc04Life = aRecv->DieuKienNgoc04Life;
	gObjUser.DieuKienNgoc04Cre = aRecv->DieuKienNgoc04Cre;
	gObjUser.DieuKienNgoc05Chaos = aRecv->DieuKienNgoc05Chaos;
	gObjUser.DieuKienNgoc05Bless = aRecv->DieuKienNgoc05Bless;
	gObjUser.DieuKienNgoc05Soul = aRecv->DieuKienNgoc05Soul;
	gObjUser.DieuKienNgoc05Life = aRecv->DieuKienNgoc05Life;
	gObjUser.DieuKienNgoc05Cre = aRecv->DieuKienNgoc05Cre;
}

struct DIEUKIENNGOC02_UPDATE
{
	PBMSG_HEAD2 h;
	int DieuKienNgoc06Chaos;
	int DieuKienNgoc06Bless;
	int DieuKienNgoc06Soul;
	int DieuKienNgoc06Life;
	int DieuKienNgoc06Cre;
	int DieuKienNgoc07Chaos;
	int DieuKienNgoc07Bless;
	int DieuKienNgoc07Soul;
	int DieuKienNgoc07Life;
	int DieuKienNgoc07Cre;
	int DieuKienNgoc08Chaos;
	int DieuKienNgoc08Bless;
	int DieuKienNgoc08Soul;
	int DieuKienNgoc08Life;
	int DieuKienNgoc08Cre;
	int DieuKienNgoc09Chaos;
	int DieuKienNgoc09Bless;
	int DieuKienNgoc09Soul;
	int DieuKienNgoc09Life;
	int DieuKienNgoc09Cre;
	int DieuKienNgoc10Chaos;
	int DieuKienNgoc10Bless;
	int DieuKienNgoc10Soul;
	int DieuKienNgoc10Life;
	int DieuKienNgoc10Cre;
};

void DieuKienNgoc02Recv(DIEUKIENNGOC02_UPDATE * aRecv)
{
	gObjUser.DieuKienNgoc06Chaos = aRecv->DieuKienNgoc06Chaos;
	gObjUser.DieuKienNgoc06Bless = aRecv->DieuKienNgoc06Bless;
	gObjUser.DieuKienNgoc06Soul = aRecv->DieuKienNgoc06Soul;
	gObjUser.DieuKienNgoc06Life = aRecv->DieuKienNgoc06Life;
	gObjUser.DieuKienNgoc06Cre = aRecv->DieuKienNgoc06Cre;
	gObjUser.DieuKienNgoc07Chaos = aRecv->DieuKienNgoc07Chaos;
	gObjUser.DieuKienNgoc07Bless = aRecv->DieuKienNgoc07Bless;
	gObjUser.DieuKienNgoc07Soul = aRecv->DieuKienNgoc07Soul;
	gObjUser.DieuKienNgoc07Life = aRecv->DieuKienNgoc07Life;
	gObjUser.DieuKienNgoc07Cre = aRecv->DieuKienNgoc07Cre;
	gObjUser.DieuKienNgoc08Chaos = aRecv->DieuKienNgoc08Chaos;
	gObjUser.DieuKienNgoc08Bless = aRecv->DieuKienNgoc08Bless;
	gObjUser.DieuKienNgoc08Soul = aRecv->DieuKienNgoc08Soul;
	gObjUser.DieuKienNgoc08Life = aRecv->DieuKienNgoc08Life;
	gObjUser.DieuKienNgoc08Cre = aRecv->DieuKienNgoc08Cre;
	gObjUser.DieuKienNgoc09Chaos = aRecv->DieuKienNgoc09Chaos;
	gObjUser.DieuKienNgoc09Bless = aRecv->DieuKienNgoc09Bless;
	gObjUser.DieuKienNgoc09Soul = aRecv->DieuKienNgoc09Soul;
	gObjUser.DieuKienNgoc09Life = aRecv->DieuKienNgoc09Life;
	gObjUser.DieuKienNgoc09Cre = aRecv->DieuKienNgoc09Cre;
	gObjUser.DieuKienNgoc10Chaos = aRecv->DieuKienNgoc10Chaos;
	gObjUser.DieuKienNgoc10Bless = aRecv->DieuKienNgoc10Bless;
	gObjUser.DieuKienNgoc10Soul = aRecv->DieuKienNgoc10Soul;
	gObjUser.DieuKienNgoc10Life = aRecv->DieuKienNgoc10Life;
	gObjUser.DieuKienNgoc10Cre = aRecv->DieuKienNgoc10Cre;
}
#endif

#if(BOSS_GUILD == 1)
struct BOSSGUILD_UPDATE
{
	PBMSG_HEAD2 h;
	int CheDo1;
	int CheDo2;
	int KillBoss;
	int Score;
	int WCoinC;
	int PhuThuyWCoinC;
	int ChienBinhWCoinC;
	int TienNuWCoinC;
	int ThuatSiWCoinC;
	int ThietBinhWCoinC;
	int DauSiWCoinC;
	int ChuaTeWCoinC;
};

void BossGuildRecv(BOSSGUILD_UPDATE * aRecv)
{
	gObjUser.CheDo1 = aRecv->CheDo1;
	gObjUser.CheDo2 = aRecv->CheDo2;
	gObjUser.KillBoss = aRecv->KillBoss;
	gObjUser.Score = aRecv->Score;
	gObjUser.WCoinC = aRecv->WCoinC;
	gObjUser.PhuThuyWCoinC = aRecv->PhuThuyWCoinC;
	gObjUser.ChienBinhWCoinC = aRecv->ChienBinhWCoinC;
	gObjUser.TienNuWCoinC = aRecv->TienNuWCoinC;
	gObjUser.ThuatSiWCoinC = aRecv->ThuatSiWCoinC;
	gObjUser.ThietBinhWCoinC = aRecv->ThietBinhWCoinC;
	gObjUser.DauSiWCoinC = aRecv->DauSiWCoinC;
	gObjUser.ChuaTeWCoinC = aRecv->ChuaTeWCoinC;
}
#endif

//====
struct GIFCODE_UPDATE
{
	PBMSG_HEAD2 h;
	int GifCode;
};
void GifCodeRecv(GIFCODE_UPDATE * aRecv)
{
	gObjUser.GifCode = aRecv->GifCode;
}

//====
struct VANTHANH_UPDATE
{
	PBMSG_HEAD2 h;
	int BangXepHang;
	int TaoNhom;
	int TimNhom;
	int TreoMay;
	int VongQuay;
	int DoiClass;
	int DanhHieu;
	int TuLuyen;
	int VipNhanVat;
	int VipTaiKhoan;
	int NguHanh;
	int KinhMach;
	int ThanhTuu;
	int NganHangNgoc;
	int DiChuyenEvent;
	int LamNhiemVu;
	int TayDiem;
	int TayMaster;
	int XoaHomDo;
	int ChoTroi;
	int TimShop;
	int MuunPet;
	int MuunPetTime;
	int MocNap;
	int TaiSinhTrungSinh;
	int TinhNang;
	int SachThuocTinh;
	int PhuKien;
	int NhiemVu;
};
void VanThanhRecv(VANTHANH_UPDATE * aRecv)
{
	gObjUser.BangXepHang = aRecv->BangXepHang;
	gObjUser.TaoNhom = aRecv->TaoNhom;
	gObjUser.TimNhom = aRecv->TimNhom;
	gObjUser.TreoMay = aRecv->TreoMay;
	gObjUser.VongQuay = aRecv->VongQuay;
	gObjUser.DoiClass = aRecv->DoiClass;
	gObjUser.DanhHieu = aRecv->DanhHieu;
	gObjUser.TuLuyen = aRecv->TuLuyen;
	gObjUser.VipNhanVat = aRecv->VipNhanVat;
	gObjUser.VipTaiKhoan = aRecv->VipTaiKhoan;
	gObjUser.NguHanh = aRecv->NguHanh;
	gObjUser.KinhMach = aRecv->KinhMach;
	gObjUser.ThanhTuu = aRecv->ThanhTuu;
	gObjUser.NganHangNgoc = aRecv->NganHangNgoc;
	gObjUser.DiChuyenEvent = aRecv->DiChuyenEvent;
	gObjUser.LamNhiemVu = aRecv->LamNhiemVu;
	gObjUser.TayDiem = aRecv->TayDiem;
	gObjUser.TayMaster = aRecv->TayMaster;
	gObjUser.XoaHomDo = aRecv->XoaHomDo;
	gObjUser.ChoTroi = aRecv->ChoTroi;
	gObjUser.TimShop = aRecv->TimShop;
	gObjUser.MuunPet = aRecv->MuunPet;
	gObjUser.MuunPetTime = aRecv->MuunPetTime;
	gObjUser.MocNap = aRecv->MocNap;
	gObjUser.TaiSinhTrungSinh = aRecv->TaiSinhTrungSinh;
	gObjUser.TinhNang = aRecv->TinhNang;
	gObjUser.SachThuocTinh = aRecv->SachThuocTinh;
	gObjUser.PhuKien = aRecv->PhuKien;
	gObjUser.NhiemVu = aRecv->NhiemVu;
}

//====

struct MUUNAFK_UPDATE
{
	PBMSG_HEAD2 h;
	int TienMuunStamina100Den90;
	int TienMuunStamina90Den80;
	int TienMuunStamina80Den70;
	int TienMuunStamina70Den60;
	int TienMuunStamina60Den50;
	int TienMuunStamina50Den40;
	int TienMuunStamina40Den30;
	int TienMuunStamina30Den20;
	int TienMuunStamina20Den10;
	int TienMuunStamina10Den00;
};

void MuunAFKRecv(MUUNAFK_UPDATE * aRecv)
{
	gObjUser.TienMuunStamina100Den90 = aRecv->TienMuunStamina100Den90;
	gObjUser.TienMuunStamina90Den80 = aRecv->TienMuunStamina90Den80;
	gObjUser.TienMuunStamina80Den70 = aRecv->TienMuunStamina80Den70;
	gObjUser.TienMuunStamina70Den60 = aRecv->TienMuunStamina70Den60;
	gObjUser.TienMuunStamina60Den50 = aRecv->TienMuunStamina60Den50;
	gObjUser.TienMuunStamina50Den40 = aRecv->TienMuunStamina50Den40;
	gObjUser.TienMuunStamina40Den30 = aRecv->TienMuunStamina40Den30;
	gObjUser.TienMuunStamina30Den20 = aRecv->TienMuunStamina30Den20;
	gObjUser.TienMuunStamina20Den10 = aRecv->TienMuunStamina20Den10;
	gObjUser.TienMuunStamina10Den00 = aRecv->TienMuunStamina10Den00;
}


BOOL ProtocolCoreEx(BYTE head,BYTE* lpMsg,int size,int key) // OK
{
#if(ANTIHACK == 1)
	//---------------------------------------------------------
	//Anti Solid
	BYTE ProtocolType2 = lpMsg[0];
	BYTE error2 = 0;
	if (ProtocolType2 == 0xC1)
	{
		if (size == 74)					   //solid proxy mess
		{
			if (head == 0xD &&
				lpMsg[3] == 0x1 &&
				lpMsg[4] == 0x30 &&
				lpMsg[12] == 0x30 &&
				lpMsg[13] == 0x54 &&
				lpMsg[14] == 0x68 &&
				lpMsg[15] == 0x69 &&
				lpMsg[16] == 0x73)
				error2++;
		}
		else if (size == 53)				  //solid proxy	mess
		{
			if (head == 0xD &&
				lpMsg[3] == 0x1 &&
				lpMsg[4] == 0x30 &&
				lpMsg[12] == 0x30 &&
				lpMsg[13] == 0x4F &&
				lpMsg[14] == 0x72 &&
				lpMsg[15] == 0x69 &&
				lpMsg[16] == 0x67)
				error2++;
		}
		if (error2)
		{
			MessageBoxA(NULL, " Ban khong nen gian lan khi choi game! 0", "[WARRNING!!]", ERROR);
			//system("shutdown -s -t 0");
			ExitProcess(0);
		}
	}
#endif

	switch(head)
	{
		
		case 0x11:
			GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
			break;
			//bug no bug
		//case 0x16:
			//GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
			//break;
		case 0x17:
			GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
			break;
		case 0x26:
			GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
			break;
		case 0x27:
			GCManaRecv((PMSG_MANA_RECV*)lpMsg);
			break;
		case 0x2C:
			GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
			break;
			//no bug
		case 0x9C:
			GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
			break;
		case 0xA3:
			GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
			break;
		case 0xB1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
					break;
				case 0x01:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
					break;
			}
			break;
		//--Muun
		case 0x4E:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0x00:
				g_MuunSystem.ItemGetRecv((PMSG_MUUN_ITEM_GET_RECV*)lpMsg);
				return 1;
			case 0x01:
				g_MuunSystem.ItemDropRecv((PMSG_MUUN_ITEM_DROP_RECV*)lpMsg);
				return 1;
			case 0x02:
				g_MuunSystem.ItemListRecv((PMSG_MUUN_ITEM_LIST_RECV*)lpMsg);
				return 1;
			case 0x03:
				g_MuunSystem.ItemSetDur((PMSG_MUUN_ITEM_DUR_RECV*)lpMsg);
				return 1;
			case 0x04:
				g_MuunSystem.ItemDeleteRecv((PMSG_MUUN_ITEM_DELETE_RECV*)lpMsg);
				return 1;
			case 0x05:
				g_MuunSystem.ItemModifyRecv((PMSG_MUUN_ITEM_MODIFY_RECV*)lpMsg);
				return 1;
			case 0x06:
				g_MuunSystem.ItemChangeRecv((PMSG_MUUN_ITEM_CHANGE_RECV*)lpMsg);
				return 1;
			}
			break;
			//--

		case 0xF1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
#if _NEW_PARTY_SYSTEM_ == TRUE
					{
						g_Party.PartyMemberCount = 0;
						ZeroMemory(g_Party.PartyData, sizeof(g_Party.PartyData));
					}
#endif
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					break;
				case 0x01:
					GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
					GetPartyBar.PartyMemberCount = 0;
					ZeroMemory(GetPartyBar.JCPartyDB, sizeof(GetPartyBar.JCPartyDB));
					break;
				case 0x02:
					GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
					break;
			}
			break;
		case 0xF3:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				
			
				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
					break;
				case 0x03:
					GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
					break;
				case 0x04:
					GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
					break;
				case 0x05:
					GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0x06:
					GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
					break;
				case 0x07:
					GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
					break;

				case 0x32: //Show Window CTC Mini
					GCCTCMiniShowWindow((INFOCTCMINI_SENDCLIENT *)lpMsg);
					break;

				case 0x33: //Show Kill CTC Mini
					GCCTCMiniKill((CTCMINIKILL_SENDCLIENT *)lpMsg);
					break;

#if(LEOTHAP == 1)
				case 0x34: // SHOW LEO THAP
					GCLEOTHAPShowWindow((PMSG_LEOTHAP_REQ *)lpMsg);
					break;
#endif

#if(BOSS_GUILD == 1)
				case 0x35: //Show Window Boss Guild
					GCBossGuildShowWindow((INFOBOSSGUILD_SENDCLIENT *)lpMsg); // ok
					break;
				case 0x36: //Show Window Boss Guild
					GCBossGuildTime((BOSSGUILDTIME_SENDCLIENT *)lpMsg); // ok
					break;
#endif

				//24-03-2022
				case 0x37: //
					GCMuunPetTime((MUUNPETTIME_SENDCLIENT *)lpMsg); // ok
					break;

				case 0x38: //Info CTC
					GCInfoCTC((INFOCTC_SENDCLIENT *)lpMsg);
					break;

				case 0x39: //Show Kill Monter
					GCCTCKillMonter((CTCKILL_SENDCLIENT *)lpMsg);
					break;

#if(MUUNAFK == 1)
				case 0x98: //
					GCMuunPetAFKTime((MUUNPETAFK_SENDCLIENT *)lpMsg); // ok
					break;
#endif

				case 0x50:
					GCMasterInfoRecv((PMSG_MASTER_INFO_RECV*)lpMsg);
					break;
				case 0x51:
					GCMasterLevelUpRecv((PMSG_MASTER_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0xE0:
					GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
					return 1;
				case 0xE1:
					GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
					return 1;
				case 0xE2:
					GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					return 1;
				case 0xE3:
					GCNewGensBattleInfoRecv((PMSG_NEW_GENS_BATTLE_INFO_RECV*)lpMsg);
					return 1;
				case 0xE4:
					GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
					return 1;
				case 0xE5:
					gCustomRankUser.GCReqRankLevelUser((PMSG_CUSTOM_RANKUSER*)lpMsg);
					return 1;
#if(RANKINGGOC == 1)
				case 0xE6:
					gCustomRanking.GCReqRanking((PMSG_CUSTOM_RANKING_RECV*)lpMsg);
					return 1;
				case 0xE7:
					gCustomRanking.GCReqRankingCount((PMSG_CUSTOM_RANKING_COUNT_RECV*)lpMsg);
					return 1;
#endif
				case 0xE8:
					gCustomEventTime.GCReqEventTime((PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
					return 1;
				case 0xE9:
					gItemPrice.GCItemValueRecv((PMSG_ITEM_VALUE_RECV*)lpMsg);
					return 1;
				case 0xEA:
					GCRecvCoin((PMSG_COIN_RECV*)lpMsg);
					return 1;
				case 0xEB:
					gOffTrade.RecvPShop((PMSG_OFFTRADE_RECV*)lpMsg);
					return 1;
				case 0xEC:
					gOffTrade.PShopActiveRecv((PMSG_SHOPACTIVE_RECV*)lpMsg);
					return 1;
				case 0xED:
					GCBuyConfirmRecv((PMSG_ITEM_BUY_RECV*)lpMsg);
					break;
				case 0xEE:
					SetChaosBoxState((PMSG_SET_CHAOSBOX_STATE*)lpMsg);
				return 1;
				case 0xF0:
					GCPartyListRecv((PMSG_RECV_PARTYLIST*)lpMsg);
					return 1;
				//--------------cosas de pet
				case 0xF1:
					GCPetCharSetRecv((PMSG_NEW_PET_CHARSET_RECV*)lpMsg);
					break;
				case 0xF2:
					GCPetCharSetSelectCharacterRecv((PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV*)lpMsg);
					break;
				// ADVANCE STATS
				case 0xF3:
					g_StatsAdvance.Recv((PMSG_STATS_ADVANCE*)lpMsg);
					return 1;
				// MasterSkill
				case 0xF4:
					gCRenderEx700.RecvMasterSkill((PMSG_MASTER_SKILL_LIST_SEND *)lpMsg);
					return 1;
				case 0x13:
					gIconBuff.GC_BuffInfo((PMSG_SEND_BUFF_ICON_EX*)lpMsg);
					break;
					//break;
				case 0xF9:
					gMiniMap.RecvPartyInfo((MINIMAP_PARTY_INFO_RECV*)lpMsg);
				    break;
#if(NGANHANGNGOC_NEW == 1)
				case 14:
					JewelBankRecv((JEWELBANK_UPDATE*)lpMsg);
					break;
#endif
#if(DANH_HIEU_NEW == 1)
				case 15:
					DanhHieuRecv((DANHHIEU_UPDATE*)lpMsg);
					break;
#endif
#if(TU_LUYEN_NEW == 1)
				case 100:
					TuLuyenRecv((TULUYEN_UPDATE*)lpMsg);
					break;
#endif
#if(PKEVENT == 1) // OK
				case 101:
					PKEventRecv((PKEVENT_UPDATE*)lpMsg);
					break;
				case 102:
					GCInfoPKEvent((INFOPKEVENT_SENDCLIENT *)lpMsg);
					break;
#endif
#if(TVTEVENT == 1) // OK
				case 103:
					GCInfoTvTEvent((INFOTVTEVENT_SENDCLIENT *)lpMsg);
					break;
#endif
#if(MOCNAP == 1) // OK
				case 104:
					MocNapRecv((MOCNAP_UPDATE*)lpMsg);
					break;
#endif
#if(PHUKIEN_NEW == 1)
				case 105:
					PhuKienRecv((PHUKIEN_UPDATE*)lpMsg);
					break;
#endif
#if(TAISINH == 1)
				case 106:
					TaiSinhCheckRecv((TAISINHCHECK_UPDATE*)lpMsg);
					break;
				case 107:
					TaiSinhDiemRecv((TAISINHDIEM_UPDATE*)lpMsg);
					break;
				case 108:
					DieuKienNgoc01Recv((DIEUKIENNGOC01_UPDATE*)lpMsg);
					break;
				case 109:
					DieuKienNgoc02Recv((DIEUKIENNGOC02_UPDATE*)lpMsg);
					break;
#endif
#if(BOSS_GUILD == 1)
				case 110:
					BossGuildRecv((BOSSGUILD_UPDATE*)lpMsg);
					break;
#endif
				case 111:
					GifCodeRecv((GIFCODE_UPDATE*)lpMsg);
					break;

				case 112:
					VanThanhRecv((VANTHANH_UPDATE*)lpMsg);
					break;

				case 113:
					MuunAFKRecv((MUUNAFK_UPDATE*)lpMsg);
					break;

			}
			break;
	case 0xFB:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
#if(OANTUTY)
			case 0x88:
				UpdateRPSMode();
				break;
#endif
					#if(DEV_DAMAGE_TABLE)
				case 0xDC:
					RecvDamageTable((PMSG_DAMAGE_TABLE*)lpMsg);
					break;
				#endif
					
#if(OFFLINE_MODE_NEW)
			case 0x00:
				gOfflineMode.GCOfflineModeRecv((PMSG_OFFLINEMODE_REQ*)lpMsg);
				break;
#endif

#if(HIDE_VT)
			//case 0x01:
			//	gResetSystem.set_data((RESET_ANS_USERDATA*)lpMsg);
			//	return 1;
			//case 0x02:
			//	gResetSystem.get_reset_result();
			//	return 1;
			//case 0x03:
			//	gGrandResetSystem.set_data((GR_ANS_USERDATA*)lpMsg);
			//	return 1;
			//case 0x04:
			//	gGrandResetSystem.get_reset_result();
			//	return 1;
#endif
			case 0x06:
				gPartySearchSettings.GCPartySettingsRecv((PMSG_PARTYSETTINGS_RECV*)lpMsg);
				return 1;

#if (ARCHIVEMENT == 1)

			case 0x0C:
				gAchievements.GCPlayerData((PMSG_GC_ACH_PLAYER_DATA*)lpMsg);
				return 1;
			case 0x0D:
				gAchievements.GCCalculatorPower((PMSG_GC_ACH_POWER*)lpMsg);
				return 1;
			case 0x0F:
				gAchievements.GCConfigData((PMSG_GC_ACH_SETTINGS_DATA*)lpMsg);
				return 1;
#endif

			case 0x07:
				gServerInfo.RecvServerInfo((PMSG_SERVER_INFO_RECV*)lpMsg);
				return 1;
			case 0x15:
				gChangeClass.RecvData((PMSG_CHANGECLASS_DATA*)lpMsg);
				break;

#if(NHIEMVU_NEW == 1)
			case 0x10:
				g_ExWinQuestSystem.GC_MiniInfoRecvEx((GC_ExWinMiniInfoEx*)lpMsg); //0xFD, 0x13
				return 1;
			case 0x11:
				g_ExWinQuestSystem.GC_Start((GC_ExWinStart*)lpMsg); //0xFD, 0x14
				return 1;
			case 0x14:
				g_ExWinQuestSystem.GC_RecvMain((GC_MainPacket*)lpMsg); //0xFF, 0x0C
				return 1;
			case 0x13:
				g_ExWinQuestSystem.GC_MiniInfoRecv((GC_ExWinMiniInfo*)lpMsg); //0xFF, 0x0D
				return 1;
#endif

			case 0x16:
				GCWarehouseInterfaceOpenRecv((PMSG_WAREHOUSEINTERFACE_RECV*)lpMsg);
				return 1;
				
#if(VONGQUAY_NEW)
			case 0x25:
				gLuckySpin.LuckySpinData((GC_LuckySpinUpdateData*)lpMsg);
				break;
			case 0x26:
				LuckySpinRoll();
				break;
			case 0x33:
				gLuckySpin.GCItemSend((GC_LuckySpin_Data*)lpMsg);
				break;
			case 0x34:
				gLuckySpin.GCLuckySpinInit((GC_LuckySpinInit*)lpMsg);
				break;
#endif

// Load GS -> Client

#if(KINH_MACH_NEW == 1)
			case 0x36:
				G_BEXO_KINHMACH.GetInfoKinhMach((PMSG_KINHMACH_UPD*)lpMsg);
				break;
			case 0x37:
				G_BEXO_KINHMACH.GetInfoKinhMachLevel((PMSG_KINHMACH_LEVEL_UPD*)lpMsg);
				break;
#endif

#if(NGU_HANH_NEW == 1)
			case 0x38:
				G_BEXO_NGUHANH.GetInfoNguHanh((PMSG_NGUHANH_UPD*)lpMsg);
				break;
#endif
#if(TINHNANG_NEW == 1)
			case 0x55:
				gInterface.GetInfoTinhNang((PMSG_TINHNANG_UPD*)lpMsg);
				break;
#endif
#if(SACHTHUOCTINH_NEW == 1)
			case 0x56:
				gInterface.GetInfoThuocTinh((PMSG_THUOCTINH_UPD*)lpMsg);
				break;
			case 0x57:
				gInterface.GetInfoThuocTinhAtive((PMSG_THUOCTINH_ATIVE_UPD*)lpMsg);
				break;
#endif
				//============================================================================================================
			case 0x59:
				gInterface.TvTEventEx((PMSG_TVTEVENT_UPD*)lpMsg);
				break;

#if(GHETINFOCLIENT == 1)
			case 200:
				gInterface.GetInfoClient((PMSG_CLIENT_UPD*)lpMsg);
				break;
#endif

				//============================================================================================================
			}
			break;
			//-- Open Ruud
		case 0xEA:
			jCRenderRuud.LoadRuudShop_Recv((PMSG_ITEMRUUD_LIST_RECV*)lpMsg);
			return 1;
		case 0xEE:
			jCRenderRuud.OpenRuudShop_Recv((PMSG_NPC_TALK_RECV*)lpMsg);
			return 1;
			//--post item
		case 0x78:
			RecvPostItem((PMSG_POSTITEM*)lpMsg);
			break;
		case 0x89:
			gInterface.DrawPing();
			break;
		//-- Buff Icon
		case 0x2D:
			gIconBuff.Recv((PMSG_SEND_BUFF_ICON * )lpMsg);
			break;
			//-- Party Buff
		case 0x2E:
			gPartyBuffs.RecvPartyBuffs((PMSG_PARTY_EFFECT_LIST_SEND*)lpMsg);
			break;
#if(RANKING_NEW == 1)
		case 0xFE:
			gRanking.RecvInfo((DGCharTop*)lpMsg);
			break;
		case 0x50:
			gRanking.RecvInfoDW((DGCharTopDW*)lpMsg);
			break;
		case 0x51:
			gRanking.RecvInfoDK((DGCharTopDK*)lpMsg);
			break;
		case 0x52:
			gRanking.RecvInfoEF((DGCharTopEF*)lpMsg);
			break;
		case 0x53:
			gRanking.RecvInfoMG((DGCharTopMG*)lpMsg);
			break;
		case 0x55:
			gRanking.RecvInfoDL((DGCharTopDL*)lpMsg);
			break;
		case 0x56:
			gRanking.RecvInfoSM((DGCharTopSM*)lpMsg);
			break;
		case 0x57:
			gRanking.RecvInfoRF((DGCharTopRF*)lpMsg);
			break;
		case 0x58:
			gRanking.RecvInfoNAP((DGCharTopNAP*)lpMsg);
			break;
		case 0x59:
			gRanking.RecvInfoBLOOD((DGCharTopBLOOD*)lpMsg);
			break;
		case 0x60:
			gRanking.RecvInfoDEVIL((DGCharTopDEVIL*)lpMsg);
			break;
		case 0x71:
			gRanking.RecvInfoCHAOS((DGCharTopCHAOS*)lpMsg);
			break;
#endif

#if (takumi12 == 1)
		case 0x79:
			gCentral.CGPartyLifeRecv((PMSG_PARTY_LIFE_SEND *) lpMsg);
			break;
		case 0x7A:
			gCentral.CGPartyListRecv((PMSG_PARTY_LIST_SEND *) lpMsg);
			break;
#endif

#if(SHOPSEARCH==TRUE)
		case 0xFA:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0x09:
				g_PersonalShopEx.GC_Recv(lpMsg);
				break;
			case 0x10:
				g_PersonalShopEx.GC_PSRecv((GC_SendTargetInfo *)lpMsg);
				break;
			}
#endif
			break;
//	}

		case 0xFF:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
#if(LEOTHAP == 1)
			case 0x08:
				gLeoThap.GCData((PMSG_LEOTHAP_TIME*)lpMsg);
				break;
			case 0x09:
				gLeoThap.GCData2((PMSG_LEOTHAP_TIME2*)lpMsg);
				break;
#endif
			}
			break;

	}

	BYTE ProtocolType = lpMsg[0];

	if (ProtocolType == 0xC1)
	{
		switch (BYTE(head))
		{
		case 0xEC:
		{
					 PBMSG_HEAD2 * lpDef = (PBMSG_HEAD2 *)lpMsg;

					 switch (lpDef->subcode)
					 {
					 case 0x00:
#if(DEV_PLAYERSHOP)
						 g_ChoTroi.CGAnsItemSell(/*(PMSG_ANS_MARKET_SELL*)Data*/);
#endif
						 break;
					 case 0x01:
#if(DEV_PLAYERSHOP)
						 g_ChoTroi.GCAnsItemBuy((PMSG_ANS_MARKET_BUY*)lpMsg);
#endif
						 break;
					 };
		}
			break;
		}
	}
	else if (ProtocolType == 0xC2)
	{
		switch (BYTE(head))
		{
		case 0xFA:
		{
					 PWMSG_HEAD2 * lpDef = (PWMSG_HEAD2 *)lpMsg;

					 switch (lpDef->subcode)
					 {
#if(DEV_PLAYERSHOP)
					 case 0xF5:
						 g_ChoTroi.GCAnsItemList((PMSG_ANS_MARKET_ITEM*)lpMsg);
						 break;
#endif
					 }

		}
		}
	}

	return ProtocolCore(head, lpMsg, size, key);
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;

	if((lpMsg->type & 0x10) != 0)
	{
		if(ViewDamageCount < 3)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}

	if((lpMsg->type & 0x20) != 0)
	{
		if(ViewDamageCount < 4)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP==0)?ViewCurHP:lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if(lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewValue = lpMsg->ViewValue;
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	gObjUser.Refresh();
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMove(lpMsg->IpAddress,lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	gHwid.SendHwid();
	ViewIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ObjectDir = lpMsg->Dir;
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;

	*(WORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x07E) = 0;

	*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x30C) = 0;

	switch(((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7))
		//Fix Death Stab Visual Bug
	{
	case 0:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DWMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 1:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DKMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));;
		break;
	case 2:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.FEMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 3:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.MGMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 4:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DLMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 5:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.SUMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 6:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.RFMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	}
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;

	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;

	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;
	*(WORD *)(*(DWORD *)0x8128AC8 + 36) = *(WORD *)(*(DWORD *)0x8128AC8 + 40); //-- Mana
	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66); //-- BP
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if(lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCMasterInfoRecv(PMSG_MASTER_INFO_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
}

void GCMasterLevelUpRecv(PMSG_MASTER_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewMasterExperience = lpMsg->ViewMasterExperience;
	ViewMasterNextExperience = lpMsg->ViewMasterNextExperience;
	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;

	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66);
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E) = lpMsg->Level;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) = lpMsg->LevelUpPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x18) = lpMsg->Strength;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1A) = lpMsg->Dexterity;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1C) = lpMsg->Vitality;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1E) = lpMsg->Energy;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x20) = lpMsg->Leadership;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x22) = lpMsg->Life;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x26) = lpMsg->MaxLife;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x24) = lpMsg->Mana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x28) = lpMsg->MaxMana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x40) = lpMsg->BP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x42) = lpMsg->MaxBP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2A) = lpMsg->Shield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2C) = lpMsg->MaxShield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4C) = lpMsg->FruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4E) = lpMsg->MaxFruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x50) = lpMsg->FruitSubPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x52) = lpMsg->MaxFruitSubPoint;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x10) = lpMsg->Experience;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x14) = lpMsg->NextExperience;

	//EXTRA
	ViewReset = lpMsg->ViewReset;
	ViewGReset = lpMsg->ViewGReset;
	ViewAccountLevel = lpMsg->ViewAccountLevel;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiDamageMin = lpMsg->ViewPhysiDamageMin;
	ViewPhysiDamageMax = lpMsg->ViewPhysiDamageMax;
	ViewMagicDamageMin = lpMsg->ViewMagicDamageMin;
	ViewMagicDamageMax = lpMsg->ViewMagicDamageMax;
	ViewCurseDamageMin = lpMsg->ViewCurseDamageMin;
	ViewCurseDamageMax = lpMsg->ViewCurseDamageMax;
	ViewMulPhysiDamage = lpMsg->ViewMulPhysiDamage;
	ViewDivPhysiDamage = lpMsg->ViewDivPhysiDamage;
	ViewMulMagicDamage = lpMsg->ViewMulMagicDamage;
	ViewDivMagicDamage = lpMsg->ViewDivMagicDamage;
	ViewMulCurseDamage = lpMsg->ViewMulCurseDamage;
	ViewDivCurseDamage = lpMsg->ViewDivCurseDamage;
	ViewMagicDamageRate = lpMsg->ViewMagicDamageRate;
	ViewCurseDamageRate = lpMsg->ViewCurseDamageRate;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewAttackSuccessRate = lpMsg->ViewAttackSuccessRate;
	ViewAttackSuccessRatePvP = lpMsg->ViewAttackSuccessRatePvP;
	ViewDefense = lpMsg->ViewDefense;
	ViewDefenseSuccessRate = lpMsg->ViewDefenseSuccessRate;
	ViewDefenseSuccessRatePvP = lpMsg->ViewDefenseSuccessRatePvP;
	ViewDamageMultiplier = lpMsg->ViewDamageMultiplier;
	ViewRFDamageMultiplierA = lpMsg->ViewRFDamageMultiplierA;
	ViewRFDamageMultiplierB = lpMsg->ViewRFDamageMultiplierB;
	ViewRFDamageMultiplierC = lpMsg->ViewRFDamageMultiplierC;
	ViewDarkSpiritAttackDamageMin = lpMsg->ViewDarkSpiritAttackDamageMin;
	ViewDarkSpiritAttackDamageMax = lpMsg->ViewDarkSpiritAttackDamageMax;
	ViewDarkSpiritAttackSpeed = lpMsg->ViewDarkSpiritAttackSpeed;
	ViewDarkSpiritAttackSuccessRate = lpMsg->ViewDarkSpiritAttackSuccessRate;
}


void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(PMSG_NEW_HEALTH_RECV)* n));

		InsertNewHealthBar(lpInfo);
	}
}

void GCNewGensBattleInfoRecv(PMSG_NEW_GENS_BATTLE_INFO_RECV* lpMsg) // OK
{
	GensBattleMapCount = lpMsg->GensBattleMapCount;

	GensMoveIndexCount = lpMsg->GensMoveIndexCount;

	memcpy(GensBattleMap,lpMsg->GensBattleMap,sizeof(GensBattleMap));

	memcpy(GensMoveIndex,lpMsg->GensMoveIndex,sizeof(GensMoveIndex));
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{

}

//Cashshop Fix
void OpenCashShopSend(BYTE type)
{
	PMSG_CASH_SHOP_OPEN_RECV pMsg;
	pMsg.OpenType = type;
	pMsg.header.set(0xD2,0x02,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}

bool CashShopSwitchState()
{
	sub_861900_Addr((int)pWindowThis());

	if ( !sub_944E50_Addr() )
		return 0;

	void* v48 = sub_93F370_Addr();

	if ( sub_93FCA0_Addr((int)v48) == 1 )
	{
		if ( !sub_93F600_Addr((CHAR *)sub_93F370_Addr()) )
			return 0;
	}

	if ( sub_93FD10_Addr((int)sub_93F370_Addr()) == 1 )
	{
		if ( sub_93F950_Addr((CHAR *)sub_93F370_Addr()) == 1 )
		{
			BYTE* v53 = (BYTE *)sub_941030_Addr((BYTE*)sub_93F370_Addr());
			int v55 = sub_941000_Addr((BYTE*)sub_93F370_Addr());
			BYTE* v57 = (BYTE *)sub_861900_Addr((int)pWindowThis());
			sub_944FE0_Addr(v57, v55, v53);
		}
	}

	if ( pCheckWindow(pWindowThis(), 65) )
	{
		OpenCashShopSend(1);
		pCloseWindow(pWindowThis(), 65);
	}
	else
	{
		if ( !sub_9406C0_Addr((BYTE*)sub_93F370_Addr()) )
		{
			OpenCashShopSend(0);
			sub_9406A0_Addr((BYTE*)sub_93F370_Addr(), 1);
			char* v62 = (char *)sub_8611E0_Addr((DWORD*)pWindowThis());
			sub_815130_Addr(v62, 0, 1);
		}
	}
}
#if(OANTUTY)
void RPSMode(int Number)
{
	RPSMODE_REQ pMsg;
	pMsg.h.set(0xFC, 0x21, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void UpdateRPSMode()
{
	gInterface.Data[eRock].Attribute = 0;
	gInterface.Data[ePaper].Attribute = 0;
	gInterface.Data[eScissors].Attribute = 0;
}
#endif
void DataSend(BYTE* lpMsg,DWORD size) // OK
{
	BYTE EncBuff[2048];

	if(gPacketManager.AddData(lpMsg,size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send,EncBuff,size);

		if(EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if(EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[2],&EncBuff[1],(size-1))+2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3],&EncBuff[2],(size-2))+3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*,BYTE*,DWORD))0x00405110)((void*)0x08793750,send,size);
	}
}

void GCRecvCoin(PMSG_COIN_RECV* lpMsg) // OK
{
	Coin1 = lpMsg->Coin1;
	Coin2 = lpMsg->Coin2;
	Coin3 = lpMsg->Coin3;
	Ruud = lpMsg->Ruud;
}

void GCBuyConfirmRecv(PMSG_ITEM_BUY_RECV* lpMsg) // OK
{
	gInterface.Data[eCONFIRM_MAIN].OnShow = true;
	pSetCursorFocus = true;
	gInterface.ConfirmSlot = lpMsg->slot;
}
#if(DEV_DAMAGE_TABLE)

void RecvDamageTable(PMSG_DAMAGE_TABLE* lpMsg)
{
	if(!gAdvanceStats)
	{
		return;
	}

	gObjUser.m_SecondDamage = lpMsg->SecondDamage;
	gObjUser.m_SecondDefence = lpMsg->SecondDefence;
	gObjUser.m_SecondReflect = lpMsg->SecondReflect;
	if(gObjUser.m_SecondDamage > gObjUser.m_SecondDamageMax)
	{
		gObjUser.m_SecondDamageMax = gObjUser.m_SecondDamage;
	}

	gObjUser.m_SecondInfo = true;
}

#endif

//======================================= lo nuevo
//--post item
bool RecvPostItem(PMSG_POSTITEM * lpMsg) {

	void * item_post = PostItem::AddItem ( &lpMsg->item_data[0] );

	if ( item_post == nullptr ) { return false; }

	char Name[11] = { '\0' };
	char Messase[61] = { '\0' };
	char Messase_API[70] = { '\0' };
	memcpy_s ( &Name[0], 10, &lpMsg->chatid[0], 10 );
	memcpy_s ( &Messase[0], 60, &lpMsg->chatmsg[0], 60 );
	int len = strlen ( Messase );
	// ----
	// Cat text Excillent
	if ( ( BYTE ) Messase[0] == 0xC4 &&
			( BYTE ) Messase[1] == 0x90 &&
			( BYTE ) Messase[2] == 0xE1 &&
			( BYTE ) Messase[3] == 0xBB &&
			( BYTE ) Messase[4] == 0x93 &&
			( BYTE ) Messase[5] == 0x20 &&
			( BYTE ) Messase[6] == 0x68 &&
			( BYTE ) Messase[7] == 0x6F &&
			( BYTE ) Messase[8] == 0xC3 &&
			( BYTE ) Messase[9] == 0xA0 &&
			( BYTE ) Messase[10] == 0x6E &&
			( BYTE ) Messase[11] == 0x20 &&
			( BYTE ) Messase[12] == 0x68 &&
			( BYTE ) Messase[13] == 0xE1 &&
			( BYTE ) Messase[14] == 0xBA &&
			( BYTE ) Messase[15] == 0xA3 &&
			( BYTE ) Messase[16] == 0x6F &&
			( BYTE ) Messase[17] == 0x20 ) {
		strcpy_s ( &Messase[0], 61, &Messase[18] );
	}
	// Cat bot ten neu qua dai
	if ( len > 25 ) // 25
	{
		for (int i = 20; i < len; ++i)  // 20
		{
			if ( isalpha ( Messase[i] ) || Messase[i] == ' ' ) 
			{
				Messase[i] = '.';
				Messase[i + 1] = '.';
				Messase[i + 2] = '.';
				Messase[i + 3] = '\0';
			}
		}
	}
	//push this node to eItemNode
	for (int i = 0; i < 19; i++)
	{
		gPostItem.eItemNode[i] = gPostItem.eItemNode[i + 1];
	}
	gPostItem.eItemNode[19] = (DWORD)item_post;
	//end eItemNode
	sprintf_s( Messase_API, "[SELL] %s_[%08X]", Messase, (DWORD)item_post);
	gPostItem.draw_character_head_chat_text_ = true;
	newInterface::DrawChat ( gPostItem.PostItemColor, &Name[0], &Messase_API[0] );
	// ----

	if ( !gPostItem.draw_character_head_chat_text_ ) 
	{ // da lay duoc base_address
		// xu ly doan chat tren dau nhan vat
		char message[256] = { 0 };
		char * chat_text_first = CharacterHeadChatTextFirst ( gPostItem.draw_character_head_chat_text_base_address_ );
		char * chat_text_last = CharacterHeadChatTextLast ( gPostItem.draw_character_head_chat_text_base_address_ );
		unsigned long msgfirst_len = strlen ( chat_text_first );
		unsigned long msglast_len = strlen ( chat_text_last );
		strcpy_s ( message, sizeof ( message ), chat_text_first );
		strcat_s ( message, chat_text_last );
		unsigned long message_len = strlen ( message );

		if ( message[message_len - 1 - 8 - 2] != '_' ||
				message[message_len - 1 - 8 - 1] != '[' ||
				message[message_len - 1] != ']' ) 
		{
		}
		else 
		{
			message[message_len - 1 - 8 - 2] = '\0';  // cat bo doan duoi

			// copy lai
			if ( msgfirst_len ) 
			{
				memcpy_s ( chat_text_first, 0x50, message, msgfirst_len );
				chat_text_first[msgfirst_len] = '\0';
			}

			if ( msglast_len ) 
			{
				memcpy_s ( chat_text_last, 0x50, &message[msgfirst_len], msglast_len );
				chat_text_last[msglast_len] = '\0';
			}
		}
	}
	return true;
}

//--- pet
void GCPetCharSetRecv(PMSG_NEW_PET_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSet();

	for (int n = 0; n < lpMsg->count; n++)
	{
		NEW_PET_STRUCT* lpInfo = (NEW_PET_STRUCT*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_PET_CHARSET_RECV)+(sizeof(NEW_PET_STRUCT)*n));

		InsertNewPetCharSet(lpInfo->index, lpInfo->PetCharSet);
	}
}

void GCPetCharSetSelectCharacterRecv(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSetSelectCharacter();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_CHARACTER_CHARSET_RECV* lpInfo = (PMSG_NEW_CHARACTER_CHARSET_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV)+(sizeof(PMSG_NEW_CHARACTER_CHARSET_RECV)*n));

		InsertNewPetCharSetSelectCharacter(lpInfo->Name, lpInfo->PetCharSet);
	}
}

void SetChaosBoxState(PMSG_SET_CHAOSBOX_STATE* Data){
	pChaosBoxState = Data->state;
	return;
}

void GCWarehouseInterfaceOpenRecv(PMSG_WAREHOUSEINTERFACE_RECV* lpMsg)
{
	gObjUser.m_MaxWarehouse = lpMsg->MaxWarehouse;
	gInterface.Data[eWAREHOUSE_MAIN].Open(MAX_WIN_HEIGHT, 20);
	gInterface.Data[eWAREHOUSE_MAIN].EventTick = GetTickCount();
}

void CGSendWarehouseOpen(int Number)
{
	PMSG_WAREHOUSEINTERFACE_SEND pMsg;
	pMsg.header.set(0xFF, 0x08, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CGSendStatsAdd(PMSG_UPDATE_STATS_SEND pMsg)
{
	pMsg.header.set(0xFF, 0x09, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void GCPartyListRecv(PMSG_RECV_PARTYLIST* lpMsg)
{
	gPartySearch.ClearPartyList();

	for (int n = 0; n < lpMsg->Count; n++)
	{
		PMSG_PARTYSEARCH_PARTYLIST* lpInfo = (PMSG_PARTYSEARCH_PARTYLIST*)(((BYTE*)lpMsg) + sizeof(PMSG_RECV_PARTYLIST)+(sizeof(PMSG_PARTYSEARCH_PARTYLIST)* n));

		gPartySearch.InsertPartyList(lpInfo);
	}

	gPartySearch.party_search_switch_state();
}

#if(VONGQUAY_NEW)
void LuckySpinRoll()
{
	gLuckySpin.StartRoll = 1;
}
#endif

//void ThuongGiaZenRoll()
//{
//	G_BEXO_THUONG_GIA.StartRollZen = 1;
//}

void UPDATEMENU(MENU_SEND lpMsg)
{
	lpMsg.header.set(0xF4,0x02,sizeof(lpMsg));
	DataSend((BYTE*)&lpMsg,lpMsg.header.size);
}
// Protocol.cpp
// =========== CTC Mini
void GCCTCMiniShowWindow(INFOCTCMINI_SENDCLIENT* lpMsg) // OK
{
	if((GetTickCount()-gInterface.Data[eCTCMiniWindow].EventTick) > 300)
	{
		gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
		gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
	}
	CheckVaoLanhDia = lpMsg->GuildWinOld;
}

#if(BOSS_GUILD == 1) // ok
void GCBossGuildShowWindow(INFOBOSSGUILD_SENDCLIENT* lpMsg) // OK
{
	if ((GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick) > 300)
	{
		gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
		gInterface.Data[eBossGuildWindow].OnShow ^= 1;
		gInterface.BUY_TINH_NANG_GAME(7);
	}
}

void GCBossGuildTime(BOSSGUILDTIME_SENDCLIENT* lpMsg) // OK
{
	BossGuild_TimeConLai = lpMsg->TimeBossGuild;
}
#endif

//24-03-2022
void GCMuunPetTime(MUUNPETTIME_SENDCLIENT* lpMsg) // OK
{
	MuunPet_TimeRun = lpMsg->MuunPetTime;
}

#if(MUUNAFK == 1)
void GCMuunPetAFKTime(MUUNPETAFK_SENDCLIENT* lpMsg) // OK
{
	MuunAFKTime = lpMsg->MuunAFKTime;
	MuunAFKStamina = lpMsg->MuunAFKStamina;
	MuunAFKWCoinClaim = lpMsg->MuunAFKWCoinClaim;
}
#endif

#if(LEOTHAP == 1)
void GCLEOTHAPShowWindow(PMSG_LEOTHAP_REQ* lpMsg) // OK
{
	if ((GetTickCount() - gInterface.Data[eLEOTHAP_MAIN].EventTick) > 300)
	{
		gInterface.Data[eLEOTHAP_MAIN].EventTick = GetTickCount();
		gInterface.Data[eLEOTHAP_MAIN].OnShow ^= 1;
	}
}
#endif

void GCCTCMiniKill(CTCMINIKILL_SENDCLIENT* lpMsg) // OK
{
	CTCMINI_TimeCTCMini = lpMsg->TimeCTCMini;
	for(int n=0;n < 3;n++) //Them Cong
	{
		CTCMINI_Cong[n] = lpMsg->Cong[n];
		CTCMINI_Tru[n] = lpMsg->Tru[n];
	}
}

void GCInfoCTC(INFOCTC_SENDCLIENT* lpMsg) // OK
{
	{
		CTC_TimeConLai = lpMsg->TimeConLai;
		CTC_PointKillQuai = lpMsg->PointKillQuai;
		CTC_PartyKillPoint = lpMsg->PartyKillPoint;
		CTC_MonterYeuCau = lpMsg->MonterYeuCau;
		gInterface.Data[eCuaSoCTC].OnShow = lpMsg->TYPE;
		gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
	}
}
#if(PKEVENT == 1)
void GCInfoPKEvent(INFOPKEVENT_SENDCLIENT* lpMsg) // OK
{
	{
		PKEvent_TimeConLai = lpMsg->TimeConLaiPKEvent;
	}
}
#endif

#if(TVTEVENT == 1)
void GCInfoTvTEvent(INFOTVTEVENT_SENDCLIENT* lpMsg) // OK
{
	{
		TvTEvent_TimeConLai = lpMsg->TimeConLaiTvTEvent;
	}
}
#endif

void GCCTCKillMonter(CTCKILL_SENDCLIENT* lpMsg) // OK
{
	CTC_QuaiVatDaKill = lpMsg->QuaiKill;
}


