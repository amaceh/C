#include "header.h"

void CreateEmpty(stack *S)
{
	(*S).top = -1;
}

int IsEmpty(stack S)
{
	int hasil = 0;
	if(S.top == -1)
	{
		hasil = 1;
	}
	return hasil;
}

int IsFull(stack S)
{
	int hasil = 0;
	if(S.top == 9)
	{
		hasil = 1;
	}
	return hasil;
}

void push(char nama[], stack *S)
{
	if(IsFull(*S) == 1)
	{
		printf("stack penuh\n");
	}
	else
	{
		if(IsEmpty(*S) == 1)
		{
			(*S).top = 0;

			strcpy((*S).data[0].nama, nama);
		}
		else
		{
			(*S).top = (*S).top + 1;

			strcpy((*S).data[(*S).top].nama, nama);
		}
	}
}

void pop(stack *S)
{
	if((*S).top == 0)
	{
		(*S).top = -1;
	}
	else
	{
		if((*S).top != -1)
		{
			(*S).top = (*S).top - 1;
		}
	}
}

void spop(stack *S1, stack *S2){
	push((*S1).data[(*S1).top].nama, S2);
	pop(S1);
	
}



void printstack(stack S)
{
	if(S.top != -1)
	{
		int i = 1;
		for(i=S.top; i>=0; i--)
		{
			printf(" %s", S.data[i].nama);
		}
		printf("\n");
	}
	else
	{
		printf(" Stack Kosong\n");
	}
}