#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP6,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//bunkusan proyek
typedef struct
{
	char nama[50];
	int waktu;
	int profit;
}proyek;

//bungkusan elemen
typedef struct elmt *alamatelmt;
typedef struct elmt
{
	proyek elmt;
	alamatelmt next;
}elemen;

//bungkusan stack
typedef struct
{
	elemen* top;
}stack;


char temp[50];//var global untuk return fungsi
///deklarasi prosedur fungsi
void CreateEmpty(stack *S);
int IsEmpty(stack S);
void push(char nama[], int waktu, int profit, stack *S);
void pop(stack *S);
void printstack(stack S);
char* popreturn(stack S);
int popreturn2(stack S);
int popreturn3(stack S);
void Sorting(stack *S);
void getMaxMoney(stack *S1, stack *S2);