#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[10], nama[100], nilai[100];
}nilaiMarKul;

int main()
{
	nilaiMarKul record;
	FILE *recordMatKul1;
	FILE *recordMatKul2;
	recordMatKul1=fopen("recordMatKul1.dat", "r");
	recordMatKul2=fopen("recordMatKul1.bak", "w");
	printf("copying the record\n");
	fscanf(recordMatKul1, "%s %s %s\n",
		&record.nim, &record.nama,
		&record.nilai);
	if (strcmp(record.nim, "XXXXX")==0)
	{
		fprintf(recordMatKul2, "%s %s %s\n", "XXXXX", "XXX", "X");
	}else{
		while(strcmp(record.nim, "XXXXX") !=0){
			fprintf(recordMatKul2, "%s %s %s\n", 
				record.nim, record.nama, record.nilai);
			fscanf(recordMatKul1, "%s %s %s\n", 
				&record.nim, &record.nama, 
				&record.nilai);
		}
		fprintf(recordMatKul2, "%s %s %s\n", 
			"XXXXX", "XXX", "X");
	}

	printf("copying is finished\n");
	fclose(recordMatKul1);
	fclose(recordMatKul2);
	return 0;
}