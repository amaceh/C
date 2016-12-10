#include <stdio.h>
#include <math.h>
#include <string.h>

void destobiner(int x, char str[11]){
	strcpy(str, "0000000000");
	int i, bin=pow(2,9);
	for (i = 0; i < 10; i+=1)
	{
		if (x>=bin)
		{
			x-=bin;
			str[i]='1';
		}
		bin=bin/2;
	}
}


int main()
{
	char binary[11];//maks 10 digit ~ 1023 in decimal
	int decimal;
	printf("masukkan angka desimal (maxs 1023) : ");
	scanf("%d", &decimal);
	destobiner(decimal, binary);
	printf("%s\n", binary);
	return 0;
}	