#include <stdio.h>

int main()
{
  int num;
  printf("Enter the number of rows:");
  scanf("%d",&num);
  printf("\n");
  int i,j;
  
  for(i=num;i>0;i--)
  {
    for(j=1;j<=i;j++)
    {
      printf("%d",j);
    }
    printf("\n");
  }
  
  for(i=2;i<=num;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("%d",j);
    }
    printf("\n");
  }
return 0;
}
