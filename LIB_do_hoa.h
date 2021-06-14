#include "LIB_linh_tinh.h"
#include <vector>

//mau sac
#define MAU_XAM 247
#define MAU_XAM_DAM 248
#define MAU_XANH 243
#define MAU_TIM 5
#define MAU_LAM 241
#define MAU_DEN 0
#define MAU_TRANG 15
#define MAU_DO 252

//kich thuoc
#define CHIEU_DAI_KHUNG 47
#define CHIEU_RONG_KHUNG 167
#define CHIEU_DAI_CHUC_NANG 220
#define CHIEU_RONG_CHUC_NANG 220
#define CHIEU_DAI_LUA_CHON 220
#define CHIEU_RONG_LUA_CHON 220

//ki tu
#define HCN_MO 176
#define HCN 219
#define VUONG_THAP 220
#define VUONG_CAO 223
#define TRAI_TREN 201
#define PHAI_TREN 187
#define TRAI_DUOI 200
#define PHAI_DUOI 188
#define NGANG 205
#define DOC 186
#define trai_tren 218
#define phai_tren 191
#define trai_duoi 192
#define phai_duoi 217
#define ngang 196
#define doc 179
#define noi_trai 195
#define noi_phai 180
#define noi_tren 194
#define noi_duoi 193
#define noi_giua 197

//================== TAO KHOI ====
void NenTrang()
{
	SetBGColor(15);
	system("cls");
}
void HCN_VienLon(int x1, int y1, int x2, int y2)
{
	SetColor(MAU_XANH);
	for (int i = x1; i <= x2; i++)
	{
		gotoxy(i, y1);
		cout << char(VUONG_THAP);
		gotoxy(i, y2);
		cout << char(VUONG_CAO);
	}
	for (int i = y1 + 1; i <= y2 - 1; i++)
	{
		gotoxy(x1, i);
		cout << char(HCN);
		gotoxy(x2, i);
		cout << char(HCN);
	}
}
void HCN_VienKep(int x1, int y1, int x2, int y2)
{
	SetColor(MAU_XANH);
	//in goc
	{
		gotoxy(x1, y1);
		cout << char(TRAI_TREN);
		gotoxy(x1, y2);
		cout << char(TRAI_DUOI);
		gotoxy(x2, y1);
		cout << char(PHAI_TREN);
		gotoxy(x2, y2);
		cout << char(PHAI_DUOI);
	}
	//in ngang
	for (int i = x1 + 1; i <= x2 - 1; i++)
	{
		gotoxy(i, y1);
		cout << char(NGANG);
		gotoxy(i, y2);
		cout << char(NGANG);
	}
	//in doc
	for (int i = y1 + 1; i <= y2 - 1; i++)
	{
		gotoxy(x1, i);
		cout << char(DOC);
		gotoxy(x2, i);
		cout << char(DOC);
	}
}
void HCN_VienDon(int x1, int y1, int x2, int y2)
{
	SetColor(MAU_XANH);
	//in goc
	{
		gotoxy(x1, y1);
		cout << char(218);
		gotoxy(x1, y2);
		cout << char(192);
		gotoxy(x2, y1);
		cout << char(191);
		gotoxy(x2, y2);
		cout << char(217);
	}
	//in ngang
	for (int i = x1 + 1; i <= x2 - 1; i++)
	{
		gotoxy(i, y1);
		cout << char(196);
		gotoxy(i, y2);
		cout << char(196);
	}
	//in doc
	for (int i = y1 + 1; i <= y2 - 1; i++)
	{
		gotoxy(x1, i);
		cout << char(179);
		gotoxy(x2, i);
		cout << char(179);
	}
}
void HCN_VienDon1(int x1, int y1, int x2, int y2, int color)
{
	SetColor(color);
	//in goc
	{
		gotoxy(x1, y1);
		cout << char(218);
		gotoxy(x1, y2);
		cout << char(192);
		gotoxy(x2, y1);
		cout << char(191);
		gotoxy(x2, y2);
		cout << char(217);
	}
	//in ngang
	for (int i = x1 + 1; i <= x2 - 1; i++)
	{
		gotoxy(i, y1);
		cout << char(196);
		gotoxy(i, y2);
		cout << char(196);
	}
	//in doc
	for (int i = y1 + 1; i <= y2 - 1; i++)
	{
		gotoxy(x1, i);
		cout << char(179);
		gotoxy(x2, i);
		cout << char(179);
	}
}
void DT_Ngang(int x1, int x2, int y)
{
	SetColor(MAU_XANH);
	for (int i = x1; i <= x2; i++)
	{
		gotoxy(i, y);
		cout << char(ngang);
	}
}
void DT_Doc(int x, int y1, int y2)
{
	SetColor(MAU_XANH);
	for (int i = y1; i <= y2; i++)
	{
		gotoxy(x, i);
		cout << char(doc);
	}
}
void HCN_NenTrang(int x1, int y1, int x2, int y2)
{
	SetColor(MAU_TRANG);
	for (int i = y1; i <= y2; i++)
	{
		for (int j = x1; j <= x2; j++)
		{
			gotoxy(j, i);
			cout << char(HCN);
			gotoxy(j, i);
			cout << char(HCN);
		}
	}
}
void outtextxy(int x, int y, string s, int style)
{
	SetColor(MAU_DEN);
	// style = -1 : Can tr�i
	if (style == -1)
	{
		gotoxy(x, y);
		cout << s;
	}
	// style = 0 : Can gi?a
	else if (style == 0)
	{
		gotoxy((x - s.length() / 2) + 1, y);
		cout << s;
	}
	// style = 1 : Can ph?i
	else
	{
		gotoxy(x - s.length() + 1, y);
		cout << s;
	}
}
void outtextxy1(int x, int y, string s, int style, int color)
{
	SetColor(color);
	// style = -1 : Can tr�i
	if (style == -1)
	{
		gotoxy(x, y);
		cout << s;
	}
	// style = 0 : Can gi?a
	else if (style == 0)
	{
		gotoxy((x - s.length() / 2) + 1, y);
		cout << s;
	}
	// style = 1 : Can ph?i
	else
	{
		gotoxy(x - s.length() + 1, y);
		cout << s;
	}
	SetColor(MAU_DEN);
}
void outtextxy2(int x, int y, string s, int style, int color, int bg)
{
	SetBGColor(bg);
	SetColor(color);
	// style = -1 : Can tr�i
	if (style == -1)
	{
		gotoxy(x, y);
		cout << s;
	}
	// style = 0 : Can gi?a
	else if (style == 0)
	{
		gotoxy((x - s.length() / 2) + 1, y);
		cout << s;
	}
	// style = 1 : Can ph?i
	else
	{
		gotoxy(x - s.length() + 1, y);
		cout << s;
	}
	SetBGColor(MAU_TRANG);
	SetColor(MAU_DEN);
}
void outtextxy3(int x, int y, string s1, string s2, int color)
{
	SetColor(color);
	gotoxy(x, y);
	cout << s1 << " " << s2;
}
//============ TAO KHUNG CO BAN ===========
void KhungLon()
{
	HCN_VienLon(1, 0, 167, 47);
}
void KhungChucNang()
{
	HCN_VienKep(2, 1, 29, 29);
}

