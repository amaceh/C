#include <stdio.h>

int main(){
	int lin, star, col;

	printf("masukkan banyaknya bintang: \n");
	scanf("%d", &star);
	for (lin = 1; lin <= star; lin+=1){
		for (col = 1; col <= star; col+=1){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

/*
int main(){
	int lin, star, col;

	printf("masukkan banyaknya bintang: \n");
	scanf("%d", &star);
	for (lin = 1; lin <= star; lin+=1){
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}*/