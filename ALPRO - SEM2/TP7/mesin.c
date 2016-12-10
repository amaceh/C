#include "header.h"//panggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan Hitung" IP CERIA TP7,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//prosedur penghitung IP
void counttheIdxPres(IdxPrestasi x[128], int limit){
	int i;//var loop
	for (i = 0; i < limit; i+=1)
	{
		x[i].IP=x[i].mutu/x[i].sks;
		//hitung ip setiap data
	}
}

//prosedur insertion sort
void insertionsort(int x, IdxPrestasi n[128]){
	int i, j;//var loop
	IdxPrestasi insertion;//bungkusan sebagai data sisipan

	for (i = 0; i < x; i+=1)
	{
		//salin data ke insertion
		insertion.IP = n[i].IP;
		strcpy(insertion.nim,n[i].nim);
		strcpy(insertion.nama,n[i].nama);
		j=i-1;
		while((insertion.IP>n[j].IP) && (j>=0)){
		//jika ada data yg lebih besar
		//salin data ke tempatnya
			n[j+1].IP=n[j].IP;
			strcpy(n[j+1].nim,n[j].nim);
			strcpy(n[j+1].nama,n[j].nama);
			j=j-1;
		}
		//lalu kembalikan data dari insertion ke tempatnya
		n[j+1].IP=insertion.IP;
		strcpy(n[j+1].nim,insertion.nim);
		strcpy(n[j+1].nama,insertion.nama);
	}
}
void insertionsort2(int x, IdxPrestasi n[128]){
	int i, j;//var loop
	IdxPrestasi insertion;//bungkusan sebagai data sisipan

	for (i = 0; i < x; i+=1)
	{
		//salin data ke insertion
		insertion.IP = n[i].IP;
		strcpy(insertion.nim,n[i].nim);
		strcpy(insertion.nama,n[i].nama);
		j=i-1;
		while(strcmp(insertion.nim,n[j].nim)==1 && (j>=0)){
		//jika ada data yg lebih besar
		//salin data ke tempatnya
			n[j+1].IP=n[j].IP;
			strcpy(n[j+1].nim,n[j].nim);
			strcpy(n[j+1].nama,n[j].nama);
			j=j-1;
		}
		//lalu kembalikan data dari insertion ke tempatnya
		n[j+1].IP=insertion.IP;
		strcpy(n[j+1].nim,insertion.nim);
		strcpy(n[j+1].nama,insertion.nama);
	}
}

void readthefirst(int counter[2], IdxPrestasi temp1[128]){
	IdxPrestasi record;
	counter[0]=0;
	FILE *firstlist;//deklarasi file firstlist
	firstlist=fopen("firstlist.txt", "r");//buka file secara dibaca
	fscanf(firstlist, "%s %s %f %d\n", &record.nim, &record.nama,
		&record.mutu, &record.sks);//baca data pertama

	if (strcmp(record.nim, "##")!=0)//jika data pertama bukan dummy
	{//salin data
		do
		{
			strcpy(temp1[counter[0]].nim, record.nim);//salin nim
			strcpy(temp1[counter[0]].nama, record.nama);//salin nama
			temp1[counter[0]].mutu=record.mutu;//salin mutu
			temp1[counter[0]].sks=record.sks;//salin sks
			counter[0]+=1;//tambah penghitung
			fscanf(firstlist, "%s %s %f %d\n", &record.nim, &record.nama,
				&record.mutu, &record.sks);//baca data berikutnya			
		} while (strcmp(record.nim, "##")!=0);
		//lakukan proses hingga ditemukan data dummy
		counttheIdxPres(temp1, counter[0]);
		//panggil prosedur penghitung IP
	}
	fclose(firstlist);//close file pertama
}

void readthesecond(int counter[2], IdxPrestasi temp2[128]){
	IdxPrestasi record;
	counter[1]=0;
	FILE *secondlist;//deklarasi file secondlist
	secondlist=fopen("secondlist.txt", "r");//buka file secara dibaca
	fscanf(secondlist, "%s %s %f %d\n", &record.nim, &record.nama,
		&record.mutu, &record.sks);//baca data pertama

	if (strcmp(record.nim, "##")!=0)//jika data pertama bukan dummy
	{
		do
		{//salin data
			strcpy(temp2[counter[1]].nim, record.nim);//salin nim
			strcpy(temp2[counter[1]].nama, record.nama);//salin nama
			temp2[counter[1]].mutu=record.mutu;//salin mutu
			temp2[counter[1]].sks=record.sks;//salin sks
			counter[1]+=1;//tambah penghitung
			fscanf(secondlist, "%s %s %f %d\n", &record.nim, &record.nama,
				&record.mutu, &record.sks);			
		} while (strcmp(record.nim, "##")!=0);
		//lakukan proses hingga ditemukan data dummy
		counttheIdxPres(temp2, counter[1]);
		//panggil prosedur penghitung IP	
	}
	fclose(secondlist);//close file kedua
}

