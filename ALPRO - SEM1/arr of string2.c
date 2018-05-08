#include <stdio.h>
#include <string.h>

int main(){
	
	int n, i, j, status=1;
	scanf("%d", &n);
	char arr[n][50];
	for (i = 0; i < n; i+=1)
	{
		scanf("%s", &arr[i]);
	}

	i=0;
	while((i<n)&&(status==1)){
		int ada = 0;
		j = 0;
		while(j<strlen(arr[i]) && (ada==0)){
			if (arr[i][j]=='a')
			{
				ada=1;
			}else{
				j+=1;
			}
		}
		if (ada==0)
		{
			status=0;
		}else{
			i+=1;
		}
	}

	if(status==0){
		printf("tidak valid\n");
	}else{
		printf("valid\n");
	}
	
	return 0;
}	