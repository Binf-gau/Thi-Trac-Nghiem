#include <iostream>
using namespace std;

//1. Khai bao
struct nodetype
{
	int key;
	int info;
	int bf;
	struct nodetype *left, *right;
};
struct nodetype *NODEPTR;

//2. Them nut

//- phep xoay trai
NODEPTR Rotate_Left(NODEPTR root)
{
	NODEPTR p;
	if (root == NULL)
		cout << "Khong the xoay trai vi cay rong.";
	else if (root->right == NULL)
		cout << "Khong the xoay trai vi khong co nut con ben phai";
	else
	{
		p = root->right;
		root->right = p->left;
		p->left = root;
	}
	return p;
}

//- phep xoay phai
NODEPTR Rotate_Right(NODEPTR ya)
{
	NODEPTR s;
	if (ya->left == NULL)
		cout << "Khong the xoay phai vi cay con rong";
	else if (ya->left == NULL)
		cout << "Khong the xoay phai vi khong co nut con ben trai";
	else
	{
		s = ya->left;
		ya->left = s->right;
		s->right = ya;
	}
	return s;
}

//- them nut
void Insert(NODEPTR &pavltree, int x, int a) //khóa là x, nội dung là a
{
	NODEPTR fp, p, q, fya, ya, s;
	/*  fp là nút cha của p
		q là nút con của p
		ya là nút trước gần nhất có thể mất cân bằng
		fya là nút cha của ya
		s là nút con của ya theo hướng mất cân bằng */
	int imbal;
	/*  imbal = 1 nếu bị lệch về nhánh trái
		imbal = -1 nếu bị lệch về nhánh phải */

	/* khởi động các giá trị */
	fp = NULL;
	p = pavltree;
	fya = NULL;
	ya = p;
	/* tìm nút fp, ya và fya, nút mới thêm vào là nút lá của nút fp */
	while (p != NULL)
	{
		if (x == p->key) //bị trùng khóa
			return;
		if (x < p->key)
			q = p->left;
		else
			q = p->right;
		if (q != NULL)
			if (q->bf != 0) //trường hợp chỉ số cân bằng của q là 1 hay -1
			{
				fya = p;
				ya = q;
			}
		fp = p;
		p = q;
	}

	/* thêm nút mới (nút lá) là con của nút fp */
	q = new node; //cấp phát vùng nhớ
	q->key = x;
	q->info = a;
	q->bf = 0;
	q->left = NULL;
	q->right = NULL;
	if (x < fp->key)
		fp->left = q;
	else
		fp->right = q;

	/* hiệu chỉnh chỉ số cân bằng của tất cả các nút giữa ya và q, nếu bị lệch về phía trái thì chỉ số cân bằng của tất cả các nút giữa ya và q đều là 1, nếu bị lệch về phía phải thì chỉ số cân bằng của tất cả các nút giữa ya và q đều là -1 */
	if (x < ya->key)
		p = ya->left;
	else
		p = ya->right;
	s = p; //s là con của nút ya
	while (p != q)
	{
		if (x < p->key)
		{
			p->bf = 1;
			p = p->left;
		}
		else
		{
			p->bf = -1;
			p = p->right;
		}
	}

	/* xác định hướng lệch */
	if (x < ya->key)
		imbal = 1;
	else
		imbal = -1;

	if (ya->bf == 0)
	{
		ya->bf = imbal;
		return;
	}
	if (ya->bf != imbal)
	{
		ya->bf = 0;
		return;
	}

	if (s->bf == imbal) //Trường hợp xoay đơn
	{
		if (imbal == 1) //Xoay phải
			p = Rotate_Right(ya);
		else //Xoay trái
			p = Rotate_Left(ya);
		ya->bf = 0;
		s->bf = 0;
	}
	else //Trường hợp xoay kép
	{
		if (imbal == 1) //Xoay kép trái - phải
		{
			ya->left = Rotate_Left(s);
			p = Rotate_Right(ya);
		} //Xoay kép phải - trái
		else
		{
			ya->right = Rotate_Left(s);
			p = Rotate_Left(ya);
		}
		if (p->bf == 0) //Trường hợp p là nút mới thêm vào
		{
			ya->bf = 0;
			s->bf = 0;
		}
		else if (p->bf == imbal)
		{
			ya->bf = -imbal;
			s->bf = 0;
		}
		else
		{
			ya->bf = 0;
			s->bf = imbal;
		}
		p->bf = 0;
	}

	if (fya == NULL)
		pavltree = p;
	else if (ya = fya->right)
		fya->right = p;
	else
		fya->left = p;
}
void Create_AVLTree(NODEPTR &root)
{
	int khoa, noidung;
	char so[10];
	NODEPTR p;
	do
	{
		cout << "Nhap khoa: ";
		gets(so);
		khoa = atoi(so);
		if (khoa != 0)
		{
			cout << "Nhap noi dung: ";
			gets(so);
			noidung = atoi(so);
			if (root == NULL)
			{
				p = New_Node();
				p->key = khoa;
				p->info = noidung;
				p->bf = 0;
				p->left = NULL;
				p->right = NULL;
				root = p;
			}
			else
				Insert(root, khoa, noidung);
		}
	} while (khoa != 0);
}
int main()
{
}
