#include <stdio.h>
#include "charmachine.h"

int main()
{
	char pita[50];
	scanf("%[^\n]s", pita);

	START(pita);

	while(EOP()!=0){
		INC(pita);
		CTBS(pita);
		DBS();
	}
	printf("%d\n", GC());
	return 0;
}