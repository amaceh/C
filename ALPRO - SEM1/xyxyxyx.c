#include <stdio.h>

int main(){
	int n[999], i=0, loop, count=0;

	while(loop != 0){
		scanf("%d", &n[i]);
		loop=n[i];
		count+=n[i];
		i+=1;
	}
	printf("%d\n", count);

	return 0;
}