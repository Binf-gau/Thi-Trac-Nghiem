#pragma once
#include "LIB_menu.h"

#include "LIB_mon_hoc.h"
#include "LIB_cau_hoi_thi.h"
#include "LIB_mang_random_id.h"

/*_____________________________________ [ĐĂNG NHẬP] _____________________________________*/
void DangNhap()
{
	//------------- Khai báo biến danh sách -------------------
	DanhSachLop dsl;
	DanhSachMonHoc dsmh;
	DanhSachCauHoiThi dscht;
	MangRandomID mri;
	//--------------- loading file ------------------
	DocDuLieuMonHoc(dsmh);
	DocDuLieuCauHoiThi(dscht);
	DocDuLieuLop(dsl);
	DocDuLieuSinhVien(dsl);
	DocDuLieuDiemThi(dsl);
	DocDuLieuBaiThi(dsl);
	DocMangRandomID(mri);
	NenTrang();
	InChuDe();
	while (true) //sau khi đăng nhập thất bại, reset cac giá trị
	{
		
		KhungDangNhap();
		string dangNhap[2] = {"", ""};
		char kiTu;
		bool phimKep;
		int choice = 0;

		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
//			goto MENUGV;
			InChuDe();
			HienConTro();
			switch (choice)
			{
			case 0:
			{
				gotoxyUser(0);
				break;
			}
			case 1:
			{
				gotoxyPass(0);
				break;
			}
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

			while (kiTu != ENTER) // chứa di chuyển, xóa, cộng string
			{
				if (((kiTu == UP || kiTu == DOWN) && phimKep) || (kiTu == TAB && !phimKep))
				{
					if (choice == 0)
					{
						choice = 1;
						gotoxyPass(dangNhap[1].length());
					}
					else if (choice == 1)
					{
						choice = 0;
						gotoxyUser(dangNhap[0].length());
					}
				}

				else if (kiTu == RIGHT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					switch (choice)
					{
					case 0:
					{
						gotoxy(min(x + 1, 80 + (int)dangNhap[choice].length()), y);
						break;
					}
					case 1:
					{
						gotoxy(min(x + 1, 80 + (int)dangNhap[choice].length()), y);
						break;
					}
					}
				}

				else if (kiTu == LEFT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					switch (choice)
					{
					case 0:
					{
						gotoxy(max(wherex() - 1, 80), y);
						break;
					}
					case 1:
					{
						gotoxy(max(wherex() - 1, 80), y);
						break;
					}
					}
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int const viTri = x - 80;
					if (viTri >= 0)
					{
						AnConTro();
						switch (choice)
						{
						case 0:
						{
							if (dangNhap[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "   Empty    ", -1, MAU_XAM);
								gotoxyUser(0);
							}
							else if (dangNhap[choice].length() != 0 && viTri > 0)
							{
								dangNhap[choice].erase(dangNhap[choice].begin() + viTri - 1);
								gotoxyUser(0);
								cout << dangNhap[choice] << " ";
								gotoxy(80 + viTri - 1, y);
							}
							break;
						}
						case 1:
						{
							if (dangNhap[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "   Empty    ", -1, MAU_XAM);
								gotoxyPass(0);
							}
							else if (dangNhap[choice].length() != 0 && viTri > 0)
							{
								dangNhap[choice].erase(dangNhap[choice].begin() + viTri - 1);
								gotoxyPass(0);
								for (int i = 1; i <= dangNhap[choice].length(); i++)
								{
									cout << "*";
								}
								cout << " ";
								gotoxy(80 + viTri - 1, y);
							}
							break;
						}
						}
						HienConTro();
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && !phimKep) // kytu
				{
					int const viTri = wherex() - 80;
					int x = wherex();
					int y = wherey();
					AnConTro();
					switch (choice)
					{
					case 0:
					{
						if (dangNhap[choice].length() < 12)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							dangNhap[choice].insert(dangNhap[choice].begin() + viTri, kiTu);
							gotoxyUser(0);
							cout << dangNhap[choice];
							gotoxy(viTri + 1 + 80, 24);
						}
						else
						{
							gotoxyUser(0);
							ThongBaoNhanh(wherex(), wherey(), "    Full     ", -1, MAU_XAM);
							gotoxyUser(0);
							cout << dangNhap[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 1:
					{
						if (dangNhap[choice].length() < 12)
						{
							dangNhap[choice].insert(dangNhap[choice].begin() + viTri, kiTu);
							gotoxyPass(0);
							for (int i = 1; i <= dangNhap[choice].length(); i++)
							{
								cout << "*";
							}
							gotoxy(viTri + 1 + 80, y);
						}
						else
						{
							gotoxyPass(0);
							ThongBaoNhanh(wherex(), wherey(), "    Full     ", -1, MAU_XAM);
							gotoxyPass(0);
							for (int i = 1; i <= dangNhap[choice].length(); i++)
							{
								cout << "*";
							}
							gotoxy(x, y);
						}
						break;
					}
					}
					HienConTro();
				}

				else if (kiTu == ESC)
				{
					HuyAVLTree(dscht.TREE);
					HuyDanhSachSinhVienTungLop(dsl);
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
			//kiem tra du lieu da nhap sau khi an enter
			if (dangNhap[0].length() == 0 || dangNhap[1].length() == 0) // khong co user hoac pass
			{
				if (dangNhap[0].length() == 0)
				{
					gotoxyUser(0); //  Quay lai user
					choice = 0;
				}
				else
				{
					gotoxyPass(0); // Quay lai pass
					choice = 1;
				}
			}
			else // Co user va pass
			{
				AnConTro();
				if (dangNhap[0] == "GV" && (dangNhap[1] == "GV" || dangNhap[1] == "gv"))
				{
					TrangThaiDangNhap(true);
				MENUGV:;
					MenuGV(dsmh, dscht, dsl, mri);
					NenTrang();
					InChuDe();
					break;
				}
				else
				{
					for (int i = 0; i < dsl.sl; i++)
					{
						NodeSinhVien *p = TimSinhVienBangMaSinhVien(dsl.ds[i].dssv, dangNhap[0]);
						if (p != NULL && (p->data.password == dangNhap[1]))
						{
							TrangThaiDangNhap(true);
							NenTrang();
							MenuSV(dsmh, dscht, dsl, p);
							goto DANGNHAP;
						}
					}
					TrangThaiDangNhap(false);
					break;
				}
			}
		}
	DANGNHAP:;
	}
THOAT:;
}
