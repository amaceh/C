#include <stdio.h>
#include <string.h>

void playcard(int n, char P1[n][3], char P2[n][3], 
	char P3[n][3], char P4[n][3], char out[n*4][3]){
	int i, j, k, idx=0;
	///////////////////////////////
	char card[13][3];
	strcpy(card[0], "A");
	strcpy(card[1], "K");
	strcpy(card[2], "Q");
	strcpy(card[3], "J");
	strcpy(card[4], "10");
	strcpy(card[5], "9");
	strcpy(card[6], "8");
	strcpy(card[7], "7");
	strcpy(card[8], "6");
	strcpy(card[9], "5");
	strcpy(card[10], "4");
	strcpy(card[11], "3");
	strcpy(card[12], "2");
	////////////////////////
	for (k = 0; k < 13; k+=1){
		for (i = 0; i < n; i+=1)
		{
			if (strcmp(P1[i], card[k])==0)
			{
				strcpy(out[idx], P1[i]);
				idx+=1;
				for (j = i; j < n; j+=1)
				{
					strcmp(P1[j], P1[j+1]);
				}
			}
			if (strcmp(P2[i], card[k])==0)
			{
				strcpy(out[idx], P2[i]);
				idx+=1;
				for (j = i; j < n; j+=1)
				{
					strcmp(P2[j], P2[j+1]);
				}
			}
			if (strcmp(P3[i], card[k])==0)
			{
				strcpy(out[idx], P3[i]);
				idx+=1;
				for (j = i; j < n; j+=1)
				{
					strcmp(P3[j], P3[j+1]);
				}
			}
			if (strcmp(P4[i], card[k])==0)
			{
				strcpy(out[idx], P4[i]);
				idx+=1;
				for (j = i; j < n; j+=1)
				{
					strcmp(P4[j], P4[j+1]);
				}
			}
		}
	}

	for (i = 0; i < idx; i+=1)
	{
		printf("%s\n", out[i]);
	}	
}

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	char P1[n][3], P2[n][3], P3[n][3], P4[n][3], out[n*4][3];

	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P1[i]);
	}
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P2[i]);
	}
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P3[i]);
	}
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", P4[i]);
	}
playcard(n, P1, P2, P3, P4, out);
	return 0;
}	