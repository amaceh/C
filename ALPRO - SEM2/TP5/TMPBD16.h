#include <stdio.h>//scanf printf
#include <string.h>//strcpy
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan TMPBD16 TP5,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
typedef struct
{
	char binary[11];//string biner
	int decimal;//hasil konversi
	char code;//kode penunjuk dari siapa biner berasal
}bigdata;//typedef struct
//fungsi konversi biner
int binaryconverter(char xstr[11]);
//prosedur quick sort
void quicksortpinggir(int x, bigdata a[x], int l, int r);
//prosedur merge table
void mergetable(int x, int y, bigdata a[x], bigdata b[y], bigdata d[x+y]);
//prosedur pencari data yang "suspicious"
void suspiciousdata(int x, bigdata z[x]);
//fungsi pengecek apakah data sudah digunakan 
//oleh suspicious sebelumnya atau belum
int blackchecker(int x, int black[x], int a, int b, int c);