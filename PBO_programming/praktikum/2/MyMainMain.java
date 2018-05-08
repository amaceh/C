import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.TextField;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;

public class MyMainMain extends Application{
	public static void main(String[] args) {
		Application.launch(args);
	}

	@Override public void start(Stage stage){
		//1st scene
		//welcome scene
		Group root = new Group();
		Scene welcomeScene = new Scene(root, 300, 200);//scene size

		Text scenetitle = new Text("Cari Gambar Galaxy"); //titte bar scene
		scenetitle.setFont(Font.font("Calibri", FontWeight.BOLD, 20));
		scenetitle.setLayoutX(20); //x axis
		scenetitle.setLayoutY(30); //y axis
		root.getChildren().add(scenetitle);

		//galaxy label
		Label lGalaxy = new Label("Galaxy");
		lGalaxy.setLayoutX(30); //x axis
		lGalaxy.setLayoutY(80); //y axis
		root.getChildren().add(lGalaxy);
		
		//galaxy textfield
		TextField tfGalaxy = new TextField();
		tfGalaxy.setLayoutX(100); //x axis
		tfGalaxy.setLayoutY(80); //y axis
		root.getChildren().add(tfGalaxy);

		//search button
		Button bCari = new Button("Cari");
		bCari.setLayoutX(205); //x axis
		bCari.setLayoutY(110); //y axis
		root.getChildren().add(bCari);

		//scene 2
		//main scene
		Group rootM = new Group();
		Scene mainScene = new Scene(rootM, 400, 450);

		Image img5 = new Image ("img/img5.jpg");
		Image andro = new Image ("img/andromeda.jpg");
		Image milky = new Image ("img/milkyway.jpg");
		Image galak1 = new Image ("img/NGC2841.jpg");
		Image galak2 = new Image ("img/NGC6814.jpg");

		ImageView ViewM = new ImageView();

		ViewM.setFitHeight(400);//height
		ViewM.setFitWidth(400);//width

		Label mNama = new Label("");
		mNama.setLayoutX(10); //x axis
		mNama.setLayoutY(415); //y axis

		Button mBack = new Button("Cari Lagi kk?");
		mBack.setLayoutX(300); //x axis
		mBack.setLayoutY(412); //y axis

		rootM.getChildren().add(mNama);
		rootM.getChildren().add(mBack);
		rootM.getChildren().add(ViewM);

		//login button while in welcome scene
		bCari.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				if (tfGalaxy.getText().equals("andromeda")) {
					ViewM.setImage(andro);
					mNama.setText("Andromeda Galaxy");
				}else if (tfGalaxy.getText().equals("milkyway")){
					ViewM.setImage(milky);
					mNama.setText("MilkyWay Galaxy");		
				}else if (tfGalaxy.getText().equals("galaksi1")){
					ViewM.setImage(galak1);
					mNama.setText("Galaxy 1");		
				}else if (tfGalaxy.getText().equals("galaksi2")){
					ViewM.setImage(galak2);
					mNama.setText("Galaxy 2");		
				}else{
					ViewM.setImage(img5);
					mNama.setText("Gambar Ndak Ada");		
				}
				stage.setScene(mainScene);
			}
		});

		mBack.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				tfGalaxy.setText("");
				stage.setScene(welcomeScene);
			}
		});

		stage.setScene(welcomeScene);
		stage.sizeToScene();
		stage.show();
	}
}
