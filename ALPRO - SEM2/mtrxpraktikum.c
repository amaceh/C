#include <stdio.h>
#include <string.h>

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);
	int matrix[L][C];
	int line, column;
	for (line = 0; line < L; line+=1)
	{
		for (column = 0; column < C; column+=1)
		{
			scanf("%d", &matrix[line][column]);
		}
	}
	int x, i, j, k;
	scanf("%d", &x);
	char command[7];
	int cmd1, cmd2, temp;
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %d %d", &command, &cmd1, &cmd2);
		if (strcmp(command, "TukarB")==0)
		{
			for (j = 0; j < C; j+=1)
			{
				temp=matrix[cmd1-1][j];
				matrix[cmd1-1][j]=matrix[cmd2-1][j];
				matrix[cmd2-1][j]=temp;
			}
		}else if (strcmp(command, "TukarK")==0)
		{
			for (j = 0; j < L; j+=1)
			{
				temp=matrix[j][cmd1-1];
				matrix[j][cmd1-1]=matrix[j][cmd2-1];
				matrix[j][cmd2-1]=temp;
			}
		}
	}

	for (line = 0; line < L; line+=1)
	{
		for (column = 0; column < C; column+=1)
		{
			printf("%d ", matrix[line][column]);
		}
		printf("\n");
	}

	return 0;
}