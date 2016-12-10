#include <stdio.h>

main() {
	
	int input; //membuat variabel untuk menampung input angka
	int ribuan; //membuat variabel ribuan
	int ratusan; //membuat variabel ratusan
	int puluhan; //membuat variabel puluhan
	int satuan; //membuat variabel satuan
	//meminta user memasukkan angka
	printf("masukkan angka yang akan dijelaskan:\n");
	scanf("%d", &input);
	//mengolah angka
	ribuan = input / 1000;
	ratusan = (input / 100) - (ribuan * 10);
	puluhan = (input / 10) - (ribuan * 100) - (ratusan * 10);
	satuan = input - (ribuan * 1000) - (ratusan * 100) - (puluhan *10);
	//menampilkan angka
	printf ("ribuan: %d\n", ribuan);
	printf ("ratusan: %d\n", ratusan);
	printf ("puluhan: %d\n", puluhan);
	printf ("satuan: %d\n", satuan);
	
	return 0;
}