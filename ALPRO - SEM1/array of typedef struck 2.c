#include <stdio.h>
/*tampilkan semua titik yang x-nya ganjil 
	dan y-nya lebih besar dari x*/
typedef struct 
{
	int x;
	int y;
}titik;

int main()
{
	int n, i, jx=0, jy=0;
	printf("mau berapa banyak?\n");
	scanf("%d", &n);
	titik ikatan_titik[n];//array of typedef struct
	for (i = 1; i <= n; i+=1)
	{
		printf("masukkan titik X [spasi] Y ke %d\n", i);
		scanf("%d %d", &ikatan_titik[i].x, &ikatan_titik[i].y);//how to input arroftystr
	}

	for (i = 1; i <= n; i+=1)
	{
		if (ikatan_titik[i].x % 2 == 1){
				printf("x ke %d ganjil, nilai x tersebut : %d\n", i, ikatan_titik[i].x);
			}
		if (ikatan_titik[i].y > ikatan_titik[i].x)
		{
				printf("y ke %d lebih besar dari x, nilai y tersebut : %d\n", i, ikatan_titik[i].y);
		}
	}

	
	return 0;
}