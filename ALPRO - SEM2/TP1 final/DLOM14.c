#include "DLOM14.h"//memanggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan DLOM14 TP1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur default peta
void blankmap(char mtrx[10][10][2]){
	int i, j;//var loop
	for (i = 0; i < 10; i+=1)
	{
		for (j = 0; j < 10; j+=1)
		{
			strcpy(mtrx[i][j], "*");
			//setiap matrix dirubah menjadi bintang yang merupakan keadaan awal peta
		}
	}

}
//prosedur pengolahan langkah di peta
void mapdrawing(int x, int y, int n, char move[n][6], int step[n], char mtrx[10][10][2]){
	int i, j;//var loop
	strcpy(mtrx[y-1][x-1], "x");//matrix dengan index sesuai input awal diisi dengan "x"

	for (i = 0; i < n; i+=1)
	{
		if (strcmp(move[i], "kanan")==0)//jika ke arah kanan
		{
			for (j = x; j < step[i]+x; j+=1)
			{
				strcpy(mtrx[y-1][j], "-");//ganti matrix sebanyak jumlah langkah
			}
			x+=step[i];//koordinat x ditambah (bergerak ke kanan)
		}else if(strcmp(move[i], "kiri")==0){
			for (j = x; j > x-step[i]; j-=1)
			{
				strcpy(mtrx[y-1][j-2], "-");//ganti matrix sebanyak jumlah langkah
			}
			x-=step[i];//koordinat x dikurangi (bergerak ke kiri)
		}else if(strcmp(move[i], "atas")==0){
			for (j = y; j > y-step[i]; j-=1)
			{
				strcpy(mtrx[j-2][x-1], "|");//ganti matrix sebanyak jumlah langkah
			}
			y-=step[i];//koordinat y dikurangi (bergerak ke atas)
		}else if(strcmp(move[i], "bawah")==0){
			for (j = y; j < step[i]+y; j+=1)
			{
				strcpy(mtrx[j][x-1], "|");//ganti matrix sebanyak jumlah langkah
			}
			y+=step[i];//koordinat y ditambah (bergerak ke bawah)
		}
	}
}
//prosedur pencetakan hasil olahan peta
void printmap(char mtrx[10][10][2]){
	int i, j;//var loop
	for (i = 0; i < 10; i+=1)
	{
		for (j = 0; j < 10; j+=1)
		{
			printf("%s", mtrx[i][j]);//print setiap matrix
		}
		printf("\n");//newline tiap baris
	}
}