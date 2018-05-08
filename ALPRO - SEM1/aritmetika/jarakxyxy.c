#include <stdio.h>
#include <math.h>

main() {
	int bilxsatu; //variabel x1
	int bilxdua; //variabel x2
	int bilysatu; //variabel y1
	int bilydua; //variabel y2
	//meminta user memasukkan tiap angka
	printf("masukkan nilai x1:\n");
	scanf("%d", &bilxsatu);
	printf("masukkan nilai y1:\n");
	scanf("%d", &bilysatu);
	printf("masukkan nilai x2:\n");
	scanf("%d", &bilxdua);
	printf("masukkan nilai y2:\n");
	scanf("%d", &bilydua);
	//menghitung dengan rumus
	//mengurangakan
	int rumussatu = bilxsatu - bilxdua;
	int rumusdua = bilysatu - bilydua;
	//mengkuadratkan
	int rumustiga = rumussatu * rumussatu;
	int rumusempat = rumusdua * rumusdua;
	//mengakarkan kuadrat (xi-x2)
	float rumuslima = sqrt(rumustiga);
	//menjumlahkan
	float hasil = rumusempat + rumuslima;
	//menampilkan hasil
	printf("jarak titik adalah: %0.2f\n", hasil);
	
	return 0;
}