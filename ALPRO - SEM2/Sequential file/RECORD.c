#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[10], nama[100], nilai[2];
}nilaiMAtkul;

int main()
{
	nilaiMAtkul record;
	FILE *recordMatkul;
	recordMatkul = fopen("recordMatkul.dat", "w");
	printf("***Tulis record satu persatu***\n");
	printf("Masukkan NIM : \n");
	scanf("%s", &record.nim);

	while(strcmp(record.nim, "XXXXX") !=0){
		printf("Masukkan nama : \n");
		scanf("%s", record.nama);
		printf("Masukkan nilai : \n");
		scanf("%s", record.nilai);

	fprintf(recordMatkul, "%s %s %s\n", record.nim, record.nama, record.nilai);
	//fprintf print ke file
	printf("masukkan nim : \n");
	scanf("%s", &record.nim);
	}

	fprintf(recordMatkul, "%s %s %s\n", "XXXXX", "XXX", "X");
	fclose(recordMatkul);
	return 0;
}