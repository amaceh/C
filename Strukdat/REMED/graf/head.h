#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan REMEDIAL STRUKDAT,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//dekalrasi graf
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char info[50];
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	// int jarak;
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul *first;
}graph;


void createEmpty(graph *G);
void addSimpul(char c[], graph *G);
void addJalur(simpul *tujuan, simpul *awal);
void delSimpul(char c[], graph *G);
simpul* findSimpul(char c[], graph G);
void delJalur(char ctujuan[], simpul *awal);
void printGraph(graph G);

void addByPath(char x[], char y[], graph *G);
/////////////////////////////////////////////
/////////////////////////////////////////////
//deklarasi queue
typedef struct{
	int A;
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

//fungsi prosedru lain
void createEmptyQ(queue *Q);
void printQueue(queue Q);
void add(int A, queue *Q);
int validation(char x[], char y[], graph G);
void checkPath(char x[], graph G, queue *Q);
// int isEmpty(queue Q);
// int countElement(queue Q);
// void del(queue *Q);
// void printQueue(queue Q);
// void addAllJlr(queue *Q, graph *G);
// void findTheWay(char A[], char B[], queue *Q, graph G);