#include "PURTP15.h"//memanggil lib dari header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan PURTP15 TP 10,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur permainan
void playcard(int n, char P1[n][3], char P2[n][3], 
	char P3[n][3], char P4[n][3]){
	int i, j, k, idx=0;//var loop dan index
	char out[n*4][3];//arr of str hasil permainanS
	///////////////////////////////
	//mennyatakan urutan kartu dengan arr of str
	char card[13][3];
	strcpy(card[0], "A");
	strcpy(card[1], "K");
	strcpy(card[2], "Q");
	strcpy(card[3], "J");
	strcpy(card[4], "10");
	strcpy(card[5], "9");
	strcpy(card[6], "8");
	strcpy(card[7], "7");
	strcpy(card[8], "6");
	strcpy(card[9], "5");
	strcpy(card[10], "4");
	strcpy(card[11], "3");
	strcpy(card[12], "2");
	////////////////////////
	int stop=1;//variabel control loop while
	for (i = 0; i < n*4; i+=1)
	{
		j=0;//default j
		while(j<13 && stop==1){
			if (strcmp(P1[0], card[j])==0)//jika kartu piyu yang terbesar
			{
				stop=0;//hentikan proses loop
				strcpy(out[idx], P1[0]);//kartu dimainkan
				idx+=1;
				for (k = 0; k < n; k+=1)
				{
					strcpy(P1[k], P1[k+1]);//kartu hilang dari tangan
				}
			}else if (strcmp(P2[0], card[j])==0)//jika kartu moni yang terbesar
			{
				stop=0;//hentikan proses loop
				strcpy(out[idx], P2[0]);//kartu dimainkan
				idx+=1;
				for (k = 0; k < n; k+=1)
				{
					strcpy(P2[k], P2[k+1]);//kartu hilang dari tangan
				}
			}else if (strcmp(P3[0], card[j])==0)//jika kartu tobi yang terbesar
			{
				stop=0;//hentikan proses loop
				strcpy(out[idx], P3[0]);//kartu dimainkan
				idx+=1;
				for (k = 0; k < n; k+=1)
				{
					strcpy(P3[k], P3[k+1]);//kartu hilang dari tangan
				}
			}else if (strcmp(P4[0], card[j])==0)//jika kartu maman yang terbesar
			{
				stop=0;//hentikan proses loop
				strcpy(out[idx], P4[0]);//kartu dimainkan
				idx+=1;
				for (k = 0; k < n; k+=1)
				{
					strcpy(P4[k], P4[k+1]);//kartu hilang dari tangan
				}
			}
			j+=1;
		}
		stop=1;//jalankan lagi prosesnya
	}
//kartu yang dimainkan di print
	for (i = 0; i < idx; i+=1)
	{
		printf("%s\n", out[i]);
	}
}