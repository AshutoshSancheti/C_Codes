#include <stdio.h>
#include <string.h>

int main()
{
	int t; //No. of test cases
	int i;
	char str[100000];
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		//fgets(str, 100000, stdin); don't
		scanf(" %[^\n]s", str); 
		
		int n = strlen(str);
		int j;
		char temp = '.';
		int count = 0, count_A = 0 , count_B = 0;
		for(j = 0;j<n;j++)
		{
			if((count!=0) && str[j] != '.')
			{
				if(temp == str[j])
				{
					if(temp == 'A')
						count_A += count;
					else if(temp == 'B')
						count_B += count;
					
				}
				count = 0;
			}
						
				
			if(str[j] == '.')
			{
				count++;
			}
			else if(str[j] == 'A')
			{
				count_A++;
				temp = 'A';
			}
			else if(str[j] == 'B')
			{
				count_B++;
				temp = 'B';
			}
			
		}
		//print A_count and B_count
		printf("%d %d", count_A, count_B);
		
	}
	return 0;
}
		