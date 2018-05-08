/*
class RekapitulasiPendapatan
- noKTP
- kodeToko
- bulan
- total
- untung
- modal
*/

class RekapitulasiPendapatan{
	private String noKTP, kodetoko; 
	private int bulan, total, untung, modal;
	RekapitulasiPendapatan(){

	}
	//set get method
	
	public void setNoKTP(String noKTP){
		this.noKTP = noKTP;
	}
	public String getNoKTP(){
		return this.noKTP;
	}
	public void setKodeToko(String kodetoko){
		this.kodetoko = kodetoko;
	}
	public String getKodeToko(){
		return this.kodetoko;
	}

	public void setbulan(int bulan){
		this.bulan = bulan;
	}
	public int getbulan(){
		return this.bulan;
	}
	public void setTotal(int total){
		this.total = total;
	}
	public int getTotal(){
		return this.total;
	}
	public void setUntung(int untung){
		this.untung = untung;
	}
	public int getUntung(){
		return this.untung;
	}

	public void setModal(int modal){
		this.modal = modal;
	}
	public int getModal(){
		return this.modal;
	}
}