#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
	char info;
	alamatsimpul right;
	alamatsimpul left;
}simpul;

typedef struct{
	simpul* root;
}tree;

void makeTree(char c, tree *T);
void addRight(char c, tree *T, simpul *root);
void addLeft(char c, tree *T, simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root, int *lim);
void printTreeInOrder(simpul *root, int *lim);
void printTreePostOrder(simpul *root, int *lim);