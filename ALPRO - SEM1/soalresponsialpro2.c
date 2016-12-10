#include <stdio.h>

int maxfinder(int x, int in[x]){
	int i, out;
	int max=in[0];
	for (i = 1; i < x; i+=1)
	{
		if (max<in[i])
		{
			max=in[i];
		}
	}
	if (max%2==0)
	{
		out=0;//genap saya nyatakan nol
	}else{
		out=1;//ganjil saya nyatakan 1
	}
	return out;
}

int main()
{
	int n, m, i;
	scanf("%d", &n);
	int grp1[n];
	for (i = 0; i < n; i+=1)
	{
		scanf("%d", &grp1[i]);
	}
	scanf("%d", &m);
	int grp2[m];
	for (i = 0; i < m; i+=1)
	{
		scanf("%d", &grp2[i]);
	}
	int g1=maxfinder(n, grp1);
	int g2=maxfinder(m, grp2);

	if (g1==g2)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}