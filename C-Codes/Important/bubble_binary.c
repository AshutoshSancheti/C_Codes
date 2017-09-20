#include <stdio.h>

void bubble_sort(int arr1[],int k,int arr2[]);
int binary_search(int arr1[],int k,int key);

int main()
{
  int arr1[8] = {3,5,1,6,2,7,8,4};
  int arr2[8];
  int index, key, k;
  key = 5;
  k = 8;
  bubble_sort(arr1, k, arr2);
  index = binary_search(arr1, k, key);
  printf("%d ",index);
}

int binary_search(int arr1[],int k,int key)
{
  int low = 0, high = (k-1),mid,index,c =0;
  while(low<=high)
  {
    mid = (low+high)/2;
    if(key == arr1[mid])
    {
      index = mid;
      c =1;
      break;
    }

    else if(key<arr1[mid])
    {
       high = mid -1;
    }
    else
      low = mid+1;
  }

  if(c ==1)
    return index;
  else
    return -1;
}

void bubble_sort(int arr1[],int k,int arr2[])
{
  int i;
  int j,x;
  for(x =0;x<k;x++)
  {  arr2[x] = arr1[x];
     printf("%d ",arr2[x]);
  }
  printf("\n");

  for(i=0;i<k;i++)
  {
    for(j = k-1;j>i;j--)
    {
      if(arr2[j]<arr2[j-1])
      {
        int temp;
        temp = arr2[j];
        arr2[j] = arr2[j-1];
        arr2[j-1] = temp;
       }
     }
  }
  for(x =0;x<k;x++)
   printf("%d ",arr2[x]);
  printf("\n");
}


