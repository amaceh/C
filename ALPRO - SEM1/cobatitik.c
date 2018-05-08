#include <stdio.h>

typedef struct{
	int x;
	int y;
}titik;

int main(){
	titik p1;
	
	printf("masukkan nilai koordinat x:\n");
	scanf("%d", &p1.x);
	printf("masukkan nilai koordinat y:\n");
	scanf("%d", &p1.y);
	
	printf("titik yang anda masukkan: \n");
	printf("x: %d\n", p1.x);
	printf("y: %d\n", p1.y);

	
return 0;
}