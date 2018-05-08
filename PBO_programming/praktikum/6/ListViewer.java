import java.util.Arrays;
import javafx.application.Application;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.Group;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.Stage;

/*

ComboBox<String> tfGender = new ComboBox<String>();
		tfGender.getItems().addAll("M", "F");
		tfGender.setLayoutX(130);
		tfGender.setLayoutY(120);
		tfGender.setValue("M");
		root1.getChildren().add(tfGender);

*/


public class ListViewer extends Application{
	public static class BarangBeli{
		private final SimpleStringProperty No;
		private final SimpleStringProperty KodeBarang;
		private final SimpleStringProperty JenisBarang;
		private final SimpleStringProperty QtyBarang;
		private final SimpleStringProperty HargaBarang;

		private BarangBeli(String NO, String KB, String JB,String QB, String HB){
			this.No = new SimpleStringProperty(NO);
			this.KodeBarang = new SimpleStringProperty(KB);
			this.JenisBarang = new SimpleStringProperty(JB);
			this.QtyBarang = new SimpleStringProperty(QB);
			this.HargaBarang = new SimpleStringProperty(HB);
		}
		public String getNO(){
			return No.get();
		}
		public void setNO(String NO){
			No.set(NO);
		}

		public String getKodeBarang(){
			return KodeBarang.get();
		}
		public void setKodeBarang(String KB){
			KodeBarang.set(KB);
		}

		public String getQtyBarang(){
			return QtyBarang.get();
		}
		public void setQtyBarang(String QB){
			QtyBarang.set(QB);
		}

		public String getHargaBarang(){
			return HargaBarang.get();
		}
		public void setHargaBarang(String HB){
			HargaBarang.set(HB);
		}

		public String getJenisBarang(){
			return JenisBarang.get();
		}
		public void setJenisBarang(String JB){
			JenisBarang.set(JB);
		}
	}


		private TableView<BarangBeli> table = new TableView<BarangBeli>();

		private final ObservableList<BarangBeli> data2=
			FXCollections.observableArrayList(
				new BarangBeli("1", "BRG001", "Laptop", "1", "400000")
			);

			private HBox hb = new HBox();

			public static void main(String[] args) {
				launch(args);		
			}

			int no=1;
			@Override
			public void start(Stage stage){
				Scene scene = new Scene(new Group());
				Group root=new Group();

				stage.setTitle("Tabel");
				stage.setWidth(500);
				stage.setWidth(590);

				final Label label = new Label("Tabel Pembeli Barang");

				TableColumn<BarangBeli, String> noCol = new TableColumn<BarangBeli, String>("No");
				noCol.setMaxWidth(50);

				noCol.setCellValueFactory(
					new PropertyValueFactory<BarangBeli, String>("NO")
				);

				TableColumn<BarangBeli, String> kodebarangCol = new TableColumn<BarangBeli, String>("Kode Barang");
				kodebarangCol.setMaxWidth(120);

				kodebarangCol.setCellValueFactory(
					new PropertyValueFactory<BarangBeli, String>("KodeBarang")
				);

				TableColumn<BarangBeli, String> jenisCol = new TableColumn<BarangBeli, String>("Jenis Barang");
				jenisCol.setMaxWidth(120);

				jenisCol.setCellValueFactory(
					new PropertyValueFactory<BarangBeli, String>("JenisBarang")
				);

				TableColumn<BarangBeli, String> qtyCol = new TableColumn<BarangBeli, String>("Quantity");
				qtyCol.setMaxWidth(120);

				qtyCol.setCellValueFactory(
					new PropertyValueFactory<BarangBeli, String>("QtyBarang")
				);

				TableColumn<BarangBeli, String> hargaCol = new TableColumn<BarangBeli, String>("Harga");
				hargaCol.setMaxWidth(120);

				hargaCol.setCellValueFactory(
					new PropertyValueFactory<BarangBeli, String>("HargaBarang")
				);


				table.getColumns().addAll(Arrays.asList(noCol, kodebarangCol, jenisCol, qtyCol, hargaCol));
				
				table.setItems(data2);

				final VBox vbox = new VBox();
				vbox.setSpacing(5);
				vbox.setLayoutY(50);
				vbox.getChildren().addAll(label, table,hb);
				vbox.setPadding(new Insets(10,0,0,10));

				final TextField addKodeBarang = new TextField();
				addKodeBarang.setPromptText("Kode Barang");
				addKodeBarang.setMaxWidth(kodebarangCol.getPrefWidth());

				final TextField addQtyBarang = new TextField();
				addQtyBarang.setPromptText("Qty Barang");
				addQtyBarang.setMaxWidth(qtyCol.getPrefWidth());

				final ComboBox<String> cbJenis = new ComboBox<String>();
				cbJenis.getItems().addAll("Laptop", "PC", "Storage");
				cbJenis.setMaxWidth(qtyCol.getPrefWidth());
				
				// cbJenis.setLayoutX(130);
				// cbJenis.setLayoutY(120);
				// cbJenis.setValue("M");
				// root1.getChildren().add(cbJenis);

				final TextField addHargaBarang = new TextField();
				addHargaBarang.setPromptText("Harga Barang");
				addHargaBarang.setMaxWidth(hargaCol.getPrefWidth());
				
				final Label label1=new Label("");
				label1.setLayoutX(30);
				label1.setLayoutY(550);

				final Label label2=new Label("");
				label2.setLayoutX(60);
				label2.setLayoutY(550);

				final Label label3=new Label("");
				label3.setLayoutX(90);
				label3.setLayoutY(550);

				root.getChildren().addAll(label1, label2, label3);
				
				final Button addButton = new Button("Tambah");
				addButton.setOnAction(new EventHandler<ActionEvent>(){
					@Override
					public void handle(ActionEvent e){
						no++;
						data2.add(new BarangBeli(
						""+no,
						addKodeBarang.getText(),
						cbJenis.getValue(),
						addQtyBarang.getText(),
						addHargaBarang.getText()
						));
						addKodeBarang.setText("");
						addKodeBarang.setText("");
						cbJenis.getSelectionModel().clearSelection();
						addQtyBarang.setText("");
						addHargaBarang.setText("");
						label1.setText(addQtyBarang.getText());
						label1.setText(addHargaBarang.getText());

					}
				});

				hb.getChildren().addAll(addKodeBarang, cbJenis, addQtyBarang,addHargaBarang, addButton);
				hb.setSpacing(3);

				((Group) scene.getRoot()).getChildren().addAll(vbox);			
				
				stage.setScene(scene);
				stage.show();
	}	
}