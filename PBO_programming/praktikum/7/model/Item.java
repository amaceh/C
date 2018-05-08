package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class Item extends DB{
	private String name;
	private String price;
	private String sellprice;

	public Item() throws Exception, SQLException{
		super();
	}

	public void getItems(){
		try{
			String query = "SELECT * FROM tb_courier";
			createQuery(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}

	public void addItems(String name, int buy, int sell)throws SQLException, Exception{
		try { 
            
            // Statement st = conn.createStatement(); 
            // st.executeUpdate
            //String query = "SELECT * FROM tb_courier";
			createQuery("INSERT INTO tb_courier " + 
                "VALUES ('"+name+"','"+buy+"','"+sell+"')"); 

        } catch (Exception e) { 
            System.err.println(e.getMessage()); 
        } 
	}
}