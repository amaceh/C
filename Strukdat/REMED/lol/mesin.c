#include "head.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan REMEDIAL STRUKDAT,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//prosedur deklarasi kosong
void createList(list *L){
	(*L).first = NULL;
}
/*=====Count Element Baris=====*/
int countElementB(list L){
	int hasil = 0;
	if(L.first !=NULL){
		/*list tidak kosong*/
		eBaris *elmt;
		/*inisialisasi*/
		elmt = L.first;
		while(elmt != NULL){
			/*proses*/
			hasil = hasil + 1;
			/*iterasi*/
			elmt = elmt->next;
		}
	}
	return hasil;
}
/*=====Count Element Kolom=====*/
int countElementK(eBaris L){
	int hasil = 0;
	if(L.col !=NULL){
		/*list tidak kosong*/
		eKolom *elmt;
		/*inisialisasi*/
		elmt = L.col;
		while(elmt != NULL){
			/*proses*/
			hasil = hasil + 1;
			/*iterasi*/
			elmt = elmt->next;
		}
	}
	return hasil;
}
/*=====Add First Baris=====*/
void addFirstB(int jumlah, list *L){
	eBaris *elmt;//siapkan pointer
	elmt = (eBaris *) malloc (sizeof (eBaris));//alokasikan memori
	elmt->elmt.jumlah= jumlah;//salin data
	elmt->col = NULL;//belum punay baris
	if((*L).first == NULL){//jika masih kosong
		elmt->next= NULL;
	}else{//jika tidak geser
		elmt->next = (*L).first;
	}
	(*L).first = elmt;//first menjadi elemne
	elmt = NULL;
}
/*=====Add First Kolom=====*/
void addFirstK(char kata[], eBaris *L){
	eKolom *elmt;//siapkan pointer
	elmt = (eKolom *) malloc (sizeof (eKolom));//alokasikan memori
	strcpy(elmt->elmt.kata, kata);//salin data     
	if((*L).col== NULL){//jika kolom kosong
		elmt->next = NULL;
	}else{//jika tidak geser
		elmt->next = (*L).col;
	}
	(*L).col = elmt;
	elmt = NULL; 
}
/*=====Add First Baris=====*/
void addAfterB(eBaris *prev, int jumlah){
	eBaris *elmt;//siapkan pointer
	elmt = (eBaris *) malloc (sizeof (eBaris));//alokasikan memori
	elmt->elmt.jumlah= jumlah;//salin data 
	elmt->col = NULL; 
	if(prev->next == NULL){//jika di akhir
		elmt->next= NULL;
	}else{//jika bukan geser
		elmt->next = prev->next;
	}
	prev->next = elmt;//hubungkan pointer
	elmt = NULL; 
}
/*=====Add After Kolom=====*/
void addAfterK(eKolom *prev, char kata[]){
	eKolom *elmt;
	elmt = (eKolom *) malloc (sizeof (eKolom));//alokasikan memori
	strcpy(elmt->elmt.kata, kata);//salin data
	if(prev->next == NULL){
		elmt->next = NULL;
	}else{//jika tidak geser
		elmt->next = prev->next;
	}
	prev->next = elmt;
	elmt = NULL; 
}
/*=====Add After Baris=====*/
void addLastB(int jumlah, list *L){
	if((*L).first == NULL){
		/*jika list adalah list kosong*/
		addFirstB(jumlah, L);
	}else{
		/*jika list tidak kosong*/
		eBaris *elmt;
		elmt = (eBaris *) malloc (sizeof (eBaris));//alokasikan memori
		elmt->elmt.jumlah= jumlah;       
		elmt->next = NULL;
		elmt->col = NULL;
		/*mencari elemen terakhir list*/
		eBaris *last = (*L).first;
		while(last->next != NULL){ 
			/*iterasi*/
			last = last->next;
		}    
		last->next = elmt;
		elmt = NULL;
	}
}
/*=====Add Last Kolom=====*/
void addLastK(char kata[], eBaris *L){
	if((*L).col == NULL){
		/*jika list adalah list kosong*/
		addFirstK(kata, L);
	}else{
		/*jika list tidak kosong*/
		eKolom *elmt;
		elmt = (eKolom *) malloc (sizeof (eKolom));//alokasikan memori
		strcpy(elmt->elmt.kata, kata);         
		elmt->next = NULL;
		/*mencari elemen terakhir list*/
		eKolom *last = (*L).col;
		while(last->next != NULL){      
			/*iterasi*/
			last = last->next;      
		}
		last->next = elmt;
		elmt = NULL;
	}
}
// /*=====Delete First Baris=====*/
// void delFirstB(list *L){
// 	if((*L).first != NULL){
// 		/*jika list bukan list kosong*/
// 		eBaris *elmt = (*L).first;
// 		if(countElementB(*L) == 1){
// 		(*L).first =NULL;
// 		}else{
// 			(*L).first = (*L).first->next;
// 			elmt->next = NULL;
// 		}
// 		free(elmt);
// 	}
// }
// /*=====Delete First Kolom=====*/
// void delFirstK(eBaris *L){
// 	if((*L).col != NULL){
// 		/*jika list bukan list kosong*/
// 		eKolom *elmt = (*L).col;
// 	if(countElementK(*L) == 1){
// 		(*L).col= NULL;
// 	}else{
// 		(*L).col = (*L).col->next;
// 		elmt->next = NULL;
// 	}
// 	free(elmt);
// 	}
// }
// /*=====Delete After Baris=====*/
// void delAfterB(eBaris *prev){
// 	eBaris *elmt = prev->next;
// 	if(elmt->next == NULL){
// 		prev->next = NULL;
// 	}else{
// 		prev->next = elmt->next;
// 		elmt->next = NULL;
// 	}
// 	free(elmt);
// }
// /*=====Delete After Kolom=====*/
// void delAfterK(eKolom *prev){
// 	eKolom *elmt = prev->next;
// 	if(elmt->next == NULL){
// 		prev->next = NULL;
// 	}else{
// 		prev->next = elmt->next;
// 		elmt->next = NULL;
// 	}
// 	free(elmt);
// }
// /*=====Delete Last Baris=====*/
// void delLastB(list *L){
// 	if((*L).first != NULL){
// 		/*jika list tidak kosong*/
// 		if(countElementB(*L) == 1){
// 			/*list terdiri dari satu elemen*/
// 			delFirstB(L);
// 		}else{
// 			/*mencari elemen terakhir list*/
// 			eBaris *last = (*L).first;
// 			eBaris *before_last;
// 			while(last->next != NULL){
// 				/*iterasi*/
// 				before_last = last;
// 				last = last->next;
// 			}
// 			before_last->next = NULL;
// 			free(last);
// 		}
// 	}
// }
// /*=====Delete Last Kolom=====*/
// void delLastK(eBaris *L){
// 	if((*L).col != NULL){
// 		/*jika list tidak kosong*/
// 		if(countElementK(*L) == 1){
// 			/*list terdiri dari satu elemen*/
// 			delFirstK(L);
// 		}else{
// 			/*mencari elemen terakhir list*/
// 			eKolom *last = (*L).col;
// 			eKolom *before_last;
// 			while(last->next != NULL){
// 				/*iterasi*/
// 				before_last = last;
// 				last = last->next;
// 			}
// 			before_last->next = NULL;
// 			free(last);
// 		}
// 	}
// }
/*=====Print Element=====*/
void printElement(list L){
	if(L.first != NULL){
		/*jika list tidak kosong*/
		/*inisialisasi*/
		eBaris *elmt = L.first;
		int i = 1;
		while(elmt != NULL){
			/*proses*/ 
			//cetak dulu list besar
			printf("%d\n", elmt->elmt.jumlah);
			eKolom *eCol = elmt->col;
			while(eCol != NULL){//lalu list kecil
				printf("%s\n", eCol->elmt.kata);  
				eCol = eCol->next;
			}
			/*iterasi*/
			elmt = elmt->next;
			i = i + 1;
		}
	}else{
		/*proses jika list kosong*/
		printf("list kosong\n");
	}
}
/*=====Delete All Baris=====*/
// void delAllB(list *L){ 
// 	if(countElementB(*L) != 0){
// 		int i;
// 		for(i=countElementB(*L);i>=1;i--){
// 			/*proses menghapus elemen list*/
// 			delLastB(L);   
// 		}
// 	}
// }
/*=====Delete All Kolom=====*/
// void delAllK(eBaris *L){ 
// 	if(countElementK(*L) != 0){
// 		int i;
// 		for(i=countElementK(*L);i>=1;i--){
// 			/*proses menghapus elemen list*/
// 			delLastK(L);   
// 		}
// 	}
// }
//prosedur tambah elemen sesuai jumlah vokal
void addByVoc(char x[], list *L){
	int angka=countVokal(x);
	if ((*L).first==NULL){//jika masih kosng
		addFirstB(angka, L);
		getTheVoc(x);//ubah dulu
		addFirstK(x, (*L).first);
	}else{//jika tidak
		int tanda;
		eBaris *prev,*elmt=(*L).first;
		tanda=0;
		//cari dulu sudah ada atau belum
		while(elmt!=NULL && tanda==0){
			if (elmt->elmt.jumlah==angka){
				getTheVoc(x);//ubah dulu
				addLastK(x, elmt);//tambah diakhir list itu
				tanda = 1;
			}
			prev=elmt;
			elmt=elmt->next;
		}
		if (tanda==0){//jika belum ada tambah diakhir
			addLastB(angka, L);
			elmt=prev->next;
			getTheVoc(x);//ubah dulu
			addFirstK(x, elmt);
			tanda=1;
		}
	}
}
//fungsi hitung jumlah vokal
int countVokal(char x[]){
	int i, res=0,len=strlen(x);
	for (i = 0; i < len; i+=1){//jika ada yang sama
		if (x[i]=='a' || x[i]=='i' || x[i]=='u' || x[i]=='e' || x[i]=='o'){
			res+=1;//tambahkan
		}
	}
	return res;
}
//prosedur ubah kata menjadi vokal saja
void getTheVoc(char x[]){
	char temp[50];
	int i, idx=0,len=strlen(x);
	for (i = 0; i < len; i+=1){//jika ada vokal
		if (x[i]=='a' || x[i]=='i' || x[i]=='u' || x[i]=='e' || x[i]=='o'){
			temp[idx]=x[i];//tambahkan di temporary
			idx+=1;
		}
	}
	temp[idx]='\0';
	strcpy(x, temp);//salin temp
}