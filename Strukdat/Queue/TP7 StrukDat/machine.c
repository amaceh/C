#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP7,
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
void add(char nama[], int tufel, queue *Q){
	elemen *elmt;//siapkan elemen
	elmt=(elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(elmt->elmt.nama, nama);//salin data ke elemen
	elmt->elmt.tufel = tufel;//salin data ke elemen
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

//prosedur cetak queue
void printQueue(queue Q){
	if (Q.first!=NULL){//pastikan tidak kosong
		elemen *elmt = Q.first;//inisiasi

		int i=1;
		while(elmt!=NULL){//print sampai bertemu null
			printf("%s %d\n", elmt->elmt.nama, elmt->elmt.tufel);
			//iterasi
			elmt=elmt->next;
			i+=1;
		}
	}else{
		printf("Kosong!\n");
	}
}
//prosedur add elemen sesuai prioritasnya
void addPriority(char nama[], int tufel,int prior, queue *Q){
	if ((*Q).first!=NULL){//pastikan tidak kosong
		
		elemen *prev,*elmt = (*Q).first;//inisiasi

		int i=1, stop=0;//counter dan penanda
		while(elmt!=NULL && stop==0){//lakukan pencarian posisi yang tepat
			//hingga habis atau tanda berubah
			if (countElement(*Q)<prior || prior==0){//jika kurang diprioritaskan
				add(nama, tufel, Q);//langsung add
				stop=1;//hentikan pencarian
			}else if (i==prior){//jika posisi yang tepat ditemukan
				stop=1;//hentikan pencarian
				elemen *baru;//siapkan elemen
				baru = (elemen *) malloc (sizeof(elemen));//alokasikan memori
				//salin data
				strcpy(baru->elmt.nama,nama);
				baru->elmt.tufel=tufel;
				
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
		add(nama, tufel, Q);
	}
}

/////////////////////////////////////////////////////////

///bikin pemindahan jika penuh goloangan pertama
void KickOut1(queue *Q1, int limit, int score,queue *Q2, queue *Q3){
	if ((*Q1).first!=NULL){//pastikan queue tidak kosong
		elemen *elmt = (*Q1).first;//inisiasi

		int count=0;
		while(elmt!=NULL){//lakukan proses sampai habis
			if (elmt->elmt.tufel >= score && count<limit){
			//jika memenuhi syarat dan kuota belum habis
				add(elmt->elmt.nama,elmt->elmt.tufel,Q2);//tambahkan di antrian gol 1
				count+=1;//kuota berkurang
			}else{//selain itu akan di proses di golongan berikutnya
				add(elmt->elmt.nama,elmt->elmt.tufel,Q3);
			}
			del(Q1);//hapus data yang di proses karena sudah dimutasi ke gol lain
			elmt=(*Q1).first;//iterasi mengikuti prinsip delete
			// elmt=elmt->next;
		}
	}	
}
///bikin pemindahan jika penuh goloangan kedua
void KickOut2(queue *Q1, int limit, int score,queue *Q2){
	if ((*Q1).first!=NULL){//pastikan data tidak kosong
		elemen *elmt = (*Q1).first;//inisiasi

		int count=0, stop=0;//penghitung dan penanda
		while(elmt!=NULL && stop==0){//lakukan proses sampai kuota terpenuhi atau data habis
			if (elmt->elmt.tufel >= score && count<limit){//jika memenuhi syarat dan kuota belum habis
				add(elmt->elmt.nama,elmt->elmt.tufel,Q2);
				count+=1;//kuota berkurang
			}
			del(Q1);//hapus saja data yang gugur
			elmt=(*Q1).first;//iterasi mengikuti prinsip delete
			if (count==limit){//jika kuota habis tapi masih ada pelamar
				stop=1;//hentikan dulu proses, agar data tetap ada di daftar tunggu
			}
			// elmt=elmt->next;
		}
	}	
}

/* 
26
A 500 4
B 250 0
C 680 0
D 800 5
E 100 0
F 000 1
G 1000 1
H 400 0
I 245 0
J 425 0
K 525 0
L 925 1
M 720 8
N 470 0
O 480 0
P 310 0
Q 340 0
R 759 9
S 727 0
T 282 0
U 218 0
V 651 0
W 281 0
X 998 2
Y 141 0
Z 830 1


===Antrian Wawancara Golongan 1===
Z 830
L 925
X 998
G 1000
C 680
===Antrian Wawancara Golongan 2===
A 500
D 800
M 720
R 759
K 525
===Sisa Pendaftar===
N 470
O 480
P 310
Q 340
S 727
T 282
U 218
V 651
W 281
Y 141
*/