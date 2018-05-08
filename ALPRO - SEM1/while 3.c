#include <stdio.h>

int main(){
	
	int n, idx, done, idx2, temp;

	printf("Program penampil 3 angka genap\n");
	printf("mau berapa angka yang akan di cek?\n");
	scanf("%d", &n);
	int arr[n];
	int arrgen[3];
	
	for (idx = 1; idx <= n; idx +=1){
		printf("masukkan angka %d: ", idx);
		scanf("%d", &arr[idx]);
	}

	done = 0;
	idx = 0;
	idx2 = 1;
	while ((done <= 3) && (idx < n)){

		if (arr[idx] % 2 == 0)
		{
			arrgen[idx2]=arr[idx];
			idx2=idx2+1;
			done = done + 1;
		}

		idx=idx+1;
	}

	if(done >= 3){
		for (idx = 1; idx <= 3; idx +=1){
			printf("%d\n", arrgen[idx]);
		}
	}else{
		printf("angka genap kurang\n");
	}

	return 0;
}