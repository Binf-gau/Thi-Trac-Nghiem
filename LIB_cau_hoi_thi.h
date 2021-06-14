#pragma once
#include "LIB_lop.h"
#include "LIB_dong_ho.h"

#define LH -1 //cây con trái cao hơn
#define EH 0  //hai cây con bằng nhau
#define RH 1  //cây con phải cao hơn

/*_______ [Danh Sách Câu Hỏi Thi] ____*/
typedef struct NodeCauHoiThi
{
	int id;
	int balFactor;
	string maMonHoc;
	string noiDung;
	string a;
	string b;
	string c;
	string d;
	string dapAn;
	NodeCauHoiThi *pLeft;
	NodeCauHoiThi *pRight;
};
typedef NodeCauHoiThi *AVLTree;
typedef struct DanhSachCauHoiThi
{
	AVLTree TREE = NULL;
};
typedef struct MangID
{
	int *mangID;
	int soLuong;
};

/*______________________ [Khai Báo Nguyên Mẫu Hàm] ______________________*/
/* Xử lí AVLTree */
void RotateLL(AVLTree &TREE);
void RotateRR(AVLTree &TREE);
void RotateLR(AVLTree &TREE);
void RotateRL(AVLTree &TREE);
int BalanceLeft(AVLTree &TREE);
int BalanceRight(AVLTree &TREE);
int InsertNodeCauHoiThi(AVLTree &TREE, AVLTree p);
int TimPhanTuTheMang(AVLTree &p, AVLTree &q);
int XoaNodeCauHoiThi(AVLTree &TREE, int id);
AVLTree TimPhanTuPhaiCung(AVLTree TREE);
AVLTree TimCauHoiThiBangMaID(AVLTree TREE, int id);
void HuyAVLTree(AVLTree &TREE);
bool NhapNodeCauHoiThi(DanhSachMonHoc dsmh, string line[]);
bool HieuChinhNodeCauHoiThi(DanhSachMonHoc dsmh, string line[]);
bool ThemCauHoiThi(DanhSachCauHoiThi &dscht, DanhSachMonHoc dsmh, MangRandomID &mri);
void HieuChinhCauHoiThi(AVLTree &TREE, DanhSachMonHoc dsmh, DanhSachLop dsl);
bool XoaCauHoiThi(AVLTree &TREE, DanhSachLop dsl);
int SoLuongCauHoiThi(AVLTree TREE);
int SoLuongCauHoi1Mon(AVLTree TREE, string maMonHoc);
void InCauHoiThiTheoMMH(AVLTree TREE, string maMonHoc);
void InDanhSachCauHoiThi(AVLTree TREE, DanhSachMonHoc dsmh);
void InLichSuThi(DanhSachLop dsl, DanhSachMonHoc dsmh, AVLTree TREE);

/* Xử lí mảng ID (dùng để random id câu hỏi) */
void KhoiTaoMangID(MangID &mi, int soLuong);
void HuyMangID(MangID &mi);
void ThemVaoMangID(MangID &mi, AVLTree TREE, string maMonHoc);
void TaoCauHoiNgauNhien(MangID &mi, AVLTree TREE, int soLuongCauHoiYeuCau);
void TaoMangCauHoi(MangID mi, AVLTree TREE, BaiLam *bl);
/* Xử lí mảng thi trắc nghiệm */
void ChamDiem(DiemThi &dt, AVLTree TREE);
void DeThi(DiemThi &dt, AVLTree TREE);
void ThiTracNghiem(AVLTree TREE, NodeSinhVien *p, DanhSachMonHoc dsmh, string line[]);
void ThiTracNghiemGV(AVLTree TREE, DanhSachMonHoc dsmh, string line[]);
int NhapHinhThucThi(AVLTree TREE, DanhSachMonHoc dsmh, NodeSinhVien *p, string line[]);
int NhapHinhThucThiGV(AVLTree TREE, DanhSachMonHoc dsmh, string line[]);
/* Dọc Ghi File */
void DocDuLieuCauHoiThi(DanhSachCauHoiThi &dscht);
void LuuDuLieu1CauHoiThi(AVLTree p, AVLTree q);
void LuuDuLieuCauHoiThi(DanhSachCauHoiThi dscht);

/*_____________________________________ [Xử Lí - Danh Sách Câu Hỏi Thi] _____________________________________*/
//1. quay đơn left-left
void RotateLL(AVLTree &TREE)
{
	AVLTree T1 = TREE->pLeft;
	TREE->pLeft = T1->pRight;
	T1->pRight = TREE;
	switch (T1->balFactor)
	{
	case LH:
		TREE->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		TREE->balFactor = LH;
		T1->balFactor = RH;
		break;
	}
	TREE = T1;
}
//2. quay đơn right-right
void RotateRR(AVLTree &TREE)
{
	AVLTree T1 = TREE->pRight;
	TREE->pRight = T1->pLeft;
	T1->pLeft = TREE;
	switch (T1->balFactor)
	{
	case RH:
		TREE->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		TREE->balFactor = RH;
		T1->balFactor = LH;
		break;
	}
	TREE = T1;
}
//3. quay kép left-right
void RotateLR(AVLTree &TREE)
{
	AVLTree T1 = TREE->pLeft;
	AVLTree T2 = T1->pRight;
	TREE->pLeft = T2->pRight;
	T2->pRight = TREE;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	switch (T2->balFactor)
	{
	case LH:
	{
		TREE->balFactor = RH;
		T1->balFactor = EH;
		break;
	}
	case EH:
	{
		TREE->balFactor = EH;
		T1->balFactor = EH;
		break;
	}
	case RH:
	{
		TREE->balFactor = EH;
		T1->balFactor = LH;
		break;
	}
	}
	T2->balFactor = EH;
	TREE = T2;
}
//4. quay kép right-left
void RotateRL(AVLTree &TREE)
{
	AVLTree T1 = TREE->pRight;
	AVLTree T2 = T1->pLeft;
	TREE->pRight = T2->pLeft;
	T2->pLeft = TREE;
	T1->pLeft = T2->pRight;
	T2->pRight = T1;
	switch (T2->balFactor)
	{
	case RH:
	{
		TREE->balFactor = LH;
		T1->balFactor = EH;
		break;
	}
	case EH:
	{
		TREE->balFactor = EH;
		T1->balFactor = EH;
		break;
	}
	case LH:
	{
		TREE->balFactor = EH;
		T1->balFactor = RH;
		break;
	}
	}
	T2->balFactor = EH;
	TREE = T2;
}
//5. cân bằng cây khi cây bị lệch về bên trái
int BalanceLeft(AVLTree &TREE)
{
	AVLTree T1 = TREE->pLeft;
	switch (T1->balFactor)
	{
	case LH:
	{
		RotateLL(TREE);
		return 2;
	}
	case EH:
	{
		RotateLL(TREE);
		return 1;
	}
	case RH:
	{
		RotateLR(TREE);
		return 2;
	}
	}
	return 0;
}
//6. cân bằng cây khi cây bị lệch về bên phải
int BalanceRight(AVLTree &TREE)
{
	AVLTree T1 = TREE->pRight;
	switch (T1->balFactor)
	{
	case LH:
	{
		RotateRL(TREE);
		return 2;
	}
	case EH:
	{
		RotateRR(TREE);
		return 1;
	}
	case RH:
	{
		RotateRR(TREE);
		return 2;
	}
	}
	return 0;
}
//7. thêm 1 node câu hỏi thi trên cây AVL
/* 
							 T
							/ \
						  T1   [...] 
						 /  \    
			h-1		    /\   T2        h         
							 /\
 */
