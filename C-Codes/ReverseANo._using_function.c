//Reverse a number using A Function
#include <stdio.h>

int reverse(int);
int main()
{
    int rev = reverse(435);
    printf("%d",rev);
}

int reverse(int i)
{
    int reverse = 0;
    while(i!=0)
    {
       reverse = reverse*10;
        reverse = reverse + i%10;
      i = i/10;
    }
    return (reverse);
}
