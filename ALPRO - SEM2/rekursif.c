#include <stdio.h>

void write(int n){
	int counter;
	counter = n;

	if (counter>0)
	{
		printf("proses rekursif dengan nilai counter : %d\n", counter);
		counter-=1;
		write(counter);
	}
}

int main()
{
	write(10);
	return 0;
}