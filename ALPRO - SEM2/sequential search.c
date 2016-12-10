#include <stdio.h>
#include <string.h>

typedef struct
{
	char nim[50];
	char nama[50];
	float nilai;
}nilaiMatkul;

nilaiMatkul tabel[5];

void isi(int i, char nim[], char nama[], float nilai){
	strcpy(tabel[i].nim, nim);
	strcpy(tabel[i].nama, nama);
	tabel[i].nilai=nilai;
}

// void sequentsearch(int x, nilaiMatkul str[5], char search[]){
// 	int i=0, done=0;
// 	while((i<x) && (done==0)){
// 			if (strcmp(str[i].nim, search)==0)
// 			{
// 				done=1;
// 			}else{
// 				i+=1;
// 			}
// 		}
// 	if (done==1)
// 	{
// 		printf("nim : %s\n", str[i].nim);
// 		printf("nama : %s\n", str[i].nama);
// 		printf("nilai : %0.2f\n", str[i].nilai);
// 	}else{
// 		printf("tidak ditemukan\n");
// 	}
// }

void sequentsearch(int x, nilaiMatkul str[5], char search){
	int i=0, done=0;
	while((i<x) && (done==0)){
			if (str[i].nama[0]==search)
			{
				done=1;
			}else{
				i+=1;
			}
		}
	if (done==1)
	{
		printf("nim : %s\n", str[i].nim);
		printf("nama : %s\n", str[i].nama);
		printf("nilai : %0.2f\n", str[i].nilai);
	}else{
		printf("tidak ditemukan\n");
	}
}

int main()
{
	char nim_cari[50];
	//int ketemu; int i;
	isi(0, "13507701", "Dana", 64.75);
	isi(1, "13507702", "Rudi", 75.11);
	isi(2, "13507703", "Dea", 84.63);
	isi(3, "13507704", "Ahsan", 77.87);
	isi(4, "13507705", "Tiara", 66.70);

	strcpy(nim_cari, "13507703");
	//ketemu=0; i=0;
	// while((i<5) && (ketemu==0)){
	// 	if (strcmp(tabel[i].nim, nim_cari)==0)
	// 	{
	// 		ketemu=1;
	// 	}else{
	// 		i+=1;
	// 	}
	// }
	sequentsearch(5, tabel, 'A');
	return 0;
}	