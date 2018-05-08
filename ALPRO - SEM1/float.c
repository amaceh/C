#include<stdio.h>
int main(){
	float a; //kotak angka 
	//meminta input kotak
	scanf("%f", &a);
	//mengambil angka depan koma
	int w = a * 100;
	int x= w / 1000;
	int y=(w/100)-(x*10);
	int z=(w/10)- (x*100) - (y*10);
	
	//mengecek apakah angka depan kelipatan 3 atau bukan
	if(z % 3 == 0){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}