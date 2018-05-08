import java.util.Random;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.Group;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;
//lot of class import

import global.Constant;
import entity.Ball;
import entity.SegiEnam;
import entity.Persegi;
import entity.PersegiBulat;
//import file class from global entity

public class Lmao extends Application{
	private int jumlah = 0;
	private int sh[]={0,0,0,0};
	//some attribute

	//main method
	public static void main(String[] args) {
		Application.launch(args);
	}

	@Override
	public void start(Stage stage){
		Group root1 = new Group();
		Scene scene = new Scene(root1, Constant.WIDTH, Constant.HEIGHT, Color.GREY);//scene dengan warna abu
		
		Text h1 = new Text("~ E S T E T I K A ~"); //header judul
		h1.setFont(Font.font("Calibri", FontWeight.BOLD, 50));//font option
		h1.setLayoutX(310); //x axis
		h1.setLayoutY(100); //y axis
		h1.setFill(Color.WHITE);//text color
		root1.getChildren().add(h1);//add to group

		Text h2 = new Text("1503631"); //footer
		h2.setFont(Font.font("Calibri", FontWeight.BOLD, 20));//font option
		h2.setLayoutX(10); //x axis
		h2.setLayoutY(540); //y axis
		h2.setFill(Color.WHITE);//white text color
		root1.getChildren().add(h2);//add to group


		Text h3 = new Text("Achmad Abdul Rofiq"); //footer
		h3.setFont(Font.font("Calibri", FontWeight.BOLD, 20));//font option
		h3.setLayoutX(790); //x axis
		h3.setLayoutY(540); //y axis
		h3.setFill(Color.WHITE);//white text color
		root1.getChildren().add(h3);//add to group

		Button bStart = new Button("MULAI");
		bStart.setLayoutX(390); //x, y axis
		bStart.setLayoutY(280);
		bStart.setStyle("-fx-font-size: 40pt; -fx-font-family: 'Calibry'; -fx-base: #48566d;");//start button layout style
		root1.getChildren().add(bStart);//add to scene

		

		BorderPane border = new BorderPane();//borderpane di dalam scene
		Pane center = new Pane(); //pane untuk animasi
	    center.setPrefSize(Constant.WIDTH,Constant.HEIGHT-100);//ukuran pane
		border.setTop(addHBox(center));//posisi atas borderpane diisi hbox
		border.setCenter(center);//posisi tengah borderpane diisi pane
		Scene scene2 = new Scene(border, Constant.WIDTH, Constant.HEIGHT);//masukan borderpane ke scene

		bStart.setOnAction(new EventHandler<ActionEvent>(){//eventhandler ketika tombol start ditekan
			@Override
				public void handle(ActionEvent e){
					System.out.println("Start to the main scene");
					stage.setScene(scene2);//ganti scene ke scene berikutnya
				}
		});
		bStart.setOnMouseEntered(new EventHandler<MouseEvent>() {//eventhandle ketika mouse ada di tombol
            @Override
            public void handle(MouseEvent event) {
				bStart.setStyle("-fx-base: #fff;-fx-font-size: 40pt; -fx-font-family: 'Calibry';");//styling
            }
        });
        bStart.setOnMouseExited(new EventHandler<MouseEvent>() {//eventhandle ketika mouse meninggalkan tombol
            @Override
            public void handle(MouseEvent event) {
				bStart.setStyle("-fx-base: #48566d;-fx-font-size: 40pt; -fx-font-family: 'Calibry';");//styling
            }
        });
		stage.setScene(scene);//defualt scene
		stage.setResizable(false);//to hide polygon well, unable user to increase window size
		stage.setTitle("Simple Animation with E S T E T I K A");//windows title
		stage.show();
	}

