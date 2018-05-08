#include <iostream>
#include <string>
using namespace std;
#include "Manusia.cpp"
#include "Karyawan.cpp"

int main()
{
	Manusia m1;
	Karyawan k1;

	m1.setNama("Achmad");
	m1.setAlamat("Bandung");
	m1.setKTP("1503631");
	m1.setTelepon("083821146073");

	cout << m1.getNama() << endl;
	cout << m1.getAlamat() << endl;
	cout << m1.getKTP() << endl;
	cout << m1.getTelepon() << endl;

	k1.setNama("Cyka");
	k1.setAlamat("Blyat");
	k1.setKTP("6666");
	k1.setTelepon("69696969696");
	k1.setNoPegawai("12345");
	k1.setJabatan("General");
	k1.setDepartemen("Militer");	

	cout << k1.getNama() << endl;
	cout << k1.getAlamat() << endl;
	cout << k1.getKTP() << endl;
	cout << k1.getTelepon() << endl;
	cout << k1.getNoPegawai() << endl;
	cout << k1.getJabatan() << endl;
	cout << k1.getDepartemen() << endl;
	return 0;
}

