#pragma once

#if(DATASERVER_UPDATE>=701)
#define INVENTORY_SIZE 237
#elif(DATASERVER_UPDATE>=602)
#define INVENTORY_SIZE 236
#else
#define INVENTORY_SIZE 108
#endif
#if(DATASERVER_UPDATE>=701)
#define MAX_EFFECT_LIST 32
#else
#define MAX_EFFECT_LIST 16
#endif
#if(DATASERVER_UPDATE>=701)
#define MAX_SKILL_LIST 60
#else
#define MAX_SKILL_LIST 60
#endif

#define SET_NUMBERHB(x) ((BYTE)((DWORD)(x)>>(DWORD)8))
#define SET_NUMBERLB(x) ((BYTE)((DWORD)(x)&0xFF))
#define SET_NUMBERHW(x) ((WORD)((DWORD)(x)>>(DWORD)16))
#define SET_NUMBERLW(x) ((WORD)((DWORD)(x)&0xFFFF))
#define SET_NUMBERHDW(x) ((DWORD)((QWORD)(x)>>(QWORD)32))
#define SET_NUMBERLDW(x) ((DWORD)((QWORD)(x)&0xFFFFFFFF))

#define SET_NUMBERH(x)			( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x)			( (BYTE)((DWORD)(x) & 0xFF) )

#define MAKE_NUMBERW(x,y) ((WORD)(((BYTE)((y)&0xFF))|((BYTE)((x)&0xFF)<<8)))
#define MAKE_NUMBERDW(x,y) ((DWORD)(((WORD)((y)&0xFFFF))|((WORD)((x)&0xFFFF)<<16)))
#define MAKE_NUMBERQW(x,y) ((QWORD)(((DWORD)((y)&0xFFFFFFFF))|((DWORD)((x)&0xFFFFFFFF)<<32)))

//**********************************************//
//************ Packet Base *********************//
//**********************************************//

struct PBMSG_HEAD
{
	void set(BYTE head,BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->head = head;
	}

	void setE(BYTE head,BYTE size) // OK
	{
		this->type = 0xC3;
		this->size = size;
		this->head = head;
	}

