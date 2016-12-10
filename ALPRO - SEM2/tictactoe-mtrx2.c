#include <stdio.h>

int main()
{
	//bersih layar
	system("cls");
	int board[3][3];
	//angka 1 player 1 == huruf O
	//angka 2 player 2 == huruf X
	int i, j, k;

	//inisialisasi board diisi 0
	for (i = 0; i < 3; i+=1)
	{
		for (j = 0; j < 3; j+=1)
		{
			board[i][j]=0;
		}
	}

	//awalnya setiap player di set -1 sebagai penanda permainan belum mulai
		int player=-1;
		//x dan y juga di set -1
		int x=-1, y=-1;
		for (i = 0; i < 9; i+=1)
		{
			//mengisi board jika ada inputan
			if ((x != -1) && (y != -1))
			{
				board[x][y]=player;
			}

	//gambar board
			printf("**noob tictactoe**\n");
			printf("--1---2---3--\n");
			printf("-------------\n");
			for (j = 0; j < 3; j+=1)
			{
				printf("| ");
				for (k = 0; k < 3; k+=1)
				{
					if (board[k][j]==0)
					{
						//jika papan kosong
						printf("  | ");
					}else if (board[k][j]==1)
					{
						//jika papan diisi pemain pertama
						printf("O | ");
					}else if (board[k][j]==2)
					{
						//jika papan diisi pemain kedua
						printf("X | ");
					}
				}
		printf("\n-------------\n");
			}
		printf("\n");

		//pergantian pemain yang akan mengisi papan
			if (player==1)
			{
				player=2;
			}else{
				player=1;
			}

		//meminta masukkan pemain
		printf("masukkan x, y (pemain %d): \n", player);
		scanf("%d %d", &x, &y);
		x-=1;
		y-=1;
		//bersih layar
		system("cls");//khusus wedhus
		}
	return 0;
}