#include <stdio.h>
#include <string.h>

void sort(int x, char str[x][100]){
	int miniidx;
	int i, j;
	char temp[100];

	for (i = 0; i < x-1; i+=1)
	{
		miniidx=i;
		for (j = i+1; j < x; j+=1)
		{
			if (strcmp(str[miniidx], str[j])==1){
				miniidx=j;
			}
			/*
			prosedur diatas sama dengan angka_1 < angka_2 DESC
			kalau ASC tinggal dirubah menjadi -1
			saya menggunakan selection sort, insertion? pake komdisi ini juga
			*/
		}
		strcpy(temp, str[i]);
		strcpy(str[i], str[miniidx]);
		strcpy(str[miniidx], temp);
	}
}

int main()
{
	int x;
	printf("mau berapa kata?\n");
	scanf("%d", &x);
	char str[x][100];
	int i;
	for (i = 0; i < x; i+=1)
	{
		scanf("%s", str[i]);
	}

	sort(x, str);
	for (i = 0; i < x; i+=1)
	{
		printf("%s\n", str[i]);
	}

	return 0;
}