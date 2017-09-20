#include <stdio.h>
#include <math.h>

long int factorial(int );
float cosine_sum(float angle, int N);

int main()
{
    int N;
    float angle;
    printf("Enter the angle in degrees:");
    scanf("%d", &angle);
    printf("\nEnter the no. of terms:");
    scanf("%d", &N);

    float sum = cosine_sum(angle, N);
    printf("\n%f", sum);
}

long int factorial(int n)
{
    long int fact =1;
    int i;
    if(n>0)
    {
        for(i = 1; i<=n;i++)
        {
            fact = fact*i;
        }
    }
    else if(n < 0)
        fact = 0;
    return fact;
}

float cosine_sum(float angle,int N)
{
    float sum = 0;
    int i,sign = 1;
    if(angle != 0.00)
    {
            for(i = 0; i<N;i++)
        {
           sum = sum + (sign*(pow(angle,2*i)))/factorial(2*i);
           sign *= (-1);
        }
    }
    else if(angle == 0)
        sum = 1;

    return (sum);
}

