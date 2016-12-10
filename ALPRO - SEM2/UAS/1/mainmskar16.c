#include "mskar16.h"//panggil header
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan maskar16 UAS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
int main()
{
	char xstr[1000];//deklarasi string
	scanf("%999[^\n]s", &xstr);//scan string sampai enter
	int result=0;//variabel counter
	char x,y,z;//char x, y, z
	START(xstr);//mulai proses
	x=GETCC();//ambil char pertama
	INC(xstr);//maju
	y=GETCC();//ambil char berikutnya
	INC(xstr);//maju
	z=GETCC();//ambil char berikutnya

	while(EOP()!=1){//jika proses masih berjalan(belum EOP)
		if (x>='a' && x<='z' && y>='a' && y<='z'){//cek dulu x dan y huruf atau bukan
			if(x!='a' && x!='i' 
			&& x!='u' && x!='e' 
			&& x!='o'){//kemudian cek x konsonan atau bukan
				if(y=='a' || y=='i' 
				|| y=='u' || y=='e' 
				|| y=='o'){//lalu cek y huruf vokal bukan
				if (z>='0' && z<='9'){//terakhir cek z angka bukan
					result+=1;//jika semua memnuhi tambah hasil
					} 
				}
			}
		}
		//majukan karakter
		x=y;
		y=z;
		INC(xstr);
		z=GETCC();
	}
	printf("%d\n", result);//tampilkan hasil
	return 0;
}