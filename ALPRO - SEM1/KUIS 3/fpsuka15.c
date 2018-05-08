#include "fpsuka15.h"
//memanggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan fpsuka15 Kuis 3,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//////////fungsi penentu banyak genap atau ganjil
int genorganmore(int n, char in[n][50]){
	int i, gen=0, gan=0, out=0;//membuat var lokal
	//looping dan counter genap ganjil dan keluaran fungsi

	for (i = 0; i < n; i+=1)
	{
		if (strlen(in[i])%2==0)
		{
			gen+=1;//jika genap maka counter bertambah
		}else{
			gan+=1;//jika ganjil maka counter bertambah
		}
	}

	if (gen>gan)
	{
		out=1;//jika genap lebih banyak maka fungsi menghasilkan 1
	}else if(gan>gen){
		out=2;//jika ganjil lebih banyak maka fungsi menghasilkan 2
	}
	return out;//mengembalikan keluaran dari fungsi
} 


//prosedur pemutar char
void reversechar(int n, char in[n][50]){
			int i, j, idx;//var lokal looping, dan index pembantu
			char temparostr[n][50];//temporary lokal untuk memutar
			for (i = 0; i < n; i+=1)
			{
				strcpy(temparostr[i], in[i]);//mengopi string
			}
			for (i = 0; i < n; i+=1){
				idx=strlen(in[i])-1;//penentuan jumlah index
				for (j = 0; j < strlen(in[i]); j+=1){	
					in[i][j]=temparostr[i][idx];//mengopi setiap char dari belakan
					idx-=1;//counter berkurang
				}
			}
		}


//prosedur pola 1
void ptrn1(int n, char in[n][50]){
	int i, j, space1=0, space2=0, idx;//var lokal untuk loop, dan penentu spasi
	for (i = 0; i < n/2; i+=1)//loop untuk menampilkan setengah pertama
	{
		for (j = 0; j < space1; j+=1)//loop spasi di belakang
		{
			printf(" ");
		}
		printf("%s\n", in[i]);//print spasi
		space1 +=strlen(in[i]);	//spasi bertambah
	}
	idx=n;
	for (i = n/2; i > 1; i-=1)//penghitung spasi untuk setengah balakang
		{
			space2 +=strlen(in[idx-1]);
			idx-=1;
		}
	idx=n/2;
	for (i = n/2; i > 0; i-=1)//loop untuk menampilkan setengah pertama
	{
		for (j = 0; j < space2; j+=1)//print spasi di belakang
		{
			printf(" ");
		}
		printf("%s\n", in[idx]);//print string
		space2 -=strlen(in[idx+1]);//spasi berkurang
		idx+=1;
	}
}


//prosedur pola dua
void ptrn2(int n, char in[n][50]){
	int i, j, k, square=0;//var lokal untuk loop dan spasi
	for (i = 0; i < n; i+=2)
	{
		for (j = 0; j < strlen(in[i]); j+=1)
		{
			for (k = 0; k < square; k+=1)//loop spasi awal
			{
				printf(" ");
			}
			for (k = 0; k < j; k+=1)//loop spasi segitiga
			{
				printf(" ");
			}
			printf("%c\n", in[i][j]);//printchar diakhir spasi
		}
		for (j = 0; j < strlen(in[i]); j+=1)//loop spasi awal
		{
			printf(" ");
		}
		for (k = 0; k < square; k+=1)//loop spasi awal
			{
				printf(" ");
			}
			printf("%s\n", in[i+1]);//print string
		square=square+strlen(in[i])+strlen(in[i+1]);//penambahan jumlah spasi
	}
}