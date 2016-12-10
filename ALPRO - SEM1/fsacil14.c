#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char n[10];
	n[0]='\0';

	if (strcmp(n, "\0")==0)
	{
		printf("bisa\n");
	}
	return 0;
}