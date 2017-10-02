/*  Date: 19/09/2017
	Name: Ashutosh Sancheti
	cd "Documents\Codes-C\Codes-C"
	gcc Round_table_killers_in_circular_linked_list.c -o Round_table_killers_in_circular_linked_list.exe
	Use of a circular linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node NODE;
typedef NODE * LINK;
struct node
{
	int person;
	LINK next;
};

typedef struct
{
	LINK head;
	int size;
}LIST;

//Define a global LINK for pointing to the last node
LINK last = NULL;											//last node in circular??

LIST circularList(int size);
LIST insertElement(int person, LIST ls);

LIST my_list;

int main()
{
	int n, x, k, j, a;										//what are j, a 
	//Total no. of persons
	printf("Input your n, x, k values:");					
	scanf("%d %x %f", &n, &x, &k);							//why x and f 
	my_list = circularList(n);
	//killer_pointer
	LINK killer = my_list.head;
	int i;
	for(a = 2; a<=x;a++)
		killer = killer -> next;
	i = killer -> person;
	
	while(my_list.size > 1)
	{
		for(j = 1;j<=(i%k);j++)
		{
			killer -> next = killer -> next -> next;
			//Write a line to release the memory
			my_list.size--;
		}
		killer = killer -> next;
		i = killer -> person;
	}
	printf("%d", i);
	return 0;
}

//A function to create a circular linked list
LIST circularList(int size)
{
	LIST ls;
	ls.size = size;
	ls.head = NULL;
	int i;
	for(i = 1;i<=size;i++)
		ls = insertElement(i, ls);
	return ls;
}

//Always inserted at the end
LIST insertElement(int person, LIST ls)
{
	if(person == 1) //To insert 1st element
	{
		LINK new_node = (LINK) malloc(sizeof(NODE));
		ls.head = new_node;
		new_node -> person = person;
		new_node -> next = new_node;
		last = new_node; //last pointer pointing to 1st node
	}
	else
	{
		LINK new_node = (LINK) malloc(sizeof(NODE));
		// the new_node will be ended at the end therefore new_node -> next will point to where ls.head points
		new_node -> next = ls.head;
		new_node -> person = person;
		//the next in last will now point to new_node
		last -> next = new_node;
		//last will now point to new_node which will be the last node;
		last = new_node;
	}
	return ls;
}
		