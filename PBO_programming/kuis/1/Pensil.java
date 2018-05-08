/*
class Pensil, mewarisi class alatTulis
- kode <dari AlatTulis>
- nama <dari AlatTulis>
- jenis (mekanik atau biasa)
- keterangan
- harga
*/

class Pensil extends AlatTulis {
	private String jenis, keterangan;
	private int harga;
	Pensil(){

	}
	//set get method
	
	public void setJenis(String jenis){
		this.jenis = jenis;
	}
	public String getJenis(){
		return this.jenis;
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