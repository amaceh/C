package controller;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

import model.DB;
import model.CitaCita;

/*
 *	Class ProsesCitaCita
 *	class yang digunakan untuk mengakses controller
 *	untuk menampilkan score pada tableview
 */

public class ProsesCitaCita{
	//list container
	private List<String[]> dftr = new ArrayList<String[]>();
	
	private String error;
	
	public ProsesCitaCita(){
		//konstruktor
	}
	
	public void prosesCita(){
		try{
			//buat object model
			CitaCita cta = new CitaCita();
			cta.getScore();//ambil data pemain dan score

			//lakukan iterasi hingga semua data terjelajahi
			while(cta.getResult().next()){
				//ambil username dan score
				String uname = cta.getResult().getString(2);
				String score = cta.getResult().getString(3);
				
				//tampung
				String[] temp= new String[2];
				temp[0] = uname;
				temp[1] = score;
				
				//lalu tambahkan ke list
				dftr.add(temp);
			}
			//tutup DB
			cta.closeResult();
			cta.closeConnection();
		}catch(Exception e){
			error = e.toString();
			System.out.println(error);
		}
		
	}
	
	//get set
	public int getJml(){
		return this.dftr.size();
	}
	
	//get container
	public List<String[]> getHasil(){
		return this.dftr;
	}
	
	public String getError(){
		return this.error;
	}
}