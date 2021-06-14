#include "mylib.h"
using namespace std;

//phím
#define BACKSPACE 8
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define F1 59

//màu sắc
#define MAU_XANH 243
#define MAU_LAM 177
#define MAU_DEN 0 //241?
#define MAU_TRANG 15

//kích thước
#define CHIEU_DAI_KHUNG 47
#define CHIEU_RONG_KHUNG 167
#define CHIEU_DAI_CHUC_NANG 220
#define CHIEU_RONG_CHUC_NANG 220
#define CHIEU_DAI_LUA_CHON 220
#define CHIEU_RONG_LUA_CHON 220

//kí tự in
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

int posYmenuSv[3] = {2, 7};
string menuSv[3] = {"THI TRAC NGHIEM", "DANG XUAT"};

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
	// style = -1 : Căn trái
	if (style == -1)
	{
		gotoxy(x, y);
		cout << s;
	}
	// style = 0 : Căn giữa
	else if (style == 0)
	{
		gotoxy((x - s.length() / 2) + 1, y);
		cout << s;
	}
	// style = 1 : Căn phải
	else
	{
		gotoxy(x - s.length() + 1, y);
		cout << s;
	}
}

void outtextxy1(int x, int y, string s, int style, int color)
{
	SetColor(color);
	// style = -1 : Căn trái
	if (style == -1)
	{
		gotoxy(x, y);
		cout << s;
	}
	// style = 0 : Căn giữa
	else if (style == 0)
	{
		gotoxy((x - s.length() / 2) + 1, y);
		cout << s;
	}
	// style = 1 : Căn phải
	else
	{
		gotoxy(x - s.length() + 1, y);
		cout << s;
	}
}

void gotoA()
{
}
void gotoB()
{
}
void gotoC()
{
}
void gotoD()
{
}

void NenTrang()
{
	SetBGColor(15);
	system("cls");
}

void KhungLon()
{
	HCN_VienLon(1, 0, 167, 47);
}

void KhungChucNang()
{
	HCN_VienKep(2, 1, 29, 29);
}

void KhungHuongDan()
{
	HCN_VienKep(2, 32, 29, 46);
}

void HieuUng()
{
	for (int i = 2; i <= 28; i++)
	{
		gotoxy(3, i);
		cout << "                          ";
	}
	SetBGColor(15);
	SetColor(243);
	for (int i = 29; i >= 5; i--)
	{
		gotoxy(2, i);
		cout << char(TRAI_DUOI);
		gotoxy(29, i);
		cout << char(PHAI_DUOI);
		for (int j = 3; j <= 28; j++)
		{
			gotoxy(j, i);
			cout << char(NGANG);
		}
		gotoxy(2, i + 1);
		cout << "                            "; //28 o trang
		Sleep(i);
	}
	HCN_VienLon(3, 2, 28, 4);
	HCN_NenTrang(3, 3, 28, 3);
}

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

void InChuDe()
{
	int x = 38;
	outtextxy(x, 8, " 	      _      _                                              _      _                         ", -1);
	outtextxy(x, 9, " 	 _   | |    (_)    _                                       | |    (_)                        ", -1);
	outtextxy(x, 10, " 	| |_ | |__   _    | |_  _ __  __ _   ____     _ __    __ _ | |__   _   ___  _ __ ___         ", -1);
	outtextxy(x, 11, " 	| __|| '_ \\ | |   | __|| '__|/ _` | /  __|   | '_ \\  /  _ || '_ \\ | | / _ \\| '_ ` _ \\   ", -1);
	outtextxy(x, 12, " 	| |_ | | | || |   | |_ | |  | (_| | | (__    | | | | | (_||| | | || ||  __/| | | | | |       ", -1);
	outtextxy(x, 13, "	\\___||_| |_||_|   \\___||_|   \\__,_| \\____|   |_| |_| \\__, ||_| |_||_| \\___||_| |_| |_| ", -1);
	outtextxy(x, 14, "	                                                      __/ /'                                 ", -1);
	outtextxy(x, 15, "	                                                     (___/                                   ", -1);
}

void KhungDangNhap()
{
	HCN_VienLon(71, 22, 95, 29);
	HCN_VienDon(78, 23, 93, 25);
	HCN_VienDon(78, 26, 93, 28);
	outtextxy(82, 21, "DANG NHAP", 0);
	outtextxy(77, 24, "MSSV:", 1);
	outtextxy(77, 27, "PASS:", 1);
}

void XoaKhungDangNhap()
{
	HCN_NenTrang(38, 8, 125, 29);
}

void TrangThaiDangNhap(bool mode)
{
	HCN_NenTrang(73, 23, 93, 28);
	if (mode)
	{
		outtextxy(83, 25, "DANG NHAP THANH CONG", 0);
		Sleep(100);
	}
	else
	{
		outtextxy(83, 25, "MSSV or PASSWORD SAI", 0);
		Sleep(100);
		KhungDangNhap();
	}
}

