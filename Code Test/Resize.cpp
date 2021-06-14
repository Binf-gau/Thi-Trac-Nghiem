#include <iostream>
#include <Windows.h>
#include "mylib.h">
using namespace std;

void SetFontSize(int width, int height)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = width;                   // Width of each character in the font
	cfi.dwFontSize.Y = height;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
int main () {
	FullScreen();
	SetFontSize(12,10);
	cout<< "Font";
	getch();
}
