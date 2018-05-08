#include "EV2FP15.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan EV2FP15 evaluasi 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//fungsi pencari kata yang horizontal
int horisearch(int n ,char in[n][100], char what[100]){
	int i, j, idx=0;//variable loop dan index
	int counter=0, result=0;//penghitung dan jumlah kata yang benar

	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < strlen(in[i]); j+=1)
		{
			if (in[i][j]==what[idx])//setiap char di cek apakah sama atau tidak secara horizontal
			{
				counter+=1;//counter akan bertambah
				idx+=1;//idx juga bertambah
			}
			
			if (counter==strlen(what))//jika panjangnya sama dengan kata yang dicari
			{
				result+=1;//jika ada yang sama maka jumlah hasil bertambah satu
				counter=0;//reset counter
			}
		}
		idx=0;//reset idx
		counter=0;//reset counter
	}
	return result;//mengembalikan nilai hasil fungsi
}
//fungsi pencari kata yang vertikal
int vertisearch(int n ,char in[n][100], char what[100]){
	int i, j, idx=0;// var loop dan idx
	int counter=0, result2=0;//var counter dan hasil kata yang sama
	int maxlen=strlen(in[0]);//panjang maksimal pengecekan huruf secara vertikal
	for (i = 1; i < n; i+=1)
	{
		if (maxlen<strlen(in[i]))//jika ada yang lebih panjang
		{
			maxlen=strlen(in[i]);//akan diganti
		}
	}

	for (i = 0; i < maxlen; i+=1)
	{
		for (j = 0; j < n; j+=1)
		{
			if (in[j][i]==what[idx])//setiap char di cek apakah sama atau tidak secara vertikal
			{
				counter +=1;//counter akan bertambah
				idx+=1;//idx juga bertambah
			}else{
				idx=0;
			}
			
			if (counter==strlen(what))//jika panjangnya sama dengan panjang kata
			{
				result2 += 1;//jika ada yang sama maka jumlah hasil bertambah satu
				counter = 0;//reset counter
			}
		}
		counter = 0;//reset counter
		idx=0;//reset idx
	}
	return result2;//mengembalikan nilai hasil fungsi
}
