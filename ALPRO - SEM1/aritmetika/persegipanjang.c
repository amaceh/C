#include <stdio.h>

int main() {
	int Panjang;//mebuat variabel panjang
	int Lebar;//membuat variabel lebar
	//meminta user memasukkan data
	printf("masukkan ukuran panjang:\n");
	scanf("%d", &Panjang);
	printf("masukkan ukuran Lebar\n");
	scanf("%d", &Lebar);
	/*membuat variabel untuk 
	menampilkan luas*/
	int Luas = Panjang * Lebar;
	printf("Luas persegi panjang itu adalah:%d\n", Luas);
	
	return 0;
}