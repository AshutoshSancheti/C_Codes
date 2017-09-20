#include <stdio.h>

int main()
{
    int num, n, i ,j ,x,z;
    scanf("%d",&num);
    n = (num + 1)/2;

    for(i=1;i<=n;i++)
    {
        for(x=1;x<=(n -i);x++)
        {
            printf(" ");
        }
        for(j =1;j<=i;j++)
        {
            printf("%d",j);
        }
        for(z =i -1;z>0;z--)
        {
            printf("%d",z);
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--)
    {
        for(x=1;x<=(n -i);x++)
        {
            printf(" ");
        }
        for(j =1;j<=i;j++)
        {
            printf("%d",j);
        }
        for(z =i -1;z>0;z--)
        {
            printf("%d",z);
        }
        printf("\n");
    }
}
