#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Nhap n";
	cin >> n;
	int *a = new int;
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
    delete[] a;
	return 0;
}
