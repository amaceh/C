class Main{
	/*metode main untuk mengetes kelas Titik*/
	public static void main(String[] args) {
		titik t1 = new titik();
		titik t2 = new titik(11, 9);
		t1.setX(18);
		t1.setY(28);
		System.out.println("t1 : nilai X : " + t1.getX());
		System.out.println("t1 : nilai Y : " + t1.getY());
		System.out.println("t2 : nilai X : " + t2.getX());
		System.out.println("t2 : nilai Y : " + t2.getY());
	}
}