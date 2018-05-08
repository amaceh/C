#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP7,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int x, i;//var input dan loop
	scanf("%d", &x);//input
	data in;//bungkusan input
	int prior;//input prior
	//deklarasi queue
	queue Utama, Gol1, Gol2, Other;
	createEmpty(&Utama);
	createEmpty(&Gol1);
	createEmpty(&Gol2);
	createEmpty(&Other);
	///////////////////////
	//lakukan input sebanyak yang diminta
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %d %d", in.nama, &in.tufel, &prior);
		addPriority(in.nama, in.tufel, prior,&Utama);//add sesuai prioritasnya
	}
	//lakukan seleksi pertama
	KickOut1(&Utama, 5, 650, &Gol1, &Other);
	//lakukan seleksi berikutnya
	KickOut2(&Other, 5, 500, &Gol2);

	///////////////////////
	//print semua hasil seleksi
	//////////////////////
	printf("===Antrian Wawancara Golongan 1===\n");
	printQueue(Gol1);
	printf("===Antrian Wawancara Golongan 2===\n");
	printQueue(Gol2);
	printf("===Sisa Pendaftar===\n");
	printQueue(Other);
	return 0;
}	