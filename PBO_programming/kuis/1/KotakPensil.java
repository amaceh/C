/*
class KotakPensil
- kode <ada di alatTulis>
- nama <ada di alatTulis>
- bahan
- bentuk
- keterangan
- harga
*/

class KotakPensil extends AlatTulis{
	private String bahan, bentuk, keterangan;
	private int harga;

	KotakPensil(){

	}
	//set get method
	
	public void setBahan(String bahan){
		this.bahan = bahan;
	}
	public String getBahan(){
		return this.bahan;
	}

	public void setBentuk(String bentuk){
		this.bentuk = bentuk;
	}
	public String getBentuk(){
		return this.bentuk;
	}

	public void setKeterangan(String keterangan){
		this.keterangan = keterangan;
	}
	public String getKeterangan(){
		return this.keterangan;
	}

	public void setHarga(int harga){
		this.harga = harga;
	}
	public int getHarga(){
		return this.harga;
	}
}