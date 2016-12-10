#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>//atoi
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan Kuis 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//bunkusan proyek
typedef struct
{
	char string[50];
	char angka;
}data;

//bungkusan elemen
typedef struct elmt *alamatelmt;
typedef struct elmt
{
	data elmt;
	alamatelmt next;
}elemen;

//bungkusan stack
typedef struct
{
	elemen* top;
}stack;//sebuah stack


char temp[50];//var global untuk return fungsi
///deklarasi prosedur fungsi
void CreateEmpty(stack *S);
int IsEmpty(stack S);
int CountElement(stack S);
void push(char string[], stack *S);//push stringnya saja
void push2(char string[], int angka,stack *S);//push beserta hasil operasi
void pop(stack *S);
void printstack(stack S);
///////
char* popreturn(stack S);//fungsi isi pop
//////
void proses(stack *S, stack *S2);//prosedur untuk proses skrip hitungan