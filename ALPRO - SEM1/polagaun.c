#include <stdio.h>
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan polagaun UTS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main(){
	
	int line, colm, star;//membuat variabel baris, kolom, dan banyak bintang
	//meminta input
	scanf("%d", &star);

	//pola dibuat 3 lapisan
	for (line = 1; line <= star; line+=1){//for induk untuk membuat newline lapis satu
		//membuat spasi berbentuk segitiga tebalik
		for (colm = star; colm-1 >= line; colm-=1){
			printf(" ");
		}
		//pola bintang segitiga
		for (colm = 1; colm <= line; colm+=1){
			printf("*");
		}
		//pola bintang kotak
		for (colm = 1; colm <= star; colm+=1){
			printf("*");
		}
		//spasi berbentuk kotak
		for (colm = 1; colm <= star; colm+=1){
			printf(" ");
		}
		//pola bintang kotak
		for (colm = 1; colm <= star; colm+=1){
			printf("*");
		}
		//pola bintang segitiga
		for (colm = 1; colm <= line; colm+=1){
			printf("*");
		}
		printf("\n");
	}

	for (line = 1; line <= star; line+=1){//for induk untuk membuat newline di lapis 2
		//membuat 2 kotak spasi sekaligus
		for (colm = 1; colm <= star*2; colm+=1){
			printf(" ");
		}
		//pola bintang kotak 
		for (colm = 1; colm <= star; colm+=1){
			printf("*");
		}
		printf("\n");
	}

	for (line = 1; line <= star; line+=1){//for induk untuk membuat newline di lapis 3
		//membuat kotak spasi yang lebarnya star-1
		for (colm = 1; colm <= star-1; colm+=1){
			printf(" ");
		}
		//spasi berbentuk segitiga terbalik
		for (colm = star; colm >= line; colm-=1){
			printf(" ");
		}
		//pola bintang segitiga
		for (colm = 1; colm <= line; colm+=1){
			printf("*");
		}
		//pola bintang kotak
		for (colm = 1; colm <= star; colm+=1){
			printf("*");
		}
		//pola bintang segitiga
		for (colm = 1; colm <= line; colm+=1){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}