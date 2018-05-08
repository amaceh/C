import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.effect.DropShadow;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;
//import class yang diperlukan

//import class entity dan global
import entity.Bintang;
import entity.MyWarShip;
import global.Constant;




//public class shape shooter
public class ShapeShooter extends Application{
	
	//inner class ubntuk reord	
	public static class ShapeBuilds{
		//atribut
		private final SimpleStringProperty no;
		private final SimpleStringProperty x;
		private final SimpleStringProperty y;
		private final SimpleStringProperty bobot;

		//contructor
		private ShapeBuilds(String no, String x, String y,String bobot){
			this.no = new SimpleStringProperty(no);
			this.x = new SimpleStringProperty(x);
			this.y = new SimpleStringProperty(y);
			this.bobot = new SimpleStringProperty(bobot);
		}

		//set get method
		public String getNo(){
			return no.get();
		}
		public void setNo(String no){
			this.no.set(no);
		}

		//set get method

		public String getX(){
			return x.get();
		}
		public void setX(String x){
			this.x.set(x);
		}

		//set get metho
		public String getY(){
			return y.get();
		}
		
		public void setY(String y){
			this.y.set(y);
		}

		//set get method
		public String getBobot(){
			return bobot.get();
		}
		public void setBobot(String bobot){
			this.bobot.set(bobot);
		}

	}

	//atribut
	//deklarasi tableview
	private TableView<ShapeBuilds> table = new TableView<ShapeBuilds>();

	//deklarasi obervable list
	private ObservableList<ShapeBuilds> data = FXCollections.observableArrayList();

	//attribute lain
	private int num = 0;
	private MyWarShip army;
	private int time=0;

	//main launcher
	public static void main(String[] args) {
		Application.launch(args);
	}

