#include <stdio.h>

int main()
{
    int a[8],b[8],i,n = 0;
    a[8] = {1,2,3,4,5,6,7,8};
    for(i=0;i<8;i++)
    {
        if(a[i]%2 == 0)
        {
            b[n] = a[i];
            n++;
        }

    }

    for(i=7;i>=0;i--)
    {
       if(a[i]%2 !=0)
       {
           b[n] = a[i];
           n++;
       }
    }

    for(i=0;i<8;i++)
    {
        printf("%d",b[i]);
    }

}
