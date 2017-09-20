// Compiled with Code::Blocks 10.05 over Windows 7

#include<stdio.h>
#include<math.h>

#define MAX 10

int determ(int a[MAX][MAX],int n);

int main()
{
    int i,j,r,c,a[MAX][MAX],b[MAX][MAX],det=0;
    printf("\nEnter the number of Rows of the Matrix: ");
    scanf("%d",&r);
    printf("\nEnter the number of Columns of the Matrix: ");
    scanf("%d",&c);
    if(r==c)
    {
       printf("\nEnter the Elements of the Matrix:\n");
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
          {
             scanf("%d",&a[i][j]);
          }
       }
       det=determ(a,r);
       printf("\nThe given Matrix is:\n");
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
          {
             printf("%d\t",a[i][j]);
          }
          printf("\n");
       }
       printf("\nThe Determinant of the Matrix is %d\n",det);
    }
    else
    {
       printf("\nDeterminant does not exist!!!\n");
    }
    return 0;
}


int determ(int a[MAX][MAX],int n)
{
  int det=0,p,h,k,i,j,temp[MAX][MAX];
  if(n==1)
  {
      return a[0][0];
  }
  else if(n==2)
  {
      det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
      return det;
  }
  else
  {
    for(p=0;p<n;p++)
    {
       h = 0;
       k = 0;
       for(i=1;i<n;i++)
       {
         for( j=0;j<n;j++)
         {
            if(j==p)
   	        {
   	            continue;
   	        }
	        temp[h][k] = a[i][j];
    	    k++;
	        if(k==n-1)
  	        {
 		      h++;
  		      k = 0;
    	    }
	     }
       }
       det=det+a[0][p]*pow(-1,p)*determ(temp,n-1);
    }
    return det;
  }
}
