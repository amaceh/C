#include "mskat16.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan maskat16 UAS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	char xstr[1000];//deklarasi string
	scanf("%999[^\n]s", &xstr);//scan string sampai enter
	int result=0;//variabel counter

	char temp[100];//string penampung tiap kata
	//mulai maju
	STARTKATA(xstr);
	//salin ke penampung
	strcpy(temp,GETCKATA());
	//var loop, penhenti, pengecek dan hasil
	int x=0, stop=0, cek=0, res=0;
	while(EOPKATA(xstr)!=1){//jika belum menemui EOP
		//cek adakah huruf konsonan atau tidak
		while(stop==0 && x<GETPANJANGKATA()){
			//konsonan harus mengecek 
			//apakah dia huruf atau bukan
			if (temp[x]>='a' && temp[x]<='z')
			{
				//tampa pnegecekan ini bisa saja angka dianggap konsonan
				if (temp[x]!='a' && temp[x]!='i' 
				&& temp[x]!='u' && temp[x]!='e' 
				&& temp[x]!='o'){
				//jika ada hentikan loop
				//dan tambah pengecek
					stop=1;
					cek+=1;
				}
			}
			//jika belum ketemu lanjutkan saja
			x+=1;
		}
		//reset penghenti loop
		stop=0;
		//reset indeks
		x=0;

		//cek apakah ada vokal atau tidak
		while(stop==0 && x<GETPANJANGKATA()){
			if (temp[x]=='a' || temp[x]=='i' 
			|| temp[x]=='u' || temp[x]=='e' 
			|| temp[x]=='o')
			{
				//jika ada hentikan loop
				//dan tambah pengecek
				stop=1;
				cek+=1;
			}else{
				//jika belum ketemu lanjutkan saja
				x+=1;
			}
		}
		stop=0;
		x=0;
		//cek apakah ada angka atau tidak
		while(stop==0 && x<GETPANJANGKATA()){
			if (temp[x]>='0' && temp[x]<='9')
			{
				//jika ada hentikan loop
				//dan tambah pengecek
				stop=1;
				cek+=1;
			}else{
				//jika belum ketemu lanjutkan saja
				x+=1;
			}
		}
		//reset penghenti loop
		stop=0;
		//reset indeks
		x=0;

		if (cek==3)
		//jika pengecek menyatakan semua syarat terpenuhi
		{
			res+=1;//tambah hasil
		}
		cek=0;//reset pengecek
		INCKATA(xstr);//maju kata
		strcpy(temp,GETCKATA());//salin lagi
	}
	printf("%d\n", res);//tampilkan hasil
	return 0;
}	