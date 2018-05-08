#include "x.1.h"

int main()
{
	char sortby[50];
	scanf("%s", &sortby);
	int n, m, p, i;
	scanf("%d", &n);
	tab a[n];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", a[i].str);
	}
	scanf("%d", &m);
	tab b[m];
	for (i = 0; i < m; i+=1)
	{
		scanf("%s", b[i].str);
	}
	scanf("%d", &p);
	tab c[p];
	for (i = 0; i < p; i+=1)
	{
		scanf("%s", c[i].str);
	}
	consocounter(n, a);
	consocounter(m, b);
	consocounter(p, c);

	if (strcmp(sortby,"bublesort")==0)
	{
		bublesort(n, a);
		bublesort(m, b);
		bublesort(p, c);
	}else if (strcmp(sortby,"insertionsort")==0)
	{
		insertionsort(n, a);
		insertionsort(m, b);
		insertionsort(p, c);
	}else if (strcmp(sortby,"selectionsort")==0)
	{
		selectionsort(n, a);
		selectionsort(m, b);
		selectionsort(p, c);
	}else if (strcmp(sortby,"quicksort")==0)
	{
		quicksortpinggir(n, a, 0, n-1);
		quicksortpinggir(m, b, 0, m-1);
		quicksortpinggir(p, c, 0, p-1);
	}
	tab d[n+m];
	mergetable(n, m, a, b, d);
	tab e[n+m+p];
	mergetable(n+m, p, d, c, e);
	for (i = 0; i < n+m+p; i+=1)
		{
			printf("%s\n", e[i].str);
		}	
	return 0;
}