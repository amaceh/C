#include "bk16.h"//memanggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan bk16 kuis1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int L, C;//var baris dan kolom
	scanf("%d %d", &L, &C);//meminta masukan jumlah baris dan kolom
	int mtrx1[L][C], mtrx2[L][C];//matrix baris dan kolom
	int i, j;//var loop
	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			scanf("%d", &mtrx1[i][j]);//masukan tiap matrix
		}
	}
	int count=0;//var counter
	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			mtrx2[i][j]=underone2(mtrx1[i][j], count);//memasukkan nilai counter ke setiap matrix ke 2
		}
		count=0;//reset counter
	}

	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			printf("(%d, %d)", mtrx1[i][j], mtrx2[i][j]);//print sesuai permintaan
			if (j<C-1)//print spasi kecuali di akhir
			{
				printf(" ");
			}
		}
		printf("\n");//newline tiap baris
	}

	return 0;
}