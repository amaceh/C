class Restoran{
	private String kode, jenis, pangsaPasar;
	Restoran(){

	}
	Restoran(String xkode, String xjenis, String xpangsaPasar){
		this.kode=xkode;
		this.jenis=xjenis;
		this.pangsaPasar=xpangsaPasar;
	}
	public void setKode(String xkode){
		this.kode=xkode;
	}
	public String getKode(){
		return this.kode;	
	}
	public void setJenis(String xjenis){
		this.jenis=xjenis;
	}
	public String getJenis(){
		return this.jenis;	
	}
	public void setPangsaPasar(String xpangsaPasar){
		this.pangsaPasar=xpangsaPasar;
	}
	public String getpangsaPasar(){
		return this.pangsaPasar;	
	}
}