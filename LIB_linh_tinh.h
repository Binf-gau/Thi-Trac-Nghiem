#pragma once
#include "Lib/mylib.h"
#include "LIB_do_hoa.h"
#include "LIB_mang_random_id.h"
#include <string>

#define BACKSPACE 8
#define ENTER 13
#define ESC 27
#define TAB 9
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define F1 59

void Normal()
{
	SetColor(0);
	SetBGColor(15);
}

void HighLight()
{
	SetColor(207);
	SetBGColor(12);
}

void ThongBaoNhanh(int x, int y, string s, int style, int color)
{
	outtextxy1(x, y, s, style, color);
	Sleep(500);
	for (int i = 0; i < s.length(); i++)
		s[i] = char(HCN);
	outtextxy1(x, y, s, style, MAU_TRANG);
	gotoxy(x, y);
	SetColor(MAU_DEN);
}

void ThongBaoLau(int x, int y, string s, int style)
{
	outtextxy1(x, y, s, style, 244);
	Sleep(1500);
	for (int i = 0; i < s.length(); i++)
		s[i] = char(HCN);
	outtextxy1(x, y, s, style, MAU_TRANG);
	gotoxy(x, y);
}

void ThongBaoNhanh1(int x, int y, string s1, int n, string s2, int style, int color)
{
	outtextxy1(x, y, s1, style, color);
	cout << " " << n << " " << s2;
	Sleep(350);
	SetColor(MAU_TRANG);
	for (int i = 0; i < s1.length() + s2.length(); i++)
		cout << char(HCN);
	gotoxy(x, y);
	SetColor(MAU_DEN);
}

void ThongBao(char *s)
{
	HighLight();
	int x = wherex(), y = wherey();
	gotoxy(45, 30);
	cout << s;
	Sleep(1000);
	gotoxy(45, 30);
	Normal();
	for (int i = 0; i < strlen(s); i++)
		cout << " ";
	gotoxy(x, y);
}

void BaoLoi(char *s)
{
	HighLight();
	int x = wherex(), y = wherey();
	gotoxy(45, 20);
	cout << s;
	Sleep(5000);
	gotoxy(45, 20);
	Normal();
	for (int i = 0; i < strlen(s); i++)
		cout << " ";
	gotoxy(x, y);
}

