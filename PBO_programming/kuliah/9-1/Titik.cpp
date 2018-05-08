class Titik3D;
class Titik{
	private:
	int x; //koordinat X
	int y; //koordinat Y
	
	public:
	Titik(){
		//konstruktor
		x = 0;
		y = 0;
	}
	
	Titik(int xp, int yp){
		//konstruktor
		x = xp;
		y = yp;
	}
	void setX(int xp){
		//mengembalikan nilai x
		x = xp;
	}
	
	void setY(int yp){
		//mengembalikan nilai y
		y = yp;
	}
	
	friend void tampilkanTitik(Titik t1, Titik3D t2);
};