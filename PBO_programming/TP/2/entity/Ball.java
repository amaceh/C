package entity;

//import some class
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

//lets make class ball entity
public class Ball {
	Circle circle = new Circle();

	// attribute	
	float velocity, x, y, radius;

	//contructor
	public Ball(Pane group){
		setPosition(0,0);
		setRadius(0);
		setVelocity(0);
		setCol();
		group.getChildren().add(circle);
	}

	//procedure to set rad of the circle
	public void setRadius (float radius){
		this.radius = radius;
		circle.setRadius(radius);
	}

	//procedure to set object position
	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		// circle.setLayoutX(x + radius);
		// circle.setLayoutY(y + radius);
		circle.relocate(x,y);//pane use relocate function
	}

	//radius get function
	public float getRadius (){
		return radius;
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
		circle.setFill(Color.YELLOW);
	}
}