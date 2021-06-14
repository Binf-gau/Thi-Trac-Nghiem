#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string>
#include <windows.h>
#include <iomanip>
#include <fstream>

#include "mylib.h"

using namespace std;

const int LENGTH = 25;
const int ITEM = 10;
const int DONG = 5;
const int COT = 20 ;
const int UP = 72;
const int DOWN = 80;

char menu[ITEM][100]= 
{
  	"1. Nhap danh sach sinh vien                                 ",
  	"2. Xem danh sach sinh vien                                  ",
  	"3. Tim kiem 1 hoc vien bang ma so sinh vien                 ",
  	"4. Them 1 sinh vien vao vi tri bat ki                       ",
  	"5. Xoa 1 sinh vien khoi danh sach                           ",
  	"6. Sap xep lai danh sach theo thu tu ten sinh vien tang dan ",
	"7. Sap xep lai danh sach theo thu tu mssv tang dan          ",
 	"8. Mo file de ghi vao danh sach                             ",
 	"9. Luu danh sach sinh vien                                  ",
 	"10. Ket thuc chuong trinh                                   ",
};

void Normal()
{
	SetColor(15);
	SetBGColor(0);
}

void HighLight()
{
	SetColor(15);
	SetBGColor(1);
}

int vt = 0;

int MenuDong(char menu[ITEM][100])
{
  	Normal();
  	system("cls");   
  	int i; 
	for(i=0; i<ITEM; i++)
	{
		gotoxy(COT,DONG+i);
	    cout<<menu[i];
	}
	HighLight();
	gotoxy(COT,DONG+vt);
	cout<<menu[vt];
	char kytu;
	do
	{
		kytu=getch();
	  	if(kytu==0) 
			kytu=getch();
	  	switch(kytu) 
		{
	    	case UP: 
				{
					if(vt+1>1)
					{
		  		       	Normal();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];
		              	vt--;
		              	HighLight();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];		  			
	  				}
	  				else if(vt+1==1)
	  				{
	  					Normal();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];
		              	vt=ITEM-1;
		              	HighLight();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];
					}
	  				break;
				}		
	  		case DOWN:
		  		{
		  			if(vt+1<ITEM)
		  			{
		  		        Normal();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];
		              	vt++;
		              	HighLight();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];	  				
		  			}
		  			else if(vt+1==ITEM)
		  			{
		  		        Normal();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];
		              	vt=0;
		              	HighLight();
		              	gotoxy(COT,DONG+vt);
		              	cout<<menu[vt];	  				
		  			}
		  			break;
		  		}
	  		case 13: 
	  			{
	  				return vt+1;
				}
	  	} // End switch.
	}
	while(true);
}

void BaoLoi(char *s)
{
	HighLight();
	int x=wherex(), y=wherey();
	gotoxy(10,24);
	cout<<s;
	Sleep(1000);
	gotoxy(10,24);
	clreol();
	gotoxy(x,y);
}

void NhapChuoi(char *tieude, char *S) 
{
	cout<<tieude;
	fflush(stdin);
    do
		gets(S);
    while(strcmp(S,"")==0);	
}

bool XacNhan()
{
	HighLight();
	char kytu;
	cout<<"Ban that su muon xoa (Y/N): ";
	cin>>kytu;
	while(true)
	{
		if(kytu=='y' || kytu=='Y')
			return true;
		else if(kytu=='n' || kytu=='N')
			return false;
	};
}

//-------------------------------------

//1. Khai bao kieu du lieu cau truc SinhVien.
typedef struct SinhVien
{
	int mssv;
	char ho[40];
	char ten[10];
};

//2. Khai bao kieu du lieu cau truc Node.
typedef struct Node
{
	SinhVien data;
	Node *pNext;
};

//3. Khai bao kieu du lieu cau truc List.
typedef struct List
{
	Node *pHead;
	Node *pTail;
};

//4. Tao 1 node moi.
Node *GetNode(SinhVien sv)
{
	Node *p;
	p = new Node;
	if(p==NULL)
	{
		cout<<"Khong du bo nho.";
		return NULL;
	}
	p->data=sv;
	p->pNext=NULL;
	return p;
}

//5. Tao danh sach rong.
void Init(List &l)
{
	l.pHead=l.pTail=NULL;
}

//6. Gan 1 node moi vao dau danh sach.
void AddHead(List &l, Node *new_node)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=new_node;
	}
	else
	{
		new_node->pNext=l.pHead;
		l.pHead=new_node;
	}
}

//7. Gan 1 node moi vao cuoi danh sach.
void AddTail(List &l, Node *new_node)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=new_node;
	}
	else
	{
		l.pTail->pNext=new_node;
		l.pTail=new_node;
	}
}

//8. Tim kiem 1 node bang mssv.
Node *SearchMssv(List l, int x)
{
	Node *p=l.pHead;
	while(p!=NULL)
	{
		if(p->data.mssv==x)
		{
			return p;
		}
		p=p->pNext;
	}
	return NULL;
}