void mergetable(int x, int y, IdxPrestasi a[128], IdxPrestasi b[128]
	, IdxPrestasi d[256]){

	int i=0, j=0, k=0;//variabel
	int counter;//var counter
	while(i<x && j<y){//jika kedua table belum habis
		if (a[i].IP>b[j].IP)//jika tabel a lebih kecil
		{
			//salin nilai table a ke tabel d
			d[k].IP=a[i].IP;
			strcpy(d[k].nim,a[i].nim);
			strcpy(d[k].nama,a[i].nama);
			i+=1; k+=1;
		}else if (b[j].IP>a[i].IP)//jika tabel b lebih kecil
		{
			//salin nilai table b ke tabel d
			d[k].IP=b[j].IP;
			strcpy(d[k].nim,b[j].nim);
			strcpy(d[k].nama,b[j].nama);
			j+=1; k+=1;
		}else{//jika nilai dari kedua tabel sama besar
			//salin keduanya
			//salin nilai table a ke tabel d
			d[k].IP=a[i].IP;
			strcpy(d[k].nim,a[i].nim);
			strcpy(d[k].nama,a[i].nama);
			i+=1; k+=1;
			d[k].IP=b[j].IP;
			strcpy(d[k].nim,b[j].nim);
			strcpy(d[k].nama,b[j].nama);
			j+=1; k+=1;
		}
	}

	if (i<x)//jika table a bersisa
	{
		//salin sisanya
		for (counter = i; counter < x; counter+=1)
		{
			d[k].IP=a[i].IP;
			strcpy(d[k].nim,a[i].nim);
			strcpy(d[k].nama,a[i].nama);
			i+=1; k+=1;
		}
	}

	if (j<y)//jika tabel b bersisa
	{
		//salin sisanya
		for (counter = j; counter < y; counter+=1)
		{
			d[k].IP=b[j].IP;
			strcpy(d[k].nim,b[j].nim);
			strcpy(d[k].nama,b[j].nama);
			j+=1; k+=1;
		}
	}
}
//prosedur pengurut nim bila ada ip yang sama
void sortthesameIP(int x, IdxPrestasi d[256]){
	int i, j, k, l, counter=0, start, idx;//var loop, indeks, dan penanda lainnya
	IdxPrestasi xdata, samedata[128];
	//bungkusan temp, dan penampung data yang ip-nya sama
	for (i = 0; i < x; i+=1)
	{
		xdata.IP=d[i].IP;//salin semua ke temp
		strcpy(xdata.nama,d[i].nama);
		strcpy(xdata.nim,d[i].nim);
		idx=i;
		for (j = idx+1; j < x; j+=1)
		{
			if (xdata.IP==d[j].IP)//jika ada data yang ip-nya sama
			{
				if (counter==0)
				{
					start=j;//pertama pindahkan data di temp ke penampung
					samedata[0].IP=xdata.IP;
					strcpy(samedata[0].nama,xdata.nama);
					strcpy(samedata[0].nim,xdata.nim);
				}
				counter+=1;
				samedata[counter].IP=d[j].IP;//pindahkan juga data berikutnya
				strcpy(samedata[counter].nama,d[j].nama);
				strcpy(samedata[counter].nim,d[j].nim);
				i+=1;
				//indeks i tetap ditambah agar proses tidak diulang
				//(untuk data yang sama)
			}
		}
		if (counter!=0)//jika ada data yang sama ipnya
		{
			//lakukan proses sorting
			l=0;
			insertionsort2(counter+1, samedata);//prosedur sorting
			for (k = start-1; k < start+counter; k+=1)
			{
				d[k].IP=samedata[l].IP;//kemudian ganti posisinya
				strcpy(d[k].nama,samedata[l].nama);
				strcpy(d[k].nim,samedata[l].nim);
				l+=1;
			}
		}
		counter=0;//reset penghitung
	}
}

void createfile(int x, IdxPrestasi d[256]){
	FILE *result;//deklarasi file result
	result=fopen("result.txt", "w");//lakukan penulisan file
	int i;//var loop
	for (i = 0; i < x; i+=1)
	{
		fprintf(result, "%s %s %.2f\n", d[i].nim, d[i].nama, d[i].IP);
	}//masukkan data satu persatu
	fprintf(result, "%s %s %s\n", "##", "##", "##");//tulis data dummy di akhir
	fclose(result);//tutup file
}