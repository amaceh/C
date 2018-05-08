package controller;
import controller.entity.Ball;
import javafx.scene.canvas.Canvas;
import java.util.concurrent.ThreadLocalRandom;

public class ProsesMenggapaiCita extends Thread{
	// private double x, y;
	private Thread th;
	private Ball bool;
	private int start, level;
	private double edge;
	public ProsesMenggapaiCita(Canvas kampas){
		edge=kampas.getWidth();
		bool=new Ball(kampas);
		bool.setSize(50);
		start=ThreadLocalRandom.current().nextInt(1,3);
		givePos();		
		bool.draw();
		//exclusive to top value
		// int randomNum = ThreadLocalRandom.current().nextInt(min, max + 1);
	}

	public void givePos(){
		//tentukan dari kiri atau kanan
		if (start==1){
			bool.setX(0);
			bool.setVelo(5);
		}else if (start==2) {
			bool.setX(edge-bool.getSize());
			bool.setVelo(-5);
		}
		//tinggi kanvas 600px
		//kira kira 100px untuk jagoan opal
		//sisa 450px, 25px jarak untuk down and top
		//ada 400px untuk cita2, dibagi 50(ukuran bola dibuat tetap)
		//berarti ada 9 level ketiggian
		//dengan rentang 25-475
		//satu level hanya ada 1 bola
		/*
		9 posisi ketinggian dengan kriteria diatas
		50
		100
		150
		200
		250
		300
		350
		400
		450
		setiap kriteria perbedaan skornya kira2 10
		*/
		//0-8
		int level=ThreadLocalRandom.current().nextInt(0,9);
		int y=level*50;
		bool.setY(y);
		int maxSc=110-((level+1)*10);
		int score=ThreadLocalRandom.current().nextInt(maxSc-10,maxSc+1); 
		bool.setScore(score);
	}
	public void run(){
		try{
			while(true){	
				bool.unDraw();
				if (bool.getX()==0 && start==2) {
					bool.setX(edge-bool.getSize());
				}else if (bool.getX()==edge && start==1){
					bool.setX(0);
				}
				bool.setX(bool.getX()+bool.getVelo());
				bool.draw();
				sleep(100);
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	public void start(){
        th = new Thread (this);
        th.setDaemon(true);
		th.start();
	}
}