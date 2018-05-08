#include <stdio.h>
#include <string.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan UDN15 TP3,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//membuat bungkusan nama kelas dan nilai
typedef struct
{
	char name[50];
	char class[20];
	int grade;
}Glist;

//prosedur sortir sesuai nama
void inssortbyname(int x, Glist arr[100]);
//prosedur srtir sesuai nilai
void inssortbygrade(int x, Glist arr[100]);