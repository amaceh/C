#include <stdio.h>
#include <string.h>

int main(){
	
	int in;
	int i, j;
	scanf("%d", &in);
	char alay[in][100];
	for (i = 0; i < in; ++i)
	{
		scanf("%s", alay[i]);
	}
	int arr[100];
	for (i = 0; i < in; ++i)
	{
		arr[i]=0;
		for (j = 0; j < strlen(alay[i]); ++j)
		{
			if (alay[i][j]=='1')
			{
				arr[i]+=1;
			}else if (alay[i][j]=='2')
			{
				arr[i]+=2;
			}else if (alay[i][j]=='3')
			{
				arr[i]+=3;
			}else if (alay[i][j]=='4')
			{
				arr[i]+=4;
			}else if (alay[i][j]=='4')
			{
				arr[i]+=5;
			}else if (alay[i][j]=='6')
			{
				arr[i]+=6;
			}else if (alay[i][j]=='7')
			{
				arr[i]+=7;
			}else if (alay[i][j]=='8')
			{
				arr[i]+=8;
			}else if (alay[i][j]=='9')
			{
				arr[i]+=9;
			}
		}
	}
	
	int primacount=0;
	for (i = 0; i < in; ++i)
	{
		if (arr[i]==2 || arr[i]==3 || arr[i]==5 
			|| arr[i]==7 || arr[i]==11 
			|| arr[i]==13 || arr[i]==17)
		{
			primacount+=1;
		}
	}

	if (primacount>=2)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}