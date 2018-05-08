#include <stdio.h>
#include <string.h>

typedef struct
{
	int x, y;
}coordinate;

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);
	coordinate matrix[L][C];
	int line, column;
	for (line = 0; line < L; line+=1)
	{
		for (column = 0; column < C; column+=1)
		{
			scanf("%d", &matrix[line][column].x);
			scanf("%d", &matrix[line][column].y);
		}
	}
	int x, i, j, k;
	scanf("%d", &x);
	char command[7];
	int cmd1, cmd2, temp[2];
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %d %d", &command, &cmd1, &cmd2);
		if (strcmp(command, "TukarB")==0)
		{
			for (j = 0; j < C; j+=1)
			{
				temp[0]=matrix[cmd1-1][j].x;
				matrix[cmd1-1][j].x=matrix[cmd2-1][j].x;
				matrix[cmd2-1][j].x=temp[0];
				temp[1]=matrix[cmd1-1][j].y;
				matrix[cmd1-1][j].y=matrix[cmd2-1][j].y;
				matrix[cmd2-1][j].y=temp[1];
			}
		}else if (strcmp(command, "TukarK")==0)
		{
			for (j = 0; j < L; j+=1)
			{
				temp[0]=matrix[j][cmd1-1].x;
				matrix[j][cmd1-1].x=matrix[j][cmd2-1].x;
				matrix[j][cmd2-1].x=temp[0];
				temp[1]=matrix[j][cmd1-1].y;
				matrix[j][cmd1-1].y=matrix[j][cmd2-1].y;
				matrix[j][cmd2-1].y=temp[1];
			}
		}

	for (line = 0; line < L; line+=1)
	{
		for (column = 0; column < C; column+=1)
		{
			printf("(%d,%d)", matrix[line][column].x, matrix[line][column].y);
		}
		printf("\n");
	}
	}

	return 0;
}