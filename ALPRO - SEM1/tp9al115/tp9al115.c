#include <stdio.h>
#include <string.h>

void movetotemp(int counter, char temp[500], char msg[100][50]){
	int i, j, idx=0;
	for (i = 0; i < counter; i+=1)
	{
		for (j = 0; j < strlen(msg[i]); j+=1)
		{
			temp[idx]=msg[i][j];
			idx+=1;
		}
		temp[idx]='\0';
	}
}

void checkchar(int lentem, int swap, char temp[500], 
	char swapchar1[100], char swapchar2[100]){
	int i, j;
	for (i = 0; i < lentem; i+=1){
			for (j = 0; j < swap; j+=1){
				if (temp[i]==swapchar1[j]){
					temp[i]=swapchar2[j];
				}
			}
		}
	}
void returnchar(int counter, char msg[100][50], char temp[500]){
	int i, j, idx=0;
	for (i = 0; i < counter; i+=1){
			for (j = 0; j < strlen(msg[i]); j+=1){
				msg[i][j]=temp[idx];
				idx+=1;
			}
		}
}

	void vocaltotempvoc(int lentem, char temp[500], 
		char tempvoc[300], char tempchar){
		int i, j, idx=0;
			for (i = 0; i < lentem; i+=1){
				if (temp[i]=='a' || temp[i]=='i' 
				|| temp[i]=='u' || temp[i]=='e'
				|| temp[i]=='o'){
				tempvoc[idx]=temp[i];
				temp[i]='*';
				idx+=1;
				}
			}
			for (i = idx-1; i > 0; i-=1)
			{
				if(i==idx-1){
					tempchar=tempvoc[i];
				}
				tempvoc[i]=tempvoc[i-1];
			}
			tempvoc[0]=tempchar;
		}

		void swapstartotempvoc(int lentem, char temp[500],
			char tempvoc[300]){
			int i, j, idx=0;
			for (i = 0; i < lentem; i+=1){
				if (temp[i]=='*'){
					temp[i]=tempvoc[idx];
					idx+=1;
				}
			}
		}

		void movetomsg(int counter, char msg[100][50],
			char temp[500]){
			int i, j, idx=0;
			for (i = 0; i < counter; i+=1)
		{
			for (j = 0; j < strlen(msg[i]); j+=1)
			{
				msg[i][j]=temp[idx];
				idx+=1;
			}
		}
		}
		void movetotemp2(int counter, char temparostr[100][50],
		char msg[100][50]){
		int i;
		for (i = 0; i < counter; i+=1){
				strcpy(temparostr[i], msg[i]);
			}
		}
		void reversechar(int counter, char msg[100][50], 
			char temparostr[100][50]){
			int i, j, idx;
			for (i = 0; i < counter; i+=1){
				idx=strlen(msg[i])-1;
				for (j = 0; j < strlen(msg[i]); j+=1){	
					temparostr[i][j]=msg[i][idx];
					idx-=1;
				}
			}
		}
		void returnreverestring(int counter, char msg[100][50],
			char temparostr[100][50]){
			int i, idx=counter-1;
			for (i = 0; i < counter; i+=1)
			{
				strcpy(msg[i], temparostr[idx]);
				idx-=1;
			}
		}

int main()
{
	char msg[100][50];
	int i=0, j, k, counter=-1, idx=0;
	while(strcmp(msg[i-1], "end")!=0){
		scanf("%s", msg[i]);
		i+=1;
		if (strcmp(msg[i], "end")!=0 && counter<10)
		{
			counter+=1;
		}
	}
	
	int swap;
	scanf("%d", &swap);
	char swapchar1[100], swapchar2[100];
	
	for (i = 0; i < swap; i+=1)
	{
		scanf(" %c %c", &swapchar1[i], &swapchar2[i]);
	}
	char tempchar, temp[500], tempvoc[300], temparostr[100][50];
	///////////////////////////////
	movetotemp(counter, temp, msg);

	int lentem=strlen(temp);

	if(swap!=0){
		checkchar(lentem, swap, temp, swapchar1, swapchar2);
		returnchar(counter, msg, temp);
	}else if (swap==0){
		vocaltotempvoc(lentem, temp, tempvoc, tempchar);
		swapstartotempvoc(lentem, temp, tempvoc);

		movetomsg(counter, msg, temp);
		movetotemp2(counter, temparostr, msg);

		reversechar(counter, msg, temparostr);
		returnreverestring(counter, msg, temparostr);
	}

	for (i = 0; i < counter; ++i)
	{
		printf("%s", msg[i]);
		if (i<counter-1)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}