//============= HIEU UNG MENU ===================
// void HieuUng()
// {
// 	for (int i = 2; i <= 28; i++)
// 	{
// 		gotoxy(3, i);
// 		cout << "                          ";
// 	}
// 	SetBGColor(15);
// 	SetColor(243);
// 	for (int i = 29; i >= 5; i--)
// 	{
// 		gotoxy(2, i);
// 		cout << char(TRAI_DUOI);
// 		gotoxy(29, i);
// 		cout << char(PHAI_DUOI);
// 		for (int j = 3; j <= 28; j++)
// 		{
// 			gotoxy(j, i);
// 			cout << char(NGANG);
// 		}
// 		gotoxy(2, i + 1);
// 		cout << "                            "; //28 o trang
// 		Sleep(i);
// 	}
// 	HCN_VienLon(3, 2, 28, 4);
// 	HCN_NenTrang(3, 3, 28, 3);
// }

// void KhungLuaChon()
// {
// 	SetBGColor(15);
// 	SetColor(243);
// 	//in goc
// 	{
// 		gotoxy(2, 5);
// 		cout << char(204);
// 		gotoxy(29, 5);
// 		cout << char(185);
// 		gotoxy(2, 31);
// 		cout << char(TRAI_DUOI);
// 		gotoxy(29, 31);
// 		cout << char(PHAI_DUOI);
// 	}
// 	//in ngang
// 	for (int i = 3; i <= 28; i++)
// 	{
// 		gotoxy(i, 31);
// 		cout << char(NGANG);
// 	}
// 	//in doc
// 	for (int i = 6; i <= 30; i++)
// 	{
// 		gotoxy(2, i);
// 		cout << char(DOC);
// 		gotoxy(29, i);
// 		cout << char(DOC);
// 	}
// }

//=================== DANG NHAP =======================
void InChuDe()
{
	int x = 38;
	outtextxy1(x, 8, " 	      _      _                                              _      _                         ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 9, " 	 _   | |    (_)    _                                       | |    (_)                        ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 10, " 	| |_ | |__   _    | |_  _ __  __ _   ____     _ __    __ _ | |__   _   ___  _ __ ___         ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 11, " 	| __|| '_ \\ | |   | __|| '__|/ _` | /  __|   | '_ \\  /  _ || '_ \\ | | / _ \\| '_ ` _ \\   ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 12, " 	| |_ | | | || |   | |_ | |  | (_| | | (__    | | | | | (_||| | | || ||  __/| | | | | |       ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 13, "	\\___||_| |_||_|   \\___||_|   \\__,_| \\____|   |_| |_| \\__, ||_| |_||_| \\___||_| |_| |_| ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 14, "	                                                      __/ /'                                 ", -1, rand() % (14 - 0 + 1) + 0);
	outtextxy1(x, 15, "	                                                     (___/                                   ", -1, rand() % (14 - 0 + 1) + 0);
}

void KhungDangNhap()
{
	SetColor(MAU_XANH);
	HCN_VienLon(71, 22, 95, 29);
	HCN_VienDon(78, 23, 93, 25);
	HCN_VienDon(78, 26, 93, 28);
	outtextxy2(82, 21, " LOGIN ", 0, MAU_TRANG, MAU_XANH);
	outtextxy(77, 24, "USER:", 1);
	outtextxy(77, 27, "PASS:", 1);
}

void gotoxyUser(int length)
{
	gotoxy(80 + length, 24);
}
void gotoxyPass(int length)
{
	gotoxy(80 + length, 27);
}

void TrangThaiDangNhap(bool mode)
{
	HCN_NenTrang(73, 23, 93, 28);
	if (mode)
	{
		outtextxy1(82, 25, "^ ^", 0, MAU_LAM);
		outtextxy1(82, 26, "Login Thanh Cong!", 0, MAU_XANH);
		Sleep(1000);
		// outtextxy3(83, 25, "                    ", 0);
	}
	else
	{
		outtextxy1(82, 25, "!", 0, 244);
		outtextxy1(82, 26, "Login That Bai!", 0, MAU_XANH);
		Sleep(1000);
		HCN_NenTrang(72, 23, 94, 28);
		KhungDangNhap();
	}
}

