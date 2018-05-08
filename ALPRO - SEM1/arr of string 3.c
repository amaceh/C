#include <stdio.h>
#include <string.h>

int main(){
	
	int n, i, j, spasi=0;
	scanf("%d", &n);
	char arr[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &arr[i]);
	}
	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < spasi; j+=1)
		{
			printf(" ");
		}
		printf("%s\n", arr[i]);
		spasi+=strlen(arr[i]);
	}

	
	return 0;
}	