#include <stdio.h>
#include <string.h>

int main(){
	
	char in[100];
	int gen=0, gan=0, i, j, kali;

	scanf("%s", &in);
	for (i = 0; i < strlen(in); i+=1)
	{
		if(in[i]=='a' || in[i]=='i' || in[i]=='u'
			|| in[i]=='e' || in[i]=='o'){
			gen+=1;
		}else{
			gan+=1;
		}	
	}
	kali=gen*gan;
	
	if(kali%2==0){
		for (i = 0; i < kali/4; i+=1){
			for (j = kali/4; j > i; j-=1){
			printf(" ");
			}
			for (j = 0; j-1 < i*2; j+=1){
				printf("%c", in[j]);
			}
			printf("\n");
		}
	}//else{
	// 	for (i = 0; i < ; i+=1){
	// 		for (j = 0; j < ; j+=1){
				
	// 		}
	// 	}
	// }
	return 0;
}