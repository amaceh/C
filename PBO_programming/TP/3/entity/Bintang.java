package entity;

//import some class
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;
import javafx.scene.Group;

//lets make class star entity
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
    Polygon star;//object
	// attribute
	float velocity, x, y, side;
	//contructor
	public Bintang(float side){
		//instance
		star = new Polygon(new Star(side).getPoints());
		setVelocity(0);
	}
	
	//procedure to set object position
	public void setPosition (float x, float y){
		//simpan posisi sekarang
		this.x = x;
		this.y = y;
		//ubah koordinat bintang
		star.setLayoutX(x + side);
		star.setLayoutY(y + side);
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
	public void setCol(String col){
		star.setFill(Color.web(col));
	}

	//add group procedure
	public void addToGroup(Group group){
		group.getChildren().add(star);
	}
}