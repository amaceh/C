#include "x.1.h"

void consocounter1(int n, tab1 a[n]){
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
void consocounter2(int n, tab2 b[n]){
	int i, len, j;
	for (i = 0; i < n; i+=1)
	{
		len=strlen(b[i].str);
		b[i].conso =0;
		for (j = 0; j < len; j+=1)
		{
			if (b[i].str[j] !='a' && b[i].str[j] !='i' && b[i].str[j] !='u' &&
				b[i].str[j] !='e' && b[i].str[j] !='o'){
				b[i].conso +=1;
			}
		}
	}
}
void consocounter3(int n, tab3 c[n]){
	int i, len, j;
	for (i = 0; i < n; i+=1)
	{
		len=strlen(c[i].str);
		c[i].conso =0;
		for (j = 0; j < len; j+=1)
		{
			if (c[i].str[j] !='a' && c[i].str[j] !='i' && c[i].str[j] !='u' &&
				c[i].str[j] !='e' && c[i].str[j] !='o'){
				c[i].conso +=1;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
//111111111111111111111111111111111111111111111111111111111111111111111111111111111
////////////////////////////////////////////////////////////////////////////////////
void bublesort1(int x, tab1 a[x]){

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
void insertionsort1(int x, tab1 a[x]){
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
void selectionsort1(int x, tab1 a[x]){

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
void quicksortpinggir1(int x, tab1 a[x], int l, int r){
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
		quicksortpinggir1(x,a,l,j);
	}
	if (i<r)
	{
		quicksortpinggir1(x,a,i,r);
	}
}
/////////////////////////////////////////////
//222222222222222222222222222222222222222222222
//////////////////////////////////////////////
void bublesort2(int x, tab2 b[x]){

int i, temp, swap;
char temp2[50];

	do{
		swap=0;

		for (i = 0; i < x-1; i+=1)
		{
			if (b[i].conso>b[i+1].conso)
			{
				temp=b[i].conso;
				b[i].conso=b[i+1].conso;
				b[i+1].conso=temp;
				strcpy(temp2,b[i].str);
				strcpy(b[i].str,b[i+1].str);
				strcpy(b[i+1].str,temp2);
				swap=1;
			}
		}
	}while (swap==1);

}

//insertion sort
void insertionsort2(int x, tab2 b[x]){
	int i, insertion, j;
	char temp[50];

	for (i = 0; i < x; i+=1)
	{
		insertion = b[i].conso;
		strcpy(temp,b[i].str);
		j=i-1;
		while((insertion>b[j].conso) && (j>=0)){
			b[j+1].conso=b[j].conso;
			strcpy(b[j+1].str,b[j].str);
			j=j-1;
		}
		b[j+1].conso=insertion;
		strcpy(b[j+1].str,temp);
	}
}

//selection sort
void selectionsort2(int x, tab2 b[x]){

int i, miniidx, j, temp;
char temp2[50];

	for (i = 0; i < (x-1); i+=1)
	{
		miniidx=i;
		for (j = i+1; j < x; j+=1)
		{
			if (b[miniidx].conso>b[j].conso)
			{
				miniidx=j;
			}
		}

		temp=b[i].conso;
		b[i].conso=b[miniidx].conso;
		b[miniidx].conso=temp;
		strcpy(temp2,b[i].str);
		strcpy(b[i].str,b[miniidx].str);
		strcpy(b[miniidx].str,temp2);
	}
}

//quick sort pivot pinggir
void quicksortpinggir2(int x, tab2 b[x], int l, int r){
	int i, j, temp;
	i=l;
	j=r;
	char temp2[50];

	do{
		while((b[i].conso<b[r].conso) && (i<=r)){
			i=i+1;
		}
		while((b[j].conso>b[l].conso) && (i<=j)){
			j=j-1;
		}
		if (i<j)
		{
			temp=b[i].conso;
			b[i].conso=b[j].conso;
			b[j].conso=temp;
			strcpy(temp2,b[i].str);
			strcpy(b[i].str,b[j].str);
			strcpy(b[j].str,temp2);
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)
	{
		quicksortpinggir2(x,b,l,j);
	}
	if (i<r)
	{
		quicksortpinggir2(x,b,i,r);
	}
}

////////////////////////////////////////////////
//3333333333333333333333333333333333333333333333
/////////////////////////////////////////////////
void bublesort3(int x, tab3 c[x]){

int i, temp, swap;
char temp2[50];

	do{
		swap=0;

		for (i = 0; i < x-1; i+=1)
		{
			if (c[i].conso>c[i+1].conso)
			{
				temp=c[i].conso;
				c[i].conso=c[i+1].conso;
				c[i+1].conso=temp;
				strcpy(temp2,c[i].str);
				strcpy(c[i].str,c[i+1].str);
				strcpy(c[i+1].str,temp2);
				swap=1;
			}
		}
	}while (swap==1);

}

//insertion sort
void insertionsort3(int x, tab3 c[x]){
	int i, insertion, j;
	char temp[50];

	for (i = 0; i < x; i+=1)
	{
		insertion = c[i].conso;
		strcpy(temp,c[i].str);
		j=i-1;
		while((insertion>c[j].conso) && (j>=0)){
			c[j+1].conso=c[j].conso;
			strcpy(c[j+1].str,c[j].str);
			j=j-1;
		}
		c[j+1].conso=insertion;
		strcpy(c[j+1].str,temp);
	}
}

//selection sort
void selectionsort3(int x, tab3 c[x]){

int i, miniidx, j, temp;
char temp2[50];

	for (i = 0; i < (x-1); i+=1)
	{
		miniidx=i;
		for (j = i+1; j < x; j+=1)
		{
			if (c[miniidx].conso>c[j].conso)
			{
				miniidx=j;
			}
		}

		temp=c[i].conso;
		c[i].conso=c[miniidx].conso;
		c[miniidx].conso=temp;
		strcpy(temp2,c[i].str);
		strcpy(c[i].str,c[miniidx].str);
		strcpy(c[miniidx].str,temp2);
	}
}

//quick sort pivot pinggir
void quicksortpinggir3(int x, tab3 c[x], int l, int r){
	int i, j, temp;
	i=l;
	j=r;
	char temp2[50];

	do{
		while((c[i].conso<c[r].conso) && (i<=r)){
			i=i+1;
		}
		while((c[j].conso>c[l].conso) && (i<=j)){
			j=j-1;
		}
		if (i<j)
		{
			temp=c[i].conso;
			c[i].conso=c[j].conso;
			c[j].conso=temp;
			strcpy(temp2,c[i].str);
			strcpy(c[i].str,c[j].str);
			strcpy(c[j].str,temp2);
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)
	{
		quicksortpinggir3(x,c,l,j);
	}
	if (i<r)
	{
		quicksortpinggir3(x,c,i,r);
	}
}