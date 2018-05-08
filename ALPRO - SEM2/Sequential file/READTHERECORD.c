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
	recordMatkul = fopen("recordMatkul.dat", "r");
	printf("isi arsip beruntun adalah : \n");
	fscanf(recordMatkul, "%s %s %s\n", 
		&record.nim, &record.nama, 
		&record.nilai);

	if (strcmp(record.nim, "XXXXX")==0){
		printf("arsip kosong\n");
	}else{
		do
		{
			printf("nim : %s\nnama : %s\nnilai : %s\n",
					record.nim, record.nama, record.nilai);
			printf("****************\n");

			///iterasi
			fscanf(recordMatkul, "%s %s %s\n", 
		&record.nim, &record.nama, 
		&record.nilai);
		} while (strcmp(record.nim, "XXXXX")!=0);
	}

	fclose(recordMatkul);
	return 0;
}	