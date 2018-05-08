#include <stdio.h>

typedef struct{
	float pembilang;
	float penyebut;
	float hasil;
}bungkus_angka;

int main(){
	int i, n;
	printf("masukkan banyaknya bilangan:");
	scanf("%d", &n);

	bungkus_angka bilangan[n];

	for (i = 0; i < n; i+=1)
	{
		printf("masukkan pembilang %d: ", i+1);
		scanf("%f", &bilangan[i].pembilang);
		printf("masukkan penyebut %d: ", i+1);
		scanf("%f", &bilangan[i].penyebut);
	}

	for (i = 0; i < n; i+=1)
	{
		bilangan[i].hasil=bilangan[i].pembilang/bilangan[i].penyebut;
	}

	for (i = 0; i < n; i+=1)
	{
		printf("hasil dari %.2f dibagi %.2f adalah %.2f\n", 
			bilangan[i].pembilang, bilangan[i].penyebut, bilangan[i].hasil);
	}
	return 0;
}