#include <stdio.h>
#include <string.h>

int string_period(char str[])
{
    int length = strlen(str);
    int period, i, j,flag =1;
    char q[100];
    for(period = 1;period<(length/2);period++)
    {
        for(i=0;i<period;i++)
            q[i] = str[i];
        flag = 1;
        for(i=0;i<length && flag;i=i+period)
        {
            for(j=0;j<period;j++)
            {
                if(q[j]!=str[i+j])
                    flag = 0;
            }
        }
        if(flag)
            return period;
    }
    return length;
}

int main()
{
    FILE *fp;
    int i;
    char q[100] = "Ashutosh Sancheti";
    printf("%d",string_period(q));
    fp = fopen("C:/users/ashus/desktop/periodOfString.cmd","w");
    for(i=0;i<string_period(q);i++)
        fprintf(fp,"%c", q[i]);
    fclose(fp);
    return 0;
}
