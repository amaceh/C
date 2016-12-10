#include "EVDAM.h"//panggil header
#include "wmachine.h"//panggil mesin kata
/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan EVDAM evaluasi 2,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	char businput[250], name[30];//pita, string penampung
	bus chair[250];//arr of bungkusan berisi kursi
	int i=1, counter[2];//counter
	counter[0]=0;//saya cuma pakai 1 saja (mengakali prosedur karena saya belum bisa pointer)
	while(i==1){//endless loop, user input sebanyak-banyaknya
		flushfile(counter[0], chair);//flush file
		readfile(counter, chair);//membaca file
		//saya memulainya tanpa file.
		//jika program dimulai dengan file yg sudah ada, 
		//maka prosedur flush harus di pindahkan di akhir loop. 
		scanf(" %249[^\n]s", businput);//meminta input
		STARTKATA(businput);//mulai pembacaan pita
		strcpy(name, GETCKATA());//simpan dulu namanya
		if(EOPKATA(businput)!=1){INCKATA(businput);}//lanjutkan bila belum EOP
		if (strcmp(GETCKATA(businput), "duduk")==0)//jika kalimat berikutnya duduk
		{
			//karena di soal kalimat selalu statis, maka saya asumsikan input selalu begini
			if(EOPKATA(businput)!=1){INCKATA(businput);}//"di"
			if(EOPKATA(businput)!=1){INCKATA(businput);}//"sebelah"
			if(EOPKATA(businput)!=1){INCKATA(businput);}//maju lagi
			if (strcmp(GETCKATA(), "kanan")==0)//jika kalimatnya kanan
			{
				if(EOPKATA(businput)!=1){INCKATA(businput);}//maju lagi untuk nama 2
				if (searchleft(counter[0], chair, GETCKATA())==0)//cari apakah dikiri ada nama 2
				{
					changekosong(counter[0], chair, name, GETCKATA());//kalau ada isi sajah.
				}else{//kalau tidak ada saya asumsikan mereka duduk berdampingan
					strcpy(chair[counter[0]].left, GETCKATA());
					strcpy(chair[counter[0]].right,name);	
					counter[0]+=1;
				}
			}else if (strcmp(GETCKATA(), "kiri")==0){//jika kalimatnya kiri
				if(EOPKATA(businput)!=1){INCKATA(businput);}//maju lagi untuk nama 2
				if (searchright(counter[0], chair, GETCKATA())==0)
				{
					changekosong(counter[0], chair, name, GETCKATA());//kalau ada isi sajah.
				}else{//kalau tidak ada saya asumsikan mereka duduk berdampingan
					strcpy(chair[counter[0]].left,name);
					strcpy(chair[counter[0]].right,GETCKATA());	
					counter[0]+=1;
				}
			}else if (strcmp(GETCKATA(), "depan")==0){//jika kalimatnya depan
				if(EOPKATA(businput)!=1){INCKATA(businput);}//maju untuk nama 2
				if (searchright(counter[0], chair, GETCKATA())==0 ||
					searchright(counter[0], chair, GETCKATA())==0)//cari apakah nama 2 ada(baik dikiri maupun dikanan)
				{
					changekosong2(counter[0], chair, name, GETCKATA(),-1);//jika ada tinggal isi sajah
				}else{//untuk depan saya harus bertanya pada user, mau ditambahkah, lalu dikiri atau dikanan
					printf("nama %s tidak ada, mau ditambah di barisan baru\n1. ya 2.tidak\n", GETCKATA());	
					int req1; scanf("%d", &req1);
					if (req1==1)
					{
						printf("lalu mau di kanan (1) atau dikiri (2)? ");
						int req2; scanf("%d", &req2);
						if (req2==1)//jika dikanan
						{
							strcpy(chair[counter[0]].right,name);
							strcpy(chair[counter[0]].left,"kosong");
							counter[0]+=1;
							strcpy(chair[counter[0]].right,GETCKATA());
							strcpy(chair[counter[0]].left,"kosong");
							//counter[0]+=1;
						}else if (req2==2)//jiki dikiri
						{
							strcpy(chair[counter[0]].left,name);
							strcpy(chair[counter[0]].right,"kosong");
							counter[0]+=1;
							strcpy(chair[counter[0]].left,GETCKATA());
							strcpy(chair[counter[0]].right,"kosong");
							//counter[0]+=1;
						}
					}
					counter[0]+=1;
				}
			}
			else if (strcmp(GETCKATA(), "belakang")==0){//jika kalimatnyabelakang
				if(EOPKATA(businput)!=1){INCKATA(businput);}//maju untuk nama 2
				if (searchright(counter[0], chair, GETCKATA())==0 ||
					searchright(counter[0], chair, GETCKATA())==0)//cari apakah nama 2 ada(baik dikiri maupun dikanan)
				{
					changekosong2(counter[0], chair, name, GETCKATA(),1);//jika ada tinggal isi sajah
				}else{//untuk depan saya harus bertanya pada user, mau ditambahkah, lalu dikiri atau dikanan
					printf("nama %s tidak ada, mau ditambah di barisan baru\n1. ya 2.tidak\n", GETCKATA());	
					int req1; scanf("%d", &req1);
					if (req1==1)//jika dikanan
					{
						printf("lalu mau di kanan (1) atau dikiri (2)? ");
						int req2; scanf("%d", &req2);
						if (req2==1)
						{
							strcpy(chair[counter[0]].right,GETCKATA());
							strcpy(chair[counter[0]].left,"kosong");
							counter[0]+=1;
							strcpy(chair[counter[0]].right,name);
							strcpy(chair[counter[0]].left,"kosong");
							//counter[0]+=1;
						}else if (req2==2)//jika dikiri
						{
							strcpy(chair[counter[0]].left,GETCKATA());
							strcpy(chair[counter[0]].right,"kosong");
							counter[0]+=1;
							strcpy(chair[counter[0]].left,name);
							strcpy(chair[counter[0]].right,"kosong");
							//counter[0]+=1;
						}
					}
			}
		}
		else if(strcmp(GETCKATA(), "turun")==0){//jika kata yang diinpu turun
			toKosong(counter[0], chair, name);//jalankan prosedur turun.
		}
		else if(strcmp(GETCKATA(), "dan")==0){//jika kata berikutnya dan(kalimat seterusnya abaikan saja, toh input tidak macam2)
			if(EOPKATA(businput)!=1){INCKATA(businput);}//maju
			strcpy(chair[counter[0]].left, name);//masukkan nama pertama
			strcpy(chair[counter[0]].right, GETCKATA());//lalu nama kedua
			counter[0]+=1;
		}
		//flushfile(counter[0], chair);//nah disini bila yang diinginkan adalah membaca file
	}
	return 0;
}