#include <stdio.h>

int main()
{
  int binary;
  printf("Enter a 5 digit binary number:");
  scanf("%d",&binary);
  int sum = 0, mag,i,j;
 
  for(i=0;i<5;i++)
  { 
    mag=1;
    for(j=0;j<i;j++)
    {
      mag = mag*2;
    }
 
    sum = sum + (binary%10)*mag;
    binary = binary/10;
  }
  printf("%d",sum);
return 0;
}
  