//==================== THEM CAU HOI THI ================
void KhungThemCauHoiThi(int mode)
{
	if (mode == 0)
	{
		outtextxy2(95, 13, " THEM CAU HOI THI ", 0, MAU_TRANG, 3);
	}
	else if (mode == 1)
	{
		outtextxy2(95, 13, " HIEU CHINH CAU HOI THI ", 0, MAU_TRANG, 3);
	}

	HCN_VienLon(46, 14, 145, 42);

	HCN_VienDon1(59, 15, 82, 17, MAU_XAM);
	HCN_VienDon1(59, 18, 142, 26, MAU_XAM);
	HCN_VienDon1(59, 27, 142, 29, MAU_XAM);
	HCN_VienDon1(59, 30, 142, 32, MAU_XAM);
	HCN_VienDon1(59, 33, 142, 35, MAU_XAM);
	HCN_VienDon1(59, 36, 142, 38, MAU_XAM);
	HCN_VienDon1(59, 39, 88, 41, MAU_XAM);

	outtextxy(58, 16, "Ma Mon Hoc:", 1);
	outtextxy(58, 19, "Cau Hoi:", 1);
	outtextxy(58, 28, "A:", 1);
	outtextxy(58, 31, "B:", 1);
	outtextxy(58, 34, "C:", 1);
	outtextxy(58, 37, "D:", 1);
	outtextxy(58, 40, "Dap An:", 1);
}
void KhungHieuChinhCauHoiThi()
{
	HCN_VienDon(59, 9, 86, 11);
	outtextxy(58, 10, "Nhap ID:", 1);
}
void gotoxyID(int length)
{
	gotoxy(61 + length, 10);
}
void gotoxyMaMonHoc(int length)
{
	gotoxy(61 + length, 16);
}
void gotoxyCauHoi(int length, int dong)
{
	gotoxy(61 + length, 19 + dong);
}
void gotoxyA(int length)
{
	gotoxy(61 + length, 28);
}
void gotoxyB(int length)
{
	gotoxy(61 + length, 31);
}
void gotoxyC(int length)
{
	gotoxy(61 + length, 34);
}
void gotoxyD(int length)
{
	gotoxy(61 + length, 37);
}
void gotoxyDapAn(int length)
{
	gotoxy(61 + length, 40);
}

// ==================== MENU SINH VIEN====
int posYmenuSv[2] = {2, 7};
string menuSv[2] = {"THI TRAC NGHIEM", "DANG XUAT"};
void KhungHuongDan()
{
	for (int i = 2; i <= 29; i++)
	{
		gotoxy(i, 39);
		cout << char(NGANG);
	}

	outtextxy2(14, 38, " HUONG DAN SU DUNG ", 0, 15, 3);

	outtextxy1(3, 40, "ESC: Thoat", -1, MAU_XAM_DAM);
	outtextxy1(3, 41, "Enter: Hoan tat", -1, MAU_XAM_DAM);
	outtextxy1(3, 42, "^ v: Chon muc", -1, MAU_XAM_DAM);
	outtextxy1(3, 43, "< >: Sua luc nhap", -1, MAU_XAM_DAM);
	outtextxy1(3, 44, "Tab: Xuong muc ke tiep", -1, MAU_XAM_DAM);
	outtextxy1(3, 45, "Comingsoon", -1, MAU_XAM_DAM);
}
void KhungMenuSv()
{
	HCN_VienDon(0, 0, 31, 47);
	HCN_VienLon(32, 0, 167, 47);
	// KhungChucNang();
	int choice = 0;
	for (int i = 0; i < 2; i++)
	{
		HCN_VienKep(3, posYmenuSv[i], 28, posYmenuSv[i] + 4);
		outtextxy(14, posYmenuSv[i] + 2, menuSv[choice], 0);
		choice++;
	}
	HCN_VienLon(3, 2, 28, 2 + 4);
	KhungHuongDan();
}
void XoaKhungMenuSv()
{
	HCN_NenTrang(2, 1, 30, 46);
}

//========== MENU GIAO VIEN =================
// void KhungMenuGv()
// {
// 	system("cls");
// 	KhungLon();
// 	KhungChucNang();
// 	for (int i = 2; i + 3 <= 28; i += 3)
// 	{
// 		HCN_VienKep(3, i, 28, i + 2);
// 	}
// 	KhungHuongDan();
// 	HieuUng();
// 	KhungLuaChon();
// 	for (int i = 6; i + 3 <= 30; i += 3)
// 	{
// 		HCN_VienKep(3, i, 28, i + 2);
// 	}
// }

