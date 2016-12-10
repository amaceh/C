#include <stdio.h>

int main(){
	
	int n, idx, done;

	printf("Program pengecek ada/tidak ada ganjil\n");
	printf("mau berapa angka yang akan di cek?\n");
	scanf("%d", &n);
	int arr[n];
	
	for (idx = 1; idx <= n; idx +=1){
		printf("masukkan angka %d: ", idx);
		scanf("%d", &arr[idx]);
		printf("\n");
	}

	done = 0;
	idx = 1;
	while((done == 0)&&(idx <= n)){

		if (arr[idx] % 2 == 1)
		{
			done = 1;
		}else{
			idx = idx + 1;
		}
	}

	if(done == 1){
		printf("ada angka ganjil..\n");
	}else{
		printf("tidak ada angka ganjil..\n");
	}

	return 0;
}