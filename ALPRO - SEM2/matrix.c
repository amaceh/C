#include <stdio.h>

int main()
{
	int matrix[4][4];
	int line, column, maxlen=0, count=1, counter=1;
//input matrix satu persatu
	for (line = 0; line < 4; line+=1)
	{
		for (column = 0; column < 4; column+=1)
		{
			printf("masukkan angka di baris ke %d dan kolom ke %d: ", line+1, column+1);
			scanf("%d", &matrix[line][column]);
			while(matrix[line][column]/count>=1){
				counter+=1;
				if (counter>maxlen)
				{
					maxlen=counter;
				}
				count=count*10;
			}
			counter=1;
			count=1;
		}
		printf("\n");
	}
//print matrix satu persatu
int i=0;	
	for (line = 0; line < 4; line+=1)
	{
		for (column = 0; column < 4; column+=1)
		{
			printf("%d", matrix[line][column]);
			if (column!=3)
			{
				counter=1;
				count=1;
				i=0;
				printf("+");
				while(matrix[line][column]/count>=1){
					counter+=1;
					count=count*10;
				}
				while(i<(maxlen-counter)){
					printf("-");
					i+=1;
				}
				}
			}
		printf("\n");
	}
	printf("%d\n", maxlen);
	
////////////////modif agar rapih/////////////////////////
	
//menyalin matrix
	// int matrix2[4][4];
	// for (line = 0; line < 4; line+=1)
	// {
	// 	for (column = 0; column < 4; column+=1)
	// 	{
	// 		matrix2[line][column]=matrix[line][column];
	// 	}
	// }

	// printf("matrix pertama :\n");
	// for (line = 0; line < 4; line+=1)
	// {
	// 	for (column = 0; column < 4; column+=1)
	// 	{
	// 		printf("%d", matrix[line][column]);
	// 	}
	// 	printf("\n");
	// }
	// printf("matrix kedua(hasil kopian) :\n");
	// for (line = 0; line < 4; line+=1)
	// {
	// 	for (column = 0; column < 4; column+=1)
	// 	{
	// 		printf("%d", matrix2[line][column]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}