// ================= THI TRAC NGHIEM ================
void KhungNhapHinhThucThi()
{
	HCN_VienLon(75, 18, 116, 28);
	HCN_VienDon(94, 19, 114, 21);
	HCN_VienDon(94, 22, 114, 24);
	HCN_VienDon(94, 25, 114, 27);

	outtextxy2(95, 17, "  HINH THUC THI  ", 0, 15, 3);
	outtextxy(93, 20, "Ma Mon Hoc:", 1);
	outtextxy(93, 23, "So Luong Cau Hoi:", 1);
	outtextxy(93, 26, "Thoi Gian Thi:", 1);
}
void gotoxyHinhThucThi0(int length)
{
	gotoxy(96 + length, 20);
}
void gotoxyHinhThucThi1(int length)
{
	gotoxy(96 + length, 23);
}
void gotoxyHinhThucThi2(int length)
{
	gotoxy(96 + length, 26);
}
void TrangThaiHinhThucThi(int mode)
{
	if (mode == 1)
	{
		HCN_NenTrang(75, 17, 116, 28);
		outtextxy1(90, 23, "Dang soan de ", -1, MAU_TIM);
		Sleep(200);
		outtextxy1(103, 23, ".", -1, MAU_TIM);
		Sleep(800);
		outtextxy1(104, 23, ".", -1, MAU_TIM);
		Sleep(800);
		outtextxy1(105, 23, ".", -1, MAU_TIM);
		Sleep(500);
	}
	else if (mode == 0)
	{
		HCN_NenTrang(75, 17, 116, 28);
		outtextxy1(95, 23, "Ban tung thi mon hoc nay roi!", 0, 244);
		Sleep(3000);
		outtextxy(95, 23, "                              ", 0);
	}
	else if (mode == -1)
	{
		HCN_NenTrang(75, 17, 116, 28);
	}
}
void KhungBaoDiemThi(float diem, int soLuong, int dung)
{
	outtextxy2(83, 20, " Diem Thi ", 0, MAU_TRANG, 3);
	HCN_VienLon(75, 21, 92, 26);
	string s1, s2;
	s1 = to_string(dung);
	s2 = to_string(soLuong);
	outtextxy1(82, 23, s1, 1, 244);
	gotoxy(83, 23);
	cout << "/";
	outtextxy1(84, 23, s2, -1, 244);
	gotoxy(80, 24);
	cout << diem << " point";
	Sleep(4000);
}
void KhungThongTinNguoiThi(string mssv, string ho, string ten, string phai, string monThi)
{
	HCN_VienLon(38, 2, 86, 12);

	HCN_VienDon(47, 3, 84, 5);
	HCN_VienDon(47, 6, 84, 8);
	HCN_VienDon(47, 9, 84, 11);

	outtextxy2(64, 1, "  THONG TIN NGUOI THI  ", 0, MAU_TRANG, 3);

	outtextxy(46, 4, "MSSV:", 1);
	outtextxy(46, 7, "Ho Ten:", 1);
	outtextxy(46, 10, "Phai:", 1);

	outtextxy1(49, 4, mssv, -1, MAU_XAM_DAM);
	outtextxy3(49, 7, ho, ten, MAU_XAM_DAM);
	outtextxy1(49, 10, phai, -1, MAU_XAM_DAM);

	HCN_VienDon1(38, 15, 85, 17, MAU_XAM);
	outtextxy2(60, 14, "  THONG BAO  ", 0, 207, 12);

	HCN_VienDon(89, 15, 127, 17);
	outtextxy(91, 16, "Mon Thi: ", -1);
	outtextxy1(100, 16, monThi, -1, MAU_XAM_DAM);
}
void KhungHuongDanLamBai()
{
	HCN_VienLon(89, 2, 127, 14);
	outtextxy2(108, 1, "  HUONG DAN LAM BAI THI  ", 0, MAU_TRANG, 3);

	outtextxy1(92, 4, "Nhan F1: Nop bai thi", -1, MAU_XAM_DAM);
	outtextxy1(92, 5, "Nhan A, B, C, D: Chon dap an", -1, MAU_XAM_DAM);
	outtextxy1(92, 6, "Nhan Enter: Cau hoi ke tiep", -1, MAU_XAM_DAM);
	outtextxy1(92, 7, "Nhan Backspace: Xoa dap an", -1, MAU_XAM_DAM);
	outtextxy1(92, 8, "Nhan Tab: Toi cau chua tra loi", -1, MAU_XAM_DAM);
	outtextxy1(92, 9, "Nhan < >: Chuyen cau hoi", -1, MAU_XAM_DAM);
	outtextxy1(92, 10, "Nhan ^ v: Chuyen dap an", -1, MAU_XAM_DAM);
	outtextxy1(92, 11, "Thoi gian < 30s se co thong bao", -1, MAU_XAM_DAM);
	outtextxy1(92, 12, "Het gio he thong tu dong nop bai", -1, MAU_XANH);
}
void KhungThi(int soLuong)
{
	HCN_VienLon(38, 18, 127, 46);
	HCN_VienDon(64, 19, 101, 23);
	HCN_VienDon(102, 19, 126, 23);

	outtextxy(76, 21, "<-    /    ->", -1);
	string s = to_string(soLuong);
	outtextxy1(83, 21, s, -1, MAU_DEN);

	HCN_VienDon(39, 19, 63, 21);
	HCN_VienDon(39, 21, 63, 23);
	gotoxy(63, 21);
	cout << char(noi_phai);
	gotoxy(39, 21);
	cout << char(noi_trai);

	outtextxy(40, 20, "ID:", -1);
	outtextxy(40, 22, "Tra Loi:", -1);

	HCN_VienDon1(39, 24, 126, 33, MAU_XAM);
	HCN_VienDon1(39, 34, 126, 36, MAU_XAM);
	HCN_VienDon1(39, 37, 126, 39, MAU_XAM);
	HCN_VienDon1(39, 40, 126, 42, MAU_XAM);
	HCN_VienDon1(39, 43, 126, 45, MAU_XAM);

	outtextxy(40, 25, "Cau Hoi:", -1);
	outtextxy(40, 35, " A:", -1);
	outtextxy(40, 38, " B:", -1);
	outtextxy(40, 41, " C:", -1);
	outtextxy(40, 44, " D:", -1);
}
void DienNoiDungThi(int stt, int id, string cauHoi, string a, string b, string c, string d)
{
	gotoxy(79, 21);
	cout << "   ";
	string s = to_string(stt);
	outtextxy1(81, 21, s, 1, 244);
	gotoxy(44, 20);
	cout << id;
	int e = cauHoi.length() / 86;
	for (int i = 0; i < e + 1; i++)
	{
		gotoxy(40, 26 + i);
		cout << cauHoi.substr(i * 86, 86);
	}
	gotoxy(44, 35);
	cout << a;
	gotoxy(44, 38);
	cout << b;
	gotoxy(44, 41);
	cout << c;
	gotoxy(44, 44);
	cout << d;
}
void ToMauKhungDapAn(string a)
{
	HCN_VienDon1(39, 34, 126, 36, MAU_XAM);
	HCN_VienDon1(39, 37, 126, 39, MAU_XAM);
	HCN_VienDon1(39, 40, 126, 42, MAU_XAM);
	HCN_VienDon1(39, 43, 126, 45, MAU_XAM);

	if (a == "A")
	{
		HCN_VienDon1(39, 34, 126, 36, 244);
	}
	else if (a == "B")
	{
		HCN_VienDon1(39, 37, 126, 39, 244);
	}
	else if (a == "C")
	{
		HCN_VienDon1(39, 40, 126, 42, 244);
	}
	else if (a == "D")
	{
		HCN_VienDon1(39, 43, 126, 45, 244);
	}

	SetColor(MAU_DEN);
}
void XoaHienThi1CauHoi()
{
	SetBGColor(MAU_TRANG);
	gotoxy(44, 20);
	cout << "   ";
	gotoxy(49, 22);
	cout << " ";
	for (int i = 0; i < 7; i++)
	{
		gotoxy(40, 26 + i);
		cout << "                                                                                      ";
	}
	gotoxy(44, 35);
	cout << "                                                                                  ";
	gotoxy(44, 38);
	cout << "                                                                                  ";
	gotoxy(44, 41);
	cout << "                                                                                  ";
	gotoxy(44, 44);
	cout << "                                                                                  ";

	SetColor(MAU_DEN);
}

