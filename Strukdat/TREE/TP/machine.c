#include "head.h"//call header

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP8,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/
//prosedur membuat akar(buat pohon)
void makeTree(char nama[], int num, tree *T){
	simpul *node;//buat pointer
	node=(simpul *) malloc (sizeof (simpul));//alokasikan memori
	strcpy(node->nama,nama);//salin data
	node->num=num;//salin data
	node->right=NULL;//tidak punya anak
	node->left=NULL;
	(*T).root=node;//root menunjuk ke akar
}

//prosedur tambah tree di kanan
void addRight(char nama[], int num, simpul *root){
	if (root->right==NULL){//pastikan kosong
		simpul *node;//buat pointer
		node=(simpul *) malloc (sizeof (simpul));//alokasikan memori
		strcpy(node->nama,nama);//salin data
		node->num=num;//salin data
		node->right=NULL;//tidak punya anak
		node->left=NULL;
		root->right=node;//sambungkan dengan akar/parent
	}else{
		printf("node kanan sudah terisi\n");
	}
}

void addLeft(char nama[], int num, simpul *root){
	if (root->left==NULL){//pastikan kosong
		simpul *node;//buat pointer
		node=(simpul *) malloc (sizeof (simpul));//alokasikan memori
		strcpy(node->nama,nama);//salin data
		node->num=num;
		node->right=NULL;//tidak punya anak
		node->left=NULL;
		root->left=node;//sambungkan dengan akar/parent
	}else{
		printf("node kiri sudah terisi\n");
	}
}
/////////////////////////////////////////////////////
//prosedur membuat stack kosong
void CreateEmpty(stack *S){
	(*S).top = NULL;
}
//prosedur push stack
void push(char nama[], int sum, stack *S){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));//alokasikan memori
	strcpy(elmt->elmt.nama, nama);//isi kontainer
	elmt->elmt.sum=sum;//isi kontainer
	if((*S).top == NULL){//jika stack kosong
		elmt->next = NULL;
	}else{//jika tidak kosong
		elmt->next = (*S).top;
	}
	(*S).top = elmt;
	elmt = NULL;
}
//prosedur pop stack
void pop(stack *S){
	if((*S).top != NULL){
		//jika list kosong
		elemen *elmt = (*S).top;
		if((*S).top->next == NULL){//jika hanya terdiri dari 1 elemen
			(*S).top=NULL;
		}else{//jika tidak
			(*S).top= (*S).top->next;
			elmt->next=NULL;
		}
		free(elmt);//bebaskan memori
	}
}
//prosedur cetak stack
void printstack(stack *S){
	if((*S).top != NULL){//cek kosong atau tidak
		elemen *elmt = (*S).top;//inisiasi
		int sum = 0, i=0;//penampung
		while(elmt != NULL)//lakukan sampai bertemu null
		{
			if (strcmp(elmt->elmt.nama, "*****")!=0)//print nama selain tanda
			{
				printf("%s", elmt->elmt.nama);//print nama proyek
			}
			sum+=elmt->elmt.sum;//tambah waktunya
			pop(S);//langsung buang
			elmt = (*S).top;//iterasi
			if ((*S).top==NULL)//jika sudah habis
			{
				printf(" ");
			}else if(strcmp(elmt->elmt.nama, "*****")!=0){//print '-' selain tanda
				printf("-");
			}
			i+=1;
		}
		printf("%d %d\n", i, sum);//print totalnya
	}else{
		printf("Stack Kosong\n");
	}
}
//prosedur untuk mencari parent
void findParent(char nama[], char x[], int *y, simpul *root){
	if (root != NULL){//cek kosong atau tidak
		if ((root->right!=NULL && strcmp(root->right->nama,nama)==0)//cek apakah right atau left cocok 
			|| (root->left!=NULL && strcmp(root->left->nama,nama)==0)){
				// printf("%s\n", root->nama);
				strcpy(x, root->nama);//jika iya simpan
				*y=root->num;//simpan juga totalnya
		}else{//jika tidak cari terus
			findParent(nama, x, y, root->left);
			findParent(nama, x, y, root->right);	
		}
	}
}
//prosedur mencari data yang dicari
void findChild(char nama[], int *y, simpul *root){
	if (root != NULL){
		if (strcmp(root->nama,nama)==0){//cek jika cocok
			// printf("%s\n", root->nama);
			*y=root->num;//simpan
		}else{//cari terus
			findChild(nama, y, root->left);
			findChild(nama, y, root->right);	
		}
	}
}
//prosedur pencari parent sampai root
void trackName(char nama[], simpul *root, tree T, stack *S){
	if (strcmp(T.root->nama,nama)==0)//cek apakah root cocok atau tidak
	{
		push("Null", T.root->num, &(*S));//langsung saja push
	}else{//jika ada di anaknya
		char temp1[50], temp2[50];//temporary
		int temp3;
		//ambil dulu jumlahnya
		findChild(nama, &temp3, T.root);
		push("*****", temp3, S);//push ke stack, dengan tanda(nama pelaku tidak diprint)

		strcpy(temp1, nama);
		while(strcmp(temp1,T.root->nama)!=0){//cari parent sampai root
			findParent(temp1, temp2 ,&temp3, T.root);//cari parent
			strcpy(temp1, temp2);//lalu rubah temp2/iterasi
			// printf("%s\n", temp1);
			push(temp2, temp3, S);//lalu push
		}
	}
	printstack(S);//lalu cetak hasilnya

}

/*
4
Akbar
Nesa 
Euis
Hadi

Contoh Keluaran

Hadi-Nesa-Atik 4 66
Hadi 2 25
Hadi-Ando 3 52
Null 1 10

*/