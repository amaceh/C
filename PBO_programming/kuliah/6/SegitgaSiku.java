// import java.lang.Math;

class SegitigaSiku implements BangunDatar {
	SegitigaSiku(){

	}

	public double luas(int s1, int s2){
		return (s1*s2)/2;
	}

	public double keliling(int s1, int s2){
		return (s1+s2)+Math.sqrt((s1*s1)+(s2*s2));
	}
}