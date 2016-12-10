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
	nilaiMatKul record, delete;
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


	printf("masukkan nim dari data yang akan di delete : ");
	scanf("%s", &delete.nim);

	int i=0, pass=0;
	while(i<counter && pass==0){
		if (strcmp(delete.nim,temp[i].nim)==0)
		{
			pass=1;
		}else{
			i+=1;
		}
	}
	if (pass==0)
	{
		printf("data yg akan di delete tidak ada\n");
	}else{
		int j;
		if (i==0)
		{
			for (j = 0; j < counter; j+=1)
			{
				strcpy(temp[j].nim, temp[j+1].nim);
				strcpy(temp[j].nama, temp[j+1].nama);
				strcpy(temp[j].nilai, temp[j+1].nilai);
			}
			//counter-=1;
		}//else if (i==counter)
		//{
		//	counter-=1;
		//}
		else if (i<counter){
			for (j = i; j < counter; j+=1)
			{
				strcpy(temp[j].nim, temp[j+1].nim);
				strcpy(temp[j].nama, temp[j+1].nama);
				strcpy(temp[j].nilai, temp[j+1].nilai);
			}
			//counter-=1;
		}
		counter-=1;
	}
	printf("now deleting....\n");
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
	printf("delete is finished\n");
	return 0;
}