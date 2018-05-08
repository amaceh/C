#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan REMEDIAL STRUKDAT,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//deklarasi struct
typedef struct{
	int jumlah;
}besar;//container list besar

typedef struct{
	char kata[50];
}kecil;//kontainer list kecil

typedef struct eklm
	*alamatekolom;
typedef struct eklm{
	kecil elmt;
	alamatekolom next;
}eKolom;//satu kolom

typedef struct ebr *alamatebaris;
typedef struct ebr{
	besar elmt;
	eKolom *col;
	alamatebaris next;
}eBaris;//satu baris

typedef struct{
	eBaris *first;
}list;//satu list

//mesin list of list
void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(int jumlah, list *L);
void addFirstK(char kata[], eBaris *L);
void addAfterB(eBaris *prev, int jumlah);
void addAfterK(eKolom *prev, char kata[]);
void addLastB(int jumlah, list *L);
void addLastK(char kata[], eBaris *L);
void delFirstB(list *L);
void delFirstK(eBaris *L);
void delAfterB(eBaris *prev);
void delAfterK(eKolom *prev);
void delLastB(list *L);
void delLastK(eBaris *L);
void printElement(list L);
void delAllB(list *L);
void delAllK(eBaris *L);

//////////////////////////////
/////////////////////////////
int countVokal(char x[]);//prosedur menghitung jumlah vokal
void addByVoc(char x[], list *L);//prosedur tamabh list sesuai vokal
void getTheVoc(char x[]);//prosedur ubah kata menjadi vokal saja