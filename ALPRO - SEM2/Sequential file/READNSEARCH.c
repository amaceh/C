#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[10], nama[100], nilai[2];
}nilaiMatkul;

int main()
{
	nilaiMatkul record;
	FILE *recordMatkul;
	recordMatkul=fopen("recordMatkul.dat", "r");
	char kata_cari[10];
	printf("masukkan nim yang dicari : \n");
	scanf("%s", &kata_cari);
	fscanf(recordMatkul, "%s %s %s\n",
		&record.nim, &record.nama,
		&record.nilai);
	if (strcmp(record.nim, "XXXXX")==0){
		printf("arsip kosong\n");
	}else{
		if (strcmp(kata_cari,"XXXXX")==0)
		{
			printf("tidak ditemukan\n");
		}else{
			while(strcmp(record.nim, "XXXXX") !=0 
				&& strcmp(record.nim, kata_cari)!=0){
				fscanf(recordMatkul, "%s %s %s\n",
					&record.nim, &record.nama,
					&record.nilai);
			}
		}
		if (strcmp(record.nim, kata_cari)==0)
		{
			printf("hasil pencarian : \n");
			printf("nim : %s\n", record.nim);
			printf("nama : %s\n", record.nama);
			printf("nilai : %s\n", record.nilai);
			printf("**************\n");
		}else{
			printf("tidak ditemukan\n");
		}
	}
	return 0;
}	