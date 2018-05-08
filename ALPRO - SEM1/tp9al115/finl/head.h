//library
#include <stdio.h>//printf, scanf.
#include <string.h>//strlen, strcmp, strcpy etc.
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan tp9al115 TP 9,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
///////menghubungkan library header dengan mesin dan main//////////
//counter adalah jumlah kata yang diinput
//saya membuat berbagai macam temporary
//ada temporari char, ada temp string, dan temp array os string
//swap adalah jumlah huruf yang ditukar
//msg adalah kata yang diinput
void movetotemp(int counter, char temp[500], char msg[100][50]);
void checkchar(int lentem, int swap, char temp[500], 
		char swapchar1[100], char swapchar2[100]);
void returnchar(int counter, char msg[100][50], char temp[500]);
void vocaltotempvoc(int lentem, char temp[500], 
		char tempvoc[300], char tempchar);
void swapstartotempvoc(int lentem, char temp[500],
		char tempvoc[300]);
void movetomsg(int counter, char msg[100][50],
		char temp[500]);
void movetotemp2(int counter, char temparostr[100][50],
		char msg[100][50]);
void reversechar(int counter, char msg[100][50], 
			char temparostr[100][50]);
void returnreverestring(int counter, char msg[100][50],
			char temparostr[100][50]);

////////////////////////////////////////////////////