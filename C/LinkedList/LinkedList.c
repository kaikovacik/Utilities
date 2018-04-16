#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


// Builds and allocates a new LinkedList
LinkedList newList()
{
	LinkedList list;

	// Allocate head
	Node *head = (Node *) malloc(sizeof(Node));
	list.head = head;

	// Allocate Tail
	Node *tail = (Node *) malloc(sizeof(Node));
	list.tail = tail;

	list.size = 0;

	return list;
}


// Frees all remaining memory used by the given list
void deleteList(LinkedList *list)
{
	Node *curr = list->head;
	Node *next;

	// Free every node
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}

	list->size = 0;
}


// Pushes the data to the front of the list
void push(LinkedList *list, int data)
{
	// Initialize newNode
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	// Push data to the front of the list
	if (list->size == 0)
		list->tail = newNode;
	else
	 	newNode->next = list->head;
	 	list->head->prev = newNode;

	list->head = newNode;
	list->size++;
}


// Appends the data to the end of the list
void append(LinkedList *list, int data)
{
	// Initialize newNode
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Append data to the end of the list
	if (list->size == 0) 
		list->head = newNode;
	else
	{
		list->tail->next = newNode;
		newNode->prev = list->tail;
	}

	list->tail = newNode;
	list->size++;
}


// Inserts the data to the given index in the list
void insert(LinkedList *list, int index, int data)
{
	if (index < 0 || index > list->size) return;

	// Initialize newNode
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Traverse curr to index if required
	Node* curr = list->head;
	if (index != 0 && index != list->size)
	{
		int i;
		for (i = 0; i < index-1; i++)
			curr = curr->next;
	}

	// Insert newNode
	if (list->size == 0)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else if (index == 0)
	{
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	else if (index == list->size)
	{
		list->tail->next = newNode;
		newNode->prev = list->tail;
		list->tail = newNode;
	}
	else
	{
		newNode->next = curr->next;
		newNode->prev = curr;
		curr->next->prev = newNode;
		curr->next = newNode;
	}

	list->size++;
}


// Removes and returns the data at the front of the list
int pop(LinkedList *list)
{
	// Returns 0 if the list is empty
	int data = 0;

	if (list->size > 0)
	{
		Node* next = list->head->next;
		data = list->head->data;
		free(list->head);
		list->head = next;
		list->size--;
	}

	return data;
}


// Returns the data at the front of the list
int peek(LinkedList *list)
{
	return (list->size == 0)? 0 : list->head->data;
}


// Sorts the given list using insertion sort
void sort(LinkedList *list)
{
	int arr[list->size];

	// Build an array representation of the list
	int i;
	int n = list->size;
	for (i = 0; i < n; i++)
		arr[i] = pop(list);

	// Sort array
	for(int i = 1; i < n; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(arr[j] > arr[j-1])
			{
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	// Rebuild sorted list
	for (i = 0; i < n; i++)
		push(list, arr[i]);
}


// Returns item at the given index in the list
int itemAt(LinkedList *list, int index)
{
	if (index < 0 || index > list->size-1) return 0;

	// Traverse curr to index if required
	Node* curr = list->head;
	if (index != 0 && index != list->size)
	{
		int i;
		for (i = 0; i < index; i++)
			curr = curr->next;
	}

	// Return data at the index
	if (index == 0) 
		return list->head->data;
	else if (index == list->size) 
		return list->tail->data;
	else return curr->data;
}


// Prints the list in order
void print(LinkedList *list)
{
	if (list->size == 0)
	{
		printf("[]\n");
		return;
	}

	printf("[");

	Node *curr = list->head;
	while (curr != NULL)
	{
		printf("%s%d", ((curr == list->head)? "" : ", "), curr->data);
		curr = curr->next;
	}

	printf("]\n");
}


// Prints the list in reverse order
void printRev(LinkedList *list)
{
	if (list->size == 0)
	{
		printf("[]\n");
		return;
	}

	printf("[");

	Node *curr = list->tail;
	while (curr != NULL)
	{
		printf("%s%d", ((curr == list->tail)? "" : ", "), curr->data);
		curr = curr->prev;
	}

	printf("]\n");
}