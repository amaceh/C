#include <stdio.h>
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan arrbalik UTS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	int n, h, i, j, k;//variabel jumlah inputan dan index1,index2 dan index 3
	//meminta input
	scanf("%d", &n);
	//membuat array penampung angka
	int tabint[n];

	for (i = 0; i < n; i+=1)//for untuk membuat banyak scanf sesuai input n
	{
		scanf("%d", &tabint[i]);
	}

	int temp;
	for (i = 0; i < n/2; i+=1){
		
		temp = tabint[i];
		tabint[i] = tabint[i+n/2];
		tabint[i+n/2] = temp;

		//ingat ingat, sama dengan dalam program berarti became/jadilah
		//maka sama dengan yang terbalik menimbulkan error pada program
	}

	for (k = 0; k < n; k+=1)
	{
		printf("%d\n", tabint[k]);
	}

	return 0;
}