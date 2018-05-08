package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DB{
	//some attribute
	private String ConAddress = "jdbc:mysql://localhost/db_citacita?user=root&password=";
	private Statement stmt = null;
	private ResultSet rs = null;
	private Connection conn = null;

	// contructor
	public DB() throws Exception, SQLException{
		/*
		Method DB
		Konstruktor: Melakukan koneksi ke MySQL dan basis data
		Menerima masukan berupa string alamat koneksi ke MySQL dan basis data
		*/

		try{
			//i am using mariadb jdbc
			// Class.forName("org.mariadb.jdbc.Driver").newInstance();
			//mysql jdbc
			Class.forName("com.mysql.jdbc.Driver").newInstance();

			conn = DriverManager.getConnection(ConAddress);
			conn.setTransactionIsolation(conn.TRANSACTION_READ_UNCOMMITTED);
		}catch(SQLException e){
			throw e;
		}
	}

	public void createQuery(String Query) throws Exception, SQLException{
		/*
		method createQuery
		Mengeksekusi query tanpa mengubah isi data
		Menerima masukan harga string query
		*/

		try{
			stmt = conn.createStatement();
			// rs = stmt.executeQuery(Query);
			//double execute
			if(stmt.execute(Query)){
				rs = stmt.executeQuery(Query);
			}
		}catch(SQLException es){
			throw es;
		}
	}

	public void createUpdate(String Query)throws Exception, SQLException{
		/*
		method createQuery
		Mengeksekusi query yang mengubah isi data(update, insert, delete)
		Menerima masukan berupa string query
		*/

		try{
			stmt = conn.createStatement();
			int hasil = stmt.executeUpdate(Query);
		}catch(SQLException es){
			throw es;
		}
	}

	public ResultSet getResult() throws Exception{
		/*method getResult
		memberikan hasil query*/

		ResultSet Temp = null;
		try{
			return rs;
		}catch(Exception ex){
			return Temp;
		}
	}

	public void closeResult()throws SQLException, Exception{
		/*
		method closeresult
		menutup hubungan dari eksekusi query
		*/

		if(rs != null){
			try{
				rs.close();
			}catch(SQLException sqlEx){
				rs = null;
				throw sqlEx;
			}
		}
		if(stmt != null){
			try{
				stmt.close();
			}catch(SQLException sqlEx){
				stmt = null;
				throw sqlEx;
			}
		}
	}

	public void closeConnection()throws SQLException, Exception{
		/*
		method closeConnection
		menutup hubungan dengan MySQL dan Basis Data
		*/
		if(conn != null){
			try{
				conn.close();
			}catch(SQLException sqlEx){
				conn = null;
			}
		}
	}
}