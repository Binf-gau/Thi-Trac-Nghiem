#pragma once
#include "LIB_mon_hoc.h"
#include "LIB_sinh_vien.h"

/*_____________________________________ [Danh Sách Lớp] _____________________________________*/
typedef struct Lop
{
	string maLop;
	string tenLop;
	DanhSachSinhVien *dssv;
};
typedef struct DanhSachLop
{
	Lop ds[100];
	int sl = 0;
};

/*______________________ [Khai Báo Nguyên Mẫu Hàm] ______________________*/
//=============== VAN TIEN ======= 
//string nhap[10];
//int posY[3]={21,24};
vector<int> posY_SV{15,18,21,24,27,30};
void HieuChinhSinhVienTrongDSSV(DanhSachLop &dsl,int vtl, NodeSinhVien *p, string nhap[]);
void HieuChinhLopTrongDSL(DanhSachLop &dsl, string nhap[], int vt);
//=============== VAN BINH =======
// - diem thi
bool ThemDiemThi(DanhSachLop &dsl, DanhSachMonHoc dsmh);
bool HieuChinhDiemThi(DanhSachLop dsl, DanhSachMonHoc dsmh);
bool XoaDiemThi(DanhSachLop dsl, DanhSachMonHoc dsmh);
int SoLuongDongTrongBangDiem(DanhSachSinhVien *dssv);
bool InDanhSachDiemThi(DanhSachLop dsl);
// - lich su thi
bool TimCauHoiTheoIDTrongBaiLam(DanhSachLop dsl, int id);

/*______________________ [] ______________________*/


