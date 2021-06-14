#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

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
typedef struct List;
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
	p->data=x;
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

//8. Chen 1 node vao sau node q trong danh sach.
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

//9. Duyet danh sach.
void ProcessList(List l)
{
	Node *p = l.pHead;
	while(p!=NULL)
	{
		//
		p=p->pNext;
	}
}

//10. Tim kiem 1 phan tu co khoa x.
Node *Search(List l, int x)
{
	Node *p=l.pHead;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			return p;
		}
		p=p->pNext;
	}
	return NULL;
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
bool RemoveNode(List &l, int k)
{
	//- Duyet va tim.
	Node *p;
	p=l.pHead;
	Node *q;
	q=NULL;
	while(p!=NULL)
	{
		if(p->data==k)
		{
			break;
		}
		q=p;
		p=p->pNext;
	}
	//- Kiem tra.
	if(p==NULL)
	{
		cout<<"Khong tim thay k.";
		return false;
	}
	else if(q==NULL)
	{
		//- Thuc hien xoa phan tu dau danh sach la p.
		return true;
	}
	else
	{
		//- Thuc hien xoa phan tu p sau q.
		return true;
	}
}

//14. Huy toan bo danh sach.
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

//15. Dem so node trong danh sach.
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

//16. Trich phan tu dau danh sach.
Node *PickHead(List &l)
{
	Node *p;
	p=NULL;
	if(l.pHead==NULL)
	{
		p=l.pHead;
		l.pHead=l.pHead->pNext;
		p->pNext=NULL;
		if(l.pHead==NULL)
		{
			l.pTail=NULL;
		}
	}
	return p;
}

int main()
{
	
}
