#include <stdio.h>

int main () {
	printf("masukkan angka:\n");
	int nilai;
	scanf("%d", &nilai);
	
	if(nilai >= 80){printf("A");
	}else if((nilai < 80)&&(nilai >= 70)) {
		printf("B");
	}else if((nilai < 70)&&(nilai >= 60)) {
		printf("C");
	}else if((nilai < 60)&&(nilai >= 50)) {
		printf("D");
	}else{
		printf("E");}
	return 0;
}