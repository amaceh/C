#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	scanf("%s", &str);
	int count=0, i;

	for (i = 0; i < strlen(str); i+=1)
	{
		if(str[i]=='a' || str[i]=='i' || str[i]=='u'
			|| str[i]=='e' || str[i]=='o'){
			count+=1;
		}
	}

	printf("jadi jumlah huruf vokal adalah %d biji\n", count);
	return 0;
}	