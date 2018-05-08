#include <stdio.h>

int main(){
	int angka1, angka2;
	int pilih; //deklarasi variabel

	printf("angka 1 : ");
	scanf("%d", &angka1); //masukkan angka pertama
	printf("angka 2 : ");
	scanf("%d", &angka2); //masukkan angka kedua

	//panduan untuk user
	printf("Masukkan pilihan anda:\n");
	printf("1. Penjumlahan\n");
	printf("2. Selisih\n");
	printf("3. perkalian\n");
	printf("4. Pembagiam\n");
	printf("5. hasil bagi\n");

	printf("pilihan :");
	scanf("%d", &pilih); //masukan pilihan

	//proses pemilihan statement dengan switch
	switch(pilih){
		case 1 : //jika user memilih pilihan 1
		printf("%d\n", angka1+angka2);
		break;

		case 2 : {//jika user memilih pilihan 2
			//cek angka yang lebih besar
			if(angka1>angka2){
				printf("%d\n", angka1-angka2);
			}else{
				printf("%d\n", angka2-angka1);
			}
			break;
		}

		case 3 ://jika user memilih pilihan 3
			printf("%d\n", angka1*angka2); 
		break;
	
		case 4 : {//jika user memilih pilihan 4
			printf("%d\n", angka1/angka2);
		} 
		break;
		
		case 5 : {//jika user memilih pilihan 5
			printf("%d\n", angka1%angka2);
		}
		break;

		default:
		printf("duhh!!, inputannya ngaco bro \n");
		break;
	}
return 0;
}