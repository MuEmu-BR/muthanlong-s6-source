
#include "User.h"
#include "DSProtocol.h"

#if(CAPNHAP_DATASERVER == 1)

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
class CapNhapTime
{
public:
	void Init();
	void MainProc();
	int Enabled;
	void Read(char * path);
	void SendDateServer();
	void CheckSync();

	std::vector<CHIENTRUONGCO_START_TIME> m_TimeReloadInfo;

private:

	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;
};

extern  CapNhapTime gCapNhapTime;

#endif
