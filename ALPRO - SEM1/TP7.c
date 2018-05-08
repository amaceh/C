#include <stdio.h>
#include <string.h>

int main(){
	
	char in[100], del[100];
	int i,j,k,count=0, x=0;

	strcpy(in, "nanananananonanox");
	strcpy(del, "nana");

	int len=strlen(in);
	int lendel=strlen(del);

	for (i = 0; i < len; i+=1){
		for (j = i; j < i+lendel; j+=1){

			if (in[j]==del[x]){
				count+=1;
			}
			x+=1;
			if (count==lendel){
				for (k = i; k < lendel; k+=1){
					in[k]=in[k+lendel];
				}
			}
		}
		x=0;
		count=0;
	}
	printf("%s\n", in);
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