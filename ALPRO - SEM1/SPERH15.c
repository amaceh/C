#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	algoritma dan pemrograman 1 dalam mengerjakan SPERH15 TP7,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin.

	*/
	
	char in[100], del[100];//string inputan dan kata yang akan dihapus
	int i,j,k,count=0, x=0, y=0,idx2=0, heig=0;
	//loop, counter penghapusan, loop tambahan, index piramida, tinggi piramida

	//meminta input kedua string
	scanf("%s", in);
	scanf("%s", del);
	
	//memasukkan panjang string
	int len=strlen(in);
	int lendel=strlen(del);

	for (i = 0; i < len; i+=1){
		for (j = i; j < i+lendel; j+=1){

			if (in[j]==del[x]){//jika salah satu char ke-j==char ke-x
				count+=1;//maka counter bertambah satu
			}
			x+=1;//penambah index x
			if (count==lendel){//jika counter sama dengan panjang string yang akan dihapus
				for (k = i; k < i+lendel; k+=1){
					in[k]='.';//maka char tersebut diganti dengan titik
				}
			}
		}
		x=0;//reset index x
		count=0;//reset counter
	}//akhir dari pengecekan
	char in2[100];//string kedua atau hasil hapusan
	for (i = 0; i < len; ++i){
		if(in[i]!='.'){//jika char ke i bukan titik
			in2[y]=in[i];//char tersebut ditambahkan ke string hasil
			y+=1;//index y
		}
	}
	in2[y]='\0';//penambahan null di akhir string
	printf("%s\n", in2);//print string
	///////////////////
	int len2=strlen(in2);//memasukkan panjang string
	  for (i = 0; i < (len2/2)+1; i+=1){//for untuk spasi
    	for (j = 0; j < i; j+=1){
      		printf(" ");//print spasi
    	}
    	printf("%c", in2[i]);//print garis char kiri
    	//for spasi ditengah
    	for (j = (len2/2); j > i+1; j-=1){
    		  printf(" ");//print spasi
   		}
    	for (j = (len2/2); j > i; j-=1){
     		 printf(" ");//print spasi
    	}
    if(i !=len2/2){//pengondisian agar char dibawah hanya satu
    printf("%c", in2[len2-i-1]);
    }
    printf("\n");
  }
  //penentuan tinggi piramid
  int heigtest=sqrt(len2);
  float heigtemp=sqrt(len2);
	if(heigtemp>heigtest){//jika string tidak membentuk segitiga sempurna
    	heig=heigtest+1;
  	}else{//jika sempurna
    	heig=heigtest;
  	}
  for (i = 0; i < heig; i+=1) {
    for (j = (len2/2); j > i; j-=1){
     		 printf(" ");//print spasi
    	}

    for (k = 0; k < i*2+1; k+=1) {//loop untuk print piramid 
      	if (idx2<len2){	//jika belum habis maka akan di print
      		printf("%c", in2[idx2]);
      		idx2+=1;
      	}
    }
    printf("\n");
  }


	return 0;	
}