/*_____________________________________ [Xử Lí - Danh Sách Lớp] _____________________________________*/
void KhoiTaoDanhSachSinhVien(DanhSachLop &dsl)
{
	DanhSachSinhVien *dssv = new DanhSachSinhVien;
	dssv->pHead = dssv->pTail = NULL;
	dsl.ds[dsl.sl].dssv = dssv;
}
void GiaiPhongPTRdssv(DanhSachSinhVien *dssv)
{
	delete dssv;
}
void HuyDanhSachSinhVienTungLop(DanhSachLop &dsl)
{
	for (int i = 0; i < dsl.sl; i++)
	{
		HuyDanhSachSinhVien(dsl.ds[i].dssv);
		GiaiPhongPTRdssv(dsl.ds[i].dssv);
	}
}
int TimLopBangMaLop(DanhSachLop dsl, string maLop)
{
	for (int i = 0; i < dsl.sl; i++)
	{
		if (dsl.ds[i].maLop == maLop)
			return i;
	}
	return -1;
}
void ThemLop(DanhSachLop &dsl)
{
while(1){
	khungthemLop("THEM LOP");
	int choice=0;
loop:
	gotoxy(80,posY[choice]);
	HienConTro();
	nhapma(nhap,choice,posY,0,1,15);
	if(choice==-1) choice=1;
	else if(choice==2) choice=0;
	if(choice==-2){
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
	int vt = TimLopBangMaLop(dsl, nhap[0]);
	if (vt != -1)
	{
		choice = 0;
		ThongBaoLau(80,posY[choice],"Ma lop da ton tai",-1);
		goto loop;
	}
	else
	{
		dsl.ds[dsl.sl].maLop = nhap[0];
		dsl.ds[dsl.sl].tenLop=nhap[1];
		KhoiTaoDanhSachSinhVien(dsl);
		dsl.sl++;
		ThongBaoLau(98,28,"Them lop thanh cong",0);
		reset();
	}
	HCN_NenTrang(65,17,132,27);
}
AnConTro();
}
void XuatDanhSachLop(DanhSachLop dsl)
{
loop:
	if (dsl.sl == 0){
		ThongBaoLau(0,10,"danh sach rong",-1);
		return;
	}
	khungdanhsachLop();
	outtextxy(0,9,"SO LUONG LOP: "+to_string(dsl.sl),-1);
	gotoxy(0,11);
	vector<int> posY_DSL;
	for (int i = 0; i < dsl.sl; i++)
	{
		cout << "\n\n " << i + 1;
		posY_DSL.push_back(wherey());
		cout << "\n\n Ma lop: " << dsl.ds[i].maLop;
		cout << "\n Ten lop: " << dsl.ds[i].tenLop << endl;
	}
	HCN_VienDon1(0,posY_DSL[0]-1,30,posY_DSL[0]+1,MAU_DO);
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
					HCN_VienDon1(0,posY_DSL[stt]-1,30,posY_DSL[stt]+1,MAU_TRANG);
					stt-=1;
					if(stt==-1) stt=posY_DSL.size()-1;
					HCN_VienDon1(0,posY_DSL[stt]-1,30,posY_DSL[stt]+1,MAU_DO);
				}
				else if (kiTu == DOWN || kiTu == TAB)
				{
					HCN_VienDon1(0,posY_DSL[stt]-1,30,posY_DSL[stt]+1,MAU_TRANG);
					stt+=1;
					if(stt==posY_DSL.size()) stt=0;
					HCN_VienDon1(0,posY_DSL[stt]-1,30,posY_DSL[stt]+1,MAU_DO);
				}
			}
			else
			{
				if (kiTu == ENTER)
				{
					HienConTro();
					HieuChinhLopTrongDSL(dsl,nhap,stt);
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
void XoaLop(DanhSachLop &dsl)
{
while(1){
	khungxoaLop("XOA LOP");
	int choice=0;
loop:
	gotoxy(80,posY[choice]);
	HienConTro();
	nhapma(nhap,choice,posY,0,0,15);
	if(choice==-1) choice=0;
	else if(choice==1) choice=0;
	else if(choice==-2){
		reset();
		HCN_NenTrang(65,17,132,24);
		break;
	}
	if(choice!=-3) goto loop;
	else goto loop_end;
loop_end:
	int vt = TimLopBangMaLop(dsl, nhap[0]);
	if (vt == -1)
	{
		choice = 0;
		ThongBaoLau(80,posY[choice],"Ma lop khong ton tai",-1);
		goto loop;
	}
	else
	{	
		HuyDanhSachSinhVien(dsl.ds[vt].dssv);
		GiaiPhongPTRdssv(dsl.ds[vt].dssv);	
		for (int i = vt; i < dsl.sl - 1; i++)
		{
			dsl.ds[i] = dsl.ds[i + 1];
		}
		dsl.sl--;
		ThongBaoLau(98,25,"Da xoa xong",0);
		reset();
	}
	HCN_NenTrang(65,17,132,24);
}
AnConTro();
}
void HieuChinhLop(DanhSachLop &dsl)
{
while(1){
	khungxoaLop("HIEU CHINH LOP");
	int choice = 0;
loop_tmp:
	gotoxy(80, posY[choice]);
	HienConTro();
	nhapma(nhap, choice,posY,0,0,15);
	if(choice==-1) choice=0;
	else if(choice==1) choice=0;
	else if(choice==-2){
		reset();
		HCN_NenTrang(65,17,132,27);
		break;
	}
	if(choice!=-3) goto loop_tmp;
	else goto loop_end;
loop_end:
	int vt = TimLopBangMaLop(dsl, nhap[0]);
	if (vt == -1)
	{
		choice = 0;
		ThongBaoLau(80,posY[choice],"Khong tim thay ma lop",-1);
		goto loop_tmp;
	}
	else
	{
		HieuChinhLopTrongDSL(dsl,nhap,vt);
	}
}
AnConTro();
}
void HieuChinhLopTrongDSL(DanhSachLop &dsl, string nhap[], int vt){
		nhap[0]=dsl.ds[vt].maLop;
		nhap[1]=dsl.ds[vt].tenLop;
		HCN_NenTrang(65,17,132,24);
		khungthemLop("HIEU CHINH LOP");
		for (int i = 0; i < 2; i++){
			gotoxy(80,posY[i]);
			cout<<nhap[i];
		}
		int choice = 0;
	loop:
		HienConTro();
		gotoxy(80,posY[choice]);
		nhapma(nhap, choice, posY,0,1,15);
		if(choice==-1) choice=1;
		else if(choice==2) choice=0;
		else if(choice==-2){
			reset();
			HCN_NenTrang(65,17,132,27);
			return;
		}
		if(choice==-3) goto loop_end;
		gotoxy(80 + nhap[choice].length(), posY[choice]);
		nhapten(nhap, choice,posY,0,1,50);
		if(choice==-1) choice=1;
		else if(choice==2) choice=0;
		if(choice==-2){
			reset();
			HCN_NenTrang(65,17,132,27);
			return;
		}	
		if(choice>=0) goto loop;
		else goto loop_end;
	loop_end:
		int vttmp = TimLopBangMaLop(dsl, nhap[0]);
		if (vttmp != -1 && dsl.ds[vt].maLop!=nhap[0])
		{
			choice = 0;
			ThongBaoLau(80,posY[choice],"Ma lop da co roi",-1);
			goto loop;
		}
		dsl.ds[vt].maLop=nhap[0];
		dsl.ds[vt].tenLop=nhap[1];
		ThongBaoLau(98,28,"Da hieu chinh xong",0);
		reset();
		HCN_NenTrang(65,17,132,27);
}
/*_____________________________________ [Xử Lí - Danh Sách Sinh Viên] _____________________________________*/
// kiem tra mssv da ton tai hay ko
bool CheckMSSV(DanhSachSinhVien *dssv, string maSinhVien){
	NodeSinhVien *p = dssv->pHead;
	while (p != NULL)
	{
		if (p->data.maSinhVien == maSinhVien)
		{
			return true;
		}
		p = p->pNext;
	}
	return false;
}
void ThemSinhVien(DanhSachLop &dsl)
{
while(1){
	khungthemSV("THEM SINH VIEN");
	int choice=0;
loop_malop:
	gotoxy(80,posY_SV[choice]);
	HienConTro();
	nhapma(nhap,choice,posY_SV,0,5,15);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		break;
	}
	if(choice ==1) goto loop_mssv;
	else if(choice ==5) goto loop_pass;
	if(choice==-3) goto loop_end;
loop_mssv:
	gotoxy(80,posY_SV[choice]);
	nhapma(nhap,choice,posY_SV,0,5,10);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		break;
	}
	if(choice ==2) goto loop_ho;
	else if(choice ==0) goto loop_malop;
	if(choice==-3) goto loop_end;
loop_ho:
	gotoxy(80+ nhap[choice].length(),posY_SV[choice]);
	nhapten(nhap,choice,posY_SV,0,5,50);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		break;
	}
	if(choice ==3) goto loop_ten;
	else if(choice ==1) goto loop_mssv;
	if(choice==-3) goto loop_end;
loop_ten:
	gotoxy(80+ nhap[choice].length(),posY_SV[choice]);
	nhapten(nhap,choice,posY_SV,0,5,10);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		break;
	}
	if(choice ==4) goto loop_phai;
	else if(choice ==2) goto loop_ho;
	if(choice==-3) goto loop_end;
