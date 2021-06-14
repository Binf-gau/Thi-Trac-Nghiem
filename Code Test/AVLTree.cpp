#include <iostream>
#include <cstring>
using namespace std;

#define LH -1 //cay con trai cao hon
#define EH 0  //hai cay con bang nhau
#define RH 1  //cay con phai cao hon

// typedef struct Data
// {
// 	int key;
// };

//1. khai báo
typedef struct AVLNode
{
	int balFactor; //chi so can bang
	int key;
	AVLNode* pLeft;
	AVLNode* pRight;
};

typedef AVLNode* AVLTree;

//2. quay đơn left-left
void RotateLL(AVLTree &T)
{
	AVLTree T1 = T->pLeft;
	T->pLeft = T1->pRight;
	T1->pRight = T;
	switch (T1->balFactor)
	{
	case LH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = LH;
		T1->balFactor = RH;
		break;
	}
	T = T1;
}

//3. quay đơn right-right
void RotateRR(AVLTree &T)
{
	AVLTree T1 = T->pRight;
	T->pRight = T1->pLeft;
	T1->pLeft = T;
	switch (T1->balFactor)
	{
	case RH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = RH;
		T1->balFactor = LH;
		break;
	}
	T = T1;
}

//4. quay kép left-right
void RotateLR(AVLTree &T)
{
	AVLTree T1 = T->pLeft;
	AVLTree T2 = T1->pRight;
	T->pLeft = T2->pRight;
	T2->pRight = T;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	switch (T2->balFactor)
	{
	case LH:
	{
		T->balFactor = RH;
		T1->balFactor = EH;
		break;
	}
	case EH:
	{
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	}
	case RH:
	{
		T->balFactor = EH;
		T1->balFactor = LH;
		break;
	}
	}
	T2->balFactor = EH;
	T = T2;
}

//5. quay kép right-left
void RotateRL(AVLTree &T)
{
	AVLTree T1 = T->pRight;
	AVLTree T2 = T1->pLeft;
	T->pRight = T2->pLeft;
	T2->pLeft = T;
	T1->pLeft = T2->pRight;
	T2->pRight = T1;
	switch (T2->balFactor)
	{
	case RH:
	{
		T->balFactor = LH;
		T1->balFactor = EH;
		break;
	}
	case EH:
	{
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	}
	case LH:
	{
		T->balFactor = EH;
		T1->balFactor = RH;
		break;
	}
	}
	T2->balFactor = EH;
	T = T2;
}

//6. cân bằng cây khi cây bị lệch về bên trái
int BalanceLeft(AVLTree &T)
{
	AVLTree T1 = T->pLeft;
	switch (T1->balFactor)
	{
	case LH:
	{
		RotateLL(T);
		return 2;
	}
	case EH:
	{
		RotateLL(T);
		return 1;
	}
	case RH:
	{
		RotateLR(T);
		return 2;
	}
	}
	return 0;
}

//7. cân bằng cây khi cây bị lệch về bên phải
int BalanceRight(AVLTree &T)
{
	AVLTree T1 = T->pRight;
	switch (T1->balFactor)
	{
	case LH:
	{
		RotateRL(T);
		return 2;
	}
	case EH:
	{
		RotateRR(T);
		return 1;
	}
	case RH:
	{
		RotateRR(T);
		return 2;
	}
	}
	return 0;
}

//8. thêm 1 phần tử trên cây AVL
int InsertNode(AVLTree &T, int x)
{
	int res;
	if (T)
	{
		if (T->key == x)
		{
			return 0; //đã có
		}
		if (T->key > x)
		{
			res = InsertNode(T->pLeft, x);
			if (res < 2)
			{
				return res;
			}
			switch (T->balFactor)
			{
			case RH:
			{
				T->balFactor = EH;
				return 1;
			}
			case EH:
			{
				T->balFactor = LH;
				return 2;
			}
			case LH:
			{
				BalanceLeft(T);
				return 1;
			}
			}
		}
		else
		{
			res = InsertNode(T->pRight, x);
			if (res < 2)
			{
				return res;
			}
			switch (T->balFactor)
			{
			case LH:
			{
				T->balFactor = EH;
				return 1;
			}
			case EH:
			{
				T->balFactor = RH;
				return 2;
			}
			case RH:
			{
				BalanceRight(T);
				return 1;
			}
			}
		}
	}
	T = new AVLNode;
	if (T == NULL)
	{
		return -1; //thiếu bộ nhớ
	}
	T->key = x;
	T->balFactor = EH;
	T->pLeft = T->pRight = NULL;
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
			return BalanceRight(q); //??? p or q
		}
		}
	}
	else
	{
		p->key = q->key;
		p = q;
		q = q->pRight;
		return 2;
	}
}

//9. hủy 1 phần tử trên cây AVL
int XoaCauHoiThi(AVLTree &T, int x)
{
	int res;
	if (T == NULL)
	{
		return 0;
	}
	if (T->key > x)
	{
		res = XoaCauHoiThi(T->pLeft, x);
		if (res < 2)
		{
			return res;
		}
		switch (T->balFactor)
		{
		case LH:
		{
			T->balFactor = EH;
			return 2;
		}
		case EH:
		{
			T->balFactor = RH;
			return 1;
		}
		case RH:
		{
			return BalanceRight(T);
		}
		}
	}
	else if (T->key < x)
	{
		res = XoaCauHoiThi(T->pRight, x);
		if (res < 2)
		{
			return res;
		}
		switch (T->balFactor)
		{
		case RH:
		{
			T->balFactor = EH;
			return 2;
		}
		case EH:
		{
			T->balFactor = LH;
			return 1;
		}
		case LH:
		{
			return BalanceLeft(T);
		}
		}
	}
	else //T->key == x
	{
		AVLTree p = T;
		if (T->pLeft == NULL)
		{
			T = T->pRight;
			res = 2;
		}
		else if (T->pRight == NULL)
		{
			T = T->pLeft;
			res = 2;
		}
		else //T có cả 2 con
		{
			res = TimPhanTuTheMang(p, T->pRight);
			if (res < 2)
			{
				return res;
			}
			switch (T->balFactor)
			{
			case RH:
			{
				T->balFactor = EH;
				return 2;
			}
			case EH:
			{
				T->balFactor = LH;
				return 1;
			}
			case LH:
			{
				return BalanceLeft(T);
			}
			}
		}
		delete p;
		return res;
	}
}

void NLR(AVLTree T, int &sl)
{
	if (T != NULL)
	{
		sl++;
		NLR(T->pLeft,sl);
		NLR(T->pRight,sl);
	}
}

int main()
{
	AVLTree T = new AVLNode;
	for (int i = 1; i <= 20; i++)
	{
		InsertNode(T, i);
	}
	int sl = 0;
	NLR(T,sl);
	cout<<sl;
	return 0;
}
