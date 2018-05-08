#include <stdio.h>

int main()
{
	int i, n, stat=0;

	printf("Masukkan banyak bilangan\n");
	scanf("%d", &n);
	int arr[n];

	for (i = 0; i < n; i+=1){
		printf("Masukkan bilangan ke %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	i=0;
	while (i<n && stat==0){
		if (arr[i]%2==0)
		{
			stat=1;
		}
		i+=1;
	}

	if (stat==1)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}