#pragma once
#include "LIB_linh_tinh.h"
//#include "LIB_cau_hoi_thi.h"
#include <vector>
#include <string>
/*_____________________________________ [Danh Sách Môn Học] _____________________________________*/
typedef struct MonHoc
{
	string maMonHoc;
	string tenMonHoc;
};
typedef struct DanhSachMonHoc
{
	MonHoc *mangMonHoc[100];
	int sl = 0;
};


/*_____________________________________ [Đọc - Lưu file Danh Sách Môn Học] _____________________________________*/
void DocDuLieuMonHoc(DanhSachMonHoc &dsmh)
{
	ifstream fileIn;
	fileIn.open("Data\\DanhSachMonHoc.txt", ios::in);
	while (fileIn.eof() != true)
	{
		dsmh.mangMonHoc[dsmh.sl] = new MonHoc;
		getline(fileIn, dsmh.mangMonHoc[dsmh.sl]->maMonHoc, '|');
		getline(fileIn, dsmh.mangMonHoc[dsmh.sl]->tenMonHoc, '\n');
		dsmh.sl++;
	}
	fileIn.close();
}
void LuuDuLieuMonHoc(DanhSachMonHoc dsmh)
{
	ofstream fileOut;
	fileOut.open("Data\\DanhSachMonHoc.txt", ios::out);
	for (int i = 0; i < dsmh.sl; i++)
	{
		fileOut << dsmh.mangMonHoc[i]->maMonHoc << '|';
		fileOut << dsmh.mangMonHoc[i]->tenMonHoc;
		if (i < dsmh.sl - 1)
			fileOut << endl;
	}
	fileOut.close();
}

/*__________________________________ [Nguyên Mẫu Hàm] __________________________________*/
int TimMonHocTheoMaMonHoc(DanhSachMonHoc dsmh, string maMonHoc);
void ThemMonHoc(DanhSachMonHoc &dsmh);
void XuatDanhSachMonHoc(DanhSachMonHoc dsmh);
void XoaMonHocTheoMaMonHoc(DanhSachMonHoc &dsmh);
void HieuChinhMonHoc(DanhSachMonHoc &dsmh);
void HieuChinhMHTrongDSMH(DanhSachMonHoc &dsmh, string nhap[], int vt);

/*_____________________________________ [Xử lí - Danh Sách Môn Học] _____________________________________*/
int TimMonHocTheoMaMonHoc(DanhSachMonHoc dsmh, string maMonHoc)
{
	for (int i = 0; i < dsmh.sl; i++)
	{
		if (dsmh.mangMonHoc[i]->maMonHoc == maMonHoc)
		{
			return i;
		}
	}
	return -1;
}

string nhap[10];
vector<int> posY{21,24};

void reset()
{
	for(int i=0;i<10;i++){
		nhap[i]="";
	}
}

void ThemMonHoc(DanhSachMonHoc &dsmh)
{
while(1){
	khungthemMH("THEM MON HOC");
	int choice = 0;
	MonHoc *p = new MonHoc;
loop:
	HienConTro();
	gotoxy(80,posY[choice]);
	nhapma(nhap, choice, posY,0,1,15);
	if(choice==-1) choice=1;
	else if(choice==2) choice=0;
	else if(choice==-2){
		reset();
		HCN_NenTrang(65,17,132,27);
		break;
	}
	if(choice==-3) goto loop_end;
	gotoxy(80 + nhap[choice].length(), posY[choice]);
	nhapten(nhap, choice,posY,0,1,50);
	if(choice==-1) choice=1;
	else if(choice==2) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(65,17,132,27);
		break;
	}	
	if(choice>=0) goto loop;
	else goto loop_end;
loop_end:
	int vt = TimMonHocTheoMaMonHoc(dsmh, nhap[0]);
	if (vt != -1)
	{
		choice = 0;
		ThongBaoLau(80,posY[choice],"Ma mon hoc da co roi",-1);
		goto loop;
	}
	
	else
	{
		p->maMonHoc = nhap[0];
		p->tenMonHoc = nhap[1];	
		ChuanHoaChu(p->tenMonHoc);
		dsmh.mangMonHoc[dsmh.sl] = p;
		dsmh.sl++;
		ThongBaoLau(98,28,"Them thanh cong",0);
		reset();
	}
	HCN_NenTrang(65,17,132,27);
}
AnConTro();
}
void XuatDanhSachMonHoc(DanhSachMonHoc dsmh)
{
loop:
	if(dsmh.sl==0){
		ThongBaoLau(0,0,"danh sach rong",-1);
		return;
	}
	khungdanhsachMH();
	outtextxy(0,9,"SO LUONG MON HOC: "+to_string(dsmh.sl),-1);
	gotoxy(0,11);
	vector<int> posY_DSMH;
	for (int i = 0; i < dsmh.sl; i++)
	{
		cout << "\n\n " << i + 1;
		posY_DSMH.push_back(wherey());
		cout << "\n\n Ma mon hoc: " << dsmh.mangMonHoc[i]->maMonHoc;
		cout << "\n Ten mon hoc: " << dsmh.mangMonHoc[i]->tenMonHoc << endl;
	}
	HCN_VienDon1(0,posY_DSMH[0]-1,30,posY_DSMH[0]+1,MAU_DO);
	int stt=0;
	char kiTu;
	int x=wherex(), y=wherey();
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if(kiTu==ESC){
				return;
			}
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP)
				{
					HCN_VienDon1(0,posY_DSMH[stt]-1,30,posY_DSMH[stt]+1,MAU_TRANG);
					stt-=1;
					if(stt==-1) stt=posY_DSMH.size()-1;
					HCN_VienDon1(0,posY_DSMH[stt]-1,30,posY_DSMH[stt]+1,MAU_DO);
				}
				else if (kiTu == DOWN || kiTu == TAB)
				{
					HCN_VienDon1(0,posY_DSMH[stt]-1,30,posY_DSMH[stt]+1,MAU_TRANG);
					stt+=1;
					if(stt==posY_DSMH.size()) stt=0;
					HCN_VienDon1(0,posY_DSMH[stt]-1,30,posY_DSMH[stt]+1,MAU_DO);
				}
			}
			else
			{
				if (kiTu == ENTER)
				{
					HienConTro();
					HieuChinhMHTrongDSMH(dsmh,nhap,stt);
					AnConTro();
					system("cls");
					break;
				}
				else if(kiTu==ESC){
					return;
				}
			}
		}
	}
	goto loop;
}


