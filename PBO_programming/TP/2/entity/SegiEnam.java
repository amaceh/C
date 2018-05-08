package entity;
// import javafx.scene.Group;
//import some class
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;
import java.lang.Math;

//lets make class haxagon entity
public class SegiEnam{
	//inner class hexagon
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
    Polygon hexagon;//object
	// attribute
	float velocity, x, y, side;
	//contructor
	public SegiEnam(Pane group, float side){
		//instance
		hexagon = new Polygon(new Hexagon(side).getPoints());
		setPosition(1000,1000);//predefined hide object
		setVelocity(0);
		setCol();
		group.getChildren().add(hexagon);
	}
	
	//procedure to set object position
	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		// hexagon.setLayoutX(x + side);
		// hexagon.setLayoutY(y + side);
		hexagon.relocate(x,y);//pane use relocate function
	}

	//side get function
	public float getSide (){
		return side;
	}
	//x get function
	public float getX (){
		return x;
	}

	//y get function
	public float getY (){
		return y;
	}
	
	//velocity get function
	public float getVelocity (){
		return velocity;
	}
	
	//procedure to set curretn velocity
	public void setVelocity(float velocity){
		this.velocity = velocity;
	}
	
	//bouncer procedure
	public void bounce(){
		this.velocity *= -1;
	}
	
	//color changer
	public void setCol(){
		hexagon.setFill(Color.GREEN);
	}
}