#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[10], nama[100], nilai[2];
}nilaiMatKul;

int main()
{
	nilaiMatKul record;
	FILE *recordMatKul1;
	FILE *recordMatKul2;
	FILE *recordMatKul3;
	recordMatKul1=fopen("recordMatKul1.dat", "r");
	recordMatKul2=fopen("recordMatKul2.dat", "r");
	recordMatKul3=fopen("recordMatKul3.dat", "w");
	printf("start to merge the file\n");
	fscanf(recordMatKul1, "%s %s %s\n",
		&record.nim, &record.nama, &record.nilai);
	while(strcmp(record.nim, "XXXXX") != 0){
		fprintf(recordMatKul3, "%s %s %s\n", record.nim, record.nama, 
			record.nilai);
		fscanf(recordMatKul1, "%s %s %s\n", &record.nim, &record.nama, 
			&record.nilai);
	}
	fscanf(recordMatKul2, "%s %s %s\n",
		&record.nim, &record.nama, &record.nilai);
	while(strcmp(record.nim, "XXXXX") != 0){
		fprintf(recordMatKul3, "%s %s %s\n", record.nim, record.nama, 
			record.nilai);
		fscanf(recordMatKul2, "%s %s %s\n", &record.nim, &record.nama, 
			&record.nilai);
	}
	fprintf(recordMatKul3, "%s %s %s\n", "XXXXX", "XXX", "X");
	printf("merging file finished\n");
	fclose(recordMatKul1);
	fclose(recordMatKul2);
	fclose(recordMatKul3);
	return 0;
}