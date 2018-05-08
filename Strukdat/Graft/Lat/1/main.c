#include "head.h"

int main(){
	

	graph G;
	createEmpty(&G);
	queue Qjlr;
	createEmptyQ(&Qjlr);
	queue result;
	createEmptyQ(&result);
	int x, i;
	scanf("%d", &x);
	for (i = 0; i < x; i+=1){//berapa graf
		int y, j;
		scanf("%d", &y);//berapa kota
		char inp[50];
		for (j = 0; j < y; j+=1){
			scanf("%s", inp);//kota
			addSimpul(inp, &G);
			int z, k;
			scanf("%d", &z);//berapa jalur
			for (k = 0; k < z; k+=1){
				char inp2[50];
				int jar;
				scanf("%s %d", inp2, &jar);//tujuan jarak
				add(inp, inp2, jar, &Qjlr);
			}
		}
		addAllJlr(&Qjlr, &G);
		char A[50], B[50];
		scanf("%s %s", A, B);//yang mau dicari
		// printGraph(G);
		findTheWay(A, B, &result, G, 0);
	}
	printQueue(result);
	// addSimpul('A', &G);
	// addSimpul('B', &G);
	// addSimpul('C', &G);
	// addSimpul('D', &G);
	// addSimpul('E', &G);
	// addSimpul('F', &G);

	// simpul *bgn, *end;

	// bgn=findSimpul('A', G);
	// end=findSimpul('B', G);
	// addJalur(end,bgn);

	// bgn=findSimpul('B', G);
	// end=findSimpul('C', G);
	// addJalur(end,bgn);

	// // bgn=findSimpul('B', G);
	// end=findSimpul('E', G);
	// addJalur(end,bgn);

	// bgn=findSimpul('C', G);
	// end=findSimpul('D', G);
	// addJalur(end,bgn);

	// bgn=findSimpul('D', G);
	// end=findSimpul('F', G);
	// addJalur(end,bgn);

	// printGraph(G);

	// printf("-----\n");
	// delSimpul(x, &G);

	// printGraph(G);
	return 0;
}