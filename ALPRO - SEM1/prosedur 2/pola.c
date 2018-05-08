#include "pola.h"

void pola (int n){
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void tulisArrayInt(int n, int arr[n]){
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}
}