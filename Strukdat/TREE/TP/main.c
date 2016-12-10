#include "head.h"

/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
Struktur Data dalam mengerjakan TP8,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.

*/

int main()
{
	tree T;
	makeTree("Hadi", 10, &T);//the root
	//isi kiri dulu
	addLeft("Ando", 20, T.root);
	addLeft("Euis", 22, T.root->left);
	addRight("Otun", 23, T.root->left);
	addLeft("Dodi", 30, T.root->left->right);
	addRight("Ebta", 12, T.root->left->right);
	//lalu kanan
	addRight("Nesa", 15, T.root);
	addLeft("Yeni", 25, T.root->right);
	addRight("Atik", 20, T.root->right);
	addLeft("Kiki", 25, T.root->right->right);
	addRight("Akbar", 21, T.root->right->right);

	//buat stack tampungan
	stack S;
	CreateEmpty(&S);//inisiasi empty stack

	int i, x;//iterasi, input
	scanf("%d", &x);//input jumlah kata
	char in[x][50];//inputan
	for (i = 0; i < x; i+=1)
	{
		scanf("%s", in[i]);
	}
	for (i = 0; i < x; i+=1)
	{
		trackName(in[i], T.root, T, &S);//cari parent-root dari tiap inputan
	}
	return 0;
}