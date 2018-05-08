#include <stdio.h>
#include <math.h>

main() {
	int bil; //variabel untuk nilai integer
	float akar; //variabel untuk nilai akar kuadrat
	int kuadrat; //variabel untuk nilai kuadrat
	
	//meminta uder untuk memasukkan nilai integer
	printf("masukkan angka integer:\n");
	scanf("%d", &bil);
	akar = sqrt(bil);//menghitung akar kuadrat
	kuadrat = bil * bil;//menghitung kuadrat
	//menampikan hasil perhitungan
	printf("bilangan akar: %0.3f\n", akar);
	printf("bilangan kuadrat: %d\n", kuadrat);
	
	return 0;
}