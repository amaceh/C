#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
	char info;
	alamatsimpul right;
	alamatsimpul left;
}simpul;

typedef struct{
	simpul* root;
}tree;

void makeTree(char c, tree *T);
void addRight(char c, tree *T, simpul *root);
void addLeft(char c, tree *T, simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);

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

void printTreePreOrder(simpul *root){
	if (root != NULL){
		printf(" %c ", root->info);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

void printTreeInOrder(simpul *root){
	if (root != NULL)
	{
		printTreeInOrder(root->left);
		printf(" %c ", root->info);
		printTreeInOrder(root->right);	
	}
}

void printTreePostOrder(simpul *root){
	if (root != NULL)
	{
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);	
		printf(" %c ", root->info);
	}
}

void copyTree(simpul *root1, simpul **root2){
	if (root1!=NULL)//pastikan ada yang di copy
	{
		(*root2)=(simpul *) malloc (sizeof (simpul));
		(*root2)->info=root1->info;
		if (root1->left!=NULL){
			copyTree(root1->left, &(*root2)->left);
		}
		if (root1->right!=NULL){
			copyTree(root1->right, &(*root2)->right);
		}
	}
}

int isEqual(simpul *root1, simpul *root2){
	int hasil=1;
	if ((root1!=NULL) && (root2!=NULL)){
		if (root1->info != root2->info){
			hasil=0;
		}else{
			isEqual(root1->left, root2->left);
			isEqual(root1->right, root2->right);
		}
	}else{
		if ((root1 != NULL) || (root2 != NULL)){
			hasil = 0;
		}
	}

	return hasil;
}