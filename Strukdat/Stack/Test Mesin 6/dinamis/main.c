#include "header.h"

int main()
{
	stack S1;
	stack S2;

	char ngaran[5][10];

	CreateEmpty(&S1);
	CreateEmpty(&S2);
	int i;
	for(i=0 ; i<5 ; i++){
		scanf("%s", ngaran[i]);
	}
	printf("S1 -");
	printstack(S1);
	printf("S2 -");
	printstack(S2);
	push(ngaran[0], &S1);
	push(ngaran[1], &S2);
	spop(&S1, &S2);
	printf("S1 -");
	printstack(S1);
	printf("S2 -");
	printstack(S2);
	pop(&S2);
	push(ngaran[2], &S1);
	push(ngaran[3], &S2);
	push(ngaran[4], &S2);
	spop(&S2, &S1);
	printf("S2 -");
	printstack(S2);
	printf("S1 -");
	printstack(S1);
	return 0;
}