#include <stdio.h>//scanf printf
#include <string.h>//strcpy, strcmp
#include <malloc.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP8,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//deklarasi bungkusan untuk binary tree
typedef struct smp *alamatsimpul;
typedef struct smp{
	char nama[50];
	int num;
	alamatsimpul right;
	alamatsimpul left;
}simpul;//one node

typedef struct{
	simpul* root;
}tree;//one root
//////////////////////////////////////////////////////////////
//deklarasi bungkusan untuk stack
typedef struct
{
	char nama[50];
	int sum;
}history;//one container

//bungkusan elemen
typedef struct elmt *alamatelmt;
typedef struct elmt
{
	history elmt;
	alamatelmt next;
}elemen;

//bungkusan stack
typedef struct
{
	elemen* top;
}stack;

//deklarasi prosedur standar tree
void makeTree(char nama[],int num ,tree *T);
void addRight(char nama[],int num, simpul *root);
void addLeft(char nama[],int num, simpul *root);
//deklarasi prosedur standar stack
void CreateEmpty(stack *S);
void push(char nama[], int sum, stack *S);
void pop(stack *S);
void printstack(stack *S);
//deklarasi prosedur lain
void trackName(char nama[], simpul *root, tree T, stack *S);
void findParent(char nama[], char x[], int *y, simpul *root);