#include <iostream>
#include <cstdio>
using namespace std;
#include "mesin.cpp"
#include "Titik.cpp"
#include "Tulis.cpp"

int main(int argc, char const *argv[])
{
	Titik<int> t1(28,1);
	string kata = "membahas template ";

	TulisMasukan(18);
	TulisMasukan(28.11);
	TulisMasukan("Prosedur TulisMasukan dengan masukkan string ");
	keluaran(11, 11.82);
	keluaran(9, 'A');
	keluaran(9.81, 'A');
	keluaranO('A');
	keluaranO(82.81);
	keluaranO(3.5);
	keluaranO(18.9, 28.11);

	cout << "t1 : x : " << t1.getX() << " y :" << t1.getY() << endl;

	Tulis<string> t(kata);
	return 0;
}
