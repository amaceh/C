#include <stdio.h>
/*
Kang Cecep memiliki n domba garut, setiap dua ekor 
domba menghasilkan m ekor anak dalam setahun. Setiap tahun Kang 
Cecep menjual p ekor domba dan baru bisa dijual setelah tahun ke 2 
(mulai tahun ke- 3).

Format Masukan:


n, 2 < n <= 100, jumlah domba awal, n bilangan genap
m, 0 < m <= 6, m bilangan genap
p, 0 < p <= 6, p bilangan genap
r, 0 < r <= 50


Tampilkan jumlah domba Kang Cecep pada tahun ke r

misalkan 

n = 2
m = 2
p = 2
r = 2

maka akan menampilkan
8*/
int main (){
	int n, m, p, r;//variabel tiap angka
	int index;//variabel loop
	int jumwal, jumhir;
	
	//meminta masukkan user untuk setiap angka
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &p);
	scanf("%d", &r);
	//mengolah angka
	jumwal=(n/2)*m;
	for (index=1; index<r; index+=1){
		if(n%2==0){
			jumhir=jumwal;
		}
	}
	
	printf("%d\n", jumlah);
	//int jual = (r-2)*p;
	//int total = anak - jual;
	
	return 0;
	
}