	BYTE type;
	BYTE size;
	BYTE head;
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PSBMSG_HEAD
{
	void set(BYTE head,BYTE subh,BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->head = head;
		this->subh = subh;
	}

	void setE(BYTE head,BYTE subh,BYTE size) // OK
	{
		this->type = 0xC3;
		this->size = size;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size;
	BYTE head;
	BYTE subh;
};

struct PWMSG_HEAD
{
	void set(BYTE head,WORD size) // OK
	{
		this->type = 0xC2;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->head = head;
	}

	void setE(BYTE head,WORD size) // OK
	{
		this->type = 0xC4;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->head = head;
	}

	BYTE type;
	BYTE size[2];
	BYTE head;
};

struct PSWMSG_HEAD
{
	void set(BYTE head,BYTE subh,WORD size) // OK
	{
		this->type = 0xC2;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->head = head;
		this->subh = subh;
	}

	void setE(BYTE head,BYTE subh,WORD size) // OK
	{
		this->type = 0xC4;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size[2];
	BYTE head;
	BYTE subh;
};

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//

struct SDHP_CHARACTER_LIST_RECV
{
	PBMSG_HEAD header; // C1:01
	WORD index;
	char account[11];
};

struct SDHP_CHARACTER_CREATE_RECV
{
	PBMSG_HEAD header; // C1:02
	WORD index;
	char account[11];
	char name[11];
	BYTE Class;
};

struct SDHP_CHARACTER_DELETE_RECV
{
	PBMSG_HEAD header; // C1:03
	WORD index;
	char account[11];
	char name[11];
	BYTE guild;
	char GuildName[9];
};

struct SDHP_CHARACTER_INFO_RECV
{
	PBMSG_HEAD header; // C1:04
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_CREATE_ITEM_RECV
{
	PBMSG_HEAD header; // C1:07
	WORD index;
	char account[11];
	BYTE X;
	BYTE Y;
	BYTE Map;
	WORD ItemIndex;
	BYTE Level;
	BYTE Dur;
	BYTE Option1;
	BYTE Option2;
	BYTE Option3;
	BYTE NewOption;
	WORD LootIndex;
	BYTE SetOption;
	BYTE JewelOfHarmonyOption;
	BYTE ItemOptionEx;
	BYTE SocketOption[5];
	BYTE SocketOptionBonus;
	DWORD Duration;
};

struct SDHP_OPTION_DATA_RECV
{
	PBMSG_HEAD header; // C1:08
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_PET_ITEM_INFO_RECV
{
	PWMSG_HEAD header; // C2:09
	WORD index;
	char account[11];
	BYTE type;
	BYTE count;
};

struct SDHP_PET_ITEM_INFO1
{
	BYTE slot;
	DWORD serial;
};

struct SDHP_CHARACTER_NAME_CHECK_RECV
{
	PBMSG_HEAD header; // C1:0A
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_CHARACTER_NAME_CHANGE_RECV
{
	PBMSG_HEAD header; // C1:0B
	WORD index;
	char account[11];
	char OldName[11];
	char NewName[11];
};

struct SDHP_CRYWOLF_SYNC_RECV
{
	PBMSG_HEAD header; // C1:1E
	WORD MapServerGroup;
	DWORD CrywolfState;
	DWORD OccupationState;
};

struct SDHP_CRYWOLF_INFO_RECV
{
	PBMSG_HEAD header; // C1:1F
	WORD MapServerGroup;
};

struct SDHP_GLOBAL_POST_RECV
{
	PBMSG_HEAD header; // C1:20
	WORD MapServerGroup;
	BYTE type;
	char name[11];
	char message[60];
};
//addpostitem
struct SDHP_GLOBAL_ITEM_POST_RECV
{
	PBMSG_HEAD header; // C1:78
	WORD MapServerGroup;
	char name[11];
	char message[60];
	char item_data[107];
};

struct SDHP_GLOBAL_NOTICE_RECV
{
	PBMSG_HEAD header; // C1:21
	WORD MapServerGroup;
	BYTE type;
	BYTE count;
	BYTE opacity;
	WORD delay;
	DWORD color;
	BYTE speed;
	char message[128];
};

struct SDHP_SNS_DATA_RECV
{
	PBMSG_HEAD header; // C1:24
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_CHARACTER_INFO_SAVE_RECV
{
	PWMSG_HEAD header; // C2:30
	WORD index;
	char account[11];
	char name[11];
	WORD Level;
	BYTE Class;
	DWORD LevelUpPoint;
	DWORD Experience;
	DWORD Money;
	DWORD Strength;
	DWORD Dexterity;
	DWORD Vitality;
	DWORD Energy;
	DWORD Leadership;
	DWORD Life;
	DWORD MaxLife;
	DWORD Mana;
	DWORD MaxMana;
	DWORD BP;
	DWORD MaxBP;
	DWORD Shield;
	DWORD MaxShield;
	BYTE Inventory[INVENTORY_SIZE][16];
	BYTE Skill[MAX_SKILL_LIST][3];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	DWORD PKCount;
	DWORD PKLevel;
	DWORD PKTime;
	BYTE Quest[50];
	WORD FruitAddPoint;
	WORD FruitSubPoint;
	BYTE Effect[MAX_EFFECT_LIST][13];
	#if(DATASERVER_UPDATE>=602)
	BYTE ExtInventory;
	BYTE ExtWarehouse;
	#endif
	DWORD Kills;
	DWORD Deads;
	int freePoints;
	int GensExitTick;
#if(DANH_HIEU_NEW)
	int rDanhHieu;
#endif
#if(THUE_VIP_NEW)
	int rThueVip;
	int rThueVipTime;
#endif
#if(TU_LUYEN_NEW)
	int rTuLuyen;
#endif
#if(NGU_HANH_NEW == 1)
	int rNguHanh;
#endif
#if(RESETLIFE_NEW == 1)
	int rResetLife;
#endif
#if (CHIENTRUONGCO == 1)
	int CTCTime;
	int CTCRegDay;
#endif
#if (LEOTHAP == 1)
	int TowerCount;
	DWORD TowerTime;
#endif
#if (WINDOWSQUEST==1)
	BYTE ExWQuestStart[3];
	WORD ExWQuestNum[3];
	WORD ExWQuestCount[3][5];
#endif
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
};

struct SDHP_INVENTORY_ITEM_SAVE_RECV
{
	PWMSG_HEAD header; // C2:31
	WORD index;
	char account[11];
	char name[11];
	BYTE Inventory[INVENTORY_SIZE][16];
};

struct SDHP_OPTION_DATA_SAVE_RECV
{
	PBMSG_HEAD header; // C1:33
	WORD index;
	char account[11];
	char name[11];
	BYTE SkillKey[20];
	BYTE GameOption;
	BYTE QKey;
	BYTE WKey;
	BYTE EKey;
	BYTE ChatWindow;
	BYTE RKey;
	DWORD QWERLevel;
	#if(DATASERVER_UPDATE>=701)
	BYTE ChangeSkin;
	#endif
};

struct SDHP_PET_ITEM_INFO_SAVE_RECV
{
	PWMSG_HEAD header; // C2:34
	WORD index;
	char account[11];
	BYTE count;
};

struct SDHP_PET_ITEM_INFO_SAVE
{
	DWORD serial;
	BYTE level;
	DWORD experience;
};

struct SDHP_RESET_INFO_SAVE_RECV
{
	PBMSG_HEAD header; // C1:39
	WORD index;
	char account[11];
	char name[11];
	UINT Reset;
	UINT ResetDay;
	UINT ResetWek;
	UINT ResetMon;
};

struct SDHP_MASTER_RESET_INFO_SAVE_RECV
{
	PBMSG_HEAD header; // C1:3A
	WORD index;
	char account[11];
	char name[11];
	UINT Reset;
	UINT MasterReset;
	UINT MasterResetDay;
	UINT MasterResetWek;
	UINT MasterResetMon;
};

struct SDHP_RANKING_DUEL_SAVE_RECV
{
	PBMSG_HEAD header; // C1:3C
	WORD index;
	char account[11];
	char name[11];
	DWORD WinScore;
	DWORD LoseScore;
};

struct SDHP_RANKING_BLOOD_CASTLE_SAVE_RECV
{
	PBMSG_HEAD header; // C1:3D
	WORD index;
	char account[11];
	char name[11];
	DWORD score;
};

struct SDHP_RANKING_CHAOS_CASTLE_SAVE_RECV
{
	PBMSG_HEAD header; // C1:3E
	WORD index;
	char account[11];
	char name[11];
	DWORD score;
};

struct SDHP_RANKING_DEVIL_SQUARE_SAVE_RECV
{
	PBMSG_HEAD header; // C1:3F
	WORD index;
	char account[11];
	char name[11];
	DWORD score;
};

struct SDHP_RANKING_ILLUSION_TEMPLE_SAVE_RECV
{
	PBMSG_HEAD header; // C1:40
	WORD index;
	char account[11];
	char name[11];
	DWORD score;
};

struct SDHP_CREATION_CARD_SAVE_RECV
{
	PBMSG_HEAD header; // C1:42
	WORD index;
	char account[11];
	BYTE ExtClass;
};

struct SDHP_CRYWOLF_INFO_SAVE_RECV
{
	PBMSG_HEAD header; // C1:49
	WORD MapServerGroup;
	DWORD CrywolfState;
	DWORD OccupationState;
};

struct SDHP_SNS_DATA_SAVE_RECV
{
	PWMSG_HEAD header; // C1:4E
	WORD index;
	char account[11];
	char name[11];
	BYTE data[256];
};

struct SDHP_CUSTOM_MONSTER_REWARD_SAVE_RECV
{
	PBMSG_HEAD header; // C1:52
	WORD index;
	char account[11];
	char name[11];
	DWORD MonsterClass;
	DWORD MapNumber;
	DWORD RewardValue1;
	DWORD RewardValue2;
	DWORD RewardValue3;
	DWORD RewardValue4;
};

struct SDHP_RANKING_CUSTOM_ARENA_SAVE_RECV
{
	PBMSG_HEAD header; // C1:55
	WORD index;
	char account[11];
	char name[11];
	DWORD number;
	DWORD score;
	DWORD rank;
};

struct SDHP_CONNECT_CHARACTER_RECV
{
	PBMSG_HEAD header; // C1:70
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_DISCONNECT_CHARACTER_RECV
{
	PBMSG_HEAD header; // C1:71
	WORD index;
	char account[11];
	char name[11];
};

struct SDHP_GLOBAL_WHISPER_RECV
{
	PBMSG_HEAD header; // C1:72
	WORD index;
	char account[11];
	char name[11];
	char TargetName[11];
	char message[60];
};

struct SDHP_SERVER_INFO_RECV
{
	PBMSG_HEAD header; // C1:00
	BYTE type;
	WORD ServerPort;
	char ServerName[50];
	WORD ServerCode;
};

struct SDHP_MARRY_INFO_SAVE_RECV
{
    PBMSG_HEAD header; // C1:F0
    WORD index;
    char name[11];
    char marryname[11];
    char mode[11];
};

#if(HIDE_VT)
struct SDHP_CUSTOMQUEST_RECV
{
    PBMSG_HEAD header; // C1:F1
    WORD index;
    char name[11];
};

struct SDHP_CUSTOMQUEST_SAVE_RECV
{
    PBMSG_HEAD header; // C1:F2
    WORD index;
    char name[11];
	DWORD quest;
};
#endif

struct SDHP_SETCOIN_RECV
{
    PBMSG_HEAD header; // C1:F3
    WORD index;
    char account[11];
	char name[11];
	DWORD value1;
	DWORD value2;
	DWORD value3;
};

#if(RANKINGGOC == 1)
struct SDHP_CUSTOM_RANKING_RECV
{
    PBMSG_HEAD header; // C1:F4
	WORD index;
	WORD type;
};
#endif

//---------------------------------------------------
#if(RANKING_NEW == 1)

#define MAXTOP   10
#define MAXTOPDW 10
#define MAXTOPDK 10
#define MAXTOPEF 10
#define MAXTOPMG 10
#define MAXTOPDL 10
#define MAXTOPSM 10
#define MAXTOPRF 10

#define MAXTOPNAP 10

#define MAXTOPBLOOD 10
#define MAXTOPDEVIL 10
#define MAXTOPCHAOS 10

struct GDTop
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTop
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTop
{
	PSWMSG_HEAD h;
	CharTop	tp[MAXTOP];
};

//==============================================
struct GDTopDW
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopDW
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopDW
{
	PSWMSG_HEAD h;
	CharTopDW	tp[MAXTOPDW];
};

//==============================================
struct GDTopDK
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopDK
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopDK
{
	PSWMSG_HEAD h;
	CharTopDK	tp[MAXTOPDK];
};
//==============================================
struct GDTopEF
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopEF
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopEF
{
	PSWMSG_HEAD h;
	CharTopEF	tp[MAXTOPEF];
};
//==============================================
struct GDTopMG
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopMG
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopMG
{
	PSWMSG_HEAD h;
	CharTopMG	tp[MAXTOPMG];
};
//==============================================
struct GDTopDL
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopDL
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopDL
{
	PSWMSG_HEAD h;
	CharTopDL	tp[MAXTOPDL];
};
//==============================================
struct GDTopSM
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopSM
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopSM
{
	PSWMSG_HEAD h;
	CharTopSM	tp[MAXTOPSM];
};
//==============================================
struct GDTopRF
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopRF
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	char Guild[9];
};
struct DGCharTopRF
{
	PSWMSG_HEAD h;
	CharTopRF	tp[MAXTOPRF];
};

//==============================================
struct GDTopNAP
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopNAP
{
	char Name[11];
	int TopNap;
};
struct DGCharTopNAP
{
	PSWMSG_HEAD h;
	CharTopNAP	tp[MAXTOPNAP];
};
//==============================================
struct GDTopBLOOD
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopBLOOD
{
	char Name[11];
	int TopBLOOD;
};
struct DGCharTopBLOOD
{
	PSWMSG_HEAD h;
	CharTopBLOOD	tp[MAXTOPBLOOD];
};
//==============================================
struct GDTopDEVIL
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopDEVIL
{
	char Name[11];
	int TopDEVIL;
};
struct DGCharTopDEVIL
{
	PSWMSG_HEAD h;
	CharTopDEVIL	tp[MAXTOPDEVIL];
};
//==============================================
struct GDTopCHAOS
{
	PSWMSG_HEAD h;
	BYTE Result;
};
struct CharTopCHAOS
{
	char Name[11];
	int TopCHAOS;
};
struct DGCharTopCHAOS
{
	PSWMSG_HEAD h;
	CharTopCHAOS	tp[MAXTOPCHAOS];
};
#endif

//----------------------------------------------------

struct SDHP_CARESUME_RECV
{
    PBMSG_HEAD header; // C1:F5
    WORD index;
    char name[11];
};

struct SDHP_CARESUME_SAVE_RECV
{
    PBMSG_HEAD header; // C1:F6
    WORD index;
    char name[11];
	WORD active;
	WORD skill;
	WORD map;
	WORD posx;
	WORD posy;
	WORD autobuff;
	WORD offpvp;
	WORD autoreset;
	DWORD autoaddstr;
	DWORD autoaddagi;
	DWORD autoaddvit;
	DWORD autoaddene;
	DWORD autoaddcmd;
};

struct SDHP_RANKING_TVT_EVENT_SAVE_RECV
{
	PBMSG_HEAD header; // C1:55
	WORD index;
	char account[11];
	char name[11];
	DWORD killcount;
	DWORD deathcount;
};

struct SDHP_CUSTOMNPCQUEST_RECV
{
    PSBMSG_HEAD header; // C1:F1
    WORD index;
    char name[11];
    WORD quest;
	WORD indexnpc;
};

struct SDHP_CUSTOMNPCQUEST_SAVE_RECV
{
    PSBMSG_HEAD header; // C1:F2
    WORD index;
    char name[11];
	WORD quest;
};

struct SDHP_CUSTOMNPCQUESTMONSTERSAVE_RECV
{
    PSBMSG_HEAD header; // C1:F1
    WORD index;
    char name[11];
    WORD quest;
	DWORD monsterqtd;
};

//**********************************************//
//********** DataServer -> GameServer **********//
//**********************************************//

struct SDHP_SERVER_INFO_SEND
{
	PBMSG_HEAD header; // C1:00
	BYTE result;
	DWORD ItemCount;
};

struct SDHP_CHARACTER_LIST_SEND
{
	PWMSG_HEAD header; // C2:01
	WORD index;
	char account[11];
	BYTE MoveCnt;
	BYTE ExtClass;
	#if(DATASERVER_UPDATE>=602)
	BYTE ExtWarehouse;
	#endif
	BYTE count;
};

struct SDHP_CHARACTER_LIST
{
	BYTE slot;
	char name[11];
	WORD level;
	BYTE Class;
	BYTE CtlCode;
	BYTE Inventory[60];
	BYTE GuildStatus;
	DWORD Reset;
	DWORD MasterReset;
};

struct SDHP_CHARACTER_CREATE_SEND
{
	PBMSG_HEAD header; // C1:02
	WORD index;
	char account[11];
	char name[11];
	BYTE result;
	BYTE slot;
	BYTE Class;
	BYTE equipment[24];
	WORD level;
};

struct SDHP_CHARACTER_DELETE_SEND
{
	PBMSG_HEAD header; // C1:03
	WORD index;
	char account[11];
	BYTE result;
};

struct SDHP_CHARACTER_INFO_SEND
{
	PWMSG_HEAD header; // C2:04
	WORD index;
	char account[11];
	char name[11];
	BYTE result;
	BYTE Class;
	WORD Level;
	DWORD LevelUpPoint;
	DWORD Experience;
	DWORD Money;
	DWORD Strength;
	DWORD Dexterity;
	DWORD Vitality;
	DWORD Energy;
	DWORD Leadership;
	DWORD Life;
	DWORD MaxLife;
	DWORD Mana;
	DWORD MaxMana;
	DWORD BP;
	DWORD MaxBP;
	DWORD Shield;
	DWORD MaxShield;
	BYTE Inventory[INVENTORY_SIZE][16];
	BYTE Skill[MAX_SKILL_LIST][3];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	DWORD PKCount;
	DWORD PKLevel;
	DWORD PKTime;
	BYTE CtlCode;
	BYTE Quest[50];
	WORD FruitAddPoint;
	WORD FruitSubPoint;
	BYTE Effect[MAX_EFFECT_LIST][13];
	#if(DATASERVER_UPDATE>=602)
	BYTE ExtInventory;
	BYTE ExtWarehouse;
	#endif
	DWORD Reset;
	DWORD MasterReset;
	#if(DATASERVER_UPDATE>=801)
	DWORD UseGuildMatching;
	DWORD UseGuildMatchingJoin;
	#endif
	DWORD Kills;
	DWORD Deads;
	BYTE TheGift; // only add in is struct
	int freePoints;
	int GensExitTick;
#if(DANH_HIEU_NEW)
	int rDanhHieu;
#endif
#if(THUE_VIP_NEW)
	int rThueVip;
	int rThueVipTime;
#endif
#if(TU_LUYEN_NEW)
	int rTuLuyen;
#endif
#if(NGU_HANH_NEW)
	int rNguHanh;
#endif
#if(RESETLIFE_NEW)
	int rResetLife;
#endif
#if (CHIENTRUONGCO == 1)
	int CTCTime;
	int CTCRegDay;
#endif
#if (LEOTHAP == 1)
	int TowerCount;
	DWORD TowerTime;
#endif
#if (WINDOWSQUEST == 1)
	BYTE ExWQuestStart[3];
	WORD ExWQuestNum[3];
	WORD ExWQuestCount[3][5];
#endif
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
};

struct SDHP_CREATE_ITEM_SEND
{
	PBMSG_HEAD header; // C1:07
	WORD index;
	char account[11];
	BYTE X;
	BYTE Y;
	BYTE Map;
	DWORD Serial;
	WORD ItemIndex;
	BYTE Level;
	BYTE Dur;
	BYTE Option1;
	BYTE Option2;
	BYTE Option3;
	BYTE NewOption;
	WORD LootIndex;
	BYTE SetOption;
	BYTE JewelOfHarmonyOption;
	BYTE ItemOptionEx;
	BYTE SocketOption[5];
	BYTE SocketOptionBonus;
	DWORD Duration;
};

struct SDHP_OPTION_DATA_SEND
{
	PBMSG_HEAD header; // C1:08
	WORD index;
	char account[11];
	char name[11];
	BYTE SkillKey[20];
	BYTE GameOption;
	BYTE QKey;
	BYTE WKey;
	BYTE EKey;
	BYTE ChatWindow;
	BYTE RKey;
	DWORD QWERLevel;
	#if(DATASERVER_UPDATE>=701)
	BYTE ChangeSkin;
	#endif
};

struct SDHP_PET_ITEM_INFO_SEND
{
	PWMSG_HEAD header; // C2:09
	WORD index;
	char account[11];
	BYTE type;
	BYTE count;
};

struct SDHP_PET_ITEM_INFO2
{
	BYTE slot;
	DWORD serial;
	BYTE level;
	DWORD experience;
};

struct SDHP_CHARACTER_NAME_CHECK_SEND
{
	PBMSG_HEAD header; // C1:0A
	WORD index;
	char account[11];
	char name[11];
	BYTE result;
};

struct SDHP_CHARACTER_NAME_CHANGE_SEND
{
	PBMSG_HEAD header; // C1:0B
	WORD index;
	char account[11];
	char OldName[11];
	char NewName[11];
	BYTE result;
};

struct SDHP_CRYWOLF_SYNC_SEND
{
	PBMSG_HEAD header; // C1:1E
	WORD MapServerGroup;
	DWORD CrywolfState;
	DWORD OccupationState;
};

struct SDHP_CRYWOLF_INFO_SEND
{
	PBMSG_HEAD header; // C1:1F
	WORD MapServerGroup;
	DWORD CrywolfState;
	DWORD OccupationState;
};

struct SDHP_GLOBAL_POST_SEND
{
	PBMSG_HEAD header; // C1:20
	WORD MapServerGroup;
	BYTE type;
	char name[11];
	char message[60];
};
//addpostitem
struct SDHP_GLOBAL_ITEM_POST_SEND
{
	PBMSG_HEAD header; // C1:78
	WORD MapServerGroup;
	char name[11];
	char message[60];
	char item_data[107];
};
struct SDHP_GLOBAL_NOTICE_SEND
{
	PBMSG_HEAD header; // C1:21
	WORD MapServerGroup;
	BYTE type;
	BYTE count;
	BYTE opacity;
	WORD delay;
	DWORD color;
	BYTE speed;
	char message[128];
};

struct SDHP_SNS_DATA_SEND
{
	PWMSG_HEAD header; // C1:24
	WORD index;
	char account[11];
	char name[11];
	BYTE result;
	BYTE data[256];
};

struct SDHP_GLOBAL_WHISPER_SEND
{
	PBMSG_HEAD header; // C1:72
	WORD index;
	char account[11];
	char name[11];
	BYTE result;
	char TargetName[11];
	char message[60];
};

struct SDHP_GLOBAL_WHISPER_ECHO_SEND
{
	PBMSG_HEAD header; // C1:73
	WORD index;
	char account[11];
	char name[11];
	char SourceName[11];
	char message[60];
};
//====================================================
#if (GHRS_TOP1_NEW)
struct SDHP_CUSTOM_GHRS_RECV
{
	PBMSG_HEAD header; // C1:F0:09
	int time;
};
#endif

#if(RSTIME == 1)
struct SDHP_CUSTOM_RSTIME_RECV
{
	PBMSG_HEAD header; // C1:F0:09
	WORD time;
};
#endif
//====================================================
struct SDHP_CUSTOMQUEST_SEND
{
    PBMSG_HEAD header; // C1:F1
    WORD index;
    char name[11];
	DWORD quest;
};

struct PMSG_CUSTOM_RANKING_SEND
{
	PWMSG_HEAD header; 
	int index;
	int type;
	int count;
};

struct SDHP_CARESUME_SEND
{
    PBMSG_HEAD header; // C1:F5
    WORD index;
    char name[11];
	WORD active;
	WORD skill;
	WORD map;
	WORD posx;
	WORD posy;
	WORD autobuff;
	WORD offpvp;
	WORD autoreset;
	DWORD autoaddstr;
	DWORD autoaddagi;
	DWORD autoaddvit;
	DWORD autoaddene;
	DWORD autoaddcmd;
};

struct SDHP_CUSTOMNPCQUEST_SEND
{
    PSBMSG_HEAD header; // C1:F1
    WORD index;
    WORD quest;
	WORD indexnpc;
	DWORD questcount;
	DWORD monstercount;
};

struct THEGIFT_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	BYTE	TheGift;
};

#if(CAPNHAP_DATASERVER == 1)
struct CAPNHAPTIME_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
};
#endif

#if(BOT_STATUE == 1)
struct SDHP_BOT_INFO_GET
{
	PBMSG_HEAD header; // C1:04
	WORD index;
	WORD Rank;
	WORD TypeTop;
};
//=========================
struct SDHP_BOT_INFO_SEND
{
	PWMSG_HEAD header; // C2:04
	WORD index;
	BYTE result;
	char name[11];
	BYTE Class;
	WORD Level;
	DWORD LevelUpPoint;
	DWORD Experience;
	DWORD Money;
	DWORD Strength;
	DWORD Dexterity;
	DWORD Vitality;
	DWORD Energy;
	DWORD Leadership;
	DWORD Life;
	DWORD MaxLife;
	DWORD Mana;
	DWORD MaxMana;
	DWORD BP;
	DWORD MaxBP;
	DWORD Shield;
	DWORD MaxShield;
	BYTE Inventory[INVENTORY_SIZE][16];
	BYTE Skill[MAX_SKILL_LIST][3];
	BYTE Dir;
	DWORD PKCount;
	DWORD PKLevel;
	DWORD PKTime;
	BYTE CtlCode;
	WORD FruitAddPoint;
	WORD FruitSubPoint;
	BYTE Effect[MAX_EFFECT_LIST][13];
	DWORD Kills;
	DWORD Deads;
	int rDanhHieu;
	// GUild
	char GuildName[9];
	int GuildNumber;
	int GuildStatus;
};
#endif


#if (GHRS_TOP1_NEW)
struct PMSG_CUSTOM_GHRS_SEND
{
	PWMSG_HEAD header;
	int time;
	int resets;
	int Grand;
};
#endif

#if (ARCHIVEMENT == 1)

#define ACHIEVEMENTS_COUNT 50

struct PMSG_GDREQ_ACH_LOAD
{
	PSBMSG_HEAD h;
	int aIndex;
	char szName[11];
};

struct PMSG_DGANS_ACH_LOAD
{
	PSBMSG_HEAD h;
	int aIndex;
	bool bResult;
	unsigned int counter[ACHIEVEMENTS_COUNT];
};

struct PMSG_GDREQ_ACH_SAVE
{
	PSBMSG_HEAD h;
	char szName[11];
	//ACHIEVEMENTS_DATA usr;
	unsigned int counter[50];
};
#endif
//====================================================
#if (KINH_MACH_NEW == 1)
struct KINHMACH_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
struct KINHMACH_DG_GET_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	int		KINHMACH1;
	int		KINHMACH2;
	int		KINHMACH3;
	int		KINHMACH4;
	int		KINHMACH5;
	int		KINHMACH6;
	int		KINHMACH7;
	int		KINHMACH8;
	int		KINHMACHSD;
	int		KINHMACHHP;
};
struct KINHMACH_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int		KINHMACH1;
	int		KINHMACH2;
	int		KINHMACH3;
	int		KINHMACH4;
	int		KINHMACH5;
	int		KINHMACH6;
	int		KINHMACH7;
	int		KINHMACH8;
	int		KINHMACHSD;
	int		KINHMACHHP;
};
#endif
//====================================================
#if (SACHTHUOCTINH_NEW)
struct SACHTHUOCTINH_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
struct SACHTHUOCTINH_DG_GET_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	int SACHTHUOCTINH_01;
	int SACHTHUOCTINH_02;
	int SACHTHUOCTINH_03;
	int SACHTHUOCTINH_04;
	int SACHTHUOCTINH_05;
	int SACHTHUOCTINH_06;
	int SACHTHUOCTINH_07;
};
struct SACHTHUOCTINH_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int SACHTHUOCTINH_01;
	int SACHTHUOCTINH_02;
	int SACHTHUOCTINH_03;
	int SACHTHUOCTINH_04;
	int SACHTHUOCTINH_05;
	int SACHTHUOCTINH_06;
	int SACHTHUOCTINH_07;
};
#endif
//====================================================
#if (CUSTOM_GIOIHAN == 1)
struct GIOIHAN_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
struct GIOIHAN_DG_GET_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	int BloodCastle;
	int DevilSquare;
	int ChaosCastle;
};
struct GIOIHAN_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int BloodCastle;
	int DevilSquare;
	int ChaosCastle;
};
#endif
//====================================================
#if (MUUNAFK == 1)
struct MUUNAFK_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
struct MUUNAFK_DG_GET_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	int MuunAFKTime;
	int MuunAFKStamina;
	int MuunAFKWCoinClaim;
};
struct MUUNAFK_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int MuunAFKTime;
	int MuunAFKStamina;
	int MuunAFKWCoinClaim;
};
#endif
//====================================================
#if (PHUKIEN_NEW == 1)
struct PHUKIEN_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
//
struct PHUKIEN_DG_GET_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	int		PHUKIEN1;
	int		PHUKIEN2;
};
//
struct PHUKIEN_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int		PHUKIEN1;
	int		PHUKIEN2;
};
#endif
//====================================================
#if (MOCNAP == 1)
struct MOCNAP_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
struct MOCNAP_DG_GET_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	int		MOCNAPCOIN;
	int		MOCNAP1;
	int		MOCNAP2;
	int		MOCNAP3;
	int		MOCNAP4;
	int		MOCNAP5;
	int		MOCNAP6;
	int		MOCNAP7;
	int		MOCNAP8;
	int		MOCNAP9;
	int		MOCNAP10;
	int		MOCNAP11;
	int		MOCNAP12;
	int		MOCNAP13;
};
struct MOCNAP_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	// ----
	WORD	index;
	char	Name[11];
	int		MOCNAPCOIN;
	int		MOCNAP1;
	int		MOCNAP2;
	int		MOCNAP3;
	int		MOCNAP4;
	int		MOCNAP5;
	int		MOCNAP6;
	int		MOCNAP7;
	int		MOCNAP8;
	int		MOCNAP9;
	int		MOCNAP10;
	int		MOCNAP11;
	int		MOCNAP12;
	int		MOCNAP13;
};
#endif
//====================================================
//**********************************************//
//**********************************************//
//**********************************************//
void GDSaveTheGiftRecv(THEGIFT_GD_SAVE_DATA* lpMsg);

