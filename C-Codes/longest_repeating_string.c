#include <stdio.h>
#include <string.h>
//There will always be a repeating sub-string given in the string
//A program in which the string can be of asdfasdfasdfas, asdfas, 

int main()
{
	char line[100];
	printf("please input a string");
	gets(line);
	int len = strlen(line);
	char longest[(len+1)], test[(len+1)];
	int max = 0;
	
	int k = 1, flag, j, i;
	while(k<=(len/2))   
	{
		strncpy(test, line, k); // Copying k elements in the test string to check whether its a sub-string
		if(len%k == 0)   //As if its not 0 then the above line will not be a multiple of substring size 
		{
			i = 1;
			flag = 1;          // A test point to check whether two char are same as tested in a substring. If flag = 0, then substring don't match or repeat
			while(i<(len/k) && flag)
			{
				for(j = 0;j<k;j++)
				{
					int a;
					a = (i*k) + j; // a indicates the char of successive substring
					if(line[a] != line[j])
					{
						//String is not same
						flag = 0;
						k = 0;             //Just in case there is no repeating string
						// Check whether we can add a break; here to reduce the run time
					}
				}
				i++;
			}
		}
		if(flag)
		{
			max = k;
			break;
		}
		k++;
	}
	printf("%d", k);
	return 0;
}
//  gcc longest_repeating_string.c -o 1.exe
//  cd "Documents\Codes-C\Codes-C"