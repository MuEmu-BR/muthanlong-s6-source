
#include "User.h"
#include "DSProtocol.h"

struct CHIENTRUONGCO_START_TIME
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
class ChienTruongCoTime
{
public:
	void Init();
	void MainProc();
	int Enabled;
	void Read(char * path);
	void RsTime();
	void CheckSync();

	std::vector<CHIENTRUONGCO_START_TIME> m_TimeReloadInfo;

private:

	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;
};

extern  ChienTruongCoTime gChienTruongCoTime;

