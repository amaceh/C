#include <stdio.h>
#include <string.h>

/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	algoritma dan pemrograman 1 dalam mengerjakan nstrpola kuis 2,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin.

	*/
int main()
{
	int n;//banyaknya kata
	int i, j, k, idx=0;//index-index
	scanf("%d", &n);//masukan banyak kata
	int len[n], len2[n];//string tinggi pola bawah
	char str[n][50];//arr of str
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &str[i]);//memasukkan setiap kata
	}

	for (i = 0; i < n; i+=3){
		len[idx]=strlen(str[1+i]);//tinggi pola
		len2[idx]=(strlen(str[i]))-2;//lebar kotak spasi
		if(strlen(str[2+i])>len[idx]){//jika ada yang lebih panjang
			len[idx]=strlen(str[2+i]);//tinggi kotak spasi diganti
		}
		printf("%s\n", str[i]);
		for (k = 0; k < len2[idx]; k+=1)
		{
		for (j=0; j<len[idx]; j+=1){
			if (j > strlen(str[i+1])){
				printf(" ");
			}else{
				printf("%c", str[i+1][j]);
			}	
		}
		for (j=0; j<len2[idx]; j+=1){
			printf(" ");
		}
		for (j=0; j<len[idx]; j+=1){
			if (j>strlen(str[i+2]))
			{
				printf(" ");
			}else{
				printf("%c", str[i+2][j]);
			}
		}
		printf("\n");
	}
		idx+=1;
	}


	return 0;
}

