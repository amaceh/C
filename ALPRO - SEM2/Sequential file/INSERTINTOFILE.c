#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[10], nama[100], nilai[2];
}nilaiMatKul;

int main()
{
	int counter=0;
	nilaiMatKul temp[100];
	nilaiMatKul record, new;
	FILE *recordMatKul;
	recordMatKul=fopen("recordMatKul.dat", "r");

	printf("begin with fill the array with file data\n");
	fscanf(recordMatKul, "%s %s %s\n", &record.nim, &record.nama,
		&record.nilai);

	if (strcmp(record.nim, "XXXXX")==0)
	{
		printf("record is blank\n");
	}else{
		do
		{
			strcpy(temp[counter].nim, record.nim);
			strcpy(temp[counter].nama, record.nama);
			strcpy(temp[counter].nilai, record.nilai);
			counter+=1;
			fscanf(recordMatKul, "%s %s %s\n", &record.nim, &record.nama,
		&record.nilai);
		} while (strcmp(record.nim, "XXXXX")!=0);
	}
	fclose(recordMatKul);

	printf("input the new data...\n");
	printf("input the nim : ");
	scanf("%s", &new.nim);
	printf("\n");
	printf("input the name : ");
	scanf("%s", &new.nama);
	printf("\n");
	printf("input the grade : ");
	scanf("%s", &new.nilai);
	printf("\n");
	
	if (strcmp(new.nim, temp[0].nim)<0)
	{
		int i;
		for (i = counter-1; i >=0 ; i-=1)
		{
			strcpy(temp[i+1].nim, temp[i].nim);
			strcpy(temp[i+1].nama, temp[i].nama);
			strcpy(temp[i+1].nilai, temp[i].nilai);
		}
		counter+=1;
		strcpy(temp[0].nim, new.nim);
		strcpy(temp[0].nama, new.nama);
		strcpy(temp[0].nilai, new.nilai);
	}else if (strcmp(new.nim, temp[counter-1].nim)>0)
	{
		strcpy(temp[counter].nim, new.nim);
		strcpy(temp[counter].nama, new.nama);
		strcpy(temp[counter].nilai, new.nilai);
		counter+=1;
	}else{
		int i=0;
		int stop=0;
		while(i<counter && stop==0){
			if (strcmp(temp[i].nim, new.nim)>0)
			{
				stop=1;
			}else{
				i+=1;
			}
		}
		int j;
		for (j = counter-1; j>=i ; j-=1)
		{
			strcpy(temp[j+1].nim, temp[j].nim);
			strcpy(temp[j+1].nama, temp[j].nama);
			strcpy(temp[j+1].nilai, temp[j].nilai);
		}
		strcpy(temp[i].nim, new.nim);
		strcpy(temp[i].nama, new.nama);
		strcpy(temp[i].nilai, new.nilai);
		counter+=1;
	}
	
	recordMatKul=fopen("recordMatKul.dat", "w");
	int i;
	for (i = 0; i < counter; i+=1)
	{
		fprintf(recordMatKul, "%s %s %s\n", temp[i].nim, temp[i].nama,
			temp[i].nilai);
	}
	fprintf(recordMatKul, "%s %s %s\n", "XXXXX", "XXX", "X");
	fclose(recordMatKul);
	return 0;
}