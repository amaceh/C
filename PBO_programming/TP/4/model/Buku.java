package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Buku extends DB{
	
	//need attribute to save id;
	private String kode=null;	
	public Buku() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	//get all record from DB
	public void getDaftarBuku(){
		try{
			String query = "SELECT * FROM daftar_buku";
			//get id, judul, and penulis
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}

	//insert a record to DB
	public void insertBuku(String judul, String penulis){
		try{
			String query = "INSERT INTO daftar_buku(judul_buku,penulis_buku) values ('"+judul+"','"+penulis+"')";
			createUpdate(query);
			//get inserted ID
			kode=getInsertedID();
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}

	//well, create update is a void method, 
	//using attribute to save id and make a "simple get method" save my time :)
	public String getId(){
		return kode;
	}

	//update a record
	public void updateBuku(String id, String judul, String penulis){//we need it id
		try{
			String query = "UPDATE daftar_buku SET judul_buku='"+judul+"', penulis_buku='"+penulis+"' WHERE kode_buku='"+id+"'";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}	

	//delete a record
	public void deleteBuku(String judul, String penulis){
		try{
			String query = "DELETE FROM daftar_buku where judul_buku='"+judul+"' and penulis_buku='"+penulis+"'";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}

	//delete all record
	public void deleteAllBuku(){
		try{
			//in mysql, delele record in a table called truncate
			String query = "TRUNCATE TABLE daftar_buku";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}