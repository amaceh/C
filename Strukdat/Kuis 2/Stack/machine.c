#include "head.h"//panggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan Kuis 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedru inisiasi stack kosong
void CreateEmpty(stack *S){
	(*S).top = NULL;
}
//fungsi pengecek kosong atau tidaknya stack
int IsEmpty(stack S){
	int hasil = 0;
	if(S.top == NULL){//jika top kosong
		hasil = 1;//berarti memang kosong
	}
	return hasil;
}
//prosedur penghitung elemen
int CountElement(stack S){
	int hasil = 0;
	if(S.top != NULL){//jika tidak kosong
		elemen *elmt;

		elmt = S.top;

		while(elmt != NULL){//lakukan hitung sampai ketemu null
			hasil = hasil + 1;
			elmt = elmt->next;
		}
	}
	return hasil;//kembalikan hasil
}
//prosedur push stack
void push(char string[], stack *S){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(elmt->elmt.string, string);//isi kontainer
	if((*S).top == NULL){//jika stack kosong
		elmt->next = NULL;
	}else{//jika tidak kosong
		elmt->next = (*S).top;
	}
	(*S).top = elmt;
	elmt = NULL;
}

void push2(char string[], int angka,stack *S){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(elmt->elmt.string, string);//isi kontainer
	elmt->elmt.angka=angka;//isi kontainer
	if((*S).top == NULL){//jika stack kosong
		elmt->next = NULL;
	}else{//jika tidak kosong
		elmt->next = (*S).top;
	}
	(*S).top = elmt;
	elmt = NULL;
}


//prosedur pop stack
void pop(stack *S){
	if((*S).top != NULL){
		//jika list kosong
		elemen *elmt = (*S).top;
		if(CountElement(*S) == 1){//jika hanya terdiri dari 1 elemen
			(*S).top=NULL;
		}else{//jika tidak
			(*S).top= (*S).top->next;
			elmt->next=NULL;
		}
		free(elmt);//bebaskan memori
	}
}
//prosedur ambil data yang di pop (nama)
char* popreturn(stack S){	
	if(S.top != NULL){
		// elemen *elmt = S.top;
		strcpy(temp,S.top->elmt.string);
	}
	return temp;
}

// prosedur print isi stack
void printstack(stack S){
	if(S.top != NULL){//cek kosong atau tidak
		elemen *elmt = S.top;//inisiasi
		while(elmt != NULL)//lakukan sampai bertemu null
		{
			printf("%s = %d\n", elmt->elmt.string, elmt->elmt.angka);//print nama proyek
			elmt = elmt->next;//iterasi
		}
	}else{
		printf("Stack Kosong\n");
	}
}
// //prosedur proses skrip hitung
// void printHasil(stack *S){
// 	data var[50];//tampungan variabel
// 	int angka[50];//tampungan nilai
	
// 	int hit1=0;//penghitung operasi (jumlah variabel juga)
// 	angka[hit1]=0;//nilai pertama di nolkan
// 	if((*S).top != NULL){//cek kosong atau tidak stacknya
// 		elemen *elmt=(*S).top;//inisiasi
// 		while(elmt != NULL)//lakukan sampai bertemu null
// 		{
// 			if (atoi(popreturn(*S))!=0 && strcmp(popreturn(*S), "=")!=0 && strcmp(popreturn(*S), "+")!=0){
// 				//perikas apakah benar angka yang di pop, jika iya tambah ke tampungan nilai
// 				angka[hit1]+=atoi(popreturn(*S));//tambah jika memang angka
// 			}else if (atoi(popreturn(*S))==0 && strcmp(popreturn(*S), "=")!=0 && strcmp(popreturn(*S), "+")!=0){//string selain angka pasti returnnya nol
// 				//perikas ini variabel atau bukan
// 				strcpy(var[hit1].string, popreturn(*S));//jika iya tambah ke tampungan variabel
// 				hit1+=1;//tambah hitungan operasi
// 				angka[hit1]=0;//inisasi tampungannya
// 			}
// 			pop(S);//pop
// 			elmt=(*S).top;//iterasi
// 		}
// 	}
// 	int i;
// 	for (i = hit1-1; i >=0 ; i-=1){//print hasil proses
// 		printf("%s = %d\n", var[i].string, angka[i]);
// 	}
// }

//prosedur proses skrip hitung
void proses(stack *S, stack *S2){
	int angka;//tampungan nilai
	angka=0;//nilai pertama di nolkan
	if((*S).top != NULL){//cek kosong atau tidak stacknya
		elemen *elmt=(*S).top;//inisiasi
		while(elmt != NULL)//lakukan sampai bertemu null
		{
			if (atoi(popreturn(*S))!=0 && strcmp(popreturn(*S), "=")!=0 && strcmp(popreturn(*S), "+")!=0){
				//perikas apakah benar angka yang di pop, jika iya tambah ke tampungan nilai
				angka+=atoi(popreturn(*S));//tambah jika memang angka
			}else if (atoi(popreturn(*S))==0 && strcmp(popreturn(*S), "=")!=0 && strcmp(popreturn(*S), "+")!=0){//string selain angka pasti returnnya nol
				//perikas ini variabel atau bukan
				push2(popreturn(*S), angka, S2);//jika iya tambahkan ke stack lain
				angka=0;//inisasi tampungannya
			}
			pop(S);//pop
			elmt=(*S).top;//iterasi
		}
	}
}