#if(CAPNHAP_DATASERVER == 1)
void GDSaveCapNhapTimeRecv(CAPNHAPTIME_GD_SAVE_DATA* lpMsg);
#endif

void DataServerProtocolCore(int index,BYTE head,BYTE* lpMsg,int size);
void GDServerInfoRecv(SDHP_SERVER_INFO_RECV* lpMsg,int index);
void GDCharacterListRecv(SDHP_CHARACTER_LIST_RECV* lpMsg,int index);
void GDCharacterCreateRecv(SDHP_CHARACTER_CREATE_RECV* lpMsg,int index);
void GDCharacterDeleteRecv(SDHP_CHARACTER_DELETE_RECV* lpMsg,int index);
void GDCharacterInfoRecv(SDHP_CHARACTER_INFO_RECV* lpMsg,int index);
void GDCreateItemRecv(SDHP_CREATE_ITEM_RECV* lpMsg,int index);
void GDOptionDataRecv(SDHP_OPTION_DATA_RECV* lpMsg,int index);
void GDPetItemInfoRecv(SDHP_PET_ITEM_INFO_RECV* lpMsg,int index);
void GDCharacterNameCheckRecv(SDHP_CHARACTER_NAME_CHECK_RECV* lpMsg,int index);
void GDCharacterNameChangeRecv(SDHP_CHARACTER_NAME_CHANGE_RECV* lpMsg,int index);
void GDCrywolfSyncRecv(SDHP_CRYWOLF_SYNC_RECV* lpMsg,int index);
void GDCrywolfInfoRecv(SDHP_CRYWOLF_INFO_RECV* lpMsg,int index);
void GDGlobalPostRecv(SDHP_GLOBAL_POST_RECV* lpMsg,int index);
//addpostitem
void GDGlobalItemPostRecv(SDHP_GLOBAL_ITEM_POST_RECV* lpMsg, int index);
void GDGlobalNoticeRecv(SDHP_GLOBAL_NOTICE_RECV* lpMsg,int index);
void GDSNSDataRecv(SDHP_SNS_DATA_RECV* lpMsg,int index);
void GDCharacterInfoSaveRecv(SDHP_CHARACTER_INFO_SAVE_RECV* lpMsg);
void GDInventoryItemSaveRecv(SDHP_INVENTORY_ITEM_SAVE_RECV* lpMsg);
void GDOptionDataSaveRecv(SDHP_OPTION_DATA_SAVE_RECV* lpMsg);
void GDPetItemInfoSaveRecv(SDHP_PET_ITEM_INFO_SAVE_RECV* lpMsg);
void GDResetInfoSaveRecv(SDHP_RESET_INFO_SAVE_RECV* lpMsg);
void GDMasterResetInfoSaveRecv(SDHP_MASTER_RESET_INFO_SAVE_RECV* lpMsg);
void GDRankingDuelSaveRecv(SDHP_RANKING_DUEL_SAVE_RECV* lpMsg);
void GDRankingBloodCastleSaveRecv(SDHP_RANKING_BLOOD_CASTLE_SAVE_RECV* lpMsg);
void GDRankingChaosCastleSaveRecv(SDHP_RANKING_CHAOS_CASTLE_SAVE_RECV* lpMsg);
void GDRankingDevilSquareSaveRecv(SDHP_RANKING_DEVIL_SQUARE_SAVE_RECV* lpMsg);
void GDRankingIllusionTempleSaveRecv(SDHP_RANKING_ILLUSION_TEMPLE_SAVE_RECV* lpMsg);
void GDCreationCardSaveRecv(SDHP_CREATION_CARD_SAVE_RECV* lpMsg);
void GDCrywolfInfoSaveRecv(SDHP_CRYWOLF_INFO_SAVE_RECV* lpMsg);
void GDSNSDataSaveRecv(SDHP_SNS_DATA_SAVE_RECV* lpMsg);
void GDCustomMonsterRewardSaveRecv(SDHP_CUSTOM_MONSTER_REWARD_SAVE_RECV* lpMsg);
void GDRankingCustomArenaSaveRecv(SDHP_RANKING_CUSTOM_ARENA_SAVE_RECV* lpMsg);
void GDRankingTvTEventSaveRecv(SDHP_RANKING_TVT_EVENT_SAVE_RECV* lpMsg);
void GDConnectCharacterRecv(SDHP_CONNECT_CHARACTER_RECV* lpMsg,int index);
void GDDisconnectCharacterRecv(SDHP_DISCONNECT_CHARACTER_RECV* lpMsg,int index);
void GDGlobalWhisperRecv(SDHP_GLOBAL_WHISPER_RECV* lpMsg,int index);
void DGGlobalWhisperEchoSend(WORD ServerCode,WORD index,char* account,char* name,char* SourceName,char* message);
//===================================================================================
#if (GHRS_TOP1_NEW)
void GDCustomGHRSRecv(SDHP_CUSTOM_GHRS_RECV* lpMsg, int index);
#endif
#if(RSTIME == 1)
void GDCustomRSTIMERecv(SDHP_CUSTOM_RSTIME_RECV* lpMsg, int index);
#endif
//===================================================================================
void GDMarryInfoSaveRecv(SDHP_MARRY_INFO_SAVE_RECV* lpMsg);

