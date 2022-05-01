
#include "User.h"
#include "DSProtocol.h"

//21-03-2022 

struct BANGXEPHANGALL_START_TIME
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
class BangXepHang
{
public:
	void Init();
	void MainProc();
	int Enabled;
	void Read(char * path);
	void SendRanking();
	void CheckSync();

	std::vector<BANGXEPHANGALL_START_TIME> m_TimeReloadInfoAll;

private:

	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;
};

extern  BangXepHang gBangXepHang;

