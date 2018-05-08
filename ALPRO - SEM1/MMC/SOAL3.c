#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	int i, j;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int c0=0, c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0;
	for (i = 0; i < n; ++i)
	{
		if (arr[i]==0)
		{
			c0+=1;
		}else if (arr[i]==1)
		{
			c1+=1;
		}else if (arr[i]==2)
		{
			c2+=1;
		}else if (arr[i]==3)
		{
			c3+=1;
		}else if (arr[i]==4)
		{
			c4+=1;
		}else if (arr[i]==5)
		{
			c5+=1;
		}else if (arr[i]==6)
		{
			c6+=1;
		}else if (arr[i]==7)
		{
			c7+=1;
		}else if (arr[i]==8)
		{
			c8+=1;
		}else if (arr[i]==9)
		{
			c9+=1;
		}
	}
		if (c0!=0)
		{
			printf("0 ");
			for (j = 0; j < c0; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c1!=0)
		{
			printf("1 ");
			for (j = 0; j < c1; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c2!=0)
		{
			printf("2 ");
			for (j = 0; j < c2; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c3!=0)
		{
			printf("3 ");
			for (j = 0; j < c3; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c4!=0)
		{
			printf("4 ");
			for (j = 0; j < c4; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c5!=0)
		{
			printf("5 ");
			for (j = 0; j < c5; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c6!=0)
		{
			printf("6 ");
			for (j = 0; j < c6; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c7!=0)
		{
			printf("7 ");
			for (j = 0; j < c7; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c8!=0)
		{
			printf("8 ");
			for (j = 0; j < c8; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
		if (c9!=0)
		{
			printf("9 ");
			for (j = 0; j < c9; ++j)
			{
				printf("*");
			}
			printf("\n");
		}
	
	return 0;
}	