template <class T>
	class Titik{
	private:
		int x, y;
	public:
		Titik();
		Titik(int xp, int yp);
		int getX();
		void setX(int xp);
		int getY();
		void setY(int yp);
		~Titik();
	};