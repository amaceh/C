#include <stdio.h>
#include <string.h>

int main(){
	
	char in[100];
	char kap[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char cil[]="abcdefghijklmnopqrstuvwxyz";
	int kapital=0, kecil=0, i, j;

	scanf("%s", &in);
	for (i = 0; i < strlen(in); i+=1)
	{
		for (j = 0; j < 26; j+=1)
		{
			if(in[i]==kap[j]){
				kapital+=1;
			}else if(in[i]==cil[j]){
				kecil+=1;
			}
		}
	}

	printf("Banyaknya huruf kapital : %d\n", kapital);
	printf("Banyaknya huruf kecil : %d\n", kecil);

	return 0;
}

/*
Mengunakan ASCII

if(in[i]>=65 && in[i]<=90){
	kapital+=1;
}else if(in[i]>=97 && in[i]<=122){
	kecil+=1;
}
*/