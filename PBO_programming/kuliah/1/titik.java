class titik{
	private int x, y;

	titik(){
		x=0;
		y=0;
	}

	titik(int xp, int yp){
		x=xp;
		y=yp;
	}

	public void setX(int xp){
		x=xp;
	}
	public void setY(int yp){
		y=yp;
	}

	public int getX(){
		return x;
	}
	public int getY(){
		return y;
	}

	public void finalize(){
		
	}
}