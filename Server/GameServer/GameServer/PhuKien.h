#include "user.h"
#include "Protocol.h"

#if(PHUKIEN_NEW == 1)

struct PHUKIEN_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	// ----
	WORD	index;
	char	Name[11];
	// ----
	int		PHUKIEN1;
	int		PHUKIEN2;
	// ----
};

// -------------------------------------------------------------------------------
struct PHUKIEN_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
// -------------------------------------------------------------------------------


struct PHUKIEN_DG_GET_DATA
{
	PSBMSG_HEAD	header;
	// ----
	WORD	index;
	// ----
	int		PHUKIEN1;
	int		PHUKIEN2;
	// ----
};

// -------------------------------------------------------------------------------
struct ACTIVE_PHUKIEN_REQ
{
	PSBMSG_HEAD h;
	int			Type;
	int			Number;
};

//  ------------------------------------------------------------------------------
struct BUY_PHUKIEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------

void PhuKienDataSend(int aIndex);

class PhuKien
{
public:
	// ----
	PhuKien();
	virtual ~PhuKien();

	void	Load();

	void		GDSaveData(int aIndex);
	void		GDReqData(int aIndex);
	void		GDSaveUserInfo(int aIndex);
	void		GDReqUserInfo(int aIndex);
	void		DGGetData(PHUKIEN_DG_GET_DATA * aRecv);

	void		BUG_PHUKIEN(LPOBJ lpObj, BUY_PHUKIEN_REQ *aRecv);

	void		Option(LPOBJ lpObj, bool flag);

	int		MAX_PHUKIEN1;
	int		MAX_PHUKIEN2;

	int		ID_PHUKIEN1;
	int		ID_PHUKIEN2;

	int		OP1_PHUKIEN1;
	int		OP2_PHUKIEN1;
	int		OP3_PHUKIEN1;
	int		OP4_PHUKIEN1;
	int		OP5_PHUKIEN1;
	int		OP6_PHUKIEN1;
	int		OP7_PHUKIEN1;

	int		OP1_PHUKIEN2;
	int		OP2_PHUKIEN2;
	int		OP3_PHUKIEN2;
	int		OP4_PHUKIEN2;
	int		OP5_PHUKIEN2;
	int		OP6_PHUKIEN2;
	int		OP7_PHUKIEN2;

	char MSG_01[1024];
	char MSG_02[1024];

	// ----
	PHUKIEN_GD_REQ_DATA PHUKIEN;
	// ----

private:

}; extern PhuKien gPhuKien;

#endif
// -------------------------------------------------------------------------------