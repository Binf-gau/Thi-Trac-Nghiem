#pragma once
#include "LIB_linh_tinh.h"

typedef struct MangRandomID
{
    int *mangRandomID;
    int soLuong ;
};

void SwapID(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void KhoiTaoMangRandomID(MangRandomID &mri, int soLuong)
{
    mri.mangRandomID = new int[soLuong];
}

int RandomID(MangRandomID &mri)
{
    srand(time(NULL));
    int chiSoRandom = rand() % ( mri.soLuong -1 - 0 + 1) + 0;
    SwapID(mri.mangRandomID[chiSoRandom], mri.mangRandomID[mri.soLuong -1]);
    mri.soLuong--;
    return mri.mangRandomID[mri.soLuong];
}

void HuyMangRandomID(MangRandomID &mri)
{
    delete[] mri.mangRandomID;
}

void DocMangRandomID(MangRandomID &mri)
{
	ifstream fileIn;
	fileIn.open("Data\\MangRandomID.txt", ios::in);
	fileIn >> mri.soLuong;
	KhoiTaoMangRandomID(mri, mri.soLuong);
	for (int i = 0; i < mri.soLuong; i++)
	{
		fileIn >> mri.mangRandomID[i];
	}
	fileIn.close();
}
void LuuMangRandomID(MangRandomID mri)
{
	ofstream fileOut;
	fileOut.open("Data\\MangRandomID.txt", ios::out);
	fileOut << mri.soLuong << endl;
	for (int i = 0; i < mri.soLuong - 1; i++)
	{
		fileOut << mri.mangRandomID[i] << endl;
	}
	fileOut << mri.mangRandomID[mri.soLuong - 1];
	fileOut.close();
}