#include "head.h"//panggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP6,
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
void push(char nama[], int waktu, int profit, stack *S){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(elmt->elmt.nama, nama);//isi kontainer
	elmt->elmt.waktu=waktu;//isi kontainer
	elmt->elmt.profit=profit;//isi kontainer
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
		strcpy(temp,S.top->elmt.nama);
	}
	return temp;
}

//prosedur ambil data yang di pop (waktu)
int popreturn2(stack S){	
	int temp2=0;
	if(S.top != NULL){
		// elemen *elmt = S.top;
		temp2=S.top->elmt.waktu;
	}
	return temp2;
}

//prosedur ambil data yang di pop (profit)
int popreturn3(stack S){	
	int temp2=0;
	if(S.top != NULL){
		// elemen *elmt = S.top;
		temp2=S.top->elmt.profit;
	}
	return temp2;
}
//prosedur print isi stack
void printstack(stack S){
	if(S.top != NULL){//cek kosong atau tidak
		elemen *elmt = S.top;//inisiasi
		int sumTime = 0, sumMoney=0;//penampung
		while(elmt != NULL)//lakukan sampai bertemu null
		{
			printf("%s\n", elmt->elmt.nama);//print nama proyek
			sumTime+=elmt->elmt.waktu;//tambah waktunya
			sumMoney+=elmt->elmt.profit;//tambah profitnya
			elmt = elmt->next;//iterasi
		}
		printf("%d %d\n", sumTime, sumMoney);//print totalnya
	}else{
		printf("Stack Kosong\n");
	}
}
//prosedur sorting
void Sorting(stack *S){
	elemen *temp1, *temp2, *temp3, *temp4, *temp5 ;//temp
	temp4 = NULL;

	while(temp4!=(*S).top->next)
	{
		temp3=temp1=(*S).top;
		temp2=temp1->next;

		while(temp1!=temp4){//lakukan perulangan hingga semua data tersorting
			if(temp1->elmt.profit<temp2->elmt.profit){//jika ada profit yang lebih tinggi
				if(temp1==(*S).top){//cek apakah data top terlibat
					//jika iya tukar next
					temp5=temp2->next;
					temp2->next=temp1;
					temp1->next=temp5;
					//juga topnya
					(*S).top=temp2;
					temp3=temp2;
				}
				else{//jika tidak terlibat
					//tukar next
					temp5=temp2->next;
					temp2->next=temp1;
					temp1->next=temp5;
					temp3->next=temp2;
					temp3=temp2;
				}
			}
			else{//jika data lebih kecil
				temp3=temp1;
				temp1=temp1->next;
			}
			
			temp2=temp1->next;
			if(temp2==temp4)
			{
				temp4=temp1;
			}
		}
	}	
}

//prosedur untuk mencari proyek yang paling menguntungkan
void getMaxMoney(stack *S1, stack *S2){
	int sumTime=0;
	do{
		if (sumTime+(popreturn2(*S1))<=250)
		{//cegah waktunya melebihi batas
			sumTime+=popreturn2(*S1);//tambah waktu
			push(popreturn(*S1), popreturn2(*S1), popreturn3(*S1), S2);//masukkab ke stack 2
		}
		pop(S1);//kosongkan stack pertama
		// printf("%d\n", popreturn2(*S1));
	}while((*S1).top!=NULL);//lakukan sampai stack pertama kosong
}