#include "head.h"

int main()
{
	tree T;
	makeTree('A', &T);
	addChild('B',T.root);
	delChild('B',T.root);
	addChild('C',T.root);
	addChild('D',T.root);
	addChild('E',T.root->child);
	addChild('F',T.root->child->child);
	addChild('G',T.root->child->child->child);
	addChild('H',T.root);
	int x=8;
	//8
	printTreePreOrder(T.root, &x);
	delChild('H', T.root);
	printf("\n");
	//7
	x=7;
	printTreePreOrder(T.root, &x);
	printf("\n");
	addChild('I',T.root ->child);
	addChild('J',T.root -> child -> child);
	//9
	x=9;
	printTreePreOrder(T.root, &x);
	printf("\n");
	if (findsimpul('C', T.root->child->child))	
	{
		printf("ditemukan C\n");
	}else{
		printf("tidak ditemukan\n");
	}
	if (findsimpul('C', T.root))	
	{
		printf("ditemukan C\n");
	}else{
		printf("tidak ditemukan\n");
	}
	return 0;
}