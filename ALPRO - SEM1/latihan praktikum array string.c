#include <stdio.h>
#include <string.h>

int main(){
	int n, i, j;
	char str[n][50];

	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%s", str[i]);
	}
	int panjangmaks;
	panjangmaks=strlen(str[0]);
	for (i = 0; i < n; ++i)
	{
		if (panjangmaks<strlen(str[i]))
		{
			panjangmaks=strlen(str[i]);
		}
	}
	//out
	for (i = 0; i < panjangmaks; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if(i>strlen(str[j])){
				printf(" ");
			}else{
				printf("%c", str[j][i]);
			}
		}
		printf("\n");
	}


	return 0;
}