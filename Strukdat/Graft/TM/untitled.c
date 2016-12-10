#include "head.h"

int main(){
	
	char x;
	scanf("%c", &x);

	graph G;
	createEmpty(&G);
	addSimpul('A', &G);
	addSimpul('B', &G);
	addSimpul('C', &G);
	addSimpul('D', &G);
	addSimpul('E', &G);
	addSimpul('F', &G);

	simpul *bgn, *end;

	bgn=findSimpul('A', G);
	end=findSimpul('B', G);
	addJalur(end,bgn);

	bgn=findSimpul('B', G);
	end=findSimpul('C', G);
	addJalur(end,bgn);

	// bgn=findSimpul('B', G);
	end=findSimpul('E', G);
	addJalur(end,bgn);

	bgn=findSimpul('C', G);
	end=findSimpul('D', G);
	addJalur(end,bgn);

	bgn=findSimpul('D', G);
	end=findSimpul('F', G);
	addJalur(end,bgn);

	printGraph(G);

	printf("-----\n");
	delSimpul(x, &G);

	printGraph(G);
	return 0;
}