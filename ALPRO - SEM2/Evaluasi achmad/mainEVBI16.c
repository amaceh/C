#include "EVBI16.h"//panggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan EVBI16.h evaluasi,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main()
{
	int i=0, j;//index counter, dan loop
	tab input[256];//deklarasi bungkusan pertama
	do{
		scanf("%s", &input[i].binary);//input setiap biner
		i+=1;//tambah index
	}while (strcmp(input[i-1].binary,"Selesai")!=0);//jika ada input selesai, hentikan input
	int xnum;//var input yang akan dicari
	scanf("%d", &xnum);//meminta input

	converttab(input, i-1);//memanggil prosedur penerjemah biner
	tab big[256];//bungkusan untuk biner bernilai lebih dari 100
	tab little[256];//bungkusan untuk biner bernilai kurang dari 100
	splitthetab(input, big, little, i-1);//panggil prosedur pemecah tab
	printtheresult(input, i-1, xnum);//prosedur print hasil
	return 0;
}