#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	
	char in[100], del[100];
	int i,j,k,count=0, x=0, y=0,idx=0, heig=0;

	scanf("%s", in);
	scanf("%s", del);
	

	int len=strlen(in);
	int lendel=strlen(del);

	for (i = 0; i < len; i+=1){
		for (j = i; j < i+lendel; j+=1){

			if (in[j]==del[x]){
				count+=1;
			}
			x+=1;
			if (count==lendel){
				for (k = i; k < i+lendel; k+=1){
					in[k]='.';
				}
			}
		}
		x=0;
		count=0;
	}
	char in2[100];
	for (i = 0; i < len; ++i)
	{
		if (in[i]!='.'){
			in2[y]=in[i];
			y+=1;
		}
	}
	in2[y]='\0';
	printf("%s\n", in2);
	///////////////////
	int len2=strlen(in2);
	printf("%s\n", in2);
	  for (i = 0; i < (len2/2)+1; i+=1)
	  {
    	for (j = 0; j < i; j+=1)
    	{
      		printf(" ");
    	}
    printf("%c", in2[i]);
    	for (j = (len2/2); j > i+1; j-=1){
    		  printf(" ");
   		}
    	for (j = (len2/2); j > i; j-=1){
     		 printf(" ");
    	}
    if(i !=len2/2){
    printf("%c", in2[len2-i-1]);
    }
    printf("\n");
  }
  
  int heigtest=sqrt(len2);
  float heigtemp=sqrt(len2);
	if(heigtemp>heigtest){
    	heig=heigtest+1;
  	}else{
    	heig=heigtest;
  	}
  
  for (i = 0; i < heig; i+=1) {
    for (j = heig; j>i-1; j--) {
      printf(" ");
    }
    for (k = 0; k < i*2+1; k+=1) {
      printf("%c", in2[idx + k]);
    }
    idx += k;
    printf("\n");
  }


	return 0;	
}

/*
adakaukukantaubelumpernahtauk
tau
adakaukukanbelumpernahk

  a
 kud
andia

     1
    234
   56789
  0123456
 789012345
67890
*/