void ChuanHoaMa(string &a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			a.erase(a.begin() + i);
		}
	}
	for (int i = 0; i < a.length(); i++)
	{
		if ('a' <= a[i] && a[i] <= 'z')
		{
			a[i] -= 32;
		}
	}
}
//tiennhot23
void nhapten(string nhap[], int &choice, vector<int> pos, int beg, int end, int max_char)
{
	char kiTu;
	int x=wherex(), y=wherey();
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP)
				{
//					if(nhap[choice].empty()){
//						ThongBaoLau(80,wherey(),"Khong duoc de rong",-1);
//					}
//					else{
//						choice -= 1;
//						return;	
//					}
					choice -=1;
					return;
				}
				else if (kiTu == DOWN)
				{
//					if(nhap[choice].empty()){
//						ThongBaoLau(80,wherey(),"Khong duoc de rong",-1);
//					}
//					else{
//						choice += 1;
//						return;	
//					}
					choice +=1;
					return;
				}
				else if (kiTu == LEFT)
				{
					y = wherey();
					gotoxy(max(wherex() - 1,80), y);
				}
				else if (kiTu == RIGHT)
				{
					y = wherey();
					gotoxy(min(wherex() + 1,80 + (int)nhap[choice].length()), y);
				}
			}
			else
			{
				if ((kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= 'a' && kiTu <= 'z') || kiTu == ' ')
				{
					if(nhap[choice].length()==max_char){
						ThongBaoNhanh(80, wherey(),"Toi da "+to_string(max_char)+" ki tu!                                  ",-1,MAU_XAM);
//						gotoxy(x,y);
					}
					else{
						x = wherex() - 80 ;
						nhap[choice].insert(nhap[choice].begin() + x, kiTu);
						
					}
					y = wherey();
					gotoxy(80, y);
					cout << nhap[choice];
//					gotoxy(x + 1 + 80, y);
				}
				else if (kiTu == BACKSPACE && !nhap[choice].empty())
				{
					int x = wherex() - 80 ;
					y = wherey();
					if (x > 0)
					{
						nhap[choice].erase(nhap[choice].begin() + x - 1);
						gotoxy(/*s[choice].length()*/ 80, y);
						cout << nhap[choice] << " ";
						gotoxy(x - 1 + 80 , y);
					}
				}
				else if (kiTu == ENTER)
				{
					int x=wherex(), y=wherey();
					bool done=true;
					for(int i=beg;i<=end;i++){
						if(nhap[i].empty()){
							ThongBaoLau(80,pos[i],"Ban chua nhap thong tin nay!",-1);
							done=false;
							gotoxy(x,y);
							break;
						}
					}
					if(done){
						choice=-3;
						return;
					}
				}
				else if(kiTu==ESC){
					choice=-2;
					return;
				}
				else if (kiTu == TAB)
				{
//					if(nhap[choice].empty()){
//						ThongBaoLau(80,pos[choice],"Khong duoc de rong",-1);
//					}
//					else{
//						choice += 1;
//						return;	
//					}
					choice+=1;
					return;
				}
			}
		}
	}
}
void nhapma(string nhap[], int &choice, vector<int> pos, int beg, int end, int max_char)
{
	cout<<nhap[choice];
	char kiTu;
	int x = wherex(), y = wherey();
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP)
				{
//					if(nhap[choice].empty()){
//						ThongBaoLau(80,wherey(),"Khong duoc de rong",-1);
//					}
//					else{
//						choice -= 1;
//						return;	
//					}
					choice-=1;
					return;
				}
				else if (kiTu == DOWN)
				{
//					if(nhap[choice].empty()){
//						ThongBaoLau(80,wherey(),"Khong duoc de rong",-1);
//					}
//					else{
//						choice += 1;
//						return;	
//					}
					choice+=1;
					return;
				}
				else if (kiTu == LEFT)
				{
					x = wherex(), y = wherey();
					gotoxy(max(wherex() - 1, 80), y);
				}
				else if (kiTu == RIGHT)
				{
					x = wherex(), y = wherey();
					gotoxy(min(wherex() + 1, 80 + (int)nhap[choice].length()), y);
				}
			}
			else
			{
				if ((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9'))
				{
					if(nhap[choice].length()==max_char){
						x=wherex(),y=wherey();
						ThongBaoNhanh(80, y,"Toi da "+to_string(max_char)+" ki tu!    ",-1,MAU_XAM);
//						gotoxy(x,y);
					}
					else{
						if (kiTu >= 'a' && kiTu <= 'z')
						{
							kiTu -= 32;
						}
						x = wherex() - 80;
						nhap[choice].insert(nhap[choice].begin() + x, kiTu);
						
					}
					y = wherey();
					gotoxy(80, y);
					cout << nhap[choice];
//					gotoxy(wherex()+1, y);
				}
				else if (kiTu == BACKSPACE && !nhap[choice].empty())
				{
					int x = wherex() - 80;
					y = wherey();
					if (x > 0)
					{
						nhap[choice].erase(nhap[choice].begin() + x - 1);
						gotoxy(80, y);
						cout << nhap[choice] << " ";
						gotoxy(x - 1 + 80, y);
					}
				}
				else if (kiTu == ENTER)
				{
					x=wherex(), y=wherey();
					bool done=true;
					for(int i=beg;i<=end;i++){
						if(nhap[i].empty()){
							ThongBaoLau(80,pos[i],"Ban chua nhap thong tin nay!",-1);
							done=false;
							gotoxy(x,y);
							break;
						}
					}
					if(done){
						choice=-3;
						return;
					}
				}
				else if(kiTu==ESC){
					choice=-2;
					return;
				}
				else if (kiTu == TAB)
				{
//					if(nhap[choice].empty()){
//						ThongBaoLau(80,pos[choice],"Khong duoc de rong",-1);
//					}
//					else{
//						choice += 1;
//						return;	
//					}
					choice+=1;
					return;
				}
			}
		}
	}
}
//end tiennhot23

