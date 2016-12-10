#include <stdio.h>

int main () {
	int nilai_1; //variabel untuk menyimpan nilai 1
	int nilai_2; //variabel untuk menyimpan nilai 2
	
	//variabel untuk menyimpan hasil
	int hasil_tambah;
	int hasil_kurang;
	int hasil_kali;
	int hasil_bagi;
	int hasil_modulus;
	
	printf("nilai 1 :\n");
		//input berupa integer
		scanf("%d", &nilai_1);
	printf("nilai 2 :\n");
		//input berupa integer
		scanf("%d", &nilai_2);
		
		//proses aritmatika
		hasil_tambah = nilai_1 + nilai_2;
		hasil_kurang = nilai_1 - nilai_2;
		hasil_kali = nilai_1 * nilai_2;
		hasil_bagi = nilai_1 / nilai_2;
		hasil_modulus = nilai_1 % nilai_2;
		
	//menampilkan hasil
	printf("Tambah : %d\n", hasil_tambah);
	printf("Kurang : %d\n", hasil_kurang);
	printf("Kali : %d\n", hasil_kali);
	printf("Bagi : %d\n", hasil_bagi);
	printf("Modulus : %d\n", hasil_modulus);
	
	return 0;
}