package model;

import java.sql.SQLException;

public class CitaCita extends DB{
	
	public CitaCita() throws Exception, SQLException{
		//konstruktor
		super();
	}
	
	//method untuk mengabil semua score pemain diurutkan dari nilai tertinggi
	public void getScore(){
		try{
			//query
			String query = "SELECT * FROM top_player ORDER BY score DESC";
			createQuery(query);//execute
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
	//method untuk mengambil score pemain yang sudah ada
	public void getUserName(String uName){
		try{
			//query
			String query = "SELECT * FROM top_player where username='"+uName+"'";
			createQuery(query);//execute
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}

	//method untuk mengupdate score pemain yang sudah ada.
	public void updateScore(String uName, int score){
		try{
			//query
			String query = "UPDATE top_player SET score='"+score+"' WHERE username='"+uName+"'";
			createUpdate(query);//execute
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}

	//method untuk menginsert pemain yang belum ada
	public void insertScore(String username, int score){
		try{
			String query = "INSERT INTO top_player(username, score) values ('"+username+"','"+score+"')";
			createUpdate(query);
		}catch(Exception e){
			System.out.println(e.toString());
		}
	}
	
}