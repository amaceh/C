#include "head.h"

int main()
{
	char head[2];
	int i, j;
	int n, m, linhead[100], colhead[100];
	
	for (i = 0; i < 2; i+=1)
	{
		scanf(" %c", &head[i]);
		if (head[i]=='K')
		{
			scanf("%d", &n);
			for (j = 0; j < n; j+=1)
			{
				scanf("%d", &colhead[j]);
			}
		}else if (head[i]=='B')
		{
			scanf("%d", &m);
			for (j = 0; j < m; j+=1)
			{
				scanf("%d", &linhead[j]);
			}
		}
	}
	
	int matrix[m][n];
	faktorialcount(m, n, linhead, colhead, matrix);

	for (i = 0; i < m; i+=1)
	{
		for (j = 0; j < n; j+=1)
		{
			printf("%d\n", matrix[i][j]);
		}
	}	

	return 0;
}