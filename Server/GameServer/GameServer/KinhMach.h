#include "user.h"
#include "Protocol.h"

#if(KINHMACH_NEW == 1)

struct KINHMACH_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	WORD	index;
	char	Name[11];
	int	KINHMACH1;
	int	KINHMACH2;
	int	KINHMACH3;
	int	KINHMACH4;
	int	KINHMACH5;
	int	KINHMACH6;
	int	KINHMACH7;
	int	KINHMACH8;
	int KINHMACHSD;
	int KINHMACHHP;
};

// -------------------------------------------------------------------------------
struct KINHMACH_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
// -------------------------------------------------------------------------------


struct KINHMACH_DG_GET_DATA
{
	PSBMSG_HEAD	header;
	WORD	index;
	int	KINHMACH1;
	int	KINHMACH2;
	int	KINHMACH3;
	int	KINHMACH4;
	int	KINHMACH5;
	int	KINHMACH6;
	int	KINHMACH7;
	int	KINHMACH8;
	int KINHMACHSD;
	int KINHMACHHP;
};

// -------------------------------------------------------------------------------
struct ACTIVE_KINHMACH_REQ
{
	PSBMSG_HEAD h;
	int			Type;
	int			Number;
};

//  ------------------------------------------------------------------------------
struct BUY_KINHMACH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------s
class KinhMach
{
public:
	// ----
	KinhMach();
	virtual ~KinhMach();

	void	Init();

	void		GDSaveData(int aIndex);
	void		GDReqData(int aIndex);
	void		GDSaveUserInfo(int aIndex);
	void		GDReqUserInfo(int aIndex);
	void		DGGetData(KINHMACH_DG_GET_DATA * aRecv);

	void		BUG_KINHMACH(LPOBJ lpObj, BUY_KINHMACH_REQ *aRecv);

	void		Option(LPOBJ lpObj, bool flag);

	void	    Load();
	
	int	        MAX_KINH_MACH_01;
	int	        MAX_KINH_MACH_02;
	int	        MAX_KINH_MACH_03;
	int	        MAX_KINH_MACH_04;
	int	        MAX_KINH_MACH_05;
	int	        MAX_KINH_MACH_06;
	int	        MAX_KINH_MACH_07;
	int	        MAX_KINH_MACH_08;

	int	        POINTSD;
	int	        POINTHP;
	// ----
	KINHMACH_GD_REQ_DATA KINHMACH;
	// ----

private:

}; extern KinhMach gKinhMach;

#endif
// -------------------------------------------------------------------------------