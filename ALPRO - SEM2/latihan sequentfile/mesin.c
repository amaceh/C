#include "header.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan latihan sequential file,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

// proses pencarian nama terpanjang
int longerstr(){
  int i;
  int thelongest=strlen(data[0].nama);
  for (i = 1; i < n; i+=1)
  {
    if (thelongest<strlen(data[i].nama))//jika ada yg lebih panjang
    {
      thelongest=strlen(data[i].nama);//ganti nilai
    }
  }
  return thelongest;//kembalikan nilai hasil
}
// proses pencarian nim terpanjang
int longerstr2(){
  int i;
  int thelongest=strlen(data[0].nim);
  for (i = 1; i < n; i+=1)
  {
    if (thelongest<strlen(data[i].nim))//jika ada yg lebih panjang
    {
      thelongest=strlen(data[i].nim);//ganti nilai
    }
  }
  return thelongest;//kembalikan nilai hasil
}
// proses pencarian kelas terpanjang
int longerstr3(){
  int i;
  int thelongest=strlen(data[0].kelas);
  for (i = 1; i < n; i+=1)
  {
    if (thelongest<strlen(data[i].kelas))//jika ada yg lebih panjang
    {
      thelongest=strlen(data[i].kelas);//ganti nilai
    }
  }
  return thelongest;//kembalikan nilai hasil
}
// proses membaca file
void readFile(){
  n = 0;          // deklarasi n sama dengan nol
  mahasiswa tmp;  // bungkusan penamppung
  FILE *fdata;    // deklarasi nama file
  // membaca file
  fdata=fopen("data/mahasiswa.dat", "r");

  // proses membaca file dan ditampung di bungkusan
  do {
    fscanf(fdata, "%s %s %s",  tmp.nim, tmp.nama, tmp.kelas);
    if (strcmp(tmp.nim, "##") != 0 && strcmp(tmp.nama, "##") != 0 
      && strcmp(tmp.kelas, "##") != 0) {
    	data[n] = tmp;
    	n += 1;
    }
  }while (strcmp(tmp.nim, "##") != 0 && strcmp(tmp.nama, "##") != 0 &&
  		strcmp(tmp.kelas, "##") != 0);
  // menutup file
  fclose(fdata);
}

// proses menulis file
void writeFile() {
  int i;  // variabel iterasi

  FILE *fdata;  // deklarasi fdata
  // menulis di file
  fdata = fopen("data/mahasiswa.dat", "w");
  // proses penulisan file
  for (i = 0; i < n; i += 1) {
    fprintf(fdata, "%s %s %s\n", data[i].nim, data[i].nama, data[i].kelas);
  }
  // proses penambahan record dummy
  fprintf(fdata, "## ## ##\n");
  // menutupi file
  fclose(fdata);
}

// proses mencari data
int findData(char nim[15]) {
  int status = 0;  // deklarasi status sama dengan nol
  int i = 0;       // variabel iterasi

  // memanggil prosedur baca
  readFile();

  // proses mencari
  while (status == 0 && i < n) {
    if (strcmp(data[i].nim, nim) == 0) {
      // jika nilai yang dicari ada
      status = 1;  // status menjadi 1
    } else {
      i += 1;
    }
  }
  // melempar nilai status
  return status;
}

// proses menambah data
void insertData(mahasiswa masukan) {
  int status = findData(masukan.nim);  // menerima lemparan dari proses mencari
  // jika nim tidak ganda
  if (status == 0) {
    // data baru dimasukan
    data[n] = masukan;
    n += 1;
    // data ditulis kedalam file
    writeFile();
    printf("Data berhasil ditambahkan\n");
  } else {
    // jika nim ganda, tidak bisa memasukan data baru
    printf("NIM sudah terdaftar, data gagal ditambahkan\n");
  }
}

// proses menghapus data
void deleteData(char nim[15]) {
  // pemanggilan prosedur baca
  readFile();
  int i, j;        // variabel iterasi
  int status = 0;  // variabel status
  i = 0;
  char hapus[10];  // variabel hapus

  // proses menghapus data
  while (i < n && status == 0) {
    // jika nim yang akan dihapus ada
    if (strcmp(data[i].nim, nim) == 0) {
      status = 1;  // status menjadi satu
      // mencegah jika salah menghapus data
      printf("Data ditemukan. Yakin hapus data?");
      printf("ya/tidak\n");
      // input hapus(ya) atau tidak
      scanf("%s", hapus);
      // jika pilihan ya, maka data dihapus
      if (strcmp(hapus, "ya") == 0) {
        for (j = i; j < n; j += 1) {
          data[j] = data[j + 1];
        }
        n -= 1;
        // data ditulis ke dalam file
        writeFile();
      }
    } else {
      // jika tidak, data tidak akan dihapus
      i += 1;
    }
  }

  // jika nim tidak ada dalam data
  if (status == 0) {
    printf("Data tidak ditemukan\n");
  }
}

// proses update data
void updateData(char nim[15]) {
  // pemanggilan prosedur baca
  readFile();
  int i, j;        // variabel iterasi
  int status = 0;  // variabel status

  i = 0;
  char nama[25], kelas[15];  // variabel menampung nama dan kelas
  // proses update
  while (i < n && status == 0) {
    // jika nim yang akan diupdate ada di dalam data
    if (strcmp(data[i].nim, nim) == 0) {
      status = 1;
      printf("Data ditemukan\n");
      // tampilan awal sebelum diupdate
      printf("--Data Awal--\n");
      printf("Nama : %s\n", data[i].nama);
      printf("Kelas : %s\n", data[i].kelas);
      printf("-----------\n");
      // input data baru agar data terupdate
      printf("Masukan nama baru : \n");
      scanf("%s", nama);
      printf("Masukan kelas baru : \n");
      scanf("%s", kelas);
      // proses menempatkan ke dalam bungkusan
      strcpy(data[i].nama, nama);
      strcpy(data[i].kelas, kelas);
      printf("Data berhasil diupdate\n");
      // data ditulis kembali ke dalam file
      writeFile();
    } else {
    	i += 1;
    }
  }
  // jika nim tidak ada di dalam data
  if (status == 0) {
    printf("Data tidak ditemukan\n");
  }
}