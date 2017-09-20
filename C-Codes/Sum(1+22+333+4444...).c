#include <stdio.h>

int main()
{
    int num,sum =0,term,i,j,state;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        if(i== num)
        {
            state =0;
        }
        int weight =1;
        term=0;
        for(j=1;j<=i;j++)
        {
            term = term + i*weight;
            weight  = weight*10;
        }
        printf("%d ",term);
        if(state != 0)
        {
            printf("+ ");
        }
        sum += term;
    }
    printf("= %d",sum);
}
