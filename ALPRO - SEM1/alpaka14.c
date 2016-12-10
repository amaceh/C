#include <stdio.h>

int main() {
	char a, b, c, d, e, f;//variabel karakter
	char ang1, ang2, ang3, hur1, hur2, hur3;
	
	ang1='.';
	ang2='.';
	ang3='.';
	hur1='.';
	hur2='.';
	hur3='.';
	
	scanf("%c %c %c %c %c %c", &a, &b, &c, &d, &e, &f);
	
	if (a =='1' || a =='2' || a =='3' 
		|| a =='4' || a =='5' || a =='6'
		|| a =='7' || a =='8' || a =='9'
		|| a =='0'){
		if(ang1 == '.'){
			ang1 = a;
		}else if(ang2 == '.'){
			ang2 = a;
		}else if(ang3 == '.'){
			ang3 = a;
		}
	}else{
		if(hur1 == '.'){
			hur1 = a;
		}else if(hur2 == '.'){
			hur2 = a;
		}else if(hur3 == '.'){
			hur3 = a;
		}
	}

	if (b =='1' || b =='2' || b =='3' 
		|| b =='4' || b =='5' || b =='6'
		|| b =='7' || b =='8' || b =='9'
		|| b =='0'){
		if(ang1 == '.'){
			ang1 = b;
		}else if(ang2 == '.'){
			ang2 = b;
		}else if(ang3 == '.'){
			ang3 = b;
		}
	}else{
		if(hur1 == '.'){
			hur1 = b;
		}else if(hur2 == '.'){
			hur2 = b;
		}else if(hur3 == '.'){
			hur3 = b;
		}
	}

	if (c =='1' || c =='2' || c =='3' 
		|| c =='4' || c =='5' || c =='6'
		|| c =='7' || c =='8' || c =='9'
		|| c =='0'){
		if(ang1 == '.'){
			ang1 = c;
		}else if(ang2 == '.'){
			ang2 = c;
		}else if(ang3 == '.'){
			ang3 = c;
		}
	}else{
		if(hur1 == '.'){
			hur1 = c;
		}else if(hur2 == '.'){
			hur2 = c;
		}else if(hur3 == '.'){
			hur3 = c;
		}
	}

	if (d =='1' || d =='2' || d =='3' 
		|| d =='4' || d =='5' || d =='6'
		|| d =='7' || d =='8' || d =='9'
		|| d =='0'){
		if(ang1 == '.'){
			ang1 = d;
		}else if(ang2 == '.'){
			ang2 = d;
		}else if(ang3 == '.'){
			ang3 = d;
		}
	}else{
		if(hur1 == '.'){
			hur1 = d;
		}else if(hur2 == '.'){
			hur2 = d;
		}else if(hur3 == '.'){
			hur3 = d;
		}
	}

	if (e =='1' || e =='2' || e =='3' 
		|| e =='4' || e =='5' || e =='6'
		|| e =='7' || e =='8' || e =='9'
		|| e =='0'){
		if(ang1 == '.'){
			ang1 = e;
		}else if(ang2 == '.'){
			ang2 = e;
		}else if(ang3 == '.'){
			ang3 = e;
		}
	}else{
		if(hur1 == '.'){
			hur1 = e;
		}else if(hur2 == '.'){
			hur2 = e;
		}else if(hur3 == '.'){
			hur3 = e;
		}
	}

	if (f =='1' || f =='2' || f =='3' 
		|| f =='4' || f =='5' || f =='6'
		|| f =='7' || f =='8' || f =='9'
		|| f =='0'){
		if(ang1 == '.'){
			ang1 = f;
		}else if(ang2 == '.'){
			ang2 = f;
		}else if(ang3 == '.'){
			ang3 = f;
		}
	}else{
		if(hur1 == '.'){
			hur1 = f;
		}else if(hur2 == '.'){
			hur2 = f;
		}else if(hur3 == '.'){
			hur3 = f;
		}
	}

	if(ang1 != '.' && ang2 != '.' && ang3 !='.' 
		&& hur1 != '.' && hur2 !='.' && hur3 !='.'){
		printf("%c\n", hur1);
		printf("%c\n", ang1);
		printf("%c\n", hur2);
		printf("%c\n", ang2);
		printf("%c\n", hur3);
		printf("%c\n", ang3);
	}else{
		printf("tidak valid\n");
	}
	return 0;
}