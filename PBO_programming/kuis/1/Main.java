class Main {
	
	/*
	saya Achmad Abdul Rofiq tidak melakukan kecurangan
	seperti yang telah dispesifikasikan pada mata kuliah
	Pemrograman Berbasis Object dalam mengerjakan Kuis 1,
	jika saya melakukan kecurangan maka Allah adalah saksi
	saya, dan saya menerima hukuman-Nya. aamin...
	*/
	public static void main(String[] args) {
		//buat objek toko dan pemilik toko
		Toko store = new Toko();
		PemilikToko koko = new PemilikToko();
		//set attribute toko dan pemilik toko
		store.setNama("Bahagia");
		store.setLokasi("Bandung");
		store.setKode("1");
		koko.setNama("syukur");
		koko.setNoKTP("7898655232");
		koko.setKodeToko("1");

		//deklarasi array of object
		Pensil[] penshield = new Pensil[2];
		Buku[] buuk = new Buku[2];
		KotakPensil[] takshield = new KotakPensil[2];

		//create object setiap elemen array
		for(int i = 0; i < penshield.length ; i++)
		{
		    penshield[i] = new Pensil();
		}

		for(int i = 0; i < buuk.length ; i++)
		{
		    buuk[i] = new Buku();
		}

		for(int i = 0; i < takshield.length ; i++)
		{
		    takshield[i] = new KotakPensil();
		}
		//isi array of objek dengan set method
		penshield[0].setNama("Pensil 2B");
		penshield[1].setNama("Pensil standard");
		penshield[0].setHarga(5000);
		penshield[1].setHarga(3000);
		
		buuk[0].setNama("Buku anak");
		buuk[1].setNama("Buku mini");
		buuk[0].setHarga(10000);
		buuk[1].setHarga(5000);

		takshield[0].setNama("Kotak Pensil");
		takshield[1].setNama("Kotak Pensil Kain");
		takshield[0].setHarga(20000);
		takshield[1].setHarga(20000);		
		//variabel penampung array
		int total = 0;
		//tampung harga
		for(int i = 0; i < penshield.length ; i++)
		{
		    total = total + penshield[i].getHarga();
		}

		for(int i = 0; i < buuk.length ; i++)
		{
		    total = total + buuk[i].getHarga();
		}

		for(int i = 0; i < takshield.length ; i++)
		{
		    total = total + takshield[i].getHarga();
		}
		//tampilan nama toko dan pemilik
		System.out.println("Nama Toko :"+ store.getNama());
		System.out.println("Lokasi :" + store.getLokasi());
		System.out.println("Nama Pemilik Toko :"+koko.getNama());
		System.out.println("No KTP :"+koko.getNoKTP());
		System.out.println("--------------------");
		System.out.println("--------------------");
		//tampilan bon dengan print tiap elemen array
		for(int i = 0; i < penshield.length ; i++)
		{
		    System.out.println(penshield[i].getNama()+"          "+penshield[i].getHarga());
		}

		for(int i = 0; i < buuk.length ; i++)
		{
		    System.out.println(buuk[i].getNama()+"             "+buuk[i].getHarga());
		}

		for(int i = 0; i < takshield.length ; i++)
		{
		    System.out.println(takshield[i].getNama()+"       "+takshield[i].getHarga());
		}
		//tampilan bawah
		System.out.println("--------------------");
		System.out.println("              "+total);
	}
}