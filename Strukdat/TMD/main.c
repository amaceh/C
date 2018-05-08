#include "head.h"

int main()
{
	tree T;
	int x, i; scanf("%d", &x);
	char input[100];

	for (i = 0; i < x; i+=1){
		scanf("%s", input);
		Input(input, &T);
	}

	list L1, L2;
	createList(&L1);
	createList(&L2);	


	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%s", input);
		addLast(input, &L1);
	}
	// int y;
	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%s", input);
		addLast(input, &L2);
	}

	printf("=============\n");
	printf("=============\n");
	printf("=============\n");
	printTreePreOrder(T.root, T.root);
	printf("=============\n");
	printf("=============\n");
	printf("=============\n");
	Tobat(T.root, &L1, &L2);
	printTreePreOrder(T.root, T.root);
	return 0;
}