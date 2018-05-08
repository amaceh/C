#include <stdio.h>
int main(){
	float a; //kotak angka 
	//meminta input kotak
	scanf("%f", &a);
	//mengambil angka koma
	int wa=a*100;
	int xa=wa /1000;
	int ya=(wa/100)-(xa*10);
	int za=(wa/10)-(xa*100)-(ya*10);
	int sa=a-(xa*1000)-(ya*100)-(za*10);
	//mengolah angka
	if((za % sa == 0)){
		printf("valid");
	}else{
		printf("tidak valid");
	}
	
return 0;
}
