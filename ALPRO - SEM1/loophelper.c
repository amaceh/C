#include <stdio.h>
int main(){
	int lin, star, col;

	printf("masukkan banyaknya bintang: \n");
	scanf("%d", &star);

	for (lin = 1; lin <= 2*star; lin+=1){
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		for (col = star*2; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = star*2; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		for (col = star*2; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = star*2; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		printf("\n");
	}
	for (lin = 1; lin <= 2*star; lin+=1){
		
		for (col = 1; col <= (star*2)+1; col+=1){
			printf(" ");
		}
		for (col = 1; col <= star*3; col+=1){
			printf("*");
		}
		printf("\n");
		}
	for (lin = 1; lin <= star; lin+=1){
		for (col = 1; col <= star*4+1; col+=1){
			printf(" ");
		}
		for (col = star; col <= lin; col-=1){
			printf("*");
		}
		
		printf("\n");
		}
	return 0;
}
