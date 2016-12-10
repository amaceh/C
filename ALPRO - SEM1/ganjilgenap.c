#include <stdio.h>

int main() {
	int angkasatu, angkadua;//variabel angka pertama dan kedua
	
	//meminta user memasukkan kedua angka
	printf("masukkan angka pertama\n");
	scanf("%d", &angkasatu);
	printf("masukkan angka kedua\n");
	scanf("%d", &angkadua);
	
	//memerika bilangan pertama
	if(angkasatu % 2 == 0){
		printf("bilangan pertama genap\n");
	}else{printf("bilangan pertama ganjil\n");
	}
	//memeriksa bilangan kedua
	if(angkadua % 2 == 0){
		printf("bilangan kedua genap\n");
	}else{printf("bilangan kedua ganjil\n");
	}
	
	return 0;
}