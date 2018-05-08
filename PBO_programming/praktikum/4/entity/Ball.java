package entity;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
// import javafx.scene.shape.Rectangle;

public class Ball {
	Circle circle = new Circle();

	float velocity, x, y, radius;

	public Ball(Group group){
		setPosition(0,0);
		setRadius(0);
		setVelocity(0);
		group.getChildren().add(circle);
	}

	public void setRadius (float radius){
		this.radius = radius;
		circle.setRadius(radius);
	}

	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		circle.setLayoutX(x + radius);
		circle.setLayoutY(y + radius);
	}

	public float getRadius (){
		return radius;
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