class Karyawan : public Manusia{

private:
	string no_pegawai, jabatan, departemen;
public:
	Karyawan(){
	};
	void setNoPegawai(string no_pegawai){
		this->no_pegawai=no_pegawai;
	}
	string getNoPegawai(){
		return this->no_pegawai;
	}
	void setJabatan(string jabatan){
		this->jabatan=jabatan;
	}
	string getJabatan(){
		return this->jabatan;
	}

	void setDepartemen(string departemen){
		this->departemen=departemen;
	}
	string getDepartemen(){
		return this->departemen;
	}
	~Karyawan(){
		
	};
	
};