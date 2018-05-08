#include "bk16.h"//memanggil header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan bk16 kuis1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

//fungsi mencari berapakali membelah
int underone(int x, int count){
	if (x<1)//jika angka berada di bawah nol
	{
		return count;//kembalikan nilai urutan
	}else{//jika tidak
		underone(x/2, count+1);//lakukan pemanggilan kembali fungsi
	}
}

int underone2(int n, int c) {
	if (n < 2)
		return 0;
	else
		return 1 + underone2(n / 2, 0);
}