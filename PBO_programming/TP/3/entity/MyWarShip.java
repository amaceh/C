/*
Class ini digunakan untuk membuat bola yang menembakan peluru terdapat juga pengaturan pada peluru
*/

package entity;

//import some class
import java.util.ArrayList;
import javafx.scene.Group;
import javafx.scene.image.ImageView;
import javafx.scene.image.Image;


//class kapal perang
//extend dari imageview
public class MyWarShip extends ImageView{

	//instansiasi imageview
	ImageView shooter = new ImageView();
	//atribut lain
	float velocity;
	boolean shot;
	double x,y, size;
	// attribut peluru
	ArrayList<Peluru> arrPeluru = new ArrayList<Peluru>();
	ArrayList<Peluru> delPeluru = new ArrayList<Peluru>();
	
	//contructor	
	public MyWarShip(){
		//call the image
		Image plane = new Image ("img/airplane.png");
		shooter.setImage(plane);//ubah gambar imageview
		shot = false;
	}
	
	public void setSize(double x){
		//procedure yang digunakan untuk menentukan ukuran pesawat
		shooter.setFitHeight(x);//height
		shooter.setFitWidth(x);//width
		size = x;
	}

	//get method size
	public double getSize(){
		return size;
	}		
	
	public void setPosition(double x,double y){
		//procedure yang digunakan untuk mengatur posisi bola
		this.x = x;
		this.y = y;
		// shooter.setX(x);
		// shooter.setY(y);
		shooter.setLayoutX(x); //x, y, axis
		shooter.setLayoutY(y);
	}
	
	public double getXShip(){
		//fungsi untuk mendapatkan nilai koordinat x dari bola jagoan
		return x;
	}
	
	public double getYShip(){
		//fungsi untuk mendapatkan nilai koordinat y dari bola jagoan
		return y;
	}
	
	public ImageView getShipView(){
		//fungsi untuk mendapatkan persegi dari bola jagoan
		return shooter;
	}
	
	public float getVelocity(){
		//fungsi untuk mendapatkan nilai percepatan bola jagoan
		return velocity;
	}
	
	public void setVelocity(float velocity){
		//procedure untuk menentukan nilai percepatan bola jagoan
		this.velocity = velocity;
	}
	
	public void addToGroup(Group root){
		//add ship ke scene

		//tambahkan objek ke group
		root.getChildren().add(this);
		root.getChildren().add(shooter);
	}
	
	//method menembak
	public void shoot(Group root){
		Peluru peluru = new Peluru(x+getSize()/2,y);
		arrPeluru.add(peluru);
		root.getChildren().add(peluru);
	}

	// public void shootFill(Peluru peluru){
	// 	// FillTransition ft = new FillTransition(Duration.millis(500), peluru, Color.RED, Color.BLUE);
	// 	ft.setCycleCount(200);
	// 	ft.setAutoReverse(true);
	 
	// 	ft.play();
	// }
	
	public void updatePeluru(Group root){
		//procedure untuk menembakan peluru tengah
		//array untuk menampung peluru yang akan dihapus
		for(Peluru peluru : arrPeluru){
			//untuk menggrakan peluru
			// shootFill(peluru);
			peluru.setY(peluru.getY()-5);
			//jika peluru sudah melewati batas
			//maka dimasukan ke array untuk hapus
			if(peluru.getY()<0){
				delPeluru.add(peluru);
			}
		}
		delPeluru(delPeluru, root);
		//menghapus peluru
		// for(Peluru peluru:delPeluru){
		// 	arrPeluru.remove(peluru);
		// 	root.getChildren().remove(peluru);
		// }
	}

	//get set method peluru
	public boolean getShot(){
		return shot;
	}

	public void setShot(boolean shot){
		this.shot = shot;
	}

	// private void checkCollision(Group root, Bintang star){	
	// 	for(Peluru peluru : pesawat.get()){
	// 		//jika peluru mengenai shooter
	// 		if(peluru.getBoundsInParent().intersects(meteor.getMeteor().getBoundsInParent())){
	// 			//posisi shooter di set awal secara random
	// 			// skor = skor + 10;	//menambahkan skor
	// 			System.out.println("Gotcha");
	// 			delPeluru.add(peluru);
	// 		}
	// 	}
	// }

	// public void checkCollision(java.util.List<Spaceship> ships, java.util.List<Nuke> nukes) {
	// 	for(Nuke n : nukes) {
	// 		Rectangle nukeBounds = n.getBounds();
	// 		for(int i = 0; i<ships.size(); i++) {
	// 			Spaceship s1 = ships.get(i);
	// 			if(s1.getBounds().intersects(nukeBounds)) {
	// 				collision();
	// 				ships.remove(i);
	// 				score = score + 10;
	// 			}
	// 		}
	// 	}
	// }

	//prosedur penghapusan objek peluru
	public void delPeluru(ArrayList<Peluru> delPeluru, Group root){
		for(Peluru peluru:delPeluru){
			arrPeluru.remove(peluru);
			root.getChildren().remove(peluru);
		}	
	}

}