
#include <stdio.h>
#include <math.h>

int flag = 1;
void print(int arr[], int);
int main()
{
    int num,index =0, size,i;
    printf("Input the number:");
    scanf("%d",&num);
    size = num;
    while(size>0)
    {
       size = size/10;
       index++;
    }

    int arr[1000] ={0};

    for(i=(index-1);i>=0;i--)
    {
        arr[i] = (num%10);
        num = num/10;
    }

    printf("The array = { ");
    for(i=0;i<index;i++)
        printf("%d ",arr[i]);
    printf("}\n\n");

    print(arr,index);

    int c = 2,sum =0;
    printf("\n\nInput c: %d",c);
    //scanf("%d",c);

    for(i=0;i<index;i++)
    {
        sum = sum + arr[i]*(pow(c,i));
    }
    printf("\nP(%d) = %d\n\n",c,sum);


    for(i = index;i>=0;i--)
    {
      arr[i] = c*arr[i-1];
    }
    arr[0] = 0;
    index++;
    flag = 0;
    print(arr,index);
    printf("\n\n");
    return 0;
}


void print(int arr[], int index)
{
   int state = 1,i;
   printf("The polynomial P(x) is ");
   for(i=0;i<index;i++)
   {
       if(i == index -1)
          {state = 0;}

       if(arr[i]!=0)
          {printf("%d",arr[i]);}

       if(i != 0 && arr[i] !=0)
          {printf("x^%d",i);}

       if((state!=0) && (arr[i+1]!= 0)&&flag)
          {printf(" + ");}
          flag = 1;
    }
}