void KhungMenuSv()
{
	KhungChucNang();
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

void KhungThi()
{
	HCN_VienLon(38, 18, 127, 46);

	HCN_VienDon(64, 19, 101, 23);
	HCN_VienDon(102, 19, 126, 23);
	outtextxy(113, 21, "00:02:59", 0);
	outtextxy(81, 21, "<-  3/6  ->", 0);

	HCN_VienDon(39, 19, 63, 21);
	HCN_VienDon(39, 21, 63, 23);
	gotoxy(63, 21);
	cout << char(noi_phai);
	gotoxy(39, 21);
	cout << char(noi_trai);
	outtextxy(40, 20, "ID:", -1);
	outtextxy(40, 22, "TRA LOI:", -1);

	HCN_VienDon(39, 24, 126, 33);
	HCN_VienDon(39, 34, 126, 36);
	HCN_VienDon(39, 37, 126, 39);
	HCN_VienDon(39, 40, 126, 42);
	HCN_VienDon(39, 43, 126, 45);

	outtextxy(40, 25, "Cau Hoi:", -1);
	outtextxy(40, 35, " A:", -1);
	outtextxy(40, 38, " B:", -1);
	outtextxy(40, 41, " C:", -1);
	outtextxy(40, 44, " D:", -1);

	HCN_VienKep(38, 13, 70, 17);
	outtextxy(40, 15, "MON THI: Kien Truc May Tinh", -1);
}

void KhungThongTinNguoiThi()
{
	HCN_VienLon(38, 2, 86, 12);

	HCN_VienDon(47, 3, 84, 5);
	HCN_VienDon(47, 6, 84, 8);
	HCN_VienDon(47, 9, 84, 11);

	outtextxy(64, 1, "THONG TIN NGUOI THI", 0);

	outtextxy(46, 4, "Lop:", 1);
	outtextxy(46, 7, "MSSV:", 1);
	outtextxy(46, 10, "Ho Ten:", 1);
}

void KhungHuongDanLamBai()
{
	HCN_VienLon(89, 2, 127, 12);
	outtextxy(108, 1, "HUONG DAN LAM BAI THI", 0);

	outtextxy(92, 4, "Nhan F1: Nop bai thi", -1);
	outtextxy(92, 5, "Nhan A, B, C, D: Chon dap an", -1);
	outtextxy(92, 6, "Nhan Enter: Cau hoi ke tiep", -1);
	outtextxy(92, 7, "Nhan Backspace: Xoa dap an", -1);
	outtextxy(92, 8, "Nhan <-: Ve cau hoi truoc", -1);
	outtextxy(92, 9, "Nhan ->: Sang cau hoi sau", -1);
	outtextxy(92, 10, "Het gio he thong tu dong nop bai", -1);
}

void KhungNhapHinhThucThi()
{
	HCN_VienLon(75, 18, 116, 28);

	HCN_VienDon(94, 19, 114, 21);
	HCN_VienDon(94, 22, 114, 24);
	HCN_VienDon(94, 25, 114, 27);

	outtextxy(93, 20, "Ma Mon Hoc:", 1);
	outtextxy(93, 23, "So Luong Cau Hoi:", 1);
	outtextxy(93, 26, "Thoi Gian Thi:", 1);
}

void XoaKhungNhapHinhThucThi()
{
	HCN_NenTrang(75, 18, 116, 28);
	outtextxy1(85, 23, "Bat Dau Thi", -1, MAU_XANH);
	Sleep(1000);
	outtextxy1(85, 23, "           ", -1, MAU_XANH);
}

int main()
{
	FullScreen();
	NenTrang();
	AnConTro();
	KhungLon();
	InChuDe();
DANG_NHAP:
	InChuDe();
	KhungDangNhap();
	getch();
	TrangThaiDangNhap(true);
	XoaKhungDangNhap();
LUA_CHON:
	KhungMenuSv();
	int choice = 0;
	while (true)
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == DOWN)
			{
				HCN_VienKep(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
				choice += 1;
				if (choice == 2)
					choice = 0;
				HCN_VienLon(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
			}
			if (c == UP)
			{
				HCN_VienKep(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
				choice -= 1;
				if (choice == -1)
					choice = 1;
				HCN_VienLon(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
			}
		}
		else if (c == ENTER && choice == 0)
		{
			KhungNhapHinhThucThi();
			getch();
			XoaKhungNhapHinhThucThi();
			XoaManHinh();
			KhungThongTinNguoiThi();
			KhungHuongDanLamBai();
			KhungThi();
			getch();
			break;
		}
		else if (c == ENTER && choice == 1)
		{
			XoaKhungMenuSv();
			goto DANG_NHAP;
		}
	}
	return 0;
}
