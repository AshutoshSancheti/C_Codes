#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define showcase_size 10

typedef enum {PINK = 5,BROWN, WHITE}color;

typedef struct
{
    int bear_id;
    float bear_cost;
    color bear_color;
}teddy_bear;

///Declaration of a node
typedef struct node
{
    teddy_bear td;
    struct node *next;
}NODE;
typedef struct node *LINK;
///Declaration of head pointer
typedef struct
{
    NODE *head;
    int size;
}LIST;

LIST createList()
{
    LIST listhead;
    listhead.head = NULL;
    listhead.size = 0;
    return listhead;
}

teddy_bear teddyInfo()
{
    teddy_bear teddyread;
    printf("Please enter the teddy ID:");
    scanf("%d",&(teddyread.bear_id));
    printf("Please enter the cost of teddy:");
    scanf("%f", &(teddyread.bear_cost));
    printf("Please enter bear color");
    scanf("%d", &(teddyread.bear_color));
    return teddyread;
}

void printList(LIST ls)
{
    NODE* temp;
    temp = ls.head;
    while(temp!=NULL)
    {
        printf("%d\n",(temp->td).bear_id);
        printf("%f\n",(temp->td).bear_cost);
        printf("%d\n",(temp->td).bear_color);
        printf("\n");
        temp = temp->next;
    }
}

LIST insertFirst(LIST ls,teddy_bear tux)
{
	NODE* temp;
	temp = ls.head;
	ls.size++;
	NODE* addFirst = (NODE*) malloc(sizeof(NODE));
	addFirst->td = tux;
	addFirst->next = NULL;

	///If list is empty
	if(temp == NULL)
	{
		temp = addFirst;
		return;
	}

	else
	{
		addFirst->next = temp;
		temp = addFirst;
		return;
	}
}

void deleteLast(LIST *ls)
{
	///Pass list as pointer to a pointer otherwise change will not occur
	///GO TO THE POINTER TO THE NODE SUCH THAT THE "NEXT" IN THE NODE TO WHICH THIS POINTER POINTS TO HAS VALUE "NULL"
	LINK temp,prev;
	temp = (*ls).head;
	prev=NULL;
	while(temp->next!= NULL)
	{
		prev=temp;
		temp = temp->next;
	}
	prev->next=NULL;
	free(temp);
}

int colorCount(LIST ls, int num)
{
	int count =0;
	LINK temp;
	temp = ls.head;
	while(temp!=NULL)
	{
		if(temp->td.bear_color == num)
			count++;
		temp = temp->next;
	}
	return count;
}

///Write the below function by value ie pass LIST ls
void insertColorSort(LIST *ls,teddy_bear tux)
{
	LINK temp;
	NODE* new_node = (NODE*) malloc(sizeof(NODE));
	new_node->td = tux;
	new_node->next = NULL;
	temp = (*ls).head;
	while(temp->next!= NULL && temp->td.bear_color<tux.bear_color)
		temp = temp->next;

	if(temp==NULL)
	{
		temp->next = new_node;
	}

	else
	{
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

void deleteTeddy(LIST *ls, teddy_bear tux)
{
	int flag = 0;
	LINK temp, prev;
	temp = (*ls).head;
	prev = NULL;
	while(temp!=NULL)
	{
		if(temp->td.bear_id == tux.bear_id && temp->td.bear_cost == tux.bear_cost && temp->td.bear_color == tux.bear_color)
		{
			flag = 1;
			break;
		}
		prev = temp;
		temp =  temp->next;
	}

	if(flag)
	{
		prev->next = temp->next;
		free(temp);
		temp->next = NULL;
	}
	else
	 	printf("\nStruct not in list");
}


///make a note here
void new_launch_update(LIST *ls, teddy_bear tux)
{
    LINK temp;
    int count = 0;
    temp = (*ls).head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    ///If space is available
    if(count<10)
    {
        (*ls) = insertFirst((*ls),tux);
    }

    else
    {
        (*ls) = insertFirst((*ls),tux);
        deleteLast(ls);
    }
}

int main()
{
    LIST mylist;
    mylist = createList();

    ///Creating the nodes
    NODE* first = (NODE*) malloc(sizeof(NODE));
    printf("\n1\n");
    first->td = teddyInfo();
    first->next = NULL;
    mylist.head = first;
    mylist.size++;

    NODE* second = (NODE*) malloc(sizeof(NODE));
    printf("\n2\n");
    second->td = teddyInfo();
    second->next = NULL;
    first->next = second;

    NODE* third = (NODE*) malloc(sizeof(NODE));
    printf("\n3\n");
    third->td = teddyInfo();
    third->next = NULL;
    second->next = third;

    NODE* fourth = (NODE*) malloc(sizeof(NODE));
    printf("\n4\n");
    fourth->td = teddyInfo();
    fourth->next = NULL;
    third->next = fourth;

    NODE* fifth = (NODE*) malloc(sizeof(NODE));
    printf("\n5\n");
    fifth->td = teddyInfo();
    fifth->next = NULL;
    fourth->next = fifth;

    NODE* sixth = (NODE*) malloc(sizeof(NODE));
    printf("\n6\n");
    sixth->td = teddyInfo();
    sixth->next = NULL;
    fifth->next = sixth;

    NODE* seventh = (NODE*) malloc(sizeof(NODE));
    printf("\n7\n");
    seventh->td = teddyInfo();
    seventh->next = NULL;
    sixth->next = seventh;

    NODE* eigth = (NODE*) malloc(sizeof(NODE));
    printf("\n8\n");
    eigth->td = teddyInfo();
    eigth->next = NULL;
    seventh->next = eigth;

    //NODE* ninth = (NODE*) malloc(sizeof(NODE));
    //ninth->td = teddyInfo();
    //ninth->next = NULL;
    //eigth->next = ninth;

    teddy_bear tux1,tux2,tux3,tux4,tux5, new_teddy;
    tux1 = teddyInfo();

    mylist = insertFirst(mylist,tux1);

    deleteLast(&mylist);

    printList(mylist);

    int colorNumber = colorCount(mylist, 5);
    printf("\n%d\n",colorNumber);

    tux2 = teddyInfo();
    insertColorSort(&mylist,tux2);
    printList(mylist);

    tux3 = teddyInfo();
    insertColorSort(&mylist,tux3);
    printList(mylist);

    tux4 = teddyInfo();
    deleteTeddy(&mylist,tux4);
    printList(mylist);

    tux5 = teddyInfo();
    deleteTeddy(&mylist, tux5);
    printList(mylist);

    new_teddy = teddyInfo();
    new_launch_update(&mylist, new_teddy);
    printList(mylist);

    return 0;
}
