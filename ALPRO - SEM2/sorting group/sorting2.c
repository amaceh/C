#include <stdio.h>

typedef struct
{
	int penyebut;
	int pembilang;
}pecahan;

void insertionsort(int tabint[5]){
	int i, data_sisip, j;

	for (i = 0; i < 5; i+=1)
	{
		data_sisip = tabint[i];
		j=i-1;
		while((data_sisip>tabint[j]) && (j>=0)){
			tabint[j+1]=tabint[j];
			j=j-1;
		}
		tabint[j+1]=data_sisip;
	}
}

int main()
{
	pecahan tabint[5];
	tabint[5].pembilang={2, 7, 9, 1, 2};
	tabint[5].penyebut={3, 7, 3, 9, 7};
	int i;

	insertionsort(tabint.pembilang);
	insertionsort(tabint.penyebut);
	for (i = 0; i < 10; i+=1)
	{
		printf("%d ", tabint[i].pembilang);
	}
	printf("\n");
	for (i = 0; i < 10; i+=1)
	{
		printf("%d ", tabint[i].penyebut);
	}
	return 0;
}	