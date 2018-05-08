#include "head.h"

int faktorial(int n){
	if (n==0)
	{
		return 0;
	}
	else if(n==1)
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