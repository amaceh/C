/*
	class ini digunakan untuk membuat peluru dengan berbentuk persegi
*/

package entity;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Peluru extends Rectangle{
	
	Peluru(double x, double y){
		/*
		ini merupakan constructor
		nilai dari masukan/parameternya akan dijadikan koordinat awal dari peluru
		*/
		
		this.setX(x-5);
		this.setY(y);
		setHeight(20);
		setWidth(8);
		setArcHeight(100);
		setArcWidth(100);
		// setStroke(Color.GREEN);
		// setFill(Color.RED);
	}
	
}