	/**
		* Top side of the 2nd scene
		*@return Hbox
	*/
	private HBox addHBox(Pane center){
		HBox hbox = new HBox();//instance
		hbox.setPadding(new Insets(10,10,10,10));
		hbox.setSpacing(10);
		hbox.setStyle("-fx-background-color: #2e343d;");//header styling

		Label ljumlah= new Label("Jumlah Objek : ");//label jumlah objek
		Label lcount= new Label(Integer.toString(this.jumlah));
		ljumlah.setStyle("-fx-text-fill:white;");//styling label
		lcount.setStyle("-fx-text-fill:white;");

		//lomba button
		Button bTambah = new Button("Tambah");//button tambah objek
		bTambah.setPrefSize(100,20);//preferred size
		bTambah.setStyle("-fx-background-color: #fff;");//button styling
		bTambah.setOnAction(new EventHandler<ActionEvent>(){//eventhandler ketika button tambah ditekan
			@Override
				public void handle(ActionEvent e){
					jumlah+=1;//tambah counter
					if (jumlah<=20) {//jika jumlah shape belum habis
						lcount.setText(Integer.toString(jumlah));//ubah label jumlah sesuai jumlah sekarang
						//sould be a procedure to summon animation
						
						/////deklarasi array of object/////
						SegiEnam hexa[] = new SegiEnam[5];
						Persegi kotak[] = new Persegi[5];
						PersegiBulat kotax[] = new PersegiBulat[5];
						Ball bola[] = new Ball[5];

						for (int i=0;i<5 ; i+=1) {
							hexa[i] = new SegiEnam(center, 30);//hexagon is complex, sizenya langsung ditentukan di construktor
							kotak[i] = new Persegi(center);
							kotax[i] = new PersegiBulat(center);
							bola[i] = new Ball(center);
						}
						//////////////////////////////////////
						//get curent shape random
						int shapeControl = shapeControl(sh);
						
						if (shapeControl==1) {//if current shape is hexagon
							//pindahkan didalam scene
							//random position
							hexa[sh[0]].setPosition(randInt(1,Math.round(Constant.WIDTH-50)),randInt(1,Math.round(Constant.HEIGHT-100)));
							hexa[sh[0]].setVelocity(2);//change the speed
							sh[0]+=1;//tambah counter
							System.out.println("shape 1");
						}else if (shapeControl==2){//if the shape is rectangle
							//change the size
							kotak[sh[1]].setSide(50);
							//move to the scene in random positin
							kotak[sh[1]].setPosition(randInt(1,Math.round(Constant.WIDTH-50)),randInt(0,Math.round(Constant.HEIGHT-100)));
							kotak[sh[1]].setVelocity(2);
							sh[1]+=1;//add counter
							System.out.println("shape 2");
						}else if (shapeControl==3){//if the shape is rounded rectangle
							//do same things
							kotax[sh[2]].setSide(50);
							kotax[sh[2]].setPosition(randInt(1,Math.round(Constant.WIDTH-50)),randInt(0,Math.round(Constant.HEIGHT-100)));
							kotax[sh[2]].setVelocity(2);
							sh[2]+=1;
							System.out.println("shape 3");
						}else if (shapeControl==4){//if thw shape is circle
							//do the same thing
							bola[sh[3]].setRadius(25);
							bola[sh[3]].setPosition(randInt(1,Math.round(Constant.WIDTH-50)),randInt(0,Math.round(Constant.HEIGHT-100)));
							bola[sh[3]].setVelocity(2);
							sh[3]+=1;
							System.out.println("shape 4");
						}

						Duration fps = Duration.millis(1000/60);//time duration
						int velo[]=new int[20];//array penentu arah
						int velo2[]=new int[20];
						//lets make the direction random
						for (int i=0; i<20; i+=1) {
							velo[i]=randVelo();
							velo2[i]=randVelo();
						}
				        KeyFrame oneFrame = new KeyFrame(fps,
						new EventHandler<ActionEvent>(){//eventhandler untuk animasi
							@Override
							public void handle(final ActionEvent t){
								//penggerak shape hexagon
								hexa[0].setPosition(hexa[0].getX()+(hexa[0].getVelocity()*velo[0]), hexa[0].getY()+(hexa[0].getVelocity()*velo2[0]));
								if (hexa[0].getX()>=Constant.WIDTH-50 || hexa[0].getY()>Constant.HEIGHT-100 || hexa[0].getY()<0 || hexa[0].getX()<0) {
									hexa[0].bounce();
								}
								//penggerak shape hexagon
								hexa[1].setPosition(hexa[1].getX()+(hexa[1].getVelocity()*velo[1]), hexa[1].getY()+(hexa[1].getVelocity()*velo2[1]));
								if (hexa[1].getX()>=Constant.WIDTH-50 || hexa[1].getY()>Constant.HEIGHT-100 || hexa[1].getY()<0 || hexa[1].getX()<0) {
									hexa[1].bounce();
								}
								//penggerak shape hexagon
								hexa[2].setPosition(hexa[2].getX()+(hexa[2].getVelocity()*velo[2]), hexa[2].getY()+(hexa[2].getVelocity()*velo2[2]));
								if (hexa[2].getX()>=Constant.WIDTH-50 || hexa[2].getY()>Constant.HEIGHT-100 || hexa[2].getY()<0 || hexa[2].getX()<0) {
									hexa[2].bounce();
								}
								//penggerak shape hexagon
								hexa[3].setPosition(hexa[3].getX()+(hexa[3].getVelocity()*velo[3]), hexa[3].getY()+(hexa[3].getVelocity()*velo2[3]));
								if (hexa[3].getX()>=Constant.WIDTH-50 || hexa[3].getY()>Constant.HEIGHT-100 || hexa[3].getY()<0 || hexa[3].getX()<0) {
									hexa[3].bounce();
								}
								//penggerak shape hexagon
								hexa[4].setPosition(hexa[4].getX()+(hexa[4].getVelocity()*velo[4]), hexa[4].getY()+(hexa[4].getVelocity()*velo2[4]));
								if (hexa[4].getX()>=Constant.WIDTH-50 || hexa[4].getY()>Constant.HEIGHT-100 || hexa[4].getY()<0 || hexa[4].getX()<0) {
									hexa[4].bounce();
								}
								//////////////////////////////////
								//penggerak shape kotak
								kotak[0].setPosition(kotak[0].getX()+(kotak[0].getVelocity()*velo[5]), kotak[0].getY()+(kotak[0].getVelocity()*velo2[5]));
								if (kotak[0].getX()>=Constant.WIDTH-50 || kotak[0].getY()>Constant.HEIGHT-100 || kotak[0].getY()<0 || kotak[0].getX()<0) {
									kotak[0].bounce();
								}
								//penggerak shape kotak
								kotak[1].setPosition(kotak[1].getX()+(kotak[1].getVelocity()*velo[6]), kotak[1].getY()+(kotak[1].getVelocity()*velo2[6]));
								if (kotak[1].getX()>=Constant.WIDTH-50 || kotak[1].getY()>Constant.HEIGHT-100 || kotak[1].getY()<0 || kotak[1].getX()<0) {
									kotak[1].bounce();
								}
								//penggerak shape kotak
								kotak[2].setPosition(kotak[2].getX()+(kotak[2].getVelocity()*velo[7]), kotak[2].getY()+(kotak[2].getVelocity()*velo2[7]));
								if (kotak[2].getX()>=Constant.WIDTH-50 || kotak[2].getY()>Constant.HEIGHT-100 || kotak[2].getY()<0 || kotak[2].getX()<0) {
									kotak[2].bounce();
								}
								//penggerak shape kotak
								kotak[3].setPosition(kotak[3].getX()+(kotak[3].getVelocity()*velo[8]), kotak[3].getY()+(kotak[3].getVelocity()*velo2[8]));
								if (kotak[3].getX()>=Constant.WIDTH-50 || kotak[3].getY()>Constant.HEIGHT-100 || kotak[3].getY()<0 || kotak[3].getX()<0) {
									kotak[3].bounce();
								}
								//penggerak shape kotak
								kotak[4].setPosition(kotak[4].getX()+(kotak[4].getVelocity()*velo[9]), kotak[4].getY()+(kotak[4].getVelocity()*velo2[9]));
								if (kotak[4].getX()>=Constant.WIDTH-50 || kotak[4].getY()>Constant.HEIGHT-100 || kotak[4].getY()<0 || kotak[4].getX()<0) {
									kotak[4].bounce();
								}
								//////////////////////////////////////////
								//penggerak shape kotak lengkung
								kotax[0].setPosition(kotax[0].getX()+(kotax[0].getVelocity()*velo[10]), kotax[0].getY()+(kotax[0].getVelocity()*velo2[10]));
								if (kotax[0].getX()>=Constant.WIDTH-50 || kotax[0].getY()>Constant.HEIGHT-100 || kotax[0].getY()<0 || kotax[0].getX()<0) {
									kotax[0].bounce();
								}
								//penggerak shape kotak lengkung
								kotax[1].setPosition(kotax[1].getX()+(kotax[1].getVelocity()*velo[11]), kotax[1].getY()+(kotax[1].getVelocity()*velo2[11]));
								if (kotax[1].getX()>=Constant.WIDTH-50 || kotax[1].getY()>Constant.HEIGHT-100 || kotax[1].getY()<0 || kotax[1].getX()<0) {
									kotax[1].bounce();
								}
								//penggerak shape kotak lengkung
								kotax[2].setPosition(kotax[2].getX()+(kotax[2].getVelocity()*velo[12]), kotax[2].getY()+(kotax[2].getVelocity()*velo2[12]));
								if (kotax[2].getX()>=Constant.WIDTH-50 || kotax[2].getY()>Constant.HEIGHT-100 || kotax[2].getY()<0 || kotax[2].getX()<0) {
									kotax[2].bounce();
								}
								//penggerak shape kotak lengkung
								kotax[3].setPosition(kotax[3].getX()+(kotax[3].getVelocity()*velo[13]), kotax[3].getY()+(kotax[3].getVelocity()*velo2[13]));
								if (kotax[3].getX()>=Constant.WIDTH-50 || kotax[3].getY()>Constant.HEIGHT-100 || kotax[3].getY()<0 || kotax[3].getX()<0) {
									kotax[3].bounce();
								}
								//penggerak shape kotak lengkung
								kotax[4].setPosition(kotax[4].getX()+(kotax[4].getVelocity()*velo[14]), kotax[4].getY()+(kotax[4].getVelocity()*velo2[14]));
								if (kotax[4].getX()>=Constant.WIDTH-50 || kotax[4].getY()>Constant.HEIGHT-100 || kotax[4].getY()<0 || kotax[4].getX()<0) {
									kotax[4].bounce();
								}
								///////////////////////////////////////
								//penggerak shape bola
								bola[0].setPosition(bola[0].getX()+(bola[0].getVelocity()*velo[15]), bola[0].getY()+(bola[0].getVelocity()*velo2[15]));
								if (bola[0].getX()>=Constant.WIDTH-50 || bola[0].getY()>Constant.HEIGHT-100 || bola[0].getY()<0 || bola[0].getX()<0) {
									bola[0].bounce();
								}
								//penggerak shape bola
								bola[1].setPosition(bola[1].getX()+(bola[1].getVelocity()*velo[16]), bola[1].getY()+(bola[1].getVelocity()*velo2[16]));
								if (bola[1].getX()>=Constant.WIDTH-50 || bola[1].getY()>Constant.HEIGHT-100 || bola[1].getY()<0 || bola[1].getX()<0) {
									bola[1].bounce();
								}
								//penggerak shape bola
								bola[2].setPosition(bola[2].getX()+(bola[2].getVelocity()*velo[17]), bola[2].getY()+(bola[2].getVelocity()*velo2[17]));
								if (bola[2].getX()>=Constant.WIDTH-50 || bola[2].getY()>Constant.HEIGHT-100 || bola[2].getY()<0 || bola[2].getX()<0) {
									bola[2].bounce();
								}
								//penggerak shape bola
								bola[3].setPosition(bola[3].getX()+(bola[3].getVelocity()*velo[18]), bola[3].getY()+(bola[3].getVelocity()*velo2[18]));
								if (bola[3].getX()>=Constant.WIDTH-50 || bola[3].getY()>Constant.HEIGHT-100 || bola[3].getY()<0 || bola[3].getX()<0) {
									bola[3].bounce();
								}
								//penggerak shape bola
								bola[4].setPosition(bola[4].getX()+(bola[4].getVelocity()*velo[19]), bola[4].getY()+(bola[4].getVelocity()*velo2[19]));
								if (bola[4].getX()>=Constant.WIDTH-50 || bola[4].getY()>Constant.HEIGHT-100 || bola[4].getY()<0 || bola[4].getX()<0) {
									bola[4].bounce();
								}
							}
						});
				        Timeline t1 = new Timeline();//intance
						t1.setCycleCount(Animation.INDEFINITE);//make it indefinite animation
						t1.getKeyFrames().add(oneFrame);//add to keyframe
						t1.play();
					}else{//if the limit is reached
						//show the alert
						Alert alert = new Alert(AlertType.INFORMATION);//instance, info type
					    alert.setTitle("Unable to add object");
					    alert.setHeaderText("Sorry....");
					    alert.setContentText("you cant add more object :(");
					    alert.showAndWait();//show the alert
					}
				}
		});
		bTambah.setOnMouseEntered(new EventHandler<MouseEvent>() {//eventhandle ketika mouse ada pada tombol
            @Override
            public void handle(MouseEvent event) {
				bTambah.setStyle("-fx-background-color: grey;");//styling
            }
        });
        bTambah.setOnMouseExited(new EventHandler<MouseEvent>() {//eventhandle ketika mouse meninggalkan tombol
            @Override
            public void handle(MouseEvent event) {
				bTambah.setStyle("-fx-background-color: #fff;");//styling
            }
        });

		//lomba Acara
		Button bKeluar = new Button("Keluar");//another button
		bKeluar.setPrefSize(100,20);//prefered size
		bKeluar.setStyle("-fx-background-color: #fff;");//styling
        bKeluar.setOnAction(new EventHandler<ActionEvent>(){//eventhandle ketika tombol ditekan
			@Override
				public void handle(ActionEvent e){
					Platform.exit();//exit tha apps
				}
		});
		bKeluar.setOnMouseEntered(new EventHandler<MouseEvent>() {//eventhandle ketika mouse ada pada tombol
            @Override
            public void handle(MouseEvent event) {
				bKeluar.setStyle("-fx-background-color: grey;");//layouting
            }
        });
        bKeluar.setOnMouseExited(new EventHandler<MouseEvent>() {//eventhandle ketika mouse meninggalkan tombol
            @Override
            public void handle(MouseEvent event) {
				bKeluar.setStyle("-fx-background-color: #fff;");//layouting
            }
        });

        //set layout cant be used in hbox.
        //then just make "a right aligment" hbox inside hbox
        HBox buttonCont= new HBox(bTambah,bKeluar);
    	HBox.setHgrow(buttonCont, Priority.ALWAYS );
   		buttonCont.setAlignment( Pos.CENTER_RIGHT );
		buttonCont.setSpacing(10);

		hbox.getChildren().addAll(ljumlah, lcount, buttonCont);
		return hbox;
	}
	//random int procedure
	private int randInt(int min, int max) {

	    Random rand = new Random();//instance

	    // nextInt is normally exclusive of the top value,
	    // so add 1 to make it inclusive
	    int randomNum = rand.nextInt((max - min) + 1) + min;

	    return randomNum;
	}

	private int randVelo(){//procedure untuk merandom arah gerakan
		Random random = new Random();
		
		return random.nextBoolean() ? 1 : -1;
		//negative or positive
	}
	//procedure to limit every shape
	//we instance 5 object so every shape must be 5 or less
	private int shapeControl(int a[]){
		int num = randInt(1,4);//get random number beetween 1 and 4
		//do recursive if shae reach its limit
		if (a[0]>4 && num ==1) {
			num=shapeControl(a);
		}
		if (a[1]>4 && num ==2) {
			num=shapeControl(a);
		}
		if (a[2]>4 && num ==3) {
			num=shapeControl(a);
		}
		if (a[3]>4 && num ==4) {
			num=shapeControl(a);
		}
		return num;
	}
}
