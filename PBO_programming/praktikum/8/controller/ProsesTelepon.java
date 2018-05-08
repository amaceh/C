package controller;

import java.io.*;
import model.DB;
import model.Telepon;

public class ProsesTelepon{
	
	private int jml;
	private String kode;
	private String telp;
	private String[][] daftar = new String[25][5];
	
	private String error;
	
	public ProsesTelepon(){
		//konstruktor
		this.jml = 0;
	}
	
	public void prosesTlp(){
		jml = 0;
		try{
			Telepon brg = new Telepon();
			brg.getDaftar_Anggota();
			
			while(brg.getResult().next()){
				
				String kode = brg.getResult().getString(1);
				String telp = brg.getResult().getString(2);
				
				daftar[jml][0] = kode;
				daftar[jml][1] = telp;
				
				jml++;
			}
			brg.closeResult();
			brg.closeConnection();
		}catch(Exception e){
			
			error = e.toString();
		}
		
	}
	
	public int getJml(){
		return this.jml;
	}
	
	public String[][] getHasil(){
		return this.daftar;
	}
	
	public String getError(){
		return this.error;
	}
	
	public void tambahAnggota(String a,String b){
		
		try{
			
			Telepon brg = new Telepon();
			brg.insertKontak(a, b);
			
			brg.closeResult();
			brg.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
		
	}
}