class Main{
	public static void main(String[] args) {
		Persegi operasi;
		SegitigaSiku osegitiga;

		operasi = new Persegi();
		osegitiga = new SegitigaSiku();

		System.out.println(operasi.luas(5,8));
		System.out.println(osegitiga.luas(5,8));

	}
}