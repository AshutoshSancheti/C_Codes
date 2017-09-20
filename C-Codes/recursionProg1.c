#include <stdio.h>
void print(int n);
int count = 0;
int arr[200];

int main()
{
   print(5);
   printf("\n%d",arr[4]);
}

void print(int n)
{
    int i , j ,k;
    i = n/2;
    j = n%2;
    k = n/2;

    if(i>1)
    {
        print(i);
    }
    else
    {
        printf("%d",i);
        arr[count] = i;
        count++;
    }

    printf("%d",j);
    arr[count] = j;
    count++;

    if(k>1)
    {
        print(k);
    }
    else
    {
        printf("%d",k);
        arr[count] = k;
        count++;
    }
}


