#include <stdio.h>

void add_price(int arr[], int *size, int new_price);
void remove_price(int arr[],int *size, int delete_price);

int main()
{
    int arr[200] = {0};
    int size,i,new_price,delete_price;

    size = 5;
    arr[0] = 234;
    arr[1] = 357;
    arr[2] = 567;
    arr[3] = 683;
    arr[4] = 786;

    printf("Enter a new price:");
    scanf("%d",&new_price);
    add_price(arr, &size, new_price);

    for(i=0;i<size;i++)
        printf("%d ", arr[i]);

    printf("\nEnter the price to be deleted:");
    scanf("%d",&delete_price);
    remove_price(arr, &size, delete_price);
    for(i=0;i<size;i++)
        printf("%d ", arr[i]);
}

void add_price(int arr[], int *size, int new_price)
{
    arr[*size] = new_price;
    *size = *size + 1;
    int i, k;
    k = *size;

    for(i=(k-1);i>=0;i--)
    {
        if(arr[i]<arr[i-1])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
        else
            break;
    }
}

void remove_price(int arr[],int *size, int delete_price)
{
    int index, i;
    for(i=0;i<*size;i++)
    {
        if(delete_price == arr[i])
            index = i;
    }

    for(i = index;i<*size;i++)
        arr[i] = arr[i+1];
   *size = *size - 1;                     //(*size)--; can also be used
}

