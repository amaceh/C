package view;

import controller.DeliverItems;
import java.util.Scanner;


public class ViewItems{
	public ViewItems(){
		//konstruktor
	}

	public void view(){
		DeliverItems proitems = new DeliverItems();

		try{
			proitems.sendprocess();
			System.out.println(proitems.getHasil());
		}catch(Exception e){
			System.out.println(proitems.getError());
		}

		String inName;
		int inBuy, inSell;
		System.out.println("Masukkan data tabahan");
		Scanner scan = new Scanner(System.in);
		System.out.println("nama item :");
		inName = scan.nextLine();

		System.out.println("harga beli :");
		inBuy = scan.nextInt();

		System.out.println("harga jual:");
		inSell = scan.nextInt();

		proitems.addDataProcess(inName, inBuy, inSell);

		System.out.println("Data sudah Di insert!!");
		System.out.println("Data Sekarang");

		try{
			proitems.sendprocess();
			System.out.println(proitems.getHasil());
		}catch(Exception e){
			System.out.println(proitems.getError());
		}
	}
}