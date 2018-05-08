#include "head.h"

int main()
{
	queue Q;
	createEmpty(&Q);
	printQueue(Q);

	printf("************\n");
	add("1503631", "Achmad", 99.99, &Q);
	add("1500001", "teuing", 54.32, &Q);
	add("1501000", "gniuet", 23.45, &Q);
	printQueue(Q);
	printf("************\n");
	del(&Q);
	del(&Q);
	printQueue(Q);
	printf("************\n");
	
	return 0;
}