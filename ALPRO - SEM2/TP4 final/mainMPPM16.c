#include "MPPM16.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan MPPM16 TP4,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

int main()
{
	int N;//var banyak data
	scanf("%d", &N);//meminta banyak data
	char order1[16], order2[16], nim[N][16], nama[N][30];//string perintah, dan nim serta nama
	scanf("%s", &order1);//meminta perintah pertama
	int i;//var loop

	for (i = 0; i < N; i+=1)
	{
		scanf("%s %s", &nim[i], &nama[i]);//input nim dan nama
	}
	scanf("%s", &order2);//meminta perintah ke dua

	char realnim[N][16], realname[N][30], unnim[N][16], unname[N][30];//string nim nama yang lain
	//real untuk yang sesuai, dan un untuk yang error

	unvalidfinder(N, nim, nama, realnim, realname, unnim, unname, order1, order2);//memanggil prosedur
	return 0;
}