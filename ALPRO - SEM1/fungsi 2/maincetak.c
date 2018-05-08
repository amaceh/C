#include "cetaksemangat.h"

int main()
{
	int x, i;
	scanf("%d", &x);
	int arr[x];
	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &arr[i]);
	}

	cetakN((nilaiMinimal(x,arr)*nilaiMaksimal(x,arr)));
	return 0;
}	


