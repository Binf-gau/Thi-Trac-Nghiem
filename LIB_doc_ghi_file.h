#pragma once
#include "LIB_lop.h"

// void LuuDuLieuCauHoiThi(DanhSachCauHoiThi &dscht)
// {
// 	ofstream fileOut;
// 	fileOut.open("Data\\DanhSachCauHoiThi.txt", ios::out);
// 	MangCauHoiThi mcht;
// 	ChuyenCaySangMang(dscht, mcht);
// 	for (int i = 0; i < mcht.soLuong; i++)
// 	{
// 		fileOut << mcht.mangCauHoiThi[i]->id << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->maMonHoc << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->noiDung << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->a << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->b << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->c << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->d << '|';
// 		fileOut << mcht.mangCauHoiThi[i]->dapAn;
// 		if (i < mcht.soLuong - 1)
// 			fileOut << endl;
// 	}
// 	HuyMangCauHoiThi(mcht);
// 	fileOut.close();
// }

/*_______________________________________ [Đọc - Lưu file Danh Sách Lớp] _______________________________________*/
void DocDuLieuLop(DanhSachLop &dsl)
{
	ifstream fileIn;
	fileIn.open("Data\\DanhSachLop.txt", ios::in);
	while (fileIn.eof() != true)
	{
		getline(fileIn, dsl.ds[dsl.sl].maLop, '|');
		getline(fileIn, dsl.ds[dsl.sl].tenLop, '\n');
		KhoiTaoDanhSachSinhVien(dsl);
		dsl.sl++;
	}
	fileIn.close();
}
void LuuDuLieuLop(DanhSachLop dsl)
{
	ofstream fileOut;
	fileOut.open("Data\\DanhSachLop.txt", ios::out);
	for (int i = 0; i < dsl.sl; i++)
	{
		fileOut << dsl.ds[i].maLop << '|';
		fileOut << dsl.ds[i].tenLop;
		if (i < dsl.sl - 1)
			fileOut << endl;
	}
	fileOut.close();
}

