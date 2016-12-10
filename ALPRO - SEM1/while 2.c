#include <stdio.h>

int main()
{
	int arr[5];
	int idx;

	for (idx = 0; idx < 5 ; idx +=1)
	{
		printf("masukkan angka :\n");
		scanf("%d", &arr[idx]);
		printf("\n");
	}

	idx = 0;

	while((arr[idx]!=999) && (idx<5)){
		printf("%d\n", arr[idx]);
		idx = idx + 1;
	}
	return 0;
}