#include <stdio.h>
#include <string.h>

void bintooct(char str[11], char str2[4]){
	int i, j=2;
	int counter[4];
	for (i = 9; i >= 0; i-=4)
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
		if (str[i-3]=='1')
		{
			counter[j]+=8;
		}
		j-=1;
	}
	strcpy(str2, "000");
	for (i = 2; i >= 0; i-=1)
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
		}else if (counter[i]==8)
		{
			str2[i]='8';
		}
		else if (counter[i]==9)
		{
			str2[i]='9';
		}
		else if (counter[i]==10)
		{
			str2[i]='A';
		}
		else if (counter[i]==11)
		{
			str2[i]='B';
		}
		else if (counter[i]==12)
		{
			str2[i]='C';
		}
		else if (counter[i]==13)
		{
			str2[i]='D';
		}
		else if (counter[i]==14)
		{
			str2[i]='E';
		}
		else if (counter[i]==15)
		{
			str2[i]='F';
		}
	}
}

int main()
{
	printf("binary to hexa\n");
	char binary[11];
	char hexa[4];
	strcpy(binary, "1010011010");//666 in decimal
	bintooct(binary, hexa);
	printf("%s\n", hexa);
	return 0;
}