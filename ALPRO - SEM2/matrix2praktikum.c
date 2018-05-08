#include <stdio.h>

typedef struct
{
	int x;
	int y;
}coordinate;


int main()
{
	coordinate position[4][4];
	int i, j;

	for (i = 0; i < 4; i+=1)
	{
		for (j = 0; j < 4; j+=1)
		{
			printf("untuk elemen baris %d kolom %d\n", i+1, j+1);
			printf("masukkan koordinat x : ");
			scanf("%d", &position[i][j].x);
			printf("masukkan koordinat y : ");
			scanf("%d", &position[i][j].y);
		}
	}

	for (i = 0; i < 4; i+=1)
	{
		for (j = 0; j < 4; j+=1)
		{
			printf("(%d,%d)", position[i][j].x, position[i][j].y);
		}
		printf("\n");
	}

	return 0;
}	