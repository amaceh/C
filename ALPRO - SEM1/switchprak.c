#include <stdio.h>

int main(){
	char pilih; //deklarasi variabel
	//panduan untuk user
	printf("Masukkan pilihan anda: \n");
	printf("a) program 1 \n");
	printf("b) program 2 \n");

	//masukan
	scanf(" %c", &pilih);
	//proses pemilihan statement dengan switch
	switch (pilih){
		case 'a':
		printf("run program 1\n");
		break;
		case 'b':{		//menggunakan {} karena >1 statement
		printf("run program 2\n");
		printf("please wait\n");
		}
	break;
		default:
		printf("oppa! inputan anda salah\n");
		break;
	}
return 0;
}
