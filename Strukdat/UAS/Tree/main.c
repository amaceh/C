#include "head.h"

int main()
{
	tree T;
	
	int i;
	char in[15];
	for (i = 0; i < 14; ++i)
	{
		scanf(" %c", &in[i]);
	}

	makeTree(in[0],&T);
	addLeft(in[1],&T,T.root);
	addRight(in[2],&T,T.root);
	addLeft(in[3],&T,T.root->left);
	addRight(in[4],&T,T.root->left);
	addRight(in[5],&T,T.root->right);
	addLeft(in[6],&T,T.root->left->left);
	addRight(in[7],&T,T.root->left->left);
	addRight(in[8],&T,T.root->left->right);
	addLeft(in[9],&T,T.root->right->right);
	addRight(in[10],&T,T.root->right->right);
	addLeft(in[11],&T,T.root->left->left->right);
	addRight(in[12],&T,T.root->left->left->right);
	addLeft(in[13],&T,T.root->right->right->left);
	int x=14;
	printf("Pre\n");
	printTreePreOrder(T.root, &x);
	delLeft(T.root->left->left->right);//L Hilang
	x=13;
	printf("\nIn\n");
	printTreeInOrder(T.root, &x);
	delRight(T.root->left->right);//I Terhapus
	printf("\nPost\n");
	x=12;
	printTreePostOrder(T.root, &x);
	printf("\n");
	return 0;
}