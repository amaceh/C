#include <stdio.h>

int main() {
	/*soal:
	input 2000000
	40%
	
	output 1200000
	*/
	
	int awal; //variabel awal
	int discount; //variabel discount
	//meminta input
	printf("masukkan harga awal : Rp. ");
	scanf("%d", &awal);
	printf("masukkan jumlah discount (persen) : ");
	scanf("%d", &discount);
	
	//mengolah input
	int potong = awal * discount / 100;
	int hasil = awal - potong;
	//menampilkan hasil
	printf("maka harga akhir adalah : Rp. %d,-\n", hasil);
	
	return 0;
	
	
}