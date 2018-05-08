#include <stdio.h>

int main(){
	int angka, jumlah=0;

	do{
		scanf("%d", &angka);
		jumlah=jumlah+angka;
	}while(angka!=0);

	printf("Jumlahnya : %d\n", jumlah);
	return 0;
}