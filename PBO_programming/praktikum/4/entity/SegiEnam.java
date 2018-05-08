package entity;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;
import java.lang.Math;


public class SegiEnam{
	class Hexagon {
		double [] points;
		double center;
		public Hexagon(double side){
			center = getH(side);
			points = new double[12];
			//     X                          Y
			points[0] = 0.0;           points[1] = 0.0;
			points[2] = side;          points[3] = 0.0;
			points[4] = side+(side/2); points[5] = center;
			points[6] = side;          points[7] = center * 2;
			points[8] = 0.0;           points[9] = center * 2;
			points[10] = -side/2;      points[11] = center;

		}

		private double getH(double side) {
			return ((Math.sqrt(3)/2)*side);
		}
		public double [] getPoints(){
			return points;
		}
	}
    //hexagon builder class
    //http://stackoverflow.com/questions/27211517/how-can-i-draw-a-hexagon-in-java-scene-builder-2-0
    //

    Polygon hexagon = new Polygon();
	float velocity, x, y, side;

	public SegiEnam(Group group, float side){
		setPosition(0,0);
		setVelocity(0);
		hexagon = new Polygon(new Hexagon(side).getPoints());
		group.getChildren().add(hexagon);
	}

	// public void setSide (float side){
	// 	this.side = side;
	// }
	//
    // Polygon hexagon = new Polygon(new Hexagon(100d).getPoints());
	
	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		hexagon.setLayoutX(x + side);
		hexagon.setLayoutY(y + side);
	}

	public float getSide (){
		return side;
	}
	public float getX (){
		return x;
	}
	public float getY (){
		return y;
	}
	public float getVelocity (){
		return velocity;
	}
	public void setVelocity(float velocity){
		this.velocity = velocity;
	}
	public void bounce(){
		this.velocity *= -1;
	}
}