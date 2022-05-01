#include "user.h"
#include "Protocol.h"
#pragma once
// -------------------------------------------------------------------------------
void VanThanhDataSend(int aIndex);
void GifCodeDataSend(int aIndex);

class VanThanhProtect
{
public:
	// ----
	VanThanhProtect();
	virtual ~VanThanhProtect();
	// ----
	void	    Load();
	// ----
	int         BangXepHang;
	int         TaoNhom;
	int         TimNhom;
	int         TreoMay;
	int         VongQuay;
	int         DoiClass;
	int         DanhHieu;
	int         TuLuyen;
	int         VipNhanVat;
	int         VipTaiKhoan;
	int         NguHanh;
	int         KinhMach;
	int         ThanhTuu;
	int         NganHangNgoc;
	int         DiChuyenEvent;
	int         LamNhiemVu;
	int         TayDiem;
	int         TayMaster;
	int         XoaHomDo;
	int         ChoTroi;
	int         TimShop;
	int         MuunPet;
	int         MuunPetTime;
	int         MocNap;
	int         TaiSinhTrungSinh;
	int         TinhNang;
	int         SachThuocTinh;
	int         PhuKien;
	int         NhiemVu;

	//27-03-2022
	int         MonsterCall;

	int         GifCode;
	// ----
}; extern VanThanhProtect gVanThanhProtect;
// -------------------------------------------------------------------------------