#include "head.h"
#include "foodmachine.h"
#include "stepmachine.h"

/*
Saya Achmad Abdul Rofiq tidak melakukan kecurangan 
yang dispesifikasikan pada tugas masa depan Alpro 2 
pada saat mengerjakan Tugas Masa Depan Alpro 2. 
Jika saya melakukan kecurangan maka Allah/Tuhan 
adalah saksi saya, dan saya bersedia menerima hukumanNya. 
Aamiin.
*/

void wait(float x){
	time_t start;
	time_t current;
	time(&start);
	do{ time(&current);
	}while(difftime(current,start) < x);
}


void SetColor(int ForgC){
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

 	if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
 		//We use csbi for the wAttributes word.
		//Mask out all but the background attribute, and add in the forgournd color
    	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    	SetConsoleTextAttribute(hStdOut, wColor);
 	}
}
///////////////////////



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
	system("cls");
	step temp[500];
	int stop1=0;
	while(stop1==0){
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

		int y;  step inmenu;
		printf("\n\nMenu :\n");
		printf("   1. Tambah\n   2. Hapus\n   3. Menu Utama\n  Pilihan Menu : ");	
		scanf("%d", &y);
		if (y==3)
			{
				stop1=1;
		}else if(y!=1 && y!=2){
			printf("   Menu tidak valid\n");
			wait(1.5);
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
					wait(1.5);
				}
			}else{
				if (y==1)
				{
					printf("   maaf, sudah ada langkah di koordinat tersebut\n");
					wait(1.5);
				}else if (y==2)
				{
					deletestep(idx, temp, inmenu.x, inmenu.y);
					idx-=1;
				}
			}
		}
		system("cls");
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
	system("cls");
	makan temp[500];
	int stop1=0;
	while(stop1==0){
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

		int y;  makan inmenu;
		printf("\n\nMenu :\n");
		printf("   1. Tambah\n   2. Hapus\n   3. Menu Utama\n  Pilihan Menu : ");	
		scanf("%d", &y); 
		if(y==3){
			stop1=1;
		}else if(y!=1 && y!=2){
			printf("   Menu tidak valid\n");
			wait(1.5);
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
					wait(1.5);
				}
			}else{
				if (y==1)
				{
					printf("maaf, sudah ada makanan di koordinat tersebut\n");
					wait(1.5);
				}else if (y==2)
				{
					deletefood(idx, temp, inmenu.x, inmenu.y);
					idx-=1;
				}
			}
		}
		system("cls");
	}
}
/////////////////////////////////

void mapeditor(char xmap[500][500], int xen[500][500], int x, int y){
	int i, j, k, idx=0, l;
	char temp[50];
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
				xmap[i][j]=' ';
				xen[i][j]=0;
		}
	}
	STARTFOOD();
	for (i = 0; i < x; i+=1)
	{
		for (j = 0; j < y; j+=1)
		{
			if (i==GETCY() && j==GETCX() && EOPFOOD()!=1)
			{
				xen[i][j]=GETCENERGY();
				idx=0;
				strcpy(temp, GETCNAME());
				l=j;
				for (k = j; k < l+strlen(temp); k+=1)
				{
					xmap[i][k]=temp[idx]; idx+=1;
				}
				INCFOOD();
			}
		}
	}
}
void mapdrawer(char xmap[500][500], int xen[500][500], int x, int y){
	int i, j, k, idx=0, idc=0;

	/////////////////////////
		WORD saved_attributes;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		//simpan informasi set konsol sekarang
		saved_attributes = csbi.wAttributes;
		//rubah warna text(merubah set konsol)
		///////////////////////////
		/*
	Name         | Value
	Black        |   0 *gelap
	Blue         |   1 *gelap
	Green        |   2 *gelap
	Cyan         |   3 *gelap
	Red          |   4 *gelap 
	Magenta      |   5 *gelap
	Brown        |   6 *gelap
	Light Gray   |   7
	Dark Gray    |   8 *gelap
	Light Blue   |   9
	Light Green  |   10
	Light Cyan   |   11
	Light Red    |   12
	Light Magenta|   13
	Yellow       |   14
	White        |   15
	*/
		//////////////////////////////////
	printf("|");
	for (i = 0; i < y; i+=1){
		printf("-");
	}
	printf("|\n");
	for (i = 0; i < x; i+=1){
		printf("|");
		for (j = 0; j < y; j+=1){
			if (xen[i][j]!=0)
			{
				if (xen[i][j]>0 && xen[i][j]<=3)
				{
					SetColor(7);
				}else if (xen[i][j]>3 && xen[i][j]<=6)
				{
					SetColor(9);
				}else if (xen[i][j]>6 && xen[i][j]<=9)
				{
					SetColor(10);
				}else if (xen[i][j]>9 && xen[i][j]<=12)
				{
					SetColor(11);
				}else if (xen[i][j]>12 && xen[i][j]<=15)
				{
					SetColor(12);
				}else if (xen[i][j]>15 && xen[i][j]<=18)
				{
					SetColor(13);
				}else if (xen[i][j]>18)
				{
					SetColor(14);
				}
			}
		printf("%c", xmap[i][j]);
		if (xmap[i][j]==' ')
		{
			SetConsoleTextAttribute(hStdOut, saved_attributes);
		}
		}
		printf("|\n");
	}
	printf("|");
	for (i = 0; i < y; i+=1){
		printf("-");
	}
	printf("|\n");
}

void foodEater(int xen[500][500], char xmap[500][500]){
	int idx, stop=0;
	if (xen[GETCYS()][GETCXS()]!=0)
		{
			idx=0;
			while(stop==0){
				if (xen[GETCYS()][GETCXS()+idx+1]!=0 || xmap[GETCYS()][GETCXS()+idx+1]==' ')
				{
					stop=1;
				}
				xmap[GETCYS()][GETCXS()+idx]=' ';
				idx+=1;
			}
		}
}


void stepdrawer(char xmap[500][500], int xen[500][500], int x, int y){
	int i, j, xdone, ydone, Etotal=0;
	char temp;
	STARTSTEP();
	while(EOPSTEP()!=1){
		system("cls");
		temp=xmap[GETCYS()][GETCXS()];
		foodEater(xen, xmap);
		xmap[GETCYS()][GETCXS()]='A';
		ydone=GETCYS(); xdone=GETCXS();
		mapdrawer(xmap, xen, x, y);
		Etotal+=xen[GETCYS()][GETCXS()];
		if (xen[GETCYS()][GETCXS()]!=0)
		{
			temp=' ';
		}
		xen[GETCYS()][GETCXS()]=0;
		printf("\nEnergi A : %d\n", Etotal);
		INCSTEP();
		if(EOPSTEP()!=1){xmap[ydone][xdone]=temp;}
		wait(0.1);
		// system("cls");
	}
}