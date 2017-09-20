#include <stdio.h>

int No_Q7_correct(int student_marks[][8], int r, int ans_of_Q7);
int main()
{
    int answer_key[8], num,j,i;
    printf("Enter the answer Key:\n");
    //scanf("%d",&num);
    num = 12345678;
    int cpy_num;
    cpy_num = num;

    for(i=7;i>=0;i--)
    {
        answer_key[i] = cpy_num%10;
        cpy_num = cpy_num/10;
    }

    int student_marks[10][8];

    for(j=0;j<10;j++)
    {
        printf("\nEnter marks of student %d as an integer:",(j+1));
        int marks = 0;
        //scanf("%d",&marks);
        marks = 12345687;
        for(i=7;i>=0;i--)
        {
           student_marks[j][i] = marks%10;
           marks = marks/10;
        }
    }

    int ans_of_Q7,alpha;
    ans_of_Q7 = answer_key[6];
    alpha = No_Q7_correct(student_marks[10][8], 10,7);
    printf("\nNo. of students with correct answer for question 7:%d\n",alpha);

    for(i = 0;i<10;i++)
    {
        int sum_of_marks =0;
        for(j=0;j<8;j++)
        {
            if(student_marks[i][j] == answer_key[j])
                sum_of_marks += 4;
            else
                sum_of_marks -=1;
        }

        printf("The marks of student %d are %d\n",(i+1),sum_of_marks);
    }

    return 0;
}

int No_Q7_correct(int student_marks[][8], int r, int ans_of_Q7)
{
    int i, No_Q7_correct = 3;
    for(i = 0;i<r;i++)
    {
        if(student_marks[i][6] == ans_of_Q7)
           {
              No_Q7_correct = No_Q7_correct + 1 ;
           }
        else
            continue;
    }

 return (No_Q7_correct);
}
