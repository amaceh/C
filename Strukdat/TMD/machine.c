#include "head.h"

void createList(list *L){
	(*L).first=NULL;
}

/*menghitung jumlah elemen*/
int countElement(list L){
	int hasil=0;

	if(L.first!=NULL){
		/*list tidak kosong*/
		elemen *elmt;

		/*inisialisasi*/
		elmt=L.first;

		while(elmt!=NULL){
			/*proses*/
			hasil=hasil+1;

			/*iterasi*/
			elmt=elmt->next;
		}
	}
	return hasil;
}

/*menambahkan di awal list*/
void addFirst(char amal[], list *L){
	elemen *baru;
	baru=(elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.amal, amal);

	if((*L).first==NULL){
		baru->next=NULL;
	}else{
		baru->next=(*L).first;
	}
	(*L).first=baru;
	baru=NULL;
}

/*menambahkan di tengah list*/
void addAfter(elemen *prev, char amal[], list *L){
	elemen *baru;
	baru= (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.amal, amal);       

	if(prev->next == NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru= NULL;
}

/*menambahkan di akhir list*/
void addLast(char amal[], list *L){
	if((*L).first == NULL){
		/*jika list adalah list kosong*/
		addFirst(amal, L);
	}else{
		/*jika list tidak kosong*/
		/*mencari elemen terakhir list*/
		elemen *prev= (*L).first;
		while(prev->next != NULL){
			/*iterasi*/
			prev= prev->next;
		}
		addAfter(prev, amal, L);
	}
}

/*menghapuskan elemen pertama*/
void delFirst(list *L){
	if((*L).first != NULL){
		/*jika list bukan list kosong*/
		elemen *hapus= (*L).first;
		if(countElement(*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

/*menghapus elemen tengah*/
void delAfter(elemen *prev, list *L){
	elemen *hapus= prev->next;
	if(hapus!= NULL){
		if(hapus->next == NULL){
			prev->next = NULL; 
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

/*menghapus elemen terakhir*/
void delLast(list *L){
	if((*L).first != NULL){
		/*jika list tidak kosong*/
		if(countElement(*L) == 1){
			/*list terdiri dari satu elemen*/
			delFirst(L);
		}else{
			/*mencari elemen terakhir list*/
			elemen *last = (*L).first;
			elemen *prev;
			while(last->next != NULL){
				/*iterasi*/
				prev= last;
				last = last->next;
			}
			delAfter(prev, L);
		}
	}
}

/*menampilkan isi list*/
void printElement(list L){  
	if(L.first != NULL){
		/*jika list tidak kosong*/
		/*inisialisasi*/
		elemen *elmt = L.first;
		// int i = 1;

		while(elmt != NULL){
		/*proses*/
		printf("%s\n", elmt->elmt.amal);
		/*iterasi*/
		elmt = elmt->next;
		// i = i + 1;
		}
	}
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/



void makeTree(char c[], tree *T){
	simpul *node;
	node = (simpul *) malloc (sizeof(simpul));
	strcpy(node->nama,c);
	node->sibling = NULL;
	node->child = NULL;
	(*T).root=node;
}

void addChild(char c[], simpul *root){
	if (root!=NULL)
	{
		//pastikan tidak kosong
		simpul *node;
		node = (simpul *) malloc (sizeof(simpul));
		strcpy(node->nama,c);
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

void delChild(char c[], simpul *root){
	simpul *node = root->child;

	if (node != NULL){
		/* jika cuma 1 anak */
		if (node->sibling==NULL)
		{
			if (strcmp(root->child->nama,c)==0)
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
				if (strcmp(node->nama,c)==0)
				{
					ketemu = 1;
				}else{
					prec=node;
					node=node->sibling;
				}
			}
			if (ketemu==0 && strcmp(node->nama,c)==0)
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

simpul* findsimpul(char c[], simpul *root){
	simpul *hasil=NULL;
	if (root != NULL)
	{
		if (strcmp(root->nama,c)==0){
			hasil = root;
		}else{
			simpul *node = root->child;
			if (node != NULL){
				if (node->sibling==NULL){
					//jika satu anak
					if (strcmp(node->nama,c)==0)
					{
						hasil=node;
					}else{
						hasil=findsimpul(c, node);
					}
				}else{
					//jika banyak anak
					int ketemu=0;
					while((node->sibling != root->child) && ketemu==0){
						if (strcmp(node->nama,c)==0)
						{
							hasil=node;
							ketemu=1;
						}else{
							hasil=findsimpul(c, node);
							node=node->sibling;
						}
					}
					//proses last
					if (ketemu==0 && hasil==NULL){
						
						if (strcmp(node->nama,c)==0)
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

void printTreePreOrder(simpul *root, simpul *troot){
	if (root!=NULL){
		if (root!=troot){
			printf("|");
		}
		printf("%s\n", root->nama);
		printElement(root->bad);
		printElement(root->good);

		simpul *node= root->child;

		if (node != NULL)
		{
			if (node->sibling == NULL)
			{//jika satu anak
				printTreePreOrder(node, troot);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					printTreePreOrder(node, troot);
					node=node->sibling;
				}
				//last proses
				printTreePreOrder(node, troot);
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
		printf("%s\n", root->nama);
	}
}

void Input(char str[], tree *T){
	int i;
	int len=strlen(str);
	char temp[50], temp2[50], temp3[10];
	int step=1, idx=0, x, y;
	for (i = 0; i < len; i+=1){
		if (step==1)
		{
			temp[idx]=str[i];
			idx+=1;
			if (str[i+1]=='#')
			{
				temp[idx]='\0';
				idx=0;
				step+=1;
				i+=1;
			}
		}else if (step==2){
			temp2[idx]=str[i];
			idx+=1;
			if (str[i+1]=='#')
			{
				temp2[idx]='\0';
				idx=0;
				step+=1;
				i+=1;
			}
		}else if (step==3){
			temp3[idx]=str[i];
			idx+=1;
			if (str[i+1]=='#')
			{
				temp3[idx]='\0';
				x=atoi(temp3);
				idx=0;
				step+=1;
				i+=1;
			}
		}else if (step==4){
			temp3[idx]=str[i];
			idx+=1;
			if (str[i+1]=='\0')
			{
				temp3[idx]='\0';
				y=atoi(temp3);
				// idx=0;
				// step+=1;
				i+=1;
			}
		}
	}
	addbyRoot(temp, temp2, x, y, T);
}

void addbyRoot(char root[], char child[],int x, int y,tree *T){
	char amalan[50];
	int i;
	if (strcmp(root, "null")==0){
		makeTree(child, T);
		createList(&(*T).root->bad);
		for (i = 0; i < x; i+=1){
			scanf("%s", amalan);
			addLast(amalan, &(*T).root->bad);
		}
		createList(&(*T).root->good);
		for (i = 0; i < y; i+=1){
			scanf("%s", amalan);
			addLast(amalan, &(*T).root->good);
		}
	}else{
		simpul *node=findsimpul(root, (*T).root);
		addChild(child, node);
		node=findsimpul(child, node);
		for (i = 0; i < x; i+=1){
			scanf("%s", amalan);
			addLast(amalan, &node->bad);
		}
		createList(&(*T).root->good);
		for (i = 0; i < y; i+=1){
			scanf("%s", amalan);
			addLast(amalan, &node->good);
		}
	}
}

void BadtoGood(list *L, list *L2, list *A, list *B){  
	int stat=0;
	if((*L).first != NULL && (*A).first!=NULL){
		/*jika list tidak kosong*/
		/*inisialisasi*/
		elemen *elmt = (*L).first;
		elemen *elmt2, *prev;
		// int i = 1;

		while(elmt != NULL){
		/*proses*/
		// printf("%s\n", elmt->elmt.amal);
		elmt2 = (*A).first;
			while(elmt2 != NULL){
				if (strcmp(elmt->elmt.amal, elmt2->elmt.amal)==0){
					stat=1;
					if (elmt==(*L).first)
					{
						delFirst(L);
					}else{
						delAfter(prev, L);
					}
				}
				elmt2 = elmt2->next;
			}
		/*iterasi*/
		prev = elmt;
		elmt = elmt->next;
		// i = i + 1;
		}
		if (stat==1 && (*B).first!=NULL){
			elmt2 = (*B).first;			
			// int i = 1;
			while(elmt2 != NULL){
			/*proses*/
			// printf("%s\n", elmt2->elmt2.amal);
				addLast(elmt2->elmt.amal, L2);
			elmt2 = elmt2->next;
			}
		}
	}
}

void Tobat(simpul *root, list *A, list *B){
	if (root!=NULL){
		// printf("%s\n", root->nama);
		BadtoGood(&root->bad, &root->good, A, B);

		simpul *node= root->child;

		if (node != NULL){
			if (node->sibling == NULL){//jika satu anak
				Tobat(node, A, B);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					Tobat(node, A, B);
					node=node->sibling;
				}
				//last proses
				Tobat(node, A, B);
			}
		}
	}
}
