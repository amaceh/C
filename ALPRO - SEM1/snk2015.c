#include <stdio.h>

int main(){
	//variabel
	int n, m;//banyaknya intruksi dan langkah
	int h, i, j;//index loop
	int x[n], y[n];//array koordinat awal
	int fx[n], fy[n];//array koordinat akhir
	int k, l;//arah, banyak langkah
	int score=0;
	int note[n];
	
	scanf("%d %d", &x[0], &y[0]);//input koordinat awal
	scanf("%d", &n);//input n
	for (h = 0; h < n; h+=1){
		scanf("%d", &m);
		for (i = 0; i < m; i+=1){
			if (k=='v'|| k=='V'){
				y[i+1]=y[i]+ l;
			}else if(k=='h'|| k=='H'){
				x[i+1]=x[i]+ l;
			}
			scanf(" %c %d", &k, &l);
		}
		if(x[h+1]==fx[h] && y[h+1]==fy[h]){
		note[h]=1;
		score=score+10;
		}
		else{
		note[h]=0;
		}
		scanf("%d %d", &fx[h], &fy[h]);
	}
	
	for (j = 0; j < n; j+=1){
		if(note[j]==1){
			printf("makanan %d\n", j+1);
		}
	}
	printf("%d\n", score);
	return 0;
}