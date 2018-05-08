//i create the Spare part class 
//because the fullbody class look like the combination of this class attribute
class FullBody;
class SparePart{
//attribute
private:
	int h1, h2;
	int len;

public:
	SparePart(){};
//set get method
	void setH1(int h){
		h1=h;
	}
	void setH2(int h){
		h2=h;
	}
	void setLen(int len){
		this->len=len;
	}

	int getH1(){
		return h1;
	}
	int getH2(){
		return	h2;
	}
	int getLen(){
		return len;
	}
	//declare friend void
	friend void PrintRobot(SparePart s, FullBody f);
	~SparePart(){};

};