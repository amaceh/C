#include "EVDAM.h"//panggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan EVDAM evaluasi 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//prosedur flushfile
void flushfile(int idx, bus temp[250]){
	FILE *damri;//deklarasi file
	damri=fopen("tkursi.txt", "w");//tulis file
	int i;
	for (i = 0; i < idx; i+=1)//tulis sampai habis
	{
		fprintf(damri, "%s %s\n", temp[i].left, temp[i].right);
	}
	fprintf(damri, "%s %s\n", "#*|*#", "#*|*#");//dummy
	fclose(damri);//tutup file
}
//prosedur baca file
void readfile(int i[2], bus temp[250]){
	FILE *damri;//deklarasi file
	bus temp2;//bungkusan tampungan
	damri=fopen("tkursi.txt", "r");//baca file
	i[0]=0;
	fscanf(damri, "%s %s\n", &temp2.left, &temp2.right);//baca dulu
	while(strcmp(temp2.left, "#*|*#")!=0){//cek apakah dummy atau bukan
		strcpy(temp[i[0]].left, temp2.left);
		strcpy(temp[i[0]].right, temp2.right);
		i[0]+=1;//counter bertambah
		fscanf(damri, "%s %s\n", &temp2.left, &temp2.right);
	}//baca sampai habis
	fclose(damri);
}

//prosedur pencarian di kursi kiri
int searchleft(int idx, bus temp[250], char x[30]){
	int i=0, pass=1;//var loop
	while(i<idx && pass==1){//cari sampai habis atau ketemu
		if (strcmp(temp[i].left, x)==0)//jika ketemu
		{
			pass=0;//hentikan
		}
		i+=1;//iterasi
	}
	return pass;//kembalikan hasil pencarian
}
//prosedur pencari kursi kanan
int searchright(int idx, bus temp[250], char x[30]){
	int i=0, pass=1;//var loop
	while(i<idx && pass==1){//cari sampai habis atau ketemu
		if (strcmp(temp[i].right, x)==0)///jika ketemu
		{
			pass=0;//hentikan
		}
		i+=1;//iterasi
	}
	return pass;//kembalikan hasil pencarian
}

//prosedur untuk turun
void toKosong(int idx, bus temp[250], char x[30]){
	int i=0, stop=1;//var loop
	while(stop==1 && i<idx){//cari dulu namanaya
		if (strcmp(temp[i].left,x)==0)//jika dikiri
		{
			stop=0;
			strcpy(temp[i].left, "kosong");//jadikan kosong
		}else if (strcmp(temp[i].right,x)==0)//jika di kanan 
		{	
			stop=0;
			strcpy(temp[i].right, "kosong");//jadikan kosong
		}
		i+=1;//iterasi
	}
}
//prosedur pengisi kosong
void changekosong(int idx, bus temp[250], char x[30], char y[30]){
	int i=0, stop=1;///var loop
	while(stop==1 && i<idx){//cari dulu
		if (strcmp(temp[i].left,"kosong")==0 
			&& strcmp(temp[i].right,y)==0)//jika ada bangku kosong dan posisinya pas
		{
			stop=0;//hentikan
			strcpy(temp[i].left, x);//lalu isi kekosongan
		}else if (strcmp(temp[i].right,"kosong")==0
			&& strcmp(temp[i].left,y)==0)//jika ada bangku kosong dan posisi pas
		{	
			stop=0;//hentikan
			strcpy(temp[i].right, x);//lalu isi kekosongan
		}
		i+=1;//iterasi
	}	
}

//prosedur pengisi depan belakang
void changekosong2(int idx, bus temp[250], char x[30], char y[30], int con){
	int i=0, stop=1;//var loop
	while(stop==1 && i<idx){//cari dulu
		if (strcmp(temp[i+con].left,"kosong")==0
			&& strcmp(temp[i].left,y)==0)//kalauada kursi kosong dan posisinya pas
		{
			stop=0;//hentikan
			strcpy(temp[i+con].left, x);//lalu isi kekosongan
		}else if (strcmp(temp[i+con].right,"kosong")==0 
			&& strcmp(temp[i].right,y)==0)//jika ada kursi kosong dan posisi pass
		{	
			stop=0;//hentikan
			strcpy(temp[i+con].right, x);//lalu isi kekosongan
		}
		i+=1;//iterasi
	}
}