package controller;

//this is our controller
import model.DB;
import model.Buku;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public class ProsesBuku{
	
	// private int jml;
	//i need to edit it using list, but next time then
	// container
	private List<String[]> dftr = new ArrayList<String[]>();
	// private String[][] daftar = new String[25][5];
	private String error, idin;
	
	public ProsesBuku(){
		//konstruktor
		// this.jml = 0;
	}
	
	//this method add DB content to container
	public void proses(){
		// jml = 0;
		try{
			//call the model
			Buku buuk = new Buku();
			buuk.getDaftarBuku();//get all record from DB
			
			while(buuk.getResult().next()){//do loop until the last result
				String id = Integer.toString(buuk.getResult().getInt(1));
				String judul = buuk.getResult().getString(2);
				String penulis = buuk.getResult().getString(3);
			
				String[] temp= new String[3];
				

				//add to container
				temp[0] = id;
				temp[1] = judul;
				temp[2] = penulis;
				dftr.add(temp);
			}
			//close connection
			buuk.closeResult();
			buuk.closeConnection();
		}catch(Exception e){	
			error = e.toString();
			System.out.println(error);
		}
		
	}

	public String getKode(){
		return idin;//get inserted ID
	}

	public int getJml(){
		return this.dftr.size();
	}
	
	//get container
	// public String[][] getHasil(){
	// 	return this.daftar;
	// }
	public List<String[]> getHasil(){
		return this.dftr;
	}
	//get err exception
	public String getError(){
		return this.error;
	}
	
	//method to add record to DB
	public void tambahBuku(String a,String b){
		
		try{
			//call the model
			Buku buuk = new Buku();
			buuk.insertBuku(a, b);
			//get inserted ID
			idin=buuk.getId();
			buuk.closeResult();
			buuk.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
		
	}

	//method to delete a record
	public void hapusBuku(String a,String b){
		
		try{
			//call the model
			Buku buuk = new Buku();
			buuk.deleteBuku(a, b);
			
			buuk.closeResult();
			buuk.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}	
	}

	//method to delete all record
	public void hapusSemuaBuku(){
		
		try{
			//call the model
			Buku buuk = new Buku();
			buuk.deleteAllBuku();
			
			buuk.closeResult();
			buuk.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}	
	}
	//method to update DB content
	public void ubahBuku(String i,String a,String b){
		
		try{
			//call the model
			Buku buuk = new Buku();
			//update
			buuk.updateBuku(i, a, b);
			
			buuk.closeResult();
			buuk.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}
}