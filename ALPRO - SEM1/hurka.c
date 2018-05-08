#include <stdio.h>

int main () {
	//enam kotak karakter
	char ca, cb, cc, cd, ce, cf;

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
	//memeriksa angka
	if((ca == '1') || (ca == '2') 
		|| (ca == '3') || (ca == '4') 
		|| (ca == '5')|| (ca == '6') 
		|| (ca == '7')|| (ca == '8')
		|| (ca == '9')|| (ca == '0')){			
			a=1;
		}else{
			az=1;
		}
	//periksa huruf
	if((cb != '1') && (cb != '2') 
		&& (cb != '3') && (cb != '4') 
		&& (cb != '5') && (cb != '6') 
		&& (cb != '7') && (cb != '8') 
		&& (cb != '9') && (cb != '0')){
			b=1;
		}else{
			bz=1;
		}
	//memeriksa angka
	if((cc == '1') || (cc == '2') 
		|| (cc == '3') || (cc == '4') 
		|| (cc == '5') || (cc == '6') 
		|| (cc == '7') || (cc == '8') 
		|| (cc == '9') || (cc == '0')){			
			c=1;
		}else{
			cz=1;
		}
	//memeriksa huruf
	if((cd != '1') && (cd != '2') 
		&& (cd != '3') && (cd != '4') 
		&& (cd != '5') && (cd != '6') 
		&& (cd != '7') && (cd != '8') 
		&& (cd != '9') && (cd != '0')){
			d=1;
		}else{
			dz=1;
		}
	//memeriksa huruf
	if((ce == '1') || (ce == '2') 
		|| (ce == '3') || (ce == '4') 
		|| (ce == '5') || (ce == '6') 
		|| (ce == '7') || (ce == '8') 
		|| (ce == '9') || (ce == '0')){			
			e=1;
		}else{
			ez=1;
		}
	//memeriksa angka
	if((cf != '1') && (cf != '2') 
		&& (cf != '3') && (cf != '4') 
		&& (cf != '5') && (cf != '6') 
		&& (cf != '7') && (cf != '8') 
		&& (cf != '9') && (cf != '0')){
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
