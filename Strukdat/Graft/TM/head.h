#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char info;
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	// int info;
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul *first;
}graph;


void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *tujuan, simpul *awal);
void delSimpul(char c, graph *G);
simpul* findSimpul(char c, graph G);
void delJalur(char ctujuan, simpul *awal);
void printGraph(graph G);