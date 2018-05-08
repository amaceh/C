#include "TMPBD16.h"//panggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan TMPBD16 TP5,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int i, n, m, o;//var loop, dan jumlah masing masing biner
	scanf("%d", &n);//masukan jumlah biner dari tobi
	bigdata tobi[n];//deklarasi bungkusan
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &tobi[i].binary);//input setiap biner
		//langsung konversi ke biner
		tobi[i].decimal=binaryconverter(tobi[i].binary);
		//beri kode penunjuk bahwa biner berasal dari tobi
		tobi[i].code='T';
	}
	scanf("%d", &m);//masukan jumlah biner dari moni
	bigdata moni[m];//deklarasi bungkusan
	for (i = 0; i < m; i+=1)
	{
		scanf("%s", &moni[i].binary);//input setiap biner
		//langsung konversi ke biner
		moni[i].decimal=binaryconverter(moni[i].binary);
		//beri kode penunjuk bahwa biner berasal dari moni
		moni[i].code='M';
	}
	scanf("%d", &o);//masukan jumlah biner dari piyu
	bigdata piyu[o];//deklarasi bungkusan
	for (i = 0; i < o; i+=1)
	{
		scanf("%s", &piyu[i].binary);//input setiap biner
		//langsung konversi ke biner
		piyu[i].decimal=binaryconverter(piyu[i].binary);
		//beri kode penunjuk bahwa biner berasal dari piyu
		piyu[i].code='P';
	}
	//urutkan setiap biner.
	quicksortpinggir(n, tobi, 0, n-1);
	quicksortpinggir(m, moni, 0, m-1);
	quicksortpinggir(o, piyu, 0, o-1);
	bigdata merge1[n+m];//deklarasi bungkusan
	bigdata merge2[n+m+o];
	mergetable(n, m, tobi, moni, merge1);//gabungkan data dari tobi dan moni
	mergetable(n+m, o, merge1, piyu, merge2);//gabungkan data dari tobi dan moni serta piyu
	//print sesuai perintah soal
	printf("Laporan Data Biner\n");
	printf("====================\n");
	for (i = 0; i < n+m+o; i+=1)
	{
		printf("%s\n", merge2[i].binary);//print setiap biner
	}
	suspiciousdata(n+m+o, merge2);//panggil prosedur pencetak data "suspicious"
	return 0;
}