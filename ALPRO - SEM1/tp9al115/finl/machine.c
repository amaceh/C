#include "head.h"//memanggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan tp9al115 TP 9,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur pengkopian setiap char ke dalam satu string
void movetotemp(int counter, char temp[500], char msg[100][50]){//variabel pada main
	int i, j, idx=0;// variabel yang hanya dipakai di mesin
	for (i = 0; i < counter; i+=1)
	{
		//pengunaan nested for agar setiap char terkopi
		for (j = 0; j < strlen(msg[i]); j+=1){
			temp[idx]=msg[i][j];
			idx+=1;
		}
		temp[idx]='\0';
	}
}

//prosedur pengecekan dan penggantian char
void checkchar(int lentem, int swap, char temp[500], 
	char swapchar1[100], char swapchar2[100]){//variabel pada main
	int i, j;// variabel yang hanya dipakai di mesin
	for (i = 0; i < lentem; i+=1){
		//pengunaan nested for agar setiap char di cek dan diganti
			for (j = 0; j < swap; j+=1){
				if (temp[i]==swapchar1[j]){
					temp[i]=swapchar2[j];
				}
			}
		}
	}

//prosedur pengkopian kembali char setelah di rubah
void returnchar(int counter, char msg[100][50], char temp[500]){//variabel pada main
	int i, j, idx=0;// variabel yang hanya dipakai di mesin
	for (i = 0; i < counter; i+=1){
		//pengunaan nested for agar setiap char terkopi
			for (j = 0; j < strlen(msg[i]); j+=1){
				msg[i][j]=temp[idx];
				idx+=1;
			}
		}
}

//prosedur pengambilan huruf vokal
void vocaltotempvoc(int lentem, char temp[500], 
	char tempvoc[300], char tempchar){//variabel pada main
	int i, j, idx=0;// variabel yang hanya dipakai di mesin
	for (i = 0; i < lentem; i+=1){
		if (temp[i]=='a' || temp[i]=='i' 
		|| temp[i]=='u' || temp[i]=='e'
		|| temp[i]=='o'){//setiap char dicek apakah vokal atau bukan
			//jika vokal maka char tersbut akan di kopi ke temporary dan diganti menjadi '*'
			tempvoc[idx]=temp[i];
			temp[i]='*';
			idx+=1;
		}
	}
	//kemudian di dalam temporary vokal di geser
	for (i = idx-1; i > 0; i-=1){
		if(i==idx-1){//yang di kopi di temporary ini hanya char terakhir
			tempchar=tempvoc[i];
		}
		tempvoc[i]=tempvoc[i-1];
		}
		tempvoc[0]=tempchar;//kemudian dikopi ke char pertama
}

//prosedur pengembalian vokal
void swapstartotempvoc(int lentem, char temp[500],
	char tempvoc[300]){//variabel pada main
	int i, j, idx=0;// variabel yang hanya dipakai di mesin
	for (i = 0; i < lentem; i+=1){
		if (temp[i]=='*'){//jika char bintang
			//maka diganti dengan vokal yang sudah di geser
			temp[i]=tempvoc[idx];
			idx+=1;
		}
	}
}

//prosedur pengembalian ke arr of string msg
void movetomsg(int counter, char msg[100][50],
	char temp[500]){//variabel pada main
	int i, j, idx=0;// variabel yang hanya dipakai di mesin
	for (i = 0; i < counter; i+=1){
		//pengunaan nested for agar setiap char terkopi
		for (j = 0; j < strlen(msg[i]); j+=1){
			msg[i][j]=temp[idx];
			idx+=1;
		}
	}
}
//prosedur pengkopian arr of string
void movetotemp2(int counter, char temparostr[100][50],
	char msg[100][50]){//variabel pada main
	int i;// variabel yang hanya dipakai di mesin
	for (i = 0; i < counter; i+=1){
		strcpy(temparostr[i], msg[i]);
	}
}
//prosedur pembalikan kata
void reversechar(int counter, char msg[100][50], 
	char temparostr[100][50]){//variabel pada main
	int i, j, idx;// variabel yang hanya dipakai di mesin
	/*	cara yang saya pakai dalam membalikkan adalah
		dengan menggunakan looping dua arah, dimana idx saya atur
		agar looping secara mundur */
	for (i = 0; i < counter; i+=1){
		idx=strlen(msg[i])-1;
		for (j = 0; j < strlen(msg[i]); j+=1){	
			temparostr[i][j]=msg[i][idx];
			idx-=1;
		}
	}
}

//prosedur pembalikan urutan kata
void returnreverestring(int counter, char msg[100][50],
	char temparostr[100][50]){//variabel pada main
	int i, idx=counter-1;// variabel yang hanya dipakai di mesin
		/*	cara yang saya pakai dalam membalikkan adalah
		dengan menggunakan looping dua arah, dimana idx saya atur
		agar looping secara mundur */
	for (i = 0; i < counter; i+=1){
		strcpy(msg[i], temparostr[idx]);
		idx-=1;
	}
}
