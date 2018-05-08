#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int i, j, k, len, idx=0, heig;
	char in[100];

	scanf("%s", in);
	len=strlen(in);
  
  int heigtest=sqrt(len);
  float heigtemp=sqrt(len);
  if(heigtemp>heigtest){//jika string tidak membentuk segitiga sempurna
      heig=heigtest+1;
    }else{//jika sempurna
      heig=heigtest;
    }

	for (i = 0; i < heig; i+=1) {
    for (j = heig; j > i+1; j-=1){
     		 printf(" ");//print spasi
    	}

    for (k = 0; k < i*2+1; k+=1) {//loop untuk print piramid 
      	if (idx<len){	//jika belum habis maka akan di print
      		printf("%c", in[idx]);
      		idx+=1;
      	}
  }
    printf("\n");
  }
	return 0;
}	