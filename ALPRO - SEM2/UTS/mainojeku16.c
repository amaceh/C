#include "ojeku16.h"//panggil library

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan ojeku16.h UTS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	char sortby[20];//string sortby
	scanf("%s", &sortby);//perintah sorting
	int n, m, p, i;//var jumlah elemen dan loop
	scanf("%d", &n);//jumlah elemen pertama
	tab a[n];//deklarasi bungkusan pertama
	for (i = 0; i < n; i+=1)
	{
		//input bungkusan
		scanf("%s %s %d %lf", &a[i].name, &a[i].number, &a[i].times, &a[i].komisi);
	}
	scanf("%d", &m);//input elemen kedua
	tab b[m];//deklarasi bungkusan kedua
	for (i = 0; i < m; i+=1)
	{
		//input bungkusan
		scanf("%s %s %d %lf", &b[i].name, &b[i].number, &b[i].times, &b[i].komisi);
	}
	scanf("%d", &p);//input elemen ketiga
	tab c[p];//deklarasi bungkusan ketiga
	for (i = 0; i < p; i+=1)
	{
		//input bungkusan
		scanf("%s %s %d %lf", &c[i].name, &c[i].number, &c[i].times, &c[i].komisi);
	}

	if (strcmp(sortby,"bubble")==0)//jika yang diminta adalah bublesort
	{
		//panggil prosedur untuk setiap bungkusan
		bublesort(n, a);
		bublesort(m, b);
		bublesort(p, c);
	}else if (strcmp(sortby,"insert")==0)//jika yang diminta adalah insertionsort
	{
		//panggil prosedur untuk setiap bungkusan
		insertionsort(n, a);
		insertionsort(m, b);
		insertionsort(p, c);
	}else if (strcmp(sortby,"select")==0)//jika yang diminta adalah selection sort
	{
		//panggil prosedur untuk setiap bungkusan
		selectionsort(n, a);
		selectionsort(m, b);
		selectionsort(p, c);
	}else if (strcmp(sortby,"quick")==0)//jika yang diminta adalah quicksort
	{
		//panggil prosedur untuk setiap bungkusan
		quicksortpinggir(n, a, 0, n-1);
		quicksortpinggir(m, b, 0, m-1);
		quicksortpinggir(p, c, 0, p-1);
	}
	tab d[n+m];//deklarasi bungkusan keempat
	mergetable(n, m, a, b, d);//menggabungkan tabel pertama dan kedua
	tab e[n+m+p];//deklarasi bungkusan kelima
	mergetable(n+m, p, d, c, e);//menggabungkan tabel ke empat dan kelima
	for (i = 0; i < n+m+p; i+=1)
		{
			//print table ke lima
			//gunakan %0. supaya angka belakang koma tidak di print
			printf("%s %s %d %0.lf\n", e[i].name, e[i].number, e[i].times, e[i].komisi);
		}
	return 0;
}	