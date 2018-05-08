#include "ojeku16.h"//memanggil library
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan ojeku16.h UTS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur bublesort
void bublesort(int x, tab a[x]){

int i, temp, swap;//var loop, temp, dan penentu
char temp2[100];//string temp

	do{
		swap=0;//reset swap
		for (i = 0; i < x-1; i+=1)
		{
			if (a[i].komisi<a[i+1].komisi)//jika ada yang lebih besar
			{
				//pindahkan nama, nomor, jam, dan komisi ke tempat seharusnya
				strcpy(temp2,a[i].name);
				strcpy(a[i].name,a[i+1].name);
				strcpy(a[i+1].name,temp2);
				strcpy(temp2,a[i].number);
				strcpy(a[i].number,a[i+1].number);
				strcpy(a[i+1].number,temp2);
				temp=a[i].times;
				a[i].times=a[i+1].times;
				a[i+1].times=temp;
				temp=a[i].komisi;
				a[i].komisi=a[i+1].komisi;
				a[i+1].komisi=temp;
				swap=1;//stop
			}
		}
	}while (swap==1);

}

//prosedur insertion sort
void insertionsort(int x, tab a[x]){
	int i, insertion, j, tempint;//var loop, insert, dan temp untuk jam
	char temp[100], temp2[100];//temp untuk nama dan nomor

	for (i = 0; i < x; i+=1)
	{
		//salin dulu ke temp dan insert
		insertion = a[i].komisi;
		tempint = a[i].times;
		strcpy(temp,a[i].name);
		strcpy(temp2,a[i].number);
		j=i-1;
		while((insertion>a[j].komisi) && (j>=0)){//jika ada yang lebih besar
			//pindahkan ke tempat seharusnya
			a[j+1].komisi=a[j].komisi;
			a[j+1].times=a[j].times;
			strcpy(a[j+1].name,a[j].name);
			strcpy(a[j+1].number,a[j].number);
			j=j-1;
		}
		//kembalikan apa yang ada di temp
		a[j+1].komisi=insertion;
		a[j+1].times=tempint;
		strcpy(a[j+1].name,temp);
		strcpy(a[j+1].number,temp2);
	}
}

//prosedur selection sort
void selectionsort(int x, tab a[x]){

int i, miniidx, j, temp;//var loop, miniidx, dan temp
char temp2[100];//string temp

	for (i = 0; i < (x-1); i+=1)
	{
		miniidx=i;
		for (j = i+1; j < x; j+=1)
		{
			if (a[miniidx].komisi<a[j].komisi)//jika ada yang lebih besar
			{
				miniidx=j;//copy indexnya
			}
		}
		//lalu pindahkan sesuai index
		temp=a[i].komisi;
		a[i].komisi=a[miniidx].komisi;
		a[miniidx].komisi=temp;
		temp=a[i].times;
		a[i].times=a[miniidx].times;
		a[miniidx].times=temp;
		strcpy(temp2,a[i].name);
		strcpy(a[i].name,a[miniidx].name);
		strcpy(a[miniidx].name,temp2);
		strcpy(temp2,a[i].number);
		strcpy(a[i].number,a[miniidx].number);
		strcpy(a[miniidx].number,temp2);
	}
}

//prosedur quick sort pivot pinggir
void quicksortpinggir(int x, tab a[x], int l, int r){
	int i, j, temp;//var loop dan temp
	i=l;
	j=r;
	char temp2[100];//var temp string

	do{
		while((a[i].komisi>a[r].komisi) && (i<=r)){//jika ada yang lebih besar
			i=i+1;//tambah indexnya
		}
		while((a[j].komisi<a[l].komisi) && (i<=j)){//jika ada yang lebih besar
			j=j-1;//tambah indexnya
		}
		if (i<j)
		{	//pindahkan sesuai index yang didapat diatas
			temp=a[i].komisi;
			a[i].komisi=a[j].komisi;
			a[j].komisi=temp;
			temp=a[i].times;
			a[i].times=a[j].times;
			a[j].times=temp;
			strcpy(temp2,a[i].name);
			strcpy(a[i].name,a[j].name);
			strcpy(a[j].name,temp2);
			strcpy(temp2,a[i].number);
			strcpy(a[i].number,a[j].number);
			strcpy(a[j].number,temp2);
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)//jika belum habis
	{
		quicksortpinggir(x,a,l,j);//panggil lagi
	}
	if (i<r)//jika belum habis
	{
		quicksortpinggir(x,a,i,r);//panggil lagi
	}
}
//prosedur penggabungan tabel
void mergetable(int x, int y, tab a[x], tab b[y], tab d[x+y]){

	int i=0, j=0, k=0;//var index
	int counter;//var counter
	while(i<x && j<y){//jika salah satu belum habis
		if (a[i].komisi>b[j].komisi)//jika komisi dari tabel a lebih besar
		{
			//tambahkan data dari tabel a ke tabel gabungan
			d[k].komisi=a[i].komisi;
			d[k].times=a[i].times;
			strcpy(d[k].name,a[i].name);
			strcpy(d[k].number,a[i].number);
			i+=1; k+=1;//tambah index
		}else if (b[j].komisi>a[i].komisi)//jika komisi dari tabel b lebih besar
		{
			//tambahkan data dari table b ke tabel gabungan
			d[k].komisi=b[j].komisi;
			d[k].times=b[j].times;
			strcpy(d[k].name,b[j].name);
			strcpy(d[k].number,b[j].number);
			j+=1; k+=1;//tambah index
		}else{//jika ternyata nilai komisi dari kedua table sama
			//salin data dari tabel a ke tabel gabungan
			d[k].komisi=a[i].komisi;
			d[k].times=a[i].times;
			strcpy(d[k].name,a[i].name);
			strcpy(d[k].number,a[i].number);
			i+=1; k+=1;
			//juga salin data dari tabel b ke tabel gabungan
			d[k].komisi=b[j].komisi;
			d[k].times=b[j].times;
			strcpy(d[k].name,b[j].name);
			strcpy(d[k].number,b[j].number);
			j+=1; k+=1;
		}
	}

	if (i<x)//jika ternyata data di tabel a bersisa
	{
		//pindahkan semua sisanya ke table gabungan
		for (counter = i; counter < x; counter+=1)
		{
			d[k].komisi=a[counter].komisi;
			d[k].times=a[counter].times;
			strcpy(d[k].name,a[counter].name);
			strcpy(d[k].number,a[counter].number);
			k+=1;//index bertambah
		}
	}

	if (j<y)//jika ternyata data di tabel b bersisa
	{
		//pindahkan semua sisanya ke table gabungan
		for (counter = j; counter < y; counter+=1)
		{
			d[k].komisi=b[counter].komisi;
			d[k].times=b[counter].times;
			strcpy(d[k].name,b[counter].name);
			strcpy(d[k].number,b[counter].number);
			k+=1;//index bertambah
		}
	}
}