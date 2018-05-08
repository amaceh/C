#include <stdio.h>

int main(){
	int n ,m , i, j, tot1=0, tot2=0;
	scanf("%d", &n);
	int arraysatu[n];

	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &arraysatu[i]);
	}
	scanf("%d", &m);
	int arraydua[m];

	for (j = 0; j < m; j+=1)
	{
		scanf("%d", &arraydua[j]);
	}

	for (i = 0; i < n/2; i+=1)
	{
		tot1=tot1 + arraysatu[i];
		}
	for (j = m/2; j < m; j+=1)
	{
		tot2=tot2 + arraydua[j];
		}

	if (tot1 == tot2)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}


	return 0;
}