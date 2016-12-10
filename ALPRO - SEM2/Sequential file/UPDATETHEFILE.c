#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char nim[10], nama[100], nilai[2];
}nilaiMatKul;

int main()
{
	int counter=0;
	nilaiMatKul temp[100];
	nilaiMatKul record, update;
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


	printf("masukkan nim yang akan di update : ");
	scanf("%s", &update.nim);
	int i=0, pass=0;
	while(i<counter && pass==0){
		if (strcmp(update.nim,temp[i].nim)==0)
		{
			pass=1;
		}else{
			i+=1;
		}
	}
	if (pass==0)
	{
		printf("data yg akan di update tidak ada\n");
	}else{
		printf("mau ganti apanya? pilih nomornya\n1.nama\n2.nilai\n3.keduanya\n");
		int select; 
		scanf("%d", &select);
		if (select==1)
		{
			printf("masukkan nama baru : ");
			scanf("%s", &update.nama);
			strcpy(temp[i].nama, update.nama);
		}else if (select==2)
		{
			printf("masukkan nilai baru : ");
			scanf("%s", &update.nilai);
			strcpy(temp[i].nilai, update.nilai);
		}else if (select==3)
		{
			printf("masukkan nama baru : ");
			scanf("%s", &update.nama);
			printf("masukkan nilai baru : ");
			scanf("%s", &update.nilai);
			strcpy(temp[i].nama, update.nama);
			strcpy(temp[i].nilai, update.nilai);
		}
	}
	printf("now updating....\n");
	if (pass!=0)
	{
		recordMatKul=fopen("recordMatKul.dat", "w");
	int k;
	for (k = 0; k < counter; k+=1)
	{
		fprintf(recordMatKul, "%s %s %s\n", temp[k].nim, temp[k].nama,
			temp[k].nilai);
	}
	fprintf(recordMatKul, "%s %s %s\n", "XXXXX", "XXX", "X");
	fclose(recordMatKul);
	}
	printf("update is finished\n");
	system("pause");
	return 0;
}