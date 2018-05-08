package controller;

import model.DB;
import model.CitaCita;

import view.Home;
import view.Animation;
import view.entity.Jagoan;
import view.entity.Ball;

import java.util.concurrent.ThreadLocalRandom;
import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/*
 * Class ProsesJagoan
 * class yang mengatur animasi jagoan
 * merupakan extend dari class Thread java
 */

public class ProsesJagoan extends Thread{
	//atribute
	private Thread th;
	private Jagoan chaw;
	private Ball[] bool;
	private Scene container;
	private Stage stage;
	private Home home;
	private Animation anim;
	private String username;
	private int score;

	public ProsesJagoan(Scene sc, Stage st, Home h, Animation a, Jagoan jg, Ball[] bola){
		//simpan semua param menjadi attribut
		home=h;
		anim=a;
		setUser(anim.getUser());
		chaw=jg;
		bool=bola;
		container=sc;
		stage=st;

		//image size is 640x1280
		//make it 60X120
		chaw.setWidth(60);
		chaw.setHeight(120);
		chaw.setX(390);
		chaw.setY(455);
		chaw.setVelo(0);
		chaw.draw();
		score=0;
	}

	//override method run pada class thread
	public void run(){
		try{
			while(true){
				//eventhandler ketika tombol ditekan
				container.setOnKeyPressed(new EventHandler<KeyEvent>(){
	        		@Override
	        		public void handle(KeyEvent key) {
	        			if (key.getCode().equals(KeyCode.UP) && chaw.getY()>20){
							chaw.setVelo(-1);
							//tombol up untuk menaikkan jagaan
	        			}else if (key.getCode().equals(KeyCode.DOWN) && chaw.getY()<454){
							chaw.setVelo(2);
							//tombol down untuk menurunkan jagaan
	        			}else if (key.getCode().equals(KeyCode.SPACE)){
							endGame();
							//tombol spasi untuk mengakhiri permainan
	        			}
	        		}
	        	});

				//eventhandler ketika tombol baru saja dilepas
	        	container.setOnKeyReleased(new EventHandler<KeyEvent>(){
		            public void handle(KeyEvent key) {
						if (chaw.getY()<454) {
							if (key.getCode().equals(KeyCode.UP)) {
								chaw.setVelo(1);
							}else if (key.getCode().equals(KeyCode.DOWN)) {
								chaw.setVelo(1);
							}
						}
	        		}
	        	});
	        	//jelajahi semua object oval
	        	for (int i=0; i<9 ; i+=1) {
	        		double size=bool[i].getSize();
	        		//cek apakah jagoan menyentuk ovak atau tidak
					if((bool[i].getY()+(size)>chaw.getY()) && (
						bool[i].getY()<chaw.getY())){
						if (bool[i].getX()<chaw.getX() &&
							bool[i].getX()+40>chaw.getX()){
							if (bool[i].getColor()!="#000000") {//cek apakah oval zonk atau bukan
								// System.out.println("Makan "+bool[i].getScore());
								//tambah score setiap oval yang kena
								score+=bool[i].getScore();
								bool[i].setStat(1);//lalu ubah status oval
							}else{//jika kena zonk
								score-=bool[i].getScore();//score dikurangi
								endGame();//permainan selesai
							}
						}
					}
	        	}
				chaw.unDraw();//hapus
				chaw.setY(chaw.getY()+chaw.getVelo());//geser
				chaw.draw();//gambar
				//batasan untuk turun dan naik
	        	if (chaw.getY()>454 || chaw.getY()<20) {
					chaw.setVelo(0);
				}
				sleep(10);//jeda thread(jeda animasi)
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	//set get username
	public void setUser(String user){
		username=user;
	}
	public String getUser(){
		return username;
	}

	//method untuk menghentikan permainan
	private void endGame(){
		//ketika jagoan menyentuh oval, proses ini tidak aman
		//gunakan runlater
		Platform.runLater(new Thread() {
	    	@Override
	    	public void run() {
				try{
					//akses database
					CitaCita cta = new CitaCita();
					cta.getUserName(username);//cek apakah nama sudah atau belum
					if (cta.getResult().next()){//jik ada
						int oldScore=Integer.parseInt(cta.getResult().getString(3)); 
						if (score>oldScore) {//cek apakah lebih besar
							cta.updateScore(username, score);
						}
					}else{//jika tidak ada
						if (score>0) {//cek apakah pemain mendapat score atau tidak
							cta.insertScore(username, score);
						}
					}
				}catch(Exception e){
					String error = e.toString();
					System.out.println(error);
				}
				home.show(stage, anim);
			}
    	});
	}

	//method untuk memulai thread
	public void start(){
        th = new Thread (this);
        th.setDaemon(true);
        //set daemon untuk memastikan thread berhenti ketika permainan berhenti
		th.start();
	}
}