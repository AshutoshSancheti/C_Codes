#include <stdio.h>

struct node;
typedef struct node *PTR;
typedef struct
{
    int data;
    PTR next;
}NODE;

typedef struct
{
    PTR head;
    int size;
}HEAD;

HEAD createList()
{
    HEAD ls;
    ls.head = NULL;
    ls.size = 0;
}

int main()
{
    mylist = createList();
   
}
