#include <stdio.h>

int main()
{
	char in;

	do{
		printf("Pilihan Menu Makan Siang Mainstream\n");
		printf("1. Mie Bakso\n");
		printf("2. Ayam Penyet\n");
		printf("3. Baso Tahu\n");
		printf("4. Nasi Kucing\n");
		printf("mau menampilkan menu lagi ? Y/N \n");
		scanf(" %c", &in);
	}while(in=='Y');
	
	return 0;
}