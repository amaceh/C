#include<stdio.h>

int main(){
	printf("Masukkan dua buah angka\n");
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	printf("Pilihlah Menu Berikut: \n");
	printf("1. Tambah\n");
	printf("2. kurang\n");
	printf("3. kali\n");
	
	int menu;
	scanf("%d", &menu);
	
	switch(menu){
	case 1 : {
		printf("hasil tambah : %d\n", (a+b));
		break;
	}
	case 2 : {
		printf("hasil kurang : %d\n", (a-b));
		break;
	}
	case 3 : {
		printf("hasil kali : %d\n", (a*b));
		break;
	}
	default :{
		printf("Menu tidak valid\n");
		break;
	}
	}
return  0;
}