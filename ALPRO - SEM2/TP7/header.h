#include <stdio.h>//printf, scanf
#include <string.h>//strcpy, strcmp

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan Hitung" IP CERIA TP7,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

typedef struct
{ 
	char nim[10], nama[100];//string untuk nim dan nama
	float IP, mutu;//float untuk IP dan jumlah mutu
	int sks;//integer untuk sks
}IdxPrestasi;//deklarasi struct

//prosedur penghitung IP
void counttheIdxPres(IdxPrestasi x[128], int limit);
//prosedur insertion sort
void insertionsort(int x, IdxPrestasi n[128]);
void insertionsort2(int x, IdxPrestasi n[128]);
//prosedur pembaca file
void readthefirst(int counter[2], IdxPrestasi temp1[128]);
void readthesecond(int counter[2], IdxPrestasi temp2[128]);
//prosedur mergetable terurut
void mergetable(int x, int y, IdxPrestasi a[128], IdxPrestasi b[128]
	, IdxPrestasi d[256]);
//prosedur sortdata bila ip sama
void sortthesameIP(int x, IdxPrestasi d[256]);
//prosedur pembuat file
void createfile(int x, IdxPrestasi d[256]);