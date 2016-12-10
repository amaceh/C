#include <stdio.h>
#include <string.h>

//quick sort pivot pinggir
void quicksortpinggir(int x, char str[x][20],int l, int r){
	int i, j;
	i=l; j=r;
	char temp[20];

	do{
		while(strcmp(str[i],str[r])==-1 && (i<=r)){
			i+=1;
		}
		while(strcmp(str[j],str[l])==1 && (i<=j)){
			j-=1;
		}
		if (i<j)
		{
			strcpy(temp,str[i]);
			strcpy(str[i],str[j]);
			strcpy(str[j],temp);
			i=i+1;
			j=j-1;
		}	
	}while(i<j);

	if (l<j)
	{
		quicksortpinggir(x, str,l,j);
	}
	if (i<r)
	{
		quicksortpinggir(x, str,i, r);
	}
}

int main()
{
	int x; scanf("%d", &x);
	char str[x][20];
	int i;
	for (i = 0; i < x; i+=1)
	{
		scanf("%s", &str[i]);
	}
	quicksortpinggir(x, str , 0, x-1);
	for ( i = 0; i < x; i+=1)
	{
		printf("%s\n", str[i]);
	}
	return 0;
}