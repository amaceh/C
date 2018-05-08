#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	scanf("%s", &str);
	int i, j;

	for (i = 0; i < strlen(str); i+=1){
		for (j = 0; j < i; j+=1){
			printf(" ");
		}
		printf("%c\n", str[i]);
	}
	return 0;
}