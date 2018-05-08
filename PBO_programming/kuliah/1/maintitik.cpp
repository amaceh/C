#include <iostream>
#include "titik.cpp"
using namespace std;
/*fungsi main untuk mengetes kelas Titik*/
int main(){
	titik t1;
	titik t2(11, 9);
	t1.setX(18);
	t1.setY(28);
	cout << "t1 : nilai X :" << t1.getX() << endl;
	cout << "t1 : nilai Y :" << t1.getY() << endl;
	cout << "t2 : nilai X :" << t2.getX() << endl;
	cout << "t2 : nilai Y :" << t2.getY() << endl;
	return 0;
}