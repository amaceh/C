#include<stdio.h>
float main(){
/*saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 1 dalam mengerjakan online judge ini,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/
	float a,b,c,d,e,f; //kotak angka 
	//memfloata input kotak
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	scanf("%f", &e);
	scanf("%f", &f);
	//mengambil angka koma 1
	float wa=a*100;
	float xa=wa /1000;
	float ya=(wa/100)-(xa*10);
	float za=(wa/10)-(xa*100)-(ya*10);
	float pa=wa-(xa*1000)-(ya*100)-(za*10);
	//mengambil angka koma 2
	float wb=b*100;
	float xb=wb/1000;
	float yb=(wb/100)-(xb*10);
	float zb=(wb/10)-(xb*100)-(yb*10);
	float pb=wb-(xb*1000)-(yb*100)-(zb*10);
	//mengambil angka koma 3
	float wc=c*100;
	float xc=wc/1000;
	float yc=(wc/100)-(xc*10);
	float zc=(wc/10)- (xc*100)-(yc*10);
	float pc=wc-(xc*1000)-(yc*100)-(zc*10);
	//mengambil angka koma 4
	float wd=d*100;
	float xd=wd/1000;
	float yd=(wd/100)-(xd*10);
	float zd=(wd/10)-(xd*100)-(yd*10);
	float pd=wd-(xd*1000)-(yd*100)-(zd*10);
	//mengambil angka koma 5
	float we= e * 100;
	float xe=we / 1000;
	float ye=(we/100)-(xe*10);
	float ze=(we/10)-(xe*100)-(ye*10);
	float pe=we-(xe*1000)-(ye*100)-(ze*10);
	//mengambil angka koma 6
	float wf=f*100;
	float xf=wf/1000;
	float yf=(wf/100)-(xf*10);
	float zf=(wf/10)-(xf*100)-(yf*10);
	float pf=wf-(xf*1000)-(yf*100)-(zf*10);
	
	
	printf ("%f %f %f %f %f %f\n", pa, pb, pc, pd, pe, pf);
return 0;
}