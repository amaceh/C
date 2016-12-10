#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[10], nama[100], nilai[2];
}nilaiMatKul;

int main()
{
	nilaiMatKul record1;
	nilaiMatKul record2;
	FILE *recordMatKul1;
	FILE *recordMatKul2;
	FILE *recordMatKul3;
	recordMatKul1 =fopen("recordMatKul1.dat", "r");
	recordMatKul2 =fopen("recordMatKul2.dat", "r");
	recordMatKul3 =fopen("recordMatKul3.dat", "w");
	printf("start to merge the file\n");
	fscanf(recordMatKul1, "%s %s %s\n", &record1.nim, &record1.nama, 
		&record1.nilai);
	fscanf(recordMatKul2, "%s %s %s\n", &record2.nim, &record2.nama, 
		&record2.nilai);
	while(strcmp(record1.nim, "XXXXX")!=0 && strcmp(record2.nim, "XXXXX")!=0){
		if (strcmp(record1.nim,record2.nim)==-1)
		{
			fprintf(recordMatKul3, "%s %s %s\n", record1.nim,
				record1.nama, record1.nilai);
			fscanf(recordMatKul1, "%s %s %s\n", &record1.nim, &record1.nama, 
			&record1.nilai);
		}else if(strcmp(record1.nim,record2.nim)==1){
			fprintf(recordMatKul3, "%s %s %s\n", record2.nim,
			record2.nama, record2.nilai);
			fscanf(recordMatKul2, "%s %s %s\n", &record2.nim, &record2.nama, 
			&record2.nilai);
		}else{
			fprintf(recordMatKul3, "%s %s %s\n", record1.nim,
				record1.nama, record1.nilai);
			fscanf(recordMatKul1, "%s %s %s\n", &record1.nim, &record1.nama, 
			&record1.nilai);
			fprintf(recordMatKul3, "%s %s %s\n", record2.nim,
			record2.nama, record2.nilai);
			fscanf(recordMatKul2, "%s %s %s\n", &record2.nim, &record2.nama, 
			&record2.nilai);
		}
	}
	while(strcmp(record1.nim, "XXXXX")!=0){
		fprintf(recordMatKul3, "%s %s %s\n", record1.nim,
			record1.nama, record1.nilai);
		fscanf(recordMatKul1, "%s %s %s\n", &record1.nim, &record1.nama, 
		&record1.nilai);
	}
	while(strcmp(record2.nim, "XXXXX")!=0){
		fprintf(recordMatKul3, "%s %s %s\n", record2.nim,
			record2.nama, record2.nilai);
		fscanf(recordMatKul2, "%s %s %s\n", &record2.nim, &record2.nama, 
			&record2.nilai);	
	}
	fprintf(recordMatKul3, "%s %s %s\n", "XXXXX", "XXX", "X");
	printf("merging file finished\n");
	fclose(recordMatKul1);
	fclose(recordMatKul2);
	fclose(recordMatKul3);
	return 0;
}