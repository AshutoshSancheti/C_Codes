#include<stdio.h>

int main()
{
	int n,x,k,remaining,j,i,value;
	// enter n,k,x
	scanf("%d%d%d",&n,&k,&x);
	int array[10000];
	remaining=n;
	for(i=1;i<=n;i++)
	{
		array[i]=1;
	}
	i=x;
	while(i%k<remaining)
	{	
		value=i%k;
		if(value==0 || array[i]==0)
		{
			i++;
			continue;
		}
		while(value>0)
		{	
			if(i==n)
			{	
				i=0;
			}
			if(array[i+1]==0)
			{	
				i++;
				continue;
			}
			
			else
			{
				array[i+1]=0;
				remaining--;
				i++;
				value--;
			}
		}
		for(j=i;;j++)
		{
			if(array[j%n]==1)
			{
				i=j;
				break;
			}
		}
		if(i>=n)
		{
			for(j=1;j<=n;j++)
			{
				if(array[j]==1)
				{
					i=j;
					break;
				}
			}
		}

	}
	printf("%d\n",i);
}

































/*#include <stdio.h>

int main()
{
	int n, k, x;
	
	printf("Input n, x, k\n");
	scanf("%d %d %d", &n, &x, &k);
	int arr[n],a;
	for(a = 0; a < n;a++)
		arr[a] = a+1;
	int killer = x;
	int kill_no = killer%k;
	int i = (killer - 1);
	int alive = n;
	
	while(alive > (killer%k))
	{
		//int kill_no = killer%k;     //this part must be later
		//i = (killer - 1);          //i indicates array indexing while killer indicates actual numbering of person starting from 1;
		
		printf("Enter while 1");
		//Killin starts must be careful about already dead people
		int count = 0;
		while(count<=kill_no)
		{
			printf("Enter loop 2");
			if(arr[i]!=0)
			{
				arr[i] = 0;
				alive--;
				count++;
			}
			i++;                     //when the loop ends this i will be the index of the person next to the last killed person
			if(i == n)
				i = 0;
		}
		
		//If the new person is already dead we want to skip him
		while(arr[i] == 0)
		{
			i++;			//when this loop exits we will get the index of the new killer
			if(i == n)
				i = 0;
		}
		
		killer = i+1;                //the new killer no
		kill_no = killer%k;          //Calculating the no of persons to be killed
	}
	
	printf("alive: %d killer: %d", alive, killer);
	return 0;
}
*/	
		