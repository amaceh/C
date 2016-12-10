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

	int x, n, cmd1, cmd2, temp;
	char command[8];
	int i, j, k, stop=0;
	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%s %d %d %d", 
			&command, &n, &cmd1, &cmd2);
		if (strcmp(command, "Replace")==0)
		{
			matrix[cmd1-1][cmd2-1]=n;
		}else if(strcmp(command, "Swap")==0){
			j=0;
			while(stop==0 && j<L){
				k=0;
				while(stop==0 && k<C){
					if (matrix[j][k]==n){
						stop=1;
						temp=matrix[j][k];
						matrix[j][k]=matrix[cmd1-1][cmd2-1];
						matrix[cmd1-1][cmd2-1]=temp;
					}else{
						k+=1;
					}
				}
				j+=1;
			}
			stop=0;
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