#if(HIDE_VT)
void GDCustomQuestSaveRecv(SDHP_CUSTOMQUEST_SAVE_RECV* lpMsg);
void GDCustomQuestRecv(SDHP_CUSTOMQUEST_RECV* lpMsg,int index);
#endif


void GDSetCoinRecv(SDHP_SETCOIN_RECV* lpMsg);
#if(RANKINGGOC == 1)
void GDCustomRankingRecv(SDHP_CUSTOM_RANKING_RECV* lpMsg,int index);
#endif
void GDCustomAttackResumeRecv(SDHP_CARESUME_RECV* lpMsg,int index);
void GDCustomAttackSaveRecv(SDHP_CARESUME_SAVE_RECV* lpMsg);
void GDCustomNpcQuestSaveRecv(SDHP_CUSTOMNPCQUEST_SAVE_RECV* lpMsg);
void GDCustomNpcQuestRecv(SDHP_CUSTOMNPCQUEST_RECV* lpMsg,int index);
void GDCustomNpcQuestMonsterCountSaveRecv(SDHP_CUSTOMNPCQUESTMONSTERSAVE_RECV* lpMsg);

#if (ARCHIVEMENT == 1)
void DGAchievementsLoad(PMSG_GDREQ_ACH_LOAD* lpMsg, int aIndex);
void GDAchievementsSave(PMSG_GDREQ_ACH_SAVE* lpMsg, int aIndex);
#endif

