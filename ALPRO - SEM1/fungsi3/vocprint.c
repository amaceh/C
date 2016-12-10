#include "vocprint.h"

int voccount(int n, char in[n][50]){
	int i, j, voc=0;
	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < strlen(in[i]); j+=1)
		{
			if (in[i][j]=='a' || in[i][j]=='i' 
				|| in[i][j]=='u' || in[i][j]=='e' ||
				in[i][j]=='o')
			{
				voc+=1;
			}
		}
	}
	return voc;
}

void strprint(int n, char in[n][50], int x){
	int i, j;
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < n; j+=1)
		{
			printf("%s", in[j]);
			if (j<n-1)
			{
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
}