/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan CINGEYE1 TP 4,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
#include <stdio.h>

int main()
{
	int n, i, j;//n untuk masukan, i untuk index baris, j untuk index kolom

	//meminta masukan
	scanf("%d", &n);

	//###untuk membuat pola saya membuat empat lapisan pola.##//
	
	for (i = 1; i <= n; i+=1)//for induk untuk membuat newline pada pola atas
	{
		//membuat for spasi untuk membentuk pola atas
		for (j = 1; j <= 2; j+=1)
		{
			printf(" ");
		}
		for (j = n; j-1 >= i; j-=1){
			printf(" ");
		}
		//membuat segitiga pertama
		for (j = 1; j <= i; j+=1)
		{
			printf("*");
		}
		for (j = 1; j <= i; j+=1)
		{
			printf("*");
		}
		//memebuat for spasi lagi untuk membentuk pola
		for (j = n; j-1 >= i; j-=1){
			printf(" ");
		}
		for (j = 1; j <= n*3-3; j+=1)
		{
			printf(" ");
		}
		for (j = n; j-1 >= i; j-=1){
			printf(" ");
		}
		//membuat segitiga atas kedua
		for (j = 1; j <= i; j+=1)
		{
			printf("*");
		}
		for (j = 1; j <= i; j+=1)
		{
			printf("*");
		}
		printf("\n");
	}//akhir dari lapisan pertama

	for (i = 1; i <= n; i+=1)//for induk untuk membuat newline pada lapisan kedua
	{
		//kotak pertama
		for (j = 1; j <= n; j+=1)
		{
			printf("*");
		}
		//kotak spasi pertama
		for (j = 1; j <= n; j+=1)
		{
			printf(" ");
		}
		//persegi panjang di tengah
		for (j = 1; j <= n*3+1; j+=1)
		{
			printf("*");
		}
		//kotak spasi lagi
		for (j = 1; j <= n; j+=1)
		{
			printf(" ");
		}
		//kotak kedua
		for (j = 1; j <= n; j+=1)
		{
			printf("*");
		}
		printf("\n");
	}//akhir dari lapis kedua


	for (i = 1; i <= n; i+=1)//for induk untuk membuat newline di lapisan ketiga
	{	
		//spasi segtiga untuk membentuk pola
		for (j = 1; j <= i-1; j+=1)
		{
			printf(" ");
		}
		//bintang segitita pertama
		for (j = n; j >= i; j-=1){
			printf("*");
		}
		//bintang kotak pertama
		for (j = 1; j <= n*2+1; j+=1)
		{
			printf("*");
		}
		//kotak spasi di tengah
		for (j = 1; j <= n-1; j+=1)
		{
			printf(" ");
		}
		//kotak bintang kedua
		for (j = 1; j <= n*2+1; j+=1)
		{
			printf("*");
		}
		//kotak segitiga kedua
		for (j = n; j >= i; j-=1){
			printf("*");
		}
	printf("\n");
	}//akhir dari lapis ketiga
	
	for (i = 1; i <= n; i+=1)
	{	
		/*menggunakan if karena saya kesulitan
		mencari for yang tepat untuk input 1*/
		//for untuk membuat kotak spasi untuk membentuk pola
		if (n == 1){
			for (j = 1; j <= n*2; j+=1){
			printf(" ");
		}}
		else{
			for (j = 1; j <= n*2+1; j+=1){
			printf(" ");
		}
		}
		//for untuk membuat segitiga spasi untuk membentuk pola
		for (j = 1; j <= i; j+=1)
		{
			printf(" ");
		}
		//for untuk membuat segitiga di tengah
		for (j = n; j >= i; j-=1){
			printf("*");
		}
		for (j = 1; j <= n-3; j+=1)
		{
			printf("*");
		}
		for (j = n; j >= i; j-=1){
			printf("*");
		}
		printf("\n");
	}//akhir dari lapis 4
	return 0;
}