#if(RANKING_NEW == 1)
void CharacterRanking(GDTop* lpMsg, int pIndex);
void CharacterRankingDW(GDTopDW* lpMsg, int pIndex);
void CharacterRankingDK(GDTopDK* lpMsg, int pIndex);
void CharacterRankingEF(GDTopEF* lpMsg, int pIndex);
void CharacterRankingMG(GDTopMG* lpMsg, int pIndex);
void CharacterRankingDL(GDTopDL* lpMsg, int pIndex);
void CharacterRankingSM(GDTopSM* lpMsg, int pIndex);
void CharacterRankingRF(GDTopRF* lpMsg, int pIndex);
void CharacterRankingNAP(GDTopNAP* lpMsg, int pIndex);
void CharacterRankingBLOOD(GDTopBLOOD* lpMsg, int pIndex);
void CharacterRankingDEVIL(GDTopDEVIL* lpMsg, int pIndex);
void CharacterRankingCHAOS(GDTopCHAOS* lpMsg, int pIndex);
#endif
//===================================================================================
#if (KINH_MACH_NEW)
void GDCharacterKinhMachRecv(KINHMACH_GD_REQ_DATA* lpMsg, int index);
void GDCharacterKinhMachSaveRecv(KINHMACH_GD_SAVE_DATA* lpMsg);
#endif
//===================================================================================
#if (SACHTHUOCTINH_NEW)
void GDCharacterSachThuocTinhRecv(SACHTHUOCTINH_GD_REQ_DATA* lpMsg, int index);
void GDCharacterSachThuocTinhSaveRecv(SACHTHUOCTINH_GD_SAVE_DATA* lpMsg);
#endif
//===================================================================================
#if (CUSTOM_GIOIHAN == 1)
void GDCharacterGioiHanRecv(GIOIHAN_GD_REQ_DATA* lpMsg, int index);
void GDCharacterGioiHanSaveRecv(GIOIHAN_GD_SAVE_DATA* lpMsg);
#endif
//===================================================================================
#if (MUUNAFK == 1)
void GDCharacterMuunAFKRecv(MUUNAFK_GD_REQ_DATA* lpMsg, int index);
void GDCharacterMuunAFKSaveRecv(MUUNAFK_GD_SAVE_DATA* lpMsg);
#endif
//===================================================================================
#if (PHUKIEN_NEW == 1)
void GDCharacterPhuKienRecv(PHUKIEN_GD_REQ_DATA* lpMsg, int index);
void GDCharacterPhuKienSaveRecv(PHUKIEN_GD_SAVE_DATA* lpMsg);
#endif
//===================================================================================
#if (MOCNAP == 1)
void GDCharacterMocNapRecv(MOCNAP_GD_REQ_DATA* lpMsg, int index);
void GDCharacterMocNapSaveRecv(MOCNAP_GD_SAVE_DATA* lpMsg);
#endif

