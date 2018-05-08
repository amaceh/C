#include <stdio.h>

int main(){
	int n ,m , i, j, k, x, y, valid=0;
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
	int arrayx[n];
	for (i = 0; i < n; i+=1)
	{
		if (arraysatu[i]%2==0 && arraysatu[i]!=0)
		{
			arrayx[i]=1;
		}else{
			arrayx[i]=0;
		}
	}
	int arrayy[m];
	for (j = 0; j < m; j+=1)
	{
		if (arraydua[j]%2==0  && arraydua[j]!=0)
		{
			arrayy[j]=1;
		}else{
			arrayy[j]=0;
		}
	}

	for (k = 0; k < n ; k+=1)
	{
		if(arrayx[k]==arrayy[k]){
			valid=valid+1;
		}
	}

	
	if (valid==n && n==m)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
return 0;
}