void KhungThongBaoDaNopBai(bool mode)
{
	NenTrang();
	if (mode == true)
	{
		outtextxy2(83, 20, " THONG BAO ", 0, MAU_TRANG, 3);
		HCN_VienLon(75, 21, 92, 25);
		outtextxy(83, 23, "Da Nop Bai", 0);
		Sleep(2000);
	}
	else
	{
		outtextxy2(82, 20, " THONG BAO ", 0, MAU_TRANG, 3);
		HCN_VienLon(63, 21, 101, 25);
		outtextxy(66, 23, "\aHet Gio, He Thong Tu Dong Nop Bai", -1);
		Sleep(3000);
	}
}

//====================== THEM CAU HOI THI  ================
void LamTrangKhungThemCauHoiThi()
{
	for (int i = 0; i < 7; i++)
	{
		gotoxyCauHoi(0, i);
		cout << "                                                                                 ";
	}
	gotoxyA(0);
	cout << "                                                                                 ";
	gotoxyB(0);
	cout << "                                                                                 ";
	gotoxyC(0);
	cout << "                                                                                 ";
	gotoxyD(0);
	cout << "                                                                                 ";
}
//============================ BANG DIEM THI ======================
void Table(int soLuong)
{
	int dongDau = 11;
	int dongCuoi = soLuong * 2 + dongDau;
	outtextxy2(36, 10, " Stt ", 0, MAU_TRANG, 3);		   // gotoxy(36,12);
	outtextxy2(49, 10, " Ma Sinh Vien ", 0, MAU_TRANG, 3); // gotoxy(42,12);
	outtextxy2(75, 10, " Ho ", 0, MAU_TRANG, 3);		   // gotoxy(62,12);
	outtextxy2(97, 10, " Ten ", 0, MAU_TRANG, 3);		   // gotoxy(92,12);
	outtextxy2(117, 10, " Ma Mon Hoc ", 0, MAU_TRANG, 3);  // gotoxy(107,12);
	outtextxy2(147, 10, " Diem Thi ", 0, MAU_TRANG, 3);	   // gotoxy(132,12);
	HCN_VienDon(34, dongDau, 164, dongCuoi);
	DT_Doc(40, dongDau, dongCuoi);
	DT_Doc(60, dongDau, dongCuoi);
	DT_Doc(90, dongDau, dongCuoi);
	DT_Doc(105, dongDau, dongCuoi);
	DT_Doc(130, dongDau, dongCuoi);
	for (int i = dongDau + 2; i <= dongCuoi - 2; i += 2)
	{
		DT_Ngang(34, 164, i);
	}
	for (int i = dongDau + 2; i <= dongCuoi - 2; i += 2)
	{
		gotoxy(34, i);
		cout << char(noi_trai);
		gotoxy(164, i);
		cout << char(noi_phai);
	}
	gotoxy(40, dongDau);
	cout << char(noi_tren);
	gotoxy(40, dongCuoi);
	cout << char(noi_duoi);
	gotoxy(60, dongDau);
	cout << char(noi_tren);
	gotoxy(60, dongCuoi);
	cout << char(noi_duoi);
	gotoxy(90, dongDau);
	cout << char(noi_tren);
	gotoxy(90, dongCuoi);
	cout << char(noi_duoi);
	gotoxy(105, dongDau);
	cout << char(noi_tren);
	gotoxy(105, dongCuoi);
	cout << char(noi_duoi);
	gotoxy(130, dongDau);
	cout << char(noi_tren);
	gotoxy(130, dongCuoi);
	cout << char(noi_duoi);
	for (int i = dongDau + 2; i <= dongCuoi - 2; i += 2)
	{
		gotoxy(40, i);
		cout << char(noi_giua);
		gotoxy(60, i);
		cout << char(noi_giua);
		gotoxy(90, i);
		cout << char(noi_giua);
		gotoxy(105, i);
		cout << char(noi_giua);
		gotoxy(130, i);
		cout << char(noi_giua);
	}
}
void KhungNhapLopXemDiemThi()
{
	HCN_VienDon(48, 6, 68, 8);
	outtextxy(47, 7, "Nhap ma lop:", 1);
}
void gotoxyNhapMaLop(int length)
{
	gotoxy(50 + length, 7);
}

//========================= BAI THI ===========
void KhungNhapBaiLam()
{
	HCN_VienDon(47, 3, 84, 5);
	HCN_VienDon(47, 6, 84, 8);
	outtextxy(46, 4, "MSSV:", 1);
	outtextxy(46, 7, "Ma Mon Hoc:", 1);
}
void gotoxyMSSV_BL(int length)
{
	gotoxy(49 + length, 4);
}
void gotoxyMMH_BL(int length)
{
	gotoxy(49 + length, 7);
}
void KhungThongTinBaiLam()
{
	HCN_VienLon(89, 2, 162, 18);

	HCN_VienDon(117, 3, 160, 5);
	HCN_VienDon(117, 6, 160, 8);
	HCN_VienDon(117, 9, 160, 11);
	HCN_VienDon(117, 12, 160, 14);
	HCN_VienDon(117, 15, 160, 17);

	outtextxy2(125, 1, " THONG TIN BAI LAM ", 0, MAU_TRANG, 3);

	outtextxy(116, 4, "Ho Ten:", 1);
	outtextxy(116, 7, "Thoi Gian Yeu Cau:", 1);
	outtextxy(116, 10, "Thoi Gian Hoan Thanh:", 1);
	outtextxy(116, 13, "So Luong Cau Hoi Yeu Cau:", 1);
	outtextxy(116, 16, "So Luong Cau Tra Loi Dung:", 1);
}

