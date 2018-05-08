#include "header.h"

void CreateEmpty(stack *S)
{
	(*S).top = NULL;
}

int IsEmpty(stack S)
{
	int hasil = 0;
	if(S.top == NULL)
	{
		hasil = 1;
	}
	return hasil;
}

int CountElement(stack S)
{
	int hasil = 0;
	if(S.top != NULL)
	{
		elemen *elmt;

		elmt = S.top;

		while(elmt != NULL)
		{
			hasil = hasil + 1;
			elmt = elmt->next;
		}
	}
	return hasil;
}

void push(char nama[], stack *S)
{
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nama, nama);

	elmt->next = (*S).top;
	(*S).top = elmt;
	elmt = NULL;
}



																																																																																																	88888888888888void pop(stack *S)
{
	if((*S).top != NULL)
	{
		elemen *elmt = (*S).top;
		(*S).top = (*S).top->next;
		elmt->next = NULL;
		free(elmt);
	}
}

void spop(stack *S1, stack *S2){
	if((*S1).top != NULL)
	{
		elemen *elmt = (*S1).top;
		(*S1).top = (*S1).top->next;
		elmt->next = NULL;
		push(elmt->elmt.nama, S2);
	}
	
}



void printstack(stack S)
{
	if(S.top != NULL)
	{
		elemen *elmt = S.top;
		int i = 1;
		while(elmt != NULL)
		{
			printf(" %s", elmt->elmt.nama);
			elmt = elmt->next;
			i = i+1;
		}
		printf("\n");
	}
	else
	{
		printf(" Stack Kosong\n");
	}
}