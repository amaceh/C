#include <stdio.h>
#include "wmachine.h"

int main()
{
	char pita[512];
	printf("masukkan pada kalimat pita :\n");
	scanf("%[^\n]s", &pita);

	STARTKATA(pita);
	printf("%s\n", GETCKATA());
	
	while(EOPKATA(pita)==0){
		INCKATA(pita);
		printf("%s\n", GETCKATA());
	}
	return 0;
}