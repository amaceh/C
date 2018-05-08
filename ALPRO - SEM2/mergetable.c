#include <stdio.h>

int main()
{
	int n, m, i;
	printf("first table, how long?\n");
	scanf("%d", &n);
	int first[n];
	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &first[i]);
	}
	printf("second table, how long?\n");
	scanf("%d", &m);
	int second[m];
	for (i = 0; i < m; i+=1)
	{
		scanf("%d", &second[i]);
	}
	int merged[n+m];
	for (i = 0; i < n; i+=1)
	{
		merged[i]=first[i];
	}
	for (i = n; i < m+n; i+=1)
	{
		merged[i]=second[i-n];
	}

	for (i = 0; i < n+m; i+=1)
	{
		printf("%d\n", merged[i]);
	}
	return 0;
}