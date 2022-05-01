
#include "User.h"
#include "DSProtocol.h"

//21-03-2022 

struct MuunPetCustom_Time
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct MUUNPETTIME_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	int	MuunPetTime;
};

//==============================
class MuunPetCustom
{
public:
	void Init();
	void MainProc();
	int Enabled;
	void Read(char * path);

	void GiamMauMuunPet();

	void HoiMauMuunPet(LPOBJ lpObj);
	void HoiMauMuunPet1(LPOBJ lpObj);

	void TimeMuunPet(int aIndex, int Type);

	void CheckSync();

	int Debug;

	int MauPetGiam;
	int MauPetTang;


	std::vector<MuunPetCustom_Time> m_MuunPetCustom_Time;

private:

	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;
};

extern  MuunPetCustom gMuunPetCustom;

