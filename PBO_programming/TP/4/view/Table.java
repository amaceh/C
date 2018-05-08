package view;

import java.util.Optional;
import javafx.application.Application;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.scene.control.Label;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn.CellEditEvent;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.Group;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.util.Callback;

import controller.ProsesBuku;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;



//table class
public class Table{
	//blank contructor
	public Table(){
	}
	
	public static class DaftarBuku{//class for tableview item
		//id is required for update
		private final SimpleStringProperty ID;
		private final SimpleStringProperty JUDUL;
		private final SimpleStringProperty PENULIS;
		
		//constructor
		private DaftarBuku(String ID,String JD,String PN){
			this.ID = new SimpleStringProperty(ID);
			this.JUDUL = new SimpleStringProperty(JD);
			this.PENULIS = new SimpleStringProperty(PN);
		}

		//attribute set and get
		public String getId(){
			return ID.get();
		}
		
		public void setId(String ID){
			this.ID.set(ID);
		}


		public String getJudul(){
			return JUDUL.get();
		}
		
		public void setJudul(String JD){
			JUDUL.set(JD);
		}
		
		public String getPenulis(){
			return PENULIS.get();
		}
		
		public void setPenulis(String PN){
			PENULIS.set(PN);
		}
	}

	//attribute
	//tableview	that contain DaftarBuku
	private TableView<DaftarBuku> table = new TableView<DaftarBuku>();
	//observable list to contain tableview item
	private final ObservableList<DaftarBuku> data2 = FXCollections.observableArrayList();
	
	
	public void tampil(Stage stage){
		//make same layout component
		HBox hbx = new HBox();
		hbx.setPadding(new Insets(10,10,10,10));
		VBox leftvb = new VBox();
		VBox rightvb = new VBox();
		//call the controller
		ProsesBuku buuks = new ProsesBuku();
		Group root = new Group();
		Scene scene = new Scene(new Group());

		//set windows
		stage.setTitle("Nyak Buku List");
		stage.setWidth(800);
		stage.setHeight(650);
		
		//top label
		final Label label = new Label("DAFTAR BUKU NYAK");
		//styling
		label.setStyle("-fx-font-size: 40pt; -fx-font-family: 'segoe ui';");
		
		//column of tableview
		TableColumn judulCol = new TableColumn("Judul Buku");
		judulCol.setPrefWidth(240);
		judulCol.setCellValueFactory(
			new PropertyValueFactory<DaftarBuku,String>("judul")
			);
		//column of tableview
		TableColumn penulisCol = new TableColumn("Penulis Buku");
		penulisCol.setPrefWidth(240);
		penulisCol.setCellValueFactory(
			new PropertyValueFactory<DaftarBuku,String>("penulis")
			);
		
		//eventhandle to edit a record (judul column)
		judulCol.setOnEditCommit(
			new EventHandler<CellEditEvent<DaftarBuku, String>>() {
				@Override
				public void handle(CellEditEvent<DaftarBuku, String> t) {
					DaftarBuku val=((DaftarBuku) t.getTableView().getItems().get(
						t.getTablePosition().getRow()));//get a single object to edit

					val.setJudul(t.getNewValue());//change in tableview
					// and update in DB
					buuks.ubahBuku(val.getId(),val.getJudul(),val.getPenulis());
				}
			}
			);

		//eventhandle to edit a record (judul column)

		penulisCol.setOnEditCommit(
			new EventHandler<CellEditEvent<DaftarBuku, String>>() {
				@Override
				public void handle(CellEditEvent<DaftarBuku, String> t) {
					DaftarBuku val=((DaftarBuku) t.getTableView().getItems().get(
						t.getTablePosition().getRow()));//get a single object to edit
					val.setPenulis(t.getNewValue());//change in tableview
					// and update in DB
					buuks.ubahBuku(val.getId(),val.getJudul(),val.getPenulis());
				}
			}
			);

		//add column to tableview
		table.getColumns().addAll(judulCol,penulisCol);
		table.setItems(data2);//add item to tableview
		table.setEditable(true);//make tableview editable
		table.setStyle("-fx-font-size: 12pt; -fx-font-family: 'segoe ui';");//styling
		//set table height
		table.setPrefHeight(520);
		table.setMaxWidth(480);

		//make a cellfactory(to enable edit on row)
		Callback<TableColumn, TableCell> cellFactory =
         new Callback<TableColumn, TableCell>() {
             public TableCell call(TableColumn p) {
                return new EditingCell();
             }
         };

		judulCol.setCellFactory(cellFactory);
		penulisCol.setCellFactory(cellFactory);
		
		leftvb.setSpacing(5);
		leftvb.setLayoutY(30);
		leftvb.getChildren().addAll(label,table);
		//add label tabel to left vbox

		leftvb.setPadding(new Insets(10,0,0,10));
		
		//list container
		List<String[]> dftr= new ArrayList<String[]>();
		
		try{
			buuks.proses();
			//get db contain
			
			dftr=buuks.getHasil();
		}catch(Exception e){
			System.out.println(buuks.getError());
		}
		
		for(String item[]:dftr){//foreach container
			data2.add(new DaftarBuku (
				item[0],
				item[1],
				item[2]
			));
    	}
		//add obeservable item to tableview
		table.setItems(data2);

		//----------Tambah Data ke table (Proses Add)
		//two text field to input data
		final TextField addJudul = new TextField();
		addJudul.setPromptText("Judul");
		addJudul.setMaxWidth(judulCol.getPrefWidth());
				
		final TextField addPenulis = new TextField();
		addPenulis.setPromptText("Penulis");
		addPenulis.setMaxWidth(penulisCol.getPrefWidth());
		
		//button to add data
		final Button addButton = new Button("Tambah");
		addButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				//add data ke list
				//secara otomatis tabel akan terupdate secara otomatis menyesuaikan data yang ada di dalam list
				if(!addJudul.getText().trim().isEmpty() ||
					!addPenulis.getText().trim().isEmpty()){//no blank
					buuks.tambahBuku(addJudul.getText(),addPenulis.getText());
					//get autoincrement id
					String id=buuks.getKode();
					//and add everything to tableview
					data2.add(new DaftarBuku(
						id,
						addJudul.getText(),
						addPenulis.getText())
					);

				}else{
					Alert alert = new Alert(AlertType.ERROR);
				    alert.setTitle("Blank Data");
				    alert.setHeaderText("Data tidak valid atau kosong");
				    alert.setContentText("Tolong Masukan Input yang sesuai.");
				    alert.showAndWait();
				}

				//make it blank again
				addJudul.setText("");
				addPenulis.setText("");
			}
		});

		//delete button
		final Button delButton = new Button("Hapus");
		delButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				//check if there is a selected item
				if (!table.getSelectionModel().getSelectedItems().isEmpty()){
					//make a custom button in alert
					ButtonType hapus = new ButtonType("Hapus", ButtonBar.ButtonData.OK_DONE);
					ButtonType batal = new ButtonType("Batal", ButtonBar.ButtonData.CANCEL_CLOSE);
					//delete process should asking user (data is Important)
					Alert alert = new Alert(AlertType.WARNING,
					        "Yakin mau hapus Data Buku ini?",
					        hapus,
					        batal);

					alert.setTitle("Konfirmasi Hapus");
					Optional<ButtonType> result = alert.showAndWait();//show the alert

					if (result.isPresent() && result.get() == hapus) {//if user comfirm to delete it
						DaftarBuku dft = table.getSelectionModel().getSelectedItem();
						buuks.hapusBuku(dft.getJudul(), dft.getPenulis());//delete record from DB
						table.getItems().removeAll(//and from tableview
			                table.getSelectionModel().getSelectedItem()
				        );
					}
				}
			}
		});

		//delete all button
		final Button delAllButton = new Button("Hapus Semua");
		delAllButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e){
				//delete process should asking user (data is Important)
				ButtonType hapus = new ButtonType("Hapus", ButtonBar.ButtonData.OK_DONE);
				ButtonType batal = new ButtonType("Batal", ButtonBar.ButtonData.CANCEL_CLOSE);
				Alert alert = new Alert(AlertType.WARNING,
				        "Yakin mau hapus semua DATA ini?\ndata yang terhapus TIDAK BISA DIKEMBALIKAN",
				        hapus,
				        batal);

				alert.setTitle("Konfirmasi Hapus");
				Optional<ButtonType> result = alert.showAndWait();//show the alert

				if (result.isPresent() && result.get() == hapus) {//if user comfirm to delete it
					buuks.hapusSemuaBuku();//delete from DB
					table.getItems().clear();//and delete from tableview
				}
			}
		});
		//some styling
		addJudul.setStyle("-fx-font-size: 12pt; -fx-font-family: 'segoe ui';");
		addPenulis.setStyle("-fx-font-size: 12pt; -fx-font-family: 'segoe ui';");
		addButton.setStyle("-fx-font-size: 20pt; -fx-font-family: 'segoe ui'; -fx-pref-width: 240px;");
		delButton.setStyle("-fx-font-size: 20pt; -fx-font-family: 'segoe ui'; -fx-pref-width: 240px;");
		delAllButton.setStyle("-fx-font-size: 20pt; -fx-font-family: 'segoe ui'; -fx-pref-width: 240px;");
		
		//add delete button to another vbox(container)
		//to place the button on the buttom of the right vbox
		VBox buttonCont= new VBox(delButton,delAllButton);
    	VBox.setVgrow(buttonCont, Priority.ALWAYS );
   		buttonCont.setAlignment( Pos.BOTTOM_RIGHT );
		buttonCont.setSpacing(10);

		//add textfield, add button and vbox container to right vbox
		rightvb.getChildren().addAll(addJudul,addPenulis,addButton,buttonCont);
		rightvb.setSpacing(3);
		//add left and right vboc to hbox
		hbx.getChildren().addAll(leftvb,rightvb);
		rightvb.setPadding(new Insets(80, 0, 0, 0));
		rightvb.setSpacing(10);
		hbx.setSpacing(20);
		//add hbox to group
		((Group) scene.getRoot()).getChildren().addAll(hbx);
		
		//show window
		stage.setScene(scene);
		stage.centerOnScreen();
		stage.show();
	}
	//a class to edit tableview in the row
	//source : javafx documentation
	//it improve UX while editing tableview
	class EditingCell extends TableCell<DaftarBuku, String> {

		private TextField textField;

		public EditingCell() {
		}

		@Override
		public void startEdit() {
			if (!isEmpty()) {
				super.startEdit();
				createTextField();
				setText(null);
				setGraphic(textField);
				textField.selectAll();
			}
		}

		@Override
		public void cancelEdit() {
			super.cancelEdit();

			setText((String) getItem());
			setGraphic(null);
		}

		@Override
		public void updateItem(String item, boolean empty) {
			
			super.updateItem(item, empty);

			if (empty) {
				setText(null);
				setGraphic(null);
			} else {
				if (isEditing()) {
					if (textField != null) {
						textField.setText(getString());
					}
					setText(null);
					setGraphic(textField);
				} else {
					setText(getString());
					setGraphic(null);
				}
			}
		}

		private void createTextField() {
			textField = new TextField(getString());
			textField.setMinWidth(this.getWidth() - this.getGraphicTextGap()* 2);
			textField.focusedProperty().addListener(new ChangeListener<Boolean>(){
				@Override
				public void changed(ObservableValue<? extends Boolean> arg0, 
					Boolean arg1, Boolean arg2) {
					if (!arg2) {
						commitEdit(textField.getText());
					}
				}
			});
		}

		private String getString() {
			return getItem() == null ? "" : getItem().toString();
		}
	}
}


