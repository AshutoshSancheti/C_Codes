#include <stdio.h>

int main()
{
  int num;
  printf("Enter the number of rows:");
  scanf("%d",&num);
  printf("\n");
  int i,j,x;

  for(i=1;i<(2*num +1);i = i +2)
  {
    for(x=1;x<(2*num-i);x=x+2)
      printf(" ");
    for(j=1;j<=i;j++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  for(i=1;i<(num*2-1);i=i+2)
  {
    for(x=1;x<=i+1;x=x+2)
      printf(" ");
    for(j=1;j<=(num*2-i-2);j++)
    {
      printf("*");
    }
    printf("\n");
  }
return 0;
}

