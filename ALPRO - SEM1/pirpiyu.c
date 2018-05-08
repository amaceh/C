#include <stdio.h>
#include <string.h>

int main(){
	int i, j, k, len, idx=0;
	char in[100];

	
	scanf("%s", in);
	len=strlen(in);
	int line=0, ex=0, ex2=1;
	while(ex<len){
		ex+=ex2;
		ex2+=2;
		line+=1;
	}

	for (i = 1; i < len/2+1; i+=1){
		for (j = i; j < len/2; j+=1){
			printf("-");
		}
		printf("%c", in[idx]);
		idx+=1;		
		printf("\n");
	}
	for (i = len/2-1; i < len-1; i+=1){
		for (j = i; j >=len/2; j-=1){
			printf("-");
		}		
		printf("%c", in[idx]);
		idx+=1;
		printf("\n");
	}
	idx=0;


	for (i = 0; i < line; i+=1){
		for (j = line+1; j > i; j-=1){
     		printf(" ");//print spasi
     	}

	    for (k = 0; k < i*2+1; k+=1) {//loop untuk print piramid 
	      	if (idx<len){//jika belum habis maka akan di print
				printf("%c", in[idx]);
	      		idx+=1;
	      	}
      	}
    	printf("\n");
  	}
  return 0;
}	