loop_phai:
	gotoxy(80+ nhap[choice].length(),posY_SV[choice]);
	nhapten(nhap,choice,posY_SV,0,5,3);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		break;
	}
	if(choice ==5) goto loop_pass;
	else if(choice ==3) goto loop_ten;
	if(choice==-3) goto loop_end;
loop_pass:
	gotoxy(80,posY_SV[choice]);
	nhapma(nhap,choice,posY_SV,0,5,10);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		break;
	}
	if(choice ==0) goto loop_malop;
	else if(choice ==4) goto loop_phai;
	if(choice>=0) goto loop_malop;
	else goto loop_end;
loop_end:
	int vt = TimLopBangMaLop(dsl, nhap[0]);
	if (vt == -1){
		choice = 0;
		ThongBaoLau(80,posY_SV[choice],"Ma lop khong ton tai",-1);
		goto loop_malop;
	}
	for(int i=0;i<dsl.sl;i++){
		if(CheckMSSV(dsl.ds[i].dssv,nhap[1])){
			choice=1;
			ThongBaoLau(80,posY_SV[choice],"MSSV da ton tai!",-1);
			goto loop_mssv;
		}
	}
	
	
	{
		SinhVien sv;
		sv.maSinhVien = nhap[1];
		sv.ho = nhap[2];
		ChuanHoaChu(sv.ho);
		sv.ten=nhap[3];
		ChuanHoaChu(sv.ten);
		sv.phai = nhap[4];
		ChuanHoaChu(sv.phai);
		sv.password = nhap[5];
		if (TaoNodeSinhVien(sv) != NULL)
		{
			ThemSinhVienVaoCuoi(dsl.ds[vt].dssv, TaoNodeSinhVien(sv));
			KhoiTaoDanhSachDiemThi(dsl.ds[vt].dssv);
			ThongBaoLau(98,34,"Them sinh vien thanh cong",0);
		}
		else
		{
			ThongBaoLau(98,34,"Khong du bo nho de tao node sinh vien moi",0);
		}
		reset();
	}
	HCN_NenTrang(67,11,132,33);
}
AnConTro();
}
void InDanhSachSinhVien(DanhSachLop dsl)
{

	khungxoaLop("IN DANH SACH SINH VIEN");
	int choice=0;
loop:
	gotoxy(80,posY[choice]);
	HienConTro();
	nhapma(nhap,choice,posY,0,0,15);
	if(choice==-1) choice=0;
	else if(choice==1) choice=0;
	else if(choice==-2){
		reset();
		HCN_NenTrang(65,17,132,24);
		return;
	}
	if(choice!=-3) goto loop;
	string maLop = nhap[0];
	vector<int> posY_DSSV;
	vector<string> mssv_DSSV;
	NodeSinhVien *p;
loop_2:
	int vt = TimLopBangMaLop(dsl, maLop);
	if (vt == -1)
	{
		choice = 0;
		ThongBaoLau(80,posY[choice],"Ma lop khong ton tai",-1);
		goto loop;
	}
	else{
		HCN_NenTrang(65,17,132,24);
		reset();
		AnConTro();
		khungdanhsachSV();
		outtextxy(0,9,"MA LOP:",-1);
		HCN_VienDon(7,8,30,10);
		outtextxy(8,9,maLop,-1);
		outtextxy(0,12,"SO LUONG:",-1);
		HCN_VienDon(9,11,30,13);
		int slsv=0;
		p = dsl.ds[vt].dssv->pHead;
		
		if (p == NULL)
		{
			HCN_VienDon1(0,14,30,16,MAU_TRANG);
			ThongBaoLau(1,15,"Danh sach rong",-1);
			return;
		}
		else
		{
			while (p != NULL)
			{
				slsv+=1;
				cout << "\n\n\n " << slsv;
				posY_DSSV.push_back(wherey());
				cout << "\n\n Ma sinh vien: " << p->data.maSinhVien;
				mssv_DSSV.push_back(p->data.maSinhVien);
				cout << "\n Ho: " << p->data.ho;
				cout << "\n Ten: " << p->data.ten;
				cout << "\n Phai: " << p->data.phai;
				cout << "\n Password: " << p->data.password;
				p = p->pNext;
			}
		}
		outtextxy(10,12,to_string(slsv),-1);	
	}
	HCN_VienDon1(0,posY_DSSV[0]-1,30,posY_DSSV[0]+1,MAU_DO);
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
					HCN_VienDon1(0,posY_DSSV[stt]-1,30,posY_DSSV[stt]+1,MAU_TRANG);
					stt-=1;
					if(stt==-1) stt=posY_DSSV.size()-1;
					HCN_VienDon1(0,posY_DSSV[stt]-1,30,posY_DSSV[stt]+1,MAU_DO);
				}
				else if (kiTu == DOWN || kiTu == TAB)
				{
					HCN_VienDon1(0,posY_DSSV[stt]-1,30,posY_DSSV[stt]+1,MAU_TRANG);
					stt+=1;
					if(stt==posY_DSSV.size()) stt=0;
					HCN_VienDon1(0,posY_DSSV[stt]-1,30,posY_DSSV[stt]+1,MAU_DO);
				}
			}
			else
			{
				if (kiTu == ENTER)
				{
					p=TimSinhVienBangMaSinhVien(dsl.ds[vt].dssv, mssv_DSSV[stt]);
					HieuChinhSinhVienTrongDSSV(dsl, vt, p, nhap);
					if(p->data.maSinhVien!=mssv_DSSV[stt]){
						mssv_DSSV[stt]=p->data.maSinhVien;
					}
					system("cls");
					break;
				}
				else if(kiTu==ESC){
					return;
				}
			}
		}
	}
	goto loop_2;
}
void XoaSinhVien(DanhSachLop &dsl){
while(1){
	khungxoaSV("XOA SINH VIEN");
	int choice=1;
loop:
	gotoxy(80,posY_SV[choice]);
	HienConTro();
	nhapma(nhap,choice,posY_SV,1,1,10);
	if(choice==0 || choice==2) choice=1;
	if(choice==-2){
		reset();
		HCN_NenTrang(72,14,132,21);
		break;
	}
	if(choice>=0) goto loop;
	NodeSinhVien *p;
	int vtl=-1;
	for(int i=0;i<dsl.sl;i++){
		p=TimSinhVienBangMaSinhVien(dsl.ds[i].dssv, nhap[1]);
		if(p!=NULL){
			XoaSinhVienTheoMaSinhVien(dsl.ds[i].dssv, nhap[1]);
			goto loop_end;
			break;
		}
	}
	if(p==NULL){
		choice = 1;
		ThongBaoLau(80,posY_SV[choice],"Khong tim thay MSSV",-1);
		goto loop;
	}
loop_end:
	ThongBaoLau(98,22,"Da xoa sinh vien",0);
	reset();
	HCN_NenTrang(72,14,132,21);
}
AnConTro();
}
void HieuChinhSinhVien(DanhSachLop &dsl){
while(1){
	khungxoaSV("HIEU CHINH SINH VIEN");
	int choice=1;
loop:
	gotoxy(80,posY_SV[choice]);
	HienConTro();
	nhapma(nhap,choice,posY_SV,1,1,10);
	if(choice==0 || choice==2) choice=1;
	if(choice==-2){
		reset();
		HCN_NenTrang(72,14,132,21);
		break;
	}
	if(choice>=0) goto loop;
	else goto loop_end;
loop_end:
	NodeSinhVien *p;
	int vtl=-1;
	for(int i=0;i<dsl.sl;i++){
		p = TimSinhVienBangMaSinhVien(dsl.ds[i].dssv, nhap[1]);
		if(p!=NULL){
			vtl=i;
			reset();
			HCN_NenTrang(72,14,132,21);
			break;
		}
	}
	if(p==NULL){
		choice = 1;
		ThongBaoLau(80,posY_SV[choice],"Khong tim thay MSSV",-1);
		goto loop;
	}
	HieuChinhSinhVienTrongDSSV(dsl,vtl, p, nhap);
}
AnConTro();
}

