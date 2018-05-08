import java.util.Scanner;//scanner class
import java.util.regex.Pattern;//pattern class, for incase sensitive search

/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	Pemrograman Berbasis Objek dalam mengerjakan Mid Test,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin.
*/

//main class
class Main{
	/*
	Main Program Description:
	Please make some class array and input the data (hardcode) for Book, 
	BookStore, and Publisher and show the content of each array on screen. 
	Make a searching process and input a part or whole of the booktitle, 
	show the searching process result as Book, BookStore, and Publisher data 
	if it is exist or show "Not Found" if it is not exist.

	Send your work to rosa_if_itb_01@yahoo.com with subject 
	and zip/rar file name as "OOP_Mid_Name" and your due time is 09.20 yahoo time. 
	There are some discount for every minute late (2 point).
	*/

	//main Method
	public static void main(String[] args) {
		//input the book, bookstore, and publisher

		//declare array of object
		Book buku[] = new Book[5];
		BookStore gramed[] = new BookStore[5];
		BookPublisher penerbit[] = new BookPublisher[5];

		//instance every object in the array
		for(int i=0; i<5; i+=1){
			buku[i] = new Book();
			gramed[i] = new BookStore();
			penerbit[i] = new BookPublisher();
		}

		//input the data(hardcode)
		buku[0].setTitle("Laskar Pelangi");
		gramed[0].setName("Merdeka");
		penerbit[0].setName("Erlangga");

		buku[1].setTitle("5 Menara");
		gramed[1].setName("TSM");
		penerbit[1].setName("Bunda");

		buku[2].setTitle("Kite Runner");
		gramed[2].setName("Readers");
		penerbit[2].setName("Syahdu");

		buku[3].setTitle("Chicken Soup");
		gramed[3].setName("Terang");
		penerbit[3].setName("Nanana");

		buku[4].setTitle("Ayat-ayat Cinta");
		gramed[4].setName("Light");
		penerbit[4].setName("Mesir");
		//show something to the user
		System.out.println("List Buku Terfavorit");
		System.out.println("=================================");
		
		System.out.println("No--\t--Judul--\t--Toko--Penerbit");
		//show content of every array
		for(int i=0; i<5; i+=1){
			System.out.println(i+"\t"+buku[i].getTitle()+"\t"+gramed[i].getName()+"\t"+penerbit[i].getName());
		}
		System.out.println("=================================");
		System.out.print("Silahkan Masukan Pencarian Judul Buku Anda : ");
		
		//lets make some scanner
		Scanner scan = new Scanner(System.in);
		String search = scan.nextLine();//string scanner

		//searching algorithm
		int done = 0;
		int get= 0;
		int i = 0;
		System.out.println("Hasil Pencarian :");

		while(done == 0 && i<5){//search until end of array, or when the object found
			//incase sensitive search
			if(Pattern.compile(Pattern.quote(search), Pattern.CASE_INSENSITIVE).matcher(buku[i].getTitle()).find()){
			//Case Sensitive search
			// if(buku[i].getTitle().contains(search)){//contains() is searching some word in string, while equal somare entire string
				System.out.println(i+"\t"+buku[i].getTitle()+"\t"+gramed[i].getName()+"\t"+penerbit[i].getName());
           		
           		get = 1;
           		// done = 1;//uncomment to get only one result
           		//mungkin ada lebih dari 1 buku yang judulnya mirip. 
        	}
			i+=1;
		}
		if (get==0) {
			System.out.println("Not Found");
		}
	}

}