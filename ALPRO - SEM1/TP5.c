#include <stdio.h>
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan SNK2015 TP 5,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main(){
	//variabel
	int n, m;//banyaknya intruksi dan langkah
	int h, i, j;//index loop
	int x, y;//array koordinat awal
	int buah[2];//array koordinat akhir
	char k;
	int l;//arah, banyak langkah
	int score=0;//score
	int note[100];//pencatat makanan Ke berapa
	
	scanf("%d %d", &x, &y);//input koordinat awal
	scanf("%d", &n);//input n
	for (h = 0; h < n; h+=1){
		scanf("%d", &m);//scan jumlah langkah
		for (i = 0; i < m; i+=1){
			scanf(" %c %d", &k, &l);
			if (k=='V'){//jika vertikal
				y=y+ l;
			}else if(k=='H'){//jika horizontal
				x=x+ l;
			}
			scanf("%d %d", &buah[0], &buah[1]);
			if(x==buah[0] && y==buah[1]){//jika makanan bisa dimakan
			note[h]=1;
			score=score+10;
			}
			else{//jika makanan tak bisa dimakan
			note[h]=0;
			}
		}
	}
	//print output
	for (j = 0; j < n; j+=1){
		if(note[j]==1){
			printf("makanan %d\n", j+1);//tambah satu karena array dimulau dari nol
		}
	}
	printf("%d\n", score);
	
	return 0;
}

