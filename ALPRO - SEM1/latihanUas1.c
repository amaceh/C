#include <stdio.h>
#include <string.h>

void ptrn(int n, char str[n][50]){
	int i, j, k, l;
	int ptrncount[n];
	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < strlen(str[i]); j+=1)
		{
			if (str[i][j]=='0')
			{
				ptrncount[i]=0;
			}else if (str[i][j]=='1')
			{
				ptrncount[i]=1;
			}else if (str[i][j]=='2')
			{
				ptrncount[i]=2;
			}else if (str[i][j]=='3')
			{
				ptrncount[i]=3;
			}else if (str[i][j]=='4')
			{
				ptrncount[i]=4;
			}else if (str[i][j]=='5')
			{
				ptrncount[i]=5;
			}else if (str[i][j]=='6')
			{
				ptrncount[i]=6;
			}else if (str[i][j]=='7')
			{
				ptrncount[i]=7;
			}else if (str[i][j]=='8')
			{
				ptrncount[i]=8;
			}else if (str[i][j]=='9')
			{
				ptrncount[i]=9;
			}
		}
	}
	int space1=0, space2=0;
	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < ptrncount[i]; j+=2)
		{
			for (l = 0; l < space2; l+=1)
			{
				printf(" ");
			}
			printf("%s\n", str[i]);
			space1+=strlen(str[i]);
			if (ptrncount[i]%2!=1 || j<ptrncount[i]-2)
			{
			for (k = 0; k < space1; k+=1)
			{
				printf(" ");
			}
			for (l = 0; l < space2; l+=1)
			{
				printf(" ");
			}
			printf("%s\n", str[i]);
			space2+=1;
			}
			space1=0;
		}
		space2=0;
	}

}


int main()
{
	int n;
	int i;
	scanf("%d", &n);
	char input[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", input[i]);
	}

ptrn(n, input);
	return 0;
}