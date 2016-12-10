#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan latihan sequential file,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

// bungkusan
typedef struct {
  char nim[15];  // variabel nim
  char nama[50];  // variabel nama
  char kelas[10];  // variabel kelas
}mahasiswa;  // nama bungkusan

// variabel global
mahasiswa data[999];  // variabel bungkusan menampung data
int n;                // banyak data

// prosedur
int longerstr(); 			 //pencari nama terpanjang
int longerstr2(); 			 //pencari nim terpanjang
int longerstr3(); 			 //pencari kelas terpanjang

void readFile();             // untuk membaca file
void writeFile();            // untuk menulis file
int findData(char[15]);      // fungsi untuk mencari data yang sama
void insertData(mahasiswa);  // untuk memasukan data
void deleteData(char[15]);   // untuk menghapus data
void updateData(char[15]);   // untuk mengupdate data