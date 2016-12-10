#include <stdio.h>//library untuk printf scanf
#include <string.h>//library untuk strcmp strcpy

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan DLOM14 TP1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
void blankmap(char mtrx[10][10][2]);//prosedur default peta
//prosedur pengolahan langkah di peta
void mapdrawing(int x, int y, int n, char move[n][6], int step[n], char mtrx[10][10][2]);
void printmap(char mtrx[10][10][2]);//prosedur pencetakan hasil olahan peta