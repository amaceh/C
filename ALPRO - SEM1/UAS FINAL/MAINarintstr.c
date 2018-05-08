#include "arintstr.h"
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan PURTP15 TP 10,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main()
{
	int i;//var loop
	int n, m;//var jumlah arr of int dan arr of string
	scanf("%d", &n);//input jumlah array of int
	int arrint[n];//arr of int
	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &arrint[i]);//input tiap arr of int
	}
	scanf("%d", &m);//input jumlah arr of string
	char arrofstr[m][50];//array of integer
	for (i = 0; i < m; i+=1)
	{
		scanf("%s", &arrofstr[i]);//input tiap array of integer
	}
	int result=compare(n, arrint);//memanggil fungsi pembanding
	printstring(m, arrofstr, result);//memanggil prosedur print hasil
	return 0;
}