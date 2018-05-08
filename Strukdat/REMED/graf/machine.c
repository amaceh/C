#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan REMEDIAL STRUKDAT,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

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

void addJalur(simpul *tujuan ,simpul *awal){
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
// void delSimpul(char c[], graph *G){
// 	simpul *elmt=(*G).first;
// 	if (elmt!=NULL){
// 		simpul *prec=NULL;
// 		//cari yang mau dihapus
// 		int ketemu=0;
// 		while(elmt!=NULL && ketemu==0){
// 			if (elmt->info==c){
// 				ketemu=1;
// 			}else{
// 				prec=elmt;
// 				elmt=elmt->next;
// 			}
// 		}

// 		if (ketemu==1){
// 			if (prec==NULL){
// 				(*G).first=elmt->next;
// 			}else{
// 				if (elmt->next==NULL){
// 					//last
// 					prec->next=NULL;
// 				}else{
// 					prec->next=elmt->next;
// 					elmt->next=NULL;
// 				}
// 			}
			
// 			while(node!=NULL){
// 			printf("Node %c\n", node->info);
// 			arc=node->arc;
// 			while(arc!=NULL){
// 				printf("Jalur %c ke %c\n",node->info, arc->node->info);
// 				arc=arc->next;
// 			}
// 			node=node->next;
// 			}
			
// 			simpul *node=(*G).first;
// 			// jalur *arc;
// 			while(node!=NULL){
// 				// while(arc!=NULL){
// 				// if (arc->node->info==c){
// 					delJalur(node->info, elmt);
// 					delJalur(elmt->info, node);
// 				// }
// 				// arc=arc->next;
// 				// }
// 				node=node->next;
// 			}
// 			free(elmt);//beware
// 		}else{
// 			printf("simpul tidak ada\n");
// 		}
// 	}else{
// 		printf("simpul tidak ada\n");
// 	}
// }

simpul* findSimpul(char c[], graph G){
	simpul *hasil=NULL;
	simpul *node=G.first;
	int ketemu=0;
	while(node!=NULL && ketemu==0){
		if (strcmp(node->info,c)==0){
			hasil=node;
			ketemu=1;
		}else{
			node=node->next;
		}
	}
	return hasil;
}

// void delJalur(char ctujuan[], simpul *awal){
// 	jalur *arc=awal->arc;
// 	if (arc!=NULL){
// 		jalur *prec=NULL;
// 		//cari yang mau dihapus
// 		int ketemu=0;
// 		while(arc!=NULL && ketemu==0){
// 			if (arc->node->info==ctujuan){
// 				ketemu=1;
// 			}else{
// 				prec=arc;
// 				arc=arc->next;
// 			}
// 		}

// 		if (ketemu==1){
// 			if (prec==NULL){
// 				awal->arc=arc->next;
// 			}else{
// 				if (arc->next==NULL){
// 					//last
// 					prec->next=NULL;
// 				}else{
// 					prec->next=arc->next;
// 					arc->next=NULL;
// 				}
// 			}
// 			free(arc);//beware
// 		}else{
// 			printf("Jalur Tidak Ada\n");
// 		}
// 	}else{
// 		printf("Jalur Tidak Ada\n");
// 	}
// }

// void printGraph(graph G){
// 	simpul *node=G.first;
// 	jalur *arc;
// 	if (node!=NULL){
// 		while(node!=NULL){
// 			printf("kota %s\n", node->info);
// 			arc=node->arc;
			// while(arc!=NULL){
			// 	printf("Jalur %s ke %s\n", node->info, arc->node->info);
			// 	arc=arc->next;
			// }
// 			node=node->next;
// 		}
// 	}else{
// 		printf("graph kosong\n");
// 	}
// }

void addByPath(char x[], char y[], graph *G){
	simpul *begin, *end;
	begin=findSimpul(x, *G);
	if (begin==NULL){
		addSimpul(x, G);
		begin=findSimpul(x, *G);
	}
	end=findSimpul(y, *G);
	if (end==NULL){
		addSimpul(y, G);
		end=findSimpul(y, *G);
	}
	addJalur(end, begin);
}


////////////////////////////////////////////////
////////////////////////////////////////////////
void createEmptyQ(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;	
}

void add(int A, queue *Q){
	elemen *elmt;
	elmt=(elemen *) malloc (sizeof (elemen));
	elmt->elmt.A = A;
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

//prosedur mengecek jejak
void checkPath(char x[], graph G, queue *Q){
	int len=strlen(x);
	int i=0, idx=0, valid=0;
	char tmp1[10], tmp2[10];
	strcpy(tmp1, "-");//default
	while(i < len && valid==0){//cek semua kata
		if (x[i]!='-' && x[i]!='\0'){//ambil satu node
			tmp2[idx]=x[i];
			idx+=1;
		}else{
			tmp2[idx]='\0';
			idx=0;
			// printf("%s %s\n", tmp1, tmp2);
			if (strcmp(tmp1, "-")!=0){
				valid=validation(tmp1, tmp2, G);//lalu cek
			}
			strcpy(tmp1, tmp2);//geser
		}
		i+=1;
	}
	valid=validation(tmp1, tmp2, G);
	if (valid==0){//jika cocok
		add(1, Q);//tambah
	}else{
		add(0, Q);//jika tidak
	}
}
//prosedru cek
int validation(char x[], char y[], graph G){
	int val=1;
	//cari dulu node
	simpul *awal=findSimpul(x, G);
	simpul *end=findSimpul(y, G);
	//periksa jika tidak kosong
	if (awal!=NULL && end!=NULL){
		jalur *arc=awal->arc;
		while(arc!=NULL && val==1){//perikasa semua jalur
			if (arc->node==end){//jika sama
				val=0;//tampilkan hasil
			}
			arc=arc->next;
		}
	}else{
		val=1;
	}
	return val;
}
// int isEmpty(queue Q){
// 	if (Q.first==NULL)
// 	{
// 		return 1;
// 	}else{
// 		return 0;
// 	}
// }

// int countElement(queue Q){
// 	int hasil=0;
// 	if (Q.first!=NULL)
// 	{//tidak kosong
// 		elemen *elmt;
// 		elmt=Q.first;
// 		while(elmt!=NULL){
// 			hasil+=1;
// 			elmt=elmt->next;
// 		}
// 	}
// 	return hasil;
// }



// void del(queue *Q){
// 	if((*Q).first != NULL){
// 		/*jika queue tidak kosong*/
// 		elemen *elmt= (*Q).first;
// 		if(countElement(*Q) == 1){
// 			(*Q).first = NULL;
// 			(*Q).last = NULL;	
// 		}else{
// 			(*Q).first = (*Q).first->next;
// 			elmt->next = NULL;
// 		}
// 		free(elmt);
// 	}
// }

// ////////////////////////////////////////////////
// ///////////////////////////////////////////////
// void addAllJlr(queue *Q, graph *G){
// 	if (countElement(*Q)!=0){
// 		elemen *elmt = (*Q).first;
// 		while(elmt!=NULL){
// 			simpul *awal, *tujuan;
// 			awal=findSimpul(elmt->elmt.A, *G);
// 			tujuan=findSimpul(elmt->elmt.B, *G);
// 			if (awal!=NULL && tujuan!=NULL){
// 				addJalur(tujuan, elmt->elmt.jarak, awal);
// 			}
// 			del(Q);
// 			elmt = (*Q).first;
// 		}
// 	}
// }


void printQueue(queue Q){
	if (Q.first!=NULL){
		elemen *elmt = Q.first;
		// int i=1;
		while(elmt!=NULL){
			// printf("%d\n", elmt->elmt.A);
			if (elmt->elmt.A==1){
				printf("ada\n");
			}else{
				printf("tidak ada\n");
			}
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