#include "JADKOS15.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan JADKOS15 TP6,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int x, y, z, i;//var jumlah input dan loop

	scanf("%d", &x);//scan jumlah input tobi
	schedule tobi[x];//deklarasi bungkusan
	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &tobi[i].days);//input hari
		scanf("%d", &tobi[i].start);//input jam mulai sibuk
		scanf("%d", &tobi[i].end);//input akhir jam sibuk
	}
	scanf("%d", &y);//scan jumlah input moni
	schedule moni[y];//deklarasi bungkusan
	for (i = 0; i < y; i+=1)
	{
		scanf("%d", &moni[i].days);//input hari
		scanf("%d", &moni[i].start);//input jam mulai sibuk
		scanf("%d", &moni[i].end);//input akhir jam sibuk
	}
	scanf("%d", &z);//scan jumlah input piyu
	schedule piyu[z];//deklarasi bungkusan
	for (i = 0; i < z; i+=1)
	{
		scanf("%d", &piyu[i].days);//input hari
		scanf("%d", &piyu[i].start);//input jam mulai sibuk
		scanf("%d", &piyu[i].end);//input akhir jam sibuk
	}
	//cari timeline merek bertiga
	findthesparetime(x, tobi);
	findthesparetime(y, moni);
	findthesparetime(z, piyu);
	//deklarasi arr of int dari timeline asli mereka
	int tobitime[5][11], monitime[5][11], piyutime[5][11];
	//cari timeline mereka yang sudah di gabungkan
	mergethesparetime(x, tobi, tobitime);
	mergethesparetime(y, moni, monitime);
	mergethesparetime(z, piyu, piyutime);
	//kemudian cari jam kosong dari mereka bertiga
	finalsearch(tobitime, monitime, piyutime);
	return 0;
}