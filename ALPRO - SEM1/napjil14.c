#include <stdio.h>

int main() {
	int a, b, c, d, e, f;//variabel setiap angka
	int gen1, gen2, gen3, gan1, gan2, gan3;
	//variabel tanda genap dan ganjil
	
	gan1=0;
	gan2=0;
	gan3=0;
	gen1=0;
	gen2=0;
	gen3=0;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	scanf("%d", &f);
	
	if (a % 2 ==0){
		if(gen1 == 0){
			gen1 = a;
		}else if(gen2 == 0){
			gen2 = a;
		}else if(gen3 == 0){
			gen3 = a;
		}
	}else{
		if(gan1 ==0){
			gan1 = a;
		}else if(gan2 == 0){
			gan2 = a;
		}else if(gan3 == 0){
			gan3 = a;
		}
	}

	if (b % 2 ==0){
		if(gen1 == 0){
			gen1 = b;
		}else if(gen2 == 0){
			gen2 = b;
		}else if(gen3 == 0){
			gen3 = b;
		}
	}else{
		if(gan1 ==0){
			gan1 = b;
		}else if(gan2 == 0){
			gan2 = b;
		}else if(gan3 == 0){
			gan3 = b;
		}
	}
	
	if (c % 2 ==0){
		if(gen1 == 0){
			gen1 = c;
		}else if(gen2 == 0){
			gen2 = c;
		}else if(gen3 == 0){
			gen3 = c;
		}
	}else{
		if(gan1 ==0){
			gan1 = c;
		}else if(gan2 == 0){
			gan2 = c;
		}else if(gan3 == 0){
			gan3 = c;
		}
	}

		if (d % 2 ==0){
		if(gen1 == 0){
			gen1 = d;
		}else if(gen2 == 0){
			gen2 = d;
		}else if(gen3 == 0){
			gen3 = d;
		}
	}else{
		if(gan1 ==0){
			gan1 = d;
		}else if(gan2 == 0){
			gan2 = d;
		}else if(gan3 == 0){
			gan3 = d;
		}
	}

	if(e % 2 ==0){
		if(gen1 == 0){
			gen1 = e;
		}else if(gen2 == 0){
			gen2 = e;
		}else if(gen3 == 0){
			gen3 = e;
		}
	}else{
		if(gan1 ==0){
			gan1 = e;
		}else if(gan2 == 0){
			gan2 = e;
		}else if(gan3 == 0){
			gan3 = e;
		}
	}

	if(f % 2 ==0){
		if(gen1 == 0){
			gen1 = f;
		}else if(gen2 == 0){
			gen2 = f;
		}else if(gen3 == 0){
			gen3 = f;
		}
	}else{
		if(gan1 ==0){
			gan1 = f;
		}else if(gan2 == 0){
			gan2 = f;
		}else if(gan3 == 0){
			gan3 = f;
		}
	}

	if(gen1 != 0 && gen2 !=0 && gen3 !=0 
		&& gan1 !=0 && gan2 !=0 && gan3 !=0){
		printf("%d\n", gen1);
		printf("%d\n", gan1);
		printf("%d\n", gen2);
		printf("%d\n", gan2);
		printf("%d\n", gen3);
		printf("%d\n", gan3);
	}else{
		printf("tidak valid\n");
	}
	return 0;
}