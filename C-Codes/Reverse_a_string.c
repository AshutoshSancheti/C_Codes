#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
//char col[][100];

void reverse(char sttr[]);

int main()
{
    char str[100];
    printf("Input a sentence");
    gets(str);
     reverse(str);

    printf("%d",count);
    return 0;
}

void reverse(char str[])
{
    int i =0;
    while(str[i] !='\0')
    {
        int flag = 1;
        while(str[i]!= ' ')
        {
            if(flag == 1)
            {
                count++;
                flag =0;
            }
            i++;
        }

        while(str[i] == ' ' )
            i++;
        flag =1;
    }
    //Till here the code is for counting no of words

    int k = 0;
    char *col[4];
    col = calloc(4, sizeof(char *));

//    char *col[4] = (char*) calloc(4, sizeof(char *));
//col[count] = NULL;
   // col[count][100];
    i =0;
    while(str[i] != '\0')
    {
        int flag = 0;
        int j = 0;
        while(str[i] != ' ')
        {
            (*(*(col + k)+j)) = str[i];
            j++;
            i++;
            flag = 1;
        }
        if(flag)
        {
            k++;
            flag = 0;
        }

        while(str[i] == ' ')
        {
            i++;
        }

    }

    for(i = 4 -1;i>=0;i--)
        printf("%s", col[i]);
}

