#include <stdio.h>
#include <string.h>

int main()
{
	char putar[100], temp;
	scanf("%[^\n]s", &putar);
	int i, k, len=strlen(putar)+1;
	putar[len-1]=' ';
	putar[len]='\0';
	for (k = 0; k < len; )
	{
		printf("%s\n", putar);
		temp=putar[len-1];
		for (i = len; i > 0; i-=1)
		{
			putar[i]=putar[i-1];
		}
		putar[len]='\0';
		putar[0]=temp;
	}
	return 0;
}