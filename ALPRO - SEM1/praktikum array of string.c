#include "stdio.h"
#include "string.h"

int main()
{
	int n, i, j, ketemu, total;
	scanf("%d", &n);

	char arrstr[n][50];

	for (i = 0; i < n; ++i)
	{
		scanf("%s", &arrstr[i]);
	}

	total=0;

	for (i = 0; i < n; ++i)
	{
		j=0;
		ketemu=0;
		while(j<strlen(arrstr[i]) && ketemu==0){
			if ((arrstr[i][j]=='1') || (arrstr[i][j]=='2')
				|| (arrstr[i][j]=='3') || (arrstr[i][j]=='4')
				|| (arrstr[i][j]=='5') || (arrstr[i][j]=='6')
				|| (arrstr[i][j]=='7') || (arrstr[i][j]=='8')
				|| (arrstr[i][j]=='9') || (arrstr[i][j]=='0')){
				ketemu==1;
			}else{
				j+=1;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}