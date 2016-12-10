#include "vocprint.h"

int main()
{
	int n;
	scanf("%d", &n);
	char input[n][50];
	int i;
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &input[i]);
	}

	int hasil=voccount(n, input);
	strprint(n, input, hasil);
	return 0;
}