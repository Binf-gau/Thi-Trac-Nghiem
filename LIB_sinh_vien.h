#pragma once
#include "LIB_diem_thi.h"
///*_____________________________________ [Danh Sách Sinh Viên] _____________________________________*/
//1.
typedef struct SinhVien
{
	string maSinhVien;
	string ho;
	string ten;
	string phai;
	string password;
	DanhSachDiemThi *dsdt;
	
};
//2.
typedef struct NodeSinhVien
{
	SinhVien data;
	NodeSinhVien *pNext;
};
//3.
typedef struct DanhSachSinhVien
{
	NodeSinhVien *pHead;
	NodeSinhVien *pTail;
};
/*_____________________________________ [Xử Lí - Danh Sách Sinh Viên] _____________________________________*/
void KhoiTaoDanhSachDiemThi(DanhSachSinhVien *dssv)
{
	DanhSachDiemThi *dsdt = new DanhSachDiemThi;
	dsdt->pHead = dsdt->pTail = NULL;
	dssv->pTail->data.dsdt = dsdt;
}
//Cho danh sách sinh viên chảy từ phead đến ptail và giải phóng *dssv
void GiaiPhongPTRdsdt(DanhSachDiemThi *dsdt)
{
	delete dsdt;
}
//4. Tạo 1 node sinh viên mới
NodeSinhVien *TaoNodeSinhVien(SinhVien sv)
{
	NodeSinhVien *p = new NodeSinhVien;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = sv;
	p->pNext = NULL;
	return p;
}
//6. Thêm 1 node sinh viên vào đầu danh sách
void ThemSinhVienVaoDau(DanhSachSinhVien *dssv, NodeSinhVien *new_node)
{
	if (dssv->pHead == NULL)
	{
		dssv->pHead = new_node;
	}
	else
	{
		new_node->pNext = dssv->pHead;
		dssv->pHead = new_node;
	}
}
//7. Thêm 1 node sinh viên vào cuối danh sách
void ThemSinhVienVaoCuoi(DanhSachSinhVien *dssv, NodeSinhVien *new_node)
{
	if (dssv->pHead == NULL)
	{
		dssv->pHead = dssv->pTail = new_node;
	}
	else
	{
		dssv->pTail->pNext = new_node;
		dssv->pTail = new_node;
	}
}
//8. Nhập mã sinh viên x ----> Trả về 1 node sinh viên
NodeSinhVien *TimSinhVienBangMaSinhVien(DanhSachSinhVien *dssv, string maSinhVien)
{
	NodeSinhVien *p = dssv->pHead;
	while (p != NULL)
	{
		if (p->data.maSinhVien == maSinhVien)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
//9. Nhập số thứ tự k ----> Trả về 1 node sinh viên
NodeSinhVien *TimSinhVienBangSoThuTu(DanhSachSinhVien *dssv, int k)
{
	int stt = 0;
	NodeSinhVien *p = dssv->pHead;
	while (p != NULL)
	{
		if (++stt == k - 1)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
//10. Chen 1 node vao sau node q trong danh sach.
void ThemSinhVienVaoSauNodeQ(DanhSachSinhVien dssv, NodeSinhVien *new_node, NodeSinhVien *q)
{
	if (q != NULL)
	{
		new_node->pNext = q->pNext;
		q->pNext = new_node;
		if (q == dssv.pTail)
		{
			dssv.pTail = new_node;
		}
	}
}
//11. Xoa 1 node o dau cua danh sach.
void XoaSinhVienTaiDau(DanhSachSinhVien *dssv)
{
	if (dssv->pHead == NULL)
	{
		return;
	}
	NodeSinhVien *p;
	p = dssv->pHead;
	dssv->pHead = p->pNext;
	if (dssv->pHead == NULL)
	{
		dssv->pTail = NULL;
	}
	delete p;
	return;
}
//12. Xoa 1 node o sau node q trong danh sach.
void XoaSinhVienTaiSauNodeQ(DanhSachSinhVien *dssv, NodeSinhVien *q)
{
	if (q != NULL && q->pNext != NULL)
	{
		NodeSinhVien *p;
		p = q->pNext;
		q->pNext = p->pNext;
		if (p == dssv->pTail)
		{
			dssv->pTail = q;
		}
		delete p;
		return;
	}
	else
	{
		return;
	}
}
//13. Huy 1 phan tu co khoa la k.
void XoaSinhVienTheoMaSinhVien(DanhSachSinhVien *dssv, string k)
{
	//- Duyet va tim.
	NodeSinhVien *p;
	p = dssv->pHead;
	NodeSinhVien *q;
	q = NULL;
	while (p != NULL)
	{
		if (p->data.maSinhVien == k)
		{
			break;
		}
		q = p;
		p = p->pNext;
	}
	//- Kiem tra.
	if (p == NULL)
	{
		cout << "Khong tim thay k.";
		return;
	}
	else if (q == NULL)
	{
		XoaSinhVienTaiDau(dssv);
		return;
	}
	else
	{
		XoaSinhVienTaiSauNodeQ(dssv, q);
		return;
	}
}
//14. Dem so node trong danh sach.
int SoLuongSinhVien(DanhSachSinhVien dssv)
{
	int count = 0;
	NodeSinhVien *p;
	p = dssv.pHead;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}
//15. Huy toan bo danh sach.
void HuyDanhSachSinhVien(DanhSachSinhVien *dssv)
{
	NodeSinhVien *p;
	while (dssv->pHead != NULL)
	{
		HuyDanhSachDiemThi(dssv->pHead->data.dsdt);
		GiaiPhongPTRdsdt(dssv->pHead->data.dsdt);
		p = dssv->pHead;
		dssv->pHead = p->pNext;
		delete p;
	}
	dssv->pTail = NULL;
}
