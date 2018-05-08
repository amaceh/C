#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
	char info;
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct
{
	simpul *root;
}tree;

void makeTree(char c, tree *T);
void addChild(char c, simpul *root);
void delChild(char c, simpul *root);
void delChild(char c, simpul *root);
simpul* findsimpul(char c, simpul *root);
void printTreePreOrder(simpul *root, int *x);
void printTreePostOrder(simpul *root);