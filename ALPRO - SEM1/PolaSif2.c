#include <stdio.h>
int main(){
	int lin, star, col;

	scanf("%d", &star);

	for (lin = 1; lin <= star-2; lin+=1){
		for (col = 1; col <= star; col+=1){
			printf(" ");
		}
		for (col = 1; col <= star; col+=1){
			printf("*");
		}
		for (col = 1; col <= star+1; col+=1){
			printf(" ");
		}
		for (col = 1; col <= star; col+=1){
			printf("*");
		}
		printf("\n");
	}
	for (lin = 1; lin <= star-1; lin+=1){
		for (col = 2; col <= lin; col+=1){
			printf("*");
		}
		for (col = 2; col <= star; col+=1){
			printf("*");
		}
		for (col = 2; col <= star+1; col+=1){
			printf("*");
		}
		for (col = 2; col <= star; col+=1){
			printf("*");
		}
		printf("\n");
	}
return 0;
}
/*
   ***    *** 
 *****     *** 
******      ***
   ***   ***
    *** *** 
     *****
   ***   ***
  ***     ***
 ***       ***

 */