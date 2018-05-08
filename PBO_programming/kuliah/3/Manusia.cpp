class Manusia
{
private:
	string nama, alamat, no_ktp, no_telepon;
public:
	Manusia(){

	};

	void setNama(string nama){
		this->nama=nama;
	}
	string getNama(){
		return this->nama;
	}
	void setAlamat(string alamat){
		this->alamat=alamat;
	}
	string getAlamat(){
		return this->alamat;
	}
	void setKTP(string no_ktp){
		this->no_ktp=no_ktp;
	}
	string getKTP(){
		return this->no_ktp;
	}
	void setTelepon(string no_telepon){
		this->no_telepon=no_telepon;
	}
	string getTelepon(){
		return this->no_telepon;
	}
	~Manusia(){
		
	};
	
};