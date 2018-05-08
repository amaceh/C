#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char info;
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	char info;
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul *first;
}graph;

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

void addJalur(simpul *tujuan, int beban, simpul *awal){
	jalur *arc;
	arc=(jalur *) malloc(sizeof(jalur));
	arc->info=beban;
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
			printf("jalur tidak ada\n");
		}
	}else{
		printf("jalur tidak ada\n");
	}
}

void printGraph(graph G){
	simpul *node=G.first;
	jalur *arc;
	if (node!=NULL){
		while(node!=NULL){
			printf("simpul : %c\n", node->info);
			arc=node->arc;
			while(arc!=NULL){
				printf("\t- jalur %c, dengan beban %d\n", arc->node->info, arc->info);
				arc=arc->next;
			}
			node=node->next;
		}
	}else{
		printf("graph kosong\n");
	}
}