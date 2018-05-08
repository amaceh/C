#include <stdio.h>
#include <string.h>

void ptrn(int n, char str[n][50]){
	int i, j, k;
	int space1=0, space2=0, ptrncount[n];

	for (i = 0; i < n; i+=1)
	{
		ptrncount[i]=0;
		for (j = 0; j < strlen(str[i]); j+=1)
		{
			if (str[i][j]=='a' || str[i][j]=='i'
				|| str[i][j]=='u' || str[i][j]=='e'
				|| str[i][j]=='o')
			{
				ptrncount[i] +=1;
			}
		}
	}
	
	for (i = 0; i < n; i+=2)
	{
		for (j = 0; j < ptrncount[i]; j+=1)
		{
			for (k = 0; k < space1; k+=1)
			{
				printf(" ");
			}
			printf("%s\n", str[i]);
			space1+=strlen(str[i]);
		}


		for (j = 1; j < ptrncount[i+1]; j+=1)
		{
			space2+=strlen(str[i+1]);
		}
		for (j = 0; j < ptrncount[i+1]; j+=1)
		{
			for (k = 0; k < space2; k+=1)
			{
				printf(" ");
			}
			printf("%s\n", str[i+1]);
			space2-=strlen(str[i+1]);
		}
	space1=0;
	space2=0;
	}
}

int main()
{
	int i, n;
	scanf("%d", &n);
	char input[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", input[i]);
	}

	ptrn(n, input);


	return 0;
}