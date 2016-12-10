#include <stdio.h>
#include <string.h>

int compare(int n, int in[n]){
	int i;
	int min1, min2;

	min1=in[0];
	for (i = 1; i < n/2; i+=1)
	{
		if (min1>in[i])
		{
			min1=in[i];
		}
	}
	min2=in[n/2];
	for (i = n/2+1; i < n; i+=1)
	{
		if (min2>in[i])
		{
			min2=in[i];
		}
	}
	int out;
	if (min1>min2)
	{
		out=min1;
	}else if(min1<min2){
		out=min2;
	}

	return out;
}

void printstring(int m, char in[m][50], int x){
	int i;
	printf("%d\n", x);
	for (i = 0; i < m; i+=1)
	{
		if ((i+1)%x==0)
		{
			printf("%s\n", in[i]);
		}
	}
}

int main()
{
	int i;
	int n, m;
	scanf("%d", &n);
	int arrint[n];
	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &arrint[i]);
	}
	scanf("%d", &m);
	char arrofstr[m][50];
	for (i = 0; i < m; i+=1)
	{
		scanf("%s", &arrofstr[i]);	
	}
	int result=compare(n, arrint);
	printstring(m, arrofstr, result);
	return 0;
}