#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[50];
}nami;

typedef struct 
{
	int top;
	nami data[10];
}stack;

void CreateEmpty(stack *S);
int IsEmpty(stack S);
int isFull(stack S);
void push(char nama[], stack *S);
void pop(stack *S);
void printstack(stack S);
