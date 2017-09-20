//Program for pascal triangle
#include <stdio.h>

int main()
{
  int num;
  printf("Enter the number of rows:");
  scanf("%d",&num);
  printf("\n");
int i,j,x,y,z;
 //The indexing of rows and corresponding terms must start from 0
 
  for(i=0;i<num;i++)
  {  
     int term =0;
    
     for(j=0;j<=i;j++)
     {
         int fact1 =1;
         if(i>0&&j>0)    
         {
            for(x=1;x<=i;x++)
            {
              fact1 = fact1*x;
            }
         }

         else
           fact1 =1;

         int fact2 = 1, fact3 = 1;
       
         if(j>0)
         {
             for(y =1;y<=j;y++)
             {
               fact2 = fact2*y;
             }
             for(z=1;z<=(i-j);z++)
             {
               fact3 = fact3*z;
             }
        }
      
        else
        {
            fact2 =1;
            fact3 =1;
        }
      
        term = fact1/(fact2*fact3);
        printf("%d ",term);
    } 
    printf("\n");
  }
} 
    
