#include <iostream>
#include <thread>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool stop = 1;
struct Hour
{
	int hour;
	int minute;
	int second;
};

char inToA(int k)
{
	switch (k)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	default:
		break;
	}
}

void insertarray(char *h, Hour *j)
{
	int bait = 0;
	bait = j->second;
	h[7] = inToA(bait % 10);
	h[6] = inToA(bait /= 10);

	bait = j->minute;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);

	bait = j->hour;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);
}

bool changetime(Hour *h)
{
	if (h->second > 0)
		--h->second;
	else if (h->minute > 0)
	{
		h->second = 59;
		--h->minute;
	}
	else if (h->hour > 0)
	{
		--h->hour;
		h->minute = 59;
		h->second = 59;
	}
	else
		return 0;
	return 1;
}

//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char *Arraych, int row, int col, int x, int y, int color)
{
	CHAR_INFO *charater = new CHAR_INFO[row * col];
	for (int i = 0; i < row * col; i++)
	{
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = {col, row};
	COORD pos = {0, 0};
	SMALL_RECT earea = {x, y, x + col - 1, y + row - 1};
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}

void printClock(int thoiGian)
{
	Hour h = {0, 0, 0};
	h.hour = thoiGian/60;
	h.minute = thoiGian%60;
	h.second = 0;
	char a[8] = {'0', '0', ':', '0', '0', ':', '0', '0'};
	while (stop)
	{
		if (!changetime(&h))
			stop = 0;
		insertarray(a, &h);
		WriteBlockChar(a, 1, 8, 70, 3, 0x004 | 0x060);
		Sleep(1000);
	}
	return;
}

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//void close(DWORD evt) {
//	if (evt == CTRL_CLOSE_EVENT) stop = 0;
//}
char timedCharInput(unsigned sec)
{
	clock_t stop = clock() + sec * CLOCKS_PER_SEC;
	char ret = '\0';
	while (clock() <= stop)
	{
		if (_kbhit())
		{
			char guess = _getch();
			if (guess == '\b') // || guess == 0x7f)
			{
				if (ret)
					std::cout << "\b \b";
				ret = '\0';
			}
			else if (guess == '\r' || guess == '\n')
			{
				std::cout << '\n';
				return ret;
			}
			else
			{
				if (ret)
					std::cout << "\b \b";
				std::cout << guess;
				ret = guess;
			}
		}
		//        Sleep(16);
	}
	std::cout << '\n';
	return '\0';
}

int main()
{
	//	SetConsoleCtrlHandler((PHANDLER_ROUTINE)close, TRUE);
	thread clock;
	int i = 0;
	int thoiGian;
	cout << "Nhap thoi gian(phut) nhan dap an: ";
	cin >> thoiGian;
	for (i; i < 10; i++)
	{
		stop = 1;
		clock = thread(printClock,thoiGian);
		std::cout << "Nhap dap an thu " << i + 1 << ": ";
		char guess = timedCharInput(10);
		if (!guess)
			std::cout << "Het gio.\n";
		else
			std::cout << "Dap an cua ban la: " << guess << '\n';
		stop = 0;
		clock.join();
	}
	return 0;
}