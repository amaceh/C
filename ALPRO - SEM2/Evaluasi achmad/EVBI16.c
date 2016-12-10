#include "EVBI16.h"//panggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan EVBI16.h evaluasi,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur konverter biner ke desimal
int binaryconverter(char xstr[9]){
	int i, biner=1, result=0, idx=0;//deklarasi variabel
	for (i = 7; i >= 0; i-=1)
	{
		if (xstr[i]=='1')//jika ada char bernilai 1
		{
			result=result+biner;//maka tambahkan nilai biner
		}
		biner=biner*2;//pengali nilai biner
	}
	return result;//kembalikan nilai result
}
//prosedur konverter isi tab
void converttab(tab input[256], int counter){
	int i;//var loop
	for (i = 0; i < counter; i+=1)
	{
		input[i].decimal=binaryconverter(input[i].binary);//konvert setiap biner
	}
}

void insertionsort(int x, tab xtab[256]){
	
	int i, insertion, j;//variabel loop dan insertion
	char temp[9];//var temp

	for (i = 0; i < x; i+=1)
	{
		//salin dulu ke temp dan insertion
		insertion = xtab[i].decimal;
		strcpy(temp,xtab[i].binary);
		j=i-1;
		while((insertion<xtab[j].decimal) && (j>=0)){//jika ada yg lebih kecil
			//salin ke tempat seharusny
			xtab[j+1].decimal=xtab[j].decimal;
			strcpy(xtab[j+1].binary,xtab[j].binary);
			j=j-1;
		}
		//kembalikan nilai dari temp dan insertion ke tempat seharusnya
		xtab[j+1].decimal=insertion;
		strcpy(xtab[j+1].binary,temp);
	}
}
//prosedur merge table terurut
void mergetable(int x, int y, tab a[256], tab b[256], tab d[256]){

	int i=0, j=0, k=0;//variabel
	int counter;//var counter
	while(i<x && j<y){//jika kedua table belum habis
		if (a[i].decimal<b[j].decimal)//jika tabel a lebih kecil
		{
			//salin nilai table a ke tabel d
			d[k].decimal=a[i].decimal;
			strcpy(d[k].binary,a[i].binary);
			i+=1; k+=1;
		}else if (b[j].decimal<a[i].decimal)//jika tabel b lebih kecil
		{
			//salin nilai table b ke tabel d
			d[k].decimal=b[j].decimal;
			strcpy(d[k].binary,b[j].binary);
			j+=1; k+=1;
		}else{//jika nilai dari kedua tabel sama besar
			//salin keduanya
			d[k].decimal=a[i].decimal;
			strcpy(d[k].binary,a[i].binary);
			i+=1; k+=1;
			d[k].decimal=b[j].decimal;
			strcpy(d[k].binary,b[j].binary);
			j+=1; k+=1;
		}
	}

	if (i<x)//jika table a bersisa
	{
		//salin sisanya
		for (counter = i; counter < x; counter+=1)
		{
			d[k].decimal=a[counter].decimal;
			strcpy(d[k].binary,a[counter].binary);
			k+=1;
		}
	}

	if (j<y)//jika tabel b bersisa
	{
		//salin sisanya
		for (counter = j; counter < y; counter+=1)
		{
			d[k].decimal=b[counter].decimal;
			strcpy(d[k].binary,b[counter].binary);
			k+=1;
		}
	}
}

//prosedur pembagi tab
void splitthetab(tab input[256], tab big[256], tab litte[256],int counter){
	int i, j=0, k=0;//var loop
	for (i = 0; i < counter; i+=1)
	{
		if (input[i].decimal>100)//jika nilainya lebih dari 100
		{
			//tambahkan ke tab besar
			big[j].decimal=input[i].decimal;
			strcpy(big[j].binary,input[i].binary);
			j+=1;
		}else if (input[i].decimal<=100)//jika nilainya kurang dari 100
		{
			//tambahkan ke tab kecil
			litte[k].decimal=input[i].decimal;
			strcpy(litte[k].binary,input[i].binary);
			k+=1;
		}
	}
	//langsung sortir disini
	insertionsort(j, big);//sortir table besar
	insertionsort(k, litte);//sortir table kecil
	mergetable(j, k, big, litte, input);//gabuung kembali
}
//prosedur pencetak hasil
void printtheresult(tab x[256], int counter, int order){
	int stop=0, i=0, j;//var stop, loop
	while((stop==0) && (i<counter)){//jika stop bernilai nol dan i lebih kecil dari counter
		if (x[i].decimal==order)//jika ada angka desimal yang sama dengan yang dicari
		{
			stop=1;//hentikan proses
			//print setiap biner
			for (j = 0; j < counter; j+=1)
			{
				printf("%s\n", x[j].binary);
			}
			//print indexnya juga
			printf("index %d\n", i+1);
		}
		i+=1;//penambah index
	}
	if (stop==0)//kalau proses berhenti tanpa hasil
	{
		//print sesuai permintaan
		printf("data not found\n");
	}
}