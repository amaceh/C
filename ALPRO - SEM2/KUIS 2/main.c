#include "header.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan KUIS 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int x, i;//var jumlah bungkusan dan loop
	scanf("%d", &x);//meminta jumlah bungkusan
	makanan list[x];//deklarasi bungkusan sebanyak x
	char what[10], wanted[20];//string untuk menampung data apa yang dicari
	//dan string penampung pencarian
	int wanted2=0;//int untuk  pencarian harga
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %s %d", &list[i].kode, &list[i].nama, &list[i].harga);
		//meminta input data sebanyak x
	}
	scanf("%s", &what);//input jenis data yg dicari
	strcpy(wanted, "\0");//data diisi nul dulu
	if (strcmp(what, "harga")!=0)//kalau data yang dicari bukan harga
	{
		scanf("%s", &wanted);//input stringnya
	}else{//jika yang dicari harga
		scanf("%d", &wanted2);//input int-nya
	}

	//panggil prosedur selection sort
	selectionsort(x, list, what);
	//panggil prosedur binary search
	binarysearch(x, list, what, wanted, wanted2);

	return 0;
}

/*
3
001 sate 4000
005 gulai 55000
003 soto 34000
kode 005 
#include <time.h>
void wait(float x) {
time_t start;
time_t current;
time(&start);
do
time(&current);
while (difftime(current,start) < x);
}
*/