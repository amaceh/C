#include "head.h"

int main()
{
	int i;
	data in[9];
	queue Q;
	createEmpty(&Q);
	for (i = 0; i < 8; i+=1)
	{
		scanf("%s", in[i].nama);		
	}
	add(in[0].nama, &Q);
	add(in[1].nama, &Q);
	addPriority(in[2].nama, 1, &Q);
	printf("======\n");
	printQueue(Q);
	del(&Q);
	del(&Q);
	del(&Q);
	printQueue(Q);
	add(in[3].nama, &Q);
	addPriority(in[4].nama, 1, &Q);
	printQueue(Q);
	add(in[5].nama, &Q);
	add(in[6].nama, &Q);
	addPriority(in[7].nama, 10, &Q);
	printQueue(Q);
	
	return 0;
}