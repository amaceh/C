#include <stdio.h>//printf scanf
#include <string.h>//strcpy, strcmp

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan EVBI16.h evaluasi,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

typedef struct
{
	char binary[9];
	int decimal;
}tab;//deklarasi struct

int binaryconverter(char xstr[9]);//fungsi konverter biner
void converttab(tab input[256], int counter);//prosedur konvert setiap biner
void insertionsort(int x, tab xtab[256]);//prosedur insertion sort
void mergetable(int x, int y, tab a[256], tab b[256], tab d[256]);//prosedur mergetable terurut
void splitthetab(tab input[256], tab big[256], tab litte[256],int counter);//prosedur pemisah tab
void printtheresult(tab x[256], int counter, int order);//prosedur pencetak hasil
