#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[50];
}datanam;

typedef struct{
	int first, last;
	datanam data[6];
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nama[], queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(char nama[], int prior, queue *Q);