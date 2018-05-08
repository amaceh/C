#include <stdio.h>
#include <string.h>

int genorganmore(int n, char in[n][50]){
	int i, j, gen=0, gan=0, out=0;
	
	for (i = 0; i < n; i+=1)
	{
		if (strlen(in[i])%2==0)
		{
			gen+=1;
		}else{
			gan+=1;
		}
	}

	if (gen>gan)
	{
		out=1;
	}else if(gan>gen){
		out=2;
	}
	return out;
} 

void reversechar(int n, char in[n][50]){
			int i, j, idx;
			char temparostr[n][50];
			for (i = 0; i < n; i+=1)
			{
				strcpy(temparostr[i], in[i]);
			}
			for (i = 0; i < n; i+=1){
				idx=strlen(in[i])-1;
				for (j = 0; j < strlen(in[i]); j+=1){	
					in[i][j]=temparostr[i][idx];
					idx-=1;
				}
			}
		}
void ptrn1(int n, char in[n][50]){
	int i, j, k, space1=0, space2=0;
	for (i = 0; i < n/2; i+=1)
	{
		for (j = 0; j < space1; j+=1)
		{
			printf(" ");
		}
		printf("%s\n", in[i]);
		space1 +=strlen(in[i]);	
	}
	for (i = n/2-1; i > 0; i-=1)
		{
			space2 +=strlen(in[i]);
		}
	for (i = n/2; i > 0; i-=1)
	{
		for (j = 0; j < space2; j+=1)
		{
			printf(" ");
		}
		printf("%s\n", in[i]);
		space2 -=strlen(in[i+1]);
	}
}

void ptrn2(int n, char in[n][50]){
	int i, j, k, square=0;
	for (i = 0; i < n; i+=2)
	{
		for (j = 0; j < strlen(in[i]); j+=1)
		{
			for (k = 0; k < square; k+=1)
			{
				printf(" ");
			}
			for (k = 0; k < j; k+=1)
			{
				printf(" ");
			}
			printf("%c\n", in[i][j]);
		}
		for (j = 0; j < strlen(in[i]); j+=1)
		{
			printf(" ");
		}
		for (k = 0; k < square; k+=1)
			{
				printf(" ");
			}
			printf("%s\n", in[i+1]);
		square=square+strlen(in[i])+strlen(in[i+1]);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	char input[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", input[i]);
	}
	int ptrn=genorganmore(n, input);
	if (ptrn==1)
	{
		reversechar(n, input);
		ptrn1(n, input);
	}else if(ptrn==2){
		ptrn2(n, input);
	}
	return 0;
}	