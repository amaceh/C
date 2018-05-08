package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Telepon extends DB{
	
	private String kode_anggota; //kode anggota
	private String no_telepon; //no telp
	
	public Telepon() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	public void getDaftar_Anggota(){
		try{
			String query = "SELECT * FROM daftar_telepon";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	public void insertKontak(String kode, String telp){
		try{
			String query = "INSERT INTO daftar_telepon(kode_anggota,no_telp) values ('"+kode+"','"+telp+"')";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}