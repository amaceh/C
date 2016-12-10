#include <stdio.h>
#include <string.h>

int main(){
	
	int n, m, x;
	int i, j, k;
	int idx=0, idx2=0, swap=0, swap2=0;

	scanf("%d", &n);
	
	char str1[n][50];
	for (i = 0; i < n; i+=1){
		scanf("%s", str1[i]);
	}

	scanf("%d", &m);
	char str2[m][50];
	for (i = 0; i < m; i+=1){
		scanf("%s", str2[i]);
	}

	scanf("%d", &x);

	char temp[n+m][50];
	for (i = 0; i < n; i+=1)
	{
		strcpy(temp[i], str1[i]);
	}
	for (i = 0; i < m; i+=1)
	{
		strcpy(temp[i+n], str2[i]);	
	}

	for (i = 0; i < n+m; i+=1)
	{	
		if ((i+x) < n+m){
			swap=i+x;
		}else if ((i+x) > n+m){
			if (swap==n+m+1){
				swap=0;
				idx=0;
			}
			swap=idx;
			idx+=1;
		}
		printf("%d\n", swap);
		if (i<=n){
			strcpy(str1[i], temp[swap]);
		}else{
			strcpy(str2[i], temp[swap]);
		}
	}

	for (i = 0; i < n; i+=1){
		printf("%s\n", str1[i]);
	}

	for (i = 0; i < m; i+=1){
		printf("%s\n", str2[i]);
	}	

	return 0;
}