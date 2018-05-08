#include "EV2FP15.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan EV2FP15 evaluasi 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int n, m;//variable jumlah inputan dan jumlah kata yang dicari
	int i;//var loop
	scanf("%d", &n);//input jumlah kata
	char randomword[n][100];//arr of str inputan
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", randomword[i]);//input setiap kata
	}
	char whatword[100];//str kata yang dicari
	scanf("%s", whatword);//input string
	scanf("%d", &m);//input jumlah kata
	//memanggil fungsi kemudian hasilnya dimasukkan ke totalword
	int totalword=vertisearch(n, randomword, whatword)+horisearch(n,randomword,whatword);
	if (totalword==m)//jika jumlahnya sama
	{
		printf("Semangat TMD!!!\n");//print
	}else{//jika tidak
		printf("Jangan ditunda-tunda TMDnya!!!\n");//print
	}
	return 0;
}