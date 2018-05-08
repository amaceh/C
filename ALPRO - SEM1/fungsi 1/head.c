#include "head.h"

// int jumlahA(char str[]){
// 	int i, j=0;

// 	for (i = 0; i < strlen(str); i+=1)
// 	{
// 		if (str[i]=='a' || str[i]=='A')
// 		{
// 			j+=1;
// 		}
// 	}
// 	return j;
// }

// int tambah(int a, int b){
// 	return (a+b);
// }

int sum(int n, int arr[n]){
	int i, hasil=0;
	for (i = 0; i < n; i+=1)
	{
		hasil+=arr[i];
	}
	return hasil;
}