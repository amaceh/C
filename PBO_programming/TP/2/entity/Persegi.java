package entity;

// import javafx.scene.Group;
//import some class

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

//lets make class rectangle entity
public class Persegi{
	Rectangle kotak = new Rectangle();

	// attribute
	float velocity, x, y, side;

	//contructor
	public Persegi(Pane group){
		setPosition(0,0);
		setSide(0);
		setVelocity(0);
		setCol();
		group.getChildren().add(kotak);
	}

	//procedure to set size (side lenght)
	public void setSide (float side){
		this.side = side;
		kotak.setWidth(side);
		kotak.setHeight(side);
	}

	//procedure to set object position
	public void setPosition (float x, float y){
		this.x = x;
		this.y = y;
		// kotak.setLayoutX(x);
		// kotak.setLayoutY(y);
		kotak.relocate(x, y);//pane use relocate function
	}

	//side get function
	public float getside (){
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
		kotak.setFill(Color.RED);
	}
}