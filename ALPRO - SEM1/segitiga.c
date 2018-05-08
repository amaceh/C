#include <stdio.h>

int main (){
	//kotak sisi segitiga
	int a, b, c;
	//meminta masukkan user untuk ketiga sisi
	printf("masukkan tiap sisi segitiga\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	//mengolah data
	if(a == b == c){
		printf("segitiga tersebut sama sisi");
	}else if (((a == b) && (a |= c)) 
		|| ((a == c) && (a |= b)) 
		|| ((b == c) && (b |= a))){
			printf("segitiga tersebut sama kaki");
	}else if(((a*a)+(b*b)==(c*c)) 
		|| ((a*a)+(c*c)==(b*b)) 
		|| ((c*c)+(b*b)==(a*a))){
			printf("segitiga tersebut siku-siku");
		}else{
			printf("segitiga tersebut sembarang");
		}
	return 0;
}
