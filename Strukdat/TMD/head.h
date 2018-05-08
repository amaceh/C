#include <stdio.h>//scanf, printf
#include <string.h>//strcmp, strcpy
#include <stdlib.h>//atoi
#include <malloc.h>//malloc
/*
Saya Achmad Abdul Rofiq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

//struct untuk queue
//saya menggunakan queue untuk menampung panjang nama/amal maksimal dari tiap generasi
typedef struct{
	int len, idx;
}lens;//one container

typedef struct elm *alamtelmt;
typedef struct elm{
	lens elmt;
	alamtelmt next;
}elem;//one element

typedef struct
{
	elem *first;
	elem *last;
}queue;//one queue

//fungsi/prosedur queue yang saya pakai
void createEmpty(queue *Q);//empty
void add(int len,  int idx, queue *Q);//dan add queue

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

//struct list
//saya menggunakan list untuk menampung amal yang ada pada inputan dan juga di tree
typedef struct{
	char amal[50];
}data;//one container

typedef struct elmt *alamatelmt;
typedef struct elmt{
	data elmt;
	alamatelmt next;
}elemen;//one element

typedef struct{
	elemen *first;
}list;//one list

//fungsi dan prosedur list yang saya pakai
void createList(list *L);//empty
int countElement(list L);//menghitung jumlah elemen dalam list
void addFirst(char amal[], list *L);//menambah data di awal list
void addAfter(elemen *prev, char amal[], list *L);//menambah data setelah elemen tertentu
void addLast(char amal[], list *L);//menambah data di elemen terakhir
void delFirst(list *L);//hapus elemen di awal
void delAfter(elemen *prev, list *L);//hapus elemen ditengah
void delLast(list *L);//hapus elemen di akhir
void printElement(list L, int x);//cetak list

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

//struct N-ER Tree
//pohon pertanggung jawaban dibuat dengan N-ER Tree

typedef struct smp *alamatsimpul;

typedef struct smp{
	char nama[50];
	list bad, good;//amal dibuat dengan list
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;//one nodes

typedef struct{
	simpul *root;
}tree;//one tree
//fungsi/prosedur N-ER yang saya pakai 
void makeTree(char c[], tree *T);
void addChild(char c[], simpul *root);
simpul* findsimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, simpul *troot, int x, int y, queue len);

//prosedur tambah data di pohon(mengolah input)
void Input(char str[], tree *T);//olah input(memecah string)
void addbyRoot(char root[], char child[], int x, int y,tree *T);
//tambah sesuai root

//prosedur pengganti tanggung-jawab dengan amal baik
void BadtoGood(list *L, list *L2, list *A, list *B);
void Tobat(simpul *root, list *A, list *B);
//mengganti isi list pertanggung jawaban dengan isi dari input amal baik

/////////////////////////////////////////////////////////
//prosedur untuk mengelola tampilan tree

//mencari kata terpanjang dari sebuah sumpul
int findtheLongest(simpul *node, simpul *troot);
//menghitung pnajng kata di simpul setiap generasi
void LentoQ(simpul *root, simpul *troot,queue *Len, int x);

/////////////////////////////////////////////////////////
