#include <stdio.h>
#include <string.h>

int main()
{
	int x, y, n, i, j;
	scanf("%d %d", &x, &y);
	scanf("%d", &n);
	char move[n][6];
	int step[n];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s %d", &move[i], &step[i]);
	}
	
	char mtrx[10][10][2];
	//inisialisasi
	for (i = 0; i < 10; i+=1)
	{
		for (j = 0; j < 10; j+=1)
		{
			strcpy(mtrx[i][j], "*");
		}
	}
	strcpy(mtrx[y-1][x-1], "x");

	for (i = 0; i < n; i+=1)
	{
		if (strcmp(move[i], "kanan")==0)
		{
			for (j = x; j < step[i]+x; j+=1)
			{
				strcpy(mtrx[y-1][j], "-");
			}
			x+=step[i];
		}else if(strcmp(move[i], "kiri")==0){
			for (j = x; j > x-step[i]; j-=1)
			{
				strcpy(mtrx[y-1][j-2], "-");
			}
			x-=step[i];
		}else if(strcmp(move[i], "atas")==0){
			for (j = y; j > y-step[i]; j-=1)
			{
				strcpy(mtrx[j-2][x-1], "|");
			}
			y-=step[i];
		}else if(strcmp(move[i], "bawah")==0){
			for (j = y; j < step[i]+y; j+=1)
			{
				strcpy(mtrx[j][x-1], "|");
			}
			y+=step[i];
		}
	}

	for (i = 0; i < 10; i+=1)
	{
		for (j = 0; j < 10; j+=1)
		{
			printf("%s", mtrx[i][j]);
		}
		printf("\n");
	}

	return 0;
}