#include "head.h"//panggil lib dari header

/*
Saya Achmad Abdul Rofiq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

////////////////////mesin list
//////////////////////////////////

//deklarasi list kosong
void createList(list *L){
	(*L).first=NULL;
}

/*menghitung jumlah elemen*/
int countElement(list L){
	int hasil=0;

	if(L.first!=NULL){
		/*list tidak kosong*/
		elemen *elmt;
		/*inisialisasi*/
		elmt=L.first;
		while(elmt!=NULL){
			/*proses*/
			hasil=hasil+1;
			/*iterasi*/
			elmt=elmt->next;
		}
	}
	return hasil;
}

/*menambahkan di awal list*/
void addFirst(char amal[], list *L){
	elemen *baru;//buat pointer
	baru=(elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(baru->elmt.amal, amal);//copy data

	if((*L).first==NULL){//jika masih kosong
		baru->next=NULL;
	}else{//jika sudah berisi
		baru->next=(*L).first;
	}
	(*L).first=baru;//ubah pointer first ke elemen baru
	baru=NULL;
}

/*menambahkan di tengah list*/
void addAfter(elemen *prev, char amal[], list *L){
	elemen *baru;//buat pointer
	baru= (elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(baru->elmt.amal, amal);//salin data

	if(prev->next == NULL){//jika diakhir
		baru->next = NULL;
	}else{//jika bukan
		baru->next = prev->next;
	}
	prev->next = baru;//hubungkan pointer
	baru= NULL;
}

/*menambahkan di akhir list*/
void addLast(char amal[], list *L){
	if((*L).first == NULL){
		/*jika list adalah list kosong*/
		addFirst(amal, L);
	}else{
		/*jika list tidak kosong*/
		/*mencari elemen terakhir list*/
		elemen *prev= (*L).first;
		while(prev->next != NULL){
			/*iterasi*/
			prev= prev->next;
		}
		addAfter(prev, amal, L);
	}
}

/*menghapuskan elemen pertama*/
void delFirst(list *L){
	if((*L).first != NULL){
		/*jika list bukan list kosong*/
		elemen *hapus= (*L).first;
		if(countElement(*L) == 1){//jika data hanya 1
			(*L).first = NULL;
		}else{//jika tidak
			(*L).first = (*L).first->next;//geser first
			hapus->next = NULL;
		}
		free(hapus);//bebaskan memori
	}
}

/*menghapus elemen tengah*/
void delAfter(elemen *prev, list *L){
	elemen *hapus= prev->next;
	if(hapus!= NULL){
		if(hapus->next == NULL){//jika diakhir
			prev->next = NULL; 
		}else{//jika tidak
			prev->next = hapus->next;//geser pointer
			hapus->next = NULL;
		}
		free(hapus);//bebaskan memori
	}
}

/*menghapus elemen terakhir*/
void delLast(list *L){
	if((*L).first != NULL){
		/*jika list tidak kosong*/
		if(countElement(*L) == 1){
			/*list terdiri dari satu elemen*/
			delFirst(L);
		}else{
			/*mencari elemen terakhir list*/
			elemen *last = (*L).first;
			elemen *prev;
			while(last->next != NULL){
				/*iterasi*/
				prev= last;
				last = last->next;
			}
			delAfter(prev, L);
		}
	}
}

/*menampilkan isi list*/
void printElement(list L, int x){  
	if(L.first != NULL){
		/*jika list tidak kosong*/
		/*inisialisasi*/
		elemen *elmt = L.first;
		// int i = 1;

		while(elmt != NULL){
			/*proses*/
			int i;
			for (i = 0; i < x+1; i+=1){
				printf(" ");
			}//cetak dulu spasi
			//lalu isi data
			printf("%s\n", elmt->elmt.amal);
			/*iterasi*/
			elmt = elmt->next;
			// i = i + 1;
		}
	}
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/

////mesin N-ER Tree//
//////////////////////////////////
//prosedur buat tree
void makeTree(char c[], tree *T){
	simpul *node;//siapkan pointer
	node = (simpul *) malloc (sizeof(simpul));//alokasikan memori
	strcpy(node->nama,c);//salin data
	//belum punya anak
	node->sibling = NULL;
	node->child = NULL;
	(*T).root=node;
}

//prosedur tambah anak
void addChild(char c[], simpul *root){
	if (root!=NULL){
		//pastikan tidak kosong
		simpul *node;//siapkan pointer
		node = (simpul *) malloc (sizeof(simpul));//alokasikan memori
		strcpy(node->nama,c);//salin data
		node->child=NULL;//belum punya anak
		if (root->child==NULL){
			/* simpul baru itu anak pertama */
			node->sibling= NULL;//belum punya sibling
			root->child=node;//hubungkan dengan root
		}else{
			if (root->child->sibling==NULL){
				//jika anak kedua
				node->sibling=root->child;//hubungkan pointer sibling
				root->child->sibling=node;
			}else{
				//bukan anak ke dua
				//cari anak terakhir
				simpul *last = root->child;
				while(last->sibling!=root->child){
					last= last->sibling;
				}
				//lalu hubungkan dengan root serta siblingnya
				node->sibling=root->child;
				last->sibling=node;
			}
		}
	}
}
//fungsi cari simpul
simpul* findsimpul(char c[], simpul *root){
	simpul *hasil=NULL;//default
	if (root != NULL){//pastikan root tidak null
		if (strcmp(root->nama,c)==0){//jika cocok
			hasil = root;//hasil sudah ketemu
		}else{
			simpul *node = root->child;//buat pointer anak
			if (node != NULL){//pastikan tidak null
				if (node->sibling==NULL){
					//jika satu anak
					if (strcmp(node->nama,c)==0){//jika cocok
						hasil=node;
					}else{//jika tidak cari ke anaknya
						hasil=findsimpul(c, node);
					}
				}else{
					//jika banyak anak
					int ketemu=0;//tanda
					//cari sampai semua data dijelajahi, atau data sudah ditemukan
					while((node->sibling != root->child) && ketemu==0 && hasil == NULL){
						if (strcmp(node->nama,c)==0){//jika cocok
							hasil=node;//hasil ditemukan
							ketemu=1;//rubah tanda
						}else{
							hasil=findsimpul(c, node);//cari di anaknya
							node=node->sibling;//iterasi sibling
						}
					}
					//proses last
					if (ketemu==0 && hasil==NULL){//jika belum ketemu		
						if (strcmp(node->nama,c)==0){//jika cocok
							hasil=node;
						}else{//jika tidak cari di anak-anaknya
							hasil=findsimpul(c, node);
						}
					}
				}
			}
		}
	}
	return hasil;//kembalikan hasil pencarian
}

//prosedur cetak pohon secara preorder
void printTreePreOrder(simpul *root, simpul *troot, int x, int y, queue len){
	if (root!=NULL){//pastikan root tidak kosong
		if (root!=troot){//jika root bukan pada root paling atas(T.root)
			int i;
			printf("\n");//cetak jarak
			for (i = 0; i < x; i+=1){//cetak spasi
				printf(" ");
			}
			printf("|");//dan tanda anak
		}
		printf("%s\n", root->nama);//cetak nama
		printElement(root->bad, x);//cetak tanggung-jawab dahulu
		printElement(root->good, x);//lalu cetak amal baik
		
		elem *elmt = len.first;//pointer
		y+=1;//counter generasi
		int j=0;//idx
		while(elmt!=NULL && j<y){//cari pointer sesuai index generasi
			j+=1;
			if (j<y){
				elmt=elmt->next;
			}
		}
		if (j==y){//jika ada
			x+=elmt->elmt.len;//tambahkan panjang jarak spasi
			//sesuai generasinya
		}

		simpul *node = root->child;//pointer child

		if (node != NULL){
			if (node->sibling == NULL){//jika satu anak
				printTreePreOrder(node, troot, x, y,len);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					printTreePreOrder(node, troot, x, y,len);
					node=node->sibling;
				}
				//last proses
				printTreePreOrder(node, troot, x, y,len);
			}
		}
	}
}

//fungsi mencari kata terpanjang dari sebuah node
int findtheLongest(simpul *node, simpul *troot){
	int x;
	x=strlen(node->nama);
	//cek list tanggung jawab
	elemen *elmt=node->bad.first;//inisiasi
	if(elmt != NULL){
		/*jika list tidak kosong*/
		while(elmt != NULL){
			/*proses*/
			if (strlen(elmt->elmt.amal)>x){//jika ada yang lebih panjang
				x=strlen(elmt->elmt.amal);//ganti
			}
			/*iterasi*/
			elmt = elmt->next;
		}
	}
	//kemudian cek list amal baik
	elmt = node->good.first;//inisiasi lagi
	if(elmt != NULL){
		/*jika list tidak kosong*/

		while(elmt != NULL){
			/*proses*/
			if (strlen(elmt->elmt.amal)>x){//jika ada yang lebih panjang
				x=strlen(elmt->elmt.amal);//ganti
			}
			elmt = elmt->next;//iterasi
		}
	}
	//untuk spasi tambahan amal( tanda '|')
	if (node!=troot){//jika root bukan root paling awal (T.root)
		return x+1;
	}else{
		return x;
	}
}

//prosedur pengelola input
void Input(char str[], tree *T){
	int i;
	int len=strlen(str);//simpan panjang input
	char temp[50], temp2[50], temp3[10];
	int step=1, idx=0, x, y;
	for (i = 0; i < len; i+=1){//lakukan hingga semua terproses
		if (step==1){//ambil nama bapa
			temp[idx]=str[i];//salin ke tampungan
			idx+=1;//tambah indeks
			if (str[i+1]=='#'){//jika akan menemui tanda
				temp[idx]='\0';//beri nul di penampung
				idx=0;//reset indeks
				step+=1;//langkah berikutnya
				i+=1;//lewat satu char
			}
		}else if (step==2){//tampung nama anak
			temp2[idx]=str[i];//tampung tiap char
			idx+=1;
			if (str[i+1]=='#'){//jika akan menemui penanda
				temp2[idx]='\0';//beri nul
				idx=0;//reset indeks
				step+=1;//langkah berikutnya
				i+=1;//lewat satu char
			}
		}else if (step==3){//tampung jumlah tanggung jawab
			temp3[idx]=str[i];//tampung tiap char
			idx+=1;
			if (str[i+1]=='#'){//jika akan menemui tanda
				temp3[idx]='\0';//beri nul
				x=atoi(temp3);//tampung hasil(rubah ke int dahulu)
				idx=0;//reset indeks
				step+=1;//langkah berikutnya
				i+=1;//lewat satu char
			}
		}else if (step==4){//tampun jumlah amal baik
			temp3[idx]=str[i];//tampung tiap char
			idx+=1;
			if (str[i+1]=='\0'){//jika string sudah habis
				temp3[idx]='\0';//beri nul
				y=atoi(temp3);////tampung hasil(rubah ke int dahulu)
				i+=1;
			}
		}
	}
	addbyRoot(temp, temp2, x, y, T);//lalu masukkan ke tree inputan yang sudah diolah
}

void addbyRoot(char root[], char child[],int x, int y,tree *T){
	char amalan[50];//tampungan input
	int i;
	if (strcmp(root, "null")==0){//jika bapanya itu null(anak sebenarnya root)
		makeTree(child, T);//buat tree
		createList(&(*T).root->bad);//buat list tanggung jawab
		for (i = 0; i < x; i+=1){//input 
			scanf("%s", amalan);
			addLast(amalan, &(*T).root->bad);//langsung tambah di list
		}
		createList(&(*T).root->good);//buat list amal
		for (i = 0; i < y; i+=1){//input
			scanf("%s", amalan);
			addLast(amalan, &(*T).root->good);//langsung masukkan di list
		}
	}else if((*T).root!=NULL){//jika bukan root
		simpul *node=findsimpul(root, (*T).root);//cari pointer simpul ayahnya
		if (node!=NULL){//pastikan ada hasilnya
			addChild(child, node);//tambah anak
			node=findsimpul(child, node);//ambil simpu anak yang baru
			createList(&(*T).root->bad);//buat list tanggung jawab
			for (i = 0; i < x; i+=1){//tambah list tanggung jawab
				scanf("%s", amalan);
				addLast(amalan, &node->bad);//tambah ke list
			}
			createList(&(*T).root->good);//buat list amal
			for (i = 0; i < y; i+=1){//tambah list amal baik
				scanf("%s", amalan);
				addLast(amalan, &node->good);//langsung tambah ke list
			}
		}
	}
}
//prosedur pengubah isi list yang ada di dalam tree
void BadtoGood(list *L, list *L2, list *A, list *B){  
	int stat=0;//penada
	if((*L).first != NULL && (*A).first!=NULL){//pastikan tidak kosong
		int del;

		elemen *elmt = (*L).first;//inisiasi
		elemen *elmt2, *prev;
		while(elmt != NULL){//lakukan sampai akhir
		/*proses*/
			del=0;//reset
			elmt2 = (*A).first;//inisiasi
			while(elmt2 != NULL && elmt!=NULL){//lakukan sampai akhir
				del=0;//reset
				if (strcmp(elmt->elmt.amal, elmt2->elmt.amal)==0){//jika cocok
					stat=1;//ubah tanda(amal akan ditambah)
					del=1;//ubah tanda
					if (elmt==(*L).first){// jika diawal
						delFirst(L);
						elmt=(*L).first;
					}else{
						delAfter(prev, L);//jika bukan
						elmt=prev;
					}
				}
				elmt2 = elmt2->next;//iterasi
			}
			if (del!=1){//jika tanda tidak berubah
				prev = elmt;
				elmt = elmt->next;
			}
		}
		if (stat==1 && (*B).first!=NULL){//jika ada data yang dihapus
			elmt2 = (*B).first;
			while(elmt2 != NULL){//tambah setiap amal
			/*proses*/
				addLast(elmt2->elmt.amal, L2);
				elmt2 = elmt2->next;//iterasi
			}
		}
	}
}
//prosedur ubah pertanggung jawaban di tiap node
void Tobat(simpul *root, list *A, list *B){
	if (root!=NULL){
		// printf("%s\n", root->nama);
		BadtoGood(&root->bad, &root->good, A, B);//ubah di node root

		simpul *node= root->child;

		if (node != NULL){//lalu ke anak anakanya
			if (node->sibling == NULL){//jika satu anak
				Tobat(node, A, B);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					Tobat(node, A, B);
					node=node->sibling;
				}
				//last proses
				Tobat(node, A, B);
			}
		}
	}
}

/////////////////////////////////////////////
////////////////prosedur queue
//queue ksosong
void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;	
}
//prosedur menghitung panjang kata tiap generasi
void LentoQ(simpul *root, simpul *troot,queue *Len, int x){
	if (root!=NULL){
		int i;
		//inisiasi
		elem *elmt=(*Len).first;
		elem *prev=(*Len).first;
		for (i = 0; i < x; i+=1){
			int lens=findtheLongest(root, troot);
			if (elmt==NULL){//jika belum ada data sesuai generasi
				add(lens, x-1, Len);//tambah
			}else if(elmt!=NULL && elmt->elmt.idx==x-1){//jika sudah ada
				if (elmt->elmt.len<findtheLongest(root, troot)){
					//cek mana yang lebih panjang
					elmt->elmt.len=findtheLongest(root, troot);
				}
			}
			//kelola iterasi
			if (elmt!=NULL){
				prev=elmt;//mundur dahulu
				elmt=elmt->next;//maju lagi
			}else{//jika ada add data
				if (prev==NULL){//jika data pertama
					elmt=(*Len).first;
				}else{//jika bukan
					elmt=prev;
				}
				elmt=elmt->next;//iterasi
			}
		}
		x+=1;//tambah tanda generasi
		//lanjut ke generasi berikutna
		simpul *node= root->child;
		if (node != NULL)
		{
			if (node->sibling == NULL)
			{//jika satu anak
				LentoQ(node, troot,Len, x);
			}else{//jika banyak anak
				while(node->sibling != root->child){
					LentoQ(node, troot,Len, x);
					node=node->sibling;
				}
				//last proses
				LentoQ(node, troot,Len, x);
			}
		}
	}
}


////////////////////////mesin queue
//////////////////////////////////
//prosedur tambah data ke queue
void add(int len, int idx, queue *Q){
	elem *elmt;//siapkan pointer
	elmt=(elem *) malloc (sizeof (elem));//alokasikan memori
	elmt->elmt.len = len;//salin panjang data
	elmt->elmt.idx = idx;//salin data indeks

	elmt->next=NULL;
	if ((*Q).first==NULL){//jika data kosong
		(*Q).first=elmt;
	}else{//jika tidak
		(*Q).last->next=elmt;
	}
	(*Q).last=elmt;//sambungkan last
	elmt=NULL;
}

/////////////////////////////////////////////
/////////////////////////////////////