void HieuChinhSinhVienTrongDSSV(DanhSachLop &dsl,int vtl, NodeSinhVien *p, string nhap[]){
	khungthemSV("HIEU CHINH SINH VIEN");
	nhap[0]=dsl.ds[vtl].maLop;
	nhap[1]=p->data.maSinhVien;
	nhap[2]=p->data.ho;
	nhap[3]=p->data.ten;
	nhap[4]=p->data.phai;
	nhap[5]=p->data.password;
	for(int i=0;i<posY_SV.size();i++){
		gotoxy(80,posY_SV[i]);
		cout<<nhap[i];
	}
	int choice=0;
loop_malop:
	gotoxy(80,posY_SV[choice]);
	HienConTro();
	nhapma(nhap,choice,posY_SV,0,5,15);
	if(choice==-1) choice=5;
	else if(choice==6) choice=0;
	if(choice==-2){
		reset();
		HCN_NenTrang(67,11,132,33);
		AnConTro();
		return;
	}
	if(choice==-3) goto loop_end;
loop_mssv:
		gotoxy(80,posY_SV[choice]);
		nhapma(nhap,choice,posY_SV,0,5,10);
		if(choice==-1) choice=5;
		else if(choice==6) choice=0;
		if(choice==-2){
			reset();
			HCN_NenTrang(67,11,132,33);
			AnConTro();
			return;
		}
		if(choice==-3) goto loop_end;
loop_ho:
		gotoxy(80+ nhap[choice].length(),posY_SV[choice]);
		nhapten(nhap,choice,posY_SV,0,5,50);
		if(choice==-1) choice=5;
		else if(choice==6) choice=0;
		if(choice==-2){
			reset();
			HCN_NenTrang(67,11,132,33);
			AnConTro();
			return;
		}
		if(choice==-3) goto loop_end;
loop_ten:
		gotoxy(80+ nhap[choice].length(),posY_SV[choice]);
		nhapten(nhap,choice,posY_SV,0,5,10);
		if(choice==-1) choice=5;
		else if(choice==6) choice=0;
		if(choice==-2){
			reset();
			HCN_NenTrang(67,11,132,33);
			AnConTro();
			return;
		}
		if(choice==-3) goto loop_end;
loop_phai:
		gotoxy(80+ nhap[choice].length(),posY_SV[choice]);
		nhapten(nhap,choice,posY_SV,0,5,3);
		if(choice==-1) choice=5;
		else if(choice==6) choice=0;
		if(choice==-2){
			reset();
			HCN_NenTrang(67,11,132,33);
			AnConTro();
			return;
		}
		if(choice==-3) goto loop_end;
loop_pass:
		gotoxy(80,posY_SV[choice]);
		nhapma(nhap,choice,posY_SV,0,5,15);
		if(choice==-1) choice=5;
		else if(choice==6) choice=0;
		if(choice==-2){
			reset();
			HCN_NenTrang(67,11,132,33);
			AnConTro();
			return;
		}
	if(choice>=0) goto loop_malop;
	else goto loop_end;
loop_end:
	int vt = TimLopBangMaLop(dsl, nhap[0]);
	if (vt == -1){
		choice = 0;
		ThongBaoLau(80,posY_SV[choice],"Ma lop khong ton tai",-1);
		goto loop_malop;
	}
	for(int i=0;i<dsl.sl;i++){
		if(CheckMSSV(dsl.ds[i].dssv,nhap[1]) && p->data.maSinhVien!=nhap[1]){
			choice=1;
			ThongBaoLau(80,posY_SV[choice],"MSSV da ton tai!",-1);
			goto loop_mssv;
		}
	}
	
	{
		SinhVien sv;
		sv.maSinhVien = nhap[1];
		sv.ho = nhap[2];
		ChuanHoaChu(sv.ho);
		sv.ten = nhap[3];
		ChuanHoaChu(sv.ten);
		sv.phai = nhap[4];
		ChuanHoaChu(sv.phai);
		sv.password = nhap[5];
		p->data.maSinhVien=nhap[1];
		p->data.ho=nhap[2];
		p->data.ten=nhap[3];
		p->data.phai=nhap[4];
		p->data.password=nhap[5];
		if(nhap[0]!=dsl.ds[vtl].maLop){
			NodeSinhVien *q=dsl.ds[vtl].dssv->pHead;
			if(q==p){
				dsl.ds[vtl].dssv->pHead=p->pNext;
			}
			else{
				while(q->pNext!=p){
					q=q->pNext;
				}
			}
			q->pNext=p->pNext;
			vtl=TimLopBangMaLop(dsl, nhap[0]);
			ThemSinhVienVaoDau(dsl.ds[vtl].dssv, p);
		}
		ThongBaoLau(98,34,"Da thay doi thong tin sinh vien",0);
		reset();
	}
	HCN_NenTrang(67,11,132,33);
	AnConTro();
}

