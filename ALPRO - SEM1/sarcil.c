#include <stdio.h>

int main(){
	int a, b, c;//variabel integer besar
	int x, y, z;//variabel integer kecil
	//meminta input user
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	
	//membuat kotak penanda
	int p=0, q=0, r=0;
		//jika integer besar kelipatan integer kecil pertama
		if(a % x == 0){
		p=1;
		}
		if(b % x == 0){
		q=1;
		}
		if(c % x == 0){
		r=1;
		}
		//jika integer besar kelipatan integer kecil kedua
		if(a % y == 0){
		p=1;
		}
		if(b % y == 0){
		q=1;
		}
		if(c % y == 0){
		r=1;
		}
		//jika integer besar kelipatan integer kecil ketiga
		if(a % z == 0){
		p=1;
		}
		if(b % z == 0){
		q=1;
		}
		if(c % z == 0){
		r=1;
		}
		
	//validasi angka
	if(p+q+r>=2){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}
