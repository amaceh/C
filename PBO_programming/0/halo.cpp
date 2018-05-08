#include <iostream>
#include <string>

using namespace std;

class halo{
	private:
		string kata;
	public:
		halo(){
			kata = "halo dunia";
		};
		void tulis(){
			cout << kata << endl;
		};
		~halo(){

		};
};		