int InsertNodeCauHoiThi(AVLTree &TREE, AVLTree p)
{
	int res = 0;
	if (TREE)
	{
		if (TREE->id == p->id)
		{
			return 0; //đã có
		}
		if (TREE->id > p->id)
		{
			res = InsertNodeCauHoiThi(TREE->pLeft, p);
			if (res < 2) /* không cập nhật lại chỉ số cân bằng */
			{
				return res;
			}
			/* p được thêm vào cây, p nằm ở phía bên trái T2 */
			switch (TREE->balFactor)
			{
			case RH:
			{
				TREE->balFactor = EH;
				return 1;
			}
			case EH:
			{
				TREE->balFactor = LH;
				return 2;
			}
			case LH:
			{
				BalanceLeft(TREE);
				return 1;
			}
			}
		}
		else
		{
			res = InsertNodeCauHoiThi(TREE->pRight, p);
			if (res < 2) /* không cập nhật lại chỉ số cân bằng */
			{
				return res;
			}
			/* p được thêm vào cây, p nằm ở phía bên phải T2 */
			switch (TREE->balFactor)
			{
			case LH:
			{
				TREE->balFactor = EH;
				return 1;
			}
			case EH:
			{
				TREE->balFactor = RH; /* nếu TREE đang cân bằng thì sau khi thêm TREE lệch phải */
				return 2;			  /* tiếp tục điều chỉnh balFactor của TREE cha */
			}
			case RH:
			{
				BalanceRight(TREE);
				return 1;
			}
			}
		}
	}
	TREE = new NodeCauHoiThi;
	if (TREE == NULL)
	{
		return -1; //thiếu bộ nhớ
	}
	TREE = p;
	return 2; //thêm thành công, chiều cao tăng
}
//8. tìm phần tử thế mạng
int TimPhanTuTheMang(AVLTree &p, AVLTree &q)
{
	int res;
	if (q->pLeft)
	{
		res = TimPhanTuTheMang(p, q->pLeft);
		if (res < 2)
		{
			return res;
		}

		switch (q->balFactor)
		{
		case LH:
		{
			q->balFactor = EH;
			return 2;
		}
		case EH:
		{
			q->balFactor = RH;
			return 1;
		}
		case RH:
		{
			return BalanceRight(q);
		}
		}
	}
	else
	{
		p->id = q->id;
		p = q;
		q = q->pRight;
		return 2;
	}
}
//9. hủy 1 phần tử trên cây AVL
int XoaNodeCauHoiThi(AVLTree &TREE, int id) // sau khi hủy, chiều cao giảm, giá trị 2 sẽ được trả về
{
	int res;
	if (TREE == NULL)
	{
		return 0;
	}
	if (TREE->id > id)
	{
		res = XoaNodeCauHoiThi(TREE->pLeft, id);
		if (res < 2)
		{
			return res;
		}
		switch (TREE->balFactor)
		{
		case LH:
		{
			TREE->balFactor = EH;
			return 2;
		}
		case EH:
		{
			TREE->balFactor = RH;
			return 1;
		}
		case RH:
		{
			return BalanceRight(TREE);
		}
		}
	}
	else if (TREE->id < id)
	{
		res = XoaNodeCauHoiThi(TREE->pRight, id);
		if (res < 2)
		{
			return res;
		}
		switch (TREE->balFactor)
		{
		case RH:
		{
			TREE->balFactor = EH;
			return 2;
		}
		case EH:
		{
			TREE->balFactor = LH;
			return 1;
		}
		case LH:
		{
			return BalanceLeft(TREE);
		}
		}
	}
	else //TREE->id == id
	{
		AVLTree p = TREE;
		if (TREE->pLeft == NULL)
		{
			TREE = TREE->pRight;
			res = 2;
		}
		else if (TREE->pRight == NULL)
		{
			TREE = TREE->pLeft;
			res = 2;
		}
		else //T có cả 2 con
		{
			res = TimPhanTuTheMang(p, TREE->pRight);
			if (res < 2)
			{
				return res;
			}
			switch (TREE->balFactor)
			{
			case RH:
			{
				TREE->balFactor = EH;
				return 2;
			}
			case EH:
			{
				TREE->balFactor = LH;
				return 1;
			}
			case LH:
			{
				return BalanceLeft(TREE);
			}
			}
		}
		delete p;
		return res;
	}
}

AVLTree TimPhanTuPhaiCung(AVLTree TREE)
{
	AVLTree p;
	p = TREE;
	while (p->pRight != NULL)
	{
		p = p->pRight;
	}
	return p;
}

AVLTree TimCauHoiThiBangMaID(AVLTree TREE, int id)
{
	AVLTree p;
	p = TREE;
	while (p != NULL)
	{
		if (id < p->id)
		{
			p = p->pLeft;
		}
		else if (id > p->id)
		{
			p = p->pRight;
		}
		else
		{
			return p;
		}
	}
	return NULL;
}

void HuyAVLTree(AVLTree &TREE)
{
	if (TREE)
	{
		HuyAVLTree(TREE->pLeft);
		HuyAVLTree(TREE->pRight);
		delete TREE;
	}
}

