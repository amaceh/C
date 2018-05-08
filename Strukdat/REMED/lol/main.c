#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan REMEDIAL STRUKDAT,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main(){

	char input[50];
	int n, i; scanf("%d",&n);//input jumlah masukkan

	list L;//deklarasi list
	createList(&L);

	for(i=0;i<n;i+=1){
		scanf("%s", input);//input
		addByVoc(input, &L);//lalu langsung proses
	}
	printElement(L);//cetak hasil proses

	
	return 0;
}