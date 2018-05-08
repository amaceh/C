#include <stdio.h>
int main()
{
	int n, i, min,min2;
	scanf("%d", &n);
	int array[n];

	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &array[i]);
	}
	for (i = 0; i < n/2; i+=1)
	{
		if (array[i]<min){
				min=array[i];
		}
	for (i = n/2; i < n; i+=1)
	{
		if (array[i]>min2){
				min2=array[i];
		}
	}
	
	if (min = min2)
	{
		printf("valid\n");
		printf("%d\n", min);
	}else{
		printf("tidak valid\n");
		printf("%d\n", min);
		printf("%d\n", max);
	}
	}
	return 0;
}
	