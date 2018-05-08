package view;

import java.io.File;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;
import javafx.scene.Group;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.paint.Color;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

import view.Home;

import controller.ProsesOval;
import controller.ProsesJagoan;

import view.entity.Ball;
import view.entity.Jagoan;

/*
 *	Class Animation, berisi tampilan animasi
 *  permainan ada pada class ini
 */

public class Animation{
	//atribute untuk menyimpan username
	private String username;
	
	//constructor
	public Animation(){

	}

	//method tampilan scene animasi
	public void show(Stage stage, Home hum){
		
		//buat container
		Group root = new Group();
		Scene scene = new Scene(root);


		//lalu canvas
		Canvas kampas = new Canvas(800, 600);
		root.getChildren().add(kampas);//add to scene

		//play music
		

		//buat object untuk menggambar oval
		Ball[] bola=new Ball[9];
		for (int i=0; i<9; i+=1){
			bola[i]= new Ball(kampas);
		}

		//lalu object thread yang melakuakn animasi oval
		ProsesOval[] cito = new ProsesOval[9];
		
		for (int i=0; i < 9; i+=1) {
			cito[i]=new ProsesOval(kampas, bola[i],i);
		}

		//mulai semua thread
		for (int i=0; i < 9; i+=1) {
			cito[i].start();
		}

		//buat object untuk jagoan
		Jagoan neon=new Jagoan(kampas);

		//thread untuk jagoan
		ProsesJagoan ggwp = new ProsesJagoan(scene, stage, hum, this, neon, bola);
		ggwp.start();//mulai thread
		
		stage.setTitle("Catch The Goal");
		stage.setWidth(800);
		stage.setHeight(600);
		stage.setScene(scene);
		stage.setResizable(false);
		stage.centerOnScreen();
		stage.show();
	}

	//set get user
	public void setUser(String user){
		username=user;
	}

	public String getUser(){
		return username;
	}
}