#include <stdio.h>
#include <string.h>

int horisearch(int n ,char in[n][100], char what[100]){
	int i, j, idx=0;
	int counter=0, result=0;

	for (i = 0; i < n; i+=1)
	{
		for (j = 0; j < strlen(in[i]); j+=1)
		{
			if (in[i][j]==what[idx])
			{
				counter+=1;
			}
			idx+=1;
			if (counter==strlen(what))
			{
				result+=1;
			}
		}
		counter=0;
		idx=0;
	}
	return result;
}
int vertisearch(int n ,char in[n][100], char what[100]){
	int i, j, idx=0;
	int counter=0, result=0;
	int maxlen=strlen(in[0]);
	for (i = 1; i < n; i+=1)
	{
		if (maxlen<strlen(in[i]))
		{
			maxlen=strlen(in[i]);
		}
	}

	for (i = 0; i < maxlen; i+=1)
	{
		for (j = 0; j < n; j+=1)
		{
			if (in[j][i]==what[idx])
			{
				counter+=1;
			}
			idx+=1;
			if (counter==strlen(what))
			{
				result+=1;
			}
		}
		counter=0;
		idx=0;
	}
	return result;
}


int main()
{
	int n, m;
	int i;
	scanf("%d", &n);
	char randomword[n][100];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &randomword[i]);
	}
	char whatword[100];
	scanf("%d", &m);
	
	int totalword=vertisearch(n, randomword, whatword)+
					horisearch(n,randomword,whatword);
	if (totalword==m)
	{
		printf("Semangat TMD!!!\n");
	}else{
		printf("Jangan ditunda-tunda TMDnya!!!\n");
	}
	printf("%d\n", totalword);

	return 0;
}

10
Hefeuigehs
aeAdoejriw
asEojjpene
dsDeonenfl
weojpenefe
owhefbdsls
feinwpeqnc
sdifhenwsd
eojfemsdpe
efowneklsd
jpen
3