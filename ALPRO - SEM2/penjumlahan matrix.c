#include <stdio.h>

int main()
{
	int mtrx[4][4];
	int mtrx2[4][4];
	int summtrx[4][4];
	int line;
	int column;

	printf("*******matrix pertama*******\n");
	for (line = 0; line < 4; line+=1)
	{
		for (column = 0; column < 4; column+=1)
		{
			printf("masukkan angka di baris ke %d dan kolom ke %d: ", line+1, column+1);
			scanf("%d", &mtrx[line][column]);
		}
		printf("\n");
	}
	printf("******matrix kedua*******\n");
	for (line = 0; line < 4; line+=1)
	{
		for (column = 0; column < 4; column+=1)
		{
			printf("masukkan angka di baris ke %d dan kolom ke %d: ", line+1, column+1);
			scanf("%d", &mtrx2[line][column]);
		}
		printf("\n");
	}

	for (line = 0; line < 4; line+=1)
	{
		for (column = 0; column < 4; column+=1)
		{
			summtrx[line][column]=mtrx[line][column]+mtrx2[line][column];
		}
	}


	printf("^^^^^^^^matrix hasil penjumlahan^^^^^^^^\n");
	for (line = 0; line < 4; line+=1)
	{
		for (column = 0; column < 4; column+=1)
		{
			printf("%d", summtrx[line][column]);
		}
		printf("\n");
	}
	return 0;
}