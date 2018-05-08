#include <stdio.h>

int main () {
	//enam kotak karakter
	char ca;
	char cb;
	char cc;
	char cd;
	char ce; 
	char cf;

	//meminta masukan user untuk 6 kotak karakter
	scanf(" %c", &ca);
	scanf(" %c", &cb);
	scanf(" %c", &cc);
	scanf(" %c", &cd);
	scanf(" %c", &ce);
	scanf(" %c", &cf);

	//membuat dua kotak integer untuk penanda
	int a=0, b=0, c=0, d=0, e=0, f=0;
	int az=0, bz=0, cz=0, dz=0, ez=0, fz=0;
	int tanda1;
	int tanda2;
	//kombinasi pertama
	//memeriksa vokal
	if((ca == 'a') || (ca == 'i') 
		|| (ca == 'u') || (ca == 'e') 
		|| (ca == 'o')){			
			a=1;
		}else{
			az=1;
		}
	//periksa konsonan
	if((cb != 'a') && (cb != 'i') 
		&& (cb != 'u') && (cb != 'e') 
		&& (cb != 'o')){
			b=1;
		}else{
			bz=1;
		}
	//memeriksa vokal
	if((cc == 'a') || (cc == 'i') 
		|| (cc == 'u') || (cc == 'e') 
		|| (cc == 'o')){			
			c=1;
		}else{
			cz=1;
		}
	//memeriksa konsonan
	if((cd != 'a') && (cd != 'i') 
		&& (cd != 'u') && (cd != 'e') 
		&& (cd != 'o')){
			d=1;
		}else{
			dz=1;
		}
	//memeriksa vokal
	if((ce == 'a') || (ce == 'i') 
		|| (ce == 'u') || (ce == 'e') 
		|| (ce == 'o')){			
			e=1;
		}else{
			ez=1;
		}
	//memeriksa konsonan
	if((cf != 'a') && (cf != 'i') 
		&& (cf != 'u') && (cf != 'e') 
		&& (cf != 'o')){
			f=1;
		}else{
			fz=1;
		}
	
	//memeriksa memnuhi syarat atau tidak
	tanda1 = a + b + c + d + e + f;
	tanda2 = az + bz + cz + dz + ez + fz;
	if((tanda1 == 6) || (tanda2 == 6)){
		printf("kombinasi valid\n");
	}else{
		printf("kombinasi tidak valid\n");
	}
	return 0;
	}
