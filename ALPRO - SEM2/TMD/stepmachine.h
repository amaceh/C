#include "head.h"
typedef struct{
	int x, y;
	char tempx[10];
}step;

step ctabs;
FILE *stepdata;    // deklarasi nama file
	// membaca file

void STARTSTEP(){
	stepdata=fopen("tperjalanan.dat", "r");
	fscanf(stepdata, "%s %d\n", &ctabs.tempx, &ctabs.y);
		if (strcmp(ctabs.tempx,"##")!=0){
			ctabs.x=atoi(ctabs.tempx);}
}

void INCSTEP(){
	fscanf(stepdata, "%s %d\n", &ctabs.tempx, &ctabs.y);
		if (strcmp(ctabs.tempx,"##")!=0){
			ctabs.x=atoi(ctabs.tempx);}
}

int GETCXS(){
	return ctabs.x;
}
int GETCYS(){
	return ctabs.y;
}

int EOPSTEP(){
	if (strcmp(ctabs.tempx,"##")==0)
	{
		fclose(stepdata);
		return 1;
	}else{
		return 0;
	}
}