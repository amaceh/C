#include "Titik.h"

template <class T>
	Titik<T>::Titik(){
		//contruktor
		Titik<T>::x=0;
		Titik<T>::y=0;
	}

template <class T>
	Titik<T>::Titik(int xp, int yp){
		//contruktor
		Titik<T>::x=xp;
		Titik<T>::y=yp;
	}

template <class T>
	int Titik<T>::getX(){
		return Titik<T>::x;
	}

template <class T>
	void Titik<T>::setX(int xp){
		return Titik<T>::x = xp;
	}

template <class T>
	int Titik<T>::getY(){
		return Titik<T>::y;
	}

template <class T>
	void Titik<T>::setY(int yp){
		return Titik<T>::y = yp;
	}

template <class T>
	Titik<T>::~Titik(){
	}