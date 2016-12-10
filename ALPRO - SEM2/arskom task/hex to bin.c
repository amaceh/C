#include <stdio.h>

void octtobin(int x, char str[x], char str2[x*4]){
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
		}else if (str[i]=='8'){	temp[i]=8;
		}else if (str[i]=='9'){	temp[i]=9;
		}else if (str[i]=='A'){	temp[i]=10;
		}else if (str[i]=='B'){	temp[i]=11;
		}else if (str[i]=='C'){	temp[i]=12;
		}else if (str[i]=='D'){	temp[i]=13;
		}else if (str[i]=='E'){	temp[i]=14;
		}else if (str[i]=='F'){	temp[i]=15;
		}	
	}
	int bin, idxx;
	for (i = x*4-1; i >=0 ; i-=4)
	{
		bin=8; idxx=3;
		for (j = i; j < i+4; j+=1)
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
	str2[x*4]='\0';
}

int main()
{
	printf("convert hex to bin\nmau berapa digit?");
	int n; scanf("%d", &n);
	
	char hex[n], bin[n*4];
	scanf("%s", &hex);
	octtobin(n, hex, bin);
	printf("%s\n", bin);
	return 0;
}	