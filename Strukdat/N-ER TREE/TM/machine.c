#include "head.h"

void makeTree(char c, tree *T){
	simpul *node;
	node = (simpul *) malloc (sizeof(simpul));
	node -> info = c;
	node -> sibling = NULL;
	node -> child = NULL;
	(*T).root=node;
}

void addChild(char c, simpul *root){
	if (root!=NULL)
	{
		//pastikan tidak kosong
		simpul *node;
		node = (simpul *) malloc (sizeof(simpul));
		node->info=c;
		node->child=NULL;
		if (root->child==NULL)
		{
			/* simpul baru itu anak pertama */
			node->sibling= NULL;
			root->child=node;
		}else{
			if (root->child->sibling==NULL)
			{
				//jika anak kedua
				node->sibling=root->child;
				root->child->sibling=node;
			}else{
				//lebih dari 2
				simpul *last = root->child;
				while(last->sibling!=root->child){
					last= last->sibling;
				}

				node->sibling=root->child;
				last->sibling=node;
			}
		}
	}
}

void delChild(char c, simpul *root){
	simpul *node = root->child;

	if (node != NULL){
		/* jika cuma 1 anak */
		if (node->sibling==NULL)
		{
			if (root->child->info==c)
			{
				root->child=NULL;
				if (node->child==NULL)
				{
					free(node);
				}
			}else{
				printf("simpul tidak ada\n");
			}

		}else{
			simpul *prec=NULL;
			//find simpul
			int ketemu=0;
			while((node->sibling != root->child) && 
				ketemu == 0){
				if (node->info==c)
				{
					ketemu = 1;
				}else{
					prec=node;
					node=node->sibling;
				}
			}
			if (ketemu==0 && node->info==c)
			{
				ketemu=1;
			}

			if (ketemu==1){
				simpul *last=root->child;

				//cari yang terakhir
				while(last->sibling != root->child){
					last=last->sibling;
				}
				if (prec == NULL)
				{//jika anak pertama
					if ((node->sibling==last) && (last->sibling== root-> child))
					{//jika 2 anak
						root->child = last;
						last->sibling=NULL;
					}else{
						root->child=node->sibling;
						last->sibling=root->child;
					}
				}else{
					if ((prec==root->child) && (last->sibling==root->child))
					{
						//jika 2 anak
						root->child->sibling=NULL;
					}else{
						prec->sibling=node->sibling;
						node->sibling=NULL;
					}
				}
				
				if (node->child == NULL)
				{
					free(node);
				}
			}else{
				printf("simpul tidak ada\n");
			}
		}
	}
}

simpul* findsimpul(char c, simpul *root){
	simpul *hasil=NULL;
	if (root != NULL)
	{
		if (root->info==c)
		{
			hasil = root;
		}else{
			simpul *node = root->child;
			if (node != NULL)
			{
				if (node->sibling==NULL)
				{
					//jika satu anak
					if (node->info==c)
					{
						hasil=node;
					}else{
						hasil=findsimpul(c, node);
					}
				}else{
					//jika banyak anak
					int ketemu=0;
					while((node->sibling != root->child) && ketemu==0){
						if (node->info==c)
						{
							hasil=node;
							ketemu=1;
						}else{
							hasil=findsimpul(c, node);
							node=node->sibling;
						}
					}
					//proses last
					if (ketemu==0)
					{
						
						if (node->info==c)
						{
							hasil=node;
						}else{
							hasil=findsimpul(c, node);
						}
					}
				}
			}
		}
	}
	return hasil;
}

void printTreePreOrder(simpul *root, int *x){
	if (root!=NULL)
	{
		(*x)-=1;
		if ((*x)>1)
		{
			printf("%c ", root->info);
		}else{
			printf("%c", root->info);
		}
		simpul *node= root->child;

		if (node != NULL)
		{
			if (node->sibling == NULL)
			{//jika satu anak
				printTreePreOrder(node, x);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					printTreePreOrder(node, x);
					node=node->sibling;
				}
				//last proses
				printTreePreOrder(node, x);
			}
		}
	}
}

void printTreePostOrder(simpul *root){
	if (root!=NULL)
	{
		simpul *node= root->child;
		if (node != NULL)
		{
			if (node->sibling == NULL)
			{//jika satu anak
				printTreePostOrder(node);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					printTreePostOrder(node);
					node=node->sibling;
				}
				//last proses
				printTreePostOrder(node);
			}
		}
		printf("%c ", root->info);
	}
}

// void copyTree(simpul *root1, simpul **root2){
// 	if (root1!=NULL)
// 	{
// 		(*root2)=(simpul *) malloc (sizeof(simpul));
// 		(*root2)->info=root1->info;
// 		(*root2)->sibling=NULL;
// 		(*root2)->child=NULL;
		
// 		if (root1->child != NULL)
// 		{
// 			if (root1->child->sibling==NULL)
// 			{//satu anak
// 				copyTree(root1->child, &(*root2)->child);
// 			}else{
// 				simpul *node1=root1->child;
// 				simpul *node2=(*root2)->child;
// 				while(node1->sibling != root1->child){
// 					copyTree(node1, &node2);
// 					node1=node1->sibling;
// 					node2=node2->sibling;
// 				}
// 				copyTree(node1, &node2);
// 			}
// 		}
// 	}
// }


// int isEqual(simpul *root1, simpul *root2){
// 	int hasil=1;
// 	if((root1!=NULL)&&(root2!=NULL)){
// 		if(root1->info!=root2->info){
// 			hasil=0;
// 		}else{
// 			if (root1!=NULL && root2!= NULL)
// 			{
// 				if (root1->child->sibling==NULL)
// 				{
// 					/* jika satu anak */
// 					isEqual(root1->child, root2->child);
// 				}else{
// 					simpul *node1 = root1->child;
// 					simpul *node2 = root2->child;

// 					while(node1->sibling!=root1->child){
// 						if (node1!=NULL && node2!=NULL)
// 						{
// 							hasil=isEqual(node1,node2);
// 							node1=node1->sibling;
// 							node2=node2->sibling;
// 						}else{
// 							hasil=0;
// 							break;
// 						}
// 					}
// 					hasil=isEqual(node1, node2);
// 				}
// 			}
// 		}
// 	}else{
// 		if((root1!=NULL)||(root2!=NULL)){
// 			hasil=0;
// 		}
// 	}
// 	return hasil;
// }