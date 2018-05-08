package view;

import javafx.application.Application;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

import controller.ProsesTelepon;

public class Table{
	
	public Table(){
	}
	
	public static class DaftarTelepon{
		private final SimpleStringProperty No;
		private final SimpleStringProperty KodeAnggota;
		private final SimpleStringProperty NoTelp;
		
		private DaftarTelepon(String NO,String KA,String NT){
			this.No = new SimpleStringProperty(NO);
			this.KodeAnggota = new SimpleStringProperty(KA);
			this.NoTelp = new SimpleStringProperty(NT);
		}
		
		public String getNo(){
			return No.get();
		}
		
		public void setNo(String NO){
			No.set(NO);
		}
		
		public String getKodeAnggota(){
			return KodeAnggota.get();
		}
		
		public void setKodeAnggota(String KA){
			KodeAnggota.set(KA);
		}
		
		public String getNoTelp(){
			return NoTelp.get();
		}
		
		public void setNoTelp(String NT){
			NoTelp.set(NT);
		}
	}
	
	private TableView<DaftarTelepon> table = new TableView<DaftarTelepon>();
	private final ObservableList<DaftarTelepon> data2 = FXCollections.observableArrayList();
	private HBox hb = new HBox();
	private int no;
	
	
	public void tampil(Stage stage){
		
		ProsesTelepon ptlp = new ProsesTelepon();
		Group root = new Group();
		Scene scene = new Scene(new Group());

		stage.setTitle("Table");
		stage.setWidth(375);
		stage.setHeight(590);
		
		final Label label = new Label("Tabel Daftar Kontak Anggota");
		
		TableColumn NoCol = new TableColumn("No");
		NoCol.setMaxWidth(50);
		NoCol.setCellValueFactory(
			new PropertyValueFactory<DaftarTelepon,String>("No")
		);
		
		TableColumn kodeanggotaCol = new TableColumn("Kode Anggota");
		kodeanggotaCol.setMaxWidth(120);
		kodeanggotaCol.setCellValueFactory(
			new PropertyValueFactory<DaftarTelepon,String>("KodeAnggota")
		);
		
		TableColumn notelpCol = new TableColumn("Nomor Telepon");
		notelpCol.setMaxWidth(170);
		notelpCol.setCellValueFactory(
			new PropertyValueFactory<DaftarTelepon,String>("NoTelp")
		);
		
		table.getColumns().addAll(NoCol,kodeanggotaCol,notelpCol);
		table.setItems(data2);
		
		final VBox vbox = new VBox();
		vbox.setSpacing(5);
		vbox.setLayoutY(30);
		vbox.getChildren().addAll(label,table,hb);
		vbox.setPadding(new Insets(10,0,0,10));
		
		//----------Memasukan data ke dalam table (Proses Read)
		int jumlah = 0, i = 0;
		String[][] daftar = new String[25][5];
		
		try{
			ptlp.prosesTlp();
			jumlah = ptlp.getJml();
			daftar = ptlp.getHasil();
			no = jumlah;
		}catch(Exception e){
			System.out.println(ptlp.getError());
		}
		
		for(i=0;i<jumlah;i++){
			// String nomor = "" + no;
			data2.add(new DaftarTelepon (
				""+(i+1),
				daftar[i][0],
				daftar[i][1]
			));
		}
		table.setItems(data2);
		
		//----------Tambah Data ke table (Proses Add)
		final TextField addKodeAnggota = new TextField();
		addKodeAnggota.setPromptText("Kode Anggota");
		addKodeAnggota.setMaxWidth(kodeanggotaCol.getPrefWidth());
		
		//untuk add kuantiti barang
		final TextField addNoTelp = new TextField();
		addNoTelp.setPromptText("Nomor Telepon");
		addNoTelp.setMaxWidth(notelpCol.getPrefWidth());
		
		final Label label1 = new Label("kalem");
		label1.setLayoutX(30);
		label1.setLayoutY(580);
		
		final Label label2 = new Label("melak");
		label2.setLayoutX(60);
		label2.setLayoutY(580);
		root.getChildren().addAll(label1,label2);
		
		final Button addButton = new Button("Tambah");
		addButton.setOnAction(new EventHandler<ActionEvent>(){
			@Override
				public void handle(ActionEvent e){
					no++;
					//add data ke list
					//secara otomatis tabel akan terupdate secara otomatis menyesuaikan data yang ada di dalam list
					
					data2.add(new DaftarTelepon(
						""+no,
						addKodeAnggota.getText(),
						addNoTelp.getText())
					);
					
					ptlp.tambahAnggota(addKodeAnggota.getText(),addNoTelp.getText());
										
					addKodeAnggota.setText("");
					addNoTelp.setText("");
					// addHargaBarang.setText("");
					// label1.setText(addQtyBarang.getText());
					// label1.setText(addHargaBarang.getText());
					// no++;
					// stage.show();
				}
		});
		
		
		
		//add ke scene
		hb.getChildren().addAll(addKodeAnggota,addNoTelp,addButton);
		hb.setSpacing(3);
		
		((Group) scene.getRoot()).getChildren().addAll(vbox);
		
		stage.setScene(scene);
		stage.show();
	}
	
}
