#include "DLOM14.h"//memanggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan DLOM14 TP1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main()
{
	int x, y, n, i, j;
	//var koordinat awal, jumlah perintah, dan var loop
	scanf("%d %d", &x, &y);//input koordinat awal
	scanf("%d", &n);//input jumlah perintah
	char move[n][6];//arr of str perintah
	int step[n];//arr of int jumlah langkah
	for (i = 0; i < n; i+=1)
	{
		scanf("%s %d", &move[i], &step[i]);//input tiap arah dan jumlah langkah
	}

	char mtrx[10][10][2];//matrix peta

	blankmap(mtrx);//memanggil prosedur default peta
	mapdrawing(x, y, n, move, step, mtrx);//memanggil prosedur pengolah langkah peta
	printmap(mtrx);//memanggil prosedur pencetakan peta

	return 0;//success
}