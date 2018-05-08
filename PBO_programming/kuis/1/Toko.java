/*
class Toko
- kode
- nama
- lokasi
*/
class Toko{
	private String kode, nama, lokasi;
	Toko(){

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
	public void setLokasi(String lokasi){
		this.lokasi = lokasi;
	}
	public String getLokasi(){
		return this.lokasi;
	}
}