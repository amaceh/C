#include <stdio.h>//printf, scanf
#include <string.h>//strcpy, strcmp
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan JADKOS15 TP6,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
typedef struct
{
	int days, start, end, timeline[11];
}schedule;//struct berisi jadwal, dan catatan waktu mereka

//----------prosedur pengisi nilai default pada bungkusan
void def(int x, schedule input[x], int y);
//----------prosedur pengisi nilai default pada arr of int
void def2(int tabint[5][11]);
//-----------------------------------------------------

//prosedur pengisi timeline(satu hari bisa ada 2 timeline)
void findthesparetime(int x, schedule input[x]);
//prosedur pengisi timeline(mengabungkan menjadi 1 timeline tiap hari)
void mergethesparetime(int x, schedule input[x], int sparetime[5][11]);
//prosedur pencari ada atau tidaknya jadwal kosong
void finalsearch(int x[5][11], int y[5][11], int z[5][11]);
//prosedur sequential search untuk mencari awal jam kosong
//dan akhir jam kosong
void sequencesearch(int x[5][11], int y[5][11], int z[5][11],
	int j, int i, char spare[5]);