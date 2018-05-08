#include <stdio.h>

int main()
{
	int tabInt[5]={34, 67, 23, 28, 98};
	int i, temp, swap;

	do{
		swap=0;

		for (i = 0; i < 5-1; i+=1)
		{
			if (tabInt[i]>tabInt[i+1])
			{
				temp=tabInt[i];
				tabInt[i]=tabInt[i+1];
				tabInt[i+1]=temp;
				swap=1;
			}
		}
	}while (swap==1);
	for (i = 0; i < 5; i+=1)
	{
		printf("%d, ", tabInt[i]);
	}
	return 0;
}