#include <stdio.h>

int main (){
	//kotak angka
	int a, b;
	//meminta masukkan dari user
	printf("masukkan angka pertama :\n");
	scanf("%d",&a);
	printf("masukkan angka ke dua :\n");
	scanf("%d", &b);
	//mengolah angka
	int genap =a*b;
	int ganjil =a+b;
	if((a%2==0) && (b%2==0) && (a!=0) && (b!=0)){
		printf("%d\n", genap);
	}else if ((a%2!=0) && (b%2!=0) && (a!=0) && (b!=0)){
		printf("%d\n", ganjil);
	}else{
		printf("%d %d\n", a, b);
	}
	return 0;
}