/*_____________________________________ [Đọc - Lưu file Danh Sách Sinh Viên] _____________________________________*/
void DocDuLieuSinhVien(DanhSachLop &dsl)
{
	ifstream fileIn;
	fileIn.open("Data\\DanhSachSinhVien.txt");
	while (!fileIn.eof())
	{
		string maLop;
		getline(fileIn, maLop, '|');
		int i = TimLopBangMaLop(dsl, maLop);
		if (i == -1)
		{
			getline(fileIn, maLop, '\n');
			continue;
		}
		else
		{
			SinhVien sv;
			getline(fileIn, sv.maSinhVien, '|');
			getline(fileIn, sv.ho, '|');
			getline(fileIn, sv.ten, '|');
			getline(fileIn, sv.phai, '|');
			getline(fileIn, sv.password, '\n');
			ThemSinhVienVaoCuoi(dsl.ds[i].dssv, TaoNodeSinhVien(sv));
			KhoiTaoDanhSachDiemThi(dsl.ds[i].dssv);
		}
	}
	fileIn.close();
}
void LuuDuLieuSinhVien(DanhSachLop dsl)
{
	ofstream fileOut;
	fileOut.open("Data\\DanhSachSinhVien.txt", ios::out);
	int i = 0;
	for (i; i < dsl.sl; i++)
	{
		NodeSinhVien *p = dsl.ds[i].dssv->pHead;
		while (p != NULL)
		{
			fileOut << dsl.ds[i].maLop << '|';
			fileOut << p->data.maSinhVien << '|';
			fileOut << p->data.ho << '|';
			fileOut << p->data.ten << '|';
			fileOut << p->data.phai << '|';
			fileOut << p->data.password;
			p = p->pNext;
			if (p != NULL)
				fileOut << endl;
		}
		break;
	}
	for (i = i + 1; i < dsl.sl; i++)
	{
		NodeSinhVien *p = dsl.ds[i].dssv->pHead;
		while (p != NULL)
		{
			fileOut << endl;
			fileOut << dsl.ds[i].maLop << '|';
			fileOut << p->data.maSinhVien << '|';
			fileOut << p->data.ho << '|';
			fileOut << p->data.ten << '|';
			fileOut << p->data.phai << '|';
			fileOut << p->data.password;
			p = p->pNext;
		}
	}
	fileOut.close();
}
/*_____________________________________ [Đọc - Lưu file Danh Sách Điểm Thi] _____________________________________*/
void DocDuLieuDiemThi(DanhSachLop &dsl)
{
	ifstream fileIn;
	fileIn.open("Data\\DanhSachDiemThi.txt", ios::in);
	while (!fileIn.eof())
	{
		string maSinhVien;
		getline(fileIn, maSinhVien, '|');
		for (int i = 0; i < dsl.sl; i++)
		{
			NodeSinhVien *p = TimSinhVienBangMaSinhVien(dsl.ds[i].dssv, maSinhVien);
			if (p != NULL)
			{
				string diem;
				DiemThi dt;
				getline(fileIn, dt.maMonHoc, '|');
				getline(fileIn, diem, '\n');
				dt.diem = atof(diem.c_str());
				dt.bl = new BaiLam;
				ThemDiemThiVaoCuoi(p->data.dsdt, TaoNodeDiemThi(dt));
				break;
			}
		}
	}
	fileIn.close();
}
void LuuDuLieuDiemThi(DanhSachLop dsl)
{
	ofstream fileOut;
	fileOut.open("Data\\DanhSachDiemThi.txt", ios::out);
	int i = 0;
	bool first = true;
	for (i; i < dsl.sl; i++)
	{
		NodeSinhVien *p = dsl.ds[i].dssv->pHead;
		while (p != NULL)
		{
			NodeDiemThi *q = p->data.dsdt->pHead;
			while (q != NULL)
			{
				if (first == false)
				{
					fileOut << endl;
					fileOut << p->data.maSinhVien << '|';
					fileOut << q->data.maMonHoc << '|';
					fileOut << q->data.diem;
				}
				else
				{
					first = false;
					fileOut << p->data.maSinhVien << '|';
					fileOut << q->data.maMonHoc << '|';
					fileOut << q->data.diem;
				}
				q = q->pNext;
			}
			p = p->pNext;
		}
	}
	fileOut.close();
}
/*_____________________________________ [Đọc - Lưu file Danh Sách Bài Thi] _____________________________________*/
void DocDuLieuBaiThi(DanhSachLop &dsl)
{
	ifstream fileIn;
	fileIn.open("Data\\DanhSachBaiThi.txt", ios::in);
	while (!fileIn.eof())
	{
		string maSinhVien;
		getline(fileIn, maSinhVien, '|');
		for (int i = 0; i < dsl.sl; i++)
		{
			NodeSinhVien *p = TimSinhVienBangMaSinhVien(dsl.ds[i].dssv, maSinhVien);
			if (p != NULL)
			{
				string maMonHoc;
				getline(fileIn, maMonHoc, '\n');
				NodeDiemThi *q = TimDiemThiBangMaMonHoc(p->data.dsdt, maMonHoc);
				if (q == NULL)
				{
					cout << "Loi - doc file bai thi";
					return;
				}
				else
				{
					// string ThoiGianYeuCau;
					// getline(fileIn, ThoiGianYeuCau, ' ');
					// q->data.bl->thoiGianYeuCau = atoi(ThoiGianYeuCau.c_str());
					fileIn >> q->data.bl->soLuongCauHoiYeuCau;
					fileIn >> q->data.bl->soLuongCauTraLoiDung;
					KhoiTaoMangCauHoi(q->data.bl);
					fileIn >> q->data.bl->thoiGianYeuCau;
					fileIn >> q->data.bl->thoiGianHoanThanh;
					for (int i = 0; i < q->data.bl->soLuongCauHoiYeuCau; i++)
					{
						string temp;
						fileIn >> q->data.bl->mangCauHoi[i]->id;
						getline(fileIn, temp, '|');
						getline(fileIn, q->data.bl->mangCauHoi[i]->traLoi, '\n');
					}
					break;
				}
			}
		}
	}
	fileIn.close();
}
void LuuDuLieuBaiThi(DanhSachLop dsl)
{
	ofstream fileOut;
	fileOut.open("Data\\DanhSachBaiThi.txt", ios::out);
	int i = 0;
	bool first = true;
	for (i; i < dsl.sl; i++)
	{
		NodeSinhVien *p = dsl.ds[i].dssv->pHead;
		while (p != NULL)
		{
			NodeDiemThi *q = p->data.dsdt->pHead;
			while (q != NULL)
			{
				if (first == false)
				{
					fileOut << endl;
					fileOut << p->data.maSinhVien << '|';
					fileOut << q->data.maMonHoc << endl;
					fileOut << q->data.bl->soLuongCauHoiYeuCau << ' ';
					fileOut << q->data.bl->soLuongCauTraLoiDung << ' ';
					fileOut << q->data.bl->thoiGianYeuCau << ' ';
					fileOut << q->data.bl->thoiGianHoanThanh << endl;
					for (int j = 0; j < q->data.bl->soLuongCauHoiYeuCau; j++)
					{
						fileOut << q->data.bl->mangCauHoi[j]->id << ' ' << '|';
						fileOut << q->data.bl->mangCauHoi[j]->traLoi;
						if (j < q->data.bl->soLuongCauHoiYeuCau - 1)
						{
							fileOut << endl;
						}
					}
				}
				else
				{
					first = false;
					fileOut << p->data.maSinhVien << '|';
					fileOut << q->data.maMonHoc << endl;
					fileOut << q->data.bl->soLuongCauHoiYeuCau << ' ';
					fileOut << q->data.bl->soLuongCauTraLoiDung << ' ';
					fileOut << q->data.bl->thoiGianYeuCau << ' ';
					fileOut << q->data.bl->thoiGianHoanThanh << endl;
					for (int j = 0; j < q->data.bl->soLuongCauHoiYeuCau; j++)
					{
						fileOut << q->data.bl->mangCauHoi[j]->id << ' ' << '|';
						fileOut << q->data.bl->mangCauHoi[j]->traLoi;
						if (j < q->data.bl->soLuongCauHoiYeuCau - 1)
						{
							fileOut << endl;
						}
					}
				}
				q = q->pNext;
			}
			p = p->pNext;
		}
	}
	fileOut.close();
}
