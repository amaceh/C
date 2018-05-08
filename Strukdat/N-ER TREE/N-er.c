#include "head.h"

int main(int argc, char const *argv[]){
	tree T;
	makeTree('A', &T);
	addChild('B', T.root);
	addChild('C', T.root);
	addChild('D', T.root);

	simpul *node=findsimpul('B', T.root);
	if(node!=NULL){
		addChild('E', T.root);
		addChild('F', T.root);
	}

	node=findsimpul('C', T.root);
	if(node!=NULL){
		addChild('G', T.root);
	}
	

	node=findsimpul('D', T.root);
	if(node!=NULL){
		addChild('H', T.root);
		addChild('I', T.root);
		addChild('J', T.root);
	}

	node=findsimpul('J', T.root);
	if(node!=NULL){
		addChild('K', T.root);
		addChild('L', T.root);
		addChild('M', T.root);
	}

	printf("================================\n");
	printf("PreOrder\n");
	printTreePreOrder(T.root);
	printf("\n================================\n");
	printf("PostOrder\n");
	printTreePostOrder(T.root);
	printf("\n==============================\n");

	tree T2;

	copyTree(T.root, &T2.root);

	if(isEqual(T.root, T2.root)==1){
		printf("pohon sama\n");
	}else{
		printf("pohon tidak sama\n");
	}
	printf("========\n");
	printTreePreOrder(T2.root);
	printf("\n");
	printf("========\n");
	
	node=findsimpul('J', T.root);
	if(node!=NULL){
		delChild('K', node);
		delChild('L', node);
		delChild('M', node);
	}

	printf("=============================\n");
	printf("PreOrder setelah dihapus\n");
	printTreePreOrder(T.root);
	printf("\n=============================\n");


	return 0;
}