//========= DIEM THI ========================
void KhungThemDiemThi()
{
	HCN_VienLon(66, 16, 132, 26);
	outtextxy2(98, 15, " THEM DIEM THI ", 0, MAU_TRANG, 3);
	HCN_VienDon(79, 17, 130, 19);
	HCN_VienDon(79, 20, 130, 22);
	HCN_VienDon(79, 23, 130, 25);
	outtextxy(78, 18, "MSSV:", 1);
	outtextxy(78, 21, "Ma Mon Hoc:", 1);
	outtextxy(78, 24, "Diem Thi:", 1);
}
void KhungHieuChinhDiemThi()
{
	HCN_VienLon(66, 16, 132, 26);
	outtextxy2(98, 15, " HIEU CHINH DIEM THI ", 0, MAU_TRANG, 3);
	HCN_VienDon(79, 17, 130, 19);
	HCN_VienDon(79, 20, 130, 22);
	HCN_VienDon(79, 23, 130, 25);
	outtextxy(78, 18, "MSSV:", 1);
	outtextxy(78, 21, "Ma Mon Hoc:", 1);
	outtextxy(78, 24, "Diem Thi:", 1);
}
void KhungXoaDiemThi()
{
	HCN_VienLon(66, 16, 132, 23);
	outtextxy2(98, 15, " XOA DIEM THI ", 0, MAU_TRANG, 3);
	HCN_VienDon(79, 17, 130, 19);
	HCN_VienDon(79, 20, 130, 22);
	outtextxy(78, 18, "MSSV:", 1);
	outtextxy(78, 21, "Ma Mon Hoc:", 1);
}
void gotoxyMSSV(int length)
{
	gotoxy(81 + length, 18);
}
void gotoxyMMH(int length)
{
	gotoxy(81 + length, 21);
}
void gotoxyDiemThi(int length)
{
	gotoxy(81 + length, 24);
}


//tiennhot23============================================================================
//========== MENU GIAO VIEN =================


int posYmenuGv1[7] = {2, 7, 12, 17, 22, 27, 32};
string menuGv1[7] = {"MON HOC", "CAU HOI THI", "LOP", "SINH VIEN", "THI TRAC NGHIEM", "LICH SU THI", "DIEM THI"};
void KhungMenuGv1()
{
	HCN_VienDon(0, 0, 31, 47);
	HCN_VienLon(32, 0, 167, 47);
	// KhungChucNang();
	int choice1 = 0;
	for (int i = 0; i < 7; i++)
	{
		HCN_VienKep(3, posYmenuGv1[i], 28, posYmenuGv1[i] + 4);
		outtextxy(14, posYmenuGv1[i] + 2, menuGv1[choice1], 0);
		choice1++;
	}
	HCN_VienLon(3, 2, 28, 2 + 4);
	KhungHuongDan();
}

int posYmenuGv2[5] = {7, 12, 17, 22};
vector<vector<string>> menuGv2{{"MON HOC", "THEM MON HOC", "IN DANH SACH MON HOC", "XOA MON HOC", "HIEU CHINH MON HOC"},
							   {"CAU HOI THI", "THEM CAU HOI THI", "IN DANH SACH CAU HOI", "XOA CAU HOI", "HIEU CHINH CAU HOI"},
							   {"LOP", "THEM LOP", "IN DANH SACH LOP", "XOA LOP", "HIEU CHINH LOP"},
							   {"SINH VIEN", "THEM SINH VIEN", "IN DANH SACH SINH VIEN","XOA SINH VIEN","HIEU CHINH SINH VIEN"},
							   {"THI TRAC NGHIEM"},
							   {"LICH SU THI"},
							   {"DIEM THI", "THEM DIEM THI", "IN BANG DIEM", "HIEU CHINH DIEM THI", "XOA DIEM THI"}};
void KhungMenuGv2(int choice1)
{
	HCN_NenTrang(0, 0, 31, 47);
	HCN_VienDon(0, 0, 31, 47);
	HCN_VienLon(32, 0, 167, 47);
	outtextxy(14, 3, menuGv2[choice1][0], 0);
	SetColor(243);
	SetBGColor(15);
	for (int i = 1; i < menuGv2[choice1].size(); i++)
	{
		HCN_VienLon(3, 7, 28, 7 + 4);
		HCN_VienKep(3, posYmenuGv2[i - 1], 28, posYmenuGv2[i - 1] + 4);
		outtextxy(14, posYmenuGv2[i - 1] + 2, menuGv2[choice1][i], 0);
	}
	KhungHuongDan();
}
void khungthemMH(string title)
{
	HCN_VienLon(65, 17, 132, 27);
	outtextxy(98, 19, title, 0);
	HCN_VienDon(79, 20, 130, 22);
	HCN_VienDon(79, 23, 130, 25);
	outtextxy(78, 21, "MA MON HOC:", 1);
	outtextxy(78, 24, "TEN MON HOC:", 1);
}
void khungxoaMH(string title)
{
	//	HCN_VienLon(65,19,132,26);
	//	outtextxy(98,21,"XOA MON HOC",0);
	//	HCN_VienDon(79,22,130,24);
	//	outtextxy(78,23,"MA MON HOC:",1);
	HCN_VienLon(65, 17, 132, 24);
	outtextxy(98, 19, title, 0);
	HCN_VienDon(79, 20, 130, 22);
	outtextxy(78, 21, "MA MON HOC:", 1);
}
//void khunghieuchinhMH()
//{
//	HCN_VienLon(65, 17, 132, 24);
//	outtextxy(98, 21, "HIEU CHINH MON HOC", 0);
//	HCN_VienDon(79, 20, 130, 22);
//	outtextxy(78, 21, "MA MON HOC:", 1);
//	getch();
//	HCN_NenTrang(65, 19, 132, 28);
//	HCN_VienLon(65, 17, 132, 27);
//	outtextxy(98, 19, "HIEU CHINH MON HOC", 0);
//	HCN_VienDon(79, 20, 130, 22);
//	HCN_VienDon(79, 23, 130, 25);
//	outtextxy(78, 21, "MA MON HOC:", 1);
//	outtextxy(78, 24, "TEN MON HOC:", 1);
//}

