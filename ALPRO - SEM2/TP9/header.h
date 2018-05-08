#include <stdio.h>//printf, scanf
#include <string.h>//strcpy, strcmp
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan RSBMPTN1 TP9,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int idx, wordlen;
char cword[50];
//////deklarasi mesin kata
void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char pita[]);
////////////
////////////deklarasi prosedur lain////////
////prosedur pengecek kata REG
void CREG(char xstr[250], int x, int val[x], int y);
////prosedur pengecek kata SBMPTN
void CSBM(char xstr[250], int x, int val[x], int y);
////prosedur pengecek nama
void CNAMA(char xstr[250], int x, int val[x], int y);
////prosedur pengecek kota
void CKOTA(char xstr[250], int x, int val[x], int y, char temp[50]);
////prosedur peubah kata menjadi lowercase(mempermudah membandingkan sekolah dan kota)
void converttolowercase(char xstr[50]);
////prosedur pengecek sekolah
void CSKLH(char xstr[250], int x, int val[x], int y, char xtemp[50]);
/////prosedur pengecek kode
void CKODE(char xstr[250], int x, int val[x], int y);
////////////