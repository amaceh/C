#include "head.h"

/*
Saya Achmad Abdul Rofiq tidak melakukan kecurangan 
yang dispesifikasikan pada tugas masa depan Alpro 2 
pada saat mengerjakan Tugas Masa Depan Alpro 2. 
Jika saya melakukan kecurangan maka Allah/Tuhan 
adalah saksi saya, dan saya bersedia menerima hukumanNya. 
Aamiin.
*/

int main()
{
	char map[500][500];//deklarasi array of char 2 dimensi
	int y=21, x=51, mapenergy[500][500];//deklarasi panjang dan lebar
	//juga array of int untuk menampung energi
	int stop=1, stopb2=1, show=1;//variabel penanda
	while(stop==1){
		if (show==1){//untuk tampilan pertama kali, 
			//munculkan animasi A cari makan 
			mapeditor(map, mapenergy, y ,x);
			stepdrawer(map, mapenergy, y, x);
		}else{
			//munculkan gambar peta saja
			mapeditor(map, mapenergy, y ,x);
			mapdrawer(map, mapenergy, y ,x);
		}
		show=0;
		//tampilan menu	
		printf("Menu:\n");
		printf("0. Panjang dan Lebar Papan\n");
		printf("1. Kelola Makanan\n");
		printf("2. Kelola Perjalanan\n");
		printf("3. A Cari Makan\n");
		printf("4. Keluar\n");
		printf("Masukkan Menu : ");
		int what;//var untuk meminta inputan
		scanf("%d", &what);
		if (what==0)
		{
			printf("tinggi (y) :");
			scanf("%d", &y);//
			x+=1;
			printf("lebar (x) :");
			scanf("%d", &x);
			y+=1;
		}else if (what==1)
		{
			foodmanager();
		}else if (what==2)
		{
			stepmanager();
		}else if (what==3)
		{
			show=1;
		}else if (what==4)
		{
			stop=0;
			system("exit");	
		}else{
			printf("Menu tidak valid\n");
			wait(1.5);
		}
		system("cls");	
	}
	return 0;
}