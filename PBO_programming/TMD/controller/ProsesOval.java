package controller;
import view.entity.Ball;

import java.util.concurrent.ThreadLocalRandom;
import javafx.scene.canvas.Canvas;

/*
 * Class ProsesOval
 * class yang mengatur animasi oval
 * merupakan extend dari class Thread java
 */

public class ProsesOval extends Thread{
	//attribute
	private Thread th;
	private Ball bool;
	private double edge;

	//contructor
	public ProsesOval(Canvas kampas, Ball bola,int lv){
		edge=kampas.getWidth();
		bool=bola;
		bool.setLevel(lv);
		bool.setSize(40);
		bool.setStat(0);
		//tentukan dari kiri atau kanan
		int start=ThreadLocalRandom.current().nextInt(1,3);
		bool.setStart(start);
		givePos();
		scoreGenerate();
		bool.setColor(bool.randCol());
		bool.draw(bool.getX(), bool.getY(), bool.getSize(), bool.getScore(), bool.getColor());
	}

	//method untuk memberikan posisi awal secara random
	public void givePos(){
		//waktu muncul ditentukan dari seberapa jauh angak random
		int randomNum = ThreadLocalRandom.current().nextInt(50, 501);
		if (bool.getStart()==1){
			bool.setX(0-randomNum);
			bool.setVelo(1);
		}else if (bool.getStart()==2) {
			bool.setX(edge-(bool.getSize()*1.5)+randomNum);
			bool.setVelo(-1);
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
	}

	//method untuk memberikan score secara acak sesuai level dari oval
	public void scoreGenerate(){
		int y=bool.getLevel()*50;
		bool.setY(y);
		int maxSc=110-((bool.getLevel()+1)*10);
		int score=ThreadLocalRandom.current().nextInt(maxSc-10,maxSc+1); 
		bool.setScore(score);
	}

	//method override dari thread
	//animasi dijalankan di method ini
	public void run(){
		try{
			while(true){
				//hapus
				bool.unDraw(bool.getX(), bool.getY(), bool.getSize());
				//jika sudah sampai ujung
				if (bool.getX()<0 && bool.getStart()==2) {
					//pindah, ganti warna, score, dan reset status
					bool.setStat(0);
					bool.setColor(bool.randCol());
					scoreGenerate();
					givePos();
				}else if (bool.getX()>edge-(bool.getSize()*1.5) && bool.getStart()==1){
					//pindah, ganti warna, score, dan reset status
					bool.setStat(0);
					bool.setColor(bool.randCol());
					scoreGenerate();
					givePos();
				}
				//geser
				bool.setX(bool.getX()+bool.getVelo());
				//gambar lagi jika status belum dimakan
				if (bool.getStat()==0) {
					bool.draw(bool.getX(), bool.getY(), bool.getSize(), bool.getScore(), bool.getColor());
				}else{
					//jika status diubah
					//usir dari jagoan
					//dan tidak digambar lagi
					if (bool.getStart()==2){
						bool.setX(-1);
					}else if(bool.getStart()==1){
						bool.setX(edge);
					}
					// bool.draw(bool.getX(), bool.getY(), bool.getSize(), bool.getScore(), bool.getColor());
				}
				sleep(10);//jeda thread(animasi)
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	//method untuk memulai thread
	public void start(){
        th = new Thread (this);
        th.setDaemon(true);
        //set daemon untuk memastikan thread berhenti ketika permainan berhenti
		th.start();
	}
}