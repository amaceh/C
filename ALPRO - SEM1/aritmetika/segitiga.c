#include <stdio.h>

main(){
int tinggi;// variabel tinggi
int alas;//variabel alas
//meminta user memasukkan angka
printf("masukkan ukuran alas:\n");
scanf("%d", &alas);
printf("masukkan ukuran tinggi:\n");
scanf("%d", &tinggi);
//variabel luas
int luas = 0.5 * alas * tinggi;
//menampilkan luas
printf("luas segitiga itu adalah: %d\n", luas);

return 0 ;
}