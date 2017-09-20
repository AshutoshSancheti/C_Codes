/*  Date: 19/09/2017
	Name: Ashutosh Sancheti
	cd "Documents\Codes-C\Codes-C"
	gcc Round_table_killeres_in_circular_linked_list.c -o 1.exe
	Use of a circular linked list
*/

#include <stdio.h>

struct node;
typedef struct node NODE;
typedef NODE * LINK;
struct node
{
	int person;
	LINK next;
}

//A function to create a circular linked list


int main()
{
	