//===================================================================================
#if (BOT_STATUE == 1)
void GDBotInfoRecv(SDHP_BOT_INFO_GET* lpMsg, int index);
#endif
//===================================================================================
//**************************************************************************//
// RAW FUNCTIONS ***********************************************************//
//**************************************************************************//

void DS_GDReqCastleTotalInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqOwnerGuildMaster(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleNpcBuy(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleNpcRepair(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleNpcUpgrade(BYTE *lpRecv, int aIndex);
void DS_GDReqTaxInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqTaxRateChange(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleMoneyChange(BYTE *lpRecv, int aIndex);
void DS_GDReqSiegeDateChange(BYTE *lpRecv, int aIndex);
void DS_GDReqGuildMarkRegInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqSiegeEndedChange(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleOwnerChange(BYTE *lpRecv, int aIndex);
void DS_GDReqRegAttackGuild(BYTE *lpRecv, int aIndex);
void DS_GDReqRestartCastleState(BYTE *lpRecv, int aIndex);
void DS_GDReqMapSvrMsgMultiCast(BYTE *lpRecv, int aIndex);
void DS_GDReqRegGuildMark(BYTE *lpRecv, int aIndex);
void DS_GDReqGuildMarkReset(BYTE *lpRecv, int aIndex);
void DS_GDReqGuildSetGiveUp(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleNpcRemove(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleStateSync(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleTributeMoney(BYTE *lpRecv, int aIndex);
void DS_GDReqResetCastleTaxInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqResetSiegeGuildInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqResetRegSiegeInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleInitData(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleNpcInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqAllGuildMarkRegInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqFirstCreateNPC(BYTE *lpRecv, int aIndex);
void DS_GDReqCalcRegGuildList(BYTE *lpRecv, int aIndex);
void DS_GDReqCsGuildUnionInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqCsSaveTotalGuildInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqCsLoadTotalGuildInfo(BYTE *lpRecv, int aIndex);
void DS_GDReqCastleNpcUpdate(BYTE *lpRecv, int aIndex);


