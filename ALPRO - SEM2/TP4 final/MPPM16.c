#include "MPPM16.h"//memanggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan MPPM16 TP4,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/
//prosedur bublesort
void bublesort(int x, char str[x][16], char str2[x][30]){
	int i, swap;//var loop dan swap
	char temp[30];//string temporary
	do{
		swap=0;
		for (i = 0; i < x-1; i+=1)
		{
			//bandingkan
			if (strcmp(str[i],str[i+1])==1)
			{
				//jika lebih atas maka copy
				strcpy(temp,str[i]);//copy nim ke temp
				strcpy(str[i],str[i+1]);//copy nim ke posisi seharusnya
				strcpy(str[i+1],temp);//copy nim dari temp
				strcpy(temp,str2[i]);//copy nama ke temp
				strcpy(str2[i],str2[i+1]);//copy nama ke tempat seharusnya
				strcpy(str2[i+1],temp);//copy nama dari temp
				swap=1;
			}
		}
	}while (swap==1);
}

//prosedur quicksort pivot pinggir
void quicksortpinggir(int x, char str[x][30],int l, int r, char str2[x][16]){
	int i, j;//var loop
	i=l; j=r;
	char temp[30];//string temp

	do{
		while(strcmp(str[i],str[r])==-1 && (i<=r)){
			i+=1;//tambah index , mencegah i berjalan terlalu jauh
		}
		while(strcmp(str[j],str[l])==1 && (i<=j)){
			j-=1;//tambah index, mencegah j berjalan terlalu jauh
		}
		if (i<j)
		{
			//proses pemindahan
			strcpy(temp,str[i]);///salin ke temp
			strcpy(str[i],str[j]);//salin ke tempat seharusnya
			strcpy(str[j],temp);//salin dari temp
			strcpy(temp,str2[i]);//salin ke temp
			strcpy(str2[i],str2[j]);//salin ke tempat seharusnya
			strcpy(str2[j],temp);//salin ke temp
			i=i+1;
			j=j-1;
		}	
	}while(i<j);

	if (l<j)
	{
		quicksortpinggir(x, str,l,j, str2);
	}
	if (i<r)
	{
		quicksortpinggir(x, str,i,r, str2);
	}
}
void printthelist(int x, char str[x][16], char str2[x][30],
		char strx[x][16], char strx2[x][30], int unvalid, 
		char order1[16], char order2[16]){
	int i;//var loop
	if (strcmp(order2, "nim")==0 || strcmp(order2, "nama")==0)//jika perintah adalah nama atau nim
	{
		if (strcmp(order2, "nim")==0)//jika perintah nim
		{
			bublesort(x, str, str2);///panggil prosedur bublesort
		}else if (strcmp(order2, "nama")==0)//jika printha adalah nama
		{
			quicksortpinggir(x, str2, 0, x-unvalid-1, str);//panggil prosedur quicksort
		}
		printf("---Hasil Pengurutan---\n");//print sesuai permintaan
		if (unvalid<x)//jika masih ada data valid
		{
			for (i = 0; i < x-unvalid; i+=1)
			{
				printf("%s %s\n", str[i], str2[i]);//print setiap data
			}
		}else{//jika tidak ada data valid
			printf("Tidak ada data valid.\n");//print sesuai permintaan
		}
		if (strcmp(order1, "ya")==0)//jika perintah adalah ya
		{//print daftar error
			if (unvalid>0)//jika ada daftar error
			{
				printf("---Daftar Error---\n");//print sesuai perintah	
			}
			for (i = 0; i < unvalid; i+=1)
			{
				printf("%s - %s tidak valid.\n", strx[i], strx2[i]);//print setiap data sesuai permintaan
			}
		}
	}else{//jika perintah tidak valid
		printf("---Data tidak dapat diproses---\n");//printsaja sesuai perimntaan
	}
}
int numbercheck(char str[16]){//fungsi pengecek valid atau tidaknya nim
	int i;
	int counter=0;
	for (i = 0; i < 7; i+=1)
	{
		if (str[i]=='0' || str[i]=='1' || str[i]=='2'|| str[i]=='3' || str[i]=='4'
			|| str[i]=='5' || str[i]=='6' || str[i]=='7' || str[i]=='8' || str[i]=='9')
		{
			counter+=1;//jika char adalah angka maka counter bertambah
		}
		
	}
	if (counter==7)//jika counter sama dengan 7
	{
		return 0;//kembalikan nilai nol
	}else{//jika tidak
		return 1;//kembalikan nilai satu
	}
}

void unvalidfinder(int x, char str[x][16], char str2[x][30], char stry[x][16], 
	char stry2[x][30], char strx[x][16], char strx2[x][30], char order1[16], char order2[16]){
	int i, j;//var loop
	int len;//var len
	int count=0, count2=0;//counter
	for (i = 0; i < x; i+=1)
	{
		len=strlen(str[i]);
		if (len!=7 || numbercheck(str[i])==1){//syarat valid atau tidaknya nim
			//jika nim tidak valid
			strcpy(strx[count],str[i]);//copy data ke daftar error
			strcpy(strx2[count],str2[i]);
			count+=1;//index counter bertambah
		}else{//jika ternyata data valid
			strcpy(stry[count2],str[i]);//copy data ke daftar valid
			strcpy(stry2[count2],str2[i]);
			count2+=1;
		}
	}

	printthelist(x, stry, stry2, strx, strx2, count, order1, order2);//panggil prosedur pencetak

}