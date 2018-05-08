#include <stdio.h>//printf, scanf
#include <string.h>//strcmp, strcpy

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan ojeku16.h UTS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

typedef struct//deklarasi bungkusan
{
	char name[100];//nama
	char number[100];//nomor
	int times;//waktu
	double komisi;//komisi
}tab;

void bublesort(int x, tab a[x]);//prosedur bublesort
void insertionsort(int x, tab a[x]);//prosedur insertionsort
void selectionsort(int x, tab a[x]);//prosedur selectionsort
void quicksortpinggir(int x, tab a[x], int l, int r);//prosedur quicksort
void mergetable(int x, int y, tab a[x], tab b[y], tab d[x+y]);//prosedur merge table