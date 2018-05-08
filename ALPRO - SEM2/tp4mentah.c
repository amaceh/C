#include <stdio.h>
#include <string.h>

void bublesort(int x, char str[x][16], char str2[x][30]){
	int i, swap;
	char temp[30];
	do{
		swap=0;
		for (i = 0; i < x-1; i+=1)
		{
			//strcmp(str[miniidx], str[j])==-1
			if (strcmp(str[i],str[i+1])==1)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[i+1]);
				strcpy(str[i+1],temp);
				strcpy(temp,str2[i]);
				strcpy(str2[i],str2[i+1]);
				strcpy(str2[i+1],temp);
				swap=1;
			}
		}
	}while (swap==1);
}
void quicksortpinggir(int x, char str[x][30],int l, int r, char str2[x][16]){
	int i, j;
	i=l; j=r;
	char temp[30];

	do{
		while(strcmp(str[i],str[r])==-1 && (i<=r)){
			i+=1;
		}
		while(strcmp(str[j],str[l])==1 && (i<=j)){
			j-=1;
		}
		if (i<j)
		{
			strcpy(temp,str[i]);
			strcpy(str[i],str[j]);
			strcpy(str[j],temp);
			strcpy(temp,str2[i]);
			strcpy(str2[i],str2[i+1]);
			strcpy(str2[i+1],temp);
			i=i+1;
			j=j-1;
		}	
	}while(i<j);

	if (l<j)
	{
		quicksortpinggir(x, str,l,j, str2);
	}
	if (i<r)
	{
		quicksortpinggir(x, str,i,r, str2);
	}
}
void printthelist(int x, char str[x][16], char str2[x][30],
		char strx[x][16], char strx2[x][30], int unvalid, 
		char order1[16], char order2[16]){
	int i;
	if (strcmp(order2, "nim")==0 || strcmp(order2, "nama")==0)
	{
		if (strcmp(order2, "nim")==0)
		{
			bublesort(x, str, str2);
		}else if (strcmp(order2, "nama")==0)
		{
			quicksortpinggir(x, str2, 0, x-unvalid-1, str);
		}
		printf("---Hasil Pengurutan---\n");
		if (unvalid<x)
		{
			for (i = 0; i < x-unvalid; i+=1)
			{
				printf("%s %s\n", str[i], str2[i]);
			}
		}else{
			printf("Tidak ada data valid.\n");
		}
		if (strcmp(order1, "ya")==0)
		{
			printf("---Daftar Error---\n");
			for (i = 0; i < unvalid; i+=1)
			{
				printf("%s %s\n", strx[i], strx2[i]);
			}
		}
	}else{
		printf("---Data tidak dapat diproses---\n");
	}
}
int numbercheck(char str[16]){
	int i;
	int counter=0;
	for (i = 0; i < 7; i+=1)
	{
		if (str[i]=='0' || str[i]=='1' || str[i]=='2'|| str[i]=='3' || str[i]=='4'
			|| str[i]=='5' || str[i]=='6' || str[i]=='7' || str[i]=='8' || str[i]=='9')
		{
			counter+=1;	
		}
		
	}
	if (counter==7)
	{
		return 0;
	}else{
		return 1;
	}
}

void unvalidfinder(int x, char str[x][16], char str2[x][30], char stry[x][16], 
	char stry2[x][30], char strx[x][16], char strx2[x][30], char order1[16], char order2[16]){
	int i, j;
	int len;
	int count=0, count2=0;
	for (i = 0; i < x; i+=1)
	{
		len=strlen(str[i]);
		if (len!=7 || numbercheck(str[i])==1){
			
			strcpy(strx[count],str[i]);
			strcpy(strx2[count],str2[i]);
			count+=1;
		}else{
			strcpy(stry[count2],str[i]);
			strcpy(stry2[count2],str2[i]);
			count2+=1;
		}
	}

	printthelist(x, stry, stry2, strx, strx2, count, order1, order2);

}

int main()
{
	int N;
	scanf("%d", &N);
	char order1[16], order2[16], nim[N][16], nama[N][30];
	scanf("%s", &order1);
	int i;

	for (i = 0; i < N; i+=1)
	{
		scanf("%s %s", &nim[i], &nama[i]);
	}
	scanf("%s", &order2);

	char realnim[N][16], realname[N][30], unnim[N][16], unname[N][30];

	unvalidfinder(N, nim, nama, realnim, realname, unnim, unname, order1, order2);
	return 0;
}	