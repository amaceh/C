#include <stdio.h>
#include <string.h>//library string

int main()
{
	char setering[50], setering2[50];
	int i;

	scanf("%s", &setering);
	scanf("%s", &setering2);
	
	//batasan dengan menggunakan panjang string
	// for (i = 0; i < strlen(setering); i+=1)
	// {
	// 	printf("%c\n", setering[i]);
	// }

	//cara penulisan setering2==setering untuk string
	// strcpy(setering2,setering);
	// printf("%s\n", setering2);

	//cara penulisan syarat if string
	if (strcmp(setering,setering2)==0)
	{
		printf("kedua string sama\n");
	}else{
		printf("kedua string berbeda\n");
	}
	return 0;
}	

/*

strcpy == string copy
strlen == string lenght
strcmp == membandingkan string, jika sama hasilnya nol
*/