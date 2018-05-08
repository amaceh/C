#include <stdio.h>//scanf printf
#include <string.h>//strcmp, strcpy, strlen

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan MPPM16 TP4,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

void bublesort(int x, char str[x][16], char str2[x][30]);//prosedur bublesort
void quicksortpinggir(int x, char str[x][30],int l, int r, char str2[x][16]);//prosedur quicksort pivot pinggir
void printthelist(int x, char str[x][16], char str2[x][30],
		char strx[x][16], char strx2[x][30], int unvalid, 
		char order1[16], char order2[16]);//prosedur print hasil akhir
int numbercheck(char str[16]);//fungsi pengecek ada atau tidaknya huruf
void unvalidfinder(int x, char str[x][16], char str2[x][30], char stry[x][16], 
	char stry2[x][30], char strx[x][16], char strx2[x][30], char order1[16], char order2[16]);
//prosedur pencari apakah nim valid atau tidak