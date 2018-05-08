#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan REMEDIAL STRUKDAT,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main(){
	graph G;//buat graf
	createEmpty(&G);
	
	char in1[50], in2[10];//tampung input
	int x; scanf("%d", &x);
	int i;
	for (i = 0; i < x; i+=1){
		scanf("%s %s", in1, in2);//tampung jalur -jalur
		addByPath(in1, in2, &G);//tambah jalur
	}
	queue Q;//buat queue
	createEmptyQ(&Q);
	int y; scanf("%d", &y);
	for (i = 0; i < y; i+=1){
		scanf("%s", in1);//input masukkan
		checkPath(in1, G, &Q);//cek jejak
	}
	printQueue(Q);//tampilkan hasil
	// printGraph(G);
	return 0;
}