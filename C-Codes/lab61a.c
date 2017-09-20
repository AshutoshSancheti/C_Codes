#include <stdio.h>

int main()
{
  int num;
  printf("Enter the number of rows:");
  scanf("%d",&num);
  printf("\n");
  int i,j;
  
  for(i=1;i<=num;i++)
  { 
    for(j=1;j<=i;j++)
    {
      printf("%d ",j);
    }
    printf("\n");
   }
  return 0;
} 
