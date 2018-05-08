class Main{
	public static void main(String[] args) {
		Animasi anim = new Animasi(50, 9);
		Animasi multi = new Animasi(30, 5);

		multi.run();
		anim.run();
	}
}