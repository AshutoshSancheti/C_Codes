/// Name: Ashutosh Sancheti
/// Date: 13 April, 2017
/// Trying to understand Structures and dynamic Memory allocation

#include <stdio.h>
#include <stdlib.h>


///Declaring the structure of  textbook information.By making "booklist" a pointer of kind "struct textbook", you don't
///have to declare " struct textbook booklist[no_of_books]"
struct textbook
{
    char name[10];
    int price;
    int numaut;
    char **author;
};


struct classroom
{
    int no_of_books;
    struct textbook *booklist;
    ///Here instead of declaring an array of structures for my books of a particular class,
    ///I have declared a pointer which can be used as an array and the memory allocation for it will be dynamic
    ///If i had declared an array of "struct textbook" I would not be able to alter the no. of books in each "classroom"
    ///Please look at how memory is allocated dynamically for booklist in EACH "CLASSROOM"
    ///To access each member of booklist (i.e. "struct textbook" element), you have to use booklist[i] or *(booklist + i)
    ///where max value of i = no_of_books -1
};
typedef struct classroom std;


///Function prototypes
void read_classInfobyRef(std *s,int class_no,int no_of_books);
void print_classInfobyRef(std *s,int class_no);
void print_allInfo(std *s,int no_of_classes);


int main()
{
    int no_of_classes;
    printf("Please enter the no. of classes:");
    scanf("%d", &no_of_classes);

    std *s;              /// "struct classroom *s;" - ANOTHER WAY
    ///Here again by declaring s as a pointer of kind "struct classroom", you can use it as a dynamic array of "classroom"
    ///with dynamic memory allocation instead of std s[no_of_classrooms]
    ///Please check it's dynamic memmory allocation

    s = (std *) malloc(sizeof(std)*no_of_classes);
    ///Another way is " std *s = (std *) malloc(sizeof(std)*no_of_classes);"
    ///One more " struct classroom *s = (struct classroom *) malloc(sizeof(struct classroom)*no_of_classrooms);"

    ///through the above dynamic memory allocation,
    /// s is a pointer of type "struct classroom" pointer to the memory block which consists of smaller memory blocks
    ///each of these smaller blocks has memory equal to "struct classroom" and the no of these smaller blocks is equal to
    ///no_of_classes
    ///To access each of these smaller blocks, you have to use *(s+0), *(s+i) or s[i] (by value just like any simple array)
    ///Max value of i = no_of_classes - 1;


    ///Function calling

    read_classInfobyRef(s,0,2);///Function call for filling the data of classroom 0 i.e s[0]
    print_allInfo(s,no_of_classes);
    //print_classInfo(&s,0);

    return 0;
}


///FUNCTIONS


///This function is for storing the info regarding all the books in that class
///Be careful as here you pass the "address" of the "Array(the pointer way) of 'classrooms'"
///class_no starts from 0. If it starts from 1 you have to make changes accordingly
///numbering of books starts from 0
void read_classInfobyRef(std *s,int class_no,int no_of_books)
{
    int i;
    ///Storing the value of no. of books. Has to be done explicitly for each "classroom"
    s[class_no].no_of_books = no_of_books;
    ///Here you have dynamically allocate memory for "booklist"
    s[class_no].booklist = (struct textbook *) malloc(sizeof(struct textbook)*no_of_books);
    /// Another way is (*(s + class_no)).booklist = (struct textbook *) malloc(sizeof(struct textbook)*no_of_books);
    ///If booklist wasn't declared globally the " struct textbook *(s[class_no].booklist) = (struct textbook *) malloc...


    printf("\nEnter the details of the books:");
    for(i=0;i<no_of_books;i++)
    {
        printf("\nEnter the details of book[%d]",i+1);
        scanf("%s", &(s[class_no].booklist[i].name));
        scanf("%d", &(s[class_no].booklist[i].price));  /// * is "canceled by &
        ///Try  scanf("%d", (s+class_no).(*(booklist[i]).price);  /// * is "canceled by &
        scanf("%d", &(s[class_no].booklist[i].numaut));
        s[class_no].booklist[i].author = (char **) malloc(sizeof(char *)*(s[class_no].booklist[i].numaut));
        int a;
        for(a=0;a<(s[class_no].booklist[i].numaut);a++)
           {
               s[class_no].booklist[i].author[a] = (char *) malloc(sizeof(char)*20);
               printf("Please enter the author's name");
               scanf("%s ", s[class_no].booklist[i].author[a]);
           }

        printf("\n");
    }
}


void print_classInfobyRef(std *s,int class_no)
{
    printf("%d\n",s[class_no].no_of_books);
    printf("%d\n",s[class_no].booklist);
}


void print_allInfo(std *s,int no_of_classes)
{
    int i,j, k;
    ///I is the counter of class and j is for books
    for(i=0;i<no_of_classes;i++)
    {
        ///nb indicates no_of_books in each "struct class"
        int nb = s[i].no_of_books;
        printf("No. of books in class[%d]:%d\n",i,nb);
        for(j=0;j<nb;j++)
        {
            printf("Info of book[%d] is\n:",i);
            printf("%s\n", (s[i].booklist[j].name));
            printf("%d\n", (s[i].booklist[j].price));
            printf("%d\n", (s[i].booklist[j].numaut));
            for(k=0;k<(s[i].booklist[j].numaut);k++)
                printf("%s\n", (s[i].booklist[j].author[k]));
            printf("\n");
        }
    }
}
