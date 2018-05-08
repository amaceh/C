#include <stdio.h>
#include <string.h>

int main()
{
	char string[100];
	scanf("%s", string);

	int i, counter=0;
	char ganti;

	for (i = 0; i < strlen(string); ++i)
	{
		if (string[i] == 'a' || string[i] == 'i'
			|| string[i] == 'u' || string[i] == 'e'
			|| string[i] == 'o'){
			
			if (counter>9)
			{
				counter=counter % 10;
			}

			if (counter==0){
				ganti='0';
			}else if(counter==1){
				ganti='1';
			}else if(counter==2){
				ganti='2';
			}else if(counter==3){
				ganti='3';
			}else if(counter==4){
				ganti='4';
			}else if(counter==5){
				ganti='5';
			}else if(counter==6){
				ganti='6';
			}else if(counter==7){
				ganti='7';
			}else if(counter==8){
				ganti='8';
			}else if(counter==9){
				ganti='9';
			}

			string[i]=ganti;
			counter+=1;
		}
	}
printf("%s\n", string);
	return 0;
}	