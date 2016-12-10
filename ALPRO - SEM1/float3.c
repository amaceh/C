#include <stdio.h>
int main(){
	float a,b,c,d,e,f; //kotak angka 
	//meminta input kotak
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	scanf("%f", &e);
	scanf("%f", &f);
	//mengambil angka koma 1
	int wa=a*100;
	int xa=wa /1000;
	int ya=(wa/100)-(xa*10);
	int za=(wa/10)-(xa*100)-(ya*10);
	//mengambil angka koma 2
	int wb=b*100;
	int xb=wb/1000;
	int yb=(wb/100)-(xb*10);
	int zb=(wb/10)-(xb*100)-(yb*10);
	//mengambil angka koma 3
	int wc=c*100;
	int xc=wc/1000;
	int yc=(wc/100)-(xc*10);
	int zc=(wc/10)-(xc*100)-(yc*10);
	//mengambil angka koma 4
	int wd=d*100;
	int xd=wd/1000;
	int yd=(wd/100)-(xd*10);
	int zd=(wd/10)-(xd*100)-(yd*10);
	//mengambil angka koma 5
	int we= e * 100;
	int xe=we / 1000;
	int ye=(we/100)-(xe*10);
	int ze=(we/10)-(xe*100)-(ye*10);
	//mengambil angka koma 6
	int wf=f*100;
	int xf=wf/1000;
	int yf=(wf/100)-(xf*10);
	int zf=(wf/10)-(xf*100)-(yf*10);
	
	//membuat integer penanda
	int aa=0, bb=0, cc=0, dd=0, ee=0,ff=0;
	int validasi;//kotak validasi
	
	//mengecek apakah angka kelipatan 3 atau bukan
	if((za % 3 ==0) && (za|=0)){
		aa=1;
	}
	if((zb % 3 ==0) && (zb|=0)){
		bb=1;
	}
	if((zc % 3 ==0) && (zc|=0)){
		cc=1;
	}
	if((zd % 3 ==0) && (zd|=0)){
		dd=1;
	}
	if((ze % 3 ==0) && (ze|=0)){
		ee=1;
	}
	if((zf % 3 ==0) && (zf|=0)){
		ff=1;
	}
	//validasi angka
	validasi = aa + bb + cc + dd + ee + ff;
	
	if(validasi >= 3){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
return 0;
}