void khungthemLop(string title)
{
	HCN_VienLon(69, 17, 132, 27);
	outtextxy(98, 19, title, 0);
	HCN_VienDon(79, 20, 130, 22);
	HCN_VienDon(79, 23, 130, 25);
	outtextxy(78, 21, "MA LOP:", 1);
	outtextxy(78, 24, "TEN LOP:", 1);
}
void khungxoaLop(string title)
{
	HCN_VienLon(69, 17, 132, 24);
	outtextxy(98, 19, title, 0);
	HCN_VienDon(79, 20, 130, 22);
	outtextxy(78, 21, "MA LOP:", 1);
}
//void khunghieuchinhLop()
//{
//	HCN_VienLon(69, 19, 132, 26);
//	outtextxy(98, 21, "HIEU CHINH LOP", 0);
//	HCN_VienDon(79, 22, 130, 24);
//	outtextxy(78, 23, "MA LOP:", 1);
//	getch();
//	HCN_NenTrang(65, 19, 132, 28);
//	HCN_VienLon(69, 16, 132, 27);
//	outtextxy(98, 18, "HIEU CHINH LOP", 0);
//	HCN_VienDon(79, 20, 130, 22);
//	HCN_VienDon(79, 23, 130, 25);
//	outtextxy(78, 21, "MA LOP:", 1);
//	outtextxy(78, 24, "TEN LOP:", 1);
//}
void khungthemSV(string title){
	HCN_VienLon(67,11,132,33);
	outtextxy(98,13,title,0);
	HCN_VienDon(79,14,130,16);
	HCN_VienDon(79,17,130,19);
	HCN_VienDon(79,20,130,22);
	HCN_VienDon(79,23,130,25);
	HCN_VienDon(79,26,87,28);
	HCN_VienDon(79,29,130,31);
	outtextxy(78,15,"MA LOP:",1);
	outtextxy(78,18,"MSSV:",1);
	outtextxy(78,21,"HO:",1);
	outtextxy(78,24,"TEN:",1);
	outtextxy(78,27,"PHAI:",1);
	outtextxy(78,30,"PASSWORD:",1);
}
void khungxoaSV(string title){
	HCN_VienLon(72,14,132,21);
	outtextxy(98,16,title,0);
	HCN_VienDon(79,17,130,19);
	outtextxy(78,18,"MSSV:",1);
}
void khungthemDiemthi()
{
	HCN_VienLon(65, 14, 132, 30);
	outtextxy(98, 16, "THEM DIEM THI", 0);
	HCN_VienDon(79, 17, 130, 19);
	HCN_VienDon(79, 20, 130, 22);
	HCN_VienDon(79, 23, 130, 25);
	HCN_VienDon(79, 26, 87, 28);
	outtextxy(78, 18, "MA LOP:", 1);
	outtextxy(78, 21, "MSSV:", 1);
	outtextxy(78, 24, "MA MON HOC:", 1);
	outtextxy(78, 27, "DIEM THI:", 1);
}
void khungdanhsachMH()
{
	SetColor(243);
	AnConTro();
	int l = 44;
	outtextxy(l, 2, "      _                _                           _                                     _                  ", -1);
	outtextxy(l, 3, "     | |              | |                         | |                                   | |                 ", -1);
	outtextxy(l, 4, "   __| |  __ _  _ __  | |__      ___   __ _  ____ | |__      _ __ ___    ___   _ __     | |__    ___   ____ ", -1);
	outtextxy(l, 5, "  / _' | / _' || '_ \\ | '_ \\    |  _| / _' |/  __|| '_ \\    | '_ \\ _ \\  / _ \\ | '_ \\    | '_ \\  / _ \\ /  __|", -1);
	outtextxy(l, 6, " | (_| || (_| || | | || | | |    \\ \\ | (_| || (__ | | | |   | | | | | || (_) || | | |   | | | || (_) || (__ ", -1);
	outtextxy(l, 7, "  \\__,_| \\__,_||_| |_||_| |_|   |___| \\__,_|\\____||_| |_|   |_| |_| |_| \\___/ |_| |_|   |_| |_| \\___/ \\____|", -1);
//	HCN_VienLon(32, 14, 164, 45);
//	outtextxy(98, 10, "<- 1/100 ->", 0);
//	outtextxy(34, 13, "STT", -1);
//	outtextxy(47, 13, "MA MON HOC", 0);
//	outtextxy(109, 13, "TEN MON HOC", 0);
//	int i = 15;
//	while (i + 3 <= 45)
//	{
//		HCN_VienDon(33, i, 37, i + 2);
//		HCN_VienDon(38, i, 59, i + 2);
//		HCN_VienDon(60, i, 163, i + 2);
//		i += 3;
//	}
}
void khungdanhsachSV()
{
//	SetColor(243);
//	AnConTro();
//	HCN_VienLon(69, 19, 132, 26);
//	outtextxy(98, 21, "IN DANH SACH SINH VIEN", 0);
//	HCN_VienDon(79, 22, 130, 24);
//	outtextxy(78, 23, "MA LOP:", 1);
//	getch();
//	HCN_NenTrang(69, 19, 132, 26);
	SetColor(243);
	int l = 30;
	outtextxy(l, 2, "      _                _                           _                        _                               ", -1);
	outtextxy(l, 3, "     | |              | |                         | |                      | |                              ", -1);
	outtextxy(l, 4, "   __| |  __ _  _ __  | |__      ___   __ _  ____ | |__      ___  _  _ __  | |__      _   _  _   ___  _ __  ", -1);
	outtextxy(l, 5, "  / _' | / _' || '_ \\ | '_ \\    |  _| / _' |/  __|| '_ \\    |  _|| || '_ \\ | '_ \\    | | | || | / _ \\| '_ \\ ", -1);
	outtextxy(l, 6, " | (_| || (_| || | | || | | |    \\ \\ | (_| || (__ | | | |    \\ \\ | || | | || | | |   | |_| || ||  __/| | | |", -1);
	outtextxy(l, 7, "  \\__,_| \\__,_||_| |_||_| |_|   |___| \\__,_|\\____||_| |_|   |___||_||_| |_||_| |_|    \\___/ |_| \\___||_| |_|", -1);
//	HCN_VienLon(32, 15, 164, 46);
//	outtextxy(98, 10, "<- 1/100 ->", 0);
//	outtextxy(34, 14, "STT", -1);
//	outtextxy(47, 14, "MA LOP", 0);
//	outtextxy(69, 14, "MA SO SINH VIEN", 0);
//	outtextxy(96, 14, "HO", 0);
//	outtextxy(123, 14, "TEN", 0);
//	outtextxy(137, 14, "PHAI", -1);
//	outtextxy(151, 14, "PASSWORD", 0);
//
//	int i = 16;
//	while (i + 3 <= 46)
//	{
//		HCN_VienDon(33, i, 37, i + 2);
//		HCN_VienDon(38, i, 59, i + 2);
//		HCN_VienDon(60, i, 81, i + 2);
//		HCN_VienDon(82, i, 113, i + 2);
//		HCN_VienDon(114, i, 135, i + 2);
//		HCN_VienDon(136, i, 141, i + 2);
//		HCN_VienDon(142, i, 163, i + 2);
//		i += 3;
//	}
}
void khungdanhsachCHT()
{
	SetColor(243);
	AnConTro();
	int l = 44;
	outtextxy(l, 2, "      _                _                           _                                _               ", -1);
	outtextxy(l, 3, "     | |              | |                         | |       	               | |              ", -1);
	outtextxy(l, 4, "   __| |  __ _  _ __  | |__      ___   __ _  ____ | |__      ____   __ _  _   _    | |__    ___   _ ", -1);
	outtextxy(l, 5, "  / _' | / _' || '_ \\ | '_ \\    |  _| / _' |/  __|| '_ \\    /  __| / _' || | | |   | '_ \\  / _ \\ | |", -1);
	outtextxy(l, 6, " | (_| || (_| || | | || | | |    \\ \\ | (_| || (__ | | | |   | (__ | (_| || |_| |   | | | || (_) || |", -1);
	outtextxy(l, 7, "  \\__,_| \\__,_||_| |_||_| |_|   |___| \\__,_|\\____||_| |_|   \\____| \\__,_||,___,|   |_| |_| \\___/ |_|", -1);
	HCN_VienLon(32, 14, 164, 45);
	outtextxy(98, 10, "<- 1/100 ->", 0);
	outtextxy(34, 13, "STT", 0);
	outtextxy(43, 13, "ID", 0);
	outtextxy(61, 13, "MA MON HOC", 0);
	outtextxy(114, 13, "NOI DUNG CAU HOI", 0);
	outtextxy(159, 13, "DAP AN", 0);
	int i = 15;
	while (i + 3 <= 45)
	{
		HCN_VienDon(33, i, 37, i + 2);
		HCN_VienDon(38, i, 49, i + 2);
		HCN_VienDon(50, i, 71, i + 2);
		HCN_VienDon(72, i, 155, i + 2);
		HCN_VienDon(156, i, 163, i + 2);
		i += 3;
	}
}
void khungdanhsachLop()
{
	SetColor(243);
	AnConTro();
	int l = 58;
	outtextxy(l, 2, "      _                _                           _         _					 ", -1);
	outtextxy(l, 3, "     | |              | |                         | |       | |			       ", -1);
	outtextxy(l, 4, "   __| |  __ _  _ __  | |__      ___   __ _  ____ | |__     | |      ___   _ ___  ", -1);
	outtextxy(l, 5, "  / _' | / _' || '_ \\ | '_ \\    |  _| / _' |/  __|| '_ \\    | |     / _ \\ | ' _ \\ ", -1);
	outtextxy(l, 6, " | (_| || (_| || | | || | | |    \\ \\ | (_| || (__ | | | |   | |___ | (_) ||  (_) |", -1);
	outtextxy(l, 7, "  \\__,_| \\__,_||_| |_||_| |_|   |___| \\__,_|\\____||_| |_|   |_____| \\___/ | \\___/ ", -1);
	outtextxy(l, 8, "                                                                          |_|     ", -1);
//	HCN_VienLon(55, 15, 142, 46);
//	outtextxy(98, 11, "<- 1/100 ->", 0);
//	outtextxy(57, 14, "STT", -1);
//	outtextxy(71, 14, "MA LOP", 0);
//	outtextxy(111, 14, "TEN LOP", 0);
//	int i = 16;
//	while (i + 3 <= 46)
//	{
//		HCN_VienDon(56, i, 60, i + 2);
//		HCN_VienDon(61, i, 82, i + 2);
//		HCN_VienDon(83, i, 141, i + 2);
//		i += 3;
//	}
}
