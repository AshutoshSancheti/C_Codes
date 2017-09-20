#include <stdio.h>

typedef struct node
{
    int td;
    struct node *next;
}NODE;
typedef struct node *LINK;
///Declaration of head pointer
typedef struct
{
    NODE *head;
    int size;
}LIST;

/*void reverseList(LINK *ls)
{
    LINK temp;
    LINK *mark;
    mark = ls;
    temp = *ls;

        if((*mark)->next!=NULL)
        {
            reverseList(&(temp->next));
        }
        else
        {
             temp->next = (*ls);
             (*ls) = temp;
             temp = NULL;
             return ;
        }
}

void printList(LIST ls)
{
    NODE* temp;
    temp = ls.head;
    while(temp!=NULL)
    {
        printf("%d\n",(temp->td));
        printf("\n");
        temp = temp->next;
    }
}

void list_reverse_without_recursion(LINK *head)
{
    LINK curr, prev, next;
    curr = (*head);
    prev = NULL;
    next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev->next;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}
*/
///Linked list reversal using recursion
void reverseUsingRecursion(LINK *head,LINK pre)
{

    LINK temp;
    temp = *head;
    if(temp->next!=NULL)
            reverseUsingRecursion(&(temp->next),temp);
    else
    {
        temp->next = *head;
        *head = temp;
        pre->next = NULL;
        return;
    }
}

void printReverse(LINK ls)
{
    LINK temp;
    temp = ls;
    if(temp->next!= NULL)
        printReverse(temp->next);
    printf("%d\n",ls->td);
    return;
}

int main()
{
    LIST mylist;
    mylist.head = NULL;

    NODE* first =(NODE*)malloc(sizeof(NODE));
    first->td = 1;
    first->next = NULL;
    mylist.head = first;
    mylist.size++;

    LINK second = (NODE*)malloc(sizeof(NODE));
    second->td = 2;
    second->next = NULL;
    first->next = second;
    mylist.size++;

    NODE* third = (NODE*)malloc(sizeof(NODE));
    third->td = 3;
    third->next = NULL;
    second->next = third;
    mylist.size++;

    NODE* fourth = (NODE*)malloc(sizeof(NODE));
    fourth->td = 4;
    fourth->next = NULL;
    third->next = fourth;
    mylist.size++;

    NODE* fifth = (NODE*)malloc(sizeof(NODE));
    fifth->td = 5;
    fifth->next = NULL;
    fourth->next = fifth;
    mylist.size++;

    reverseUsingRecursion(&mylist.head,NULL);
    //list_reverse_without_recursion(&first);
    printReverse(mylist.head);
   // reverseList(&first);

   // printList(mylist);

    return 0;
}
