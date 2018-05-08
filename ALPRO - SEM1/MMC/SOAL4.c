#include <stdio.h>
#include <string.h>

int main()
{
	int in, i;
	scanf("%d", &in);
	char input1[in][50], input2[in][50];

	for (i = 0; i < in; ++i)
	{
		scanf("%s %s", input1[i], input2[i]);
	}

	int yeah, idx=0;
	scanf("%d", &yeah);
	char pass[100][50];
	for (i = 0; i < in; ++i)
	{
		if (strcmp(input2[i], "it")==0)
		{
			strcpy(pass[idx], input1[i]);
			idx+=1;
		}
	}

	printf("%s\n", pass[yeah-1]);
	return 0;
}	