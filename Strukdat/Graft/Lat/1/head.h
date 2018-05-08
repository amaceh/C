#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char info[50];
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	int jarak;
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul *first;
}graph;


void createEmpty(graph *G);
void addSimpul(char c[], graph *G);
void addJalur(simpul *tujuan, int jarak,simpul *awal);
void delSimpul(char c[], graph *G);
simpul* findSimpul(char c[], graph G);
void delJalur(char ctujuan[], simpul *awal);
void printGraph(graph G);


/////////////////////////////////////////////
/////////////////////////////////////////////
typedef struct{
	char A[50], B[50];
	int jarak;
}konjalur;

typedef struct elm *alamatelmt;
typedef struct elm{
	konjalur elmt;
	alamatelmt next;
}elemen;

typedef struct
{
	elemen *first;
	elemen *last;
}queue;

void createEmptyQ(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char A[], char B[], int jarak, queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addAllJlr(queue *Q, graph *G);
// void findTheWay(char A[], char B[], queue *Q, graph G);
void findTheWay(char A[], char B[], queue *Q, graph G, int jarak);
