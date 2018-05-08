#include <stdio.h>

int main(){
	/*saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan JPP TP 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/
	int n, p, q, r, total, kembalian;
	//variabel hari, waktu masuk, waktu keluar, uang, total bayar, dan kembalian
	char cp;//variabel paket parkir
	
	//meminta input
	scanf("%d", &n);
	scanf(" %c", &cp);
	scanf("%d", &p);
	scanf("%d", &q);
	scanf("%d", &r);
	
	//mengolah input sekaligus hasil
	//hari
	if(n == 1){
		printf("senin ");
	}
	if(n == 2){
		printf("selasa ");
	}
	if(n == 3){
		printf("rabu ");
	}
	if(n == 4){
		printf("kamis ");
	}
	if(n == 5){
		printf("jumat ");
	}
	if(n == 6){
		printf("sabtu ");
	}
	if(n == 7){
		printf("minggu ");
	}
	//paket yang dipilih
	if(cp == 'a'){
		printf("kelabu\n");
	}else if(cp == 'b'){
		printf("ceria\n");
	}
	//menghitung harga parkir
	//harga tiap paket
	int harga;
	if((cp == 'a') && (q>p)){//jika jam parkir tidak melewati tengah malam
		harga = ((q-p-2)*500)+(1500*2);
	}
	if((cp == 'a') && (p>q)){//jika jam parkir melewati tengah malam
		harga = ((24-p+q-2)*500)+(1500*2);
	}
	if((cp == 'b') && (q>p)){//jika jam parkir tidak melewati tengah malam
		harga = ((q-p-1)*1000)+3000;
	}
	if((cp == 'b') && (p>q)){//jika jam parkir melewati tengah malam
		harga = ((24-p+q-1)*1000)+3000;
	}
	
	//perhitungan sesuai hari
	int pajak = harga/4;//jumlah pajak
	if((n==6) || (n == 7)){
		total = harga + pajak;
	}else{
		total = harga;
	}
	kembalian =r-total;
	if(kembalian >= 0){
		printf("%d\n", kembalian);
	}else{
		printf("tidak valid\n");
	}
	return 0;
	
}
