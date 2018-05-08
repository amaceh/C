#include <stdio.h>

int main(){
	int g;//variabel gehu
	int b;//variabel bala bala
	int p;//variabel pisang
	int c;//variabel cireng
	int h;//variabel lama berjualan
	//meminta masukan jumlah gorengan
	scanf("%d", &g);
	scanf("%d", &b);
	scanf("%d", &p);
	scanf("%d", &c);
	//meminta masukkan jumlah hari
	scanf("%d", &h);
	//memasukkan jumlah laba
	int gehu = 100;
	int bala = 150;
	int pisang = 75;
	int cireng = 175;
	//mengolah angka
	int laba1, laba2, laba3, laba4;//variabel tiap laba total
	int total; //variabel jumlah harga keseluruhan
	
	laba1 = gehu * g;
	laba2 = bala * b;
	laba3 = pisang * p;
	laba4 = cireng * c;
	total = (laba1 + laba2 + laba3 + laba4) * h;
	
	//menampilkan output
	printf("%d\n", total);
	
	return 0;
	}
