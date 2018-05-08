#include "header.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan RSBMPTN1 TP9,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
///mulai kata
void STARTKATA(char pita[]){
	idx=0; wordlen=0;
	while(pita[idx]==' '){
		idx+=1;
	}
	while(pita[idx]!=' ' && pita[idx]!='.'){
		cword[wordlen]=pita[idx];
		idx+=1; wordlen+=1;
	}
	cword[wordlen]='\0';
}
//reset kata
void RESETKATA(){
	wordlen=0; cword[wordlen]='\0';
}
///inckata
void INCKATA(char pita[]){
	wordlen=0;
	while(pita[idx]==' '){
		idx+=1;
	}
	while(pita[idx]!=' ' && pita[idx]!='.'){
		cword[wordlen]=pita[idx];
		idx+=1; wordlen+=1;
	}
	cword[wordlen]='\0';
}
///fungsi current kata
char* GETCKATA(){
	return cword;
}
///fungsi panjang kata
int GETPANJANGKATA(){
	return wordlen;
}
//fungsi EOP
int EOPKATA(char pita[]){
	if(pita[idx]=='.')
	{
		return 1;
	}else{
		return 0;
	}
}


///////////////////////////////////////////

//prosedur pengecek kata REG
void CREG(char xstr[250], int x, int val[x], int y){
	STARTKATA(xstr);//start kata
	if (strcmp(GETCKATA(),"REG")==0)
	{//kata harus REG dan kapital
		val[y]+=1;//maka valid
	}
}
//prosedur pengecek kata SBMPTN
void CSBM(char xstr[250], int x, int val[x], int y){
	INCKATA(xstr);//kata maju
	if (strcmp(GETCKATA(),"SBMPTN")==0)
	{//kata harus SBMPTN dan kapital
		val[y]+=1;//maka valid
	}
}
//prosedur pengecek nama
void CNAMA(char xstr[250], int x, int val[x], int y){
	INCKATA(xstr);//kata maju
	int i, count=0;//var loop dan counter
	char temp[100];//arr temp
	strcpy(temp,GETCKATA());//salin kata
	for (i = 0; i < GETPANJANGKATA(); i+=1)
	{
		if (temp[i]=='_' && temp[i+1]!='_')//double '_' dianggap tidak valid
		{//jika ada tanda '_'(penanda pemisah bagian)
			count+=1;//tambah counter
		}
	}
	if (count==2)//jika nama terdiri dari 3 bagian(ada 2 tanda)
	{
		val[y]+=1;//maka valid
	}
}
//prosedur pengecek kota
void CKOTA(char xstr[250], int x, int val[x], int y, char temp[50]){
	INCKATA(xstr);
	int i, not=1;//var pengecek dan loop
	strcpy(temp,GETCKATA());//salin kata
	while(i<GETPANJANGKATA() && not==1)
	{
		if (temp[i]>='0' && temp[i]<='9')
		{//jika ada karakter angka
			not=0;//penanda berubah
		}
		i+=1;
	}
	if (not=1)//jika penanda tidak berubah
	{
		val[y]+=1;//maka valid
	}
}
//prosedur pengubah kata menjadi lowercase
//memudahkan pengecekan sekolah
void converttolowercase(char xstr[50]){
	int i;//var loop
	for (i = 0; i < GETPANJANGKATA(); i+=1)
	{
		//pandang karakter dari sisi ASCII
		//a==97 //A==65 //jaraknya 32
		if (xstr[i]>='A' && xstr[i]<='Z')
		{
			xstr[i]+=32;//maka setiap huruf kapital, 
			//harus ditambah 32(ASCII)
		}
	}
}
void CSKLH(char xstr[250], int x, int val[x], int y, char xtemp[50]){
	INCKATA(xstr);
	int i, count=0, idx=0;//var loop, index dan counter
	char temp[100], temp2[50];//string temporary
	strcpy(temp,GETCKATA());//salin kata
	for (i = 0; i < GETPANJANGKATA(); i+=1)
	{
		if (temp[i]=='_' && temp[i+1]!='_')//double '_' dianggap tidak valid
		{//jika ada tanda '_'
			count+=1;
		}
		if (count==2)//jika sekolah terdiri dari 3 bagian
		{//atau dua tanda '_'
			temp2[idx]=temp[i+1];//salin kota sekolahnya
			idx+=1;
		}
	}
	temp2[idx]='\0';//null diakhir
	converttolowercase(xtemp);//ubah dulu ke lowercase
	converttolowercase(temp2);//ubah dulu ke lowercase
	if (count==2 && strcmp(xtemp,temp2)==0)
	{//jika nama sekolah ada 3 bagian dan kota sekolah valid
		val[y]+=1;//maka valid
	}
}


void CKODE(char xstr[250], int x, int val[x], int y){
	INCKATA(xstr);
	int i=0, pass=0;//var loop dan penada
	char temp[50];//string temporary
	strcpy(temp, GETCKATA());//salin kata
	while(i<GETPANJANGKATA() && pass==0)
	{
		if (temp[i]=='*')
		{//jika ada minimal satu tanda '*'
			pass=1;//tanda berubah
		}
		i+=1;
	}
	if (pass==1)//jika tanda berubah
	{
		val[y]+=1;//maka valid
	}
}