#include <iostream>
using namespace std;
#include  "Titik.cpp"
#include "Titik3D.cpp"

//fungsi friend
//bisa hanya satu masukan
void tampilkanTitik(Titik t1, Titik3D t2){
	//bisa mengakses atribut private
	cout << "Fungsi Friend" << endl;
	cout << "Titik : \nx : " << t1.x << "\ny : " << t2.y << "\nz : " << t2.getZ() << endl;
	cout << "------------------------------------------------" << endl;
}

int main(){
	Titik t1(28, 1);
	Titik3D t2(28, 1, 7);
	
	tampilkanTitik(t1, t2);
	
	return 0;
}