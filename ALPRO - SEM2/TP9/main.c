#include "header.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan RSBMPTN1 TP9,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main()
{
	int x, i;//var jumlh input dan loop 
	scanf("%d", &x);//meminta jumlah input
	//deklarasi string, dan penampung
	char sms[250], kotatemp[50];
	//deklarasi arr of int berisi jumlah kata yang valid
	int valid[x];

	for (i = 0; i < x; i+=1)
	{
		//input pita
		scanf(" %[^\n]s", sms);
		valid[i]=0;//default validasi
		//pertama cek kevalidan kata REG
		CREG(sms, x, valid, i);
		//lalu Kata SBMPTN
		/*pastikan semua pengecekan selanjutnya bukan EOP*/
		if (EOPKATA(sms)!=1){CSBM(sms, x, valid, i);}
		//lalu format nama
		if (EOPKATA(sms)!=1){CNAMA(sms, x, valid, i);}
		//lalu format kota
		if (EOPKATA(sms)!=1){CKOTA(sms, x, valid, i, kotatemp);}
		//lalu format sekolah
		if (EOPKATA(sms)!=1){CSKLH(sms, x, valid, i, kotatemp);}
		//dan terakhir format kode
		if (EOPKATA(sms)!=1){CKODE(sms, x, valid, i);}
		if (EOPKATA(sms)!=1){//jika ternyata masih ada kata lain
			//atau belum EOP
			valid[i]=0;//sms dianggap tidak valid
		}
	}
	for (i = 0; i < x; i+=1)
	{
		if (valid[i]==6)//jika semua pengecekan bernilai valid
		{//print valid
			printf("valid\n");
		}else{//jika tidak, print tidak valid
			printf("tidak valid\n");
		}
	}
	return 0;
}