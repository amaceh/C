#include "head.h"//panggil lib dari header

/*
Saya Achmad Abdul Rofiq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

int main(){
	//deklarasi tree
	tree T;
	int x, i; scanf("%d", &x);//input jumlah simpul
	char input[50];//string tampungan input
	T.root=NULL;

	for (i = 0; i < x; i+=1){//input tree sebanyak user mau
		scanf("%s", input);
		Input(input, &T);//langsung masukkan ke tree
	}
	//list unutk tampungan tanggung jawab dan amal baru
	list L1, L2;
	createList(&L1);
	createList(&L2);	

	//input jumlah tanggung jawab
	scanf("%d", &x);
	for (i = 0; i < x; i+=1){//input tanggung jawab
		scanf("%s", input);
		addLast(input, &L1);//langsung masuk list
	}
	//input jumlah amal
	scanf("%d", &x);
	for (i = 0; i < x; i+=1){
		scanf("%s", input);
		addLast(input, &L2);//langsung masuk list
	}

	queue Len;//queue tampungan panjang kata setiap generasi
	createEmpty(&Len);
	
	LentoQ(T.root, T.root,&Len, 1);//hitung dahulu panjang kata setiap generasi
	printTreePreOrder(T.root, T.root, 0, 0, Len);//lalu cetak pohon
	Tobat(T.root, &L1, &L2);//ganti tanggung jawab dengan amal baik
	printf("\n");//beri jarak
	//hitung lagi panjang kata setiap generasi
	LentoQ(T.root, T.root,&Len, 1);
	printTreePreOrder(T.root, T.root, 0, 0, Len);//cetak lagi pohon
	return 0;
}