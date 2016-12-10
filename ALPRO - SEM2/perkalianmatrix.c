#include <stdio.h>

int main()
{
	int mtrx1[2][3];
	int mtrx2[3][3];
	int summtrx[2][3];
	int line, column, kalicount;
	printf("masukkan matrix pertama (2x3)\n");
	for (line = 0; line < 2; line+=1)
	{
		for (column = 0; column < 3; column+=1)
		{
			scanf("%d", &mtrx1[line][column]);
		}
	}
	printf("masukkan matrix kedua (3x3)\n");
	for (line = 0; line < 3; line+=1)
	{
		for (column = 0; column < 3; column+=1)
		{
			scanf("%d", &mtrx2[line][column]);
		}
	}

	for (line = 0; line < 2; line+=1)
	{
		for (column = 0; column < 3; column+=1)
		{
			summtrx[line][column]=0;
			for (kalicount = 0; kalicount < 3; kalicount+=1)
			{
				summtrx[line][column] +=
				mtrx1[line][kalicount]*mtrx2[kalicount][column];
			}
		}
	}
	printf("hasil perkalian\n");
	for (line = 0; line < 2; line+=1)
	{
		for (column = 0; column < 3; column+=1)
		{
			printf("%d ", summtrx[line][column]);
		}
		printf("\n");
	}
	return 0;
}