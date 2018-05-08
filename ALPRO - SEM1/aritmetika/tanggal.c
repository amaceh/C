#include <stdio.h>

int main () {
	int tahun; //variabel tahun
	int bulan; //variabel bulan
	int tanggal; //variabel tanggal
	
	//meminta user menginput data
	printf("Masukkan Tahun :\n");
	scanf("%d", &tahun);
	printf("Masukkan Bulan :\n");
	scanf("%d", &bulan);
	printf("Masukkan Tanggal :\n");
	scanf("%d", &tanggal);
	
	//menampillkan output
	printf("Penulisan Tanggal : %d-%d-%d\n", tanggal, bulan, tahun);
	
	return 0;
	}