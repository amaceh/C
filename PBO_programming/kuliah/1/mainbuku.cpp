#include "buku.cpp"

int main(){
	buku b1;
	b1.setJudul("J2ME");
	b1.setPengarang("Ane");

	cout << b1.getJudul() << endl;
	cout << b1.getPengarang() << endl;

	buku b2("Lala", "Ente");
	cout << b2.getJudul() << endl;
	cout << b2.getPengarang() << endl;
	return 0;
}