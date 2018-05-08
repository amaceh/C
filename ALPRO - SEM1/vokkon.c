#include <stdio.h>

int main () {
	//tiga kotak karakter
	char ca, cb, cc;

	//meminta masukan user untuk 3 kotak karakter
	scanf("%c %c %c", &ca, &cb, &cc);

	//membuat tiga kotak integer untuk penanda
	int a=0, b=0, c=0;

	//periksa konsonan
	if((ca != 'a') && (ca != 'i') 
		&& (ca |= 'u') && (ca != 'e') 
		&& (ca != 'o')){
			a=1;
		}
	//memeriksa vokal
	if((cb == 'a') || (cb == 'i') 
		|| (cb == 'u') || (cb == 'e') 
		|| (cb == 'o')){			
			b=1;
		}
	//memeriksa konsonan
	if((cc != 'a') && (cc != 'i') 
		&& (cc != 'u') && (cc != 'e') 
		&& (cc != 'o')){
			c=1;
		}
	//memeriksa memnuhi syarat atau tidak
	if((a == 1) && (b == 1) && (c==1)){
		printf("memenuhi syarat\n");
	}else{
		printf("tidak memenuhi syarat");
	}
	return 0;
	}
