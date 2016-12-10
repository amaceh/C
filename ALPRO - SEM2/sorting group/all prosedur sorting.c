///buble sorting

void bublesort(int x, int tabInt[x]){

int i, temp, swap;

	do{
		swap=0;

		for (i = 0; i < x-1; i+=1)
		{
			if (tabInt[i]>tabInt[i+1])
			{
				temp=tabInt[i];
				tabInt[i]=tabInt[i+1];
				tabInt[i+1]=temp;
				swap=1;
			}
		}
	}while (swap==1);

}

//insertion sort
void insertionsort(int x, int tabint[x]){


	int i, insertion, j;

	for (i = 0; i < x; i+=1)
	{
		insertion = tabint[i];
		j=i-1;
		while((insertion>tabint[j]) && (j>=0)){
			tabint[j+1]=tabint[j];
			j=j-1;
		}
		tabint[j+1]=insertion;
	}
}

//selection sort
void selectionsort(int x, int tabint[x]){

int i, miniidx, j, temp;

	for (i = 0; i < (x-1); i+=1)
	{
		miniidx=i;
		for (j = i+1; j < x; j+=1)
		{
			if (tabint[miniidx]>tabint[j])
			{
				miniidx=j;
			}
		}

		temp=tabint[i];
		tabint[i]=tabint[miniidx];
		tabint[miniidx]=temp;
	}
}

//quick sort pivot pinggir
void quicksortpinggir(int l, int r){
	int i, j, temp;
	i=l;
	j=r;

	do{
		while((tabint[i]<tabint[r]) && (i<=r)){
			i=i+1;
		}
		while((tabint[j]>tabint[l]) && (i<=j)){
			j=j-1;
		}
		if (i<j)
		{
			temp= tabint[i];
			tabint[i]=tabint[j];
			tabint[j]=temp;
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)
	{
		quicksortpinggir(l,j);
	}
	if (i<r)
	{
		quicksortpinggir(i, r);
	}
}

//quicksort pivot tengah
void quicksorrtengah(int l, int r){
	int i, j, temp;
	i=l; j=r;

	int pivot=tabint[(l+r)/2];
	do{
		while(tabint[i]<pivot && i<=j){
			i+=1;
		}
		while(tabint[j]>pivot && i<=j){
			j-=1;
		}
		if (i<j)
		{
			temp=tabint[i];
			tabint[i]=tabint[j];
			tabint[j]=temp;
			i+=1;
			j-=1;
		}
	}while(i<j);

	if (l<j && j<r && i!=j)
	{
		quicksorrtengah(l, j);
	}
	if (i<r && i>l)
	{
		quicksorrtengah(i, r);
	}
}