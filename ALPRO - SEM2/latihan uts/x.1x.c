#include "x.1.h"

void consocounter(int n, tab a[n]){
	int i, len, j;
	for (i = 0; i < n; i+=1)
	{
		len=strlen(a[i].str);
		a[i].conso =0;
		for (j = 0; j < len; j+=1)
		{
			if (a[i].str[j] !='a' && a[i].str[j] !='i' && a[i].str[j] !='u' &&
				a[i].str[j] !='e' && a[i].str[j] !='o'){
				a[i].conso +=1;
			}
		}
	}
}

void bublesort(int x, tab a[x]){

int i, temp, swap;
char temp2[50];

	do{
		swap=0;

		for (i = 0; i < x-1; i+=1)
		{
			if (a[i].conso>a[i+1].conso)
			{
				temp=a[i].conso;
				a[i].conso=a[i+1].conso;
				a[i+1].conso=temp;
				strcpy(temp2,a[i].str);
				strcpy(a[i].str,a[i+1].str);
				strcpy(a[i+1].str,temp2);
				swap=1;
			}
		}
	}while (swap==1);

}

//insertion sort
void insertionsort(int x, tab a[x]){
	int i, insertion, j;
	char temp[50];

	for (i = 0; i < x; i+=1)
	{
		insertion = a[i].conso;
		strcpy(temp,a[i].str);
		j=i-1;
		while((insertion>a[j].conso) && (j>=0)){
			a[j+1].conso=a[j].conso;
			strcpy(a[j+1].str,a[j].str);
			j=j-1;
		}
		a[j+1].conso=insertion;
		strcpy(a[j+1].str,temp);
	}
}

//selection sort
void selectionsort(int x, tab a[x]){

int i, miniidx, j, temp;
char temp2[50];

	for (i = 0; i < (x-1); i+=1)
	{
		miniidx=i;
		for (j = i+1; j < x; j+=1)
		{
			if (a[miniidx].conso>a[j].conso)
			{
				miniidx=j;
			}
		}

		temp=a[i].conso;
		a[i].conso=a[miniidx].conso;
		a[miniidx].conso=temp;
		strcpy(temp2,a[i].str);
		strcpy(a[i].str,a[miniidx].str);
		strcpy(a[miniidx].str,temp2);
	}
}

//quick sort pivot pinggir
void quicksortpinggir(int x, tab a[x], int l, int r){
	int i, j, temp;
	i=l;
	j=r;
	char temp2[50];

	do{
		while((a[i].conso<a[r].conso) && (i<=r)){
			i=i+1;
		}
		while((a[j].conso>a[l].conso) && (i<=j)){
			j=j-1;
		}
		if (i<j)
		{
			temp=a[i].conso;
			a[i].conso=a[j].conso;
			a[j].conso=temp;
			strcpy(temp2,a[i].str);
			strcpy(a[i].str,a[j].str);
			strcpy(a[j].str,temp2);
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)
	{
		quicksortpinggir(x,a,l,j);
	}
	if (i<r)
	{
		quicksortpinggir(x,a,i,r);
	}
}

void mergetable(int x, int y, tab a[x], tab b[y], tab d[x+y]){

	int i=0, j=0, k=0;
	int counter;
	while(i<x && j<y){
		if (a[i].conso<b[j].conso)
		{
			d[k].conso=a[i].conso;
			strcpy(d[k].str,a[i].str);
			i+=1; k+=1;
		}else if (b[j].conso<a[i].conso)
		{
			d[k].conso=b[j].conso;
			strcpy(d[k].str,b[j].str);
			j+=1; k+=1;
		}else{
			d[k].conso=a[i].conso;
			strcpy(d[k].str,a[i].str);
			i+=1; k+=1;
			d[k].conso=b[j].conso;
			strcpy(d[k].str,b[j].str);
			j+=1; k+=1;
		}
	}

	if (i<x)
	{
		for (counter = i; counter < x; counter+=1)
		{
			d[k].conso=a[counter].conso;
			strcpy(d[k].str,a[counter].str);
			k+=1;
		}
	}

	if (j<y)
	{
		for (counter = j; counter < y; counter+=1)
		{
			d[k].conso=b[counter].conso;
			strcpy(d[k].str,b[counter].str);
			k+=1;
		}
	}
}