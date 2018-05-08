#include <stdio.h>
#include <string.h>

void bintooct(char str[11], char str2[5]){
	int i, j=3;
	int counter[5];
	for (i = 9; i >= 0; i-=3)
	{
		counter[j]=0;
		if (str[i]=='1')
		{
			counter[j]+=1;
		}
		if (str[i-1]=='1')
		{
			counter[j]+=2;
		}
		if (str[i-2]=='1')
		{
			counter[j]+=4;
		}
		j-=1;
	}
	strcpy(str2, "0000");
	for (i = 4; i >= 0; i-=1)
	{
		if (counter[i]==1)
		{
			str2[i]='1';
		}else if (counter[i]==2)
		{
			str2[i]='2';
		}else if (counter[i]==3)
		{
			str2[i]='3';
		}else if (counter[i]==4)
		{
			str2[i]='4';
		}else if (counter[i]==5)
		{
			str2[i]='5';
		}else if (counter[i]==6)
		{
			str2[i]='6';
		}else if (counter[i]==7)
		{
			str2[i]='7';
		}
	}
}

int main()
{
	printf("binary to octal\n");
	char binary[11];
	char octal[5];
	strcpy(binary, "0101100010");//354 in decimal
	bintooct(binary, octal);
	printf("%s\n", octal);
	return 0;
}