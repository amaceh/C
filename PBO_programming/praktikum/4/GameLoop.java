import entity.Ball;
import entity.SegiEnam;
import entity.Persegi;
import entity.PersegiBulat;


import global.Constant;
//import from other file

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;

public class GameLoop extends Application{
	public static void main(String[] args) {
		Application.launch(args);
	}

	@Override
	public void start(Stage stage){
		Group root = new Group();
		Scene scene = new Scene(root, Constant.WIDTH, Constant.HEIGHT, Color.LIGHTBLUE);
		
		SegiEnam hexa = new SegiEnam(root, 25);
		hexa.setPosition(0, 0);
		hexa.setVelocity(4);
		Persegi kotak = new Persegi(root);
		kotak.setSide(50);
		kotak.setPosition(0, 0);
		kotak.setVelocity(4);
		Ball bola3 = new Ball(root);
		bola3.setRadius(25);
		bola3.setPosition(0, 0);
		bola3.setVelocity(6);
		PersegiBulat kotax = new PersegiBulat(root);
		kotax.setSide(50);
		kotax.setArc(20);
		kotax.setPosition(Constant.WIDTH-50, 0);
		kotax.setVelocity(4);

		Duration fps = Duration.millis(1000/60);
		KeyFrame oneFrame = new KeyFrame(fps,
		new EventHandler(){
			@Override
			public void handle(Event arg0){
				//movement
				hexa.setPosition(12, hexa.getY()+hexa.getVelocity());
				kotak.setPosition(kotak.getX()+kotak.getVelocity(), 0);
				bola3.setPosition(bola3.getX()+bola3.getVelocity(), bola3.getY()+bola3.getVelocity());
				kotax.setPosition(Constant.WIDTH-52,kotax.getY()+kotax.getVelocity());

				//cek to back
				//+50 to make it not breach the wall
				if (hexa.getY()>=Constant.HEIGHT-40 || hexa.getY()<0) {
					// hexa.setPosition(0,0);
					hexa.bounce();
				}
				if (kotax.getY()>=Constant.HEIGHT-50 || kotax.getY()<0) {
					// kotax.setPosition(0,0);
					kotax.bounce();
				}
				if (kotak.getX()>=Constant.WIDTH-50 || kotak.getX()<0) {
					kotak.bounce();
				}
				//nice bounce will be show in the 3rd ball
				if (bola3.getX()>=Constant.WIDTH-50 || bola3.getY()>Constant.HEIGHT-50 || bola3.getY()<0 || bola3.getX()<0) {
					bola3.bounce();
				}
			}
		});
	stage.setScene(scene);
	stage.show();

	Timeline t1 = new Timeline();
	t1.setCycleCount(Animation.INDEFINITE);
	t1.getKeyFrames().add(oneFrame);
	t1.play();
	}
}
