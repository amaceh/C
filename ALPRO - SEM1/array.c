#include <stdio.h>
/*
int main()
{
	int tabint[5];
	int counter;

	for (counter = 0; counter < 5; counter+=1)
	{
		tabint[counter] = counter;
	}
	for (counter = 0; counter < 5; counter+=1)
	{
		printf("%d \n", tabint[counter]
			);
	}
	return 0;
}
*/
/*
int main()
{
	int n;
	scanf("%d", &n);
	int tabint[n];
	int counter;
	
	for (counter = 0; counter < n; counter+=1)
	{
		tabint[counter] = counter;
		printf("%d \n", tabint[counter]);
	}
	return 0;
}
*/
/*
int main()
{
	int n;
	scanf("%d", &n);
	int tabint[n];
	int counter;

	
	for (counter = 0; counter < n; counter+=1)
	{
		scanf("%d", &tabint[counter]);
		if (tabint[counter] %2 ==1)
		{
			printf("%d\n", tabint[counter]);
		}
	}


	return 0;
}
*/

int main()
{
	int n;
	scanf("%d", &n);
	int tabint[n];
	int counter;

	
	for (counter = 0; counter < n; counter+=1)
	{
		scanf("%d", &tabint[counter]);
	}
	for (counter = 0; counter < (n/2); counter+=1)
	{
		printf("%d\n", tabint[counter]);
	}

	return 0;
}