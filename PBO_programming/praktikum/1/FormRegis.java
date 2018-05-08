import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.control.ComboBox;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class FormRegis extends Application{
	@Override 
	public void start (Stage stage) {
		//create scene 1
		Group root1= new Group();
		Scene scene1 = new Scene(root1, 300, 400);
		//create form for user input
		Label fName= new Label("First Name");
		fName.setLayoutX(30);
		fName.setLayoutY(40);
		root1.getChildren().add(fName);

		TextField tfName= new TextField();
		tfName.setLayoutX(130);
		tfName.setLayoutY(40);
		root1.getChildren().add(tfName);

		Label lName= new Label("Last Name");
		lName.setLayoutX(30);
		lName.setLayoutY(80);
		root1.getChildren().add(lName);

		TextField tfLName= new TextField();
		tfLName.setLayoutX(130);
		tfLName.setLayoutY(80);
		root1.getChildren().add(tfLName);

		Label lGender= new Label("Gender(M/F)");
		lGender.setLayoutX(30);
		lGender.setLayoutY(120);
		root1.getChildren().add(lGender);


		ComboBox<String> tfGender = new ComboBox<String>();
		tfGender.getItems().addAll("M", "F");
		tfGender.setLayoutX(130);
		tfGender.setLayoutY(120);
		tfGender.setValue("M");
		root1.getChildren().add(tfGender);

		Label lUname= new Label("Username");
		lUname.setLayoutX(30);
		lUname.setLayoutY(160);
		root1.getChildren().add(lUname);

		TextField tfUname= new TextField();
		tfUname.setLayoutX(130);
		tfUname.setLayoutY(160);
		root1.getChildren().add(tfUname);

		Label lPass= new Label("Password");
		lPass.setLayoutX(30);
		lPass.setLayoutY(200);
		root1.getChildren().add(lPass);

		PasswordField pass= new PasswordField();
		pass.setLayoutX(130);
		pass.setLayoutY(200);
		root1.getChildren().add(pass);

		//membuat tombol login
		Button bLogin = new Button("Masuk");
		bLogin.setLayoutX(130);
		bLogin.setLayoutY(240);
		root1.getChildren().add(bLogin);

		//create scene 2
		Group root2 = new Group();
		Scene scene2 = new Scene(root2, 300, 400);

		Label masukF = new Label("Selamat Datang, Mbak!");
		masukF.setLayoutX(100);
		masukF.setLayoutY(100);

		Label masukM = new Label("Selamat Datang, Mas!");
		masukM.setLayoutX(100);
		masukM.setLayoutY(100);

		//create scene 3
		Group root3 = new Group();
		Scene scene3 = new Scene(root3, 300, 400);

		Label gmasuk = new Label("I dunno ur gender");
		gmasuk.setLayoutX(40);
		gmasuk.setLayoutY(40);
		root3.getChildren().add(gmasuk);

		Label gmasuk2 = new Label("u may try again!");
		gmasuk2.setLayoutX(40);
		gmasuk2.setLayoutY(60);
		root3.getChildren().add(gmasuk2);

		//compile gender with user input

		bLogin.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					//male gender
					if (tfGender.getValue().equals("M")) {
						root2.getChildren().add(masukM);
						stage.setScene(scene2);
					}
					//female gender
					else if (tfGender.getValue().equals("F")) {
						root2.getChildren().add(masukF);
						stage.setScene(scene2);
					}

					//unknown gender
					// else{
					// 	stage.setScene(scene3);
					// }
				}
		});
		stage.setScene(scene1);
		stage.sizeToScene();
		stage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}
