#include <stdio.h>
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan evaluasi 1,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main(){
	int n,m;//variabel jumlah input
	int i, j, k, l;//index
	int temp;//temp
	scanf("%d", &n);//meminta input n
	int kursi[n];//array bnyak kursi
	int counter=0;//counter untuk perintah c

	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &kursi[i]);
	}
	scanf("%d", &m);
	char proses;//jenis proses
	int nopros;//nomor yang akan di proses
	for (i = 0; i < m; i+=1){
		scanf(" %c %d", &proses, &nopros);//input proses
		if(proses =='i'){//proses input
			for (j = n; j > m; j-=1){
					
					kursi[j]=kursi[j-1];
					if(kursi[j]==nopros){	
					kursi[j]=kursi[j]*100;
					}
				}
				n = n+1;
		}else if(proses =='d'){//proses delete
			for (j = 0; j > n; j+=1){
					if(kursi[j]==nopros){
					kursi[j+1]=kursi[j];
					}
				}
				n = n-1;//saya kehabisan waktu untuk menyelesaikan ini
		}else if(proses=='c'){//proses hitung
			for (j = 0; j < n; j+=1){
					if(kursi[j]==nopros){
						counter=j+1;
					}
				}
		}
		
	}
	

	for (i = 0; i < n; i+=1)//print elemen
	{
		printf("%d\n", kursi[i]);
	}
	if (counter!=0)//print counter bila perlu
	{
		printf("count: %d\n", counter);
	}

	return 0;
}