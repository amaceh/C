#include <stdio.h>

int main () {
	int bilSatu;//membuat variabel untuk bilangan pertama
	int bilDua;//membuat variabel untuk bilangan kedua
	//meminta masukan dari user untuk memulai operasi
	printf ("masukan bilangan pertama:\n");
	scanf ("%d", &bilSatu);
	printf ("masukan bilangan kedua:\n");
	scanf ("%d", &bilDua);
	/*membuat variabel untuk
	menampilkan hasil*/
	int hasil = bilSatu + bilDua;
	//menampilkan hasil pertambahan kedua bilangan
	printf("hasil pertambahan adalah: %d\n", hasil);
	
	return 0;
}