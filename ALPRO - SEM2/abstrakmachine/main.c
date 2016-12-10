#include <stdio.h>
#include "ccmachine.h"

int main()
{
	char pita[50];
	scanf("%[^\n]s", pita);

	START(pita);
	printf("%c\n", GETCC());

	while(EOP()!=0){
		//INC(pita);
		ADV(pita);
		printf("%c\n", GETCC());
		//sebaiknya titik(EOP) tidak di print
	}
	return 0;
}