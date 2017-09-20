#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

/*
ANOTHER WAY TO DECLARE THE ABOVE NODES

struct node;
typedef struct node NODE;
typedef NODE *LINK;

struct node
{
	int data;
	LINK next;
};

*/

typedef struct
{
	int size;
	struct node *head;
}LIST;

LIST createList()
{
	LIST ls;
	ls.head = NULL;
	ls.size = 0;
	return ls;
}


void printList(struct node* h)
{
	while(h !=NULL)
	{
		printf("%d\n",h->data);
		h = h->next;
	}
}

void push(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;

	//since we pass pointer to a pointer by using (*head_ref)
	// (*head_ref) is nothing but linkedlist.head
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(struct node *prev_node, int new_data)
{
	if(prev_node == NULL)
	{
		printf("\neRROR\n");
		return;
	}

	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;

	struct node* temp;
	temp = prev_node->next;
	///TEMP POINTS TO NODE BEFORE WHICH THE NEW NODE HAS TO BE ADDED

	new_node->next = temp;
///pointer inside the new node points to next node
	prev_node->next = new_node;
}


void insertLast(struct node **head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;

	///firts we test whether list is empty
	if((*head_ref) == NULL)
	{
		(*head_ref) = new_node;
		// linkedlist.size++; is invalid here
		//this means linkedlist.head pointes to new_node
	///head_ref is the pointer to linkedlist.head
		return;
	}

	else
	{
		struct node* temp;
		temp = (*head_ref);
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		return;
	}
}

int main()
{
	LIST linkedlist;
	linkedlist = createList();

	struct node* first = NULL;  ///pointer to the first node
	struct node* second = NULL;//pointer to the second node
	struct node* third = NULL; ///pointer to the third node

	first = (struct node*) malloc(sizeof(struct node));
	second = (struct node*) malloc(sizeof(struct node));
	third = (struct node*) malloc(sizeof(struct node));

	linkedlist.head = first; ///head also points to the first node

	first->data = 1;
	first->next = second;
	linkedlist.size++;

	second->data = 2;
	second->next = third;
	linkedlist.size++;

	third->data = 3;
	third->next = NULL;
	linkedlist.size++;

	printList(linkedlist.head);
	////USING printList(first) will also give the same result


///Inserting a new node in between head and first nodeby passing the pointer which points to linkedlist.head i.e. pointer to a pointer
	push(&(linkedlist.head), 0);
	linkedlist.size++;

	printf("\nThe new linked list is:\n");
	printList(linkedlist.head);

	insertAfter(second, 4);
	//a new node to be inserted after second node
	linkedlist.size++;

	printf("\nThe new linked list is:\n");
	printList(linkedlist.head);

	insertLast(&(linkedlist.head), 5);
   	linkedlist.size++;

	printf("\nThe new linked list is:\n");
	printList(linkedlist.head);


 	return 0;
}