//9. Tim kiem 1 node bang so thu tu.
Node *SearchStt(List l, int k)
{
	int stt=0;
	Node *p=l.pHead;
	while(p!=NULL)
	{
		if(++stt==k-1)
		{
			return p;
		}
		p=p->pNext;
	}
	return NULL;
}

//10. Chen 1 node vao sau node q trong danh sach.
void AddAfter(List &l, Node *new_node, Node *q)
{
	if(q!=NULL)
	{
		new_node->pNext=q->pNext;
		q->pNext=new_node;
		if(q==l.pTail)
		{
			l.pTail=new_node;
		}
	}
}

//11. Xoa 1 node o dau cua danh sach.
bool RemoveHead(List &l)
{
	if(l.pHead==NULL)
	{
		return false;
	}
	Node *p;
	p=l.pHead;
	l.pHead=p->pNext;
	if(l.pHead==NULL)
	{
		l.pTail=NULL;
	}
	delete p;
	return true;
}

//12. Xoa 1 node o sau node q trong danh sach.
bool RemoveAfter(List &l, Node *q)
{
	if(q!=NULL && q->pNext!=NULL)
	{
		Node *p;
		p=q->pNext;
		q->pNext=p->pNext;
		if(p==l.pTail)
		{
			l.pTail=q;
		}
		delete p;
		return true;
	}
	else
	{
		return false;
	}
}

//13. Huy 1 phan tu co khoa la k.
int RemoveNode(List &l, int k)
{
	//- Duyet va tim.
	Node *p;
	p=l.pHead;
	Node *q;
	q=NULL;
	while(p!=NULL)
	{
		if(p->data.mssv==k)
		{
			break;
		}
		q=p;
		p=p->pNext;
	}
	//- Kiem tra.
	if(p==NULL)
	{
		return -1;
	}
	else if(q==NULL)
	{
		bool i=XacNhan();
		if(i==true)
		{
			RemoveHead(l);
			return 1;
		}
		else if(i==false)
		{
			return 0;
		}
	}
	else if(p!=NULL && q!=NULL)
	{
		bool i=XacNhan();
		if(i==true)
		{
			RemoveAfter(l,q);
			return 1;
		}
		else if(i==false)
		{
			return 0;
		}		
	}
}

//14. Dem so node trong danh sach.
int CountNode(List l)
{
	int count=0;
	Node *p;
	p=l.pHead;
	while(p!=NULL)
	{
		count++;
		p=p->pNext;
	}
	return count;
}

//15. Huy toan bo danh sach.
void RemoveList(List &l)
{
	Node *p;
	while(l.pHead!=NULL)
	{
		p=l.pHead;
		l.pHead=p->pNext;
		delete p;
	}
	l.pTail=NULL;
}

//-----------------------------------------

SinhVien Info(List l,SinhVien &sv)
{
	while(true)
	{
	  	cout<<"Nhap ma so: "; 
	   	cin>>sv.mssv;
	  	if(SearchMssv(l,sv.mssv)!=NULL)
	   	{
	       	BaoLoi("Ma so sinh vien bi trung");
	      	continue;
	   	}
	   	NhapChuoi("Nhap Ho: ",sv.ho);
	    NhapChuoi("Nhap Ten: ",sv.ten);
		break;
	}
}

void Input(List &l)
{
	cout<<"Nhap ma so <= 0 de ket thuc"<<endl;
	while(true)
	{
		SinhVien sv;
	  	cout<<"Nhap ma so: "; 
	   	cin>>sv.mssv;
	   	if(sv.mssv<=0) 
	   		break;
	  	if(SearchMssv(l,sv.mssv)!=NULL)
	   	{
	       	BaoLoi("Ma so sinh vien bi trung");
	      	continue;
	   	}
	   	NhapChuoi("Nhap Ho: ",sv.ho);
	    NhapChuoi("Nhap Ten: ",sv.ten);
	    if(GetNode(sv)!=NULL)
	    	AddTail(l,GetNode(sv));
	    else
	    {
	    	BaoLoi("Khong du bo nho de tao node moi");
		}
	}
}

void ThongTinSV(List l, int maso) 
{
  	if(SearchMssv(l,maso)==NULL) 
  		BaoLoi("Ma so sinh vien khong co trong danh sach");
  	else
	{ 	
		cout<<"\nThong tin cua sinh vien co mssv: "<<maso<<endl;
		cout<<"Ho: "<<SearchMssv(l,maso)->data.ho;
		cout<<"\nTen: "<<SearchMssv(l,maso)->data.ten;
        getch();
	}
}

void Swap(SinhVien &a, SinhVien &b)
{
	SinhVien temp=a;
	a=b;
	b=temp;
}

void SapXepMssv(List &l)
{
	Node *p=l.pHead;
	if(p!=NULL)
	{
		for(Node *p=l.pHead; p->pNext!=NULL; p=p->pNext)
		{
			for(Node *q=p->pNext; q!=NULL; q=q->pNext)
			{
				if(p->data.mssv > q->data.mssv)
				{
					Swap(p->data,q->data);
				}
			}
		}
		BaoLoi("Da sap xep xong");
	}
	else
		BaoLoi("Hien khong co sinh vien nao trong danh sach");
}

