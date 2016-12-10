#include <stdio.h>

int main() {
	int input; //membuat variabel untuk menampung input angka
	int ribuan; //membuat variabel ribuan
	int ratusan; //membuat variabel ratusan
	int puluhan; //membuat variabel puluhan
	int satuan; //membuat variabel satuan
	int balikan; // membuat variabel hasil
	int jam; //membuat variabel jam
	int menit;//membuat variabel menit
	int detik;//membuat variabel detik
		
		//meminta user memasukkan angka
		scanf("%d", &input);
		//mengolah angka
		ribuan=input / 1000;
		ratusan=(input/100)-(ribuan*10);
		puluhan=(input/10)- (ribuan*100) - (ratusan*10);
		satuan=input-(ribuan*1000)-(ratusan*100)-(puluhan*10);
		balikan=(satuan*1000)+(puluhan*100)+(ratusan*10)+ribuan;
		
		//mengolah jam
		jam = (balikan/3600);
		menit = (balikan%3600)/60;
		detik = ((balikan % 3600)%60);
	
	//menampilkan angka
	printf("%d\n", balikan);
	printf("%.2d:%.2d:%.2d\n", jam, menit, detik);
return 0;
/*saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan TP 1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/
}