bool NhapNodeCauHoiThi(DanhSachMonHoc dsmh, string line[])
{
	while (true)
	{
		line[0] = ""; // ma mon hoc
		line[1] = "";
		line[2] = "";
		line[3] = "";
		line[4] = "";
		line[5] = "";
		line[6] = ""; // dap an
		int e = 0;
		char kiTu = 'NULL';
		bool phimKep = false;
		int choice = 0;

		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
			switch (choice)
			{
			case 0:
			{
				gotoxyMaMonHoc(line[choice].length());
				break;
			}
			case 1:
			{
				e = line[choice].length() / 80;
				gotoxyCauHoi(line[choice].length() % 80, e);
				break;
			}
			case 2:
			{
				gotoxyA(line[choice].length());
				break;
			}
			case 3:
			{
				gotoxyB(line[choice].length());
				break;
			}
			case 4:
			{
				gotoxyC(line[choice].length());
				break;
			}
			case 5:
			{
				gotoxyD(line[choice].length());
				break;
			}
			case 6:
			{
				gotoxyDapAn(line[choice].length());
				break;
			}
			}
			HienConTro();

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
				if ((kiTu == DOWN && phimKep) || (kiTu == TAB && !phimKep))
				{
					switch (choice)
					{
					case 0:
					{
						choice++;
						e = line[1].length() / 80;
						gotoxyCauHoi(line[1].length() % 80, e);
						break;
					}
					case 1:
					{
						choice++;
						gotoxyA(line[choice].length());
						break;
					}
					case 2:
					{
						choice++;
						gotoxyB(line[choice].length());
						break;
					}
					case 3:
					{
						choice++;
						gotoxyC(line[choice].length());
						break;
					}
					case 4:
					{
						choice++;
						gotoxyD(line[choice].length());
						break;
					}
					case 5:
					{
						choice++;
						gotoxyDapAn(line[choice].length());
						break;
					}
					case 6:
					{
						choice = 0;
						gotoxyMaMonHoc(line[choice].length());
						break;
					}
					}
				}

				else if (kiTu == UP && phimKep)
				{
					switch (choice)
					{
					case 0:
					{
						choice = 6;
						gotoxyDapAn(line[choice].length());
						break;
					}
					case 1:
					{
						choice--;
						gotoxyMaMonHoc(line[choice].length());
						break;
					}
					case 2:
					{
						choice--;
						e = line[1].length() / 80;
						gotoxyCauHoi(line[1].length() % 80, e);
						break;
					}
					case 3:
					{
						choice--;
						gotoxyA(line[choice].length());
						break;
					}
					case 4:
					{
						choice--;
						gotoxyB(line[choice].length());
						break;
					}
					case 5:
					{
						choice--;
						gotoxyC(line[choice].length());
						break;
					}
					case 6:
					{
						choice--;
						gotoxyD(line[choice].length());
						break;
					}
					}
				}

				else if (kiTu == RIGHT && phimKep && choice != 1)
				{
					gotoxy(min(wherex() + 1, 61 + (int)line[choice].length()), wherey());
				}

				else if (kiTu == LEFT && phimKep && choice != 1)
				{
					gotoxy(max(wherex() - 1, 61), wherey());
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 61;
					if (viTri >= 0)
					{
						AnConTro();
						switch (choice)
						{
						case 0:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyMaMonHoc(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMaMonHoc(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 1:
						{
							if (viTri == 0 && e > 0)
							{
								e--;
								viTri = 80;
							}
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyCauHoi(0, 0);
							}
							else if (line[1].length() != 0 && viTri > 0)
							{
								line[1].erase(line[1].begin() + e * 80 + viTri - 1);
								for (int i = 0; i < e + 1; i++)
								{
									gotoxyCauHoi(0, i);
									cout << line[choice].substr(i * 80, 80);
								}
								cout << " ";
								gotoxyCauHoi(viTri - 1, e);
							}
							break;
						}
						case 2:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyA(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyA(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 3:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyB(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyB(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 4:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyC(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyC(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 5:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyD(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyD(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 6:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyDapAn(0);
							}
							else if (line[choice].length() != 0)
							{
								gotoxyDapAn(0);
								cout << " ";
								line[choice] = "";
								gotoxyDapAn(0);
							}
							break;
						}
						}
						HienConTro();
					}
				}

				else if ((kiTu >= 32 && kiTu <= 126) && !phimKep) // kytu
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 61;
					AnConTro();
					switch (choice)
					{
					case 0:
					{
						if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && line[choice].length() < 17)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyMaMonHoc(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else if (line[choice].length() >= 17)
						{
							gotoxyMaMonHoc(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyMaMonHoc(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 1: // noi dung cau hoi
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 559)
						{
							line[choice].insert(line[choice].begin() + 80 * e + viTri, kiTu);
							gotoxyCauHoi(0, 0);
							// e = line[choice].length() / 80;
							for (int i = 0; i < e + 1; i++)
							{
								gotoxyCauHoi(0, i);
								cout << line[1].substr(i * 80, 80);
							}
							if (viTri == 79)
							{
								e++;
								gotoxyCauHoi(0, e);
							}
							else
							{
								gotoxyCauHoi(viTri + 1, e);
							}
						}
						else
						{
							gotoxyCauHoi(viTri, e);
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							for (int i = 0; i < e + 1; i++)
							{
								gotoxyCauHoi(0, i);
								cout << line[1].substr(i * 80, 80);
							}
							gotoxyCauHoi(x, y);
						}
						break;
					}
					case 2:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyA(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyA(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyA(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 3:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyB(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyB(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyB(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 4:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyC(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyC(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyC(0);
							cout << line[choice];
							gotoxy(x, y);
						}

						break;
					}
					case 5:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyD(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyD(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyD(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 6:
					{
						if ((kiTu >= 'a' && kiTu <= 'd') || (kiTu >= 'A' && kiTu <= 'D'))
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice] = kiTu;
							gotoxyDapAn(0);
							cout << line[choice];
						}
						else
						{
							gotoxyDapAn(0);
							ThongBaoNhanh(wherex(), wherey(), "Dap an chi nhan A, B, C, D", -1, MAU_DO);
							cout << line[choice];
						}
						break;
					}
					}
					HienConTro();
				}

				else if (kiTu == ESC)
				{
					return 0;
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
			ChuanDauInHoa(line[1]);
			ChuanDauInHoa(line[2]);
			ChuanDauInHoa(line[3]);
			ChuanDauInHoa(line[4]);
			ChuanDauInHoa(line[5]);
			LamTrangKhungThemCauHoiThi();
			e = line[1].length() / 80;
			for (int i = 0; i < e + 1; i++)
			{
				gotoxyCauHoi(0, i);
				cout << line[1].substr(i * 80, 80);
			}
			gotoxyA(0);
			cout << line[2];
			gotoxyB(0);
			cout << line[3];
			gotoxyC(0);
			cout << line[4];
			gotoxyD(0);
			cout << line[5];
			//kiem tra du lieu da nhap sau khi an enter
			AnConTro();
			if (line[0].length() == 0)
			{
				choice = 0;
				gotoxyMaMonHoc(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap ma mon hoc", -1, MAU_DO);
			}
			else if (line[1].length() == 0)
			{
				choice = 1;
				gotoxyCauHoi(0, 0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung cau hoi", -1, MAU_DO);
			}
			else if (line[2].length() == 0)
			{
				choice = 2;
				gotoxyA(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[3].length() == 0)
			{
				choice = 3;
				gotoxyB(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[4].length() == 0)
			{
				choice = 4;
				gotoxyC(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[5].length() == 0)
			{
				choice = 5;
				gotoxyD(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[6].length() == 0)
			{
				choice = 6;
				gotoxyDapAn(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap dap an dung", -1, MAU_DO);
			}
			else // Co day du noi dung
			{
				if (TimMonHocTheoMaMonHoc(dsmh, line[0]) == -1)
				{
					gotoxyMaMonHoc(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMaMonHoc(0);
					cout << line[0];
					choice = 0;
				}
				else
				{
					return 1;
				}
			}
		}
	}
}
bool HieuChinhNodeCauHoiThi(DanhSachMonHoc dsmh, string line[])
{
	gotoxyMaMonHoc(0);
	cout << line[0];
	int e = line[1].length() / 80;
	for (int i = 0; i < e + 1; i++)
	{
		gotoxyCauHoi(0, i);
		cout << line[1].substr(i * 80, 80);
	}
	gotoxyA(0);
	cout << line[2];
	gotoxyB(0);
	cout << line[3];
	gotoxyC(0);
	cout << line[4];
	gotoxyD(0);
	cout << line[5];
	gotoxyDapAn(0);
	cout << line[6];
	while (true)
	{
		char kiTu = 'NULL';
		bool phimKep = false;
		int choice = 0;

		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
			switch (choice)
			{
			case 0:
			{
				gotoxyMaMonHoc(line[choice].length());
				break;
			}
			case 1:
			{
				e = line[choice].length() / 80;
				gotoxyCauHoi(line[choice].length() % 80, e);
				break;
			}
			case 2:
			{
				gotoxyA(line[choice].length());
				break;
			}
			case 3:
			{
				gotoxyB(line[choice].length());
				break;
			}
			case 4:
			{
				gotoxyC(line[choice].length());
				break;
			}
			case 5:
			{
				gotoxyD(line[choice].length());
				break;
			}
			case 6:
			{
				gotoxyDapAn(line[choice].length());
				break;
			}
			}
			HienConTro();

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
				if ((kiTu == DOWN && phimKep) || (kiTu == TAB && !phimKep))
				{
					switch (choice)
					{
					case 0:
					{
						choice++;
						e = line[1].length() / 80;
						gotoxyCauHoi(line[1].length() % 80, e);
						break;
					}
					case 1:
					{
						choice++;
						gotoxyA(line[choice].length());
						break;
					}
					case 2:
					{
						choice++;
						gotoxyB(line[choice].length());
						break;
					}
					case 3:
					{
						choice++;
						gotoxyC(line[choice].length());
						break;
					}
					case 4:
					{
						choice++;
						gotoxyD(line[choice].length());
						break;
					}
					case 5:
					{
						choice++;
						gotoxyDapAn(line[choice].length());
						break;
					}
					case 6:
					{
						choice = 0;
						gotoxyMaMonHoc(line[choice].length());
						break;
					}
					}
				}

				else if (kiTu == UP && phimKep)
				{
					switch (choice)
					{
					case 0:
					{
						choice = 6;
						gotoxyDapAn(line[choice].length());
						break;
					}
					case 1:
					{
						choice--;
						gotoxyMaMonHoc(line[choice].length());
						break;
					}
					case 2:
					{
						choice--;
						e = line[1].length() / 80;
						gotoxyCauHoi(line[1].length() % 80, e);
						break;
					}
					case 3:
					{
						choice--;
						gotoxyA(line[choice].length());
						break;
					}
					case 4:
					{
						choice--;
						gotoxyB(line[choice].length());
						break;
					}
					case 5:
					{
						choice--;
						gotoxyC(line[choice].length());
						break;
					}
					case 6:
					{
						choice--;
						gotoxyD(line[choice].length());
						break;
					}
					}
				}

				else if (kiTu == RIGHT && phimKep && choice != 1)
				{
					gotoxy(min(wherex() + 1, 61 + (int)line[choice].length()), wherey());
				}

				else if (kiTu == LEFT && phimKep && choice != 1)
				{
					gotoxy(max(wherex() - 1, 61), wherey());
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 61;
					if (viTri >= 0)
					{
						AnConTro();
						switch (choice)
						{
						case 0:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyMaMonHoc(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMaMonHoc(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 1:
						{
							if (viTri == 0 && e > 0)
							{
								e--;
								viTri = 80;
							}
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyCauHoi(0, 0);
							}
							else if (line[1].length() != 0 && viTri > 0)
							{
								line[1].erase(line[1].begin() + e * 80 + viTri - 1);
								for (int i = 0; i < e + 1; i++)
								{
									gotoxyCauHoi(0, i);
									cout << line[choice].substr(i * 80, 80);
								}
								cout << " ";
								gotoxyCauHoi(viTri - 1, e);
							}
							break;
						}
						case 2:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyA(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyA(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 3:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyB(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyB(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 4:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyC(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyC(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 5:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyD(0);
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyD(0);
								cout << line[choice] << " ";
								gotoxy(61 + viTri - 1, y);
							}
							break;
						}
						case 6:
						{
							if (line[choice].length() == 0)
							{
								ThongBaoNhanh(wherex(), wherey(), "Empty", -1, MAU_XAM);
								gotoxyDapAn(0);
							}
							else if (line[choice].length() != 0)
							{
								gotoxyDapAn(0);
								cout << " ";
								line[choice] = "";
								gotoxyDapAn(0);
							}
							break;
						}
						}
						HienConTro();
					}
				}

				else if ((kiTu >= 32 && kiTu <= 126) && !phimKep) // kytu
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 61;
					AnConTro();
					switch (choice)
					{
					case 0:
					{
						if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && line[choice].length() < 17)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyMaMonHoc(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else if (line[choice].length() >= 17)
						{
							gotoxyMaMonHoc(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyMaMonHoc(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 1: // noi dung cau hoi
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 559)
						{
							line[choice].insert(line[choice].begin() + 80 * e + viTri, kiTu);
							gotoxyCauHoi(0, 0);
							// e = line[choice].length() / 80;
							for (int i = 0; i < e + 1; i++)
							{
								gotoxyCauHoi(0, i);
								cout << line[1].substr(i * 80, 80);
							}
							if (viTri == 79)
							{
								e++;
								gotoxyCauHoi(0, e);
							}
							else
							{
								gotoxyCauHoi(viTri + 1, e);
							}
						}
						else
						{
							gotoxyCauHoi(viTri, e);
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							for (int i = 0; i < e + 1; i++)
							{
								gotoxyCauHoi(0, i);
								cout << line[1].substr(i * 80, 80);
							}
							gotoxyCauHoi(x, y);
						}
						break;
					}
					case 2:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyA(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyA(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyA(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 3:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyB(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyB(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyB(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 4:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyC(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyC(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyC(0);
							cout << line[choice];
							gotoxy(x, y);
						}

						break;
					}
					case 5:
					{
						if (viTri == 0 && kiTu == ' ')
						{
						}
						else if (line[choice].length() < 80)
						{
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyD(0);
							cout << line[choice];
							gotoxy(x + 1, y);
						}
						else
						{
							gotoxyD(line[choice].length());
							ThongBaoNhanh(x, y, "Full", 1, MAU_XAM);
							gotoxyD(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 6:
					{
						if ((kiTu >= 'a' && kiTu <= 'd') || (kiTu >= 'A' && kiTu <= 'D'))
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice] = kiTu;
							gotoxyDapAn(0);
							cout << line[choice];
						}
						else
						{
							gotoxyDapAn(0);
							ThongBaoNhanh(wherex(), wherey(), "Dap an chi nhan A, B, C, D", -1, MAU_DO);
							cout << line[choice];
						}
						break;
					}
					}
					HienConTro();
				}

				else if (kiTu == ESC)
				{
					return 0;
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
			ChuanDauInHoa(line[1]);
			ChuanDauInHoa(line[2]);
			ChuanDauInHoa(line[3]);
			ChuanDauInHoa(line[4]);
			ChuanDauInHoa(line[5]);
			LamTrangKhungThemCauHoiThi();
			e = line[1].length() / 80;
			for (int i = 0; i < e + 1; i++)
			{
				gotoxyCauHoi(0, i);
				cout << line[1].substr(i * 80, 80);
			}
			gotoxyA(0);
			cout << line[2];
			gotoxyB(0);
			cout << line[3];
			gotoxyC(0);
			cout << line[4];
			gotoxyD(0);
			cout << line[5];
			//kiem tra du lieu da nhap sau khi an enter
			AnConTro();
			if (line[0].length() == 0)
			{
				choice = 0;
				gotoxyMaMonHoc(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap ma mon hoc", -1, MAU_DO);
			}
			else if (line[1].length() == 0)
			{
				choice = 1;
				gotoxyCauHoi(0, 0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung cau hoi", -1, MAU_DO);
			}
			else if (line[2].length() == 0)
			{
				choice = 2;
				gotoxyA(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[3].length() == 0)
			{
				choice = 3;
				gotoxyB(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[4].length() == 0)
			{
				choice = 4;
				gotoxyC(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[5].length() == 0)
			{
				choice = 5;
				gotoxyD(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap noi dung dap an", -1, MAU_DO);
			}
			else if (line[6].length() == 0)
			{
				choice = 6;
				gotoxyDapAn(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap dap an dung", -1, MAU_DO);
			}
			else // Co day du noi dung
			{
				if (TimMonHocTheoMaMonHoc(dsmh, line[0]) == -1)
				{
					gotoxyMaMonHoc(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMaMonHoc(0);
					cout << line[0];
					choice = 0;
				}
				else
				{
					return 1;
				}
			}
		}
	}
}
bool ThemCauHoiThi(DanhSachCauHoiThi &dscht, DanhSachMonHoc dsmh, MangRandomID &mri) // nhập 1 câu hỏi thi
{
	KhungThemCauHoiThi(0);
	string nhapCauHoiThi[7] = {""};
	if (NhapNodeCauHoiThi(dsmh, nhapCauHoiThi))
	{
		AVLTree p = new NodeCauHoiThi;
		if (p == NULL)
		{
			return 0; //thiếu bộ nhớ
		}
		p->id = RandomID(mri);
		p->balFactor = EH;
		p->pLeft = p->pRight = NULL;
		p->maMonHoc = nhapCauHoiThi[0];
		p->noiDung = nhapCauHoiThi[1];
		p->a = nhapCauHoiThi[2];
		p->b = nhapCauHoiThi[3];
		p->c = nhapCauHoiThi[4];
		p->d = nhapCauHoiThi[5];
		p->dapAn = nhapCauHoiThi[6];
		InsertNodeCauHoiThi(dscht.TREE, p);
		delete p;
		return true;
	}
	return false;
}
void HieuChinhCauHoiThi(AVLTree &TREE, DanhSachMonHoc dsmh, DanhSachLop dsl)
{
	KhungHieuChinhCauHoiThi();
	string id = "";
	bool flag = true;
	while (flag)
	{
		char kiTu = 'NULL';
		bool phimKep = false;
		while (flag) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
			HienConTro();
			gotoxyID(id.length());
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
				if (kiTu == RIGHT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 61 + (int)id.length()), y);
				}
				else if (kiTu == LEFT && phimKep)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 61), y);
				}
				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 61;
					AnConTro();
					if (id.length() == 0)
					{
						ThongBaoNhanh(x, y, "      Empty      ", -1, MAU_XAM);
						gotoxyID(0);
					}
					else if (id.length() != 0 && viTri > 0)
					{
						id.erase(id.begin() + viTri - 1);
						gotoxyID(0);
						cout << id << " ";
						gotoxy(61 + viTri - 1, y);
					}
					HienConTro();
				}
				else if ((kiTu >= '0' && kiTu <= '9') && !phimKep) // kytu
				{
					int viTri = wherex() - 61;
					int x = wherex();
					int y = wherey();
					AnConTro();
					if (id.length() < 3)
					{
						id.insert(id.begin() + viTri, kiTu);
						gotoxyID(0);
						cout << id;
						gotoxy(viTri + 1 + 61, y);
					}
					else
					{
						gotoxyID(0);
						ThongBaoNhanh(wherex(), wherey(), "ID luon < 1000", -1, MAU_XAM);
						gotoxyID(0);
						cout << id;
						gotoxy(x, y);
					}
					HienConTro();
				}
				else if (kiTu == ESC)
				{
					return;
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
			AnConTro();
			if (id.length() == 0)
			{
				gotoxyID(0);
				cout << "Chua nhap ID";
				gotoxyID(0);
			}
			else
			{
				AVLTree p = TimCauHoiThiBangMaID(TREE, atoi(id.c_str()));
				if (p == NULL)
				{
					gotoxyID(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu", -1, MAU_DO);
					gotoxyID(0);
					cout << id;
				}
				else
				{
					if (TimCauHoiTheoIDTrongBaiLam(dsl, atoi(id.c_str())))
					{
						gotoxyID(0);
						ThongBaoNhanh(wherex(), wherey(), "Cau hoi da co nguoi thi", -1, MAU_DO);
						gotoxyID(0);
						cout << id;
					}
					else
					{
						flag = false;
					}
				}
			}
		}
	}
	NodeCauHoiThi *p = TimCauHoiThiBangMaID(TREE, atoi(id.c_str()));
	string line[7] = {""};
	line[0] = p->maMonHoc;
	line[1] = p->noiDung;
	line[2] = p->a;
	line[3] = p->b;
	line[4] = p->c;
	line[5] = p->d;
	line[6] = p->dapAn;
	KhungThemCauHoiThi(1);
	if (HieuChinhNodeCauHoiThi(dsmh, line))
	{
		p->maMonHoc = line[0];
		p->noiDung = line[1];
		p->a = line[2];
		p->b = line[3];
		p->c = line[4];
		p->d = line[5];
		p->dapAn = line[6];
	}
}
bool XoaCauHoiThi(AVLTree &TREE, DanhSachLop dsl)
{
	KhungHieuChinhCauHoiThi();
	string id = "";
	while (true)
	{
		char kiTu = 'NULL';
		bool phimKep = false;
		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
			HienConTro();
			gotoxyID(id.length());
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
				if (kiTu == RIGHT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 61 + (int)id.length()), y);
				}
				else if (kiTu == LEFT && phimKep)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 61), y);
				}
				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 61;
					AnConTro();
					if (id.length() == 0)
					{
						ThongBaoNhanh(x, y, "      Empty      ", -1, MAU_XAM);
						gotoxyID(0);
					}
					else if (id.length() != 0 && viTri > 0)
					{
						id.erase(id.begin() + viTri - 1);
						gotoxyID(0);
						cout << id << " ";
						gotoxy(61 + viTri - 1, y);
					}
					HienConTro();
				}
				else if ((kiTu >= '0' && kiTu <= '9') && !phimKep) // kytu
				{
					int viTri = wherex() - 61;
					int x = wherex();
					int y = wherey();
					AnConTro();
					if (id.length() < 3)
					{
						id.insert(id.begin() + viTri, kiTu);
						gotoxyID(0);
						cout << id;
						gotoxy(viTri + 1 + 61, y);
					}
					else
					{
						gotoxyID(0);
						ThongBaoNhanh(wherex(), wherey(), "ID luon < 1000", -1, MAU_XAM);
						gotoxyID(0);
						cout << id;
						gotoxy(x, y);
					}
					HienConTro();
				}
				else if (kiTu == ESC)
				{
					return false;
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
			AnConTro();
			if (id.length() == 0)
			{
				gotoxyID(0);
				cout << "Chua nhap ID";
				gotoxyID(0);
			}
			else
			{
				AVLTree p = TimCauHoiThiBangMaID(TREE, atoi(id.c_str()));
				if (p == NULL)
				{
					gotoxyID(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu", -1, MAU_DO);
					gotoxyID(0);
					cout << id;
				}
				else
				{
					if (TimCauHoiTheoIDTrongBaiLam(dsl, atoi(id.c_str())))
					{
						gotoxyID(0);
						ThongBaoNhanh(wherex(), wherey(), "Cau hoi da co nguoi thi", -1, MAU_DO);
						gotoxyID(0);
						cout << id;
					}
					else
					{
						XoaNodeCauHoiThi(TREE, atoi(id.c_str()));
						return true;
					}
				}
			}
		}
	}
}

// đếm số lượng câu hỏi trong danh sách câu hỏi thi
int SoLuongCauHoiThi(AVLTree TREE)
{
	if (TREE == NULL)
	{
		return 0;
	}
	else
	{
		return (SoLuongCauHoiThi(TREE->pLeft) + SoLuongCauHoiThi(TREE->pRight)) + 1; // +1 có ý nghĩa là mỗi lần trả về hàm gọi nó sẽ là 1 lần đếm.
	}
}
// đếm số lượng câu hỏi của 1 môn học
int SoLuongCauHoi1Mon(AVLTree TREE, string maMonHoc)
{
	if (TREE != NULL)
	{
		int a = SoLuongCauHoi1Mon(TREE->pLeft, maMonHoc);
		int b = SoLuongCauHoi1Mon(TREE->pRight, maMonHoc);
		if (TREE->maMonHoc == maMonHoc)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
void InCauHoiThiTheoMMH(AVLTree TREE, string maMonHoc) // in danh sách câu hỏi thi
{
	if (TREE != NULL)
	{
		InCauHoiThiTheoMMH(TREE->pLeft, maMonHoc);
		if (TREE->maMonHoc == maMonHoc)
		{
			cout << "\n\n\tID: " << TREE->id;
			cout << "\n\tMa mon Hoc: " << TREE->maMonHoc;
			cout << "\n\tCau hoi: " << TREE->noiDung;
			cout << "\n\tA: " << TREE->a;
			cout << "\n\tB: " << TREE->b;
			cout << "\n\tC: " << TREE->c;
			cout << "\n\tD: " << TREE->d;
			cout << "\n\tDap an: " << TREE->dapAn;
		}
		InCauHoiThiTheoMMH(TREE->pRight, maMonHoc);
	}
}
void InDanhSachCauHoiThi(AVLTree TREE, DanhSachMonHoc dsmh)
{
	HCN_VienDon(47, 6, 84, 8);
	outtextxy(46, 7, "Ma Mon Hoc:", 1);
	string maMonHoc = "";
	while (true)
	{
		char kiTu = 'NULL';
		bool phimKep = false;
		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
			HienConTro();
			gotoxy(49 + maMonHoc.length(), 7);
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
				if (kiTu == RIGHT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 49 + (int)maMonHoc.length()), y);
				}
				else if (kiTu == LEFT && phimKep)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 49), y);
				}
				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 49;
					AnConTro();
					if (maMonHoc.length() == 0)
					{
						ThongBaoNhanh(x, y, "      Empty      ", -1, MAU_XAM);
						gotoxy(49, 7);
					}
					else if (maMonHoc.length() != 0 && viTri > 0)
					{
						maMonHoc.erase(maMonHoc.begin() + viTri - 1);
						gotoxy(49, 7);
						cout << maMonHoc << " ";
						gotoxy(49 + viTri - 1, y);
					}
					HienConTro();
				}
				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z')) && !phimKep) // kytu
				{
					int viTri = wherex() - 49;
					int x = wherex();
					int y = wherey();
					AnConTro();
					if (maMonHoc.length() < 15)
					{
						if (kiTu >= 'a' && kiTu <= 'z')
							kiTu -= 32;
						maMonHoc.insert(maMonHoc.begin() + viTri, kiTu);
						gotoxy(49, 7);
						cout << maMonHoc;
						gotoxy(viTri + 1 + 49, y);
					}
					else
					{
						gotoxy(49 + 15, 7);
						ThongBaoNhanh(wherex(), wherey(), "Full", 1, MAU_XAM);
						gotoxy(49, 7);
						cout << maMonHoc;
						gotoxy(x, y);
					}
					HienConTro();
				}
				else if (kiTu == ESC)
				{
					return;
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
			AnConTro();
			if (maMonHoc.length() == 0)
			{
				gotoxy(49, 7);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap ma mon hoc", -1, MAU_DO);
				gotoxy(49, 7);
			}
			else
			{
				int vt = TimMonHocTheoMaMonHoc(dsmh, maMonHoc);
				if (vt == -1)
				{
					gotoxy(49, 7);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu", -1, MAU_DO);
					gotoxy(49, 7);
					cout << maMonHoc;
				}
				else
				{
					NenTrang();
					Normal();
					InCauHoiThiTheoMMH(TREE, maMonHoc);
					gotoxy(0, 0);
					while (true)
					{
						char k = getch();
						if (k == ESC)
						{
							return;
						}
					}
				}
			}
		}
	}
}

void InLichSuThi(DanhSachLop dsl, DanhSachMonHoc dsmh, AVLTree TREE)
{
	KhungNhapBaiLam();
	string line[2];
	NodeSinhVien *p;
	bool flag = true;
	while (flag)
	{
		line[0] = "";
		line[1] = "";
		char kiTu = 'NULL';
		bool phimKep = false;
		int choice = 0;

		while (flag) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{

			switch (choice)
			{
			case 0:
			{
				gotoxyMSSV_BL(line[choice].length());
				break;
			}
			case 1:
			{
				gotoxyMMH_BL(line[choice].length());
				break;
			}
			}
			HienConTro();

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
				if ((kiTu == DOWN && phimKep) || (kiTu == TAB && !phimKep))
				{
					if (choice == 0)
					{
						choice++;
						gotoxyMMH_BL(line[choice].length());
					}
					else if (choice == 1)
					{
						choice = 0;
						gotoxyMSSV_BL(line[choice].length());
					}
				}

				else if (kiTu == UP && phimKep)
				{
					if (choice == 0)
					{
						choice = 1;
						gotoxyMMH_BL(line[choice].length());
					}
					else if (choice == 1)
					{
						choice--;
						gotoxyMSSV_BL(line[choice].length());
					}
				}

				else if (kiTu == RIGHT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 49 + (int)line[choice].length()), y);
				}

				else if (kiTu == LEFT && phimKep)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 49), y);
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 49;
					if (viTri >= 0)
					{
						switch (choice)
						{
						case 0:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyMSSV_BL(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMSSV_BL(0);
								cout << line[choice] << " ";
								gotoxy(49 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 1:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "           Empty             ", -1, MAU_XAM);
								gotoxyMMH_BL(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMMH_BL(0);
								cout << line[choice] << " ";
								gotoxy(49 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						}
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && !phimKep) // kytu
				{
					int viTri = wherex() - 49;
					int x = wherex();
					int y = wherey();
					AnConTro();
					switch (choice)
					{
					case 0:
					{
						if (line[choice].length() < 17)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyMSSV_BL(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 49, y);
						}
						else
						{
							gotoxyMSSV_BL(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMSSV_BL(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 1:
					{
						if (line[choice].length() < 17)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyMMH_BL(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 49, y);
						}
						else
						{
							gotoxyMMH_BL(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMMH_BL(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					}
					HienConTro();
				}

				else if (kiTu == ESC)
				{
					return;
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
			AnConTro();
			if (line[0].length() == 0)
			{
				choice = 0;
			}
			else if (line[1].length() == 0)
			{
				choice = 1;
			}
			else
			{
				bool checkMSSV = false;
				for (int i = 0; i < dsl.sl; i++)
				{
					p = TimSinhVienBangMaSinhVien(dsl.ds[i].dssv, line[0]);
					if (p != NULL)
					{
						checkMSSV = true;
						break;
					}
				}
				if (checkMSSV == false)
				{
					gotoxyMSSV_BL(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMSSV_BL(0);
					cout << line[0];
					choice = 0;
				}
				else if (TimMonHocTheoMaMonHoc(dsmh, line[1]) == -1)
				{
					gotoxyMMH_BL(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMMH_BL(0);
					cout << line[1];
					choice = 1;
				}
				else
				{
					NodeDiemThi *q = TimDiemThiBangMaMonHoc(p->data.dsdt, line[1]);
					if (q != NULL && q->data.bl->soLuongCauHoiYeuCau == 0)
					{
						gotoxyMMH_BL(0);
						ThongBaoNhanh(wherex(), wherey(), "Khong co bai lam, diem do GV them", -1, MAU_DO);
						gotoxyMMH_BL(0);
						cout << line[1];
						choice = 1;
					}
					else if (q != NULL && q->data.bl->soLuongCauHoiYeuCau != 0)
					{
						flag = false;
					}
					else
					{
						gotoxyMMH_BL(0);
						ThongBaoNhanh(wherex(), wherey(), "Khong ton tai diem thi", -1, MAU_DO);
						gotoxyMMH_BL(0);
						cout << line[1];
						choice = 1;
					}
				}
			}
		}
	}
	NenTrang();
	KhungThongTinBaiLam();
	NodeDiemThi *q = TimDiemThiBangMaMonHoc(p->data.dsdt, line[1]);
	gotoxy(119, 4);
	cout << p->data.ho << " " << p->data.ten;
	gotoxy(119, 7);
	cout << q->data.bl->thoiGianYeuCau << "m";
	gotoxy(119, 10);
	cout << q->data.bl->thoiGianHoanThanh / 60 << "m" << q->data.bl->thoiGianHoanThanh % 60 << "s";
	gotoxy(119, 13);
	cout << q->data.bl->soLuongCauHoiYeuCau;
	gotoxy(119, 16);
	cout << q->data.bl->soLuongCauTraLoiDung;
	outtextxy2(46, 18, " BAI LAM ", 0, MAU_TRANG, 3);

	for (int j = 0; j < q->data.bl->soLuongCauHoiYeuCau; j++)
	{
		// gotoxy(82, 20);
		AVLTree T = TimCauHoiThiBangMaID(TREE, q->data.bl->mangCauHoi[j]->id);
		cout << "\n\n\tID: " << T->id;
		cout << "\n\tMa mon Hoc: " << T->maMonHoc;
		cout << "\n\tCau hoi: " << T->noiDung;
		cout << "\n\tA: " << T->a;
		cout << "\n\tB: " << T->b;
		cout << "\n\tC: " << T->c;
		cout << "\n\tD: " << T->d;
		cout << "\n\tDap an: " << T->dapAn;
		cout << "\n\tTra loi: " << q->data.bl->mangCauHoi[j]->traLoi;
	}
	gotoxy(0, 0);
	while (true)
	{
		char kiTu = getch();
		if (kiTu == ESC)
		{
			return;
		}
	}
}

//========= MANG ID ======================
void KhoiTaoMangID(MangID &mi, int soLuong)
{
	mi.soLuong = 0;
	mi.mangID = new int[soLuong];
}
void HuyMangID(MangID &mi)
{
	delete[] mi.mangID;
}
/* đưa id câu hỏi thi của 1 môn vào mảng id và random câu hỏi thi trên mảng id để thi trắc nghiệm */
void ThemVaoMangID(MangID &mi, AVLTree TREE, string maMonHoc)
{
	if (TREE != NULL)
	{
		if (TREE->maMonHoc == maMonHoc)
		{
			mi.mangID[mi.soLuong] = TREE->id;
			mi.soLuong++;
		}
		ThemVaoMangID(mi, TREE->pLeft, maMonHoc);
		ThemVaoMangID(mi, TREE->pRight, maMonHoc);
	}
}
void TaoCauHoiNgauNhien(MangID &mi, AVLTree TREE, int soLuongCauHoiYeuCau)
{
	srand(time(NULL));
	int chiSoRandom;
	int chiSoCuoi = mi.soLuong - 1;
	for (int i = 0; i < soLuongCauHoiYeuCau; i++)
	{
		chiSoRandom = rand() % (chiSoCuoi - 0 + 1) + 0;
		SwapID(mi.mangID[chiSoRandom], mi.mangID[chiSoCuoi]);
		chiSoCuoi--;
	}
}
void TaoMangCauHoi(MangID mi, AVLTree TREE, BaiLam *bl)
{
	for (int i = 0; i < bl->soLuongCauHoiYeuCau; i++)
	{
		bl->mangCauHoi[i]->id = mi.mangID[mi.soLuong - 1 - i];
		bl->mangCauHoi[i]->traLoi = "";
	}
}
void ChamDiem(DiemThi &dt, AVLTree TREE)
{
	for (int i = 0; i < dt.bl->soLuongCauHoiYeuCau; i++)
	{
		AVLTree T = TimCauHoiThiBangMaID(TREE, dt.bl->mangCauHoi[i]->id);
		if (T->dapAn == dt.bl->mangCauHoi[i]->traLoi)
		{
			dt.bl->soLuongCauTraLoiDung++;
		}
	}
	dt.diem = roundf(((float)10 / dt.bl->soLuongCauHoiYeuCau) * (dt.bl->soLuongCauTraLoiDung) * 100) / 100;
}
void DeThi(DiemThi &dt, AVLTree TREE)
{
	int stt = 0;
	bool flag = false; /* dựa vào flag xác định nộp bài do yêu cầu hay do hết giờ */
	bool check = false;
	thread dongHo;
	runDongHo = true;
	dongHo = thread(DongHoDemNguoc, dt.bl->thoiGianYeuCau);
	clock_t endTime = clock() + dt.bl->thoiGianYeuCau * 60 * CLOCKS_PER_SEC;
	clock_t startTime = clock();
	// AnConTro();
	KhungThi(dt.bl->soLuongCauHoiYeuCau);

	while (clock() < endTime)
	{
		ToMauKhungDapAn(dt.bl->mangCauHoi[stt]->traLoi);
		AVLTree T = TimCauHoiThiBangMaID(TREE, dt.bl->mangCauHoi[stt]->id);
		DienNoiDungThi(stt + 1, T->id, T->noiDung, T->a, T->b, T->c, T->d);
		string yeuCau = "";
		NhapDapAn(dt.bl->mangCauHoi[stt]->traLoi, yeuCau, endTime);
		if ((endTime - clock()) / CLOCKS_PER_SEC < 30)
		{
			outtextxy1(61, 16, "Sap Het Thoi Gian", 0, rand() % (15 - 0 + 1) + 0);
		}
		if (yeuCau == "RIGHT" && stt + 1 < dt.bl->soLuongCauHoiYeuCau)
		{
			XoaHienThi1CauHoi();
			stt++;
		}
		else if (yeuCau == "LEFT" && stt > 0)
		{
			XoaHienThi1CauHoi();
			stt--;
		}
		else if (yeuCau == "JUMP")
		{
			int i = 0;
			for (i; i < dt.bl->soLuongCauHoiYeuCau; i++)
			{
				if (dt.bl->mangCauHoi[i]->traLoi == "")
				{
					if (i == stt)
					{
						break;
					}
					else
					{
						XoaHienThi1CauHoi();
						stt = i;
						break;
					}
				}
			}
			if (i == dt.bl->soLuongCauHoiYeuCau)
			{
				ThongBaoLau(61, 16, "Ban Da Nhap Day Du Dap An Roi!", 0);
			}
		}
		else if (yeuCau == "DONE")
		{
			flag = true;
			break;
		}
		else if (yeuCau == "HET GIO")
		{
			break;
		}
	}
	if (flag == true) /* nộp bài do yêu cầu */
	{
		runDongHo = false;
		dongHo.join();
		KhungThongBaoDaNopBai(true);
		dt.bl->thoiGianHoanThanh = 1 + (clock() - startTime) / CLOCKS_PER_SEC;
	}
	else /* nộp bài do hết giờ */
	{
		runDongHo = false;
		dongHo.join();
		KhungThongBaoDaNopBai(false);
		dt.bl->thoiGianHoanThanh = dt.bl->thoiGianYeuCau * 60;
	}

	ChamDiem(dt, TREE);
}
void ThiTracNghiem(AVLTree TREE, NodeSinhVien *p, DanhSachMonHoc dsmh, string line[])
{
	int soLuongCauHoiYeuCau = atoi(line[1].c_str());
	int soLuongCauHoi1Mon = SoLuongCauHoi1Mon(TREE, line[0]);
	int thoiGianYeuCau = atoi(line[2].c_str());
	MangID mi;
	KhoiTaoMangID(mi, soLuongCauHoi1Mon);
	ThemVaoMangID(mi, TREE, line[0]);
	TaoCauHoiNgauNhien(mi, TREE, soLuongCauHoiYeuCau);
	// thêm 1 điểm thi
	DiemThi dt;
	dt.maMonHoc = line[0];
	dt.diem = 0;
	dt.bl = new BaiLam;
	ThemDiemThiVaoCuoi(p->data.dsdt, TaoNodeDiemThi(dt));
	p->data.dsdt->pTail->data.bl->thoiGianYeuCau = thoiGianYeuCau;
	p->data.dsdt->pTail->data.bl->soLuongCauHoiYeuCau = soLuongCauHoiYeuCau;
	KhoiTaoMangCauHoi(p->data.dsdt->pTail->data.bl);
	TaoMangCauHoi(mi, TREE, p->data.dsdt->pTail->data.bl);
	HuyMangID(mi);
	XoaManHinh();
	KhungThongTinNguoiThi(p->data.maSinhVien, p->data.ho, p->data.ten, p->data.phai, dsmh.mangMonHoc[TimMonHocTheoMaMonHoc(dsmh, line[0])]->tenMonHoc);
	KhungHuongDanLamBai();
	DeThi(p->data.dsdt->pTail->data, TREE);
	NenTrang();
	KhungMenuSv();
}
void ThiTracNghiemGV(AVLTree TREE, DanhSachMonHoc dsmh, string line[])
{
	int soLuongCauHoiYeuCau = atoi(line[1].c_str());
	int soLuongCauHoi1Mon = SoLuongCauHoi1Mon(TREE, line[0]);
	int thoiGianYeuCau = atoi(line[2].c_str());
	MangID mi;
	KhoiTaoMangID(mi, soLuongCauHoi1Mon);
	ThemVaoMangID(mi, TREE, line[0]);
	TaoCauHoiNgauNhien(mi, TREE, soLuongCauHoiYeuCau);
	// thêm 1 điểm thi
	DiemThi dt;
	dt.maMonHoc = line[0];
	dt.diem = 0;
	dt.bl = new BaiLam;
	dt.bl->thoiGianYeuCau = thoiGianYeuCau;
	dt.bl->soLuongCauHoiYeuCau = soLuongCauHoiYeuCau;
	KhoiTaoMangCauHoi(dt.bl);
	TaoMangCauHoi(mi, TREE, dt.bl);
	HuyMangID(mi);
	XoaManHinh();
	KhungThongTinNguoiThi("Test", "Test", "", "Test", dsmh.mangMonHoc[TimMonHocTheoMaMonHoc(dsmh, line[0])]->tenMonHoc);
	KhungHuongDanLamBai();
	DeThi(dt, TREE);
	NenTrang();
	KhungBaoDiemThi(dt.diem, dt.bl->soLuongCauHoiYeuCau, dt.bl->soLuongCauTraLoiDung);
	delete dt.bl;
	NenTrang();
}
int NhapHinhThucThi(AVLTree TREE, DanhSachMonHoc dsmh, NodeSinhVien *p, string line[])
{
	while (true)
	{
		line[0] = "";
		line[1] = "";
		line[2] = "";
		char kiTu = 'NULL';
		bool phimKep = false;
		int choice = 0;

		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{

			switch (choice)
			{
			case 0:
			{
				gotoxyHinhThucThi0(line[choice].length());
				break;
			}
			case 1:
			{
				gotoxyHinhThucThi1(line[choice].length());
				break;
			}
			case 2:
			{
				gotoxyHinhThucThi2(line[choice].length());
				break;
			}
			}
			HienConTro();

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
				if ((kiTu == DOWN && phimKep) || (kiTu == TAB && !phimKep))
				{
					if (choice == 0)
					{
						choice++;
						gotoxyHinhThucThi1(line[choice].length());
					}
					else if (choice == 1)
					{
						choice++;
						gotoxyHinhThucThi2(line[choice].length());
					}
					else if (choice == 2)
					{
						choice = 0;
						gotoxyHinhThucThi0(line[choice].length());
					}
				}

				else if (kiTu == UP && phimKep)
				{
					if (choice == 0)
					{
						choice = 2;
						gotoxyHinhThucThi2(line[choice].length());
					}
					else if (choice == 1)
					{
						choice--;
						gotoxyHinhThucThi0(line[choice].length());
					}
					else if (choice == 2)
					{
						choice--;
						gotoxyHinhThucThi1(line[choice].length());
					}
				}

				else if (kiTu == RIGHT && phimKep && choice == 0)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 96 + (int)line[choice].length()), y);
				}

				else if (kiTu == LEFT && phimKep && choice == 0)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 96), y);
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 96;
					if (viTri >= 0)
					{
						switch (choice)
						{
						case 0:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyHinhThucThi0(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyHinhThucThi0(0);
								cout << line[choice] << " ";
								gotoxy(96 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 1:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyHinhThucThi1(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyHinhThucThi1(0);
								cout << line[choice] << " ";
								gotoxy(96 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 2:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyHinhThucThi2(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyHinhThucThi2(0);
								cout << line[choice] << " ";
								gotoxy(96 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						default:
							break;
						}
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && !phimKep) // kytu
				{
					int viTri = wherex() - 96;
					int x = wherex();
					int y = wherey();
					AnConTro();
					switch (choice)
					{
					case 0:
					{
						if (line[choice].length() < 17)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyHinhThucThi0(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 96, y);
						}
						else
						{
							gotoxyHinhThucThi0(0);
							ThongBaoNhanh(wherex(), wherey(), "      Full       ", -1, MAU_XAM);
							gotoxyHinhThucThi0(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 1:
					{
						if ((kiTu >= '0' && kiTu <= '9') && !phimKep)
						{
							if (viTri == 0 && kiTu == '0')
							{
							}
							else
							{
								if (line[choice].length() < 3)
								{
									line[choice].insert(line[choice].begin() + viTri, kiTu);
									gotoxyHinhThucThi1(0);
									cout << line[choice];
									gotoxy(viTri + 1 + 96, y);
								}
								else
								{
									gotoxyHinhThucThi1(0);
									ThongBaoNhanh(wherex(), wherey(), "< 1.000 cau hoi", -1, MAU_DO);
									gotoxyHinhThucThi1(0);
									cout << line[choice];
									gotoxy(x, y);
								}
							}
						}
						break;
					}
					case 2:
					{
						if ((kiTu >= '0' && kiTu <= '9') && !phimKep)
						{
							if (viTri == 0 && kiTu == '0')
							{
							}
							else
							{
								if (line[choice].length() < 3)
								{
									line[choice].insert(line[choice].begin() + viTri, kiTu);
									gotoxyHinhThucThi2(0);
									cout << line[choice];
									gotoxy(viTri + 1 + 96, y);
								}
								else
								{
									gotoxyHinhThucThi2(0);
									ThongBaoNhanh(wherex(), wherey(), "< 1.000 phut", -1, MAU_DO);
									gotoxyHinhThucThi2(0);
									cout << line[choice];
									gotoxy(x, y);
								}
							}
						}
						break;
					}
					}
					HienConTro();
				}

				else if (kiTu == ESC)
				{
					return -1;
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
			AnConTro();
			if (line[0].length() == 0)
			{
				choice = 0;
			}
			else if (line[1].length() == 0)
			{
				choice = 1;
			}
			else if (line[2].length() == 0)
			{
				choice = 2;
			}
			else // Co user va pass
			{
				if (TimMonHocTheoMaMonHoc(dsmh, line[0]) == -1)
				{
					gotoxyHinhThucThi0(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyHinhThucThi0(0);
					cout << line[0];
					choice = 0;
				}
				else if (atoi(line[1].c_str()) > SoLuongCauHoi1Mon(TREE, line[0]))
				{
					int n = SoLuongCauHoi1Mon(TREE, line[0]);
					//in ra
					{
						gotoxyHinhThucThi1(0);
						SetColor(MAU_DO);
						cout << "Chi co " << n << " cau hoi";
						Sleep(400);
						gotoxyHinhThucThi1(0);
						SetBGColor(MAU_TRANG);
						cout << "                 ";
						SetColor(MAU_DEN);
					}
					gotoxyHinhThucThi1(0);
					cout << line[1];
					choice = 1;
				}
				else if (TimDiemThiBangMaMonHoc(p->data.dsdt, line[0]) != NULL)
				{
					return 0;
				}
				else
					return 1;
			}
		}
	}
}
int NhapHinhThucThiGV(AVLTree TREE, DanhSachMonHoc dsmh, string line[])
{
	while (true)
	{
		line[0] = "";
		line[1] = "";
		line[2] = "";
		char kiTu = 'NULL';
		bool phimKep = false;
		int choice = 0;

		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{

			switch (choice)
			{
			case 0:
			{
				gotoxyHinhThucThi0(line[choice].length());
				break;
			}
			case 1:
			{
				gotoxyHinhThucThi1(line[choice].length());
				break;
			}
			case 2:
			{
				gotoxyHinhThucThi2(line[choice].length());
				break;
			}
			}
			HienConTro();

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
				if ((kiTu == DOWN && phimKep) || (kiTu == TAB && !phimKep))
				{
					if (choice == 0)
					{
						choice++;
						gotoxyHinhThucThi1(line[choice].length());
					}
					else if (choice == 1)
					{
						choice++;
						gotoxyHinhThucThi2(line[choice].length());
					}
					else if (choice == 2)
					{
						choice = 0;
						gotoxyHinhThucThi0(line[choice].length());
					}
				}

				else if (kiTu == UP && phimKep)
				{
					if (choice == 0)
					{
						choice = 2;
						gotoxyHinhThucThi2(line[choice].length());
					}
					else if (choice == 1)
					{
						choice--;
						gotoxyHinhThucThi0(line[choice].length());
					}
					else if (choice == 2)
					{
						choice--;
						gotoxyHinhThucThi1(line[choice].length());
					}
				}

				else if (kiTu == RIGHT && phimKep && choice == 0)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 96 + (int)line[choice].length()), y);
				}

				else if (kiTu == LEFT && phimKep && choice == 0)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 96), y);
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 96;
					if (viTri >= 0)
					{
						switch (choice)
						{
						case 0:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyHinhThucThi0(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyHinhThucThi0(0);
								cout << line[choice] << " ";
								gotoxy(96 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 1:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyHinhThucThi1(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyHinhThucThi1(0);
								cout << line[choice] << " ";
								gotoxy(96 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 2:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "      Empty      ", -1, MAU_XAM);
								gotoxyHinhThucThi2(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyHinhThucThi2(0);
								cout << line[choice] << " ";
								gotoxy(96 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						default:
							break;
						}
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && !phimKep) // kytu
				{
					int viTri = wherex() - 96;
					int x = wherex();
					int y = wherey();
					AnConTro();
					switch (choice)
					{
					case 0:
					{
						if (line[choice].length() < 17)
						{
							if (kiTu >= 'a' && kiTu <= 'z')
								kiTu -= 32;
							line[choice].insert(line[choice].begin() + viTri, kiTu);
							gotoxyHinhThucThi0(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 96, y);
						}
						else
						{
							gotoxyHinhThucThi0(0);
							ThongBaoNhanh(wherex(), wherey(), "      Full       ", -1, MAU_XAM);
							gotoxyHinhThucThi0(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 1:
					{
						if ((kiTu >= '0' && kiTu <= '9') && !phimKep)
						{
							if (viTri == 0 && kiTu == '0')
							{
							}
							else
							{
								if (line[choice].length() < 3)
								{
									line[choice].insert(line[choice].begin() + viTri, kiTu);
									gotoxyHinhThucThi1(0);
									cout << line[choice];
									gotoxy(viTri + 1 + 96, y);
								}
								else
								{
									gotoxyHinhThucThi1(0);
									ThongBaoNhanh(wherex(), wherey(), "< 1.000 cau hoi", -1, MAU_DO);
									gotoxyHinhThucThi1(0);
									cout << line[choice];
									gotoxy(x, y);
								}
							}
						}
						break;
					}
					case 2:
					{
						if ((kiTu >= '0' && kiTu <= '9') && !phimKep)
						{
							if (viTri == 0 && kiTu == '0')
							{
							}
							else
							{
								if (line[choice].length() < 3)
								{
									line[choice].insert(line[choice].begin() + viTri, kiTu);
									gotoxyHinhThucThi2(0);
									cout << line[choice];
									gotoxy(viTri + 1 + 96, y);
								}
								else
								{
									gotoxyHinhThucThi2(0);
									ThongBaoNhanh(wherex(), wherey(), "< 1.000 phut", -1, MAU_DO);
									gotoxyHinhThucThi2(0);
									cout << line[choice];
									gotoxy(x, y);
								}
							}
						}
						break;
					}
					}
					HienConTro();
				}

				else if (kiTu == ESC)
				{
					return -1;
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
			AnConTro();
			if (line[0].length() == 0)
			{
				choice = 0;
			}
			else if (line[1].length() == 0)
			{
				choice = 1;
			}
			else if (line[2].length() == 0)
			{
				choice = 2;
			}
			else // Co user va pass
			{
				if (TimMonHocTheoMaMonHoc(dsmh, line[0]) == -1)
				{
					gotoxyHinhThucThi0(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyHinhThucThi0(0);
					cout << line[0];
					choice = 0;
				}
				else if (atoi(line[1].c_str()) > SoLuongCauHoi1Mon(TREE, line[0]))
				{
					int n = SoLuongCauHoi1Mon(TREE, line[0]);
					//in ra
					{
						gotoxyHinhThucThi1(0);
						SetColor(MAU_DO);
						cout << "Chi co " << n << " cau hoi";
						Sleep(400);
						gotoxyHinhThucThi1(0);
						SetBGColor(MAU_TRANG);
						cout << "                 ";
						SetColor(MAU_DEN);
					}
					gotoxyHinhThucThi1(0);
					cout << line[1];
					choice = 1;
				}
				else
					return 1;
			}
		}
	}
}

/*_____________________________________ [Đọc - Lưu file Danh Sách Câu Hỏi Thi] _____________________________________*/
void DocDuLieuCauHoiThi(DanhSachCauHoiThi &dscht)
{
	ifstream fileIn;
	fileIn.open("Data\\DanhSachCauHoiThi.txt", ios::in);
	while (fileIn.eof() != true)
	{
		string id;
		AVLTree p = new NodeCauHoiThi;
		if (p == NULL)
		{
			return;
		}
		p->balFactor = EH;
		p->pLeft = p->pRight = NULL;
		getline(fileIn, id, '|');
		p->id = atoi(id.c_str());
		getline(fileIn, p->maMonHoc, '|');
		getline(fileIn, p->noiDung, '|');
		getline(fileIn, p->a, '|');
		getline(fileIn, p->b, '|');
		getline(fileIn, p->c, '|');
		getline(fileIn, p->d, '|');
		getline(fileIn, p->dapAn, '\n');
		InsertNodeCauHoiThi(dscht.TREE, p);
	}
}
void LuuDuLieu1CauHoiThi(AVLTree p, AVLTree q)
{
	if (q != NULL)
	{
		LuuDuLieu1CauHoiThi(p, q->pLeft);
		if (q != p)
		{
			ofstream fileOut;
			fileOut.open("Data\\DanhSachCauHoiThi.txt", ios::app);
			fileOut << q->id << '|';
			fileOut << q->maMonHoc << '|';
			fileOut << q->noiDung << '|';
			fileOut << q->a << '|';
			fileOut << q->b << '|';
			fileOut << q->c << '|';
			fileOut << q->d << '|';
			fileOut << q->dapAn << endl;
			fileOut.close();
		}
		LuuDuLieu1CauHoiThi(p, q->pRight);
	}
}
void LuuDuLieuCauHoiThi(DanhSachCauHoiThi dscht)
{
	AVLTree p = TimPhanTuPhaiCung(dscht.TREE);
	ofstream fileOut;
	fileOut.open("Data\\DanhSachCauHoiThi.txt", ios::trunc);
	fileOut.close();
	LuuDuLieu1CauHoiThi(p, dscht.TREE);
	ofstream fileOut1;
	fileOut1.open("Data\\DanhSachCauHoiThi.txt", ios::app);
	fileOut1 << p->id << '|';
	fileOut1 << p->maMonHoc << '|';
	fileOut1 << p->noiDung << '|';
	fileOut1 << p->a << '|';
	fileOut1 << p->b << '|';
	fileOut1 << p->c << '|';
	fileOut1 << p->d << '|';
	fileOut1 << p->dapAn;
	fileOut1.close();
}

//=======================tiennhot23================================
void XoaMonHocTheoMaMonHoc(DanhSachMonHoc &dsmh, AVLTree TREE)
{
	while (1)
	{
		khungxoaMH("XOA MON HOC");
		int choice = 0;
		MonHoc *p = new MonHoc;
	loop:
		HienConTro();
		gotoxy(80, posY[choice]);
		nhapma(nhap, choice, posY, 0, 0, 15);
		if (choice == -1)
			choice = 0;
		else if (choice == 1)
			choice = 0;
		else if (choice == -2)
		{
			reset();
			HCN_NenTrang(65, 17, 132, 27);
			break;
		}
		if (choice >= 0)
			goto loop;
		else
			goto loop_end;
	loop_end:
		int vt = TimMonHocTheoMaMonHoc(dsmh, nhap[0]);
		if (vt == -1)
		{
			choice = 0;
			ThongBaoLau(80, posY[choice], "Khong tim thay ma mon hoc", -1);
			goto loop;
		}
		else
		{
			bool check = true;
			if (SoLuongCauHoi1Mon(TREE, nhap[0]) > 0)
			{
				outtextxy(98, 25, "Luu y: Mon hoc nay da co cau hoi thi. Ban muon xoa?(Y/N)", 0);
				while (1)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 'y' || c == 'Y')
							break;
						else if (c == 'n' || c == 'N')
						{
							check = false;
							break;
						}
					}
				}
			}
			outtextxy(98, 25, "                                                         ", 0);
			if (check)
			{
				for (int i = vt; i < dsmh.sl - 1; i++)
				{
					dsmh.mangMonHoc[i]->maMonHoc = dsmh.mangMonHoc[i + 1]->maMonHoc;
					dsmh.mangMonHoc[i]->tenMonHoc = dsmh.mangMonHoc[i + 1]->tenMonHoc;
				}
				MonHoc *temp = dsmh.mangMonHoc[dsmh.sl - 1];
				delete temp;
				dsmh.sl--;
				ThongBaoLau(80, 25, "Da xoa thanh cong", -1);
			}
			reset();
		}
		HCN_NenTrang(65, 17, 132, 27);
	}
	AnConTro();
}
void HieuChinhMonHoc(DanhSachMonHoc &dsmh, AVLTree TREE)
{
	while (1)
	{
		khungxoaMH("HIEU CHINH MON HOC");
		int choice = 0;
	loop_tmp:
		HienConTro();
		gotoxy(80, posY[choice]);
		nhapma(nhap, choice, posY, 0, 0, 15);
		if (choice == -1)
			choice = 0;
		else if (choice == 1)
			choice = 0;
		else if (choice == -2)
		{
			reset();
			HCN_NenTrang(65, 17, 132, 27);
			break;
		}
		if (choice >= 0)
			goto loop_tmp;
		else
			goto loop_end;
	loop_end:
		int vt = TimMonHocTheoMaMonHoc(dsmh, nhap[0]);
		if (vt == -1)
		{
			choice = 0;
			ThongBaoLau(80, posY[choice], "Khong tim thay ma mon hoc", -1);
			goto loop_tmp;
		}
		else
		{
			bool check = true;
			if (SoLuongCauHoi1Mon(TREE, nhap[0]) > 0)
			{
				outtextxy(98, 25, "Luu y: Mon hoc nay da co cau hoi thi. Ban muon xoa?(Y/N)", 0);
				while (1)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 'y' || c == 'Y')
							break;
						else if (c == 'n' || c == 'N')
						{
							check = false;
							break;
						}
					}
				}
			}
			outtextxy(98, 25, "                                                         ", 0);
			if (check)
			{
				HieuChinhMHTrongDSMH(dsmh, nhap, vt);
			}
		}
	}
	AnConTro();
}
void HieuChinhMHTrongDSMH(DanhSachMonHoc &dsmh, string nhap[], int vt)
{
	nhap[0] = dsmh.mangMonHoc[vt]->maMonHoc;
	nhap[1] = dsmh.mangMonHoc[vt]->tenMonHoc;
	HCN_NenTrang(65, 17, 132, 24);
	khungthemMH("HIEU CHINH MON HOC");
	for (int i = 0; i < 2; i++)
	{
		gotoxy(80, posY[i]);
		cout << nhap[i];
	}
	int choice = 0;
loop:
	HienConTro();
	gotoxy(80, posY[choice]);
	nhapma(nhap, choice, posY, 0, 1, 15);
	if (choice == -1)
		choice = 1;
	else if (choice == 2)
		choice = 0;
	else if (choice == -2)
	{
		reset();
		HCN_NenTrang(65, 17, 132, 27);
		return;
	}
	if (choice == -3)
		goto loop_end;
	gotoxy(80 + nhap[choice].length(), posY[choice]);
	nhapten(nhap, choice, posY, 0, 1, 50);
	if (choice == -1)
		choice = 1;
	else if (choice == 2)
		choice = 0;
	if (choice == -2)
	{
		reset();
		HCN_NenTrang(65, 17, 132, 27);
		return;
	}
	if (choice >= 0)
		goto loop;
	else
		goto loop_end;
loop_end:
	int vttmp = TimMonHocTheoMaMonHoc(dsmh, nhap[0]);
	if (vttmp != -1 && dsmh.mangMonHoc[vt]->maMonHoc != nhap[0])
	{
		choice = 0;
		ThongBaoLau(80, posY[choice], "Ma mon hoc da co roi", -1);
		goto loop;
	}
	dsmh.mangMonHoc[vt]->maMonHoc = nhap[0];
	dsmh.mangMonHoc[vt]->tenMonHoc = nhap[1];
	ChuanHoaChu(dsmh.mangMonHoc[vt]->tenMonHoc);
	ThongBaoLau(98, 28, "Da thay doi thong tin mon hoc", 0);
	reset();
	HCN_NenTrang(65, 17, 132, 27);
}
