#pragma once
#include "LIB_linh_tinh.h"
/*_____________________________________ [Danh Sách Câu Hỏi] _____________________________________*/
typedef struct CauHoi
{
    int id;
    string traLoi = "";
};
typedef struct BaiLam
{
    CauHoi **mangCauHoi;
    int thoiGianYeuCau = 0;
    int thoiGianHoanThanh = 0;
    int soLuongCauHoiYeuCau = 0;
    int soLuongCauTraLoiDung = 0;
};

/*______________________ [Khai Báo Nguyên Mẫu Hàm] ______________________*/
void KhoiTaoMangCauHoi(BaiLam *bt);
void HuyMangCauHoi(BaiLam *bt);

/*_____________________________________ [Xử Lí - Bài Thi] _____________________________________*/
void KhoiTaoMangCauHoi(BaiLam *bt)
{
	bt->mangCauHoi = new CauHoi*[bt->soLuongCauHoiYeuCau];
	for (int i = 0; i < bt->soLuongCauHoiYeuCau; i++)
	{
		bt->mangCauHoi[i] = new CauHoi;
	}
}
void HuyMangCauHoi(BaiLam *bt)
{
	while (bt->soLuongCauHoiYeuCau > 0)
	{
		delete bt->mangCauHoi[bt->soLuongCauHoiYeuCau - 1];
		bt->soLuongCauHoiYeuCau--;
	}
	delete[] bt->mangCauHoi;
}
































// chuyển cây nhị phân tìm kiếm cân bằng sang mảng
// void GhiVaoMangCauHoiThi(AVLTree TREE, MangCauHoiThi &mcht) // chuyển cây sang mảng
// {
// 	if (TREE != NULL)
// 	{
// 		mcht.mangCauHoiThi[mcht.soLuong]->id = TREE->id;
// 		mcht.mangCauHoiThi[mcht.soLuong]->maMonHoc = TREE->maMonHoc;
// 		mcht.mangCauHoiThi[mcht.soLuong]->noiDung = TREE->noiDung;
// 		mcht.mangCauHoiThi[mcht.soLuong]->a = TREE->a;
// 		mcht.mangCauHoiThi[mcht.soLuong]->b = TREE->b;
// 		mcht.mangCauHoiThi[mcht.soLuong]->c = TREE->c;
// 		mcht.mangCauHoiThi[mcht.soLuong]->d = TREE->d;
// 		mcht.mangCauHoiThi[mcht.soLuong]->dapAn = TREE->dapAn;
// 		mcht.soLuong++;
// 		GhiVaoMangCauHoiThi(TREE->pLeft, mcht);
// 		GhiVaoMangCauHoiThi(TREE->pRight, mcht);
// 	}
// }
// void ChuyenCaySangMang(DanhSachCauHoiThi dscht, MangCauHoiThi &mcht)
// {
// 	KhoiTaoMangCauHoiThi(dscht, mcht);
// 	mcht.soLuong = 0;
// 	GhiVaoMangCauHoiThi(dscht.TREE, mcht);
// }
// void SwapID(NodeCauHoiThi &a, NodeCauHoiThi &b)
// {
// 	NodeCauHoiThi tmp = a;
// 	a = b;
// 	b = tmp;
// }
// void QuickSortID(MangCauHoiThi &mcht, int left, int right)
// {
// 	int x = mcht.mangCauHoiThi[(left + right) / 2]->id;
// 	int i = left;
// 	int j = right;
// 	do
// 	{
// 		while (mcht.mangCauHoiThi[i]->id < x)
// 			i++;
// 		while (mcht.mangCauHoiThi[j]->id > x)
// 			j--;
// 		if (i <= j)
// 		{
// 			SwapID(*mcht.mangCauHoiThi[i], *mcht.mangCauHoiThi[j]);
// 			i++;
// 			j--;
// 		}
// 	} while (i <= j);
// 	if (i < right)
// 		QuickSortID(mcht, i, right);
// 	if (left < j)
// 		QuickSortID(mcht, left, j);
// }
// void SapXepCauHoiThiTheoIdTang(DanhSachCauHoiThi dscht, MangCauHoiThi &mcht)
// {
// 	ChuyenCaySangMang(dscht, mcht);
// 	QuickSortID(mcht, 0, mcht.soLuong - 1);
// }