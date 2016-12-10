#include <stdio.h>

typedef struct {
	int harga;
	int banyak;
}makanan;
/*kita sudah membuat sebuah bungkusan yang terdiri
dari 2 kotak dengan tipe sama */
int main () {
	makanan nasi_goreng, capcay; //makanan berfungsi sebagai tipe data
	//nasi goren dan capcay berfungsi sebagai variabel

	nasi_goreng.harga=10000;//inisiasi harga
	capcay.harga=4000;

	//panduan untuk user
	printf("masukkan jumlah nasi goreng. \n");
	scanf("%d", &nasi_goreng.banyak);
	printf("masukkan jumlah capcay. \n");
	scanf("%d", &capcay.banyak);

	printf("Total harga nasi goreng : %d\n", 
		nasi_goreng.harga*nasi_goreng.banyak);
	
	printf("Total harga capcay : %d\n", 
		capcay.harga*capcay.banyak);

	return 0;

}