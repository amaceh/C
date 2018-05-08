#include <iostream>
#include <cstdio>
using namespace std;
#include "Pecahan.cpp"

/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	Pemrograman Berbasis Object dalam mengerjakan Kuis 2,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin...
	*/

int main(int argc, char const *argv[])
{
	int menu;

	//double accept int, float and double itself
	//but my template can be declared as int, and float too
	//declare two template
	Pecahan<double> p1;
	Pecahan<double> p2;
	//just declare it, not use it (to show that template working)
	// Pecahan<float> p3;
	// Pecahan<float> p4;
	// Pecahan<int> p5;
	// Pecahan<int> p6;

	double input;

	//input and set
	cout << "masukkan penyebut pertama" << endl;
	scanf("%lf", &input);//cstudio, forget cin
	p1.setNumer(input);
	cout << "masukkan pembilang pertama" << endl;
	scanf("%lf", &input);
	p1.setDenom(input);	
	cout << "masukkan penyebut kedua" << endl;
	scanf("%lf", &input);
	p2.setNumer(input);
	cout << "masukkan pembilang kedua" << endl;
	scanf("%lf", &input);
	p2.setDenom(input);

	//multiply and add
	cout << "Menu :\npilih 1 untuk kali \npilih 2 untuk tambah" << endl;
	scanf("%d", &menu);
	double numer=0, denom=0;
	
	if (menu==1)
	{
		numer=p1.getNumer()*p2.getNumer();
		denom=p1.getDenom()*p2.getDenom();		
		cout<< "Penyebut " << numer <<endl;
		cout<< "Pembilang " << denom <<endl;
	}else if(menu==2){
		numer=p1.getNumer()+p2.getNumer();
		denom=p1.getDenom()+p2.getDenom();
		cout<< "Penyebut " << numer <<endl;
		cout<< "Pembilang " << denom <<endl;
	}
	return 0;
}