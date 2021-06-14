#pragma once
#include "LIB_lop.h"
#include "LIB_cau_hoi_thi.h"
#include "LIB_doc_ghi_file.h"

const int LENGTH = 25;
const int ITEM_GV = 21;
const int ITEM_SV = 3;
const int DONG = 5;
const int COT = 20;
//tiennhot23
//==============
int luachonGv1();
int luachonGv2(int choice1);

//==============

int luachonGv1()
{
	KhungMenuGv1();
	int choice1 = 0;
	while (1)
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == DOWN)
			{
				HCN_VienKep(3, posYmenuGv1[choice1], 28, posYmenuGv1[choice1] + 4);
				choice1 += 1;
				if (choice1 == 7)
					choice1 = 0;
				HCN_VienLon(3, posYmenuGv1[choice1], 28, posYmenuGv1[choice1] + 4);
			}
			if (c == UP)
			{
				HCN_VienKep(3, posYmenuGv1[choice1], 28, posYmenuGv1[choice1] + 4);
				choice1 -= 1;
				if (choice1 == -1)
					choice1 = 6;
				HCN_VienLon(3, posYmenuGv1[choice1], 28, posYmenuGv1[choice1] + 4);
			}
		}
		else if (c == ENTER)
		{
			int tmp = luachonGv2(choice1);
			if (tmp == 0)
			{
				NenTrang();
				KhungMenuGv1();
				HCN_VienKep(3, 2, 28, 2 + 4);
				HCN_VienLon(3, posYmenuGv1[choice1], 28, posYmenuGv1[choice1] + 4);
			}
			else
				return tmp;
		}
		else if (c == ESC)
		{
			return 21;
		}
	}
}
int luachonGv2(int choice1)
{
	KhungMenuGv2(choice1);
	switch (choice1)
	{
	case 4:
	{
		return 13;
	}
	case 5:
	{
		return 16;
	}
	}
	int choice2 = 0;
	while (1)
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == DOWN)
			{
				HCN_VienKep(3, posYmenuGv2[choice2], 28, posYmenuGv2[choice2] + 4);
				choice2 += 1;
				if (choice2 == menuGv2[choice1].size() - 1)
					choice2 = 0;
				HCN_VienLon(3, posYmenuGv2[choice2], 28, posYmenuGv2[choice2] + 4);
			}
			if (c == UP)
			{
				HCN_VienKep(3, posYmenuGv2[choice2], 28, posYmenuGv2[choice2] + 4);
				choice2 -= 1;
				if (choice2 == -1)
					choice2 = menuGv2[choice1].size() - 1 - 1;
				HCN_VienLon(3, posYmenuGv2[choice2], 28, posYmenuGv2[choice2] + 4);
			}
		}
		if (c == ENTER)
		{
			switch (choice1)
			{
			case 0:
			{
				switch (choice2)
				{
				case 0:
					return 1;
				case 1:
					return 2;
				case 2:
					return 3;
				case 3:
					return 4;
				}
			}
			case 1:
			{
				switch (choice2)
				{
				case 0:
					return 5;
				case 1:
					return 6;
				case 2:
					return 17;
				case 3:
					return 18;
				}
			}
			case 2:
			{
				switch (choice2)
				{
				case 0:
					return 7;
				case 1:
					return 8;
				case 2:
					return 9;
				case 3:
					return 10;
				}
			}
			case 3:
			{
				switch (choice2)
				{
				case 0:
					return 11;
				case 1:
					return 12;
				case 2:
					return 22;
				case 3:
					return 23;
				}
			}
			case 6:
			{
				switch (choice2)
				{
				case 0:
					return 14;
				case 1:
					return 15;
				case 2:
					return 19;
				case 3:
					return 20;
				}
			}
			}
		}
		else if (c == ESC)
		{
			return 0;
		}
	}
}
//end tiennhot23
/*_______________________________________ [MENU CỦA GIÁO VIÊN] _______________________________________*/
char chucNangGV[ITEM_GV][100] =
	{ //Thay đổi item thì nhớ thay đổi ITEM_GV
		"1. Them 1 mon hoc            ",
		"2. In danh sach mon hoc      ",
		"3. Xoa 1 mon hoc             ",
		"4. Hieu chinh 1 mon hoc      ",
		"5. Them 1 cau hoi thi        ",
		"6. In danh sach cau hoi thi  ",
		"7. Them 1 lop                ",
		"8. In danh sach lop          ",
		"9. Xoa 1 lop                 ",
		"10. Hieu chinh 1 lop         ",
		"11. Them 1 sinh vien         ",
		"12. In danh sach sinh vien   ",
		"13. Thi trac nghiem          ",
		"14. Them diem mon hoc        ",
		"15. In diem mon hoc          ",
		"16. In lich su thi           ",
		"17. Xoa 1 cau hoi thi        ",
		"18. Hieu chinh 1 cau hoi thi ",
		"19. Hieu chinh diem thi      ",
		"20. Xoa diem thi             ",
		"0. Dang xuat va luu du lieu  "};