// ================== VAN BINH ==================================
/*_____________________________________ [Xử lí - Danh Sách Điểm Thi] _____________________________________*/
bool ThemDiemThi(DanhSachLop &dsl, DanhSachMonHoc dsmh)
{
	KhungThemDiemThi();
	string line[3];
	NodeSinhVien *p;
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
				gotoxyMSSV(line[choice].length());
				break;
			}
			case 1:
			{
				gotoxyMMH(line[choice].length());
				break;
			}
			case 2:
			{
				gotoxyDiemThi(line[choice].length());
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
						gotoxyMMH(line[choice].length());
					}
					else if (choice == 1)
					{
						choice++;
						gotoxyDiemThi(line[choice].length());
					}
					else if (choice == 2)
					{
						choice = 0;
						gotoxyMSSV(line[choice].length());
					}
				}

				else if (kiTu == UP && phimKep)
				{
					if (choice == 0)
					{
						choice = 2;
						gotoxyDiemThi(line[choice].length());
					}
					else if (choice == 1)
					{
						choice--;
						gotoxyMSSV(line[choice].length());
					}
					else if (choice == 2)
					{
						choice--;
						gotoxyMMH(line[choice].length());
					}
				}

				else if (kiTu == RIGHT && phimKep && choice != 2)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 81 + (int)line[choice].length()), y);
				}

				else if (kiTu == LEFT && phimKep && choice != 2)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 81), y);
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 81;
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
								gotoxyMSSV(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMSSV(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
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
								gotoxyMMH(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMMH(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 2:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "            Empty             ", -1, MAU_XAM);
								gotoxyDiemThi(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyDiemThi(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						}
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9') || (kiTu == '.')) && !phimKep) // kytu
				{
					int viTri = wherex() - 81;
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
							gotoxyMSSV(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 81, y);
						}
						else
						{
							gotoxyMSSV(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMSSV(0);
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
							gotoxyMMH(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 81, y);
						}
						else
						{
							gotoxyMMH(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMMH(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 2:
					{
						if (((kiTu >= '0' && kiTu <= '9') || kiTu == '.') && !phimKep)
						{
							if (line[choice].length() < 4)
							{
								line[choice].insert(line[choice].begin() + viTri, kiTu);
								gotoxyDiemThi(0);
								cout << line[choice];
								gotoxy(viTri + 1 + 81, y);
							}
							else
							{
								gotoxyDiemThi(0);
								ThongBaoNhanh(wherex(), wherey(), "      Full       ", -1, MAU_XAM);
								gotoxyDiemThi(0);
								cout << line[choice];
								gotoxy(x, y);
							}
						}
						break;
					}
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
					gotoxyMSSV(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMSSV(0);
					cout << line[0];
					choice = 0;
				}
				else if (TimMonHocTheoMaMonHoc(dsmh, line[1]) == -1)
				{
					gotoxyMMH(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMMH(0);
					cout << line[1];
					choice = 1;
				}
				else if (TimDiemThiBangMaMonHoc(p->data.dsdt, line[1]) != NULL)
				{
					gotoxyMMH(0);
					ThongBaoNhanh(wherex(), wherey(), "Sinh vien da thi, khong the them", -1, MAU_DO);
					gotoxyMMH(0);
					cout << line[1];
					choice = 1;
				}
				else if (atof(line[2].c_str()) > 10)
				{
					gotoxyDiemThi(0);
					ThongBaoNhanh(wherex(), wherey(), " <= 10 diem ", -1, MAU_DO);
					gotoxyDiemThi(0);
					cout << line[2];
					choice = 2;
				}
				else
				{
					DiemThi dt;
					dt.maMonHoc = line[1];
					dt.diem = atof(line[2].c_str());
					dt.bl = new BaiLam;
					ThemDiemThiVaoCuoi(p->data.dsdt, TaoNodeDiemThi(dt));
					return 1;
				}
			}
		}
	}
}
bool HieuChinhDiemThi(DanhSachLop dsl, DanhSachMonHoc dsmh)
{
	KhungHieuChinhDiemThi();
	string line[3];
	NodeSinhVien *p;
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
				gotoxyMSSV(line[choice].length());
				break;
			}
			case 1:
			{
				gotoxyMMH(line[choice].length());
				break;
			}
			case 2:
			{
				gotoxyDiemThi(line[choice].length());
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
						gotoxyMMH(line[choice].length());
					}
					else if (choice == 1)
					{
						choice++;
						gotoxyDiemThi(line[choice].length());
					}
					else if (choice == 2)
					{
						choice = 0;
						gotoxyMSSV(line[choice].length());
					}
				}

				else if (kiTu == UP && phimKep)
				{
					if (choice == 0)
					{
						choice = 2;
						gotoxyDiemThi(line[choice].length());
					}
					else if (choice == 1)
					{
						choice--;
						gotoxyMSSV(line[choice].length());
					}
					else if (choice == 2)
					{
						choice--;
						gotoxyMMH(line[choice].length());
					}
				}

				else if (kiTu == RIGHT && phimKep && choice != 2)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 81 + (int)line[choice].length()), y);
				}

				else if (kiTu == LEFT && phimKep && choice != 2)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 81), y);
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 81;
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
								gotoxyMSSV(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMSSV(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
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
								gotoxyMMH(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMMH(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						case 2:
						{
							if (line[choice].length() == 0)
							{
								AnConTro();
								ThongBaoNhanh(wherex(), wherey(), "            Empty             ", -1, MAU_XAM);
								gotoxyDiemThi(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyDiemThi(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						}
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9') || (kiTu == '.')) && !phimKep) // kytu
				{
					int viTri = wherex() - 81;
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
							gotoxyMSSV(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 81, y);
						}
						else
						{
							gotoxyMSSV(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMSSV(0);
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
							gotoxyMMH(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 81, y);
						}
						else
						{
							gotoxyMMH(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMMH(0);
							cout << line[choice];
							gotoxy(x, y);
						}
						break;
					}
					case 2:
					{
						if (((kiTu >= '0' && kiTu <= '9') || kiTu == '.') && !phimKep)
						{
							if (line[choice].length() < 4)
							{
								line[choice].insert(line[choice].begin() + viTri, kiTu);
								gotoxyDiemThi(0);
								cout << line[choice];
								gotoxy(viTri + 1 + 81, y);
							}
							else
							{
								gotoxyDiemThi(0);
								ThongBaoNhanh(wherex(), wherey(), "      Full       ", -1, MAU_XAM);
								gotoxyDiemThi(0);
								cout << line[choice];
								gotoxy(x, y);
							}
						}
						break;
					}
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
					gotoxyMSSV(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMSSV(0);
					cout << line[0];
					choice = 0;
				}
				else if (TimMonHocTheoMaMonHoc(dsmh, line[1]) == -1)
				{
					gotoxyMMH(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMMH(0);
					cout << line[1];
					choice = 1;
				}
				else if (atof(line[2].c_str()) > 10)
				{
					gotoxyDiemThi(0);
					ThongBaoNhanh(wherex(), wherey(), " <= 10 diem ", -1, MAU_DO);
					gotoxyDiemThi(0);
					cout << line[2];
					choice = 2;
				}
				else
				{
					NodeDiemThi *q = TimDiemThiBangMaMonHoc(p->data.dsdt, line[1]);
					if (q != NULL && q->data.bl->soLuongCauHoiYeuCau == 0)
					{
						q->data.diem = atof(line[2].c_str());
						return 1;
					}
					else if (q != NULL && q->data.bl->soLuongCauHoiYeuCau != 0)
					{
						gotoxyMMH(0);
						ThongBaoNhanh(wherex(), wherey(), "Sinh vien da thi, khong duoc sua", -1, MAU_DO);
						gotoxyMMH(0);
						cout << line[1];
						choice = 1;
					}
					else
					{
						gotoxyMMH(0);
						ThongBaoNhanh(wherex(), wherey(), "Khong ton tai diem thi", -1, MAU_DO);
						gotoxyMMH(0);
						cout << line[1];
						choice = 1;
					}
					
				}
			}
		}
	}
}
bool XoaDiemThi(DanhSachLop dsl, DanhSachMonHoc dsmh)
{
	KhungXoaDiemThi();
	string line[2];
	NodeSinhVien *p;
	while (true)
	{
		line[0] = "";
		line[1] = "";
		char kiTu = 'NULL';
		bool phimKep = false;
		int choice = 0;

		while (true) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{

			switch (choice)
			{
			case 0:
			{
				gotoxyMSSV(line[choice].length());
				break;
			}
			case 1:
			{
				gotoxyMMH(line[choice].length());
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
						gotoxyMMH(line[choice].length());
					}
					else if (choice == 1)
					{
						choice = 0;
						gotoxyMSSV(line[choice].length());
					}
				}

				else if (kiTu == UP && phimKep)
				{
					if (choice == 0)
					{
						choice = 1;
						gotoxyMMH(line[choice].length());
					}
					else if (choice == 1)
					{
						choice--;
						gotoxyMSSV(line[choice].length());
					}
				}

				else if (kiTu == RIGHT && phimKep)
				{
					int x = wherex();
					int y = wherey();
					gotoxy(min(x + 1, 81 + (int)line[choice].length()), y);
				}

				else if (kiTu == LEFT && phimKep)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 81), y);
				}

				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 81;
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
								gotoxyMSSV(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMSSV(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
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
								gotoxyMMH(0);
								HienConTro();
							}
							else if (line[choice].length() != 0 && viTri > 0)
							{
								AnConTro();
								line[choice].erase(line[choice].begin() + viTri - 1);
								gotoxyMMH(0);
								cout << line[choice] << " ";
								gotoxy(81 + viTri - 1, y);
								HienConTro();
							}
							break;
						}
						}
					}
				}

				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && !phimKep) // kytu
				{
					int viTri = wherex() - 81;
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
							gotoxyMSSV(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 81, y);
						}
						else
						{
							gotoxyMSSV(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMSSV(0);
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
							gotoxyMMH(0);
							cout << line[choice];
							gotoxy(viTri + 1 + 81, y);
						}
						else
						{
							gotoxyMMH(0);
							ThongBaoNhanh(wherex(), wherey(), "             Full                ", -1, MAU_XAM);
							gotoxyMMH(0);
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
					gotoxyMSSV(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMSSV(0);
					cout << line[0];
					choice = 0;
				}
				else if (TimMonHocTheoMaMonHoc(dsmh, line[1]) == -1)
				{
					gotoxyMMH(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu ", -1, MAU_DO);
					gotoxyMMH(0);
					cout << line[1];
					choice = 1;
				}
				else
				{
					NodeDiemThi *q = TimDiemThiBangMaMonHoc(p->data.dsdt, line[1]);
					if (q != NULL && q->data.bl->soLuongCauHoiYeuCau == 0)
					{
						XoaDiemThiTheoMaMonHoc(p->data.dsdt, line[1]);
						return 1;
					}
					else if (q != NULL && q->data.bl->soLuongCauHoiYeuCau != 0)
					{
						gotoxyMMH(0);
						ThongBaoNhanh(wherex(), wherey(), "Sinh vien da thi, khong duoc xoa", -1, MAU_DO);
						gotoxyMMH(0);
						cout << line[1];
						choice = 1;
					}
					else
					{
						gotoxyMMH(0);
						ThongBaoNhanh(wherex(), wherey(), "Khong ton tai diem thi", -1, MAU_DO);
						gotoxyMMH(0);
						cout << line[1];
						choice = 1;
					}
					
				}
			}
		}
	}
}

