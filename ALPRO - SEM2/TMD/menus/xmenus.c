#include "head.h" 
#include "foodmachine.h"
#include "stepmachine.h"

void flushstep(int idx, step temp[500]){
	stepdata=fopen("tperjalanan.dat", "w");
	int i;
	for (i = 0; i < idx; i+=1)
	{
		fprintf(stepdata, "%d %d\n", temp[i].x, temp[i].y);
	}
	fprintf(stepdata, "%s %s\n", "##", "##");
	fclose(stepdata);
}

void deletestep(int idx, step xin[500], int x, int y){
	int i=0, stop=0;
	while(i<idx && stop==0){
		if (xin[i].y==y && xin[i].x==x)
		{
			stop=1;
		}else{
			i+=1;
		}
	}
	int j;
	for (j = i; j < idx; j+=1)
	{
		xin[j]=xin[j+1];
	}
	idx-=1;
	flushstep(idx, xin);
}

void quicksortstep(int l, int r, step ex[500]){
	int i, j;
	step temp;
	i=l;
	j=r;

	do{
		while((ex[i].x<ex[r].x) && (i<=r)){
			i=i+1;
		}
		while((ex[j].x>ex[l].x) && (i<=j)){
			j=j-1;
		}
		if (i<j)
		{
			temp= ex[i];
			ex[i]=ex[j];
			ex[j]=temp;
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)
	{
		quicksortstep(l, j, ex);
	}
	if (i<r)
	{
		quicksortstep(i, r, ex);
	}
}

void addstep(step xin[500], step inex, int idx){
	int i;
	if (xin[0].y>=inex.y){
		for (i = idx-1; i >=0 ; i-=1){
			xin[i+1]=xin[i];
		}
		xin[0]=inex;
		idx+=1;
		if (xin[1].y==inex.y)
		{
			int k=0;
			while(xin[k].y==xin[0].y){
				k+=1;
			}
			quicksortstep(0, k, xin);
		}
	}else if (inex.y>=xin[idx-1].y){
		xin[idx]=inex;
		idx+=1;
		if (inex.y==xin[idx-1].y)
		{
			int k=idx-1;
			while(xin[k].y==inex.y){
				k-=1;
			}
			quicksortstep(k+1, idx-1, xin);
		}
	}else{
		int i=0;
		int stop=0;
		while(i<idx && stop==0){
			if (xin[i].y>=inex.y)
			{
				stop=1;
			}else{
				i+=1;
			}
		}
		int j;
		for (j = idx-1; j>=i ; j-=1)
		{
			xin[j+1]=xin[j];
		}
		xin[i]=inex;
		if (xin[i].y==xin[i+1].y)
		{
			int k=i;
			while(xin[k].y==xin[i].y){
				k+=1;
			}
			quicksortstep(i, k, xin);
		}
		idx+=1;
	}
	flushstep(idx, xin);
}

int searchstep(int idx, step inex[500], int x, int y){
	int i=0, stop=0;
	while(i<idx && stop==0){
		if (inex[i].y==y && inex[i].x==x)
		{
			stop=1;
		}else{
			i+=1;
		}
	}
	return stop;
}

void stepmanager(){
	step temp[500];
	STARTSTEP();
	int idx=0, i, j, k;
	int longx=longcounter(GETCXS());
	int longy=longcounter(GETCYS());
	while(EOPSTEP()!=1){
		temp[idx].x=GETCXS();
		temp[idx].y=GETCYS();
		INCSTEP();
		idx+=1;
		if(longcounter(GETCXS())>longx){longx=longcounter(GETCXS());}
		if(longcounter(GETCYS())>longy){longy=longcounter(GETCYS());}
	}
	for (i = 0; i < (longx+2)+(longy+2)+1; i+=1){printf("-");}
	printf("\n|x");
	for (i = 0; i < longx; i+=1){printf(" ");}
	printf("|y");
	for (i = 0; i < longy; i+=1){printf(" ");}
	printf("|\n");
	for (i = 0; i < (longx+2)+(longy+2)+1; i+=1){printf("-");}
	printf("\n");
	for (i = 0; i < idx; i+=1){
		printf("|%d", temp[i].x);
		for (j = 0; j < longx+1-longcounter(temp[i].x); j+=1){printf(" ");}
		printf("|%d", temp[i].y);
		for (j = 0; j < longy+1-longcounter(temp[i].y); j+=1){printf(" ");}
		printf("|\n");
	}
	for (i = 0; i < (longx+2)+(longy+2)+1; i+=1){printf("-");}

	int y, stop2=0;  step inmenu;
	while(stop2==0){
		printf("\n\nMenu :\n");
		printf("   1. Tambah\n   2. Hapus\n   3. Menu Utama\n  Pilihan Menu : ");	
		scanf("%d", &y);
		if (y==1 || y==2 || y==3)
			{
				stop2=1;
		}
		else{
			printf("   Menu tidak valid\n");
		}	
	}
	printf("\n");
	if (y==1 || y==2)
	{
		printf("x : ");
		scanf("%d", &inmenu.x);
		printf("y : ");
		scanf("%d", &inmenu.y);
		if (searchstep(idx, temp, inmenu.x, inmenu.y)==0)
		{
			if (y==1)
			{
				addstep(temp, inmenu, idx);
				idx+=1;
			}else if (y==2)
			{
				printf("   Tidak ada langkah di koordinat tersebut\n");
			}
		}else{
			if (y==1)
			{
				printf("   maaf, sudah ada langkah di koordinat tersebut\n");
			}else if (y==2)
			{
				deletestep(idx, temp, inmenu.x, inmenu.y);
				idx-=1;
			}
		}
	}
}


void flushfood(int idx, makan temp[500]){
	fooddata=fopen("tmakanan.dat", "w");
	int i;
	for (i = 0; i < idx; i+=1)
	{
		fprintf(fooddata, "%d %d %s %d\n", temp[i].x, temp[i].y, temp[i].food, temp[i].energy);
	}
	fprintf(fooddata, "%s %s %s %s\n", "##", "##", "##", "##");
	fclose(fooddata);
}

void deletefood(int idx, makan xin[500], int x, int y){
	int i=0, stop=0;
	while(i<idx && stop==0){
		if (xin[i].y==y && xin[i].x==x)
		{
			stop=1;
		}else{
			i+=1;
		}
	}
	int j;
	for (j = i; j < idx; j+=1)
	{
		xin[j]=xin[j+1];
	}
	idx-=1;
	flushfood(idx, xin);
}

int searchfood(int idx, makan inex[500], int x, int y){
	int i=0, stop=0;
	while(i<idx && stop==0){
		if (inex[i].y==y && inex[i].x==x)
		{
			stop=1;
		}else{
			i+=1;
		}
	}
	return stop;
}



void quicksortfood(int l, int r, makan ex[500]){
	int i, j;
	makan temp;
	i=l;
	j=r;

	do{
		while((ex[i].x<ex[r].x) && (i<=r)){
			i=i+1;
		}
		while((ex[j].x>ex[l].x) && (i<=j)){
			j=j-1;
		}
		if (i<j)
		{
			temp= ex[i];
			ex[i]=ex[j];
			ex[j]=temp;
			i=i+1;
			j=j-1;
		}	
	}while(i<j);


	if (l<j)
	{
		quicksortfood(l, j, ex);
	}
	if (i<r)
	{
		quicksortfood(i, r, ex);
	}
}

void addfood(makan xin[500], makan inex, int idx){
	int i;
	if (xin[0].y>=inex.y){
		for (i = idx-1; i >=0 ; i-=1){
			xin[i+1]=xin[i];
		}
		xin[0]=inex;
		idx+=1;
		if (xin[1].y==inex.y)
		{
			int k=0;
			while(xin[k].y==xin[0].y){
				k+=1;
			}
			quicksortfood(0, k, xin);
		}
	}else if (inex.y>=xin[idx-1].y){
		xin[idx]=inex;
		idx+=1;
		if (inex.y==xin[idx-1].y)
		{
			int k=idx-1;
			while(xin[k].y==inex.y){
				k-=1;
			}
			quicksortfood(k+1, idx-1, xin);
		}
	}else{
		int i=0;
		int stop=0;
		while(i<idx && stop==0){
			if (xin[i].y>=inex.y)
			{
				stop=1;
			}else{
				i+=1;
			}
		}
		int j;
		for (j = idx-1; j>=i ; j-=1)
		{
			xin[j+1]=xin[j];
		}
		xin[i]=inex;
		if (xin[i].y==xin[i+1].y)
		{
			int k=i;
			while(xin[k].y==xin[i].y){
				k+=1;
			}
			quicksortfood(i, k, xin);
		}
		idx+=1;
	}
	flushfood(idx, xin);
}


int longcounter(int x){
	int res=1, stop=1;
	while(stop==1){
		if (x<10)
		{
			stop=0;
			return res;
		}else{
			res+=1;
			x/=10;
		}
	}
}


void foodmanager(){
	makan temp[500];
	STARTFOOD();
	int idx=0, i, j, k;
	int longx=longcounter(GETCX());
	int longy=longcounter(GETCY());
	int longener=longcounter(GETCENERGY());
	int longname=strlen(GETCNAME());
	while(EOPFOOD()!=1){
		strcpy(temp[idx].food,GETCNAME());
		temp[idx].x=GETCX();
		temp[idx].y=GETCY();
		temp[idx].energy=GETCENERGY();
		INCFOOD();
		idx+=1;
		if(longcounter(GETCX())>longx){longx=longcounter(GETCX());}
		if(longcounter(GETCY())>longy){longy=longcounter(GETCY());}
		if(longcounter(GETCENERGY())>longener){longener=longcounter(GETCENERGY());}
		if(strlen(GETCNAME())>longname){longname=strlen(GETCNAME());}
	}
	for (i = 0; i < (longx+2)+(longy+2)+(longname+2)+(longener+3)+7; i+=1){printf("-");}
	printf("\n|x");
	for (i = 0; i < longx; i+=1){printf(" ");}
	printf("|y");
	for (i = 0; i < longy; i+=1){printf(" ");}
	printf("|nama");
	for (i = 0; i < longname; i+=1){printf(" ");}
	printf("|energi");
	for (i = 0; i < longener-1; i+=1){printf(" ");}
	printf("|\n");
	for (i = 0; i < (longx+2)+(longy+2)+(longname+2)+(longener+3)+7; i+=1){printf("-");}
	printf("\n");
	for (i = 0; i < idx; i+=1){
		printf("|%d", temp[i].x);
		for (j = 0; j < longx+1-longcounter(temp[i].x); j+=1){printf(" ");}
		printf("|%d", temp[i].y);
		for (j = 0; j < longy+1-longcounter(temp[i].y); j+=1){printf(" ");}
		printf("|%s", temp[i].food);
		for (j = 0; j < longname+4-strlen(temp[i].food); j+=1){printf(" ");}
		printf("|%d", temp[i].energy);
		for (j = 0; j < longener+5-longcounter(temp[i].energy); j+=1){printf(" ");}
		printf("|\n");
	}
	for (i = 0; i < (longx+2)+(longy+2)+(longname+2)+(longener+3)+7; i+=1){printf("-");}

	int y, stop2=0;  makan inmenu;
	while(stop2==0){
		printf("\n\nMenu :\n");
		printf("   1. Tambah\n   2. Hapus\n   3. Menu Utama\n  Pilihan Menu : ");	
		scanf("%d", &y);
		if (y==1 || y==2 || y==3)
			{
				stop2=1;
		}
		else{
			printf("   Menu tidak valid\n");
		}	
	}
	printf("\n");
	if (y==1 || y==2)
	{
		printf("x : ");
		scanf("%d", &inmenu.x);
		printf("y : ");
		scanf("%d", &inmenu.y);
		if (searchfood(idx, temp, inmenu.x, inmenu.y)==0)
		{
			if (y==1)
			{
				printf("nama : ");
				scanf("%s", &inmenu.food);
				printf("energi : ");
				scanf("%d", &inmenu.energy);
				addfood(temp, inmenu, idx);
				idx+=1;
			}else if (y==2)
			{
				printf("    Makanan tidak ada di koordinat tersebut\n");
			}
		}else{
			if (y==1)
			{
				printf("maaf, sudah ada makanan di koordinat tersebut\n");
			}else if (y==2)
			{
				deletefood(idx, temp, inmenu.x, inmenu.y);
				idx-=1;
			}
		}
	}
}

int main()
{
	int stop=1;
	while(stop==1){	
	printf("Menu:\n");
	printf("0. Panjang dan Lebar Papan\n");
	printf("1. Kelola Makanan\n");
	printf("2. Kelola Perjalanan\n");
	printf("3. A Cari Makan\n");
	printf("4. Keluar\n");
	printf("Masukkan Menu : ");
	int x;
	scanf("%d", &x);
	if (x==0)
	{
		///such easy
	}else if (x==1)
	{
		foodmanager();
	}else if (x==2)
	{
		stepmanager();
	}else if (x==3)
	{
		stop=0;
	}else if (x==4)
	{
		stop=0;	
	}else{
		printf("Menu tidak valid\n");
	}
	}
	return 0;
}