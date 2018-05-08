/*
class AlatTulis dengan attribut
- kode
- nama
- golongan
*/
class AlatTulis {
	//Attrubute
	private String kode, nama, golongan;
	//contructor
	AlatTulis(){

	}
	//set get method
	public void setKode(String kode){
		this.kode = kode;
	}
	public String getKode(){
		return this.kode;
	}
	public void setNama(String nama){
		this.nama = nama;
	}
	public String getNama(){
		return this.nama;
	}
	public void setGolongan(String golongan){
		this.golongan = golongan;
	}
	public String getGolongan(){
		return this.golongan;
	}
}