#include<stdio.h>
int main(void)
{
    int i;
   int arr[7] = {1,-7,-7,3,2,9,-5};
      int arr[7] = {5};
    int first = 9, second =9 , third =9;
    //Write a for here to assign largest value of arr to first,second, third
    for(i=0;i<7;i++)
    {
        if(arr[i]<first)
        {
            third = second;
            second = first;
            first = arr[i];
        }

        else if((arr[i]<second) && (arr[i]!= first))
        {
            third = second;
            second = arr[i];
        }

        else if((arr[i]<third) && (arr[i]!= second))
        {
            third = arr[i];
        }

        else
        {
             continue;
        }

    }
    printf("%d %d %d",first,second,third);
}
