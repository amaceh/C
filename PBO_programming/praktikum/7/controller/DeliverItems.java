package controller;

import java.io.*;
import model.DB;
import model.Item;

public class DeliverItems{
	private String hasil;
	private String error;

	public DeliverItems(){
		//konstruktor
	}

	public void sendprocess(){
		try{
			Item item = new Item();
			item.getItems();
			hasil = "******************\n";

			while(item.getResult().next()){
				String item_name = item.getResult().getString(1);
				String item_price = item.getResult().getString(2);
				String item_sell_price = item.getResult().getString(3);

				hasil = hasil + "Nama Barang : " + item_name + "\n";
				hasil = hasil + "Harga Beli : " + item_price + "\n";
				hasil = hasil + "Harga Jual : " + item_sell_price + "\n";
				hasil = hasil + "****************\n"; 
			}
			
			item.closeResult();
			item.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}

	public void addDataProcess(String inName ,int inBuy, int inSell){
		try{
			Item item = new Item();
			item.addItems(inName, inBuy, inSell);
			item.closeResult();
			item.closeConnection();
		}catch(Exception e){
			error = e.toString();
		}
	}

	public String getHasil(){
		return this.hasil;
	}
	public String getError(){
		return this.error;
	}
}