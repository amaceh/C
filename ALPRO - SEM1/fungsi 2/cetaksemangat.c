#include "cetaksemangat.h"

int nilaiMinimal(int n, int arr[n]){
	int i, min=arr[0];
	for (i = 1; i < n; i+=1)
	{
		if (min > arr[i])
		{
			min=arr[i];
		}
	}
	return min;
}

int nilaiMaksimal(int n, int arr[n]){
	int i, max=arr[0];
	for (i = 1; i < n; i+=1)
	{
		if (max < arr[i])
		{
			max=arr[i];
		}
	}
	return max;
}

void cetakN(int n){
	int i;
	for (i = 0; i < n; i+=1)
	{
		printf("Terima Kasih Untuk Tetap Semangat, SEMANGAT !!!\n");
	}
}