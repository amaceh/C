#include <iostream>
#include <cstdio>

using namespace std;
#include "SparePart.cpp"
#include "FullBody.cpp"

//only this mthod have direct access to private attribute
void PrintRobot(SparePart s, FullBody f){
	//access private attribute the class, (without get method) 
	//this is what friend for
	int head = s.h2;//private
	int body = s.h1;//private
	int foot = s.len;//private
	int size = f.size;//private

	/*
	now print the robot
	-------
	|     |
	|     |
	-------
	   |
	   |
	   |
	-------
	//my robot might be weird, last time work
	*/
	//do robot printing
	for (int i = 0; i < foot; ++i)
	{
		printf("-");//use cstudio
	}
	printf("\n");

	for (int i = 0; i < head; ++i)
	{
		printf("|");
		for (int j = 0; j < foot-2; ++j)
		{
			printf(" ");
		}
		printf("|");
		printf("\n");
	}
	for (int i = 0; i < foot; ++i)
	{
		printf("-");//use cstudio
	}
	printf("\n");

	for (int i = 0; i < body; ++i)
	{
		for (int j = 0; j < foot/2; ++j)
		{
			printf(" ");
		}
		printf("|");
		printf("\n");
	}
	for (int i = 0; i < foot; ++i)
	{
		printf("-");//use cstudio
	}
	printf("\n");
	cout << "the size of the robot " << endl;
	printf("%d\n", size);
}

/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	Pemrograman Berbasis Object dalam mengerjakan Kuis 2,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin...
	*/

int main(int argc, char const *argv[])
{
	FullBody f1;//declare first class
	f1.setSize(5);//set value

	SparePart s1;//declare second class
	s1.setH1(f1.getSize());//set valeue
	s1.setH2(f1.getSize()/2);
	s1.setLen(f1.getSize()*2);

	PrintRobot(s1, f1);
	return 0;
}