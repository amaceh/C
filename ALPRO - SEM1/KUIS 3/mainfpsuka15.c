#include "fpsuka15.h"
//memanggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan fpsuka15 Kuis 3,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int n, i;//variabel jumlah input dan loop
	scanf("%d", &n);//meminta jumlah input
	char input[n][50];//arr of str input
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", input[i]);//menginput setiap string
	}
	int ptrn=genorganmore(n, input);//memanggil fungsi penentu banyak ganjil atau genap
	if (ptrn==1)//jika genap lebih banyak
	{
		reversechar(n, input);//prosedur pemutaran char
		ptrn1(n, input);//prosedur pola 1
	}else if(ptrn==2){//jika ganjil lebih banyak
		ptrn2(n, input);//prosedur pola 2
	}
	return 0;
}	