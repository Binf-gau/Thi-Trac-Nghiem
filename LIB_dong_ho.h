#pragma once
#include "LIB_linh_tinh.h"
#include <thread>

bool runDongHo = true;

struct Hour
{
    int hour;
    int minute;
    int second;
};

char Itoa(int k)
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

void DongHoChay(char *h, Hour *j)
{
    int bait = 0;
    bait = j->second;
    h[7] = Itoa(bait % 10);
    h[6] = Itoa(bait /= 10);

    bait = j->minute;
    h[4] = Itoa(bait % 10);
    h[3] = Itoa(bait /= 10);

    bait = j->hour;
    h[1] = Itoa(bait % 10);
    h[0] = Itoa(bait /= 10);
}

bool ThayDoiThoiGian(Hour *h)
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

void DongHoDemNguoc(int thoiGian)
{
    Hour h = {0, 0, 0};
    h.hour = thoiGian / 60;
    h.minute = thoiGian % 60;
    h.second = 0;
    char a[8] = {'0', '0', ':', '0', '0', ':', '0', '0'};
    while (runDongHo)
    {
        if (!ThayDoiThoiGian(&h))
            runDongHo = false;
        DongHoChay(a, &h);
        WriteBlockChar(a, 1, 8, 110, 21, (79 << 4)); //(145,210,78)
        Sleep(1000);
    }
    return;
}

// char timedCharInput(unsigned sec)
// {
//     clock_t runDongHo = clock() + sec * CLOCKS_PER_SEC;
//     char ret = '\0';
//     while (clock() <= runDongHo)
//     {
//         if (_kbhit())
//         {
//             char guess = _getch();
//             if (guess == '\b') // || guess == 0x7f)
//             {
//                 if (ret)
//                     cout << "\b \b";
//                 ret = '\0';
//             }
//             else if (guess == '\r' || guess == '\n')
//             {
//                 cout << '\n';
//                 return ret;
//             }
//             else
//             {
//                 if (ret)
//                     cout << "\b \b";
//                 cout << guess;
//                 ret = guess;
//             }
//         }
//         //        Sleep(16);
//     }
//     cout << '\n';
//     return '\0';
// }

// void CountDown(int thoiGian)
// {
//     //	SetConsoleCtrlHandler((PHANDLER_ROUTINE)close, TRUE);

//     for (int i = 0; i < 10; i++)
//     {
//         runDongHo = 1;
//         clock = thread(printClock, thoiGian);
//         cout << "Nhap dap an thu " << i + 1 << ": ";
//         char guess = timedCharInput(100);
//         if (!guess)
//             cout << "Het gio.\n";
//         else
//             cout << "Dap an cua ban la: " << guess << '\n';
//         runDongHo = 0;
//         clock.join();
//     }
//     return 0;
// }
