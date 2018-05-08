#include <stdio.h>

int faktorial(int n){
	if (n==0)
	{
		return 0;
	}else if (n==1)
	{
		return 1;
	}else{
		return (n*faktorial(n-1));
	}
}

void faktorialcount(int m, int n, int linhead[100], int colhead[100], int matrix[m][n]){
	int i, j;
	for (i = 0; i < m; i+=1)
	{
		for (j = 0; j < n; j+=1)
		{
			matrix[i][j]=faktorial(linhead[i])*faktorial(colhead[j]);
		}
	}
}

int main()
{
	char head[2];
	int i, j;
	int n, m, linhead[100], colhead[100];
	
	// scanf("%c", &head[0]);
	// int n;
	// scanf("%d", &n);
	// int colhead[n];
	// for (i = 0; i < n; i+=1)
	// {
	// 	scanf("%d", &colhead[i]);
	// }
	
	// scanf(" %c", &head[1]);
	// int m;
	// scanf("%d", &m);
	// int linhead[m];
	// for (i = 0; i < m; i+=1)
	// {
	// 	scanf("%d", &linhead[i]);
	// }

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