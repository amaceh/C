#include "TMPBD16.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan TMPBD16 TP5,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur konverter biner
int binaryconverter(char xstr[11]){
	int i, biner=1, result=0, idx=0;//deklarasi variabel
	for (i = 9; i >= 0; i-=1)
	{
		if (xstr[i]=='1')//jika ada char bernilai 1
		{
			result=result+biner;//maka tambahkan nilai biner
		}
		biner=biner*2;//pengali nilai biner
	}
	return result;//kembalikan nilai result
}
//prosedur quick sort pivot pinggir
void quicksortpinggir(int x, bigdata a[x], int l, int r){
	int i, j, temp;//var loop dan temp
	i=l;
	j=r;
	char codetemp, temp2[11];//var temp string

	do{
		while((a[i].decimal<a[r].decimal) && (i<=r))
			{//jika ada yang lebih besar
				i=i+1;//tambah indexnya
			}
		while((a[j].decimal>a[l].decimal) && (i<=j))
			{//jika ada yang lebih besar
				j=j-1;//tambah indexnya
			}
		if (i<j)
		{	//pindahkan sesuai index yang didapat diatas
			temp=a[i].decimal;
			a[i].decimal=a[j].decimal;
			a[j].decimal=temp;
			codetemp=a[i].code;
			a[i].code=a[j].code;
			a[j].code=codetemp;
			strcpy(temp2,a[i].binary);
			strcpy(a[i].binary,a[j].binary);
			strcpy(a[j].binary,temp2);
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
//prosedur merge table terurut
void mergetable(int x, int y, bigdata a[x], bigdata b[y], bigdata d[x+y]){

	int i=0, j=0, k=0;//var index
	int counter;//var counter
	while(i<x && j<y){//jika salah satu belum habis
		if (a[i].decimal<b[j].decimal)
		{//jika decimal dari tabel a lebih besar
			//tambahkan data dari tabel a ke tabel gabungan
			d[k].decimal=a[i].decimal;
			d[k].code=a[i].code;
			strcpy(d[k].binary,a[i].binary);
			i+=1; k+=1;//tambah index
		}else if (b[j].decimal<a[i].decimal)
		{//jika decimal dari tabel b lebih besar
			//tambahkan data dari table b ke tabel gabungan
			d[k].decimal=b[j].decimal;
			d[k].code=b[j].code;
			strcpy(d[k].binary,b[j].binary);
			j+=1; k+=1;//tambah index
		}else{//jika ternyata nilai decimal dari kedua table sama
			//salin data dari tabel a ke tabel gabungan
			d[k].decimal=a[i].decimal;
			d[k].code=a[i].code;
			strcpy(d[k].binary,a[i].binary);
			i+=1; k+=1;
			//juga salin data dari tabel b ke tabel gabungan
			d[k].decimal=b[j].decimal;
			d[k].code=b[j].code;
			strcpy(d[k].binary,b[j].binary);
			j+=1; k+=1;
		}
	}

	if (i<x)//jika ternyata data di tabel a bersisa
	{
		//pindahkan semua sisanya ke table gabungan
		for (counter = i; counter < x; counter+=1)
		{
			d[k].decimal=a[counter].decimal;
			d[k].code=a[counter].code;
			strcpy(d[k].binary,a[counter].binary);
			k+=1;//index bertambah
		}
	}

	if (j<y)//jika ternyata data di tabel b bersisa
	{
		//pindahkan semua sisanya ke table gabungan
		for (counter = j; counter < y; counter+=1)
		{
			d[k].decimal=b[counter].decimal;
			d[k].code=b[counter].code;
			strcpy(d[k].binary,b[counter].binary);
			k+=1;//index bertambah
		}
	}
}
//prosedur pencari data "suspicious"
void suspiciousdata(int x, bigdata z[x]){
	int i, j, k;//var loop
	int stop1=0, stop2=0, idx=0, susdata[x], blackIdx[x], idx2=0;
	//var penghenti loop, index, dan arrINT berisi "suspicious" data
	for (i = 0; i < x; i+=1)//loop pertama menjelajahi seluruh data
	{
		j=i+1;//start loop kedua
		while(stop1==0 && j<x){
		//loop kedua mencari data yang sama di bawahnya
			if (z[i].decimal==z[j].decimal && z[i].code!=z[j].code)
			//jika ternyata ada data yang sama dan kodenya berbeda
			{
				stop1=1;//hentikan loop kedua
				k=j+1;//start loop ketiga
				while(stop2==0 && k<x){
				//loop ketiga mencari data yang sama di bawahnya
					if (z[j].decimal==z[k].decimal && z[j].code!=z[k].code
						&& z[i].code!=z[j].code)
					{//jika ternyata ada data yang sama lagi dan kodenya berbeda juga
						stop2=1;//hentikan loop ketiga
						if (blackchecker(idx2,blackIdx,i,j,k)==0)
						{//cek dahulu apakah data sudah digunakan atau belum
							/*
							mencegah suspiciousdata double
							contoh kasus
							2
							1010101010
							1010101010
							2
							1010101010
							1010101010
							2
							1010101010
							1010101010
							dengan cara seperti ini(blacklist index)
							maka outputnya akan
							682
							682
							jika tidak pakai cara ini maka 682 akan 
							keluar lebih banyak
							*/
							susdata[idx]=z[k].decimal;//tambahkan angka itu ke list "suspicious data"
							idx+=1;//penambah index
							//////////////////
							blackIdx[idx2]=i;//tambah index ke daftar blacklist
							blackIdx[idx2+1]=j;//tambah index ke daftar blacklist
							blackIdx[idx2+2]=k;//tambah index ke daftar blacklist
							idx2+=3;
							//////////////////
						}
						
					}else{//jika tidak ada
						k+=1;//lanjutkan loop sampai habis
					}
				}
			}else{//jika tidak ada
				j+=1;//lanjutkan loop sampai habis
			}
		}
		stop1=0;//reset
		stop2=0;//reset
	}
	//print list "suspicious"
	for (i = 0; i < idx; i+=1)
	{
		printf("%d\n", susdata[i]);
	}
}

//fungsi pengecek apakah data sudah digunakan 
//oleh suspicious sebelumnya atau belum
int blackchecker(int x, int black[x], int a, int b, int c){
	int i;//var loop
	int counter=0;//var counter
	for (i = 0; i < x; ++i)
	{
		if (a==black[i] || b==black[i] || c==black[i])
		{//jika ada index yg telah di blacklist
			counter+=1;//tambah index
		}
	}
	if (counter!=0)//jika index bertambah atau ada data yg digunakan
	{
		return 1;//kembalikan nilai 1
	}else{//jika tidak ada
		return 0;//kembalikan nilai 0
	}
}