int MenuDongGV(){
	return luachonGv1();
}
void MenuGV(DanhSachMonHoc &dsmh, DanhSachCauHoiThi &dscht, DanhSachLop &dsl, MangRandomID &mri)
{
	srand(time(NULL));
	int luaChon;
	int yeuCauCuaGV = 0;
	bool kiemTra = true;
	while (kiemTra == true)
	{
		AnConTro();
		Normal();
		NenTrang();
		luaChon = MenuDongGV();
		switch (luaChon)
		{
		case 1:
			ThemMonHoc(dsmh);
			system("cls");
			break;
		case 2:
			system("cls");
			XuatDanhSachMonHoc(dsmh);
//			getch();
			system("cls");
			break;
		case 3:
			XoaMonHocTheoMaMonHoc(dsmh,dscht.TREE);
			system("cls");
			break;
		case 4:
			HieuChinhMonHoc(dsmh,dscht.TREE);
			system("cls");
			break;
		case 5:
			ThemCauHoiThi(dscht, dsmh, mri); //done
			break;
		case 6:
		{
			InDanhSachCauHoiThi(dscht.TREE, dsmh);
			break;
		}
		case 7:
		{
			ThemLop(dsl);
			system("cls");
			break;
		}
		case 8:
			system("cls");
			XuatDanhSachLop(dsl);
//			getch();
			system("cls");
			break;
		case 9:
			XoaLop(dsl);
			system("cls");
			break;
		case 10:
			HieuChinhLop(dsl);
			system("cls");
			break;
		case 11:
		{
			ThemSinhVien(dsl);
			system("cls");
			break;
		}
		case 12:
			system("cls");
			InDanhSachSinhVien(dsl);
			system("cls");
			break;
		case 13: //done
		{
			KhungNhapHinhThucThi();
			string hinhThuc[3];
			int mode = NhapHinhThucThiGV(dscht.TREE, dsmh, hinhThuc);
			if (mode == 1)
			{
				TrangThaiHinhThucThi(mode);
				ThiTracNghiemGV(dscht.TREE, dsmh, hinhThuc);
			}
			AnConTro();
			HCN_NenTrang(75, 17, 116, 28);
			break;
		}
		case 14:
		{
			ThemDiemThi(dsl, dsmh); //done
			break;
		}
		case 15:
			InDanhSachDiemThi(dsl); //done
			break;
		case 16:	
			InLichSuThi(dsl, dsmh, dscht.TREE);
			break;
		case 17:
			XoaCauHoiThi(dscht.TREE, dsl); //done
			break;
		case 18:
			HieuChinhCauHoiThi(dscht.TREE, dsmh, dsl); //done
			break;
		case 19:
			HieuChinhDiemThi(dsl, dsmh); //done
			break;
		case 20:
			XoaDiemThi(dsl, dsmh); //done
			break;
		case 22:{
			XoaSinhVien(dsl);
			system("cls");
			break;
		}
		case 23:{
			HieuChinhSinhVien(dsl);
			system("cls");
			break;
		}
		default:
		{
			LuuDuLieuMonHoc(dsmh);
			LuuDuLieuLop(dsl);
			LuuDuLieuSinhVien(dsl);
			LuuDuLieuDiemThi(dsl);
			LuuDuLieuCauHoiThi(dscht);
			LuuMangRandomID(mri);
			kiemTra = false;
			break;
		}
		}
	}
}
/*_____________________________________ [END MENU CỦA GIÁO VIÊN] _____________________________________*/

/*_______________________________________ [MENU CỦA SINH VIÊN] _______________________________________*/

void MenuSV(DanhSachMonHoc &dsmh, DanhSachCauHoiThi &dscht, DanhSachLop &dsl, NodeSinhVien *p)
{
	KhungMenuSv();
	char kiTu;
	bool phimKep;
	int choice = 0;
	while (true)
	{
		kiTu = getch();
		if (kiTu == -32 || kiTu == 0)
		{
			phimKep = true;
			kiTu = getch();
		}
		else
		{
			phimKep = false;
		}
		while (kiTu != ENTER)
		{
			if (((kiTu == UP || kiTu == DOWN) && phimKep) || (kiTu == TAB && !phimKep))
			{
				if (choice == 0)
				{
					HCN_VienKep(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
					choice++;
					if (choice == 2)
						choice = 0;
					HCN_VienLon(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
				}
				else if (choice == 1)
				{
					HCN_VienKep(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
					choice--;
					if (choice == -1)
						choice = 1;
					HCN_VienLon(3, posYmenuSv[choice], 28, posYmenuSv[choice] + 4);
				}
			}
			else if (kiTu == ESC)
			{
				goto THOAT;
			}

			kiTu = getch();
			if (kiTu == -32 || kiTu == 0)
			{
				phimKep = true;
				kiTu = getch();
			}
			else
			{
				phimKep = false;
			}
		}
		if (choice == 0)
		{
			HCN_VienKep(3, posYmenuSv[0], 28, posYmenuSv[0] + 4);
			KhungNhapHinhThucThi();
			string hinhThuc[3];
			int mode = NhapHinhThucThi(dscht.TREE, dsmh, p, hinhThuc);
			if (mode == 1)
			{
				TrangThaiHinhThucThi(mode);
				ThiTracNghiem(dscht.TREE, p, dsmh, hinhThuc);
				LuuDuLieuDiemThi(dsl);
				LuuDuLieuBaiThi(dsl);
				HCN_VienLon(3, 2, 28, 2 + 4);
			}
			else
			{
				AnConTro();
				TrangThaiHinhThucThi(mode);
				HCN_VienLon(3, 2, 28, 2 + 4);
			}
		}
		else if (choice == 1)
		{
			break;
		}
	}
THOAT:
	NenTrang();
}
/*_______________________________________ [END MENU CỦA SINH VIÊN] _______________________________________*/
