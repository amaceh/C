#include "arintstr.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan PURTP15 TP 10,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

////fungsi pembanding arr of int
int compare(int n, int in[n]){
	int i;//var loop
	int min1, min2;//var nilai terkecil setengah awal dan akhir

	min1=in[0];//nilai awal dari arr ke 0
	for (i = 1; i < n/2; i+=1)//mencari nilai terkecil dari setengah awal
	{
		if (min1>in[i])//jika ada yang lebih kecil
		{
			min1=in[i];//nilai diganti dengan nilai tersebut
		}
	}
	min2=in[n/2];//nilai awal dari arr ke 0
	for (i = n/2+1; i < n; i+=1)//mencari nilai terkecil dari setengah akhir
	{
		if (min2>in[i])//jika ada yang lebih kecil
		{
			min2=in[i];//nilai diganti dengan nilai tersebut
		}
	}
	int out;//variabel hasil perbadingan
	if (min1>min2)//jika hasil setengah awal lebih besar 
	{
		out=min1;//hasil adalah hasil setengah awal
	}else if(min1<min2){//jika hasil setengah awal lebih besar 
		out=min2;//hasil adalah hasil setengah awal
	}

	return out;//mengembalikan nilai hasil perbandingan
}

//prosedur print string kelipatan hasil fungsi
void printstring(int m, char in[m][50], int x){
	int i;//var loop
	printf("%d\n", x);//print hasil perbandingan
	for (i = 0; i < m; i+=1)
	{
		if ((i+1)%x==0)//jika posisi string adalah kelipatan hasil perbandingam
		{
			printf("%s\n", in[i]);//print string tersebut
		}
	}
}