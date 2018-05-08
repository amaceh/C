#include <stdio.h>
#include <string.h>
/*saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan SECMES15 TP8,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/
int main(){
	
	int n, m, x;//variabel jumlah string, dan besarnya geseran
	int i, j;//variabel loop
	int idx=0, swap=0, idx2=0;//variabel index tambahan

	scanf("%d", &n);//meminta jumlah string satu
	
	char str1[n][50];//membuat array of string satu
	for (i = 0; i < n; i+=1){
		scanf("%s", str1[i]);//scan array of string satu
	}

	scanf("%d", &m);//meminta jumlah string dua
	char str2[m][50];//membuat array of string dua
	for (i = 0; i < m; i+=1){
		scanf("%s", str2[i]);//scan array of string dua
	}

	scanf("%d", &x);//meminta jumlah putaran

	if (x!=0)//jika input bukan nol
	{
		/////proses penukaran array////
		char temp[n+m][50];//membuat array of string penampung
		/* semua array of string ditampung ke dalam satu array of string*/
		for (i = 0; i < n; i+=1)
		{
			strcpy(temp[i], str1[i]);//pengkopian array of string kesatu
		}
		for (i = 0; i < m; i+=1)
		{
			strcpy(temp[i+n], str2[i]);	//pengkopian array of string kedua
		}
		/* kemudian semua array dikembaikan dengan menukar index sesuai permintaan 'x'*/
		for (i = 0; i < n+m; i+=1)
		{	
			//penentuan index untuk array yang akan dekembalikan
			if ((i+x) < n+m){//jika belum melebihi keseluruhan
				swap=idx+x;//index akan bernilai idx ditambah 'x'
			}else if((i+x)==n+m){//jika sudah pada batas
					idx=0;//idx direset
					swap=0;//index geser direset
			}else{//setelah direset
				swap=idx;//index geser bernilai sama dengan idx
			}
			
			if (i<n)//pengembalian isi array of string pertama
			{
				strcpy(str1[i], temp[swap]);//pengkopian sesuai index geser
			}else if (i>=n)//pengembalian isi array of string kedua
			{
				strcpy(str2[idx2], temp[swap]);//pengkopian sesuai index geser
				idx2+=1;
			}
			idx+=1;//penambah idx
		}

		////proses penggeseran array/////
		char temp2[500], temp3[500];//membuat array penampung
		int lentem2=0, lentem3=0;//variabel panjang array penampung
		idx=0;//idx direset karena akan digunakan lagi
		idx2=0;//idx2 direset karena akan digunakan lagi

		/*ke dua array of string di salin ke dalam sebuah array*/
		for (i = 0; i < n; i+=1)
		{
			for (j = 0; j < strlen(str1[i]); j+=1)
			{
				//proses penyalinan array of string pertama
				temp2[idx]=str1[i][j];//penyalinan menggunakan idx sebagai index
				idx+=1;//penambah idx
			}
		}
		for (i = 0; i < m; i+=1)
		{
			for (j = 0; j < strlen(str2[i]); j+=1)
			{
				//proses penyalinan array of string kedua
				temp3[idx2]=str2[i][j];//penyalinan menggunakan idx sebagai index
				idx2+=1;//penambah idx2
			}
		}	

		////menghitung panjang array penampung yang dibutuhkan/////
		for (i = 0; i < n; i+=1)
		{
			//panjang array penampung pertama
			lentem2+=strlen(str1[i]);
		}
		for (i = 0; i < m; i+=1)
		{
			//panjang array penampung kedua
			lentem3+=strlen(str2[i]);
		}

		idx=0;//idx direset karena akan digunakan lagi
		idx2=0;//idx2 direset karena akan digunakan lagi
		int swap2=0, swap3=0;//membuat variabel index penggeser array
		int limit1=0, limit2=0;//variabel penanda batas

		for (i = 0; i < n; i+=1)
		{
			for (j = 0; j < strlen(str1[i]); j+=1)
			{
				if ((limit1+x) < lentem2){//jika belum melebihi batas
					swap2=idx+x;//nilai penggeser bernilai idx + x
				}else if((limit1+x)== lentem2){//jika sudah mencpai batas
					idx=0;//idx direset lagi
					swap2=0;//nilai penggeser direset
				}else{//jika sudah direset
					swap2=idx;//nilai geser bernilai idx
				}
				idx +=1;//penambah idx
				limit1 +=1;//penambah batasan
				str1[i][j]=temp2[swap2];//proses pengembalian string dengan geseran
			}
		}
		for (i = 0; i < m; i+=1)
		{
				for (j = 0; j < strlen(str2[i]); j+=1)
			{
				if ((limit2+x) < lentem3){//jika belum melebihi batas
					swap3=idx2+x;//nilai penggeser bernilai idx + x
				}else if((limit2+x)== lentem3){//jika sudah mencpai batas
					idx2=0;//idx2 direset lagi
					swap3=0;//nilai penggeser direset
				}else{//jika sudah direset
					swap3=idx2;//nilai geser bernilai idx2
				}
				idx2 +=1;//penambah idx
				limit2 +=1;//penambah batasan
				str2[i][j]=temp3[swap3];//proses pengembalian string dengan geseran
			}
		}
	
	}else{/////jika penggeser bernilai nol/////
		//maka string ganjil dihapus

		char temdel1[n][50], temdel2[m][50];//string penampung sementara array
		for (i = 0; i < n; i+=1)
		{
			for (j = 0; j < strlen(str1[i]); j+=1)
			{
				//string diwali dari nol, sehingga yang dihapus adalah
				//index string bernilai genap
				if (j%2==1)//jika char berindex ganjil
				{//maka char ditampung
					temdel1[i][idx]=str1[i][j];
					idx+=1;//penambah idx
				}
				temdel1[i][idx]='\0';//penambahan null di akhir
			}
			idx=0;//reset idx
		}
		for (i = 0; i < n; i+=1)
		{
			strcpy(str1[i], temdel1[i]);//string yang sudah di tampung dikembalikan
		}
		for (i = 0; i < m; i+=1)
		{
			for (j = 0; j < strlen(str2[i]); j+=1)
			{	
				//string diwali dari nol, sehingga yang dihapus adalah
				//index string bernilai genap
				if (j%2==1)//jika char berindex ganjil 
				{//maka char ditampung
					temdel2[i][idx2]=str2[i][j];
					idx2+=1;//penambah idx
				}
				temdel2[i][idx2]='\0';//penambahan null di akhir
			}
			idx2=0;//reset idx2
		}
		for (i = 0; i < m; i+=1)
		{
			strcpy(str2[i], temdel2[i]);//string yang sudah di tampung dikembalikan
		}	
	}
	int nospace1=0, nospace2=0;//variabel counter string yang kosong
	printf("1\n");//print output sesuai permintaan
	if (x!=0 || n!=1){//jika input hanya satu dan meminta untuk dihapus maka tidak akan ditampilkan
		for (i = 0; i < n; i+=1){
			if (strcmp(str1[i],"\0")!=0){//jika string tidak kosong, maka akan diprint stringnya serta spasi
					printf("%s", str1[i]);//print string hasil
				if (i<n-1){
					printf(" ");//penambahan spasi diakhir tiap string
				}
			}else{//bila string kosong counter bertambah
				nospace1+=1;
			}
			if(i==n-1 && nospace1 != n)//jika pada akhirnya semua string kosong spasi tidak di print
			{
				printf("\n");//penambahan newline di akhir
			}
		}
	}
	printf("2\n");
	if (x!=0 || m!=1){//jika input hanya satu dan meminta untuk dihapus maka tidak akan ditampilkan
		for (i = 0; i < m; i+=1){
			if (strcmp(str2[i],"\0")!=0){//jika string tidak kosong, maka akan diprint stringnya serta spasi
				printf("%s", str2[i]);
				if (i<m-1){
					printf(" ");//penambahan spasi diakhir tiap string
				}
			}else{//bila string kosong counter bertambah
				nospace2+=1;
			}
			if(i==m-1 && nospace2 != m){//jika pada akhirnya semua string kosong spasi tidak di print
				printf("\n");//penambahan newline di akhir
			}
		}	
	}
	//selesai
	return 0;
}