#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[50];
}datanam;

typedef struct{
	int first, last;
	datanam data[9];
}queue;

void createEmpty(queue *Q){
	(*Q).first=-1;
	(*Q).last=-1;
}

int isEmpty(queue Q){
	if (Q.first==-1)
	{
		return 1;
	}else{
		return 0;
	}
}

int isFull(queue Q){
	if (Q.last==8)
	{
		return 1;
	}else{
		return 0;
	}
}

void add(char nama[], queue *Q){
	if (isEmpty(*Q)==1)
	{
		//jika queue kosong
		(*Q).first=0;
		(*Q).last=0;
		strcpy((*Q).data[0].nama, nama);
	}else{
		//jika tidak kosong
		if (isFull(*Q)!=1)
		{
			(*Q).last +=1;
			strcpy((*Q).data[(*Q).last].nama, nama);
		}else{
			printf("Queue Penuh!\n");
		}
	}
}

void del(queue *Q){
	if ((*Q).last==0)
	{
		(*Q).first=-1;
		(*Q).last=-1;
	}else{
		int i;
		for (i = (*Q).first+1; i <=0 ; i+=1)
		{
			strcpy((*Q).data[i-1].nama, (*Q).data[i].nama);
		}
		(*Q).last -=1;
	}
}

void printQueue(queue Q){
	if (Q.first != -1)
	{
		int i;
		for (i = Q.last; i >= Q.first; i-=1)
		{
			printf("%s\n", Q.data[i].nama);
		}
	}else{
		printf("Queue Kosong!\n");
	}
	printf("======\n");

}

void addPriority(char nama[], int prior, queue *Q){
	if ((*Q).first!=-1)
	{
		int i=(*Q).last, stop=0;
		while(i >= (*Q).first && stop==0){
			if ((*Q).first<prior)
			{
				add(nama, Q);
				stop=1;		
			}else{
				stop=1;
				(*Q).last+=1;
				for (i = (*Q).last; i <= prior; i-=1)
				{
					(*Q).data[i]=(*Q).data[i-1];	
				}
				strcpy((*Q).data[i].nama,nama);
			}
		i-=1;
		}
		
	}else{//jika kosong langsung saja tambahkan
		add(nama, Q);
	}
}