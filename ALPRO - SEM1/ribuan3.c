#include <stdio.h>
int main(){
	/*saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan online judge ini,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/
	int a, b, c, d, e, f;//kotak input angka
	//meminta masukkan user untuk tiap kotak
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	scanf("%d", &f);
	//membuat kotak integer penanda
	int aa=0, bb=0, cc=0, dd=0, ee=0, ff=0;
	//memeriksa setiap kotak ribuan atau tidak
	if((a >= 1000) && (a <= 9999)){
		aa=1;
		}
	if((b >= 1000) && (b <= 9999)){
		bb=1;
		}
	if((c >= 1000) && (c <= 9999)){
		cc=1;
		}
	if((d >= 1000) && (d <= 9999)){
		dd=1;
		}
	if((e >= 1000) && (e <= 9999)){
		ee=1;
		}
	if((f >= 1000) && (f <= 9999)){
		ff=1;
		}
	//menghitung tanda
	int tanda = aa + bb + cc + dd + ee + ff;
	//memeriksa memenuhi syarat atau tidak
	if(tanda >= 3){
		printf("ribuan 3 atau lebih\n");
		}
	else{
		printf("tidak valid\n");
	}
return 0;
}