#include "PURTP15.h"//memanggil lib dari header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan PURTP15 TP 10,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int n;//var jumlah kartu para pemain
	int i;//var loop
	scanf("%d", &n);//input jumlah kartu
	char P1[n][3], P2[n][3], P3[n][3], P4[n][3];
	//arr of str kartu piyu, moni, tobi, maman, dan kartu yang akan dikeluarkan
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P1[i]);//input kartu piyu
	}
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P2[i]);//input kartu moni
	}
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P3[i]);//input kartu tobi
	}
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P4[i]);//input kartu maman
	}
	playcard(n, P1, P2, P3, P4);//memanggil prosedur kartu yang dimainkan
	return 0;
}	