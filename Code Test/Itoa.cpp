#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    const int coSo = 10;
    int num;
    char array[33];
   
    do
    {
        printf( "Nhap vao 1 so nguyen duong: " );
        scanf( "%d", &num );
    }
    while(num < 0);
   
    itoa(num, array, coSo);
   
    printf( "%d trong co so %d la: %s\n", num, coSo, array );
   
    return 0;
}
