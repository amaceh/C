#include <stdio.h>

int underone(int x, int count){
	if (x<1)
	{
		return count;
	}else{
		underone(x/2, count+1);
	}
}

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);
	int mtrx1[L][C], mtrx2[L][C];
	int i, j;
	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			scanf("%d", &mtrx1[i][j]);
		}
	}
	int count=0;
	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			mtrx2[i][j]=underone(mtrx1[i][j], count);
		}
		count=0;
	}

	for (i = 0; i < L; i+=1)
	{
		for (j = 0; j < C; j+=1)
		{
			printf("(%d, %d)", mtrx1[i][j], mtrx2[i][j]);
			if (j<C-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}