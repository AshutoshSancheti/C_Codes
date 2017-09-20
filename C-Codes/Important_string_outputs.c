#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "A BC DEF GHIJ";
    printf("%s\n",str+3);
    printf("%s\n",str+6);
    printf("%s\n",str+9);
    puts(str+3);
    printf("\n");


    char str1[12],str2[12];
    str1[12] = "BITS Pilani";
    str2[8] = "BITS Goa";
    int equal = strcmp(str1,str2);
    int ass = strlen(str1);
    printf("%d\n",equal);
    printf("%d\n\n\n",ass);

    char cp[5][15] = {"ARRAY", "SWITCH", "POINTER","FOR LOOP","CONDITIONAL"};
    printf("%c\n",cp[3][6]);
    printf("%c\n",*(*(cp+3)+6));
    printf("%c\n",*(*(cp+3)+1));
    printf("%c\n",*(6 + cp[3]));
    printf("%c\n\n\n",*(2 + cp[2]));

    int i=1,j=0;
    while(*(*(cp +i)+j)!= '\0')
    {
        printf("%c", *(*(cp+i)+j));
        j++;
    }
    printf("\n\n");

    char *cpa[ ] = {"ARRAY", "SWITCH", "POINTER", "FOR LOOP", "CONDITIONAL"};
char *temp;

for( i=0;i<4;i++)
{
for( j=i;j<5;j++)
{
if(strcmp(cpa[i],cpa[j])<0)
{
temp = cpa[i];
cpa[i] = cpa[j];
cpa[j]=temp;
}
}
}

for(i=0;i<5;i++)
{
    printf("%s\n",cpa[i]);
}


}
