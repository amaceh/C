#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nim[10], nama[50];
	float nilai;
}nilaiMatkul;

typedef struct elm *alamatelmt;
typedef struct elm{
	nilaiMatkul elmt;
	alamatelmt next;
}elemen;

typedef struct
{
	elemen *first;
	elemen *last;
}queue;

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

void add(char nim[], char nama[], float nilai, queue *Q){
	elemen *elmt;
	elmt=(elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nim, nim);
	strcpy(elmt->elmt.nama, nama);
	elmt->elmt.nilai = nilai;
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
		printf("------------\n");
		elemen *elmt = Q.first;

		int i=1;
		while(elmt!=NULL){
			printf("============\n");
			printf("elemen ke : %d\n", i);
			printf("nim : %s\n", elmt->elmt.nim);
			printf("nama : %s\n", elmt->elmt.nama);
			printf("nilai : %f\n", elmt->elmt.nilai);

			elmt=elmt->next;
			i+=1;
		}
		printf("-----------\n");
	}else{
		printf("queue kosong\n");
	}
}