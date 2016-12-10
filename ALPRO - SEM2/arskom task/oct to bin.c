#include <stdio.h>

void octtobin(int x, char str[x], char str2[x*3]){
	int i, temp[x], idx=x-1, j;
	for (i = x-1; i >= 0; i-=1)
	{
		if (str[i]=='0'){		temp[i]=0;
		}else if (str[i]=='1'){	temp[i]=1;
		}else if (str[i]=='2'){	temp[i]=2;
		}else if (str[i]=='3'){	temp[i]=3;
		}else if (str[i]=='4'){	temp[i]=4;
		}else if (str[i]=='5'){	temp[i]=5;
		}else if (str[i]=='6'){	temp[i]=6;
		}else if (str[i]=='7'){	temp[i]=7;
		}	
	}
	int bin, idxx;
	for (i = x*3-1; i >=0 ; i-=3)
	{
		bin=4; idxx=2;
		for (j = i; j < i+3; j+=1)
		{
			if (temp[idx]>=bin)
			{
				temp[idx]-=bin;
				str2[i-idxx]='1';
			}else{
				str2[i-idxx]='0';
			}
			idxx-=1;
			bin/=2;
		}
			idx-=1;
	}
	str2[x*3]='\0';
}

int main()
{
	printf("convert octal to bin\nmau berapa digit?");
	int n; scanf("%d", &n);
	
	char octa[n], bin[n*3];
	scanf("%s", &octa);
	octtobin(n, octa, bin);
	printf("%s\n", bin);
	return 0;
}	