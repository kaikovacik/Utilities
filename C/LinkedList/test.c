#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


int main(int argc, char const *argv[])
{
	LinkedList l1 = newList();
	LinkedList l2 = newList();
	LinkedList l3 = newList();
	

	printf("LIST1, LIST2, and LIST3\n");
	print(&l1);
	print(&l2);
	print(&l3);

	// push(&l1, 12);
	// push(&l1, 12);
	// push(&l1, 12);
	// push(&l1, 12);
	// push(&l1, 12);

	// push(&l2, 4);
	// push(&l2, 4);
	// push(&l2, 4);
	// push(&l2, 4);
	// push(&l2, 4);
	// push(&l2, 4);

	// push(&l3, 6);
	// push(&l3, 6);
	// push(&l3, 6);
	// push(&l3, 6);
	// push(&l3, 6);

	print(&l1);
	print(&l2);
	print(&l3);

	deleteList(&l1);
	deleteList(&l2);
	deleteList(&l3);
	return 0;
}


// void deleteList(LinkedList *list);
// void push(LinkedList *list, int data);
// void append(LinkedList *list, int data);
// void insert(LinkedList *list, int index, int data);
// int pop(LinkedList *list);
// int peek(LinkedList *list);
// void sort(LinkedList *list);
// int itemAt(LinkedList *list, int index);
// void print(LinkedList *list);
// void printRev(LinkedList *list);