#include "x.1.h"

int main()
{
	char sortby[50];
	scanf("%s", &sortby);
	int n, m, p, i;
	scanf("%d", &n);
	tab1 a[n];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", a[i].str);
	}
	scanf("%d", &m);
	tab2 b[m];
	for (i = 0; i < m; i+=1)
	{
		scanf("%s", b[i].str);
	}
	scanf("%d", &p);
	tab3 c[p];
	for (i = 0; i < p; i+=1)
	{
		scanf("%s", c[i].str);
	}
	consocounter1(n, a);
	consocounter2(m, b);
	consocounter3(p, c);
	
	
	return 0;
}