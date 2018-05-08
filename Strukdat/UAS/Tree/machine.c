#include "head.h"

void makeTree(char c, tree *T){
	simpul *node;
	node=(simpul *) malloc (sizeof (simpul));
	node->info=c;
	node->right=NULL;
	node->left=NULL;
	(*T).root=node;
}

void addRight(char c, tree *T, simpul *root){
	if (root->right==NULL){//pastikan kosong
		simpul *node;
		node=(simpul *) malloc (sizeof (simpul));
		node->info=c;
		node->right=NULL;
		node->left=NULL;
		root->right=node;
	}else{
		printf("node kanan sudah terisi\n");
	}
}

void addLeft(char c, tree *T, simpul *root){
	if (root->left==NULL){//pastikan kosong
		simpul *node;
		node=(simpul *) malloc (sizeof (simpul));
		node->info=c;
		node->right=NULL;
		node->left=NULL;
		root->left=node;
	}else{
		printf("node kiri sudah terisi\n");
	}
}

void delRight(simpul *root){
	simpul *node=root->right;
	if (node->right==NULL && node->left==NULL){
		root->right=NULL;
		free(node);
	}
}

void delLeft(simpul *root){
	simpul *node=root->left;
	if (node->right==NULL && node->left==NULL){
	root->left=NULL;
	free(node);	
	}
}
//A B C D E F G H I J K L M N

void printTreePreOrder(simpul *root, int *lim){
	if (root != NULL){
		(*lim)-=1;
		printf("%c", root->info);
		if ((*lim)>0){
			printf(" - ");
		}
		printTreePreOrder(root->left, lim);
		printTreePreOrder(root->right, lim);
	}
}

void printTreeInOrder(simpul *root, int *lim){
	if (root != NULL)
	{
		printTreeInOrder(root->left, lim);
		printf("%c", root->info);
		(*lim)-=1;
		if ((*lim)>0){
			printf(" - ");
		}
		printTreeInOrder(root->right, lim);	
	}
}

void printTreePostOrder(simpul *root, int *lim){
	if (root != NULL)
	{
		printTreePostOrder(root->left, lim);
		printTreePostOrder(root->right, lim);	
		printf("%c", root->info);
		(*lim)-=1;
		if ((*lim)>0){
			printf(" - ");
		}
	}
}