#include <iostream>
#include <ctime> // time_t
#include <cstdio>
#include <windows.h>
using namespace std;
int function(clock_t b, clock_t t)
{
     for (long int i = 0; i < 400; i++)
     {
          cout << i;
          Sleep(1);
          t= clock();
  	     double ttt = difftime (t,b);
  	     if(ttt>=3.0)
  	     {
  	     	double thoigian = (double) (t-b)/CLOCKS_PER_SEC;
  			cout<<"Thoi gian chay truong trinh la: "<<thoigian<<"s" ;
  	     	exit(1);
  		}
     }
}

int main()
{
     clock_t b, e, t; // time_t is a datatype to store time values.
     b = clock();
     function(b, t);
     e = clock();
     double difference = (double)(e - b) / CLOCKS_PER_SEC;
     cout << "Thoi gian chay truong trinh la: " << difference << "s";
     return 0;
}
