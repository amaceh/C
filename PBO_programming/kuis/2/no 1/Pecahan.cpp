#include "Pecahan.h"
//and here we declare every method with template
//and use datatyp P(template)
template <class P>
	Pecahan<P>::Pecahan(){
		//contruktor
		Pecahan<P>::numer=0;
		Pecahan<P>::denom=0;
	}

template <class P>
	Pecahan<P>::Pecahan(P numerp, P denomp){
		//contruktor
		Pecahan<P>::numer=numerp;
		Pecahan<P>::denom=denomp;
	}

//get set
template <class P>
	P Pecahan<P>::getNumer(){
		return Pecahan<P>::numer;
	}

template <class P>
	void Pecahan<P>::setNumer(P numerp){
		Pecahan<P>::numer = numerp;
	}

template <class P>
	P Pecahan<P>::getDenom(){
		return Pecahan<P>::denom;
	}

template <class P>
	void Pecahan<P>::setDenom(P denomp){
		Pecahan<P>::denom = denomp;
	}

template <class P>
	Pecahan<P>::~Pecahan(){
	}