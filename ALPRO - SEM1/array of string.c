#include <stdio.h>
#include <string.h>

typedef struct{
	char word[50];
}string;

int main(){
	int n, i, j;
	scanf("%d", &n);
	string arr[50];

	for (i = 0; i < n; i+=1){
		scanf("%s", &arr[i].word);
	}

	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < strlen(arr[i]); j+=1)
		{
			printf("%c\n", arr[j].word[i]);
		}
	}
	return 0;
}