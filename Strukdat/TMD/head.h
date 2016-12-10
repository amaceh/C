#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
	char amal[50];
}data;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	data elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char amal[], list *L);
void addAfter(elemen *prev, char amal[], list *L);
void addLast(char amal[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printElement(list L);

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


typedef struct smp *alamatsimpul;

typedef struct smp{
	char nama[50];
	list bad, good;
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct{
	simpul *root;
}tree;

void makeTree(char c[], tree *T);
void addChild(char c[], simpul *root);
void delChild(char c[], simpul *root);
simpul* findsimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, simpul *troot);
void printTreePostOrder(simpul *root);
void Input(char str[], tree *T);
void addbyRoot(char root[], char child[], int x, int y,tree *T);


void BadtoGood(list *L, list *L2, list *A, list *B);
void Tobat(simpul *root, list *A, list *B);