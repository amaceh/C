class titik
{
private:
	int x, y;
public:
	titik(){
		x=0;
		y=0;
	};

	titik(int xp, int yp){
		x=xp;
		y=yp;
	}

	void setX(int xp){
		x=xp;
	}
	void setY(int yp){
		y=yp;
	}

	int getX(){
		return x;
	}

	int getY(){
		return y;
	}
	~titik(){};
	
};