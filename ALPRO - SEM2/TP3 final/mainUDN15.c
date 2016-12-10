#include "UDN15.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan UDN15 TP3,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main()
{
	int x, i;//var jumlah data dan loop
	scanf("%d", &x);//meminta input jumlah data
	Glist arr[x];//deklarasi bungkusan
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %s %d", &arr[i].name, &arr[i].class, &arr[i].grade);//input nama, kelas dan nilai
	}
	/////****untuk menyelesaikan soal, cara termudah adalah dengan mengurutkan semuanya sesuai nama
	///////****kemudian baru mengurutkannya sesuai nilai
	inssortbyname(x, arr);//memanggil prosedur pengurut nama
	inssortbygrade(x, arr);//memanggil prosedur pengurut nilai
	for (i = 0; i < x; i+=1)
	{
		printf("%s %s %d\n", arr[i].name, arr[i].class, arr[i].grade);//print hasil urutan
	}
	return 0;
}
