import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
//bunch of class import

//buat class dengan nama tertera yang memiliki inheritance dari application
public class FakeCELL extends Application {
	//main method
	public static void main(String[] args) {
		Application.launch(args);
	}

	@Override 
	public void start(Stage stage){
		//create scene 1
		Group root1= new Group();
		Scene scene1 = new Scene(root1, 800, 600);//scene size

		Text h1 = new Text("PBO CELL"); //header judul
		h1.setFont(Font.font("Calibri", FontWeight.BOLD, 30));//font option
		h1.setLayoutX(330); //x axis
		h1.setLayoutY(50); //y axis
		root1.getChildren().add(h1);

		Text h2 = new Text("Cellular Phones & Accesories"); //deskripsi
		h2.setFont(Font.font("Calibri", 20));
		h2.setLayoutX(280); //x axis
		h2.setLayoutY(85); //y axis
		root1.getChildren().add(h2);

		//label username
		Label lUname= new Label("Username :");
		lUname.setLayoutX(280); //x axis
		lUname.setLayoutY(190); //y axis
		root1.getChildren().add(lUname);

		//textfield username
		TextField tfUname= new TextField();//blank
		tfUname.setLayoutX(380); //x, y axis
		tfUname.setLayoutY(190);
		root1.getChildren().add(tfUname);

		//label password
		Label lPass= new Label("Password :");
		lPass.setLayoutX(280); //x, y axis
		lPass.setLayoutY(230);
		root1.getChildren().add(lPass);

		//filed khusus password
		PasswordField pass= new PasswordField();
		pass.setLayoutX(380);
		pass.setLayoutY(230);
		root1.getChildren().add(pass);
		//button untuk scene login
		Button bLogin = new Button("Masuk");
		bLogin.setLayoutX(390);
		bLogin.setLayoutY(280);
		root1.getChildren().add(bLogin);

		//plus footer
		Text f = new Text("1503631_Achmad A. R."); //footer
		f.setFont(Font.font("Calibri", 20));
		f.setLayoutX(580); //x axis
		f.setLayoutY(580); //y axis
		root1.getChildren().add(f);

		//create scene 2
		Group root2= new Group();
		Scene scene2 = new Scene(root2, 800, 600);//scene size
		
		Text h21 = new Text("PBO CELL"); //header judul
		h21.setFont(Font.font("Calibri", FontWeight.BOLD, 30));
		h21.setLayoutX(330); //x axis
		h21.setLayoutY(50); //y axis
		root2.getChildren().add(h21);

		Text h22 = new Text("Cellular Phones & Accesories"); //deskripsi
		h22.setFont(Font.font("Calibri", 20));
		h22.setLayoutX(280); //x axis
		h22.setLayoutY(85); //y axis
		root2.getChildren().add(h22);

		//teks berikutnya
		Text welcome1 = new Text(); //tulisan ditambahkan di eventhandler
		welcome1.setFont(Font.font("Calibri", 14));
		welcome1.setLayoutX(310); //x axis
		welcome1.setLayoutY(120); //y axis
		root2.getChildren().add(welcome1);
		//font option
		Text welcome2 = new Text("Silahkan pilih vendor dan range harga untuk mencari dan"); //deskripsi
		welcome2.setFont(Font.font("Calibri", 14));
		welcome2.setLayoutX(230); //x axis
		welcome2.setLayoutY(140); //y axis
		root2.getChildren().add(welcome2);
		Text welcome3 = new Text("melihat spesifikasi produk secara lengkap"); //deskripsi
		welcome3.setFont(Font.font("Calibri", 14));
		welcome3.setLayoutX(270); //x axis
		welcome3.setLayoutY(160); //y axis
		root2.getChildren().add(welcome3);

		//////////////////
		//label vendor
		Label lVendor= new Label("Vendor :");
		lVendor.setLayoutX(280); //x,y axis
		lVendor.setLayoutY(190);
		root2.getChildren().add(lVendor);

		//combobox untuk string
		ComboBox<String> cbVendor = new ComboBox<String>();
		cbVendor.getItems().addAll("Samsung", "Asus");//tambah isi combobox
		cbVendor.setLayoutX(380);//x, y axis
		cbVendor.setLayoutY(190);
		root2.getChildren().add(cbVendor);

		//label harga
		Label lHarga= new Label("Harga :");
		lHarga.setLayoutX(280); //x, y axis
		lHarga.setLayoutY(230);
		root2.getChildren().add(lHarga);

		//comboboc untuk string
		ComboBox<String> cbHarga = new ComboBox<String>();
		//tambah isi combobox
		cbHarga.getItems().addAll("<2jt", "2-3,5jt","3,5-5jt", ">5jt");
		cbHarga.setLayoutX(380); //x, y, axis
		cbHarga.setLayoutY(230);
		root2.getChildren().add(cbHarga);

		//tombol pencarian
		Button bCari = new Button("Cari Produk");
		bCari.setLayoutX(390); //x, y axis
		bCari.setLayoutY(280);
		root2.getChildren().add(bCari);

		//another footer
		Text f2 = new Text("1503631_Achmad A. R."); //footer
		f2.setFont(Font.font("Calibri", 20));
		f2.setLayoutX(580); //x axis
		f2.setLayoutY(580); //y axis
		root2.getChildren().add(f2);
		//////////////////

		//create scene 2
		Group root3= new Group();
		Scene scene3 = new Scene(root3, 800, 600);

		Text h31 = new Text("PBO CELL"); //header judul
		h31.setFont(Font.font("Calibri", FontWeight.BOLD, 30));
		h31.setLayoutX(330); //x axis
		h31.setLayoutY(50); //y axis
		root3.getChildren().add(h31);

		Text h32 = new Text("Cellular Phones & Accesories"); //deskripsi
		h32.setFont(Font.font("Calibri", 20));
		h32.setLayoutX(280); //x axis
		h32.setLayoutY(85); //y axis
		root3.getChildren().add(h32);

		Text name = new Text(""); //header judul
		name.setFont(Font.font("Calibri", FontWeight.BOLD, 26));//font option
		name.setLayoutX(330); //x axis
		name.setLayoutY(160); //y axis
		root3.getChildren().add(name);

		Text h4 = new Text("Spesifikasi Produk :"); //deskripsi
		h4.setFont(Font.font("Calibri", 18));//font option
		h4.setLayoutX(320); //x axis
		h4.setLayoutY(225); //y axis
		root3.getChildren().add(h4);

		//label layar
		Label lLayar= new Label("Layar :");
		lLayar.setLayoutX(320);
		lLayar.setLayoutY(250);
		root3.getChildren().add(lLayar);
		//label os
		Label lOS= new Label("OS :");
		lOS.setLayoutX(320);
		lOS.setLayoutY(280);
		root3.getChildren().add(lOS);
		//label ram
		Label lRAM= new Label("RAM :");
		lRAM.setLayoutX(320);
		lRAM.setLayoutY(310);
		root3.getChildren().add(lRAM);
		//label memori
		Label lMemori= new Label("Memori :");
		lMemori.setLayoutX(320);
		lMemori.setLayoutY(340);
		root3.getChildren().add(lMemori);
		//label baterai
		Label lBaterai= new Label("Baterai :");
		lBaterai.setLayoutX(320);
		lBaterai.setLayoutY(370);
		root3.getChildren().add(lBaterai);
		//label kamera
		Label lKamera= new Label("Kamera :");
		lKamera.setLayoutX(320);
		lKamera.setLayoutY(400);
		root3.getChildren().add(lKamera);
		//////////////////////////
		//isi data layar
		Label lfLayar= new Label("");
		lfLayar.setLayoutX(370);
		lfLayar.setLayoutY(250);
		root3.getChildren().add(lfLayar);
		//isi data os
		Label lfOS= new Label("");
		lfOS.setLayoutX(350);
		lfOS.setLayoutY(280);
		root3.getChildren().add(lfOS);
		//isi data ram
		Label lfRAM= new Label("");
		lfRAM.setLayoutX(360);
		lfRAM.setLayoutY(310);
		root3.getChildren().add(lfRAM);
		//isi data memori
		Label lfMemori= new Label("");
		lfMemori.setLayoutX(380);
		lfMemori.setLayoutY(340);
		root3.getChildren().add(lfMemori);
		//isi data baterai
		Label lfBaterai= new Label("");
		lfBaterai.setLayoutX(375);
		lfBaterai.setLayoutY(370);
		root3.getChildren().add(lfBaterai);
		//isi data kamera
		Label lfKamera= new Label("");
		lfKamera.setLayoutX(380);
		lfKamera.setLayoutY(400);
		root3.getChildren().add(lfKamera);
		//////////////////////////
		//declare image
		Image smJ1 = new Image ("asset/SM-J1.jpg");
		Image smJ7 = new Image ("asset/SM-J7.jpg");
		Image smA5 = new Image ("asset/SM-A5.jpg");
		Image smS7 = new Image ("asset/SM-S7.jpg");
		Image zen5 = new Image ("asset/ZEN-5.jpg");
		Image zen2las = new Image ("asset/ZEN-2Las.jpg");
		Image zen2 = new Image ("asset/ZEN-2.jpg");
		Image zen3 = new Image ("asset/ZEN-3.jpg");

		//instance image view
		ImageView viewM = new ImageView();

		viewM.setFitHeight(240);//height
		viewM.setFitWidth(200);//width
		viewM.setLayoutX(60); //x, y, axis
		viewM.setLayoutY(200);
		root3.getChildren().add(viewM);
		//button kembali
		Button bBack = new Button("Kembali");
		bBack.setLayoutX(390); //x, y, axis
		bBack.setLayoutY(450);
		root3.getChildren().add(bBack);


		Text f3 = new Text("1503631_Achmad A. R."); //footer
		f3.setFont(Font.font("Calibri", 20));
		f3.setLayoutX(580); //x axis
		f3.setLayoutY(580); //y axis
		root3.getChildren().add(f3);
		//event untuk tombol login
		bLogin.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					//right password
					if (pass.getText().equals("pboceria")) {
						welcome1.setText("Selamat Datang "+ tfUname.getText() +",");
						stage.setScene(scene2);//ubah labe yang tadinya kosong
					}
					//warning attempt promp new window
					else{
						Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to login");
					    alert.setHeaderText("Password Salah");
					    alert.setContentText("Silahkan Coba lagi !");
					    alert.showAndWait();
					}
				}
		});
		//event untuk tombol pencarian
		bCari.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					//warning attempt jika ada combobox yang diabiarkan kosong
					if (cbVendor.getValue() == null || cbHarga.getValue() == null) {
						Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to proceed");
					    alert.setHeaderText("Pencarian Gagal");
					    alert.setContentText("Pilihlah vendor beserta harga !");
					    alert.showAndWait();
					}
					else{
						/*
						Samsung
						<2jt J1 (4,3, 4.4 KK, 512MB, 4/256, 1850mah, 5/2 mp)
						2-3,5jt J7 (5,5, 5.1 LP, 1.5GB, 16/256, 3000mah,13/5 mp)
						3,5-5jt A5 (5,2, 6.0 MM, 2GB, 16/64, 3000mah,13/5mp)
						>5jt S7 (5.1, 6.0 MM, 4GB, 64/256, 3000mah,12/5mp)
						//kondisi di bawah hanya menggambarkan data diatas
						*/
						if (cbVendor.getValue().equals("Samsung")) {
							if (cbHarga.getValue().equals("<2jt")) {
								viewM.setImage(smJ1);
								name.setText("Galaxy J1");
								lfLayar.setText("4,3 Inch");
								lfOS.setText("Android OS, v4.4 (kitkat)");
								lfRAM.setText("512 MB");
								lfMemori.setText("Internal 4 GB, External up-to 256 GB");
								lfBaterai.setText("1850 mAh");
								lfKamera.setText("Depan 2 MP, Belakang 5 MP");
							}else if (cbHarga.getValue().equals("2-3,5jt")) {
								viewM.setImage(smJ7);
								name.setText("Galaxy J7");
								lfLayar.setText("5,5 Inch");
								lfOS.setText("Android OS, v5.1 (lolipop)");
								lfRAM.setText("1,5 GB");
								lfMemori.setText("Internal 16 GB, External up-to 256 GB");
								lfBaterai.setText("3000 mAh");
								lfKamera.setText("Depan 5 MP, Belakang 13 MP");
							}else if (cbHarga.getValue().equals("3,5-5jt")) {
								viewM.setImage(smA5);
								name.setText("Galaxy A5");
								lfLayar.setText("5,2 Inch");
								lfOS.setText("Android OS, v6.0 (marsmallow)");
								lfRAM.setText("2 GB");
								lfMemori.setText("Internal 16 GB, External up-to 64 GB");
								lfBaterai.setText("3000 mAh");
								lfKamera.setText("Depan 5 MP, Belakang 13 MP");
							}else if (cbHarga.getValue().equals(">5jt")) {
								viewM.setImage(smS7);
								name.setText("Galaxy S7");
								lfLayar.setText("5,1 Inch");
								lfOS.setText("Android OS, v6.0 (marsmallow)");
								lfRAM.setText("4 GB");
								lfMemori.setText("Internal 64 GB, External up-to 256 GB");
								lfBaterai.setText("3000 mAh");
								lfKamera.setText("Depan 5 MP, Belakang 12 MP");
							}
						}else if (cbVendor.getValue().equals("Asus")) {
						/*
						ASUS
						<2jt Zenfone 5 (5, 4.4 KK, 2GB, 8/64, 2110,8/2mp)
						2-3,5jt Zenfone 2 laser (5,5, 5.0 LP, 2GB, 16/256, 3000mah,13/5mp)
						3,5-5jt Zenfone 2 ZE115ML (5,5, 5.0 LP, 4GB, 32/256, 3000mah,13/5mp)
						>5jt 3 deluxe (5.7, 6 MM, 6GB, 64/256, 3000mah,23/8mp)
						*/
							if (cbHarga.getValue().equals("<2jt")) {
								viewM.setImage(zen5);
								name.setText("Zenfone 5");
								lfLayar.setText("5,0 Inch");
								lfOS.setText("Android OS, v4.4 (kitkat)");
								lfRAM.setText("2 GB");
								lfMemori.setText("Internal 8 GB, External up-to 64 GB");
								lfBaterai.setText("2110 mAh");
								lfKamera.setText("Depan 2 MP, Belakang 8 MP");
							}else if (cbHarga.getValue().equals("2-3,5jt")) {
								viewM.setImage(zen2las);
								name.setText("Zenfone 2 Laser");
								lfLayar.setText("5,5 Inch");
								lfOS.setText("Android OS, v5.0 (lolipop)");
								lfRAM.setText("2 GB");
								lfMemori.setText("Internal 16 GB, External up-to 256 GB");
								lfBaterai.setText("3000 mAh");
								lfKamera.setText("Depan 5 MP, Belakang 13 MP");
							}else if (cbHarga.getValue().equals("3,5-5jt")) {
								viewM.setImage(zen2);
								name.setText("Zenfone 2");
								lfLayar.setText("5,5 Inch");
								lfOS.setText("Android OS, v5.0 (lolipop)");
								lfRAM.setText("4 GB");
								lfMemori.setText("Internal 32 GB, External up-to 256 GB");
								lfBaterai.setText("3000 mAh");
								lfKamera.setText("Depan 5 MP, Belakang 13 MP");
							}else if (cbHarga.getValue().equals(">5jt")) {
								viewM.setImage(zen3);
								name.setText("Zenfone 3 Deluxe");
								lfLayar.setText("5,7 Inch");
								lfOS.setText("Android OS, v6.0 (marsmallow)");
								lfRAM.setText("4 GB");
								lfMemori.setText("Internal 64 GB, External up-to 256 GB");
								lfBaterai.setText("3000 mAh");
								lfKamera.setText("Depan 5 MP, Belakang 23 MP");
							}
						}
						stage.setScene(scene3);//
					}
				}
		});
		//event untuk back button
		bBack.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					stage.setScene(scene2);
				}
		});
		stage.setScene(scene1);
		stage.sizeToScene();
		stage.show();
	}	
}
