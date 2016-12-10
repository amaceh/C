#include <stdio.h>
#include <string.h>

int main(){
	int in;
	scanf("%d", &in);
	char divcek[in][50];
	int i, j, idx=0, idx2=0;
	int validasi=1;
	
	for (i = 0; i < in; ++i)
	{
		scanf("%s", divcek[i]);
	}

	for (i = 0; i < in; ++i)
	{
		if (strcmp(divcek[i], "<div>")==0)
		{
			for (j = i; j >= 0; --j)
			{
				if (strcmp(divcek[j], "</div>")==0){
					validasi=0;
				}
			}
		}
	}

	for (i = 0; i < in; ++i){
		if (strcmp(divcek[i], "<div>")==0)
		{
			for (j = i; j < in; j+=1)
			{
				if (strcmp(divcek[j], "</div>")==0)
				{
					strcpy(divcek[j],"udahdicek");
					idx2+=1;
				}
			}
			idx+=1;
		}
	}
	if (idx!=idx2)
	{
		validasi=0;
	}
	
	if (validasi==1)
	{
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}