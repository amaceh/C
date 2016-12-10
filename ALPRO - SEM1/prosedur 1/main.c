#include "pola.h"

int main()
{
	int b;
	scanf("%d", &b);

	pola(b);
	pola(b+1);
	pola(b+2);

	return 0;
}

/*
gcc -c *.c
gcc *.c -o pola.exe
pola.exe
*/