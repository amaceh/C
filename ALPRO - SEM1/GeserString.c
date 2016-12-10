#include <stdio.h>
#include <string.h>

int main()
{
	char in[50], temp;
	int swap, i, j;

	scanf("%s", in);
	scanf("%d", &swap);

	int len=strlen(in);

	for (i = 0; i < swap; i+=1)
	{
		temp=in[len];
		for (j = len; j > 0; j-=1){
			in[j+1]=in[j+1];
		}
		in[0]=temp;
	}

	printf("%s\n", in);
	return 0;
}	