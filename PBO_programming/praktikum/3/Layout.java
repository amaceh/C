import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.VPos;
import javafx.geometry.HPos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Hyperlink;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.scene.paint.Color;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class Layout extends Application{
	public static void main(String[] args) {
		launch(Layout.class, args);
	}

	@Override
	public void start(Stage stage){
		BorderPane border = new BorderPane();
		//set all layout class into BorderPane
		border.setTop(addHBox());
		border.setLeft(addVBox());
		border.setCenter(addGridPane());
		border.setRight(addTilePane());
		border.setStyle("-fx-background-color: #2b4da4;");
		Scene scene = new Scene(border);
		stage.setScene(scene);
		stage.setTitle("Belajar Layouting");
		stage.show();
	}
	/**
	* Top side of the scene
	*@return Hbox
	*/
	private HBox addHBox(){
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(10,10,10,10));
		hbox.setSpacing(10);
		
		ImageView imageLogo = new ImageView(new Image(getClass().getResourceAsStream("graphics/LOGO.png")));		
		imageLogo.setFitHeight(50);
		imageLogo.setFitWidth(150);

		//lomba button
		Button buttonLomba = new Button("Lomba");
		buttonLomba.setPrefSize(100,20);
		buttonLomba.setStyle("-fx-background-color: #00ff2a;");
		//lomba Acara
		Button buttonAcara = new Button("Acara");
		buttonAcara.setPrefSize(100,20);
		hbox.getChildren().addAll(imageLogo,buttonLomba, buttonAcara);
		buttonAcara.setStyle("-fx-background-color: #00ff2a;");

		return hbox;
	}

	/**
	* left side of the scene
	*@return Vbox
	*/
	private VBox addVBox(){
		VBox vbox= new VBox();
		vbox.setPadding(new Insets(10));
		vbox.setSpacing(8);
		vbox.setStyle("-fx-background-color: #ffff00;");


		Text judul = new Text("Data Lomba");
		judul.setFont(Font.font("arial", FontWeight.BOLD, 14));
		vbox.getChildren().add(judul);

		Hyperlink options[] = new Hyperlink[]{
			new Hyperlink("CSPC"),
			new Hyperlink("LCA"),
			new Hyperlink("LF"),
			new Hyperlink("KJ"),
			new Hyperlink("OTIK"),
			new Hyperlink("LDG"),
			new Hyperlink("PCA"),
			new Hyperlink("LCW"),
		};
		for(final Hyperlink hyperlink : options) {
            hyperlink.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    getHostServices().showDocument("http://dinamik.cs.upi.edu/lomba/view/"+hyperlink.getText());
                }
            });
        }
		for (int i=0; i<8; i++) {
			VBox.setMargin(options[i], new Insets(0,0,0,8));
			vbox.getChildren().add(options[i]);
		}

		return vbox;
	}

	/**
	* left side of the scene
	*@return Gridpane
	*/
	private GridPane addGridPane(){
		GridPane grid = new GridPane();
		grid.setHgap(10);
		grid.setVgap(10);
		grid.setPadding(new Insets(0,10,0,10));
		grid.setStyle("-fx-background-color: #ffffff;");


		Text kategori = new Text("Data Dinamik");
		kategori.setFont(Font.font("Arial", FontWeight.BOLD,18));
		grid.add(kategori,0,0);

		Text judulGrafik = new Text("12");
		judulGrafik.setFont(Font.font("Arial", FontWeight.BOLD,18));
		grid.add(judulGrafik,1,0);

		ImageView imageChart = new ImageView(new Image(getClass().getResourceAsStream("graphics/piechart.png")));;
		//col idx, row idx, colspan //rowspan		
		grid.add(imageChart, 1, 2, 2, 1);

		return grid;
	}
	/**
	* right side of the scene
	*@return TilePane
	*/
	private TilePane addTilePane(){
		TilePane tile= new TilePane();
		tile.setPadding(new Insets(5,5,5,5));
		tile.setVgap(4);
		tile.setHgap(4);
		tile.setPrefColumns(2);
		ImageView pages[]=new ImageView[8];
		for (int i=0;i<8 ;i++ ) {
			Image img = new Image("graphics/lomba_"+(i+1)+".png");
			ImageView imgV= new ImageView();
			imgV.setImage(img);
			imgV.setFitHeight(80);
			imgV.setFitWidth(80);
			pages[i]=imgV;
			tile.getChildren().add(pages[i]);
		}
		return tile;
	}
}

