#include <stdio.h>

int FPB(int a, int b){
	if (b==0)
	{
		return a;
	}else{
		return FPB(b, a%b);
	}
}

int main()
{
	printf("hasil FPB : %d\n", FPB(10, 12));
	return 0;
}