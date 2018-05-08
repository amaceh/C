/*
Buatlah pengurutan Daftar Nilai.
Daftar Nilai terdiri dari nama, kelas, dan nilai.
Urutkan berdasarkan nilai, jika nilainya sama maka urutkan lagi berdasarkan nama.
Pakailah bungkusan, urutkan secara descending dan gunakan insertion sort


input : 
banyak nama,nilai,kelas
daftar nilai (nama, kelas, nilai)

output :
daftar nilai kelas yang sudah diurutkan
Contoh Masukan

5
Tingki C2-2014 60
Wingky C1-2015 70
Dipsi C1-2014 70
Lala C3-2012 60
Poo A-2015 55


Contoh Keluaran

Wingky C1-2015 70
Dipsi C1-2014 70
Tingki C2-2014 60
Lala C3-2012 60
Poo A-2015 55

*/
#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[50];
	char class[20];
	int grade;
}Glist;

Glist arr[100];

void inssortbyname(int x, Glist arr[100]){
	int i, j, temp1;
	char insertion[50], temp2[20];

	for (i = 0; i < x; i+=1)
	{
		strcpy(insertion, arr[i].name);
		strcpy(temp2, arr[i].class);
		temp1=arr[i].grade;
		j=i-1;
		while(strcmp(insertion, arr[j].name)==1 && (j>=0)){
			strcpy(arr[j+1].name, arr[j].name);
			strcpy(arr[j+1].class, arr[j].class);
			arr[j+1].grade=arr[j].grade;
			j=j-1;
		}
		strcpy(arr[j+1].name, insertion);
		strcpy(arr[j+1].class, temp2);
		arr[j+1].grade=temp1;
	}
}
void inssortbygrade(int x, Glist arr[100]){
	int i, insertion, j;
	char temp1[50], temp2[20];
	for (i = 0; i < x; i+=1)
	{
		insertion = arr[i].grade;
		strcpy(temp1, arr[i].name);
		strcpy(temp2, arr[i].class);
		j=i-1;
		while((insertion>arr[j].grade) && (j>=0)){
			arr[j+1].grade=arr[j].grade;
			strcpy(arr[j+1].name, arr[j].name);
			strcpy(arr[j+1].class, arr[j].class);
			j=j-1;
		}
		arr[j+1].grade=insertion;
		strcpy(arr[j+1].name, temp1);
		strcpy(arr[j+1].class, temp2);
	}
}

int main()
{
	int x, i;
	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %s %d", &arr[i].name, &arr[i].class, &arr[i].grade);
	}
	inssortbyname(x, arr);
	inssortbygrade(x, arr);
	for (i = 0; i < x; i+=1)
	{
		printf("%s %s %d\n", arr[i].name, arr[i].class, arr[i].grade);
	}
	return 0;
}
