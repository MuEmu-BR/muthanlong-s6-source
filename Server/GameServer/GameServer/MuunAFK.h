
#include "User.h"
#include "DSProtocol.h"

#if(MUUNAFK == 1)

struct MUUNAFK_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int MuunAFKTime;
	int MuunAFKStamina;
	int MuunAFKWCoinClaim;
};

struct MUUNAFK_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
// -------------------------------------------------------------------------------
struct MUUNAFK_DG_GET_DATA
{
	PSBMSG_HEAD	header;
	WORD	index;
	int MuunAFKTime;
	int MuunAFKStamina;
	int MuunAFKWCoinClaim;
};

struct MuunAFK_Time
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct MuunAFKStamina_Time
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct MUUNPETAFK_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	int	MuunAFKTime;
	int MuunAFKStamina;
	int MuunAFKWCoinClaim;
};



#define MAX_PET_WCOINC 300
// ---
struct  PET_WCOINC
{
	int  m_Type;
	int  m_Index;
	int  m_WCoin;
	int  m_TuyChinh;
};
// ---

#define MAX_PET_WCOINC_STAMINA 300
// ---
struct  PET_WCOINC_STAMINA
{
	int  m_Type;
	int  m_Index;
	int  m_WCoin;
	int  m_TuyChinh;
};
// ---

void MuunAFKDataSend(int aIndex);

//==============================
class MuunAFK
{
public:
	void Init();
	void InitStamina();

	void GDSaveData(int aIndex);
	void GDReqData(int aIndex);
	void GDSaveUserInfo(int aIndex);
	void GDReqUserInfo(int aIndex);
	void DGGetData(MUUNAFK_DG_GET_DATA * aRecv);

	void MainProc();
	void MainProcStamina();

	void Read(char * path);
	void Load(char* path);

	//---
	void LoadPetWCoinC(char* path);
	PET_WCOINC m_Data[MAX_PET_WCOINC];
	int m_count;
	//---
	void LoadPetWCoinCStamina(char* path);
	PET_WCOINC_STAMINA m_DataStamina[MAX_PET_WCOINC_STAMINA];
	int m_count_stamina;
	//---

	void RunMuunAFK();
	void RunMuunAFKStamina();

	void HoiStamina(LPOBJ lpObj);

	void NhanWCoinClaim(LPOBJ lpObj);

	void TimeMuunPet(int aIndex, int Type);

	void CheckSync();
	void CheckSyncStamina();

	int Debug;
	int m_Enabled;

	int m_DiemStamina;

	int m_SetThoiGian;

	int m_Stamina100Den90;
	int m_Stamina90Den80;
	int m_Stamina80Den70;
	int m_Stamina70Den60;
	int m_Stamina60Den50;
	int m_Stamina50Den40;
	int m_Stamina40Den30;
	int m_Stamina30Den20;
	int m_Stamina20Den10;
	int m_Stamina10Den00;

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

	std::vector<MuunAFK_Time> m_MuunAFK_Time;

	std::vector<MuunAFKStamina_Time> m_MuunAFKStamina_Time;

private:

	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;

	int m_RemainTimeStamina;
	int TargetTimeStamina;
	DWORD m_TickCountStamina;

};

extern  MuunAFK gMuunAFK;

#endif