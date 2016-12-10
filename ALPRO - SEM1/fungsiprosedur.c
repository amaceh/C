#include <stdio.h>

void pola(int n){
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <=n ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	pola (n);
	pola (n+1);
	pola (n+2);
	return 0;
}