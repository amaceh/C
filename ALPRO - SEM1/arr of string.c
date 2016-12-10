#include <stdio.h>
#include <string.h>

int main(){
	
	int n, i, j, jumlah=0;
	scanf("%d", &n);
	char arr[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &arr[i]);
	}

	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < strlen(arr[i]); j+=1)
		{
			if (arr[i][j]=='a')
			{
				jumlah+=1;
			}
		}
	}
	printf("jumlah huruf a : %d\n", jumlah);
	return 0;
}	