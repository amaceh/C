#include <stdio.h>
#include <string.h>

int fibo(int a, int b, int xnum, int i){
	int counter=a+b;
	if (counter >= xnum)
	{
		return i;
	}else{
		fibo(b, a+b, xnum, i+1);
	}
}

void drawNprint(int x, int y, int M1[x][y], int M2[x][y], 
	int M3[x][y], int M4[x][y], char M5[x][y][2]){
	
	int i, j;
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			int counter=fibo(M1[i][j], M2[i][j], M3[i][j], 3);
			if (counter<M4[i][j])
			{
				strcpy(M5[i][j], "X");
			}else{
				strcpy(M5[i][j], "O");
			}
		}
	}

	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			printf("%s ", M5[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int M1[x][y], M2[x][y], M3[x][y], M4[x][y];
	char M5[x][y][2];
	int i, j;

	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			scanf("%d", &M1[i][j]);
		}
	}
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			scanf("%d", &M2[i][j]);
		}
	}
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			scanf("%d", &M3[i][j]);
		}
	}
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			scanf("%d", &M4[i][j]);
		}
	}
	
	drawNprint(x, y, M1, M2, M3, M4, M5);
		
	return 0;
}