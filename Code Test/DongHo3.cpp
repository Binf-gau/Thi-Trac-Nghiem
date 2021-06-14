//#include <thread>
//#include <iostream>
//#include "mylib.h"
//#include <cstring>
//#include <conio.h>
//using namespace std;
//int thoigian = 0;
//int dem= 0;
//string a;
//int x1 = 2, y1 = 2;
//int x2 = 50, y2 = 3;
//void func() {
//	while(thoigian<16)
//	{
//		gotoxy(x1,y1);
//		cout<<"thoi gian con lai: "<<thoigian<<endl;
//		Sleep(1000);
//		++thoigian;
//	}
//	gotoxy(x1,y1);
//	cout<<"Het gio";
//}
//
//void fail1() {
//    std::thread t(func);
//    // will fail when we try to destroy t since it is not joined or detached
//}
//
//void works1() {
//    std::thread t(func);
//    t.join();
//    cout <<"AAA";
//}
//
//void works2() {
//	
//    std::thread t(func);
//    t.detach();
//    int i=0;
//    char x;
//    while(thoigian<15)
//	{
//		if(_kbhit())
//		{
//			
//			x = _getch();
//			gotoxy(x2,y2);
//			cout<<i;
//			cout << x;
//			Sleep(500);
//			i++;
//		}
//		
////			if(kbhit())
////			{
////				t.detach();
////				cout <<"AAA";
////				Sleep(1000);
////				x = getch();
////				if(x == 27)
////				{
////					break;
////				}
////				else
////				{
////					a = x;
////				}
////			}
////		}
////		break;
//	}
//}
//
//int main() {
//    // fail1();
////     works1();
//     works2();
//}
