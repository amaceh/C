#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama[50];
}nami;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
	nami elmt;
	alamatelmt next;
}elemen;

typedef struct 
{
	elemen *top;
}stack;

void CreateEmpty(stack *S);
int IsEmpty(stack S);
int CountElement(stack S);
void push(char nama[], stack *S);
void pop(stack *S);
void printstack(stack S);

