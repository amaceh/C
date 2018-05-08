#include <stdio.h>
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan MakaKost TP 6,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

//membuat typedef struct
typedef struct{
	int rate;
	int price;
}food;//nama

int main(){
	char rate2, price2;//variabel inputan pilihan ziah
	int i=0,j, k, money, outrate, outprice, limit=1;
	//variabel loop, uang yang dimiliki ziah, dan output. serta pembatas loop input
	food input[500];//array of typedef struct

	while(limit !=0){//meminta input dengan loop
		scanf("%d", &input[i].rate);
		limit=input[i].rate;//memasukkan nilai input ke dalam syarat loop
		if(limit !=0){//jika input 0 maka harga tidak akan diinput lagi
		scanf("%d", &input[i].price);
		i+=1;
			}
		}
	scanf(" %c %c", &rate2, &price2);//meminta permintaan ziah
	scanf("%d", &money);//meminta jumlah uang ziah

			if (rate2=='E'){//jika ziah mau enak
				for (j = 0; j < i; j+=1){
					if (price2=='J' && input[j].rate>=6 && input[j].price<=money){
						//jika ziah mau yang mahal, syarat lanjutan dari enak, dan harus sesuai jumlah uangnya
						if (j==0){//pengunaan pengondisian ini untuk membuat perbandingan berjalan
							outprice=0;//pembanding dibuat sangat murah sebagai awalan
						}
						if(input[j].price>outprice){//jika ada yang lebih mahal maka angka diganti
						outprice=input[j].price;
						outrate=input[j].rate;
						}
					}else if(price2=='K' && input[j].rate>=6 && input[j].price<=money){
						//jika ziah mau yang murah, syarat lanjutan dari enak, dan harus sesuai jumlah uangnya
						if (j==0){//pengunaan pengondisian ini untuk membuat perbandingan berjalan
							outprice=9999999;//pembanding dibuat sangat mahal sebagai awalan
						}
						if(input[j].price<outprice){//jika ada yang lebih murah maka angka diganti
						outprice=input[j].price;
						outrate=input[j].rate;
						}
					}
				}
			}
			if (rate2=='S'){//jika ziah mau yang sedang sedang saja
				for (j = 0; j < i; j+=1){
					if (price2=='J' && input[j].rate<=5 && input[j].price<=money){
						//jika ziah mau yang mahal, syarat lanjutan dari sedang, dan harus sesuai jumlah uangnya
						if (j==0){//pengunaan pengondisian ini untuk membuat perbandingan berjalan
							outprice=0;//pembanding dibuat sangat murah sebagai awalan
						}
						if(input[j].price>outprice){//jika ada yang lebih mahal maka angka diganti
						outprice=input[j].price;
						outrate=input[j].rate;
						}
					}else if(price2=='K' && input[j].rate<=5 && input[j].price<=money){
						//jika ziah mau yang murah, syarat lanjutan dari sedang, dan harus sesuai jumlah uangnya
						if (j==0){//pengunaan pengondisian ini untuk membuat perbandingan berjalan
							outprice=9999999;//pembanding dibuat sangat mahal sebagai awalan
						}
						if(input[j].price<outprice){//jika ada yang lebih murah maka angka diganti
						outprice=input[j].price;
						outrate=input[j].rate;
						}
					}
				}
			}
		
	if (outrate != 0){//jika ada angka yang diisi maka di print
		printf("%d\n", outrate);
		printf("%d\n", outprice);
	}else{//jika tidak ada
		printf("Kelaparan\n");
	}
	return 0;
}