	@Override
	public void start(Stage stage){
		//scene 1
		//nama
		//2 tombol
		//nim
		Group root1 = new Group();
		//tambah gb ke hijau;
		Scene scene = new Scene(root1, 1000, Constant.HEIGHT, Color.web("#42f450"));//scene dengan warna hijau
		
		Text h1 = new Text("SHAPE SHOOTER"); //header judul
		h1.setFont(Font.font("segoe ui", FontWeight.BOLD, 50));//font option
		h1.setLayoutX(300); //x axis
		h1.setLayoutY(100); //y axis

		DropShadow ds = new DropShadow();
		ds.setOffsetY(3.0f);
		ds.setColor(Color.color(0.4f, 0.4f, 0.4f));
		 
		h1.setEffect(ds);		


		h1.setFill(Color.WHITE);//text color
		root1.getChildren().add(h1);//add to group

		Text h2 = new Text("1503631"); //footer
		h2.setFont(Font.font("segoe ui", FontWeight.BOLD, 20));//font option
		h2.setLayoutX(10); //x axis
		h2.setLayoutY(540); //y axis
		// h2.setFill(Color.WHITE);//white text color
		root1.getChildren().add(h2);//add to group


		Text h3 = new Text("Achmad Abdul Rofiq"); //footer
		h3.setFont(Font.font("Calibri", FontWeight.BOLD, 20));//font option
		h3.setLayoutX(810); //x axis
		h3.setLayoutY(540); //y axis
		// h3.setFill(Color.WHITE);//white text color
		root1.getChildren().add(h3);//add to group

		Button bStart = new Button("MULAI"); //tombol mulai
		bStart.setLayoutX(355); //x, y axis
		bStart.setLayoutY(180);
		bStart.setStyle("-fx-font-size: 50pt; -fx-font-family: 'segoe ui'; -fx-base: #eef441; -fx-border-radius: 80 0 80 0; -fx-background-radius: 80 0 80 0;");//start button layout style
		root1.getChildren().add(bStart);//add to scene

		Button bKeluar = new Button("Keluar"); //tombol keluar
		bKeluar.setLayoutX(435); //x, y axis
		bKeluar.setLayoutY(330);
		bKeluar.setStyle("-fx-font-size: 20pt; -fx-font-family: 'segoe ui'; -fx-base: #eef441;");//start button layout style
		root1.getChildren().add(bKeluar);//add to scene


		//next scene, tableview scene

		Group root2 = new Group();
		Scene listscene = new Scene(root2, Constant.WIDTH, Constant.HEIGHT, Color.web("#42f450"));//scene dengan warna hijau

		Label tabtitl= new Label("Tabel Koordinat Target");
		tabtitl.setLayoutX(10); //x axis
		tabtitl.setLayoutY(10); //y axis
		tabtitl.setStyle("-fx-font-size: 20pt; -fx-font-family: 'segoe ui';");
		root2.getChildren().add(tabtitl);



		TableColumn<ShapeBuilds, String> noCol = new TableColumn<ShapeBuilds, String>("No");
		noCol.setPrefWidth(51);

		noCol.setCellValueFactory(
			new PropertyValueFactory<ShapeBuilds, String>("no")
		);

		TableColumn<ShapeBuilds, String> xCol = new TableColumn<ShapeBuilds, String>("X");
		xCol.setPrefWidth(61);

		xCol.setCellValueFactory(
			new PropertyValueFactory<ShapeBuilds, String>("x")
		);

		TableColumn<ShapeBuilds, String> yCol = new TableColumn<ShapeBuilds, String>("Y");
		yCol.setPrefWidth(61);

		yCol.setCellValueFactory(
			new PropertyValueFactory<ShapeBuilds, String>("y")
		);

		TableColumn<ShapeBuilds, String> bobotCol = new TableColumn<ShapeBuilds, String>("Bobot");
		// bobotCol.setMaxWidth(150);
		bobotCol.setPrefWidth(125);

		bobotCol.setCellValueFactory(
			new PropertyValueFactory<ShapeBuilds, String>("bobot")
		);

		table.getColumns().addAll(Arrays.asList(noCol, xCol, yCol, bobotCol));

		table.setItems(data);

		table.setLayoutX(25);
		table.setLayoutY(50);

		table.setPrefWidth(300);
		table.setPrefHeight(480);
		table.setStyle("-fx-font-size: 15pt");
		root2.getChildren().add(table);

		TextField addX = new TextField();
		addX.setPromptText("X");
		addX.setPrefWidth(70);

		TextField addY = new TextField();
		addY.setPromptText("Y");
		addY.setPrefWidth(70);

		TextField addBobot = new TextField();
		addBobot.setPromptText("Bobot");
		addBobot.setMaxWidth(150);
		
		Button addButton = new Button("Tambah");
		addButton.setPrefWidth(110);

		addX.setLayoutX(370);
		addX.setLayoutY(50);
		
		addY.setLayoutX(450);
		addY.setLayoutY(50);

		addBobot.setLayoutX(370);
		addBobot.setLayoutY(100);

		addButton.setLayoutX(370);
		addButton.setLayoutY(150);

		addX.setStyle("-fx-font-size: 15pt");
		addY.setStyle("-fx-font-size: 15pt");
		addBobot.setStyle("-fx-font-size: 15pt");
		addButton.setStyle("-fx-font-size: 15pt");

		TextField delTxt = new TextField();
		delTxt.setPromptText("NO");
		delTxt.setMaxWidth(110);
		
		Button delButton = new Button("Hapus");
		delButton.setPrefWidth(110);

		delTxt.setLayoutX(370);
		delTxt.setLayoutY(250);

		delButton.setLayoutX(370);
		delButton.setLayoutY(300);

		delTxt.setStyle("-fx-font-size: 15pt");
		delButton.setStyle("-fx-font-size: 15pt");

		Button startButton = new Button("MULAI\n GAME");
		startButton.setPrefWidth(190);
		startButton.setPrefHeight(110);

		startButton.setStyle("-fx-font-size: 21pt; -fx-base: #eef441");

		startButton.setLayoutX(350);
		startButton.setLayoutY(420);

		root2.getChildren().addAll(addX, addY, addBobot, addButton, delTxt, delButton, startButton);

		Timeline flasher = new Timeline(

		    new KeyFrame(Duration.seconds(0.5), e -> {
		        // use "flash" color
		        startButton.setStyle("-fx-font-size: 21pt; -fx-base: #151515");
		    }),

		    new KeyFrame(Duration.seconds(1.0), e -> {
		        // revert to regular color
		        startButton.setStyle("-fx-font-size: 21pt; -fx-base: #eef441");
		    })
		);
		flasher.setCycleCount(Animation.INDEFINITE);
		flasher.play();


		Group root3 = new Group();
		Scene gameScene = new Scene(root3, Constant.WIDTH, Constant.HEIGHT);//scene dengan warna hijau

		army = new MyWarShip();
		army.setSize(60);
		army.setPosition(275, 480);
		army.setVelocity(5);
		army.addToGroup(root3);
		army.requestFocus();//keyevent require focus

		// int shot = 1;

		Duration fps = Duration.millis(1000/60);
		KeyFrame oneFrame = new KeyFrame(fps,new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent event){
				if(time%60==0){
					//untuk memunculkan bola peluru
					if (army.getShot()) {
						army.shoot(root3);
					}
				}
				
				//untuk menggerakan peluru
				army.updatePeluru(root3);
				time++;
			}
		});

		Timeline ship = new Timeline();
		ship.setCycleCount(Animation.INDEFINITE);
		ship.getKeyFrames().add(oneFrame);
		ship.play();

		army.setOnKeyPressed(new EventHandler<KeyEvent>(){
	        @Override
	        public void handle(KeyEvent key) {
	            if (key.getCode().equals(KeyCode.RIGHT)) {
	                // imageX += 10;
	            	System.out.println("move right");
	            	updateImageView(1);
	            	
	            }else if (key.getCode().equals(KeyCode.LEFT)) {
	                // imageX -= 10;
	            	System.out.println("move left");

	            	updateImageView(-1);
	            }
	            if (key.getCode().equals(KeyCode.SPACE)) {
	                // imageX += 10;
	            	System.out.println("Shoot");
					// ship.play();
					army.setShot(true);
	            }

	        }

	        private void updateImageView(int x) {
	        	double geser = army.getXShip()+(x*army.getVelocity());
	        	if ( geser > -5 &&  geser < Constant.WIDTH-army.getSize()+5){
					army.setPosition(geser, army.getYShip());
	        	}
	        }
      	});

	    army.setOnKeyReleased(new EventHandler<KeyEvent>(){
            public void handle(KeyEvent key) {
				if (key.getCode().equals(KeyCode.SPACE)) {
	                  // imageX += 10;
	            	System.out.println("Stop Shoot");
					// ship.play();
					army.setShot(false);
					// ship.getKeyFrames().add(oneFrame);
	            }
				// army.setShot(false);
            }
        });
		// root3.getChildren().add(army);

		delButton.setOnAction(new EventHandler<ActionEvent>(){//eventhandler ketika tombol start ditekan
			@Override
				public void handle(ActionEvent e){
					int xdel = 0;
					String del = delTxt.getText();
					if (del != null && !del.trim().equals("")) {
						try{
							xdel = Integer.parseInt(del);
							System.out.println("Delete item in row number "+del);
						}catch(NumberFormatException num){
							Alert alert = new Alert(AlertType.ERROR);
						    alert.setTitle("Unable to delete Target");
						    alert.setHeaderText("Penghapusan Target Gagal");
						    alert.setContentText("Tolong Masukan Input Bilangan Bulat saja !");
						    alert.showAndWait();
						}
					}else{
						Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to delete Target");
					    alert.setHeaderText("Penghapusan Target Gagal");
					    alert.setContentText("Tolong Masukan Input dengan benar!");
					    alert.showAndWait();
					}
					
					if(xdel<=num && xdel>0){
						//select data
				        table.requestFocus();
				        table.getSelectionModel().select(xdel-1);
				        table.getFocusModel().focus(xdel-1);

				        //ask user whenever delete it or not?
				        ButtonType hapus = new ButtonType("Hapus", ButtonBar.ButtonData.OK_DONE);
						ButtonType batal = new ButtonType("Batal", ButtonBar.ButtonData.CANCEL_CLOSE);
						Alert alert = new Alert(AlertType.WARNING,
						        "Yakin mau menghapus Target?",
						        hapus,
						        batal);

						alert.setTitle("Konfirmasi Hapus");
						Optional<ButtonType> result = alert.showAndWait();

						if (result.isPresent() && result.get() == hapus) {
							table.getItems().removeAll(
				                table.getSelectionModel().getSelectedItems()
					        );
			                num-=1;
			                refreshNumbering();
							System.out.println("row number "+del+" deleted");
						}

					}else{
						//tell the user that data isn't valid
						Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to delete Target");
					    alert.setHeaderText("Penghapusan Target Gagal");
					    alert.setContentText("Target Belum Ada!");
					    alert.showAndWait();
					}


				}
		});
		

		bStart.setOnAction(new EventHandler<ActionEvent>(){//eventhandler ketika tombol start ditekan
			@Override
				public void handle(ActionEvent e){
					System.out.println("Send to Tablescene");
					stage.setScene(listscene);//ganti scene ke scene berikutnya
					stage.centerOnScreen();
				}
		});

		bKeluar.setOnAction(new EventHandler<ActionEvent>(){//eventhandler ketika tombol start ditekan
			@Override
				public void handle(ActionEvent e){
					System.out.println("Quit The Game");
					Platform.exit();//exit tha apps
				}
		});

		addButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				if (!addX.getText().trim().equals("") && !addY.getText().trim().equals("") 
					&& !addBobot.getText().trim().equals("")) {//1st validation
					try{//2nd validation
						//try parse
						int x = Integer.parseInt(addX.getText());
						int y = Integer.parseInt(addY.getText());
						int bobot = Integer.parseInt(addBobot.getText());

						num++;
						data.add(new ShapeBuilds(
						""+num,
						addX.getText(),
						addY.getText(),
						addBobot.getText()
						));
						System.out.println("add item "+addX.getText()+" "+addY.getText()+" "+addBobot.getText()+"to Table");
					}catch(NumberFormatException num){
						Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to add Target");
					    alert.setHeaderText("Penambahan Target Gagal");
					    alert.setContentText("Tolong Masukan Input Bilangan Bulat saja !");
					    alert.showAndWait();
					}
					
					addX.setText("");
					addY.setText("");
					addBobot.setText("");
				}else{
					Alert alert = new Alert(AlertType.ERROR);
					    alert.setTitle("Unable to add Target");
					    alert.setHeaderText("Penambahan Target Gagal");
					    alert.setContentText("Masukkan Input dengan Benar!");
					    alert.showAndWait();
				}
			}
		});


		bStart.setOnMouseEntered(new EventHandler<MouseEvent>() {//eventhandle ketika mouse ada di tombol
            @Override
            public void handle(MouseEvent event) {
				bStart.setStyle("-fx-base: #151515;-fx-font-size: 50pt; -fx-font-family: 'segoe ui'; -fx-border-radius: 80 0 80 0; -fx-background-radius: 80 0 80 0;");//styling
            }
        });

        bStart.setOnMouseExited(new EventHandler<MouseEvent>() {//eventhandle ketika mouse meninggalkan tombol
            @Override
            public void handle(MouseEvent event) {
				bStart.setStyle("-fx-base: #eef441;-fx-font-size: 50pt; -fx-font-family: 'segoe ui'; -fx-border-radius: 80 0 80 0; -fx-background-radius: 80 0 80 0;");//styling
            }
        });

        startButton.setOnAction(new EventHandler<ActionEvent>(){//eventhandler ketika tombol start ditekan
			@Override
				public void handle(ActionEvent e){
					System.out.println("Send to gameScene");
					stage.setScene(gameScene);//ganti scene ke scene berikutnya
					addStar(root3);	
					stage.centerOnScreen();
				}
		});

        stage.setScene(scene);//defualt scene
		stage.setResizable(false);
		stage.setTitle("Shape Shooter Game");//windows title
		stage.centerOnScreen();
		stage.show();
	}

	//coming soon
	private void refreshNumbering(){
		// List<ShapeBuilds> data = table.getItems();
		//updating
		for (int i=0; i<data.size(); i+=1) {
			data.get(i).setNo(Integer.toString(i+1));
		}
	}

	private void addStar(Group group){

		Bintang[] arrBin = new Bintang[num];
		for (int i=0; i < num; i+=1) {
			arrBin[i] = new Bintang(5);
			float x = Float.parseFloat(data.get(i).getX());
			float y = Float.parseFloat(data.get(i).getY());
			int color = Integer.parseInt(data.get(i).getBobot());
			arrBin[i].setCol(colorChooser(color));
			arrBin[i].setPosition(x, y);
			arrBin[i].addToGroup(group);
		}
	}

	public String colorChooser(int power){
		if (power>0 && power<6) {
			return "#000000";
		}else if(power<11){
			return "#80f441";
		}else{
			return "#f49542";
		}
	}

	
}