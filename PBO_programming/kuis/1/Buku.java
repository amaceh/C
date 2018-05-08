/*
Buku
- kode
- nama
- keterangan
- banyakHalaman
- harga
*/

class Buku {
	private String kode, nama, keterangan;
	private int bnykHal, harga;
	Buku(){

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
	public void setKeterangan(String keterangan){
		this.keterangan = keterangan;
	}
	public String getKeterangan(){
		return this.keterangan;
	}

	public void setBnykHal(int bnykHal){
		this.bnykHal = bnykHal;
	}
	public int getBnykHal(){
		return this.bnykHal;
	}
	public void setHarga(int harga){
		this.harga = harga;
	}
	public int getHarga(){
		return this.harga;
	}
}