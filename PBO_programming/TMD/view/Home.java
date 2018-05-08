package view;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

import view.Animation;

import controller.ProsesCitaCita;

/*
 *	Class Home, berisi tampilan awal
 *  judul permainan, input username, dan table skor ada disini
 */



public class Home{
	
	//innerclass untuk tableview
	public static class DaftarCita{
		//attribut
		private final SimpleStringProperty UNAME;
		private final SimpleStringProperty SCORE;
		
		//constructor
		public DaftarCita(String UN,String SC){
			UNAME = new SimpleStringProperty(UN);
			SCORE = new SimpleStringProperty(SC);
		}
		
		//attribut
		public String getUName(){
			return UNAME.get();
		}
		
		public void setUName(String UN){
			UNAME.set(UN);
		}
		
		public String getScore(){
			return SCORE.get();
		}
		
		public void setScore(String SC){
			SCORE.set(SC);
		}
	}

	//contructor
	public Home(){
	}
	
	//method untuk menampilkan scene
	public void show(Stage stage, Animation anim){
		//buat tableview dan list
		TableView<DaftarCita> table = new TableView<DaftarCita>();
		ObservableList<DaftarCita> data2 = FXCollections.observableArrayList();
		//lalu buat container
		Group root = new Group();
		Scene scene = new Scene(root);
		//include css file pada scene ini
		scene.getStylesheets().add("/view/style.css");

		stage.setTitle("Catch The Goal");
		stage.setWidth(800);
		stage.setHeight(600);
		//buat label
		final Label label = new Label("Catch The Goal");
		label.setLayoutX(50);
		label.setLayoutY(50);
		label.getStyleClass().add("title");
		root.getChildren().add(label);//add to scene


		final Label luser = new Label("Username : ");
		luser.setLayoutX(50);
		luser.setLayoutY(150);
		luser.getStyleClass().add("control");
		root.getChildren().add(luser);//add to scene

		//textfield input username
		final TextField userTxt = new TextField();
		userTxt.setLayoutX(200);
		userTxt.setLayoutY(150);
		userTxt.getStyleClass().add("control");
		root.getChildren().add(userTxt);//add to scene

		//button untuk memulai
		final Button mainBt = new Button("Main");
		mainBt.setLayoutX(300);
		mainBt.setLayoutY(220);
		mainBt.getStyleClass().add("control");
		root.getChildren().add(mainBt);//add to scene
		//button untuk exit
		final Button keluarBt = new Button("Keluar");
		keluarBt.setLayoutX(520);
		keluarBt.setLayoutY(220);
		keluarBt.getStyleClass().add("control");
		root.getChildren().add(keluarBt);//add to scene

		//play music
		File file = new File("bensound-epic.mp3");
		String MEDIA_URL = file.toURI().toString();
		final MediaPlayer player = new MediaPlayer(new Media(MEDIA_URL));
		player.play();

		Home thisis=this;

		//eventhandler untuk tombol main
		mainBt.setOnAction(new EventHandler<ActionEvent>(){//eventhandle ketika tombol ditekan
			@Override
				public void handle(ActionEvent e){
					//cek apakah textfield diisi atau tidak
					if (!userTxt.getText().trim().isEmpty()) {
						anim.setUser(userTxt.getText());
						anim.show(stage, thisis);
					}else{//jika tidak diisi prompt user
						Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to Enter The Game");
					    alert.setHeaderText("Username Kosong");
					    alert.setContentText("Mohon Isi Username Anda!");
					    alert.showAndWait();
					}
				}
		});
		//tombol keluar
		keluarBt.setOnAction(new EventHandler<ActionEvent>(){//eventhandle ketika tombol ditekan
			@Override
				public void handle(ActionEvent e){
					Platform.exit();//exit tha apps
				}
		});

		//buat colum untuk tableview
		TableColumn<DaftarCita, String> unameCol = new TableColumn<DaftarCita,String>("Username");
		unameCol.setCellValueFactory(
			new PropertyValueFactory<DaftarCita,String>("UName")
		);
		unameCol.setPrefWidth(200);
		
		//buat colum untuk tableview
		TableColumn<DaftarCita,String> scoreCol = new TableColumn<DaftarCita,String>("Score");
		scoreCol.setCellValueFactory(
			new PropertyValueFactory<DaftarCita,String>("score")
		);
		scoreCol.setPrefWidth(170);

		//memanggil class css untuk tableview
		scoreCol.getStyleClass().add("custom-align");
		
		//atur tableview
		table.getColumns().addAll(Arrays.asList(unameCol,scoreCol));
		table.setItems(data2);
		table.setPrefWidth(400);
		table.setPrefHeight(130);
		table.setLayoutX(210);
		table.setLayoutY(380);
		table.setSelectionModel(null);//hilangkan focus
		root.getChildren().add(table);//add to scene

		//----------Memasukan data ke dalam table (Proses Read)
		
		List<String[]> dftr= new ArrayList<String[]>();
		ProsesCitaCita citaku = new ProsesCitaCita();
		try{
			citaku.prosesCita();
			//get db contain
			
			dftr=citaku.getHasil();
		}catch(Exception e){
			String err=e.toString();
			System.out.println(err);
		}
		for(String item[]:dftr){//foreach container
			data2.add(new DaftarCita (//tambahkan pada list object
				item[0],
				item[1]
			));
    	}
		stage.setScene(scene);
		stage.setResizable(false);
		stage.centerOnScreen();
		stage.show();
	}
	
}
