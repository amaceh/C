#include <stdio.h>

typedef struct
{
	int x;
	int y;
}titik;

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);
	titik matrix[L][C];
	int i, j;
	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			printf("input baris %d kolom %d \n", i+1, j+1);
			scanf("%d", &matrix[i][j].x);
			scanf("%d", &matrix[i][j].y);
		}
	}

	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			printf("(%d,%d)", matrix[i][j].x, matrix[i][j].y);
		}
		printf("\n");
	}
	return 0;
}