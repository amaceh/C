#include <stdio.h>

int main (){
	float bil;//variabel float
	int depan;//variabel angka depan
	int belakang;//variabel angka belakang
	
	printf ("masukkan angka float:\n");
	scanf ("%f", &bil);
	
	depan = bil ; //mengambil angka depan
	belakang = (bil - depan) * 100; //mengambil angka belakang
	
	//menampilkan kedua angka
	printf ("angka depan adalah: %d\n", depan);
	printf ("angka belakang adalah: %d\n", belakang);
	
	return 0;
	}