#include "head.h"//memanggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan tp9al115 TP 9,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main(){
	char msg[100][50];//arr of str input
	int i=0, counter=-1;// var loop dan penghitung kata
	while(strcmp(msg[i-1], "end")!=0){//jika end diinput maka berhenti
		scanf("%s", msg[i]);//input kata
		i+=1;
		if (strcmp(msg[i], "end")!=0 && counter<10){//kata yang dihitung hanya 10
			//karena counter dipakai dalam batasan pada prosedur
			//maka ini menjadi batasan dari jumlah kata yang di proses
			counter+=1;
		}
	}
	
	int swap;//variabel jumlah baris huruf yang akan ditukar
	scanf("%d", &swap);//input jumlah baris huruf yang akan ditukar
	char swapchar1[100], swapchar2[100];//arr huruf yang akan ditukar
	
	for (i = 0; i < swap; i+=1){
		scanf(" %c %c", &swapchar1[i], &swapchar2[i]);//input setiap huruf yang akan ditukar(jika ada)
	}
	char tempchar, temp[500], tempvoc[300], temparostr[100][50];//char. array, dan arr of string temporari
	movetotemp(counter, temp, msg);
	//prosedur pengkopian setiap char ke dalam satu string

	int lentem=strlen(temp);//panjang temp array

	if(swap!=0){//jika input jumlah baris bukan nol
		///////lakukan prosedur berikut
		//prosedur pengecekan dan penggantian char
		checkchar(lentem, swap, temp, swapchar1, swapchar2);
		//prosedur pengkopian kembali char setelah di rubah
		returnchar(counter, msg, temp);
	}else if (swap==0){//jika input jumlah baris nol
		//////lakukan prosedur berikut
		//prosedur pengambilan huruf vokal
		vocaltotempvoc(lentem, temp, tempvoc, tempchar);
		//prosedur pengembalian vokal
		swapstartotempvoc(lentem, temp, tempvoc);
		//prosedur pengembalian ke arr of string msg
		movetomsg(counter, msg, temp);
		//prosedur pengkopian arr of string
		movetotemp2(counter, temparostr, msg);
		//prosedur pembalikan kata
		reversechar(counter, msg, temparostr);
		//prosedur pembalikan urutan kata
		returnreverestring(counter, msg, temparostr);
	}

	for (i = 0; i < counter; ++i)
	{
		printf("%s", msg[i]);
		if (i<counter-1){//print spasi di setiap akhir kata
			printf(" ");
		}else{//kecuali kata terakhir
			printf("\n");//print newline
		}
	}
	return 0;
}