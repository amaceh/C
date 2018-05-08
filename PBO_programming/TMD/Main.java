/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	Pemrograman Berbasis Objek dalam mengerjakan Tugas Masa Depan,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin...
	*/

import view.Home;
import view.Animation;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

/*
 * Main class
 * class yang memanggil view class
 */
public class Main extends Application{
	
	public static void main(String[] args){
		launch(args);
	}
	
	@Override
	public void start(Stage stage){
		//instans setiap view
		Home tampilScore = new Home();
		Animation game = new Animation();
		tampilScore.show(stage,game);//tampilkan view pertama
	}
	
}