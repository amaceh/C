/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan maskar16 UAS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

/////mesin karakter
int indeks;
char cc;

//tombol start
void START(char pita[]){
	indeks=0;
	cc=pita[indeks];
}
//tombol maju(dengan spasi)
void INC(char pita[]){
	indeks++;
	cc=pita[indeks];
}
//tombol maju tanpa spasi
void ADV(char pita[]){
	indeks++;
	cc=pita[indeks];
	while((cc == ' ') && (EOP() == 0)){
		indeks++;
		cc=pita[indeks];
	}
}
//fungsi char skrg
char GETCC(){
	return cc;
}
//end of process
int EOP(){
	if(cc == '.'){
		return 1;
	}else{
		return 0;
	}
}
///////