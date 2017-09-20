//Program for largest three nos in an array
#include<stdio.h>
int main(void)
{
    int i,n,arr[7] = {0};
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter %d values: \n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int first = 0, second = 0, third = 0;
    for(i=0;i<7;i++)
    {
        if(arr[i]>first)
        {
            third = second;
            second = first;
            first = arr[i];
        }

        else if(arr[i]>second)
        {
            third = second;
            second = arr[i];
        }

        else if(arr[i]>third)
        {
            third = arr[i];
        }

        else
        {

        }
            continue;
    }
    printf("%d %d %d",first,second,third);
}
