// package entity;
// import javafx.scene.Group;
//import some class
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;
import javafx.scene.Group;

//lets make class haxagon entity
public class Bintang{
	//inner class Star
	class Star {
		double [] points;
		double center;
		public Star(double side){
			points = new double[10];
			//     X                          Y
			points[0] = 5.0*side;	points[1] = 0.1*side;
			points[2] = 2.0*side;	points[3] = 9.1*side;
			points[4] = 9.7*side;	points[5] = 3.5*side;
			points[6] = 0.2*side;	points[7] = 3.5*side;
			points[8] = 7.9*side;	points[9] = 9.1*side;
		}
		public double [] getPoints(){
			return points;
		}
	}
    //Star builder class
    //http://stackoverflow.com/questions/27211517/how-can-i-draw-a-Star-in-java-scene-builder-2-0
    //
    Polygon Star;//object
	// attribute
	float velocity, x, y, side;
	//contructor
	public Bintang(Group group, float side){
		//instance
		Star = new Polygon(new Star(side).getPoints());
		setPosition(1000,1000);//predefined hide object
		setVelocity(0);
		setCol();
		group.getChildren().add(Star);
	}
	
	//procedure to set object position
	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		Star.setLayoutX(x + side);
		Star.setLayoutY(y + side);
		// Star.relocate(x,y);//pane use relocate function
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
		Star.setFill(Color.GREEN);
	}
}