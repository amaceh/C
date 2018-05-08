#include <stdio.h>//printf, scanf
#include <string.h>//strcpy, strcmp

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan KUIS 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//deklarasi struct
typedef struct
{
	char kode[10], nama[20];//deklarasi string untuk kode dan nama
	int harga;//deklarasi int untuk harga
}makanan;

//prosedur selection sort
void selectionsort(int x, makanan list[x], char xstr[10]);
//prosedur binary search
void binarysearch(int x, makanan list[x], char xstr[10], char want[20], int want2);