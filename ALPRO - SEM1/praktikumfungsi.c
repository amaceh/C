#include <stdio.h>
#include <string.h>

int cocokkan(int a, char in1[a][50], int b, char in2[b][50]){
	int i, j, counter=0;
	for (i = 0; i < a; i+=1)
	{
		for (j = 0; j < b; j+=1)
		{
			if (strcmp(in1[i],in2[j])==0)
			{
				counter+=1;
			}
		}
	}
	return counter;
}

int main()
{
	int a, b, i;
	scanf("%d", &a);
	char acaramoni[a][50];
	for (i = 0; i < a; i+=1)
	{
		scanf("%s", acaramoni[i]);
	}
	scanf("%d", &b);
	char toprating[b][50];
	for (i = 0; i < b; i+=1)
	{
		scanf("%s", toprating[i]);
	}

	int validasi=cocokkan(a, acaramoni, b, toprating);
	if (validasi==a)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}	