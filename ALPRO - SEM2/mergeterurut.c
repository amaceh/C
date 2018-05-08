#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, y;
	printf("masukkin jumlah tabel pertama: ");
	scanf("%d", &x);
	printf("masukkin jumlah tabel kedua: ");
	scanf("%d", &y);
	int tab1[x], tab2[y], tab3[x+y];
	int i, j, k;
	int counter;

	printf("tabel pertamax\n");
	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &tab1[i]);
	}
	printf("tabel keduax\n");
	for (i = 0; i < y; i+=1)
	{
		scanf("%d", &tab2[i]);
	}

	i=0; j=0; k=0;

	while(i<x && j<y){
		if (tab1[i]<tab2[j])
		{
			tab3[k]=tab1[i];
			i+=1; k+=1;
		}else if (tab2[j]<tab1[i])
		{
			tab3[k]=tab2[j];
			j+=1; k+=1;
		}else{
			tab3[k]=tab1[i];
			i+=1; k+=1;
			tab3[k]=tab2[j];
			j+=1; k+=1;
		}
	}

	if (i<x)
	{
		for (counter = i; counter < x; counter+=1)
		{
			tab3[k]=tab1[counter];
			k+=1;
		}
	}

	if (j<y)
	{
		for (counter = j; counter < y; counter+=1)
		{
			tab3[k]=tab2[counter];
			k+=1;
		}
	}
	return 0;
}