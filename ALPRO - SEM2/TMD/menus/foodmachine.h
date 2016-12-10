#include "head.h"
typedef struct{
	int x, y, energy;
	char tempx[8], food[64];
}makan;

int count;
makan ctab;
FILE *fooddata;    // deklarasi nama file
	// membaca file

void STARTFOOD(){
	count=0;
	fooddata=fopen("tmakanan.dat", "r");
	fscanf(fooddata, "%s %d %s %d\n", &ctab.tempx, &ctab.y, &ctab.food, &ctab.energy);
		if (strcmp(ctab.tempx,"##")!=0){
			ctab.x=atoi(ctab.tempx);}
	count += 1;
}

void INCFOOD(){
	fscanf(fooddata, "%s %d %s %d\n", &ctab.tempx, &ctab.y, &ctab.food, &ctab.energy);
		if (strcmp(ctab.tempx,"##")!=0){
			ctab.x=atoi(ctab.tempx);}
	count += 1;
}

char* GETCNAME(){
	return ctab.food;
}

int GETCX(){
	return ctab.x;
}
int GETCY(){
	return ctab.y;
}
int GETCENERGY(){
	return ctab.energy;
}

int EOPFOOD(){
	if (strcmp(ctab.tempx,"##")==0)
	{
		fclose(fooddata);
		return 1;
	}else{
		return 0;
	}
}