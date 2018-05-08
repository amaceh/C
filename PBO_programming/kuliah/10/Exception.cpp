namespace exception{
	struct error{
		const char *p;
		error(const char *q){
			p = q;
		}
	};
}

class Eksepsi{
public:
	Eksepsi(){
	/*konstruktor*/
	}
	void eksepsiThrowStandar(int kode){
		if(kode < 1){        
			throw exception::error("error code");
		}
	}
	void eksepsiThrowSendiri(int kode){
		if(kode < 1){
			throw exception::error("error");
		}
	}
	void eksepsiThrowIndexOutOfBounds(int jumlah, int index, int nilai, int *tab){
		if((jumlah-1) < index){
			throw exception::error("array index out of bounds");
		}
		else{
			(*tab) = nilai;
		}
	}
	~Eksepsi(){
	}

};