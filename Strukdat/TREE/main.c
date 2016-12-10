#include "1.h"

int main()
{
	tree T;
	makeTree('A', &T);
	addLeft('B', &T,T.root);
	addRight('C', &T,T.root);
	addLeft('D', &T,T.root->left);
	addRight('E', &T,T.root->left);
	addRight('F', &T,T.root->right);

	printf("preOrder\n");
	printTreePreOrder(T.root);
	printf("\n");
	printf("inOrder\n");
	printTreeInOrder(T.root);
	printf("\n");
	printf("PostOrder\n");
	printTreePostOrder(T.root);
	printf("\n");
	tree T2;
	copyTree(T.root, &T2.root);
	if (isEqual(T.root, T2.root)==1)
	{
		printf("sama\n");
	}else{
		printf("tidak sama\n");
	}

	// delRight(T.root->left);
	// delLeft(T.root->left);
	printTreePreOrder(T.root);
	printf("\n");
	return 0;
}