#include <stdio.h>

int main(){	

	int lin, star, col;

	scanf("%d", &star);

	for (lin = 1; lin <= star-1; lin+=1){
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		for (col = star; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = star; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		for (col = 1; col <= star ; col+=1)
		{
			printf("*");	
		}
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		printf("\n");
	}
	for (lin = 1; lin <= star; lin+=1){
		for (col = star; col >= lin; col-=1){
			printf("*");
		}
		for (col = 1; col <= lin-1; col+=1){
			printf(" ");
		}
		for (col = 1; col <= lin-1; col+=1){
			printf(" ");
		}
		for (col = star; col >= lin; col-=1){
			printf("*");
		}
		for (col = 1; col <= star ; col+=1)
		{
			printf("*");	
		}
		for (col = star; col >= lin; col-=1){
			printf("*");
		}
		printf("\n");
	}
	for (lin = 1; lin <= star; lin+=1){
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		for (col = star; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = star; col-1 >= lin; col-=1){
			printf(" ");
		}
		for (col = 1; col <= lin; col+=1){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
/*

*    *****
**  *******
************
**  *******
*    *****
*    *
**  **
******

*        *******
**      *********
***    ***********
****  *************
********************
****  *************
***    ***********
**      *********
*        *******
*        *
**      **
***    ***
****  ****
**********

*          ********
**        **********
***      ************
****    **************
*****  ****************
************************
*****  ****************
****    **************
***      ************
**        **********
*          ********
*          *
**        **
***      ***
****    ****
*****  *****
************

*/