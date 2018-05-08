#include "head.h"

void createEmpty(graph *G){
	(*G).first=NULL;
}

void addSimpul(char c[], graph *G){
	simpul *node;
	node=(simpul *) malloc (sizeof(simpul));
	strcpy(node->info,c);
	node->next=NULL;
	node->arc=NULL;

	if ((*G).first==NULL)
	{
		(*G).first=node;	
	}else{
		//tambah di akhir graf
		simpul *last=(*G).first;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=node;
	}
}

void addJalur(simpul *tujuan, int jarak,simpul *awal){
	jalur *arc;
	arc=(jalur *) malloc(sizeof(jalur));
	arc->jarak=jarak;
	arc->next=NULL;
	arc->node=tujuan;

	if (awal->arc==NULL){
		awal->arc=arc;
	}else{
		//tambah di akhir
		jalur *last=awal->arc;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=arc;
	}
}

//oprekit
//jalur kesini
//jalur darisini
//simpulnya juga
void delSimpul(char c[], graph *G){
	simpul *elmt=(*G).first;
	if (elmt!=NULL){
		simpul *prec=NULL;
		//cari yang mau dihapus
		int ketemu=0;
		while(elmt!=NULL && ketemu==0){
			if (elmt->info==c){
				ketemu=1;
			}else{
				prec=elmt;
				elmt=elmt->next;
			}
		}

		if (ketemu==1){
			if (prec==NULL){
				(*G).first=elmt->next;
			}else{
				if (elmt->next==NULL){
					//last
					prec->next=NULL;
				}else{
					prec->next=elmt->next;
					elmt->next=NULL;
				}
			}
			/*
			while(node!=NULL){
			printf("Node %c\n", node->info);
			arc=node->arc;
			while(arc!=NULL){
				printf("Jalur %c ke %c\n",node->info, arc->node->info);
				arc=arc->next;
			}
			node=node->next;
			}
			*/
			simpul *node=(*G).first;
			// jalur *arc;
			while(node!=NULL){
				// while(arc!=NULL){
				// if (arc->node->info==c){
					delJalur(node->info, elmt);
					delJalur(elmt->info, node);
				// }
				// arc=arc->next;
				// }
				node=node->next;
			}
			free(elmt);//beware
		}else{
			printf("simpul tidak ada\n");
		}
	}else{
		printf("simpul tidak ada\n");
	}
}

simpul* findSimpul(char c[], graph G){
	simpul *hasil=NULL;
	simpul *node=G.first;
	int ketemu=0;
	while(node!=NULL && ketemu==0){
		if (strcmp(node->info,c)==0)
		{
			hasil=node;
			ketemu=1;
		}else{
			node=node->next;
		}
	}
	return hasil;
}

void delJalur(char ctujuan[], simpul *awal){
	jalur *arc=awal->arc;
	if (arc!=NULL){
		jalur *prec=NULL;
		//cari yang mau dihapus
		int ketemu=0;
		while(arc!=NULL && ketemu==0){
			if (arc->node->info==ctujuan){
				ketemu=1;
			}else{
				prec=arc;
				arc=arc->next;
			}
		}

		if (ketemu==1){
			if (prec==NULL){
				awal->arc=arc->next;
			}else{
				if (arc->next==NULL){
					//last
					prec->next=NULL;
				}else{
					prec->next=arc->next;
					arc->next=NULL;
				}
			}
			free(arc);//beware
		}else{
			printf("Jalur Tidak Ada\n");
		}
	}else{
		printf("Jalur Tidak Ada\n");
	}
}

void printGraph(graph G){
	simpul *node=G.first;
	jalur *arc;
	if (node!=NULL){
		while(node!=NULL){
			printf("kota %s\n", node->info);
			arc=node->arc;
			while(arc!=NULL){
				printf("Jalur %s ke %s dengan jarak %d\n", node->info, arc->node->info, arc->jarak);
				arc=arc->next;
			}
			node=node->next;
		}
	}else{
		printf("graph kosong\n");
	}
}

////////////////////////////////////////////////
////////////////////////////////////////////////
void createEmptyQ(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;	
}

int isEmpty(queue Q){
	if (Q.first==NULL)
	{
		return 1;
	}else{
		return 0;
	}
}

int countElement(queue Q){
	int hasil=0;
	if (Q.first!=NULL)
	{//tidak kosong
		elemen *elmt;
		elmt=Q.first;
		while(elmt!=NULL){
			hasil+=1;
			elmt=elmt->next;
		}
	}
	return hasil;
}

void add(char A[], char B[], int jarak, queue *Q){
	elemen *elmt;
	elmt=(elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.A, A);
	strcpy(elmt->elmt.B, B);
	elmt->elmt.jarak = jarak;
	elmt->next=NULL;
	if ((*Q).first==NULL)
	{
		(*Q).first=elmt;
	}else{
		(*Q).last->next=elmt;
	}
	(*Q).last=elmt;
	elmt=NULL;

}

void del(queue *Q){
	if((*Q).first != NULL){
		/*jika queue tidak kosong*/
		elemen *elmt= (*Q).first;
		if(countElement(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;	
		}else{
			(*Q).first = (*Q).first->next;
			elmt->next = NULL;
		}
		free(elmt);
	}
}

////////////////////////////////////////////////
///////////////////////////////////////////////
void addAllJlr(queue *Q, graph *G){
	if (countElement(*Q)!=0){
		elemen *elmt = (*Q).first;
		while(elmt!=NULL){
			simpul *awal, *tujuan;
			awal=findSimpul(elmt->elmt.A, *G);
			tujuan=findSimpul(elmt->elmt.B, *G);
			if (awal!=NULL && tujuan!=NULL){
				addJalur(tujuan, elmt->elmt.jarak, awal);
			}
			del(Q);
			elmt = (*Q).first;
		}
	}
}


void printQueue(queue Q){
	if (Q.first!=NULL){
		elemen *elmt = Q.first;
		// int i=1;
		while(elmt!=NULL){
			printf("%d\n", elmt->elmt.jarak);
			elmt=elmt->next;
			// i+=1;
		}
	}
}

// void findTheWay(char A[], char B[], queue *Q, graph G){
// 	simpul *node=G.first;
// 	jalur *arc;
// 	if (node!=NULL){
// 		while(node!=NULL){
// 			// printf("kota %s\n", node->info);
// 			arc=node->arc;
// 			while(arc!=NULL){
// 				// printf("Jalur %s ke %s dengan jarak %d\n", node->info, arc->node->info, arc->jarak);
// 				if (strcmp(node->info, A)==0 && strcmp(arc->node->info, B)==0){
// 					add("", "", arc->jarak, Q);
// 				}
// 				arc=arc->next;
// 			}
// 			node=node->next;
// 		}
// 	}
// }

void findTheWay(char A[], char B[], queue *Q, graph G, int jarak){
	simpul *node=G.first;
	jalur *arc;
	int tanda=0;
	if (node!=NULL){
		while(node!=NULL && tanda==0){
			// printf("kota %s\n", node->info);
			arc=node->arc;
			while(arc!=NULL && tanda==0){
				// printf("Jalur %s ke %s dengan jarak %d\n", node->info, arc->node->info, arc->jarak);
				if (strcmp(node->info, A)==0 && strcmp(arc->node->info, B)==0){
					add("", "", arc->jarak, Q);
					tanda=1;
				}
				arc=arc->next;
			}
			node=node->next;
		}
	}
}