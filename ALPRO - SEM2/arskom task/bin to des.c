#include <stdio.h>

int bintodes(int n, char x[11]){
	int i, res=0, bin=1;
	for (i = n-1; i >= 0 ; i-=1)
	{
		if (x[i]=='1')
		{
			res+=bin;
		}
		bin*=2;
	}
	return res;
}


int main()
{
	printf("convert bin to des\nmau berapa digit?");
	int n; scanf("%d", &n);
	char bin[n];
	scanf("%s", &bin);
	printf("%d\n", bintodes(n, bin));
	return 0;
}	