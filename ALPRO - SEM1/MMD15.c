#include <stdio.h>

	/*saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan MMD15 TP3,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

//membuat bungkus waktu
typedef struct{
	int hari;
	int jam;
	int menit;
	int detik;
}waktu;

int main(){
	waktu pergi, sampai;//variabel waktu
	int jenis;//variabel untuk pemilihan switch kendaraan.

	//memnita input
	scanf("%d", &jenis);//input jenis
	scanf("%d", &pergi.hari);//input hari
	scanf("%d %d %d", &pergi.jam, &pergi.menit, &pergi.detik);//input waktu
	
	int totalpergi = (pergi.jam * 60 * 60) + (pergi.menit * 60) + pergi.detik;
	//waktu keberangkatan di rubah ke detik untuk mempermudah
	int totalsampai;//variabel tambahan untuk perhitungan	

		//switch untuk print hari/tidak ada pilihan dan menentukan lama perjalanan
		switch (jenis){
		case 1 :{
			printf("mobil\n");
			totalsampai = totalpergi + ((7 * 60 * 60) + (20 * 60) + 33);//waktu bila kendaraan mobil
		}break;
		case 2 :{
			printf("bus\n");
			totalsampai = totalpergi + ((9 * 60 * 60) + (10 * 60) + 15);//waktu bila kendaraan bus
		}break;
		case 3 :{
			printf("pesawat\n");
			totalsampai = totalpergi + ((2 * 60 * 60) + (40 * 60) + 10);//waktu bila kendaraan pesawat
		}break;
		default:
		printf("pilihan tidak ada\n");
		break;
	}

	//menggunakan if bila perjalanan melewati tengah malam
	if(totalsampai > (24 * 60 * 60)){
		totalsampai = totalsampai - (24 * 60 * 60);
		pergi.hari = pergi.hari + 1;
	}
	//menggunakan if bila melewati hari minggu
	if (pergi.hari > 7){
		sampai.hari = pergi.hari - 7;
	}
	//menghitung jam, menit, detik waktu sampai
		sampai.jam = (totalsampai/3600);
		sampai.menit = (totalsampai%3600)/60;
		sampai.detik = ((totalsampai % 3600)%60);

	//menggunakan switch untuk menentukan print atau tidaknya hari dan waktu
	switch (jenis){
		case 1 :{
			printf("%d\n", sampai.hari);
			printf("%d %d %.2d\n", sampai.jam, sampai.menit, sampai.detik);
		}break;
		case 2 :{
			printf("%d\n", sampai.hari);
			printf("%d %d %.2d\n", sampai.jam, sampai.menit, sampai.detik);
		}break;
		case 3 :{
			printf("%d\n", sampai.hari);
			printf("%d %d %.2d\n", sampai.jam, sampai.menit, sampai.detik);
		}break;
		default://dibiarkan kosong karena sudah di print pada switch pertama
		break;
	}
	
	return 0;
}