#include "header.h"
	/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	algoritma dan pemrograman 2 dalam mengerjakan KUIS 2,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin.

	*/
//prosedur selection sort
/*
	karena "binary search" membutuhkan data terurut dalam pencariannya
	maka prosedur ini dibuat agar bisa sorting sesuai permintaan user,
	jika user meminta pencarian harga, maka sorting sesuai harga
	jika user meminta pencarian kode, maka sorting sesuai kode
	jika user meminta pencarian nama, maka sorting sesuai nama
*/
////
void selectionsort(int x, makanan list[x], char xstr[10]){

	int i, miniidx, j;//var loop dan miniidx
	makanan temp;//bungkusan tampungan

	for (i = 0; i < (x-1); i+=1)
	{
		miniidx=i;
		if (strcmp(xstr, "kode")==0)//jika yg dicari adalah kode
		{	
			for (j = i+1; j < x; j+=1)
			{
				if (strcmp(list[miniidx].kode,list[j].kode)==1)
				//jika ada code yang harusnya lebih atas
				{
					miniidx=j;//salin idxnya
				}
			}
		}else if (strcmp(xstr, "nama")==0)//jika yang dicari adalah nama
		{
			for (j = i+1; j < x; j+=1)
			{
				//jika ada nama yang seharusnya lebih atas
				if (strcmp(list[miniidx].nama,list[j].nama)==1)
				{
					miniidx=j;//salin idxnya
				}
			}
		}else if (strcmp(xstr, "harga")==0)//jika yang dicari adalah harga
		{
			for (j = i+1; j < x; j+=1)
			{
				//jika ada harga yang lebih mahal
				if (list[miniidx].harga>list[j].harga)
				{
					miniidx=j;//salin indexnya
				}
			}
		}
		//salin dulu data ke temp
		strcpy(temp.kode,list[i].kode);
		strcpy(temp.nama,list[i].nama);
		temp.harga=list[i].harga;
		//lalu pindahkan data ke tempat seharusnya
		strcpy(list[i].kode,list[miniidx].kode);
		strcpy(list[i].nama,list[miniidx].nama);
		list[i].harga=list[miniidx].harga;
		//lalu kembalikan data dari temp ke tempatnya
		strcpy(list[miniidx].kode,temp.kode);
		strcpy(list[miniidx].nama,temp.nama);
		list[miniidx].harga=temp.harga;
	}
}
//prosedur binary search
void binarysearch(int x, makanan list[x], char xstr[10], char want[20], int want2){

	int i=0, j=x-1, k, done=0;//var atas dan loop, juga penanda pencarian
	if (strcmp(xstr,"kode")==0)//jika yang dicari adalah kode
	{//lakukan pencarian kode
		while(done==0 && i<=j){//jika belum ditemukan dan data belum habis
			k=(int)(i+j)/2;//casting
			if (strcmp(list[k].kode,want)==0)//jika data ditemukan
			{
				done=1;//hentikan loop
			}else{//jika belum
				if (strcmp(list[k].kode,want)==1)//jika data sebelumnya lebih atas
				{
					j=k-1;//ubah batas atas
				}else{//jika tidak
					i=k+1;//ubah batas bawah
				}
			}
		}
	}else if (strcmp(xstr,"nama")==0)//jika yang dicari adalah nama
	{
		while(done==0 && i<=j){//jika belum ditemukan dan data belum habis
			k=(int)(i+j)/2;//casting
			if (strcmp(list[k].nama,want)==0)//jika data ditemukan
			{
				done=1;//hentikan loop
			}else{//jika belum
				if (strcmp(list[k].nama,want)==1)//jika data sebelumnya lebih atas 
				{
					j=k-1;//ubah batas atas
				}else{//jika tidak
					i=k+1;//ubah batas bawah
				}
			}
		}
	}else if (strcmp(xstr,"harga")==0)
	{
		while(done==0 && i<=j){//jika belum ditemukan dan data belum habis
			k=(int)(i+j)/2;//casting
			if (list[k].harga==want2)//jika data ditemukan
			{
				done=1;//hentikan loop
			}else{
				if (list[k].harga==want2)//jika data sebelumnya lebih atas
				{
					j=k-1;//ubah batas atas
				}else{//jika tidak
					i=k+1;//ubah batas bawah
				}
			}
		}
	}
	if (done==1){//jika data ditemukan
		//print
			printf("%s %s %d\n", list[k].kode, list[k].nama, list[k].harga);
	}else{//jika tidak ditemukan
		printf("tidak ada\n");//print tidak ada
	}
}