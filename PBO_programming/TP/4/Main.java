import view.Table;
//call the view
import javafx.application.Application;
import javafx.stage.Stage;

//main class
public class Main extends Application{
	
	public static void main(String[] args){
		launch(args);
	}
	
	@Override
	public void start(Stage stage){
		//show the view
		Table tampilBuuk = new Table();
		tampilBuuk.tampil(stage);
	}
	
}