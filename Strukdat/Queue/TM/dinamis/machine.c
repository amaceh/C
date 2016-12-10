#include "head.h"

void createEmpty(queue *Q){
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

void add(char nama[], queue *Q){
	elemen *elmt;
	elmt=(elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nama, nama);
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

void printQueue(queue Q){
	if (Q.first!=NULL)
	{
		elemen *elmt = Q.first;

		int i=1;
		while(elmt!=NULL){
			printf("%s\n", elmt->elmt.nama);

			elmt=elmt->next;
			i+=1;
		}
	}else{
		printf("Queue Kosong!\n");
	}
	printf("======\n");
}

void addPriority(char nama[], int prior, queue *Q){
	if ((*Q).first!=NULL){
		elemen *prev,*elmt = (*Q).first;

		int i=1, stop=0;
		while(elmt!=NULL && stop==0){
			if (countElement(*Q)<prior){
				add(nama, Q);
				stop=1;		
			}else if (i==prior){
				stop=1;
				elemen *baru;
				baru = (elemen *) malloc (sizeof(elemen));
				strcpy(baru->elmt.nama,nama);
				
				if (elmt==(*Q).first)
				{
					baru->next = (*Q).first;
					(*Q).first = baru;
				}else{
					baru->next = prev->next;
					prev->next = baru;
				}
				baru = NULL;	
			}	
		prev=elmt;
		elmt=elmt->next;
		i+=1;
		}
		
	}else{//jika kosong langsung saja tambahkan
		add(nama, Q);
	}
}