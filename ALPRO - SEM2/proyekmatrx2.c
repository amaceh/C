#include <stdio.h>
#include <string.h>

///buat program papan///
int main()
{
	//bersih layar
	system("cls");
	char board[4][4][4];
	char card[4][4][4];
	///[baris][kolom][jumlah char maks]
	int i, j, k;

	//inisialisasi board diisi 0
	for (i = 0; i < 4; i+=1)
	{
		for (j = 0; j < 4; j+=1)
		{
			strcpy(board[i][j], " X ");
		}
	}

	strcpy(card[0][0], "-E6");
	strcpy(card[1][0], "-W4");
	strcpy(card[2][0], "-P3");
	strcpy(card[3][0], "-Q9");
	strcpy(card[0][1], "-V1");
	strcpy(card[1][1], "-B5");
	strcpy(card[2][1], "-I8");
	strcpy(card[3][1], "-X2");
	strcpy(card[0][2], "-A3");
	strcpy(card[1][2], "-C1");
	strcpy(card[2][2], "-Z3");
	strcpy(card[3][2], "-L5");
	strcpy(card[0][3], "-W9");
	strcpy(card[1][3], "-B7");
	strcpy(card[2][3], "-R4");
	strcpy(card[3][3], "-Z2");
	

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	//awalnya setiap player di set -1 sebagai penanda permainan belum mulai
		int player=-1;
		int step=-1, x[2], y[2];
		x[0]=0;
		x[1]=0;
		y[0]=-1;
		y[1]=-1;

		for (i = 0; i < 16; i+=1)
		{
			if (player!=-1)
			{
			if (y[player-1]!=-1 && step<5)
			{
				y[player-1]+=step;
			}else if(y[player-1]!=-1){
				x[player-1]+=1;
				y[player-1]+=step-4;
			}


			//mengisi board jika ada inputan
			if (step!=-1)
			{
				strcpy(board[y[player-1]][x[player-1]], card[y[player-1]][x[player-1]]);
			}

			}
	//gambar board
			printf("**game noob**\n");
			printf("-------------------------\n");
			for (j = 0; j < 4; j+=1)
			{
				printf("| ");
				for (k = 0; k < 4; k+=1)
				{
					//print kartu
					printf("%s | ", board[k][j]);
					
				}
		printf("\n-------------------------\n");
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
		printf("masukkan jumlah langkah (pemain %d): \n", player);
		scanf("%d", &step);
		//bersih layar
		system("cls");//khusus wedhus
		}
	return 0;
}