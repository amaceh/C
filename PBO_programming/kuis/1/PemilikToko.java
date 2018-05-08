/*
PemilikToko
- noKTP
- nama
- kodeToko
*/
class PemilikToko{
	private String noKTP, nama, kodetoko;
	PemilikToko(){

	}
	//set get method
	public void setNoKTP(String noKTP){
		this.noKTP = noKTP;
	}
	public String getNoKTP(){
		return this.noKTP;
	}
	public void setNama(String nama){
		this.nama = nama;
	}
	public String getNama(){
		return this.nama;
	}
	public void setKodeToko(String kodetoko){
		this.kodetoko = kodetoko;
	}
	public String getKodeToko(){
		return this.kodetoko;
	}
}