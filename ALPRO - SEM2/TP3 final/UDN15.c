#include "UDN15.h"//memanggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan UDN15 TP3,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur sortir sesuai nama 
void inssortbyname(int x, Glist arr[x]){
	int i, j, temp1;//var loop dan temp
	char insertion[50], temp2[20];//string yang akan disortir dan temp str kelas

	for (i = 0; i < x; i+=1)
	{
		strcpy(insertion, arr[i].name);//salin ke str insertion
		strcpy(temp2, arr[i].class);//salin ke temp
		temp1=arr[i].grade;//salin ke temp
		j=i-1;
		while(strcmp(insertion, arr[j].name)==1 && (j>=0)){
		//jika ada kalimat yang lebih akhir hufurnya(sortir DESC)
			strcpy(arr[j+1].name, arr[j].name);//salin ke urutan berikutya 
			strcpy(arr[j+1].class, arr[j].class);//salin ke urutan berikutya
			arr[j+1].grade=arr[j].grade;//salin ke urutan berikutya
			j=j-1;
		}
		strcpy(arr[j+1].name, insertion);//salin ke urutan seharusnya
		strcpy(arr[j+1].class, temp2);//salin ke urutan seharusnya
		arr[j+1].grade=temp1;//salin ke urutan seharusnya
	}
}
void inssortbygrade(int x, Glist arr[x]){
	int i, insertion, j;//var loop dan nilai yang akan dibandingkan
	char temp1[50], temp2[20];//temp setiap string
	for (i = 0; i < x; i+=1)
	{
		insertion = arr[i].grade;//salin nilai yang akan dibandingkan
		strcpy(temp1, arr[i].name);//salin ke temp
		strcpy(temp2, arr[i].class);//salin ke temp
		j=i-1;
		while((insertion>arr[j].grade) && (j>=0)){
		//bila nilai lebih besar
			arr[j+1].grade=arr[j].grade;//salin ke urutan berikutya
			strcpy(arr[j+1].name, arr[j].name);//salin ke urutan berikutya
			strcpy(arr[j+1].class, arr[j].class);//salin ke urutan berikutya
			j=j-1;
		}
		arr[j+1].grade=insertion;//salin ke urutan seharusnya
		strcpy(arr[j+1].name, temp1);//salin ke urutan seharusnya
		strcpy(arr[j+1].class, temp2);//salin ke urutan seharusnya
	}
}