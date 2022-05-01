#pragma once
#include "Object.h"
#include "Protocol.h"
#pragma pack(push, 1)
struct PMSG_TARGETDATA_REQ
{
	PSWMSG_HEAD header;
	int			aIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGETDATA_ANS
{
	PSWMSG_HEAD header;
	int aIndex;
    bool isMonster;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_MONSTER_DATA : PMSG_TARGETDATA_ANS
{
    int Life;
    int MaxLife;
    short Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_PLAYER_DATA : PMSG_TARGET_MONSTER_DATA
{
    int SD;
    int MaxSD;
    short Reset;
	short RankTitle;
	short Long;
};
#pragma pack(pop)

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};

class User
{
public:
	#if(DEV_DAMAGE_TABLE)
	bool m_SecondInfo;
	int m_SecondDamageMax;
	int m_SecondDamage;
	int m_SecondDefence;
	int m_SecondReflect;

	#endif
	int CoordenadaX;
	int CoordenadaY;
	int getLevel;
	int getReset;
	char getName[11];
	//-- post item
	int				PostItemID;
	int				PostItemLV;
	int				PostItemExc;
	int				PostItemAcc;
	int				PostItemHarmony;
	int				PostItem380;
	char*			PostItemSocket;
	int				PostItemX;
	int				PostItemY;
	int				GetPet;
	//--
	void			Load();
	void			Refresh();	
	bool			GetTarget();
	lpCharObj		lpPlayer;
	lpViewObj		lpViewPlayer;
	lpViewObj		lpViewTarget;
	BYTE			m_TargetType;	//1 - npc, 2 - attack
	int				m_MapNumber;
	int				m_CursorX;
	int				MagickAttack;
	int				m_CursorY;
	DWORD			m_TargetUpdateTick;
	int				m_QuestStat;
	BYTE			m_reset_item_check[5];
	int				m_MaxWarehouse;
	int				m_WarehouseNumber;
	static char* GetMapName(signed int MapNumber);
	static void ChangeCharInfo(LPVOID This);
	bool InSafeZone;
	static void	AllInOne();
	void DrawHP();
	void DrawRank();
	void SetTargetData(PMSG_TARGETDATA_ANS * lpMsg);
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	CUSTOM_LOGO m_Logo[400];

	static bool	ShowModelBMD(int a1, int a2, int a3);
	//Auto Sendmove
	DWORD		IsSendMove;
	DWORD			MoveToX;
	DWORD			MoveToY;
	BYTE		KhongDiDuoc;

#if(NGANHANGNGOC_NEW == 1)
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
#endif

#if(DANH_HIEU_NEW == 1)
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
#endif

#if(TU_LUYEN_NEW == 1)
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
#endif

	int SurvivorKill;
	int SurvivorDie;
	int SurvivorTotal;

#if(MOCNAP == 1)
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
#endif

#if(PHUKIEN_NEW == 1)
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
#endif

#if(TAISINH == 1)
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
	//---
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
	//---
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
	//---
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
#endif

#if(BOSS_GUILD == 1)
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
#endif


	int	BangXepHang;
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

	int GifCode;


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

	void RenderRuneEffect(DWORD ObjectModel, int ID, int Type, float Z, float Size);
	static bool UseHasMagicRing();
	static bool CreateManyFlag(ObjectPreview * pChar);
	static void __cdecl HoolCreateManyFlay(ObjectPreview * pChar);
};
extern User gObjUser;