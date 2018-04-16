#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
	LinkedList list1 = newList();
	LinkedList list2 = newList();

	push(&list1, 5);
	push(&list1, 7);

	push(&list2, 12);
	push(&list2, 46);
	push(&list2, 11);

	// printf("list1:\n");
	// print(&list1);
	// printRev(&list1);
	// printf("list2:\n");
	// print(&list2);
	// printRev(&list2);
	// printf("\n");

	append(&list1, 44);
	append(&list1, 5);
	append(&list1, 17);
	insert(&list1, 0, 111);

	append(&list2, 4);
	append(&list2, 9);

	printf("list1:\n");
	print(&list1);
	printRev(&list1);
	printf("list2:\n");
	print(&list2);
	printRev(&list2);

	// printf("list1:\n");
	// print(&list1);
	// printRev(&list1);
	// printf("list2:\n");
	// print(&list2);
	// printRev(&list2);

	// printf("\nSORTING:\n");

	// sort(&list1);
	// sort(&list2);

	// printf("list1:\n");
	// print(&list1);
	// printRev(&list1);
	// printf("list2:\n");
	// print(&list2);
	// printRev(&list2);

	printf("%d\n", itemAt(&list1, 5));

	printf("\nDELETING:\n");
	deleteList(&list1);
	deleteList(&list2);

	return 0;
}