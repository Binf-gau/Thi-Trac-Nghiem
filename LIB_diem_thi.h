#pragma once
#include "LIB_bai_lam.h"

/*____________________ [Danh Sách Điểm Thi] ___________________*/
typedef struct DiemThi
{
	string maMonHoc;
	float diem;
	BaiLam *bl;
};
typedef struct NodeDiemThi
{
	DiemThi data;
	NodeDiemThi *pNext;
};
typedef struct DanhSachDiemThi
{
	NodeDiemThi *pHead;
	NodeDiemThi *pTail;
};

/*______________________ [Khai Báo Nguyên Mẫu Hàm] ______________________*/
void KhoiTaoBaiLam(BaiLam *bl);
void GiaiPhongPTRbl(BaiLam *bl);
NodeDiemThi *TaoNodeDiemThi(DiemThi dt);
void ThemDiemThiVaoCuoi(DanhSachDiemThi *dsdt, NodeDiemThi *new_node);
NodeDiemThi *TimDiemThiBangMaMonHoc(DanhSachDiemThi *dsdt, string maMonHoc);
void ThemDiemThiVaoSauNodeQ(DanhSachDiemThi *dsdt, NodeDiemThi *new_node, NodeDiemThi *q);
bool XoaDiemThiTaiDau(DanhSachDiemThi *dsdt);
bool XoaDiemThiTaiSauNodeQ(DanhSachDiemThi *dsdt, NodeDiemThi *q);
bool XoaDiemThiTheoMaMonHoc(DanhSachDiemThi *dsdt, string k);
int SoLuongDiemThi(DanhSachDiemThi *dsdt);
void HuyDanhSachDiemThi(DanhSachDiemThi *dsdt);
/*______________________ [] ______________________*/

/*______________________ [Xử lí - Danh Sách Điểm Thi] _________________________*/
void KhoiTaoBaiLam(BaiLam *bl)
{
	bl = new BaiLam;
}
void GiaiPhongPTRbl(BaiLam *bl)
{
	delete bl;
}

/*  2. Tạo 1 node điểm thi mới */
NodeDiemThi *TaoNodeDiemThi(DiemThi dt)
{
	NodeDiemThi *p = new NodeDiemThi;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = dt;
	p->pNext = NULL;
	return p;
}
/* 3. Gắn 1 node điểm thi mới vào cuối danh sách */
void ThemDiemThiVaoCuoi(DanhSachDiemThi *dsdt, NodeDiemThi *new_node)
{
	if (dsdt->pHead == NULL)
	{
		dsdt->pHead = dsdt->pTail = new_node;
	}
	else
	{
		dsdt->pTail->pNext = new_node;
		dsdt->pTail = new_node;
	}
}
/* 4. Tìm 1 node điểm thi bằng mã môn học */
NodeDiemThi *TimDiemThiBangMaMonHoc(DanhSachDiemThi *dsdt, string maMonHoc)
{
	NodeDiemThi *p = dsdt->pHead;
	while (p != NULL)
	{
		if (p->data.maMonHoc == maMonHoc)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
/* 5. Thêm 1 node điểm thi vào sau node q trong danh sách điểm thi */
void ThemDiemThiVaoSauNodeQ(DanhSachDiemThi *dsdt, NodeDiemThi *new_node, NodeDiemThi *q)
{
	if (q != NULL)
	{
		new_node->pNext = q->pNext;
		q->pNext = new_node;
		if (q == dsdt->pTail)
		{
			dsdt->pTail = new_node;
		}
	}
}
/* 6. Xóa 1 node điểm thi ở dầu danh sách điểm thi
- hàm này cần thiết để xóa 1 node điểm thi trong khi danh sách điểm thi chỉ có 1 node điểm thi */
bool XoaDiemThiTaiDau(DanhSachDiemThi *dsdt)
{
	if (dsdt->pHead == NULL)
	{
		return false;
	}
	NodeDiemThi *p;
	p = dsdt->pHead;
	dsdt->pHead = p->pNext;
	if (dsdt->pHead == NULL)
	{
		dsdt->pTail = NULL;
	}
	delete p;
	return true;
}
/* 7. Xóa 1 node điểm thi ở sau node q trong danh sách điểm thi */
bool XoaDiemThiTaiSauNodeQ(DanhSachDiemThi *dsdt, NodeDiemThi *q)
{
	if (q != NULL && q->pNext != NULL)
	{
		NodeDiemThi *p;
		p = q->pNext;
		q->pNext = p->pNext;
		if (p == dsdt->pTail)
		{
			dsdt->pTail = q;
		}
		delete p;
		return true;
	}
	else
	{
		return false;
	}
}
/* 8. Xóa 1 node điểm thi bằng mã môn học */
bool XoaDiemThiTheoMaMonHoc(DanhSachDiemThi *dsdt, string k)
{
	/* duyệt và tìm */
	NodeDiemThi *p;
	p = dsdt->pHead;
	NodeDiemThi *q;
	q = NULL;
	while (p != NULL)
	{
		if (p->data.maMonHoc == k)
		{
			break;
		}
		q = p;
		p = p->pNext;
	}
	/* kiểm tra */
	if (p == NULL)
	{
		ThongBao("Khong tim thay ma mon hoc");
		return 0;
	}
	else if (q == NULL)
	{
		HuyMangCauHoi(dsdt->pHead->data.bl);
		GiaiPhongPTRbl(dsdt->pHead->data.bl);
		XoaDiemThiTaiDau(dsdt);
		return 1;
	}
	else
	{
		HuyMangCauHoi(dsdt->pHead->data.bl);
		GiaiPhongPTRbl(dsdt->pHead->data.bl);
		XoaDiemThiTaiSauNodeQ(dsdt, q);
		return 1;
	}
}
/* 9. Đếm số lượng node trong danh sách điểm thi */
int SoLuongDiemThi(DanhSachDiemThi *dsdt)
{
	int dem = 0;
	NodeDiemThi *p;
	p = dsdt->pHead;
	while (p != NULL)
	{
		dem++;
		p = p->pNext;
	}
	return dem;
}
/* 10. Hủy toàn bộ các node, hủy danh sách điểm thi */
void HuyDanhSachDiemThi(DanhSachDiemThi *dsdt)
{
	NodeDiemThi *p;
	while (dsdt->pHead != NULL)
	{
		HuyMangCauHoi(dsdt->pHead->data.bl);
		GiaiPhongPTRbl(dsdt->pHead->data.bl);
		p = dsdt->pHead;
		dsdt->pHead = p->pNext;
		delete p;
	}
	dsdt->pTail = NULL;
}