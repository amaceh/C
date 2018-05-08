class Titik
{
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
	
	friend void SahabatTitik::printTitik(const Titik &t);
};

/*METODE FRIEND*/
void SahabatTitik::printTitik(const Titik &t)
{
	/*bisa akses atribut private dati Titik*/
	cout << "Metode Friend" << endl;
	cout << "Titik : x : " << t.x << " y : " << t.y << endl;
	cout << "-----------------------" << endl;
}