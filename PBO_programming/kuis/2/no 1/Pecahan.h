//make template class
//with P(template) type data
//so we can use any datatype here
template <class P>
	class Pecahan{
	private:
		P numer, denom;
	public:
		Pecahan();
		Pecahan(P numerx, P denomx);
		P getNumer();
		void setNumer(P numerx);
		P getDenom();
		void setDenom(P denomx);
		~Pecahan();
	};