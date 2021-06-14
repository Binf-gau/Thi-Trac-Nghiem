//#include "graphics.h"
//#include "mylib.h"
////#include "colors.h"
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <thread>
//
//
//
//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77
//#define ESC 27
//#define ENTER 13
//
//using namespace std;
//int t = 15;
//char c;
//int pos=0;
//
//void outnumbxy(int x, int y, int tmp){
//	string s=to_string(tmp);
//  	char *cr = (char *)s.c_str();
//  	outtextxy(x,y,cr);
//  	delete[] cr;
//}
//
//void CLOCK(int tmp){
//	while(tmp>0){
//		setcolor (WHITE);
//		outtextxy(0,0,"  ");
//		Sleep(1000);
//		outnumbxy(0,0,tmp);
//		tmp--;
//		t=tmp;
//	}
//	outtextxy(0,0,"TIME OVER!!");
//}
//char text[100];
////void manhinh1(){
////	
////	setbkcolor (DARKGRAY);
////	// ve khung
////	setcolor (WHITE);
////	setfillstyle (SOLID_FILL, WHITE);
////	bar(10,10,800,500);
////	setfillstyle (SOLID_FILL, DARKGRAY);
////	bar(12,12,798,498);
////	
////	
////	setcolor (WHITE);
////	setfillstyle (SOLID_FILL, WHITE);
////	bar(25,25,500,50);
////	setfillstyle (SOLID_FILL, DARKGRAY);
////	bar(27,27,498,48);
////	
////	setcolor (WHITE);
////	setfillstyle (SOLID_FILL, WHITE);
////	bar(25,55,500,80);
////	setfillstyle (SOLID_FILL, DARKGRAY);
////	bar(27,57,498,78);
////	outtextxy(50,50,text);
////	
////	while(1){
////		c= getch();
////		if(c==ENTER) break;
////		text[pos]=c;
////		pos++;
////		outtextxy(50,50,text);
////	}
////}
//
//
//int main(){	
//	
//	int x=0,y=0;
//	int tmp=t;
//	int pos=0;
//	int mh, mode;
//	mh=0;
//	mode=0;
//	
//	initgraph(&mh, &mode,"");
//	thread clock(CLOCK, tmp);
//	clock.detach();
//	getch();
//	closegraph();
//
//    return 0;
//
//}
