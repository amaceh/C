#include <stdio.h>

int sumKelipatan(int matrix, int n){
	if (matrix<n)
	{
		return 0;
	}else{
		int jumlah= (matrix/n)*n;
		return jumlah+sumKelipatan(jumlah-n, n);
	}
}

int main()
{
	int n, L, C, i, j;
	scanf("%d", &n);
	scanf("%d %d", &L, &C);
	int matrix[L][C];
	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			matrix[i][j]=sumKelipatan(matrix[i][j], n);
		}
	}


	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			printf("%d ", matrix[i][j]);	
		}
		printf("\n");
	}

	return 0;
}