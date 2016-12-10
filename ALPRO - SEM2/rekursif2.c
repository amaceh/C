#include <stdio.h>

int faktorial(int n){
	if (n==0 || n==1)
	{
		return 1;
	}else{
		return (n*faktorial(n-1));
	}
}

int main()
{
	printf("hasil faktorial : %d\n", faktorial(3));
	return 0;

}