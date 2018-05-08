#include "head.h"

void createEmpty(graph *G){
	(*G).first=NULL;
}

void addSimpul(char c, graph *G){
	simpul *node;
	node=(simpul *) malloc (sizeof(simpul));
	node->info=c;
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

void addJalur(simpul *tujuan, simpul *awal){
	jalur *arc;
	arc=(jalur *) malloc(sizeof(jalur));
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
void delSimpul(char c, graph *G){
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

simpul* findSimpul(char c, graph G){
	simpul *hasil=NULL;
	simpul *node=G.first;
	int ketemu=0;
	while(node!=NULL && ketemu==0){
		if (node->info==c)
		{
			hasil=node;
			ketemu=1;
		}else{
			node=node->next;
		}
	}
	return hasil;
}

void delJalur(char ctujuan, simpul *awal){
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
			printf("Node %c\n", node->info);
			arc=node->arc;
			while(arc!=NULL){
				printf("Jalur %c ke %c\n",node->info, arc->node->info);
				arc=arc->next;
			}
			node=node->next;
		}
	}else{
		printf("graph kosong\n");
	}
}