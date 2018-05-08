#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP7,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//bungkusan data
typedef struct{
	char nama[50];
	int tufel;
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
void add(char nama[], int tufel ,queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(char nama[], int tufel, int x, queue *Q);
///////////////////////////////////

//mesin penyeleksi
void KickOut1(queue *Q1, int limit, int score, queue *Q2, queue *Q3);
void KickOut2(queue *Q1, int limit, int score, queue *Q2);
/////////////////