#include <stdio.h>

int main (){
	int n, m, p;//variabel jumlah domba
	int a, b, c;//variabel lama domba melompat
	int jam, menit, detik; //variabel waktu
	
	//meminta input setiap angka
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &p);
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	//mengolah angka
	int hasil = (n*a)+(m*b)+(p*c);
	//mengolah jam
	jam = (hasil%3600)/60;
	menit = ((hasil%3600)%60);
	detik = 0;//hasil dianggap menit detik pasti nol
	
	//menampilkan waktu
	printf("%.2d:%.2d:%.2d\n", jam, menit, detik);
	return 0;
}

