#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
  char in[100];
  char del[100];


  scanf("%s", in);
  scanf("%s", del);

  int len = strlen(in);
  int dellen = strlen(del);
  int i, j, k, l, idx=0, pass = 0, heig=0;

  for (i = 0; i < len; i++) {
    for (j = 0; in[i + dellen * pass + j] == del[j]; j++) {
      if (j == dellen -1) {
        pass++;
      }
    }
    in[i] = in[i + dellen * pass ];
  }

  int len2=strlen(in);
printf("%s\n", in);
  for (i = 0; i < (len2/2)+1; i+=1)
  {
    for (j = 0; j < i; j+=1)
    {
      printf(" ");
    }
    printf("%c", in[i]);
    for (j = (len2/2); j > i+1; j-=1)
    {
      printf(" ");
    }
    for (j = (len2/2); j > i; j-=1)
    {
      printf(" ");
    }
    if(i !=len2/2){
    printf("%c", in[len2-i-1]);
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
      printf("%c", in[idx + k]);
    }
    printf("\n");
    idx += k;
  }

  return 0;
}