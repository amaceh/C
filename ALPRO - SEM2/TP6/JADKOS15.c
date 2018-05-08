#include "JADKOS15.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan JADKOS15 TP6,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//----------prosedur pengisi nilai default pada bungkusan
void def(int x, schedule input[x], int y){
	int i;
	for (i = 0; i < 11; i+=1)
	{
		input[y].timeline[i]=0;//isi dengan nilai default
	}
}
//----------prosedur pengisi nilai default pada arr of int
void def2(int tabint[5][11]){
	int i, j;
	for (i = 0; i < 5; i+=1)
	{
		for (j = 0; j < 11; j+=1)
		{
			tabint[i][j]=0;//isi dengan nilai default
		}
	}
}

//prosedur pengisi timeline(satu hari bisa ada 2 timeline)
void findthesparetime(int x, schedule input[x]){
	int i, j;
	//timeline dari jam 7 sampai jam 18
	//default waktu mereka kosong/tidak ada kegiatan
	for (i = 0; i < x ; i+=1)
	{
		def(x, input, i);//ubah menjadi nilai default dahulu
		for (j = input[i].start-7; j < input[i].end-7; j+=1)
		{//tulis waktu sibuk sesuai input
			input[i].timeline[j]=1;//waktu sibuk bernilai 1
		}
	}
}

//prosedur pengisi timeline(mengabungkan menjadi 1 timeline tiap hari)
void mergethesparetime(int x, schedule input[x], int sparetime[5][11]){
	int i, j, k;
	def2(sparetime);//jadikan semua bernilai default dahulu
	for (i = 0; i < 5; i+=1)//jelajahi hari demi hari
	{
		for (j = 0; j < x; j+=1)
			{
				if (i==input[j].days-1)
				//jika rupanya data berasal dari hari yang sama
				{
					for (k = 0; k < 11; k+=1)
					{
						if (input[j].timeline[k]==1)
						//jika salah satu dari data berisi jam sibuk
						{
							sparetime[i][k]=1;
							//maka tambahkan jam sibuk di timeline gabungan
						}
					}
				}
			}	
	}
}
//prosedur sequential search untuk mencari awal jam kosong
//dan akhir jam kosong
void sequencesearch(int x[5][11], int y[5][11], int z[5][11],
	int j, int i, char spare[5]){
	int done = 0;//penanda
	while((i<11) && (done==0)){
		if (x[j][i]==0 && y[j][i]==0 && z[j][i]==0)
		//jika ada jam dimana jadwal mereka kosong semua
		{
			if (j==0){//jika data yg ditelusuri adalah senin
				printf("Senin ");//print harinya
			}else if (j==1){//jika data yg ditelusuri adalah selasa
				printf("Selasa ");//print harinya
			}else if (j==2){//jika data yg ditelusuri adalah rabu
				printf("Rabu ");//print harinya
			}else if (j==3){//jika data yg ditelusuri adalah kamis
				printf("Kamis ");//print harinya
			}else if (j==4){//jika data yg ditelusuri adalah jumat
				printf("Jumat ");//print harinya
			}
			printf("%d.00 ", i+7);//print jam awal
			done=1;//rubah tanda
			strcpy(spare,"pass");//tandai bahwa ada jam kosong
		}
			i+=1;//tambah index
	}
	while((i<11) && (done==1)){
		if (x[j][i]!=0 || y[j][i]!=0 || z[j][i]!=0)
		//jika ada dari mereka yang sibuk
		{
			printf("- %d.00\n", i+7);//print jam akhir
			done=0;//rubah tanda lagi
		}
			i+=1;
	}
	if (done==1)//kalau tanda belum berubah sampai akhir
	{//artinya mereka kosong sampe sore
		printf("- %d.00\n", i+7);//print jam saja
	}
	if (i<11 && strcmp(spare, "pass")==0)
	{
		sequencesearch(x,y,z,j,i, spare);
		//panggil lagi prosedur jika pemeriksaan belum sampai sore
		/*
		contoh kasus
		2
		1 7 9
		1 12 14
		1
		2 7 9
		1
		2 12 14
		output:
		Senin 9.00 - 12.00
		Senin 14.00 - 18.00
		Selasa 9.00 - 12.00
		Selasa 14.00 - 18.00
		Rabu 7.00 - 18.00
		Kamis 7.00 - 18.00
		Jumat 7.00 - 18.00
		*/
	}
}
//prosedur pencari ada atau tidaknya jadwal kosong
void finalsearch(int x[5][11], int y[5][11], int z[5][11]){
	int i, j;//var loop
	char spare[5];//string penanda ada atau tidaknya waktu kosong
	strcpy(spare, "not");//not/tidak ada, sebagai default
	for (j = 0; j < 5; j+=1)
	{
		i=0;
		sequencesearch(x,y,z,j,i, spare);//panggil prosedur pencari
	}
	if (strcmp(spare,"pass")!=0)
	//jika rupanya tidak ada jadwal kosong
	{
		printf("Tidak ada irisan jadwal.\n");//print sesuai permintaan
	}
 }