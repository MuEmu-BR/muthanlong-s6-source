#include "StdAfx.h"
#include "user.h"
#include "VanThanhProtect.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "ObjectManager.h"

VanThanhProtect gVanThanhProtect;
// -------------------------------------------------------------------------------
VanThanhProtect::VanThanhProtect() // OK
{
}
// -------------------------------------------------------------------------------
VanThanhProtect::~VanThanhProtect() // OK
{
}
// -------------------------------------------------------------------------------
void VanThanhProtect::Load()
{
	this->BangXepHang = GetPrivateProfileInt("Config", "BangXepHang", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TaoNhom = GetPrivateProfileInt("Config", "TaoNhom", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TimNhom = GetPrivateProfileInt("Config", "TimNhom", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TreoMay = GetPrivateProfileInt("Config", "TreoMay", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->VongQuay = GetPrivateProfileInt("Config", "VongQuay", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->DoiClass = GetPrivateProfileInt("Config", "DoiClass", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->DanhHieu = GetPrivateProfileInt("Config", "DanhHieu", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TuLuyen = GetPrivateProfileInt("Config", "TuLuyen", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->VipNhanVat = GetPrivateProfileInt("Config", "VipNhanVat", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->VipTaiKhoan = GetPrivateProfileInt("Config", "VipTaiKhoan", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->NguHanh = GetPrivateProfileInt("Config", "NguHanh", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->KinhMach = GetPrivateProfileInt("Config", "KinhMach", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->ThanhTuu = GetPrivateProfileInt("Config", "ThanhTuu", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->NganHangNgoc = GetPrivateProfileInt("Config", "NganHangNgoc", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->DiChuyenEvent = GetPrivateProfileInt("Config", "DiChuyenEvent", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->LamNhiemVu = GetPrivateProfileInt("Config", "LamNhiemVu", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TayDiem = GetPrivateProfileInt("Config", "TayDiem", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TayMaster = GetPrivateProfileInt("Config", "TayMaster", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->XoaHomDo = GetPrivateProfileInt("Config", "XoaHomDo", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->ChoTroi = GetPrivateProfileInt("Config", "ChoTroi", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TimShop = GetPrivateProfileInt("Config", "TimShop", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->MuunPet = GetPrivateProfileInt("Config", "MuunPet", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->MuunPetTime = GetPrivateProfileInt("Config", "MuunPetTime", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->MocNap = GetPrivateProfileInt("Config", "MocNap", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TaiSinhTrungSinh = GetPrivateProfileInt("Config", "TaiSinhTrungSinh", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->TinhNang = GetPrivateProfileInt("Config", "TinhNang", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->SachThuocTinh = GetPrivateProfileInt("Config", "SachThuocTinh", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->PhuKien = GetPrivateProfileInt("Config", "PhuKien", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	this->NhiemVu = GetPrivateProfileInt("Config", "NhiemVu", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
	//27-03-2022
	this->MonsterCall = GetPrivateProfileInt("Config", "MonsterCall", 0, gPath.GetFullPath("VanThanh\\VanThanhCpanel.ini"));
}

// -------------------------------------------------------------------------------
struct GIFCODE_UPDATE
{
	PBMSG_HEAD3 h;
	int GifCode;
};

void GifCodeDataSend(int aIndex)
{
	GIFCODE_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 111, sizeof(rSend));

	rSend.GifCode = lpObj->ItemStart;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}
// -------------------------------------------------------------------------------
struct VANTHANH_UPDATE
{
	PBMSG_HEAD3 h;
	int BangXepHang;
	int TaoNhom;
	int TimNhom;
	int TreoMay;
	int VongQuay;
	int DoiClass;
	int DanhHieu;
	int TuLuyen;
	int VipNhanVat;
	int VipTaiKhoan;
	int NguHanh;
	int KinhMach;
	int ThanhTuu;
	int NganHangNgoc;
	int DiChuyenEvent;
	int LamNhiemVu;
	int TayDiem;
	int TayMaster;
	int XoaHomDo;
	int ChoTroi;
	int TimShop;
	int MuunPet;
	int MuunPetTime;
	int MocNap;
	int TaiSinhTrungSinh;
	int TinhNang;
	int SachThuocTinh;
	int PhuKien;
	int NhiemVu;
};

void VanThanhDataSend(int aIndex)
{
	VANTHANH_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 112, sizeof(rSend));

	rSend.BangXepHang = gVanThanhProtect.BangXepHang;
	rSend.TaoNhom = gVanThanhProtect.TaoNhom;
	rSend.TimNhom = gVanThanhProtect.TimNhom;
	rSend.TreoMay = gVanThanhProtect.TreoMay;
	rSend.VongQuay = gVanThanhProtect.VongQuay;
	rSend.DoiClass = gVanThanhProtect.DoiClass;
	rSend.DanhHieu = gVanThanhProtect.DanhHieu;
	rSend.TuLuyen = gVanThanhProtect.TuLuyen;
	rSend.VipNhanVat = gVanThanhProtect.VipNhanVat;
	rSend.VipTaiKhoan = gVanThanhProtect.VipTaiKhoan;
	rSend.NguHanh = gVanThanhProtect.NguHanh;
	rSend.KinhMach = gVanThanhProtect.KinhMach;
	rSend.ThanhTuu = gVanThanhProtect.ThanhTuu;
	rSend.NganHangNgoc = gVanThanhProtect.NganHangNgoc;
	rSend.DiChuyenEvent = gVanThanhProtect.DiChuyenEvent;
	rSend.LamNhiemVu = gVanThanhProtect.LamNhiemVu;
	rSend.TayDiem = gVanThanhProtect.TayDiem;
	rSend.TayMaster = gVanThanhProtect.TayMaster;
	rSend.XoaHomDo = gVanThanhProtect.XoaHomDo;
	rSend.ChoTroi = gVanThanhProtect.ChoTroi;
	rSend.TimShop = gVanThanhProtect.TimShop;
	rSend.MuunPet = gVanThanhProtect.MuunPet;
	rSend.MuunPetTime = gVanThanhProtect.MuunPetTime;
	rSend.MocNap = gVanThanhProtect.MocNap;
	rSend.TaiSinhTrungSinh = gVanThanhProtect.TaiSinhTrungSinh;
	rSend.TinhNang = gVanThanhProtect.TinhNang;
	rSend.SachThuocTinh = gVanThanhProtect.SachThuocTinh;
	rSend.PhuKien = gVanThanhProtect.PhuKien;
	rSend.NhiemVu = gVanThanhProtect.NhiemVu;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}
