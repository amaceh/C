#include <stdio.h>

int main()
{
	int in, hasil=0;

	scanf("%d", &in);
	if(in!=0)
	while(in>=1){
		in=in/10;
		hasil+=1;
	}else{
		hasil=1;
	}

	printf("%d digit\n", hasil);
	return 0;
}