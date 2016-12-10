#include <stdio.h>
#include <string.h>
int vocalcounter(int x, char str[x][50]){
	int i, vocal=0;
	for (i = 0; i < strlen(str[x]); i+=1)
	{
		if (str[x][i]=='a' || str[x][i]=='i'
			|| str[x][i]=='u' || str[x][i]=='e'
			|| str[x][i]=='o')
		{
			vocal+=1;
		}
	}
	return vocal;
}

int consonantcounter(int x, char str[x][50]){
	int i, conso=0;
	for (i = 0; i < strlen(str[x]); i+=1)
	{
		if (str[x][i]!='a' && str[x][i]!='i'
			&& str[x][i]!='u' && str[x][i]!='e'
			&& str[x][i]!='o')
		{
			conso+=1;
		}
	}
	return conso;
}

int main()
{
	int i, n, m=0;
	scanf("%d", &n);
	char input[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", input[i]);
	}

	int vocfirst=vocalcounter(m, input);
	int consfirst=consonantcounter(m, input);
	int voclast=vocalcounter(n-1, input);
	int conslast=consonantcounter(n-1, input);

	if (vocfirst==voclast && consfirst==conslast)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}