int SoLuongDongTrongBangDiem(DanhSachSinhVien *dssv)
{
	int dem = 0;
	int soBaiThi = -1;
	NodeSinhVien *p = dssv->pHead;
	while (p != NULL)
	{
		dem++;
		NodeDiemThi *q = p->data.dsdt->pHead;
		while (q != NULL)
		{
			soBaiThi++;
			q = q->pNext;
		}
		if (soBaiThi != -1)
		{
			dem = dem + soBaiThi;
			soBaiThi = -1;
		}
		p = p->pNext;
	}
	return dem;
}
bool InDanhSachDiemThi(DanhSachLop dsl)
{
	KhungNhapLopXemDiemThi();
	string maLop = "";
	int viTriLop = 0;
	bool flag = true;
	while (flag)
	{
		char kiTu = 'NULL';
		bool phimKep = false;
		while (flag) // chứa: (chứa di chuyển, xóa, cộng string), kiểm tra du lieu nhap vao
		{
			HienConTro();
			gotoxyNhapMaLop(maLop.length());
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
					gotoxy(min(x + 1, 50 + (int)maLop.length()), y);
				}
				else if (kiTu == LEFT && phimKep)
				{
					int y = wherey();
					gotoxy(max(wherex() - 1, 50), y);
				}
				else if (kiTu == BACKSPACE && !phimKep)
				{
					int x = wherex();
					int y = wherey();
					int viTri = x - 50;
					AnConTro();
					if (maLop.length() == 0)
					{
						ThongBaoNhanh(x, y, "      Empty      ", -1, MAU_XAM);
						gotoxyNhapMaLop(0);
					}
					else if (maLop.length() != 0 && viTri > 0)
					{
						maLop.erase(maLop.begin() + viTri - 1);
						gotoxyNhapMaLop(0);
						cout << maLop << " ";
						gotoxy(50 + viTri - 1, y);
					}
					HienConTro();
				}
				else if (((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9')) && !phimKep) // kytu
				{
					int viTri = wherex() - 50;
					int x = wherex();
					int y = wherey();
					AnConTro();
					if (maLop.length() < 16)
					{
						if (kiTu >= 'a' && kiTu <= 'z')
							kiTu -= 32;
						maLop.insert(maLop.begin() + viTri, kiTu);
						gotoxyNhapMaLop(0);
						cout << maLop;
						gotoxy(viTri + 1 + 50, y);
					}
					else
					{
						gotoxyNhapMaLop(0);
						ThongBaoNhanh(wherex(), wherey(), "      Full      ", -1, MAU_XAM);
						gotoxyNhapMaLop(0);
						cout << maLop;
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
			if (maLop.length() == 0)
			{
				gotoxyNhapMaLop(0);
				ThongBaoNhanh(wherex(), wherey(), "Chua nhap ma lop", -1, MAU_DO);
				gotoxyNhapMaLop(0);
			}
			else
			{
				viTriLop = TimLopBangMaLop(dsl, maLop);
				if (viTriLop == -1)
				{
					gotoxyNhapMaLop(0);
					ThongBaoNhanh(wherex(), wherey(), "Khong co du lieu", -1, MAU_DO);
					gotoxyNhapMaLop(0);
					cout << maLop;
				}
				else if (dsl.ds[viTriLop].dssv->pHead == NULL)
				{
					gotoxyNhapMaLop(0);
					ThongBaoNhanh(wherex(), wherey(), "Lop chua co sinh vien", -1, MAU_DO);
					gotoxyNhapMaLop(0);
					cout << maLop;
				}
				else
				{
					flag = false;
				}
			}
		}
	}
	int stt = 0;
	int dong = 10;
	Table(SoLuongDongTrongBangDiem(dsl.ds[viTriLop].dssv));
	Normal();
	NodeSinhVien *p = dsl.ds[viTriLop].dssv->pHead;
	while (p != NULL)
	{
		NodeDiemThi *q = p->data.dsdt->pHead;
		if (q == NULL)
		{
			dong += 2;
			gotoxy(36, dong);
			cout << ++stt;
			gotoxy(42, dong);
			cout << p->data.maSinhVien;
			gotoxy(62, dong);
			cout << p->data.ho;
			gotoxy(92, dong);
			cout << p->data.ten;
			gotoxy(107, dong);
			cout << "";
			gotoxy(132, dong);
			cout << "Chua Thi";
		}
		else
		{
			while (q != NULL)
			{
				dong += 2;
				gotoxy(36, dong);
				cout << ++stt;
				gotoxy(42, dong);
				cout << p->data.maSinhVien;
				gotoxy(62, dong);
				cout << p->data.ho;
				gotoxy(92, dong);
				cout << p->data.ten;
				gotoxy(107, dong);
				cout << q->data.maMonHoc;
				gotoxy(132, dong);
				cout << q->data.diem;
				q = q->pNext;
			}
		}
		p = p->pNext;
	}
	while (true)
	{
		char kiTu = getch();
		if (kiTu == ESC)
		{
			return true;
		}
	}
}

/*_____________________________________ [Xử lí - Danh Sách Bài Làm] _____________________________________*/
bool TimCauHoiTheoIDTrongBaiLam(DanhSachLop dsl, int id)
{
	for (int i = 0; i < dsl.sl; i++)
	{
		NodeSinhVien *p = dsl.ds[i].dssv->pHead;
		while (p != NULL)
		{
			NodeDiemThi *q = p->data.dsdt->pHead;
			while (q != NULL)
			{
				for (int j = 0; j < q->data.bl->soLuongCauHoiYeuCau; j++)
				{
					if (q->data.bl->mangCauHoi[j]->id == id)
					{
						return true;
					}
				}
				q = q->pNext;
			}
			p = p->pNext;
		}
	}
	return false;
}
