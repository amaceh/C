#include "header.h"//panggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan Hitung" IP CERIA TP7,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	IdxPrestasi temp1[128], temp2[128], temp3[256];//deklarasi bungkusan
	//record untuk menampung tiap data
	//kedua temporary untuk menyimpan data dari file kemudian diolah
	int counter[2];
	readthefirst(counter, temp1);//baca data dari file pertama
	readthesecond(counter, temp2);//baca data dari file kedua
	insertionsort(counter[0], temp1);//sortir setiap data
	insertionsort(counter[1], temp2);//sortir setiap data
	mergetable(counter[0],counter[1], temp1, temp2, temp3);
	//merge secara terurut kedua tabel
	sortthesameIP(counter[0]+counter[1], temp3);
	//cari jika ada IP yang sama, lalu sort berdasar IP
	createfile(counter[0]+counter[1], temp3);//write data ke file result
	return 0;
}