string NhapMaSo()
{
	HienConTro();
	string maSo = "";
	char kiTu;
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP || kiTu == DOWN || kiTu == RIGHT || kiTu == LEFT)
					;
				//					return maSo;
			}
			else
			{
				if ((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9'))
				{
					if (kiTu >= 'a' && kiTu <= 'z')
					{
						kiTu -= 32;
					}
					maSo += kiTu;
					cout << kiTu;
				}
				else if (kiTu == BACKSPACE && !maSo.empty())
				{
					cout << "\b \b";
					maSo.erase(maSo.length() - 1, 1);
				}
				else if (kiTu == ENTER)
				{
					if (!maSo.empty())
						return maSo;
					else
					{
						ThongBao("Khong duoc de rong");
					}
				}
			}
		}
	}
}

string NhapMatKhau()
{
	string matKhau = "";
	char kiTu;
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP || kiTu == DOWN || kiTu == RIGHT || kiTu == LEFT)
					return matKhau;
			}
			else
			{
				if ((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9'))
				{
					matKhau += kiTu;
					cout << kiTu;
				}
				else if (kiTu == BACKSPACE && !matKhau.empty())
				{
					cout << "\b \b";
					matKhau.erase(matKhau.length() - 1, 1);
				}
				else if (kiTu == ENTER && !matKhau.empty())
				{
					return matKhau;
				}
			}
		}
	}
}

string DienMatKhau()
{
	string matKhau = "";
	char kiTu;
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP || kiTu == DOWN || kiTu == RIGHT || kiTu == LEFT)
					return matKhau;
			}
			else
			{
				if ((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z') || (kiTu >= '0' && kiTu <= '9'))
				{
					matKhau += kiTu;
					cout << '*';
				}
				else if (kiTu == BACKSPACE && !matKhau.empty())
				{
					cout << "\b \b";
					matKhau.erase(matKhau.length() - 1, 1);
				}
				else if (kiTu == ENTER && !matKhau.empty())
				{
					return matKhau;
				}
			}
		}
	}
}

int NhapSo()
{
	string so = "";
	char kiTu;
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu >= '0' && kiTu <= '9')
			{
				so += kiTu;
				cout << kiTu;
			}
			else if (kiTu == BACKSPACE && !so.empty())
			{
				cout << "\b \b";
				so.erase(so.length() - 1, 1);
			}
			else if (kiTu == ENTER && !so.empty())
			{
				return atoi(so.c_str());
			}
		}
	}
}

bool KiemTraChuoiRong(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != ' ')
		{
			return false;
		}
	}
	return true;
}

string NhapChu()
{
	string chu = "";
	char kiTu;
	while (true)
	{
		if (kbhit())
		{
			kiTu = getch();
			if (kiTu == -32)
			{
				kiTu = getch();
				if (kiTu == UP || kiTu == DOWN || kiTu == RIGHT || kiTu == LEFT)
					;
			}
			else
			{
				if (kiTu >= 32 && kiTu <= 126)
				{
					chu += kiTu;
					cout << kiTu;
				}
				else if (kiTu == BACKSPACE && !chu.empty())
				{
					cout << "\b \b";
					chu.erase(chu.length() - 1, 1);
				}
				else if (kiTu == ENTER)
				{
					if (!chu.empty())
						return chu;
					else
					{
						ThongBao("Khong duoc de rong");
					}
				}
			}
		}
	}
}

