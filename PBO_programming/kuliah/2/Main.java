import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		int menu=0, x=0, y=0;
		Calculator cal = new Calculator();

		System.out.println("Masukkan Menu");
		Scanner sc = new Scanner(System.in);
		try{
			menu = sc.nextInt();
		}catch(Exception e){

		}
		
		System.out.println("Masukkan x");
		try{
			x = sc.nextInt();
		}catch(Exception e){

		}

		System.out.println("Masukkan y");
		try{
			y = sc.nextInt();
		}catch(Exception e){

		}

		switch(menu){
			case 1 :
			System.out.println(
			cal.getOpr().tambah(x,y));
			break;
			case 2 :
			System.out.println(
			cal.getOpr().kurang(x,y));
			break;
			case 3 :
			System.out.println(
			cal.getOpr().kali(x,y));
			break;
			case 4 :
			System.out.println(
			cal.getOpr().bagi(x,y));
			break;
		}	
	}
}