#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;
struct Node
{
	int data;
	Node *next;
	Node *prev;
};

typedef struct LinkedList
{
	Node *head;
	Node *tail;
	int size;
}LinkedList;

LinkedList newList();
void deleteList(LinkedList *list);
void push(LinkedList *list, int data);
void append(LinkedList *list, int data);
void insert(LinkedList *list, int index, int data);
int pop(LinkedList *list);
int peek(LinkedList *list);
void sort(LinkedList *list);
int itemAt(LinkedList *list, int index);
void print(LinkedList *list);
void printRev(LinkedList *list);

#endif