void ChuanHoaChu(string &a) //Trường hợp a rỗng sẽ bị lỗi
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	for (int i = 0; i < a.length() - 1 && a.length() > 1; i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	if (a[0] >= 'a' && a[0] <= 'z')
	{
		a[0] -= 32;
	}
	for (int i = 0; i < a.length() - 1; i++)
	{
		if (a[i] == ' ')
		{
			if (a[i + 1] >= 'a' && a[i + 1] <= 'z')
			{
				a[i + 1] -= 32;
			}
		}
		else
		{
			if (a[i + 1] >= 'A' && a[i + 1] <= 'Z' && a[i + 1] != ' ')
			{
				a[i + 1] += 32;
			}
		}
	}
}

void ChuanDauInHoa(string &a) //Trường hợp a rỗng sẽ bị lỗi
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	if (a[0] >= 'a' && a[0] <= 'z')
	{
		a[0] -= 32;
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	for (int i = 0; i < a.length() - 1 && a.length() > 1; i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
}

void NhapDapAn(string &dapAn, string &yeuCau, clock_t endTime)
{
	char kiTu;
	bool phimKep;
	if (dapAn != "")
	{
		outtextxy1(49, 22, dapAn, -1, 4);
	}
	while (true)
	{
		if (_kbhit())
		{
			if (clock() >= endTime)
			{
				yeuCau = "HET GIO";
				break;
			}
			if ((endTime - clock()) / CLOCKS_PER_SEC < 30)
			{
				outtextxy1(61, 16, "Sap Het Thoi Gian", 0, rand() % (15 - 0 + 1) + 0);
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

			if ((phimKep && (kiTu == RIGHT)) || (!phimKep && (kiTu == ENTER)))
			{
				yeuCau = "RIGHT";
				break;
			}
			else if (phimKep && (kiTu == LEFT))
			{
				yeuCau = "LEFT";
				break;
			}
			else if (phimKep && (kiTu == F1))
			{
				yeuCau = "DONE";
				break;
			}
			else if (kiTu == TAB && !phimKep)
			{
				yeuCau = "JUMP";
				break;
			}
			else if (phimKep && (kiTu == UP))
			{
				if (dapAn == "")
				{
					dapAn = "D";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "A")
				{
					dapAn = "D";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "B")
				{
					dapAn = "A";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "C")
				{
					dapAn = "B";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "D")
				{
					dapAn = "C";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
			}
			else if (phimKep && (kiTu == DOWN))
			{
				if (dapAn == "")
				{
					dapAn = "A";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "A")
				{
					dapAn = "B";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "B")
				{
					dapAn = "C";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "C")
				{
					dapAn = "D";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
				else if (dapAn == "D")
				{
					dapAn = "A";
					outtextxy1(49, 22, dapAn, -1, 244);
					ToMauKhungDapAn(dapAn);
				}
			}
			else if ((kiTu >= 'a' && kiTu <= 'd') && !phimKep)
			{
				kiTu -= 32;
				dapAn = kiTu;
				outtextxy1(49, 22, dapAn, -1, 4);
				ToMauKhungDapAn(dapAn);
			}
			else if ((kiTu >= 'A' && kiTu <= 'D') && !phimKep)
			{
				dapAn = kiTu;
				outtextxy1(49, 22, dapAn, -1, 4);
				ToMauKhungDapAn(dapAn);
			}
			else if (kiTu == BACKSPACE && !dapAn.empty() && !phimKep)
			{
				dapAn = "";
				gotoxy(49, 22);
				cout << " ";
				ToMauKhungDapAn(dapAn);
			}
		}
		else
		{
			if (clock() >= endTime)
			{
				yeuCau = "HET GIO";
				break;
			}
			if ((endTime - clock()) / CLOCKS_PER_SEC < 30)
			{
				outtextxy1(61, 16, "Sap Het Thoi Gian", 0, rand() % (15 - 0 + 1) + 0);
			}
		}
	}
}
