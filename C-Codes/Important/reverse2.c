#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reverse(char str[]);

int main()
{
    char str[100];
    printf("Input a sentence\n");
    gets(str);
    reverse(str);

   // printf("%d",count);
    return 0;
}

void reverse(char str[])
{
    int count = 0;

    int i =0;
    while(str[i] !='\0')
    {
        int flag = 1;
        while(str[i] !='\0'&& str[i]!= ' ')
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
    ///Till here the code is for counting no of words

    int k = 0,a;
    i =0;
    char **col;  ///Declaring array of pointers dynamically

///Allocating memory to pointers
    col = (char **) malloc(sizeof(char *)*count);

///Allocating memory to which each pointer will point to
    for(a =0;a<count;a++)
	col[a] = (char *) malloc(sizeof(char)*30);


    while(str[i] != '\0')
    {
        int state = 0;
        int j = 0;
        while(str[i] != ' ' && str[i] != '\0') //It is necessary to str != '\0' here as well
///because while entering the outer while at start of the last word str[i] will not be NULL
///but on running the above inner while str[i] will hit NULL as so the condtion otherwise the loop will run infinitely
        {
            (*(*(col + k)+j)) = str[i];
            j++;
            i++;
            state = 1;
        }
       (*(*(col + k)+j)) = '\0';
        if(state)
        {
            k++;
            state = 0;
        }

        while(str[i] == ' ')
        {
            i++;
        }

    }

	printf("\nThe reverse of the sentence is: ");
    for(i = count -1;i>=0;i--)
        printf("%s ", col[i]);
}
