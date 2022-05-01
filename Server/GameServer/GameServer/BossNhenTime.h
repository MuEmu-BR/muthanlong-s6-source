
#include "User.h"
#include "DSProtocol.h"

#if(BOSS_NHEN_TIME == 1)

struct BOSSNHEN1_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

//==============================
class BossNhenTime
{
public:
	void Init();
	void MainProc();
	int Enabled;
	void Read(char * path);
	void KhoiDongBossNhen();
	void CheckSync();

	std::vector<BOSSNHEN1_START_TIME> m_TimeReloadInfo;

private:

	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;
};

extern  BossNhenTime gBossNhenTime;

#endif
