package view.entity;

import java.util.concurrent.ThreadLocalRandom;
import javafx.application.Platform;
import javafx.geometry.VPos;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.text.TextAlignment;

/*
 *	Class Ball
 *	class yang digunakan untuk menggambar bola/oval pada canvas
 * 	juga digunakan untuk menghapus gambar untuk keperluan animasi
 *	terdapat pula beberapa atribut yang digunakan dalam proses animasi
 */

public class Ball{
	//beberapa attribut
    private GraphicsContext gc;
    private GraphicsContext gb;

    //attribut yang nantinya digunakan untuk animasi
    private double x , y, size, velo;
    private int score, level, stat, start;
    private String color;

    //contruktor
	public Ball(Canvas canvas){
		//ambil dulu grahic context dari canvas
		gc = canvas.getGraphicsContext2D();
		gb = canvas.getGraphicsContext2D();
	}

	//method untuk menggambar bola/oval
	public void draw(double x, double y, double size, int score, String color){
		//runlater memastikan operasi di thread ini aman, karena thread ini bukan berasal dari jFx
		Platform.runLater(new Thread() {
	    	@Override
	    	public void run() {
	    		//tentukan warnanya
				gc.setFill(Color.web(color));
				//gambar ovalnya
			    gc.fillOval(x, y, size*1.5, size);
			    //lalu gambar scorenya
			    drawScore(x, y, size, score);
			}
    	});
	}

	//method untuk menghapus bola/oval
	public void unDraw(double x, double y, double size){
		//runlater memastikan operasi di thread ini aman, karena thread ini bukan berasal dari jFx
		Platform.runLater(new Thread() {
	    	@Override
	    	public void run() {
	    		//timpa bola dengan warna putih
				gb.setFill(Color.WHITE);
			    gb.fillOval(x-1, y-1, (size*1.5)+2, size+2);
			}
    	});
	}

	//method untuk menentukan warna secara random
	public String randCol(){
		//random dari 0-7
		int col=ThreadLocalRandom.current().nextInt(0,8); 
		return colorPicker(col);
	}

	//method penentu warna
	public String colorPicker(int x){
		if (x==1) {
			return "#235ab2";
		}else if(x==2){
			return "#2eb223";
		}else if(x==3){
			return "#c3c609";
		}else if(x==4){
			return "#c60808";
		}else if(x==5){
			return "#08c6ac";
		}else if(x==6){
			return "#c608a6";
		}else if(x==7){
			return "#8d08c6";
		}else{
			return "#000000";
		}
	}

	//method penggambar score
	public void drawScore(double x, double y, double size, int score){
		//pakai stroke supaya score bold
		gb.setStroke(Color.WHITE);
		//lalu digambar ditengah
		gb.setTextAlign(TextAlignment.CENTER);
		gb.setTextBaseline(VPos.CENTER);
		gb.strokeText(
			Integer.toString(score), 
			Math.round(size/ 2)+x+size/4, 
            Math.round(size/ 2)+y
			);
	}

	//get set attribut lain
	public void setStat(int st){
		stat=st;
	}

	public int getStat(){
		return stat;
	}

	public void setScore(int sc){
		score=sc;
	}

	public int getScore(){
		return score;
	}

	public void setSize(double sz){
		size=sz;
	}

	public double getSize(){
		return size;
	}

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

	public void setVelo(double vel){
		velo=vel;
	}

	public double getVelo(){
		return velo;
	}

	public void setLevel(int lv){
		level=lv;
	}

	public int getLevel(){
		return level;
	}

	public void setStart(int st){
		start=st;
	}

	public int getStart(){
		return start;
	}

	public void setColor(String cl){
		color=cl;
	}

	public String getColor(){
		return color;
	}
}