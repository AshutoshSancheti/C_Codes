#include <stdio.h>
#include <string.h>

int count = 0;
char col[2][100];

void reverse(char sttr[]);

int main()
{
    char str[100];
    int i;
    printf("Input a sentence");
    //gets(str);
    str[0] = 'A';
    str[1] = 's';
    str[2] = 'h';
    str[3] = 'u';
    str[4] = ' ';
    str[5] = 's';
    str[6] = 'a';
    str[7] = 'n';
    str[8] = 'c';
    str[9] = '\0';
    printf("\n");
    for(i=0;i<10;i++)
        printf("%c",str[i]);
    printf("\n");

    reverse(str);

    printf("\n%d",count);
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

    //char *col[count] = (char*) malloc((count)*sizeof(char));

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

    for(i = count -1;i>=0;i--)
        printf("%s ", col[i]);
}

