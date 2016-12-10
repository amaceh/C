#include <stdio.h>
#include <string.h>

int main(){
	
	char input[100], a[]="tango", 
	b[]="AQUA", c[]="gehu", end[]="sudah";
	int total=0, cek=1;

	while(cek != 0){
		scanf(" %s", &input);
		if(strcmp(input, end)==0){
			cek=0;
		}else if (strcmp(input, a)==0)
		{
			total=total+1000;
		}else if (strcmp(input, b)==0)
		{
			total=total+3000;
		}else if (strcmp(input, c)==0)
		{
			total=total+500;
		}
	}

	printf("%d\n", total);
	return 0;
}	