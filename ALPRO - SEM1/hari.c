#include <stdio.h>

int main (){
	int x;//variabel angka
	scanf("%d", &x);
	//menampilkan output
	if(x == 1){
		printf("senin\n");
	}
	if(x == 2){
		printf("selasa\n");
	}
	if(x == 3){
		printf("rabu\n");
	}
	if(x == 4){
		printf("kamis\n");
	}
	if(x == 5){
		printf("jumat\n");
	}
	if(x == 6){
		printf("sabtu\n");
	}
	if(x == 7){
		printf("minggu\n");
	}
	return 0;
}