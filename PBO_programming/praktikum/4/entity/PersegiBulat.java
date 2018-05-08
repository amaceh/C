package entity;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class PersegiBulat{
	Rectangle kotak = new Rectangle();

	float velocity, x, y, side, arc;

	public PersegiBulat(Group group){
		setPosition(0,0);
		setSide(0);
		setVelocity(0);
		group.getChildren().add(kotak);
	}

	public void setSide (float side){
		this.side = side;
		kotak.setWidth(side);
		kotak.setHeight(side);
	}

	public void setArc(float arc){
		this.arc = arc;
		kotak.setArcWidth(arc);
		kotak.setArcHeight(arc);	
	}

	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		kotak.setLayoutX(x);
		kotak.setLayoutY(y);
	}

	public float getside (){
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