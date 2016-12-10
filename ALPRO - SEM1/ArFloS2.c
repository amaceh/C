#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	float arrflo[100];
	for (i = 0; i < n; i+=1)
	{
		scanf("%f", &arrflo[i]);
	}
	int front[n], back[n], gan[n], gen[n], valid=0;
	int v, w, x, y, z;
	for (i = 0; i < n; i+=1)
	{
		v = arrflo[i] * 100;
		w = v / 1000;
		x = (v /100)-(w *10);
		y =(v /10)-(w *100)-(x *10);
		z =v-(w *1000)-(x *100)-(y *10);
		front[i] =(w *10)+x;
		back[i] =(y *10)+z;
		
		gen[i]=front[i] % 2;
		gan[i]=back[i] % 2;
		
		if(gen[i]==0 && gan[i]==1 && front[i]!=0 && back[i]!=0){
			valid=valid+1;
		}
	}
	
	if (valid >= 3)
	{
		printf("yes\n");
	}else{
		printf("no\n");
	}

	return 0;
}