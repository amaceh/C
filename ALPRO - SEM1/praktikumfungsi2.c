#include <stdio.h>
#include <string.h>

int palindrom(int a, char str[a][50]){
	int i, j, idx, counter1=0, counter2=0;
	int limit;
	for (i = 0; i < a; i+=1)
	{
		limit=strlen(str[i])/2;
		for (j = 0; j < limit; j+=1)
		{
			if (j==0)
			{
				idx=(strlen(str[i]))-1;
			}
			
			if (str[i][j]==str[i][idx])
			{
				counter1+=1;
			}
			idx -=1;
		}
		if (counter1==limit)
		{
			counter2+=1;
		}
		counter1=0;
	}
	return counter2;
}


int main()
{
	int n, i;
	scanf("%d", &n);
	char in[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", in[i]);
	}
	int hasil=palindrom(n, in);
	if (hasil==n)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}