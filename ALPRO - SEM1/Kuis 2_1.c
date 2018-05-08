#include <stdio.h>
#include <string.h>

/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	algoritma dan pemrograman 1 dalam mengerjakan strilili kuis 2,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin.

	*/
int main()
{
	//array satu dan dua
	char n[50];
	char m[50];
	int i;//index
	char kons1=0, vok1=0, kons2=0, vok2=0;
	//counter konsonan dan vokal
	//meminta masukkan kedua string
	scanf("%s", n);
	scanf("%s", m);

	int len1=strlen(n);//memasukkan panjang string
	int len2=strlen(m);

	for (i = 0; i < len1; i+=1)
	{//pengecekan apakah vokal atau bukan
		if ((n[i]=='a') || (n[i]=='i')
				|| (n[i]=='u') || (n[i]=='e')
				|| (n[i]=='o'))
		{
			vok1 +=1;//jika vokal maka counter bertambah
		}else{
			kons1 +=1;//jika konsonan maka counter bertambah
		}
	}
	for (i = 0; i < len2; i+=1)
	{
		if ((m[i]=='a') || (m[i]=='i')
				|| (m[i]=='u') || (m[i]=='e')
				|| (m[i]=='o'))
		{
			vok2 +=1;//jika vokal maka counter bertambah
		}else{
			kons2 +=1;//jika konsonan maka counter bertambah
		}
	}

	if (kons1==kons2)//jika jumlah counter konsonan sama
	{
		printf("sama konsonan\n");
	}else if(vok1==vok2){//jika jumlah counter vokal bertambah
		printf("sama vokal\n");
	}else{//jika tidak ada yang sama
		printf("tidak ada yang sama\n");
	}
	
	return 0;
}	