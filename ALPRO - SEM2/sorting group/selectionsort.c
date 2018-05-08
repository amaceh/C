#include <stdio.h>

int main()
{
	int tabint[10]={34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
	int i, miniidx, j, temp;

	for (i = 0; i < (10-1); i+=1)
	{
		miniidx=i;
		for (j = i+1; j < 10; j+=1)
		{
			if (tabint[miniidx]>tabint[j])
			{
				miniidx=j;
			}
		}

		temp=tabint[i];
		tabint[i]=tabint[miniidx];
		tabint[miniidx]=temp;
	}

	for (i = 0; i < 10; i+=1)
	{
		printf("%d ", tabint[i]);
	}
	return 0;
}	