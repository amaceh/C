#include "head.h"

int main()
{
	// int hasil;
	// char str[50];
	// scanf("%s", str);

	// hasil=jumlahA(str);
	// printf("%d\n", hasil);

	// scanf("%s", &str);
	// printf("%d\n", jumlahA(str));

	// int x, y;
	// scanf("%d %d", &x, &y);
	// printf("%d\n", tambah(x,y));

	int x, i;
	scanf("%d", &x);
	int arr[x];

	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &arr[i]);
	}
	printf("%d\n", sum(x, arr));
	return 0;
}