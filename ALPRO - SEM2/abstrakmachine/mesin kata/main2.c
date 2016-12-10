#include <stdio.h>
#include "wmachine.h"

int main()
{
	char pita[512];
	int jkata=0;
	printf("masukkan kalimat pada kata\n");
	scanf("%[^\n]s", &pita);
	STARTKATA(pita);
	while(EOPKATA(pita)==0){
		jkata+=1;
		INCKATA(pita);
	}

	if (GETPANJANGKATA()>0)
	{
		jkata+=1;
	}
	printf("%d\n", jkata);
	return 0;
}	