#include <stdio.h>

int main () {
	//tiga kotak karakter
	char ca, cb, cc, cd, ce, cf;

	//meminta masukan user untuk 3 kotak karakter
	scanf("%c %c %c %c %c %c", &ca, &cb, &cc, &cd, &ce, &cf);

	//membuat int penanda
	int a=0, b=0, c=0, d=0, e=0, f=0;

	//periksa konsonan
	if((ca != 'a') && (ca != 'i') 
		&& (ca |= 'u') && (ca != 'e') 
		&& (ca != 'o')){
			a = 1;
		}
	if((cb != 'a') && (cb != 'i') 
		&& (cb |= 'u') && (cb != 'e') 
		&& (cb != 'o')){
			b = 1;
		}
	if((cc != 'a') && (cc != 'i') 
		&& (cc |= 'u') && (cc != 'e') 
		&& (cc != 'o')){
			c = 1;
		
		}
	if((cd != 'a') && (cd != 'i') 
		&& (cd |= 'u') && (cd != 'e') 
		&& (cd != 'o')){
			d = 1;
		}
	if((ce != 'a') && (ce != 'i') 
		&& (ce |= 'u') && (ce != 'e') 
		&& (ce != 'o')){
			e = 1;
		}
	if((cf != 'a') && (cf != 'i') 
		&& (cf |= 'u') && (cf != 'e') 
		&& (cf != 'o')){
			f = 1;
		}

	//memeriksa memnuhi syarat atau tidak
	if(a+b+c+d+e+f>3){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
	}
