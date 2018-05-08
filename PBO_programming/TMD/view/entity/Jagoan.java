package view.entity;

import javafx.application.Platform;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;

public class Jagoan{

	/*
	 *	Class Jagoan
	 *	class yang digunakan untuk menggambar jagoan pada canvas
	 * 	juga digunakan untuk menghapus gambar untuk keperluan animasi
	 *	terdapat pula beberapa atribut yang digunakan dalam proses animasi
	 */

	//beberapa attribut
    private GraphicsContext gc;
    private GraphicsContext gb;

    //atribut untuk animasi
    private double x, y, width, height, velo;
    private Image image, image2;

    //konstruktor
	public Jagoan(Canvas canvas){
		gc = canvas.getGraphicsContext2D();
		//ambil gambar
        image = new Image("view/entity/Jagoan.png");
        //image2 = new Image("view/entity/JagoanHapus.png");
	}

	//method untuk menggambar
	public void draw(){
		//runlater memastikan operasi di thread ini aman, karena thread ini bukan berasal dari jFx
		Platform.runLater(new Thread() {
	    	@Override
        	public void run() {
        		//gambar jagoan di canvas
	        	gc.drawImage(image, x, y, width, height);
	        }
    	});
	}

	public void unDraw(){
		//runlater memastikan operasi di thread ini aman, karena thread ini bukan berasal dari jFx
		Platform.runLater(new Thread() {
	    	@Override
        	public void run() {
        		//sulit sekali membuat penhapus bentuk orang
	        	// gc.drawImage(image2, x-2, y-2, width+4, height+4);
	        	// gc.drawImage(image2, x-3, y-7, width+6, height+14);
		    	
		    	//pakai penghapus bentuk kotak lebih baik
		    	gc.clearRect(x, y-5, width, height+10);
		    }
    	});
	}

	//set get
	public void setX(double xx){
		x=xx;
	}

	public double getX(){
		return x;
	}

	public void setY(double yy){
		y=yy;
	}

	public double getY(){
		return y;
	}

	public void setWidth(double wd){
		width=wd;
	}

	public double getWidth(){
		return width;
	}

	public void setHeight(double hg){
		height=hg;
	}

	public double getHeight(){
		return height;
	}

	public void setVelo(double vl){
		velo=vl;
	}

	public double getVelo(){
		return velo;
	}
}