void SapXepTen(List &l)
{
	Node *p, *q;
	p=l.pHead;
	if(p!=NULL)
	{
		for(p=l.pHead; p->pNext!=NULL; p=p->pNext)
		{
			for(q=p->pNext; q!=NULL; q=q->pNext)
			{
				if(strcasecmp(p->data.ten,q->data.ten)>0)
				{
					Swap(p->data,q->data);
				}
				else if(strcasecmp(p->data.ten,q->data.ten)==0)
				{
					if(strcasecmp(p->data.ho,q->data.ho)>0)
					{
						Swap(p->data,q->data);
					}
				}
			}		
		}
		BaoLoi("Da sap xep xong");
	}
	else
		BaoLoi("Hien khong co sinh vien nao trong danh sach");
}

void SaveFile(List &l) 
{
	/* Mo tap tin */
	ofstream fileOut;
	fileOut.open("DSSV.DAT",ios::out);
	Node *p=l.pHead;
	for(p; p!=NULL; p=p->pNext)
	{
		fileOut<<p->data.mssv<<" "<<p->data.ho<<" "<<p->data.ten;
		if(p->pNext!=NULL)
			fileOut<<endl;
	}
	/* Dong tap tin */
	fileOut.close();
 	BaoLoi("Da ghi xong danh sach vao file");
}

void OpenFile(List &l)
{
	/* Mo tap tin */
	ifstream fileIn;
	fileIn.open("DSSV.DAT",ios::in);
	while(!fileIn.eof())
	{
		SinhVien sv;
		fileIn >> sv.mssv >> sv.ho >> sv.ten;
		AddTail(l,GetNode(sv));
	}
	/* Dong tap tin */
	fileIn.close();
 	BaoLoi("Da load xong danh sach vao bo nho");
}
//----------------------------------------------------------------------

void ProcessList(List l)
{
	system("cls");
	SetColor(15);
	SetBGColor(0);
	gotoxy(15,1);
	cout<<"===== DANH SACH SINH VIEN =====";
	gotoxy(10,3);
	cout<<"+----------+---------------+-----------+";
	gotoxy(10,4);
	cout<<"|   MSSV   |       HO      |    TEN    |";
	gotoxy(10,5);
	cout<<"+----------+---------------+-----------+";
	int i=0;
	Node *p=l.pHead;
	while(p!=NULL)
	{
		i++;
		gotoxy(10,5+i);
		cout<<"|          |               |           |";
		gotoxy(15,5+i);
		cout<<p->data.mssv;
		gotoxy(25,5+i);
		cout<<p->data.ho;
		gotoxy(41,5+i);
		cout<<p->data.ten;
		i++;
		gotoxy(10,5+i);
		cout<<"+----------+---------------+-----------+";
		p=p->pNext;
	}
	getch();
}

int main ()
{ 
  	system("cls");
  	int chon;  
	List l; 
	Init(l);
	int maso; 
	SinhVien sv;
  	do
  	{
	    chon=MenuDong(menu);
	    Normal();
	    system("cls");
	    switch(chon)
		{
		    case 1:
				{
					Input(l); 
					break;
				} 
		    case 2: 
			    {
			    	ProcessList(l); 
					break;	
				}
		    case 3: 
				{ 
					fflush(stdin);
					cout<<"\nNhap ma so cua sinh vien can tim: ";
			      	cin>>maso;
			      	ThongTinSV(l,maso);
					break;
			    }
			case 4:
				{
					fflush(stdin);
					int k;
	            	cout<<"Nhap vi tri them: ";
	            	cin>>k;
	            	if (k<=1)
	            	{
	            		Info(l,sv);
	            		AddHead(l,GetNode(sv));	
					}
	            	else if(k>CountNode(l))
	            	{
	            		Info(l,sv);
	            		AddTail(l,GetNode(sv));	
					}
					else
					{
		                Info(l,sv);
		                AddAfter(l,GetNode(sv),SearchStt(l,k));
	           		}
	            	getch();
	            	break;
				}
			case 5:
				{ 
					fflush(stdin);
					cout<<"\nNhap ma so cua sinh vien can xoa: ";
			      	cin>>maso;
			      	int i=RemoveNode(l,maso);
			      	if(i==-1)
			      	{
			      		BaoLoi("Khong tim thay sinh vien");
					}
					else if(i==0)
					{
						BaoLoi("Chua xoa");
					}
					else if(i==1)
					{
						BaoLoi("Da xoa");
					}
					break;
			    }    
			case 6:
				{
					SapXepTen(l);
					break;
				}
			case 7:
				{
					SapXepMssv(l);					
					break;
				}
			case 8: 
			    {
			    	RemoveList(l);
			    	OpenFile(l); 
					break;
				}
		    case 9: 
			    {
			    	SaveFile(l); 
					break;
				}
		    case ITEM: 
			    {
			    	return 0;
				}
   		}
  	}
	while(true);
  	return 0;
}
