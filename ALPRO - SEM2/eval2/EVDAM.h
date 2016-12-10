#include <stdio.h>
#include <string.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan EVDAM evaluasi 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/


typedef struct
{
	char left[20], right[20];
}bus;

//prosedur flushfile
void flushfile(int idx, bus temp[250]);
//prosedur baca file
void readfile(int i[2], bus temp[250]);
//prosedur pencarian di kursi kiri
int searchleft(int idx, bus temp[250], char x[30]);
//prosedur pencari kursi kanan
int searchright(int idx, bus temp[250], char x[30]);
//prosedur untuk turun
void toKosong(int idx, bus temp[250], char x[30]);
//prosedur pengisi kosong
void changekosong(int idx, bus temp[250], char x[30], char y[30]);
//prosedur pengisi depan belakang
void changekosong2(int idx, bus temp[250], char x[30], char y[30], int con);