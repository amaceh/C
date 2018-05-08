#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan Kuis 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int x, y, i, j;//var jumlah elemen dan loop
	scanf("%d", &x);//masukkan input
	data input;//bungkusan input
	stack S;//deklarasi stack
	CreateEmpty(&S);//inisiasi empty stack
	for (i = 0; i < x; i+=1){
		scanf("%d", &y);//masukkan input baris skrip
		for (j = 0; j < y; j+=1){
			scanf("%s", input.string);
			push(input.string, &S);//push setiap skrip ke stack
		}
	}//input setiap data ke stack
	stack hasil;//deklarasi stack baru untuk tampung hasil proses
	CreateEmpty(&hasil);//inisiasi empty stack
	proses(&S, &hasil);//lalu proses skrip yang ada di stack
	printstack(hasil);//tampilkan semua hasil proses
	return 0;
}