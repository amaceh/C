#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama[50];
}data;

typedef struct elm *alamatelmt;
typedef struct elm{
	data elmt;
	alamatelmt next;
}elemen;

typedef struct
{
	elemen *first;
	elemen *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(char nama[], int x, queue *Q);