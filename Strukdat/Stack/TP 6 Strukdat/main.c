#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP6,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int x, i;//var jumlah elemen dan loop
	scanf("%d", &x);//masukkan input
	proyek input;//bungkusan input
	stack S1, S2;//deklarasi stack
	CreateEmpty(&S1);//inisiasi empty stack
	CreateEmpty(&S2);//inisiasi empty stack
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %d %d", input.nama, &input.profit, &input.waktu);
		push(input.nama, input.profit, input.waktu, &S1);
	}//input setiap data ke stack
	Sorting(&S1);//lakukan sorting
	getMaxMoney(&S1, &S2);//cari proyek yang paling untung
	printstack(S2);//print hasilnya
	return 0;
}