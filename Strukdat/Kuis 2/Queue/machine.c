#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan Kuis 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
///////////////////		Mesin Queue
//prosedur untuk deklarasi queue kosong
void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;	
}

//fungsi pengecek kosong atau tidaknya queue
int isEmpty(queue Q){
	if (Q.first==NULL){//first null artinya kosong
		return 1;//true
	}else{
		return 0;//false
	}
}

//prosedur hitung elemen queue
int countElement(queue Q){
	int hasil=0;
	if (Q.first!=NULL){//pastikan tidak kosong
		elemen *elmt;
		elmt=Q.first;
		while(elmt!=NULL){//hitung hingga bertemu null
			hasil+=1;
			elmt=elmt->next;
		}
	}
	return hasil;
}

//prosedur add elemen queue
void add(char nama[], queue *Q){
	elemen *elmt;//siapkan elemen
	elmt=(elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(elmt->elmt.nama, nama);//salin data ke elemen
	//posisinya di akhir
	elmt->next=NULL;
	if ((*Q).first==NULL)//jika masih kosong
	{
		(*Q).first=elmt;
	}else{//jika tidak
		(*Q).last->next=elmt;
	}
	(*Q).last=elmt;
	elmt=NULL;

}
//prosedur hapus elemen queue
void del(queue *Q){
	if((*Q).first != NULL){
		/*jika queue tidak kosong*/
		//hapus elemen paling awal
		elemen *elmt= (*Q).first;
		if(countElement(*Q) == 1){//jika hanya terdiri dari 1 elemen
			(*Q).first = NULL;
			(*Q).last = NULL;	
		}else{//jika lebih
			(*Q).first = (*Q).first->next;
			elmt->next = NULL;
		}
		free(elmt);//bebaskan memori
	}
}

//prosedur cetak queue semua
void printQueue(queue Q){
	if (Q.first!=NULL){//pastikan tidak kosong
		elemen *elmt = Q.first;//inisiasi

		int i=1;
		while(elmt!=NULL){//print sampai bertemu null
			printf("%s\n", elmt->elmt.nama);
			//iterasi
			elmt=elmt->next;
			i+=1;
		}
	}else{
		printf("Kosong!\n");
	}
}
//prosedur add elemen sesuai prioritasnya
void addPriority(char nama[], int prior, queue *Q){
	if ((*Q).first!=NULL){//pastikan tidak kosong
		
		elemen *prev,*elmt = (*Q).first;//inisiasi

		int i=1, stop=0;//counter dan penanda
		while(elmt!=NULL && stop==0){//lakukan pencarian posisi yang tepat
			//hingga habis atau tanda berubah
			if (countElement(*Q)<prior || prior==0){//jika kurang diprioritaskan
				add(nama, Q);//langsung add
				stop=1;//hentikan pencarian
			}else if (i==prior){//jika posisi yang tepat ditemukan
				stop=1;//hentikan pencarian
				elemen *baru;//siapkan elemen
				baru = (elemen *) malloc (sizeof(elemen));//alokasikan memori
				//salin data
				strcpy(baru->elmt.nama,nama);
				
				if (elmt==(*Q).first){//jika data merupakan elemen pertama
					baru->next = (*Q).first;
					(*Q).first = baru;
				}else{//jika bukan
					baru->next = prev->next;
					prev->next = baru;
				}
				
				baru = NULL;
			}
		prev=elmt;//simpan dahulu pointer sebelumnya
		//iterasi
		elmt=elmt->next;
		i+=1;
		}
	}else{//jika kosong langsung saja tambahkan
		add(nama, Q);
	}
}

//prosedur cetak queue dengan posisinya, sebanyak yang dimau user
void printQueue2(queue Q, int x){
	if (Q.first!=NULL){//pastikan tidak kosong
		elemen *elmt = Q.first;//inisiasi

		int i=0;
		while(elmt!=NULL && i<x){//print sampai bertemu null, atau sampai sebanyak yang user mau
			printf("%s %d\n", elmt->elmt.nama, i+1);
			//iterasi
			elmt=elmt->next;
			i+=1;
		}
	}else{
		printf("Kosong!\n");
	}
}