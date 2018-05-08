#include<stdio.h>

typedef struct{ //tipe bungkusan kotak
	int panjang;
	int lebar;
	int tinggi;
	int luaspermukaan;
	int volume;
}balok;

int main(){
	balok b; //bungkusan di dalam main
	
	printf("masukkan nilai koordinat panjang lebar tinggi : \n");
	scanf("%d %d %d", &b.panjang, &b.lebar, &b.tinggi);
	
	b.luaspermukaan = 2* ((b.panjang * b.lebar) + 
						(b.panjang * b.tinggi) + (b.lebar * b.tinggi));
	b.volume = b.panjang * b.lebar * b.tinggi;
	
	printf("luas pemukaan: %d\n", b.luaspermukaan);
	printf("volume: %d\n", b.volume);
	
return 0;
	
}