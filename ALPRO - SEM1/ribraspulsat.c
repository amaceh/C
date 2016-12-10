#include <stdio.h>
int main(){
	//membuat kotak bilangan
	int bil;
	//meminta masukkan user
	printf("masukkan angka yang akan dijelaskan :\n");
	scanf("%d", &bil);
	
	//menjelaskan
	if((bil >= 1000) && (bil <= 9999)){
		printf("angka tersebut ribuan\n");
	}else if ((bil >= 100) && (bil <= 999)){
		printf("angka tersebut ratusan\n");
	}else if ((bil >= 10) && (bil <= 99)){
		printf("angka tersebut puluhan\n");
	}else if ((bil >=1) && (bil <=9)){
		printf("angka tersebut satuan\n");
	}
	return 0;
}