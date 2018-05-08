#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan Kuis 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//bungkusan data
typedef struct{
	char nama[50];
}data;
//satu elemen
typedef struct elm *alamatelmt;
typedef struct elm{
	data elmt;
	alamatelmt next;
}elemen;
//satu queue
typedef struct
{
	elemen *first;
	elemen *last;
}queue;

/////////////deklarasi fungsi queue
void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(char nama[], int x, queue *Q);
///////////////////////////////////
void printQueue2(queue Q, int x);