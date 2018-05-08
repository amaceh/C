template <class Masukan> void
	TulisMasukan(Masukan n){
		cout << "Masukan : " << n << endl;
	}

template <class A, class B>
	A keluaran (A n, B m){
		cout << "keluaran 2 tipe" << n << m << endl;

		return n+m;
	}

template <class T>
	T keluaranO(T n){
		cout << "keluaran overloading" << n << endl;
		return n;
	}

template <class T>
	T keluaranO(T x, T y){
		cout << "keluaran overloading" << x << y << endl;
		return x*y;
	}