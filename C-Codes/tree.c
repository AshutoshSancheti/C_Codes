#include<stdio.h>
void sum(int i)
{
    if(i<0)
        printf("%d",i);
    else
       {
           sum(--i);
            printf("%d",i);
}}
int main()
{
    sum(6);
}
