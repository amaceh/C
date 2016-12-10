#include <stdio.h>

int main()
{
	int tabint[10]={34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
	int i, data_sisip, j;

	for (i = 0; i < 10; i+=1)
	{
		data_sisip = tabint[i];
		j=i-1;
		while((data_sisip>tabint[j]) && (j>=0)){
			tabint[j+1]=tabint[j];
			j=j-1;
		}
		tabint[j+1]=data_sisip;
	}

	for (i = 0; i < 10; i+=1)
	{
		printf("%d ", tabint[i]);
	}
	return 0;
}
