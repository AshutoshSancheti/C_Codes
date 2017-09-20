#include <stdio.h>

int main()
{
    int binary,dec = 0,weight=1 ;
    scanf("%d",&binary);
    while(binary>0)
    {
        dec = dec + (binary%10)*weight;
        binary = binary/10;
        weight = weight*2;
    }
    printf("%d",dec);
}
