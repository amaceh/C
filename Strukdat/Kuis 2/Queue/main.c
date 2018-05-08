#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan Kuis 2,
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
	queue antri;
	createEmpty(&antri);
	///////////////////////
	//lakukan input sebanyak yang diminta
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %d", in.nama, &prior);
		addPriority(in.nama, prior, &antri);//add sesuai prioritasnya
	}
	int y;//input jumlah yang diprint
	scanf("%d", &y);
	printQueue2(antri, y);//print sesuai yang diinginkan
	return 0;
}	