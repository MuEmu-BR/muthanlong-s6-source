#pragma once
#if(CHONSERVER == 1)

class CCriticalSection
{
public:
	CCriticalSection();
	virtual ~CCriticalSection();
	void lock();
	void unlock();
private:
	CRITICAL_SECTION m_critical;
};
#endif